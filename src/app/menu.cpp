#include "../header/menu.h"
#include <wx/wx.h>
#include <wx/listbox.h>


Menu::Menu(const wxString& title, std::set<Set> _learning_sets) : wxFrame(nullptr, wxID_ANY, title), learning_sets(_learning_sets){
    wxPanel* panel = new wxPanel(this, wxID_ANY);

    wxListBox* box = new wxListBox(panel, wxID_ANY, wxPoint(20, 20), wxSize(200, 150));


    for(auto it = learning_sets.begin(); it != learning_sets.end(); it++){
        box->Append(it->get_name());
    }
}