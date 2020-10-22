#include <bits/stdc++.h>
#include <math.h>

using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
typedef long long ll;
const int MOD = 1000000007;
const int INF_32 = 1LL << 30;
const int64_t INF_64 = 1LL << 60;

int m, n;
const int N_MAX = 7368791 + 10;
int main()
{
    while (cin >> m && cin >> n) {
        if (m == 0 && n == 0)
            break;
        if (m > n) {
            cout << m + n << endl;
            continue;
        } else if (m == n) {
            cout << m + n + 1 << endl;
            continue;
        }

        int cnt = 0;
        vector<bool> is_check(N_MAX, false);
        bool flag = false;
        for (int i = m; i <= N_MAX; i++) {
            if (is_check[i]) {
                continue;
            }
            cnt++;
            if (cnt > n) {
                cout << i << endl;
                flag = true;
                break;
            }
            for (int j = 2 * i; j <= N_MAX; j += i)
                is_check[j] = true;
        }
        if (flag)
            continue;
    }

    return 0;
}