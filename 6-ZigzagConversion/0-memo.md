# 6. Zigzag Conversion
# はじめに
- Step1
    - 初見で解く
    - 知らなければできないことは調べる
- Step2
    - なんでも使ってコードを洗練させる
- 他の人の回答を見る
- Step3
    - 何も見ずにStep1の思考でStep2と同等のコードを3回繰り返してすらすら書く

 # step1
 インデックスの計算だけして行けば答えを求められそうだと思った
 とりあえず、問題文の操作をそのままシミュレーションすることにした
 （実際にジグザグに文字を配置していって、その後行ごとにくっつける）

 i番目の文字が、ジグザグにおいていったときに何行目に来るかの計算で少し手こずった

 ここまで20分

 インデックスの計算だけを行って答えの文字列を一つずつ追加していく方針でもやってみた`1-index_only.cpp`
 インデックスの計算がやはり面倒だし、あまり分かりやすくない気がする


 # step2
 特にロジックで変更点はなく、変数名などを整えた

 # 他の人の回答を見る
 https://github.com/Ryotaro25/leetcode_first60/pull/66/files

シミュレーションを行うのは同じだが、rowを1ずつインクリメント/デクリメントしていく 回答が多かった。
確かに、そっちの方がより分かりやすい。手作業でやるとなった時も、そのようにして行うはずである

あと最初にエッジケース（s.size() < numRows や　numRows==1 の場合）を処理している回答も多かった
エッジケースを処理した方が見通しが良くなるので、自分もそうするべきだった。

https://cpprefjp.github.io/reference/numeric/reduce.html
https://cpprefjp.github.io/reference/numeric/accumulate.html
reduceとaccumulateは知らなかった

文字列を高速に連結する処理として以下が紹介されていた
https://www.reddit.com/r/cpp_questions/comments/wxiyg1/most_efficient_way_to_concatenate_strings/
```cpp
template<typename ... Ts>
std::string concat( Ts&& ... ts )
{
   const auto size = ( std::string_view{ ts }.size() + ... );
   std::string res;
   res.reserve( size );
   ( res.append( ts ), .... );
   return res;
}
```
何をやってるか全然わからなかったのでGPTに聞いてみた
https://cpprefjp.github.io/lang/cpp11/variadic_templates.html
可変長引数によって、任意個数・任意型の引数を受け取れるようにしている

https://cpprefjp.github.io/lang/cpp17/folding_expressions.html
`( res.append( ts ), .... );`みたいな書き方を知らなかったフォールド式というらしい

連結後の文字列用のメモリ確保を、一回で済ませることで高速化している模様

文字列のコピーやメモリの確保が結構思い処理というのは頭に入れておいた方が良さそう
最後、文字列の連結を行うときも、メモリを一度に確保しておいて、連結する時も参照を使うことで無駄なコピーを避けることができる
```cpp
result.reserve(s.size());
for (const auto& str : convert_array)
```

https://github.com/Ryotaro25/leetcode_first60/pull/66/files#r2033377168
ここら辺の話は勉強になった

# step3
rowを+1/-1ずつ変化させていく
エッジケースを最初に処理してしまう

3回書き直し


