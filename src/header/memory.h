#ifndef MEMORY_H
#define MEMORY_H

#include <string>
#include <fstream>
#include <sstream>
#include <map>
#include <vector>
#include "set.h"

class Memory{
    std::map<std::string, std::vector<int>> progress_map;
    std::set<Set>& learning_sets;
    const std::string SAVE_FILE = "../memory.txt";
public:
    Memory(std::set<Set>& _learning_sets);

    ~Memory();

    void add_to_memory(std::string set_name, size_t progress);

    std::vector<int> recall_from_memory(std::string set_name);

    void load_from_file();

    void save_to_file() const;

    void calibrate();

    std::map<std::string, std::vector<int>> get_progress_map() const;
};


#endif