#include "../include/parser.h"
#include "../include/defs.h"



Parser::Parser() {
}

Parser::~Parser() {
}

bool Parser::parseFrom(const char* path) {
    std::ifstream  file(path);
    if (!file.is_open()) {
        std::cerr << "Error opening file" << std::endl;
        return false;
    }
    _buildMap(file);
    return true;
}

defs::Limits Parser::getWord(std::string& word) const {
    auto it = _map.find(word);
    if (it == _map.end()) {
        return defs::Limits();
    }
    return it->second;
}

void Parser::_buildMap(std::ifstream& file) {
    std::string line;
    unsigned int start_offset = 0;
    while (std::getline(file, line)) {
        std::string word;
        unsigned long start, lenght, endword;
        start = start_offset;
        start_offset += line.size() + 1;
        
        endword = line.find(']');
        word = line.substr(1, endword - 1);
        lenght = line.size();

        _map[word] = defs::Limits(start, lenght);
    }
}