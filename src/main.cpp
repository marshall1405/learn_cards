#include <wx/wx.h>
#include <iostream>
#include <sstream>
#include "./header/card.h"
#include "./header/set.h"

class learn_cards : public wxApp
{
public:
    virtual bool OnInit();
};

class MainFrame : public wxFrame
{
public:
    MainFrame(const wxString& title);

private:
    void OnExit(wxCommandEvent& event);
    void OnAbout(wxCommandEvent& event);
};

wxIMPLEMENT_APP(learn_cards);

bool learn_cards::OnInit()
{
    MainFrame *frame = new MainFrame("First Window! Hooray!");
    frame->Show(true);
    return true;
}

MainFrame::MainFrame(const wxString& title)
    : wxFrame(NULL, wxID_ANY, title)
{
    wxMenu *menuFile = new wxMenu;
    menuFile->Append(wxID_EXIT);

    wxMenu *menuHelp = new wxMenu;
    menuHelp->Append(wxID_ABOUT);

    wxMenuBar *menuBar = new wxMenuBar;
    menuBar->Append(menuFile, "&File");
    menuBar->Append(menuHelp, "&Help");

    SetMenuBar(menuBar);

    CreateStatusBar();

    Card c1 = Card(1, "Hello", "World");
    Card c2 = Card(2, "World", "Hello");
    std::set<Card, Card::CardComparator> s = {c1, c2};
    Set set = Set(s);

    std::ostringstream os;
    os << set;

    wxPanel* panel = new wxPanel(this, wxID_ANY);
    wxStaticText* text = new wxStaticText(panel, wxID_ANY, os.str(), wxPoint(10, 10));
}

void MainFrame::OnExit(wxCommandEvent& event)
{
    Close(true);
}
