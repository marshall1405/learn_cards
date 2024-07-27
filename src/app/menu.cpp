#include "../header/menu.h"


Menu::Menu(const wxString& title, std::set<Set> _learning_sets) : wxFrame(nullptr, wxID_ANY, title), learning_sets(_learning_sets){
    wxPanel* panel = new wxPanel(this, wxID_ANY);
    this->box = new wxListBox(panel, wxID_ANY, wxPoint(0, 0), wxSize(800, 600));

    wxFont font = box->GetFont();
    font.SetPointSize(20);
    box->SetFont(font);

    if (box->GetCount() > 0) {
        box->SetSelection(0);
    }

    box->Bind(wxEVT_KEY_DOWN, &Menu::controls, this);
    
    for(auto it = learning_sets.begin(); it != learning_sets.end(); it++){
        box->Append(it->get_name());
    }
}



void Menu::controls(wxKeyEvent& event){
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
    }else if(keyCode == WXK_RETURN){
        this->goIntoSet();
    }
}

void Menu::goIntoSet(){
    wxMessageBox("Enter key pressed, going into set");
}