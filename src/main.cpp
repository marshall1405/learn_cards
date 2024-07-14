#include <wx/wx.h>
#include <iostream>
#include <sstream>
#include "./header/card.h"
#include "./header/set.h"
#include "./header/menu.h"

class learn_cards : public wxApp{
    public:
    virtual bool OnInit();
};

Card c1(1, "SE1", "Block1");
Card c2(1, "SE1", "Block2");
Card c3(1, "SE1", "Block3");
Card c4(1, "SE1", "Block4");
Card c5(1, "SE1", "Block5");
Card c6(1, "SE1", "Block6");

std::set<Card, Card::CardComparator> block1 = {c1};
std::set<Card, Card::CardComparator> block2 = {c2};
std::set<Card, Card::CardComparator> block3 = {c3};
std::set<Card, Card::CardComparator> block4 = {c4};
std::set<Card, Card::CardComparator> block5 = {c5};
std::set<Card, Card::CardComparator> block6 = {c6};

Set s1("SE1 Block1", block1);
Set s2("SE1 Block2", block2);
Set s3("SE1 Block3", block3);
Set s4("SE1 Block4", block4);
Set s5("SE1 Block5", block5);
Set s6("SE1 Block6", block6);

std::set<Set> sets = {s1,s2,s3,s4,s5,s6};

wxIMPLEMENT_APP(learn_cards);

bool learn_cards::OnInit(){
    Menu* menu = new Menu("Menu", sets);
    menu->SetClientSize(800,600);
    menu->Center();
    menu->Show();
    return true;
}

