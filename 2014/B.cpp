#include <bits/stdc++.h>
#include <math.h>

using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
typedef long long ll;
const int MOD = 1000000007;
const int INF_32 = 1LL << 30;
const int64_t INF_64 = 1LL << 60;

const int MAX_COL = 5;

void dfs(vector<int>& puz_row, int v, int val, int& cnt)
{
    if (puz_row[v] == val) {
        cnt++;
        if (v + 1 < MAX_COL) {
            dfs(puz_row, v + 1, val, cnt);
        }
        if (cnt >= 3) {
            puz_row[v] = -1;
        }
    }
}

int main()
{
    while (true) {
        int h;
        cin >> h;
        if (h == 0)
            break;
        vector<vector<int>> puz(h + 1, vector<int>(MAX_COL + 1, 0));
        for (int row = 0; row < h; row++) {
            for (int col = 0; col < MAX_COL; col++) {
                cin >> puz[row][col];
            }
        }

        int score = 0;
        while (true) {
            bool flag = false;
            // ブロックを消去するステップ
            for (int row = 0; row < h; row++) {
                for (int col = 0; col < MAX_COL; col++) {
                    if (puz[row][col] == -1)
                        continue;
                    int val = puz[row][col];
                    int cnt = 0; // 連続する同じ石の数
                    dfs(puz[row], col, val, cnt);
                    if (cnt >= 3) {
                        flag = true;
                        score += val * cnt;
                    }
                }
            }

            if (!flag)
                break;

            // 消去したブロックを詰めるステップ
            for (int col = 0; col < MAX_COL; col++) {
                vector<int> tmp;
                // 空じゃないやつを詰めてく
                for (int row = h - 1; row >= 0; row--) {
                    if (puz[row][col] == -1)
                        continue;
                    tmp.push_back(puz[row][col]);
                }
                // 下から詰め直していく
                for (int i = 0; i < tmp.size(); i++)
                    puz[h - 1 - i][col] = tmp[i];
                for (int i = tmp.size(); i < h; i++) {
                    puz[h - 1 - i][col] = -1;
                }
            }
        }
        cout << score << endl;
    }
    return 0;
}
