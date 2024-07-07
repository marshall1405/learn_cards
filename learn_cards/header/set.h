#ifndef SET_H
#define SET_H

#include "card.h"
#include <set>
#include <stdexcept>

class Set{
    private:
    std::set<Card, Card::CardComparator> cards;
    public:
    Set(std::set<Card, Card::CardComparator> _cards) : cards(_cards){
        if(cards.empty()){
            throw std::runtime_error("Set cannot be empty!");
        }
    }

    friend std::ostream& operator<<(std::ostream& COUT, const Set& s);
};



#endif