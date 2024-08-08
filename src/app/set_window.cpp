#include "../header/set_window.h"

Set_window::Set_window(wxString title,const Set& _set, Menu* _menu, std::vector<int>* _studied_cards) : wxFrame(NULL, wxID_ANY, title, wxDefaultPosition, wxSize(800, 600)), set(_set), menu(_menu),  studied_cards(_studied_cards){

    this->set_size = set.get_cards().size();
    wxPanel* panel = new wxPanel(this, wxID_ANY);

    int card_num = find_next_card();
    current_card = set[card_num];
    term = current_card->get_term();
    answer = current_card->get_answer();

    progress_text = new wxStaticText(panel, wxID_ANY, "", wxDefaultPosition, wxDefaultSize, wxALIGN_CENTER);
    static_text = new wxStaticText(panel, wxID_ANY, term, wxDefaultPosition, wxDefaultSize, wxALIGN_CENTER);

    wxFont font_static = static_text->GetFont();
    font_static.SetPointSize(24);
    static_text->SetFont(font_static);

    wxFont font_progress = progress_text->GetFont();
    font_progress.SetPointSize(14);
    progress_text->SetFont(font_progress);

    wxBoxSizer* sizer = new wxBoxSizer(wxVERTICAL);
    sizer->Add(progress_text, 0, wxALIGN_CENTER_HORIZONTAL | wxTOP, 10);
    sizer->Add(0, 1, 1);
    sizer->Add(static_text, 0, wxALIGN_CENTER | wxALL, 10);
    sizer->Add(0, 1, 1);

    panel->SetSizerAndFit(sizer);

    panel->Bind(wxEVT_KEY_DOWN, &Set_window::set_window_controls, this);

    update_progress_text();
}



void Set_window::set_window_controls(wxKeyEvent& event){
    int keyCode = event.GetKeyCode();
    if(keyCode == WXK_BACK){
        menu->Show();
        menu->Raise();
        menu->going_back();
        this->Destroy();
    /*
    }else if(keyCode == WXK_RETURN){
        wxString current_text = static_text->GetLabel();
        if(current_text == term){
            static_text->SetLabel(answer);
        }else{
            static_text->SetLabel(term);
        }
        static_text->GetParent()->Layout();
    */
    }else if(keyCode == WXK_RIGHT){
        go_to_next_card(keyCode);
    }else if(keyCode == WXK_LEFT){
        go_to_next_card(keyCode);
    //else if for ubuntu, enter doesnt work
    }else if(keyCode == 308){
        wxString current_text = static_text->GetLabel();
        if(current_text == term){
            static_text->SetLabel(answer);
        }else{
            static_text->SetLabel(term);
        }
        static_text->GetParent()->Layout();
    }
}

void Set_window::go_to_next_card(int keyCode) {
    const auto& cards = set.get_cards();

    if (progress >= cards.size()) {
        menu->Show();
        menu->Raise();
        menu->going_back();
        this->Destroy();
        progress = 1;
        return;
    }

    auto it = cards.begin();
    std::advance(it, progress);

    if (it == cards.end()) {
        menu->Show();
        menu->Raise();
        menu->going_back();
        this->Destroy();
        progress = 1;
        return;
    }

    current_card = &*it;
    term = current_card->get_term();
    answer = current_card->get_answer();
    static_text->SetLabel(term);

    static_text->GetParent()->Layout();
    progress++;
    update_progress_text();
}

void Set_window::update_progress_text() {
    wxString progress_str = wxString::Format("%d/%zu", static_cast<int>(progress), set_size);
    progress_text->SetLabel(progress_str);
    progress_text->GetParent()->Layout();
}


int Set_window::find_next_card(){
    auto it = set.get_cards().begin();
    while(it != studied_cards.end() && std::find(studied_cards.begin(), studied_cards.end(), it->get_rank()) != studied_cards.end()){
        it++;
    }
    if(it == studied_cards.end()){
        return 0;
    }else{
        return it->get_rank();
    }
}