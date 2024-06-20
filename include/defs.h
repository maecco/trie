// Para devinir estruturas de dados a serem utilizadas
#pragma once
#include <string>
#include <utility>
#include <vector>
#include <map>

namespace defs {
    typedef std::pair<unsigned long, unsigned long> Limits;
    typedef std::vector<std::string> Words;
    typedef std::map<std::string, Limits> wordMap;
}
