#include "../include/defs.h"
#include "../include/trie.h"



Trie::Trie() {
    root = new Node(false);
}

Trie::~Trie() {
    delete root;
}

bool Trie::from_dict(const char* filename) {
    Parser p = Parser();
    if ( !p.parseFrom(filename) ) { return false; }

    defs::wordMap map = p.getMap();
    for (auto& [word, limits] : map) {
        insert(word.c_str(), limits);
    }
    return true;
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
        return std::string(pref) + " is not a prefix\n";
    }
    return  std::string(pref) + " is prefix of " + std::to_string(res) + " words\n";
}

std::string Trie::find(const char* word) const {
    defs::Limits l = root->find(word);
    if (l.first == 0 && l.second == 0) { return ""; }
    
    std::string res = std::string(word) + " is at (" \
    + std::to_string(l.first) + ", " + std::to_string(l.second) + ")\n";

    return res;
}

defs::Words Trie::words() const {
    defs::Words w;
    std::string str;
    root->words(w, str);
    return w;
}