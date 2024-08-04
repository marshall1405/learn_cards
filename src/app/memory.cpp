#include "../header/memory.h"

void Memory::add_to_memory(std::string set_name, size_t progress){
    std::string line;
    std::ifstream MyReadFile(SAVE_FILE);
    size_t line = 0;
    /*
    while(getLine(MyReadFile, line)){
        if()
    }
    */
    std::ofstream outFile(SAVE_FILE);
    outFile << set_name << ", " << progress;
    outFile.close();
}


size_t Memory::recall_from_memory(std::string set_name){
    return 1;
}