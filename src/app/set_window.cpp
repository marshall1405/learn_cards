#include "../header/set_window.h"

Set_window::Set_window(wxString title, const Set& _set, wxFrame* _menu): wxFrame(NULL, wxID_ANY, title, wxDefaultPosition, wxSize(800, 600)), set(_set), menu(_menu) {
    wxPanel* panel = new wxPanel(this, wxID_ANY);
    wxBoxSizer* vbox = new wxBoxSizer(wxVERTICAL);

    wxStaticText* text = new wxStaticText(panel, wxID_ANY, "Displaying: " + set.get_name());
    vbox->Add(text, 1, wxALIGN_CENTER | wxTOP, 20);

    panel->Bind(wxEVT_KEY_DOWN, &Set_window::set_window_controls, this);

    panel->SetSizer(vbox);
}


void Set_window::set_window_controls(wxKeyEvent& event){
    int keyCode = event.GetKeyCode();
    if(keyCode == WXK_BACK){
        menu->Show();
    }
    this->Destroy();
}



