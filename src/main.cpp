#include <wx/wx.h>
#include <iostream>
#include <sstream>
#include <functional>
#include "./header/card.h"
#include "./header/set.h"
#include "./header/menu.h"
#include "./header/set_creator.h"

class learn_cards : public wxApp{
    public:
    virtual bool OnInit();
};

wxIMPLEMENT_APP(learn_cards);

bool learn_cards::OnInit(){
    Set_creator creator("../test.txt");
    std::set<Set> sets = creator.create_sets_from_txt();
    Menu* menu = new Menu("Menu", std::ref(sets));
    menu->SetClientSize(800,600);
    menu->Center();
    menu->Show();
    return true;
}

