#include <iostream>
#include "../header/card.h"
#include "../header/set.h"


int main(){
    Card c1 = Card(1, "Hello", "World");
    Card c2 = Card(2, "World", "Hello");
    std::set<Card, Card::CardComparator> s = {c1,c2};
    Set set = Set(s);

    std::cout << set;
    return 0;
}