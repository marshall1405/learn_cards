#include "../header/card.h"
#include <iostream>


Card::Card(int _rank, std::string _term, std::string _answer) : rank(_rank), term(_term), answer(_answer){
    if(term.length() == 0 || answer.size() == 0 || term == answer){
        throw std::runtime_error("Term or Answer empty or same!");
    }
}

bool Card::CardComparator::operator()(const Card& c1, const Card& c2) const {
    return c1.rank < c2.rank;
}

bool operator==(const Card& c1, const Card& c2){
    return c1.term == c2.term;
}

std::ostream& operator<<(std::ostream& COUT, const Card& c){
    COUT << c.term << "\n";
    return COUT;
}