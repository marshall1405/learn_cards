#include "../header/menu.h"
#include "../header/set_window.h"


Menu::Menu(const wxString& title, std::set<Set>& _learning_sets) : wxFrame(nullptr, wxID_ANY, title), learning_sets(_learning_sets){
    this->memory = Memory(learning_sets);

    wxPanel* panel = new wxPanel(this, wxID_ANY);
    this->box = new wxListBox(panel, wxID_ANY, wxPoint(0, 0), wxSize(800, 600));

    wxFont font = box->GetFont();
    font.SetPointSize(20);
    box->SetFont(font);

    if (box->GetCount() > 0) {
        box->SetSelection(0);
    }

    box->Bind(wxEVT_KEY_DOWN, &Menu::menu_controls, this);
    
    for(auto it = learning_sets.begin(); it != learning_sets.end(); it++){
        box->Append(it->get_name());
    }
}



void Menu::menu_controls(wxKeyEvent& event){
    int keyCode = event.GetKeyCode();
    int selection = box->GetSelection();

    if(keyCode == WXK_DOWN){
        if(selection < box->GetCount() - 1){
            box->SetSelection(selection + 1);
        }else{
            selection = 0;
            box->SetSelection(selection);
        }
    }else if(keyCode == WXK_UP){
        if(selection > 0){
            box->SetSelection(selection - 1);
        }else if(selection == 0){
            selection = box->GetCount()-1;
            box->SetSelection(selection);
        }
    /*
    }else if(keyCode == WXK_RETURN){
        this->go_into_set();
    */
   //enter else if for ubuntu because it doesnt register enter
    }else if(keyCode == 308){
        this->go_into_set();
    }
}

void Menu::go_into_set(){
    int selection = box->GetSelection();
    wxString selectedItem = box->GetString(selection);
    auto it = learning_sets.begin();
    std::vector<int>& studied_cards = memory->get_progress_map()[selectedItem.mb_str()]; 
    std::advance(it, selection);
    Set_window* set_win = new Set_window(selectedItem, *it, this, studied_cards);
    set_win->Show();
    set_win->Center();
    this->Hide();
}

void Menu::going_back(){
    memory->calibrate();
    box->SetFocus();
}