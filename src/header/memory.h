#ifndef MEMORY_H
#define MEMORY_H

#include <string>
#include <fstream>

class Memory{
    const std::string SAVE_FILE = "../memory.txt";
public:
    Memory();

    void add_to_memory(std::string set_name, size_t progress);

    size_t recall_from_memory(std::string set_name);

};


#endif