#ifndef MENU_H
#define MENU_H
#include <wx/wx.h>
#include <wx/listbox.h>
#include "set.h"


class Menu : public wxFrame{
    std::set<Set> learning_sets;
    wxListBox* box;
    
    public:
    Menu(const wxString& title, std::set<Set> _learning_sets);

    private:

    void menu_controls(wxKeyEvent& event);

    void goIntoSet();

};


#endif