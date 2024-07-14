#ifndef MENU.H
#define MENU.H
#include <wx/wx.h>
#include "set.h"


class Menu : public wxFrame{
    std::set<Set> learning_sets;
    public:
    Menu(const wxString& title, std::set<Set> _learning_sets);
};


#endif