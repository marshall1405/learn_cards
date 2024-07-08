#include "../header/card.h"
#include <iostream>

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