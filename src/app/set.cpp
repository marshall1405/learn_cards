#include "../header/set.h"
#include <iostream>
#include <stdexcept>


Set::Set(std::string _name, std::set<Card> _cards) : name(_name), cards(_cards){
    if(cards.empty()){
        throw std::runtime_error("Set cannot be empty!");
    }
    if(name.length() == 0){
        throw std::runtime_error("Set name Cannot be empty!");
    }
}

bool Set::operator<(const Set& other) const {
    return name < other.name;
}

bool Set::operator>(const Set& other) const{
    return name > other.name;
}

bool Set::operator<=(const Set& other) const {
    return name <= other.name;
}

bool Set::operator>=(const Set& other) const {
    return name >= other.name;
}

std::ostream& operator<<(std::ostream& COUT, const Set& s){
    COUT << s.name;
    return COUT;
}