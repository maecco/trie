// Arvore principal
#pragma once

#include <string>

#include "defs.h"
#include "parser.h"

class Trie {
public:
    Trie();
    ~Trie();

    bool from_dict(const char* filename);

    void insert(const char* word, defs::Limits& limits);
    void insert(const char* word);
    
    std::string is_pref(const char* pref) const;
    
    std::string find(const char* word) const;

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
        unsigned int is_pref_of = 0;


        bool insert(const char* word, defs::Limits& limits) {
            if (*word == '\0' && !is_end) {
                is_end = true;
                this->limits = limits;
                is_pref_of++;
                return true;
            } else if (*word == '\0') {
                return false;
            }
            int idx = *word - 'a';
            if (children[idx] == nullptr) {
                children[idx] = new Node();
            }
            if (children[idx]->insert(word + 1, limits)) {
                is_pref_of++;
            }
        }

        bool insert(const char* word) {
            if (*word == '\0' && !is_end) {
                is_end = true;
                this->limits = defs::Limits();
                is_pref_of++;
                return true;
            } else if (*word == '\0') {
                return false;
            }
            int idx = *word - 'a';
            if (children[idx] == nullptr) {
                children[idx] = new Node();
            }
            if (children[idx]->insert(word + 1, limits)) {
                is_pref_of++;
            }
        }

        unsigned int is_pref(const char* pref) const {
            if (*pref == '\0') { return is_pref_of; }

            int idx = *pref - 'a';
            if (children[idx] == nullptr) { return 0; }
            return children[idx]->is_pref(pref + 1);
        }

        defs::Limits find(const char* word) const {
            if (*word == '\0' && is_end) {
                return limits;
            } else if (*word == '\0') {
                return defs::Limits();
            }
            int idx = *word - 'a';
            if (children[idx] == nullptr) {
                return defs::Limits();
            }
            return children[idx]->find(word + 1);
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

