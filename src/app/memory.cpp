#include "../header/memory.h"


Memory::Memory(std::set<Set>& _learning_sets) : learning_sets(_learning_sets){
    load_from_file();
    for(const auto& set : learning_sets){
        if(progress_map.find(set.get_name()) == progress_map.end()){
            progress_map[set.get_name()] = std::vector<int>();
        }
    }
}

Memory::~Memory(){
    save_to_file();
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
                save_file << *it;
                if (std::next(it) != set.second.end()) {
                    save_file << ", ";
                }
            }
            save_file << "\n";
        }
        save_file.close();
    }
}

void Memory::load_from_file() {
    std::ifstream in_file(SAVE_FILE);
    if (in_file.is_open()) {
        std::string line;
        while (std::getline(in_file, line)) {
            std::istringstream iss(line);
            std::string name;
            if (std::getline(iss, name, ':')) {
                std::vector<int> progress;
                std::string number, rest_of_line;
                if (!rest_of_line.empty()) {
                    std::istringstream values_stream(rest_of_line);
                    while (std::getline(values_stream, number, ',')) {
                        if (!number.empty()) {
                            int value = std::stoi(number);
                            progress.push_back(value);
                        }
                    }
                }
                progress_map[name] = progress;
            }
        }
        in_file.close();
    }
}



void Memory::calibrate(){
    for(auto set : learning_sets){
        if(progress_map[set.get_name()].size() == set.get_cards().size()){
            progress_map[set.get_name()].clear();
        }
    }
}


std::map<std::string, std::vector<int>> Memory::get_progress_map() const{
    return progress_map;
}