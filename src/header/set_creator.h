#ifndef SET_CREATOR_H
#define SET_CREATOR_H
#include <fstream>
#include "../header/card.h"
#include "../header/set.h"

class Set_creator{
    std::string path;
public:
    Set_creator(std::string _path);

    std::set<Set>& create_sets_from_txt();
};


#endif