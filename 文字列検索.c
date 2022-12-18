/**
 * 文字列検索アルゴリズムを作成してみた。
 * 『2022年度版 ニュースペックテキスト応用情報技術者』p.62をもとに作成。
 *
 * 初版作成：2022.12.18
 */
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#define NOT_FOUND_INDEX -1

// プロトタイプ宣言
int search_word_index(char* word, char* from);
void print_result(int index, char *word, char *from);

int main() {
    // 検索する文字列句
    char *word = "your";

    // 検索元の文字列(1) 存在する場合
    char *from1 = "fgaliuwgfelaugyourfeagliyuwfebva";
    //                           ^^^^
    // 検索・結果を表示
    int word_index1 = search_word_index(word, from1);
    print_result(word_index1, word, from1);
    
    // 出力結果：
    // yourが14文字目にありました！
    // fgaliuwgfelaugyourfeagliyuwfebva
    //               ^^^^

    
    // 検索元の文字列(2) 存在しない場合
    char *from2 = "fgaliuwgfelaugyorfeagliyuwfebva";
    // 検索・結果を表示
    int word_index2 = search_word_index(word, from2);
    print_result(word_index2, word, from2);

    // 出力結果：
    // yourは見つかりませんでした。

    return 0;
}

/**
 * @brief 検索対象wordと部分一致する文字列fromからの先頭のindexを返します。
 * @param word 検索対象文字列
 * @param from 検索元文字列
 *
 * @return NOT_FOUND_INDEX以外 文字列from内におけるwordと一致する部分の先頭index
 * @return NOT_FOUND_INDEX wordと一致する部分が見つからなかった
 */
int search_word_index(char* word, char* from) {
    int from_length = strlen(from);
    int word_length = strlen(word);
    
    for(int i = 0; i < from_length - word_length; i++) {
        // 検索対象文字列の頭文字が不一致ならば、次の文字の処理に進む
        if(from[i] != word[0]) {
            continue;
        }

        // 頭文字のindexを基準に検索を行う
        bool isMatch = true;
        for(int j = 1; j < word_length; j++) {
            if(from[i + j] != word[j]) {
                isMatch = false;
                break;
            }
        }

        // 一致する箇所があれば先頭のindexを返す
        if(isMatch) {
            return i;
        }
    }

    return NOT_FOUND_INDEX;
}

/**
 * @brief 検索結果からメッセージを標準出力に出力します。
 * @param 文字列のindex（存在しない場合はNOT_FOUND_INDEX）
 */
void print_result(int index, char *word, char *from) {
    if(index == NOT_FOUND_INDEX) {
        printf("%sは見つかりませんでした。\n", word);
    } 
    else {
        printf("%sが%d文字目にありました！\n", word, index);
        printf("%s\n", from);

        int word_length = strlen(word);
        for(int i = 0; i < index; i++) {
            printf(" ");
        }
        for(int i = 0; i < word_length; i++) {
            printf("^");
        }
        printf("\n");
    }
}

