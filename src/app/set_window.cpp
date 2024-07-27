#include "../header/set_window.h"

Set_window::Set_window(wxString title,const Set& _set, Menu* _menu) : wxFrame(NULL, wxID_ANY, title, wxDefaultPosition, wxSize(800, 600)), set(_set), menu(_menu) {

    wxPanel* panel = new wxPanel(this, wxID_ANY);

    this->current_card = &*set.get_cards().begin();

    wxStaticText* staticText = new wxStaticText(panel, wxID_ANY, term, wxDefaultPosition, wxDefaultSize, wxALIGN_CENTER);

    wxFont font = staticText->GetFont();
    font.SetPointSize(24);
    staticText->SetFont(font);

    wxBoxSizer* sizer = new wxBoxSizer(wxVERTICAL);
    sizer->Add(staticText, 1, wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL | wxALL, 10); // Center and add padding

    panel->SetSizerAndFit(sizer);

    panel->Bind(wxEVT_KEY_DOWN, &Set_window::set_window_controls, this);
}



void Set_window::set_window_controls(wxKeyEvent& event){
    int keyCode = event.GetKeyCode();
    if(keyCode == WXK_BACK){
        menu->Show();
        menu->Raise();
        menu->going_back();
        this->Destroy();
    }else if(keyCode == WXK_RETURN){
        std::string text = turn_card();
    }else if(keyCode == WXK_RIGHT){
        go_to_next_card(keyCode);
    }else if(keyCode == WXK_LEFT){
        go_to_next_card(keyCode);
    }
}


std::string Set_window::turn_card(){
    return "cock";
}

void Set_window::go_to_next_card(int keyCode){

}

