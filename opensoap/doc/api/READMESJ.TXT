=begin
= はじめに
 このディレクトリ以下にあるファイル郡は、
((<doxygen|URL:http://www.doxygen.org/>)) でドキュメントを生成するための
設定ファイルと、英語以外の言語用のリファレンスマニュアルの元ファイルです。
現在のところ、英語以外は日本語しか存在していません。
また、日本語の元ファイルの文字エンコードが EUC-JP となっているため、
コードセットが EUC-JP な環境で処理してください。

= リファレンスマニュアル生成方法
 各言語用のディレクトリに移動し、make docs を実行すれば、そのディレクトリ
以下に生成されます。ただし、doxygen がインストールされていないと生成されない
ので、doxygen インストール後、トップディレクトリに移り、./configure を
再実行した後、各言語用のディレクトリで make docs を実行してください。

=end
