// Arvore principal
#pragma once

#include <string>

#include "datastructs.h"

class Trie {
    public:
    Trie();
    ~Trie();

    void insert(const char* word, dstructs::Limits& limits);
    std::string is_pref(const char* pref) const;

 private:
    struct Node {
    Node(bool is_end = false) : is_end(is_end) {
        for (int i = 0; i < 26; i++) {
            children[i] = nullptr;
        }
    }
    ~Node() {
        for (int i = 0; i < 26; i++) {
            if (children[i] != nullptr) {
            delete children[i];
            }
        }
    };
    Node* children[26];
    bool is_end;
    dstructs::Limits limits;

    void insert(const char* word, dstructs::Limits& limits);
    int is_pref(const char* pref) const;
    };

    Node* root;
};

