#include "wx/wx.h"
#include "wx/filepicker.h"
#include "../res/minimal.xpm"

class MinimalApp : public wxApp
{
public:
    bool OnInit();
};

class MinimalFrame : public wxFrame
{
public:
    MinimalFrame(const wxString& title);
private:
    wxDECLARE_EVENT_TABLE();
};

wxBEGIN_EVENT_TABLE(MinimalFrame, wxFrame)
wxEND_EVENT_TABLE()

wxIMPLEMENT_APP(MinimalApp);

bool MinimalApp::OnInit()
{
    if ( !wxApp::OnInit() )
        return false;

    MinimalFrame *frame = new MinimalFrame("Minimal wxWidgets App");

    frame->Show(true);

    return true;
}

MinimalFrame::MinimalFrame(const wxString& title)
       : wxFrame(NULL, wxID_ANY, title)
{
    SetIcon(wxICON(minimal));


    wxPanel *panel1;
    wxPanel *panel2;
    wxPanel *panel3;
    wxListBox *box;
    wxFilePickerCtrl *picker;
    wxTextCtrl *text1;
    wxTextCtrl *text2;
    wxButton *button;

    panel3 = new wxPanel(this, wxID_ANY);
    panel1 = new wxPanel(panel3, wxID_ANY);
    panel2 = new wxPanel(panel3, wxID_ANY);
    box = new wxListBox(panel1, wxID_ANY);
    text1 = new wxTextCtrl(panel2, wxID_ANY);
    picker = new wxFilePickerCtrl(panel2, wxID_ANY);
    text2 = new wxTextCtrl(panel2, wxID_ANY);
    button = new wxButton(panel2, wxID_ANY);

    //box->Disable();
    //text1->Disable();
    //picker->Disable();
    //text2->Disable();
    //button->Disable();
    //panel1->SetBackgroundColour(wxColour(255,0,0));
    //panel2->SetBackgroundColour(wxColour(0,255,0));
    //panel3->SetBackgroundColour(wxColour(0,0,255));

    wxBoxSizer* const sizer1 = new wxBoxSizer(wxVERTICAL);
    sizer1->Add(box, wxSizerFlags(2).Expand().Border());
    panel1->SetSizer(sizer1);

    wxBoxSizer* const sizer2 = new wxBoxSizer(wxVERTICAL);
    sizer2->Add(text1, wxSizerFlags().Expand().Border());
    sizer2->Add(picker, wxSizerFlags().Expand().Border());
    sizer2->Add(text2, wxSizerFlags().Expand().Border());
    sizer2->Add(button, wxSizerFlags().Expand().Border());
    panel2->SetSizer(sizer2);

    wxBoxSizer* const sizer3 = new wxBoxSizer(wxHORIZONTAL);
    sizer3->Add(panel1, wxSizerFlags().Expand().Border());
    sizer3->Add(panel2, wxSizerFlags().Expand().Border());
    panel3->SetSizer(sizer3);

    SetClientSize(500, 500);
}
