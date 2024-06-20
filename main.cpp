#include <iostream>
#include "trie.h"

int main() {
    
    // using namespace std;

    // string filename;
    // string word;

    // cin >> filename;  // entrada

    // cout << filename << endl;  // esta linha deve ser removida
    
    // while (1) {  // leitura das palavras ate' encontrar "0"
    //     cin >> word;
    //     if (word.compare("0") == 0) {
    //         break;
    //     }
    //     cout << word << endl;
    // }

    Trie trie;

    trie.insert("bell");
    trie.insert("bells");
    trie.insert("bellboy");
    trie.insert("bellboys");
    trie.insert("candle");
    trie.insert("candles");
    trie.insert("apple");
    trie.insert("apples");

    defs::Words w = trie.words();
    
    for (auto& word : w) {
        std::cout << word << std::endl;
    }

    return 0;
}
