#ifndef SET_WINDOW_H
#define SET_WINDOW_H

#include <wx/wx.h>
#include "set.h"
#include "menu.h"

class Set_window : public wxFrame {
    Set set;
    const Card* current_card;
    Menu* menu;
    wxString term;
    wxString answer;
    wxStaticText* static_text;

public:
    Set_window(wxString title,const Set& _set, Menu* _menu);

private:

    void set_window_controls(wxKeyEvent& event);

    void go_to_next_card(int keyCode);
};

#endif
