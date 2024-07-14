#include "../header/menu.h"


Menu::Menu(const wxString& title, std::set<Set> _learning_sets) : wxFrame(nullptr, wxID_ANY, title), learning_sets(_learning_sets){
    wxPanel* panel = new wxPanel(this, wxID_ANY);
    this->box = new wxListBox(panel, wxID_ANY, wxPoint(0, 0), wxSize(800, 600));


    for(auto it = learning_sets.begin(); it != learning_sets.end(); it++){
        box->Append(it->get_name());
    }

    //box->Bind(wxEVT_KEY_DOWN, &Menu::goingIntoSet, this);
}



void Menu::goingIntoSet(wxKeyEvent& event){

}