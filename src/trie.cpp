#include <string>
#include "trie.h"



Trie::Trie() {
    root = new Node(false);
}

Trie::~Trie() {
    delete root;
}

void Trie::insert(const char* word, dstructs::Limits& limits) {
    root->insert(word, limits);
}

std::string Trie::is_pref(const char* pref) const {
    int res = root->is_pref(pref);
    return "bell is prefix of " + std::to_string(res) + " words";
}
