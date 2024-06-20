#include <iostream>
#include "trie.h"

int main() {
    
    using namespace std;

    string filename;
    string word;

    cin >> filename;  // entrada

    Trie trie;
    trie.from_dict(filename.c_str());
    
    while (1) {  // leitura das palavras ate' encontrar "0"
        cin >> word;
        if (word.compare("0") == 0) {
            break;
        }
        cout << trie.find(word.c_str());
        cout << trie.is_pref(word.c_str());
    }

}
