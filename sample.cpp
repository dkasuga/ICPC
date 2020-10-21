#include <bits/stdc++.h>
#include <math.h>

using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
typedef long long ll;
const int MOD = 1000000007;
const int INF_32 = 1LL << 30;
const int64_t INF_64 = 1LL << 60;

template <typename A, size_t N, typename T>
void Fill(A (&array)[N], const T& val)
{
    std::fill((T*)array, (T*)(array + N), val);
}
int N, M, A[9][9];
int ans = 0;

int check(int y)
{
    int win = 0, los = 0;
    for (int x = 0; x < N; x++) {
        if (A[y][x] == 1)
            win++;
        else if (A[y][x] == 0)
            los++;
    }
    return win <= (N - 1) / 2 and los <= (N - 1) / 2;
}

void dfs(int cu)
{
    int x = cu % N;
    int y = cu / N;

    if (cu == N * N) {
        ans++;
        return;
    }

    if (x == y or 0 <= A[y][x]) {
        if (check(y))
            dfs(cu + 1);
        return;
    }

    A[y][x] = 1, A[x][y] = 0;
    if (check(y))
        dfs(cu + 1);
    A[y][x] = 0, A[x][y] = 1;
    if (check(y))
        dfs(cu + 1);

    A[y][x] = A[x][y] = -1;
}

int main()
{
    while (cin >> N) {
        if (N == 0)
            return 0;
        cin >> M;
        rep(i, N) rep(j, N) A[i][j] = -1;
        rep(i, M)
        {
            int a, b;
            cin >> a >> b;
            a--;
            b--;
            A[a][b] = 1;
            A[b][a] = 0;
        }

        ans = 0;
        dfs(0);
        printf("%d\n", ans);
    }
}
