#include "../header/card.h"
#include <iostream>


Card::Card(int _rank, std::string _term, std::string _answer) : rank(_rank), term(_term), answer(_answer){
    if(term.length() == 0 || answer.size() == 0 || term == answer){
        throw std::runtime_error("Term or Answer empty or same!");
    }
}

bool Card::operator<(const Card& other) const {
    return rank < other.rank;
}

bool Card::operator>(const Card& other) const {
    return rank > other.rank;
}

bool Card::operator<=(const Card& other) const {
    return rank <= other.rank;
}

bool Card::operator>=(const Card& other) const {
    return rank < other.rank;
}

bool operator==(const Card& c1, const Card& c2){
    return c1.term == c2.term;
}

const std::string& Card::get_answer() const{
    return answer;
}

const std::string& Card::get_term() const{
    return term;
}

int Card::get_rank() const{
    return rank;
}