#include "../include/defs.h"
#include "../include/trie.h"



Trie::Trie() {
    root = new Node(false);
}

Trie::~Trie() {
    delete root;
}

void Trie::insert(const char* word, defs::Limits& limits) {
    root->insert(word, limits);
}
void Trie::insert(const char* word) {
    root->insert(word);
}

std::string Trie::is_pref(const char* pref) const {
    unsigned int res = root->is_pref(pref);
    if (res == 0) {
        return std::string(pref) + " is not a prefix";
    }
    return  std::string(pref) + " is prefix of " + std::to_string(res) + " words";
}


defs::Words Trie::words() const {
    defs::Words w;
    std::string str;
    root->words(w, str);
    return w;
}