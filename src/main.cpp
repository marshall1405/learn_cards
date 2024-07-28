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
Card c2(2, "SE1", "Block2");
Card c3(3, "SE1", "Block3");
Card c4(4, "SE1", "Block4");
Card c5(5, "SE1", "Block5");
Card c6(6, "SE1", "Block6");

std::set<Card> block1 = {c1,c2,c3};
std::set<Card> block2 = {c4,c5,c6};

Set s1("SE1 Test1", block1);
Set s2("SE1 Test2", block2);

std::set<Set> sets = {s1,s2};

wxIMPLEMENT_APP(learn_cards);

bool learn_cards::OnInit(){
    Menu* menu = new Menu("Menu", sets);
    menu->SetClientSize(800,600);
    menu->Center();
    menu->Show();
    return true;
}

