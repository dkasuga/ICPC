#include <bits/stdc++.h>
using namespace std;
template <class T>
inline bool chmax(T& a, T b)
{
    if (a < b) {
        a = b;
        return 1;
    }
    return 0;
}
template <class T>
inline bool chmin(T& a, T b)
{
    if (a > b) {
        a = b;
        return 1;
    }
    return 0;
}

int N;
vector<int> w;

// 計算量はO(N^3)
int solve()
{
    vector<vector<int>> dp(N + 1, vector<int>(N + 1, -N));
    for (int i = 0; i <= N; i++) {
        dp[i][i] = 0;
        if (i < N)
            dp[i][i + 1] = 0;
    }

    for (int bet = 2; bet <= N; bet++) {
        for (int i = 0; i + bet <= N; i++) {
            int j = i + bet;
            if (dp[i + 1][j - 1] == j - i - 2) { // 区間[i+1, j-1)の要素が無事すべて消滅し，要素a[i]とa[j-1]のみが残る場合
                if (abs(w[i] - w[j - 1]) <= 1)
                    chmax(dp[i][j], j - i);
                else
                    chmax(dp[i][j], j - i - 2);
            }
            for (int k = i + 1; k <= j - 1; k++) { // あるkが存在して，区間[i, k)と区間[k, j)とは独立に操作したものとみなせる場合
                chmax(dp[i][j], dp[i][k] + dp[k][j]);
            }
        }
    }
    return dp[0][N];
}

int main()
{
    while (cin >> N, N) {
        w.resize(N);
        for (int i = 0; i < N; i++)
            cin >> w[i];
        cout << solve() << endl;
    }
}