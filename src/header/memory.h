#ifndef MEMORY_H
#define MEMORY_H

#include <string>
#include <fstream>
#include <map>
#include <vector>
#include "set.h"

class Memory{
    std::map<std::string, std::vector<int>> progress_map;
    const std::string SAVE_FILE = "../memory.txt";
public:
    Memory(std::set<Set> _learning_sets);

    void add_to_memory(std::string set_name, size_t progress);

    std::vector<int> recall_from_memory(std::string set_name);

    void load_from_file() const;

    void save_to_file() const;
};


#endif