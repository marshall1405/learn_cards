#include "../header/set_window.h"

Set_window::Set_window(wxString title,const Set& _set, Menu* _menu) : wxFrame(NULL, wxID_ANY, title, wxDefaultPosition, wxSize(800, 600)), set(_set), menu(_menu) {

    wxPanel* panel = new wxPanel(this, wxID_ANY);

    std::set<Card> cards = set.get_cards();
    current_card = &*cards.begin();
    term = current_card->get_term();
    answer = current_card->get_answer();

    static_text = new wxStaticText(panel, wxID_ANY, term, wxDefaultPosition, wxDefaultSize, wxALIGN_CENTER);

    wxFont font = static_text->GetFont();
    font.SetPointSize(24);
    static_text->SetFont(font);

    wxBoxSizer* sizer = new wxBoxSizer(wxVERTICAL);

    sizer->Add(0, 1, 1);
    sizer->Add(static_text, 0, wxALIGN_CENTER | wxALL, 10);
    sizer->Add(0, 1, 1);

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
        wxString current_text = static_text->GetLabel();
        if(current_text == term){
            static_text->SetLabel(answer);
        }else{
            static_text->SetLabel(term);
        }
        static_text->GetParent()->Layout();
    }else if(keyCode == WXK_RIGHT){
        go_to_next_card(keyCode);
    }else if(keyCode == WXK_LEFT){
        go_to_next_card(keyCode);
    }
}

void Set_window::go_to_next_card(int keyCode){

}

