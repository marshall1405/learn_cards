#include "../header/set_window.h"

Set_window::Set_window(const wxString& title, const Set& _set): wxFrame(NULL, wxID_ANY, title, wxDefaultPosition, wxSize(300, 200)), set(_set) {
    wxPanel* panel = new wxPanel(this, wxID_ANY);
    wxBoxSizer* vbox = new wxBoxSizer(wxVERTICAL);

    wxStaticText* text = new wxStaticText(panel, wxID_ANY, "Displaying: " + set.get_name());
    vbox->Add(text, 1, wxALIGN_CENTER | wxTOP, 20);

    panel->SetSizer(vbox);
}
