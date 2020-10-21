#include <bits/stdc++.h>
#include <math.h>

using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
typedef long long ll;
const int MOD = 1000000007;
const int INF_32 = 1LL << 30;
const int64_t INF_64 = 1LL << 60;

int n;

int main()
{
    while (cin >> n) {
        if (n == 0)
            return 0;

        bool flag = false;
        vector<int> votes(26, 0);
        for (int i = 0; i < n; i++) {
            char c;
            cin >> c;
            int c_i = (int)(c - 'A');
            votes[c_i]++;
            int mx, mx_2;
            int mx_idx, mx_2_idx;
            mx = mx_2 = 0;
            mx_idx = mx_2_idx = -1;
            for (int j = 0; j < 26; j++) {
                if (votes[j] > mx) {
                    mx = votes[j];
                    mx_idx = j;
                } else if (votes[j] > mx_2) {
                    mx_2 = votes[j];
                    mx_2_idx = j;
                }
            }
            if (mx - mx_2 > n - i - 1) {
                cout << (char)(mx_idx + 'A') << " " << i + 1 << endl;
                flag = true;
                break;
            }
        }
        if (flag)
            continue;
        cout << "TIE" << endl;
    }
}