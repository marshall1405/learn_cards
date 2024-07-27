#ifndef SET_WINDOW_H
#define SET_WINDOW_H

#include <wx/wx.h>
#include "set.h"
#include "menu.h"

class Set_window : public wxFrame {
    Set set;
    wxFrame* menu;
    wxString term;
public:
    Set_window(wxString title, const Set& _set, wxFrame* _menu);

private:

    void set_window_controls(wxKeyEvent& event);

    void turn_card();

    void go_to_next_card(int keyCode);
};

#endif
