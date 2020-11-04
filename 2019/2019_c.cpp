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

// 解説見て実装しなおした
// https://www.youtube.com/watch?v=onlyYdtRLXQ&ab_channel=ICPCJapanmanagedbyICPCSec

// もとの分銅だけで作れる要素の集合を作る
// それぞれの薬品との差分の集合をもっておく
// その中に0が含まれる場合は気にしない
// 0が含まれない場合は，積集合をとって，最終的に得られる全体の積集合が空集合（つまり1つの分銅の追加だけでは対処できない）なら-1，そうでない場合は要素全体の最小値が追加すべき分銅

// 差分の中に
void dfs(int i, int m, int sum, vector<int>& w, set<int>& check)
{
    if (i == m) {
        check.insert(sum);
        return;
    }

    dfs(i + 1, m, sum, w, check);
    dfs(i + 1, m, sum + w[i], w, check);
    dfs(i + 1, m, sum - w[i], w, check);

    return;
}

int main()
{
    while (true) {
        int n, m;
        cin >> n >> m;
        if (n == 0 && m == 0)
            break;
        vector<int> a(n), w(m);
        rep(i, n) cin >> a[i];
        rep(i, m) cin >> w[i];
        set<int> w_check;
        dfs(0, m, 0, w, w_check);

        set<int> insec;
        for (auto w : w_check) {
            insec.insert(abs(a[0] - w));
        }

        for (int i = 1; i < n; i++) {
            set<int> s;
            for (auto w : w_check) {
                s.insert(abs(a[i] - w));
            }

            if (s.count(0))
                continue;
            set<int> tmp;
            set_intersection(s.begin(), s.end(), insec.begin(), insec.end(), inserter(tmp, tmp.end()));
            // insec.clear();
            insec = tmp;
        }

        if (insec.size() == 0) {
            cout << -1 << endl;
            continue;
        }

        int mi = *insec.begin();
        if (mi == 0) {
            cout << 0 << endl;
        } else {
            cout << mi << endl;
        }
    }
}

/* mycode

- バグってしまう…
- 戦略
    - まずもとの分胴だけで作れる和の組み合わせをすべてsetに登録する（足すか引くかなにもしないかの3通りなのでdfs）
    - 次にレシピを見ていって，作れないものがあったらその差分の分銅を追加して，新しく作れる和のsetを作る（ここに抜けがあった．新しく追加した分銅 - 今までの和，みたいなのを考えていなかった）（というかそれがあったとしても，どのレシピから見るかによって結果が変わってしまう）
    - それでも作れなかったらアウト
- 上記の戦略にはミスがある，追加の際の戦略をもっとうまくやるべき
*/
// void dfs(int i, int m, int sum, vector<int>& w, set<int>& check)
// {
//     if (i == m) {
//         return;
//     }

//     // 何も入れない
//     check.insert(sum);
//     dfs(i + 1, m, sum, w, check);
//     // 足す
//     check.insert(sum + w[i]);
//     dfs(i + 1, m, sum + w[i], w, check);
//     // 引く
//     check.insert(sum - w[i]);
//     dfs(i + 1, m, sum - w[i], w, check);

//     return;
// }

// int main()
// {
//     while (true) {
//         int n, m;
//         cin >> n >> m;
//         if (n == 0 && m == 0)
//             break;
//         vector<int> a(n), w(m);
//         rep(i, n) cin >> a[i];
//         rep(i, m) cin >> w[i];
//         set<int> check1;

//         check1.insert(0);
//         dfs(0, m, 0, w, check1);

//         int mode = 0; // 0:1つも追加しない 1:1つ追加でよい -1:だめ
//         int bigger = INF_32, smaller;

//         for (auto x : check1) {
//             cout << x << endl;
//         }

//         cout << " " << endl;
//         rep(i, n)
//         {
//             if (!check1.count(a[i])) {
//                 auto idx = check1.lower_bound(a[i]);
//                 if (idx != check1.end())
//                     bigger = *idx - a[i];
//                 smaller = a[i] - *prev(idx, 1);
//                 if (smaller > bigger)
//                     swap(bigger, smaller);
//                 mode = 1;
//                 break;
//             }
//         }

//         if (mode == 0) {
//             cout << 0 << endl;
//             continue;
//         }

//         // mode=1に突入

//         set<int> check2;
//         // smallerでやってみる
//         for (auto x : check1) {
//             if (x < 0)
//                 continue;
//             check2.insert(x + smaller);
//             if (x - smaller > 0)
//                 check2.insert(x - smaller);
//         }

//         cout << "check2(smaller):" << endl;
//         for (auto x : check2) {
//             cout << x << endl;
//         }

//         rep(i, n)
//         {
//             if (!check1.count(a[i]) && !check2.count(a[i])) {
//                 mode = -1;
//                 break;
//             }
//         }
//         if (mode == 1) {
//             cout << smaller << endl;
//             continue;
//         }

//         if (bigger != INF_32) {
//             // biggerでやってみる
//             check2.clear();
//             for (auto x : check1) {
//                 if (x < 0)
//                     continue;
//                 check2.insert(x + bigger);
//                 if (x - bigger > 0)
//                     check2.insert(x - bigger);
//             }

//             cout << "check2(bigger):" << endl;
//             for (auto x : check2) {
//                 cout << x << endl;
//             }

//             rep(i, n)
//             {
//                 if (!check1.count(a[i]) && !check2.count(a[i])) {
//                     mode = -1;
//                     break;
//                 }
//             }
//         } else {
//             mode = -1;
//         }

//         if (mode == 1) {
//             cout << bigger << endl;
//             continue;
//         }

//         cout << -1 << endl;
//     }
//     return 0;
// }
