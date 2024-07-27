#include "../header/set_window.h"

Set_window::Set_window(wxString title, const Set& _set, wxFrame* _menu)
    : wxFrame(NULL, wxID_ANY, title, wxDefaultPosition, wxSize(800, 600)), set(_set), menu(_menu) {

    wxPanel* panel = new wxPanel(this, wxID_ANY);

    std::set<Card> cards = set.get_cards();
    term = cards.begin()->get_term();

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
        this->Destroy();
    }else if(keyCode == WXK_RETURN){
        turn_card();
    }else if(keyCode == WXK_RIGHT){
        go_to_next_card(keyCode);
    }else if(keyCode == WXK_LEFT){
        go_to_next_card(keyCode);
    }
}

void Set_window::turn_card(){
    if(term == set.get_cards().begin()->get_term()){
        term = set.get_cards().begin()->get_answer();
    }else{
        set.get_cards().begin()->get_term();
    }
}

void Set_window::go_to_next_card(int keyCode){

}

