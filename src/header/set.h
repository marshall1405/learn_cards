#ifndef SET_H
#define SET_H

#include "card.h"
#include <set>

class Set{
    private:
    std::string name;
    std::set<Card, Card::CardComparator> cards;
    public:
    Set(std::string _name, std::set<Card, Card::CardComparator> _cards);

    bool operator<(const Set& other) const;

    bool operator>(const Set& other) const;

    bool operator<=(const Set& other) const;

    bool operator>=(const Set& other) const;
    
    friend std::ostream& operator<<(std::ostream& COUT, const Set& s);

    std::string get_name() const{
        return name;
    }
};



#endif