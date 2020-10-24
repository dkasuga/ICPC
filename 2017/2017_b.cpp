#include <bits/stdc++.h>
#include <math.h>

using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
typedef long long ll;
const int MOD = 1000000007;
const int INF_32 = 1LL << 30;
const int64_t INF_64 = 1LL << 60;

// my_ans
//テキトーにパースする解法
/*
""""""""
"""42"""""
とかをDIFFERENTにしてしまう(それ以外のサンプルケースはok)
*/
string s1, s2;

void parse(string& s, vector<string>& p)
{
    int size = s.size();
    int q_cnt = 0;
    int start, end;
    start = end = 0;
    bool mode = false; // trueで文字定数モード，falseでそれ以外
    for (int i = 0; i < size; i++) {
        if (s[i] == '\"') {
            q_cnt++;
            if (mode) { // 文字定数モードだったら
                end = i;
                p.push_back('*' + s.substr(start, end - start)); // 文字定数を挿入
                mode = false;
                start = i;
            }
        } else {
            if (q_cnt % 2 == 1 and not mode) { // 奇数番目の"のあとに文字列がスタート
                end = i;
                p.push_back(s.substr(start, end - start)); // そこまでの結果を挿入
                mode = true;
                start = i;
            }
        }
    }
    p.push_back(s.substr(start, size - start));
}

int main()
{
    while (true) {
        cin >> s1;
        cin >> s2;
        if (s1 == ".")
            break;
        vector<string> p1, p2; // パースした結果を入れていく

        parse(s1, p1);
        parse(s2, p2);

        if (p1.size() != p2.size()) {
            cout << "DIFFERENT1" << endl;
            continue;
        }

        bool flag = false;
        int diff_cnt = 0;
        for (int i = 0; i < p1.size(); i++) {
            if (p1[i][0] == '*' && p2[i][0] == '*') {
                if (p1[i] != p2[i])
                    diff_cnt++;
            } else {
                if (p1[i] != p2[i]) {
                    flag = true;
                    break;
                }
            }
        }

        if (flag || diff_cnt > 1) {
            cout << "DIFFERENT" << endl;
            continue;
        }

        if (diff_cnt == 1) {
            cout << "CLOSE" << endl;
            continue;
        }

        cout << "IDENTICAL" << endl;
    }

    return 0;
}
