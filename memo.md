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

# 2018C 超高層ビル「みなとハルカス」
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

# 2018D 全チームによるプレーオフ
- リーグ戦苦手
- ここらで苦手克服しておくべきか？
- バックトラッキングによる全探索
- 全探索という手法を選択できるのか？
    - [はまやん](https://www.hamayanhamayan.com/entry/2018/07/15/225020)
        - これが一番わかりやすかった
