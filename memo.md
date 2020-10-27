- 複数の入力を受け付けるには？
```cpp
// #1
while (cin >> n && n) {
        solve(n);
    }

// #2
for (int n; scanf("%d", &n) == 1 && n > 0;) {

// #3
while(1){
        int n;
        cin >> n;
        if(n==0) break;

        vector<int> a(n);
        int sum = 0;
        for(int i=0; i<n; i++){
            cin >> a[i];
            sum += a[i];
        }
        int ave = sum/n;
        int ans = 0;
        for(int i=0; i<n; i++){
            if(a[i] <= ave){
                ans++;
            }
        }
        cout << ans << endl;
    }
    return 0;
```


# 2016
- [審判長による国内予選講評（確定版）](https://icpc.iisf.or.jp/2016-tsukuba/review-by-chief-judge/?lang=ja)
    ## 2016B 当選者を探せ！
    - 最大値と2番目に大きい値を保持する方法
        - mxとmx_2みたいな
        - mxではなくmx_2より大きい場合->mx_2にそれを代入
        - mx_2がmxより大きい場合->mxとmx_2をswap

    ## 2016C 竹の花
    - エラトステネスの篩+素数定理
    - [忘れても大丈夫](http://kyopro.hateblo.jp/entry/2018/02/08/164121)
    - $k\leqq 7368791$のとき$O(k\log\log k)$の時間計算量となる

    ## 2016D ダルマ落とし
    - この手の「列の中の隣接する2項について処理を順次行う」というタイプの問題に対しては
        - スタックを用いたシミュレーション
        - 区間 DP
    - といった手法が有効であることが多い。前者の例として「カッコ列の整合性判定」、後者の例として「最適行列積計算を求めるDP」が有名だ。今回は後者のパターンになる。
        - dp[ i ][ j ] := 数列の区間 [i, j) に対して操作を施せる回数の最大値
    - としておく。このように区間 [i, j) をキーにもつような DP を区間 DP とよぶ人が多い。
        - [蟻本初級編](https://qiita.com/drken/items/e77685614f3c6bf86f44)
        - 区間に対する DP です。Monge 性は蟻本にない話題なのでどこかで学ぶ必要があります。通常の区間 DP は O(n^3) かかり、Monge 性を満たすと O(n^2) にすることができます。

    - 実装面
        - 環境によってはvector<vector<int> >のように> >とスペースをいれないといけないことも

    ## 2016E 3Dプリント
    - [忘れても大丈夫](http://kyopro.hateblo.jp/entry/2018/02/10/030143)
        - 実装はこれを参考に
        - [うさぎ小屋](https://kimiyuki.net/writeup/algo/etc/icpc-2016-domestic-e/)
            - こっちのほうがわかりやすいかも
    - [図はこれがわかりやすい](https://www.cse.kyoto-su.ac.jp/~hiraishi/ICPC/ICPC2016/Domestic/ICPC2016_DomE/ICPC2016_DomE.pdf)

    - 立方体を頂点，重なる面積を重みとする辺としてグラフを構築
    - 連結成分の重み最大化
    - 2つ以上の立方体が同時に重ならないことのメリットについてしっかり考察する
        - 重なり部分が一度出せれば，あとはそこを引くだけで全体の面積が出せる
        - これは立方体がいくつに増えても再帰的に適用できる

    - kが2以下のときに注意せよ

    - $k$個以上の連結成分が存在しない場合はどうすればよいのだろうか
        - 「$k$個の立方体の併合としてひとつの連結した多面体を得る」->この表現的に，上記は前提してよいのかも
        - 「連結した多面体を構成する k 個の立方体がない場合は -1 を出力せよ．」->確定．
    - 再帰呼び出しのあるラムダ式は次のように定義します。返り値の型と引数の型をfunction<>の中に書いたうえ、[&]と書く必要があることに注意して下さい。
        - function<返り値の型(引数の型1, 引数の型2, ...)> 関数名 = [&](引数の型1 引数名1, 引数の型2, 引数名2, ...) { 関数の処理 };


# 2017
- [審判団講評](https://icpc.iisf.or.jp/2017-tsukuba/wp-content/uploads/sites/4/2017/07/commentary-fontEmb.pdf)
## 2017B ほとんど同じ
- [ウサギ小屋](https://kimiyuki.net/writeup/algo/etc/icpc-2017-domestic-b/)
    - Pythonを使うべき
    - [ICPC2017 B問題200点 「ほとんど同じプログラム」 (copy)](ICPC2017 B問題200点 「ほとんど同じプログラム」 (copy))
      - split関数を覚えよう
      - "でsplitかけると，偶数番目が文字定数，奇数番目がそれ以外，となる
      - 実際の実装は[これ](https://simezi-tan.hatenadiary.org/entry/20171228/1514434586)を見るのが良い
      - split関数の書き方
        ```cpp
        auto split = [](string s, char d) {
            vector<string> ans;
            int p, cnt = 0;
            while ((p = s.find(d)) != s.npos) {
                ans.push_back(s.substr(0, p));
                s = s.substr(p + 1);
            }
            if (s.size()) // 最後も残ってたら
                ans.pb(s);
            return ans;
        };
        ```
        ```cpp
        split(s, "\""); // みたいに使う
        ```
    - 上の実装だと，例えば「"""42"""」みたいな"が続く場合はそこに空文字が入ることになる（実際にコードを追ってみるとわかる」

# 2018
- [審判長講評](https://icpc.iisf.or.jp/2018-yokohama/wp-content/uploads/sites/5/2018/08/commentary.pdf)
## 2018C 超高層ビル「みなとハルカス」
- しゃくとり法だと無理そう
- 時間制限8secなので実はいけた説
- この不等式をgetするの無理じゃね？
- [はまやん](https://www.hamayanhamayan.com/entry/2018/07/08/112205)
- [ツバサの備忘録](https://emtubasa.hateblo.jp/entry/2019/03/19/222913)
  - n=sqrt(b)が上限とわかる
    - この理由がよくわからん
    - $c$の列挙は$O(\sqrt(b))$で行えるので，$[1,\sqrt{2b}]$からiを取り出し，$2b$が$i$で割り切れるとき，$i$および$2b/i$が$c$の候補になる
    - これが一番わかりやすかった
- [二分探索](https://kimiyuki.net/writeup/algo/etc/icpc-2018-domestic-c/)

## 2018D 全チームによるプレーオフ
- リーグ戦苦手
- ここらで苦手克服しておくべきか？
- バックトラッキングによる全探索
- 全探索という手法を選択できるのか？
    - [はまやん](https://www.hamayanhamayan.com/entry/2018/07/15/225020)
        - これが一番わかりやすかった


- clang
