#ifndef CARD_H
#define CARD_H

#include <string>
#include <stdexcept>
#include <iostream>


class Card{
    private:
    int rank;
    std::string term;
    std::string answer;

    public:
    Card(int _rank, std::string _term, std::string _answer);
    
    bool operator<(const Card& other) const;

    bool operator>(const Card& other) const;

    bool operator<=(const Card& other) const;

    bool operator>=(const Card& other) const;
    
    friend bool operator==(const Card& c1, const Card& c2);

    friend std::ostream& operator<<(std::ostream& COUT, const Card& c);
};

#endif