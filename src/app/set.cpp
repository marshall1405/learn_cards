#include "../header/set.h"
#include <iostream>

std::ostream& operator<<(std::ostream& COUT, const Set& s){
    for(auto card : s.cards){
        COUT << card;
    }
    return COUT;
}