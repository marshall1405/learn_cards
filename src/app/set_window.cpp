#include "../header/set_window.h"

Set_window::Set_window(wxString title,const Set& _set, Menu* _menu) : wxFrame(NULL, wxID_ANY, title, wxDefaultPosition, wxSize(800, 600)), set(_set), menu(_menu) {

    wxPanel* panel = new wxPanel(this, wxID_ANY);

    current_card = &*set.get_cards().begin();
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
    wxString progress_str = wxString::Format("%d/%zu", static_cast<int>(progress), set.get_cards().size());
    progress_text->SetLabel(progress_str);
    progress_text->GetParent()->Layout();
}