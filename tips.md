- エスケープシーケンス
    - ¥a      警報音
    - ¥b      バックスペース
    - ¥n      復帰改行
    - ¥r      復帰
    - ¥f      改ページ
    - ¥t      水平タブ
    - ¥v      垂直タブ
    - ¥¥      文字としての¥
    - ¥?      文字としての?
    - ¥'      シングルクォーテーション(')
    - ¥"      ダブルクォーテーション(")
    - ¥0      Null(ヌル)
    - ¥ooo    8進数の文字コードを持つ文字
    - ¥xhh    16進数の文字コードを持つ文字

- substrの使いかた
    - 言語仕様のコピーを見ておく
    - s.substr(start, length);
    - s.substr(start, end-start); ただし，[start, end)

- [string::nposの正体](https://qiita.com/yakigac/items/8797cc256d6dcbd5e36a)
    - [ICPC2017 国内予選 B ほとんど同じプログラム](https://simezi-tan.hatenadiary.org/entry/20171228/1514434586)の実装で使われている
    - string::findで値が見つからなかった場合に返す値として定義されています。
    - [【C++】std::stringで文字列が含まれるかどうかの判定【contains】](https://marycore.jp/prog/cpp/std-string-contains/)
        - C++の文字列クラスstd::stringには、特定の文字列が含まれているかどうかを判定するためのメンバ関数containsが定義されていません。代わりにfind関数の戻り値を判定することで、containsメソッドやincludesメソッドの代用を実現します。
        ```cpp
        std::string s = "abc";

        if (s.find("b") != std::string::npos) {
        puts("文字列`b`が見つかりました");
        }
        ```
    - [【C++入門】文字列を検索するfind関数(全検索、正規表現)](https://www.sejuku.net/blog/49318)
        - 詳しい使い方

- [C++で多次元配列の初期化方法。std::fill()の便利な使い方](https://qiita.com/oyas/items/70b7e29d0388392ef2ce)
    ```cpp
    // Graphには使えない
    // dp[][]みたいな普通の配列のみ
    template <typename A, size_t N, typename T>
    void Fill(A (&array)[N], const T& val)
    {
        std::fill((T*)array, (T*)(array + N), val);
    }
    ```

- 一番最後だけ改行
    - cout << "\ n" [a == N]
- [Clangのインスコ](https://students-tech.blog/post/install-clang.html#clang%E3%81%A8%E3%81%AF)
