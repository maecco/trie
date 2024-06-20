// Recebe o caminho com o dicionario e retora um mapa entre a palavra
// e os limites da sua definiçao no arquivo.
#pragma once
#include "../include/defs.h"
#include <iostream>
#include <fstream>


struct Parser {

    Parser();
    ~Parser();
    bool parseFrom(const char* path);

    defs::Limits getWord(std::string& word) const;


// private:

    defs::wordMap _map;

    void _buildMap(std::ifstream& file);
};