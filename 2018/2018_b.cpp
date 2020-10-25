#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main()
{
    while (true) {
        int n, m, t, p;
        cin >> n >> m >> t >> p;
        if (n == 0 && m == 0 && t == 0 && p == 0)
            break;
        vector<int> d_(t), c_(t), x_(p), y_(p);
        rep(i, t) cin >> d_[i] >> c_[i];
        rep(i, p) cin >> x_[i] >> y_[i];

        vector<vector<int>> cnt(m * 20 + 10, vector<int>(n * 20 + 10, 0));
        for (int row = 0; row < m; row++) {
            for (int col = 0; col < n; col++) {
                cnt[row][col] = 1;
            }
        }

        int ox = 0, oy = 0; // 原点の位置
        rep(i, t)
        {
            int d = d_[i];
            int c = c_[i];
            if (d == 1) {
                for (int row = 0; row < 20 * m; row++) {
                    for (int j = 0; j < c; j++) {
                        int left = ox + c - 1 - j;
                        int right = ox + c + j;
                        cnt[row][right] += cnt[row][left];
                    }
                }
                ox = ox + c;
            } else {
                for (int col = 0; col < 20 * n; col++) {
                    for (int j = 0; j < c; j++) {
                        int up = oy + c - 1 - j;
                        int down = oy + c + j;
                        cnt[down][col] += cnt[up][col];
                    }
                }
                oy = oy + c;
            }
        }

        rep(i, p)
        {
            int x = ox + x_[i];
            int y = oy + y_[i];
            cout << cnt[y][x] << endl;
        }
    }
}