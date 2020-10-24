#include <bits/stdc++.h>
#include <math.h>

using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
typedef long long ll;
using Graph = vector<vector<int>>;
typedef pair<int, int> P;

const int MOD = 1000000007;
const int INF_32 = 1LL << 30;
const int64_t INF_64 = 1LL << 60;

using Graph = vector<vector<int>>;
int m, n;
const int N_MAX = 7368791 + 10;

template <typename A, size_t N, typename T>
void Fill(A (&array)[N], const T& val)
{
    std::fill((T*)array, (T*)(array + N), val);
}

template <class T>
inline bool chmin(T& a, T b)
{
    if (a > b) {
        a = b;
        return true;
    }
    return false;
}
template <class T>
inline bool chmax(T& a, T b)
{
    if (a < b) {
        a = b;
        return true;
    }
    return false;
}

vector<vector<int>> G(15, vector<int>(15, -1));
int main()
{
    while (true) {
        int d, w;
        cin >> d >> w;
        if (d == 0 && w == 0)
            break;

        for (int row = 0; row < d; row++) {
            for (int col = 0; col < w; col++) {
                cin >> G[row][col];
            }
        }

        auto capacity = [&](int irow, int icol, int jrow, int jcol) {
            int pond_max = 0;
            int moat_min = INF_32;
            for (int row = irow; row <= jrow; row++) {
                for (int col = icol; col <= jcol; col++) {
                    if (row > irow && row < jrow && col > icol && col < jcol) {
                        chmax(pond_max, G[row][col]);
                    } else {
                        chmin(moat_min, G[row][col]);
                    }
                }
            }

            if (pond_max >= moat_min)
                return 0;

            int pond_cap = 0;
            for (int row = irow; row <= jrow; row++) {
                for (int col = icol; col <= jcol; col++) {
                    if (row > irow && row < jrow && col > icol && col < jcol) {
                        pond_cap += moat_min - G[row][col];
                    }
                }
            }

            return pond_cap;
        };

        int ans = 0;

        // 左上：i，右下：j
        for (int irow = 0; irow < d; irow++) {
            for (int icol = 0; icol < w; icol++) {
                for (int jrow = irow + 2; jrow < d; jrow++) {
                    for (int jcol = icol + 2; jcol < w; jcol++) {
                        chmax(ans, capacity(irow, icol, jrow, jcol));
                    }
                }
            }
        }
        cout << ans << endl;
    }

    return 0;
}