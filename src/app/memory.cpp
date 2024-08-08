#include "../header/memory.h"


Memory::Memory(std::set<Set> learning_sets){
    for(const auto& set : learning_sets){
        if(progress_map.find(set.get_name()) == progress_map.end()){
            progress_map[set.get_name()] = std::vector<int>();
        }
    }
}

void Memory::add_to_memory(std::string set_name, size_t progress){
    progress_map[set_name].push_back(progress);
}


std::vector<int> Memory::recall_from_memory(std::string set_name){
    auto it = progress_map.find(set_name);
    if(it != progress_map.end()){
        return it->second;
    }else{
        return std::vector<int>();
    }
}

void Memory::save_to_file() const{
    std::ofstream save_file(SAVE_FILE);
    if(save_file.is_open()){
        for(const auto& set : progress_map){
            save_file << set.first << ": ";
            for(auto it = set.second.begin(); it != set.second.end(); it++){
                save_file << &it << ", ";
            }
            save_file << "\n";
        }
        save_file.close();
    }
}

void Memory::load_from_file() const{
    std::ifstream load(SAVE_FILE);
    if(load.is_open()){
        std::string name;
        std::vector<int> studied_cards;
        while(load >> name >> studied_cards){
            
        }
    }
}