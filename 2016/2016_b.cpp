#include <bits/stdc++.h>
#include <math.h>

using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
typedef long long ll;
const int MOD = 1000000007;
const int INF_32 = 1LL << 30;
const int64_t INF_64 = 1LL << 60;

// my answer
// int n;

// int main()
// {
//     while (cin >> n) {
//         if (n == 0)
//             return 0;

//         vector<char> c(n);
//         bool flag = false;
//         vector<int> votes(26, 0);
//         for (int i = 0; i < n; i++) {
//             cin >> c[i];
//         }
//         for (int i = 0; i < n; i++) {
//             int c_i = (int)(c[i] - 'A');
//             votes[c_i]++;
//             int mx, mx_2;
//             int mx_idx, mx_2_idx;
//             mx = mx_2 = 0;
//             mx_idx = mx_2_idx = -1;
//             for (int j = 0; j < 26; j++) {
//                 if (votes[j] > mx) {
//                     mx_2 = mx;
//                     mx = votes[j];
//                     mx_idx = j;
//                 } else if (votes[j] > mx_2) {
//                     mx_2 = votes[j];
//                     mx_2_idx = j;
//                 }
//             }
//             if (mx - mx_2 > n - i - 1) {
//                 cout << (char)(mx_idx + 'A') << " " << i + 1 << endl;
//                 flag = true;
//                 break;
//             }
//         }
//         if (flag)
//             continue;
//         cout << "TIE" << endl;
//     }
// }

int main()
{
    int n;
    char c;
    while (cin >> n, n) {
        vector<int> cnt((int)('Z' - 'A') + 1);
        pair<int, int> idx(0, 1);
        int find = -1;

        for (int i = 0; i < n; i++) {
            cin >> c;

            if (find != -1)
                continue;

            int cur = (int)(c - 'A');
            ++cnt[cur];
            if (cur != idx.first && cnt[idx.second] < cnt[cur])
                idx.second = cur;
            if (cnt[idx.first] < cnt[idx.second])
                swap(idx.first, idx.second);
            if (cnt[idx.second] + (n - i - 1) < cnt[idx.first])
                find = i + 1;
        }

        if (cnt[idx.first] == cnt[idx.second])
            cout << "TIE\n";
        else
            cout << (char)(idx.first + 'A') << " " << find << '\n';
    }
    return 0;
}