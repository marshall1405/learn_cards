#ifndef SET_WINDOW_H
#define SET_WINDOW_H

#include <wx/wx.h>
#include "set.h"

class Set_window : public wxFrame {
    Set set;

public:
    Set_window(const wxString& title, const Set& _set);
};

#endif
