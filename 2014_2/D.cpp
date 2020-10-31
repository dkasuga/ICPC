#include <bits/stdc++.h>
#include <math.h>

using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
typedef long long ll;
const int MOD = 1000000007;
const int INF_32 = 1LL << 30;
const int64_t INF_64 = 1LL << 60;

int main()
{
    while (true) {
        string s;
        cin >> s;
        if (s == "#")
            break;
        set<string> st;
        int size = s.size();

        for (int bit = 0; bit < (1LL << size); bit++) {
            string tmp = "";
            for (int i = 0; i < size; i++) {
                if (s[i] == 'z')
                    tmp += 'z';
                else {
                    if (bit & (1LL << i)) {
                        tmp += (char)(s[i] + 1);
                    } else {
                        tmp += s[i];
                    }
                }
            }

            vector<bool> cnt(26, false);
            bool flag = true;
            for (int i = 0; i < size; i++) {
                int idx = (int)(tmp[i] - 'a');
                if (tmp[i] == 'a')
                    continue;
                if (!cnt[idx] && tmp[i] == s[i]) { // はじめて登場するにも関わらず同じものになってる場合はアウツ
                    flag = false;
                    break;
                }
                cnt[idx] = true;
            }
            if (flag) {
                st.insert(tmp);
            }
        }

        cout << st.size() << endl;
        if (st.size() <= 10) {
            for (string p : st) {
                cout << p << endl;
            }
        } else {
            for (auto itr = st.begin(); itr != next(st.begin(), 5); itr++) {
                cout << *itr << endl;
            }
            for (auto itr = prev(st.end(), 5); itr != st.end(); itr++) {
                cout << *itr << endl;
            }
        }
    }
    return 0;
}
