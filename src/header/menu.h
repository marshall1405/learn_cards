#ifndef MENU_H
#define MENU_H
#include <wx/wx.h>
#include <wx/listbox.h>
#include "set.h"
#include "memory.h"


class Menu : public wxFrame{
    std::set<Set>& learning_sets;
    Memory* memory;
    wxListBox* box;
    
    public:
    Menu(const wxString& title, std::set<Set>& _learning_sets);

    void going_back();

    private:

    void menu_controls(wxKeyEvent& event);

    void go_into_set();
};


#endif