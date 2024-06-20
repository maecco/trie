// Arvore principal
#pragma once

#include <string>

#include "defs.h"

class Trie {
public:
    Trie();
    ~Trie();

    void insert(const char* word, defs::Limits& limits);
    void insert(const char* word);
    
    std::string is_pref(const char* pref) const;

    defs::Words words() const;

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
        defs::Limits limits;

        void insert(const char* word, defs::Limits& limits) {
            if (*word == '\0') {
                is_end = true;
                this->limits = limits;
                return;
            }
            int idx = *word - 'a';
            if (children[idx] == nullptr) {
                children[idx] = new Node();
            }
            children[idx]->insert(word + 1, limits);
        }

        void insert(const char* word) {
            if (*word == '\0') {
                is_end = true;
                this->limits = defs::Limits();
                return;
            }
            int idx = *word - 'a';
            if (children[idx] == nullptr) {
                children[idx] = new Node();
            }
            children[idx]->insert(word + 1, limits);
        }

        int is_pref(const char* pref) const {

            if (*pref == '\0') { return is_end ? 1 : 0; }

            int idx = *pref - 'a';
            if (children[idx] == nullptr) { return 0; }
            
            return is_end ? 1 : 0 + children[idx]->is_pref(pref + 1);
        }

        void words(defs::Words& str, std::string& s) const {
            for (int i = 0; i < 26; i++) {
                if (children[i] != nullptr) {
                    s += std::string(1, (char)('a' + i));
                    if (children[i]->is_end) {
                        str.push_back(std::string(s));
                    }
                    
                    children[i]->words(str, s);
                    
                    s.pop_back();
                }
            }
        }

    };

    Node* root;
};

