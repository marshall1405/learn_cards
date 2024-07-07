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
    Card(int _rank, std::string _term, std::string _answer) : rank(_rank), term(_term), answer(_answer){
        if(term.length() == 0 || answer.size() == 0){
            throw std::runtime_error("Term or Answer empty");
        }
    }

    struct CardComparator {
        bool operator()(const Card& c1, const Card& c2) const;
    };

    friend bool operator==(const Card& c1, const Card& c2);

    friend std::ostream& operator<<(std::ostream& COUT, const Card& c);
};

#endif