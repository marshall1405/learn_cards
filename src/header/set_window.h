#ifndef SET_WINDOW_H
#define SET_WINDOW_H

#include <wx/wx.h>
#include <algorithm>
#include "set.h"
#include "menu.h"
#include "memory.h"

class Set_window : public wxFrame {
    const Set& set;
    size_t set_size;
    const Card* current_card;
    Menu* menu;
    wxString term;
    wxString answer;
    wxStaticText* progress_text;
    wxStaticText* static_text;
    int progress = 0;
    std::vector<int>& studied_cards;

public:
    Set_window(wxString title,const Set& _set, Menu* _menu, std::vector<int>& _studied_cards);

private:
    void set_window_controls(wxKeyEvent& event);

    void go_to_next_card(int key_code);

    void update_progress_text(int card);

    void got_card_right();

    void got_card_wrong();

    int find_next_card(bool first_search);
};

#endif
