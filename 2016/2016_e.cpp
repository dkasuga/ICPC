#include <bits/stdc++.h>
#include <math.h>

using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
typedef long long ll;
const int MOD = 1000000007;
const int INF_32 = 1LL << 30;
const int64_t INF_64 = 1LL << 60;

template <class T>
inline bool chmin(T& a, T b)
{
    if (a > b) {
        a = b;
        return 1;
    }
    return 0;
}

int main()
{
    while (true) {
        //input
        int n, k, s;
        cin >> n >> k >> s;
        vector<int> x(n), y(n), z(n);
        for (int i = 0; i < n; i++) {
            cin >> x[i] >> y[i] >> z[i];
        }
        if (n == 0 and k == 0 and s == 0)
            break;

        // geometry
        auto is_connected = [&](int i, int j) {
            int dx = abs(x[j] - x[i]);
            int dy = abs(y[j] - y[i]);
            int dz = abs(z[j] - z[i]);
            return dx <= s and dy <= s and dz <= s;
        };
        auto intersecting_area = [&](int i, int j) {
            if (not is_connected(i, j))
                return 0;
            int dx = s - abs(x[j] - x[i]);
            int dy = s - abs(y[j] - y[i]);
            int dz = s - abs(z[j] - z[i]);
            return 2 * (dx * dy + dy * dz + dz * dx);
        };
        // make graph
        vector<vector<int>> g(n);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (i != j) {
                    if (is_connected(i, j))
                        g[i].push_back(j);
                }
            }
        }

        function<int(int, int, int, int)> dfs = [&](int i, int prev, int depth, int first) {
            if (depth == k) {
                if (3 <= k and is_connected(i, first)) { // 一番最初のやつと被るかどうか
                    return 6 * s * s - intersecting_area(i, first);
                }
                return 6 * s * s;
            } else {
                int ans = INF_32;
                for (int j : g[i])
                    if (j != prev) {
                        chmin(ans, 6 * s * s - intersecting_area(i, j) + dfs(j, i, depth + 1, first));
                    }
                return ans;
            }
        };

        int ans = INF_32;
        for (int i = 0; i < n; i++)
            chmin(ans, dfs(i, -1, 1, i));
        if (ans == INF_32)
            ans = -1;
        cout << ans << endl;
    }
    return 0;
}
