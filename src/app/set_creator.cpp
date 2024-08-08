#include "../header/set_creator.h"

Set_creator::Set_creator(std::string _path) : path(_path){

}

std::set<Set>& Set_creator::create_sets_from_txt(){
    std::ifstream MyReadFile(this->path);
    std::string line;
    int rank = 1;
    std::string set_name;
    std::set<Card> cards;
    std::set<Set> output;

    while(getline(MyReadFile, line)){
        if(line.find(",") == std::string::npos){
            if(!cards.empty()){
                output.insert(Set(set_name, cards));
            }
            cards.clear();
            set_name = line;
            rank = 1;
        }else{
            size_t comma_pos = line.find(",");
            size_t length = line.length();
            std::string term = line.substr(0, comma_pos);
            std::string answer = line.substr(comma_pos+2, length);
            Card c(rank, term, answer);
            cards.insert(c);
            rank++;
        }
    }

    output.insert(Set(set_name, cards));
    MyReadFile.close();
    return output;
}