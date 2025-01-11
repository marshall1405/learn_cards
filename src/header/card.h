#ifndef CARD_H
#define CARD_H

#include <string>
#include <stdexcept>
#include <iostream>


class Card{
    private:
    int rank;
    bool showing_term = true;
    std::string term;
    std::string answer;

    public:
    Card(int _rank, std::string _term, std::string _answer);
    
    bool operator<(const Card& other) const;

    bool operator>(const Card& other) const;

    bool operator<=(const Card& other) const;

    bool operator>=(const Card& other) const;
    
    friend bool operator==(const Card& c1, const Card& c2);
    
    const std::string& get_term() const;

    const std::string& get_answer() const;

    int get_rank() const;
};

#endif