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

wxIMPLEMENT_APP(learn_cards);

bool learn_cards::OnInit(){
    Menu* menu = new Menu("Menu");
    menu->Show();
    return true;
}
