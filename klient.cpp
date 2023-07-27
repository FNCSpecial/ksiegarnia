#include <wx/textfile.h>
#include <wx/msgdlg.h>
#include "klient.h"
#include "zamawianie.h"

//(*InternalHeaders(klient)
#include <wx/bitmap.h>
#include <wx/font.h>
#include <wx/icon.h>
#include <wx/image.h>
#include <wx/intl.h>
#include <wx/settings.h>
#include <wx/string.h>
//*)

//(*IdInit(klient)
const long klient::ID_BUTTON2 = wxNewId();
const long klient::ID_TEXTCTRL1 = wxNewId();
const long klient::ID_TEXTCTRL2 = wxNewId();
const long klient::ID_STATICTEXT1 = wxNewId();
const long klient::ID_STATICTEXT2 = wxNewId();
const long klient::ID_BUTTON1 = wxNewId();
const long klient::ID_BUTTON3 = wxNewId();
const long klient::ID_BUTTON4 = wxNewId();
const long klient::ID_CHOICE1 = wxNewId();
//*)

BEGIN_EVENT_TABLE(klient,wxFrame)
	//(*EventTable(klient)
	//*)
END_EVENT_TABLE()

klient::klient(wxWindow* parent,wxWindowID id,const wxPoint& pos,const wxSize& size)
{
	//(*Initialize(klient)
	Create(parent, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxDEFAULT_FRAME_STYLE, _T("wxID_ANY"));
	SetClientSize(wxSize(1100,450));
	SetBackgroundColour(wxColour(191,168,158));
	{
		wxIcon FrameIcon;
		FrameIcon.CopyFromBitmap(wxBitmap(wxImage(_T("C:\\Users\\Vetrox\\Desktop\\ksiegarnia\\logo.png"))));
		SetIcon(FrameIcon);
	}
	Button2 = new wxButton(this, ID_BUTTON2, _("Wyszukaj"), wxPoint(24,88), wxSize(100,35), 0, wxDefaultValidator, _T("ID_BUTTON2"));
	Button2->SetBackgroundColour(wxColour(235,245,238));
	wxFont Button2Font(12,wxFONTFAMILY_ROMAN,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_LIGHT,false,_T("Bookman Old Style"),wxFONTENCODING_DEFAULT);
	Button2->SetFont(Button2Font);
	TextCtrl1 = new wxTextCtrl(this, ID_TEXTCTRL1, wxEmptyString, wxPoint(136,88), wxSize(180,35), 0, wxDefaultValidator, _T("ID_TEXTCTRL1"));
	wxFont TextCtrl1Font(14,wxFONTFAMILY_ROMAN,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_LIGHT,false,_T("Bookman Old Style"),wxFONTENCODING_DEFAULT);
	TextCtrl1->SetFont(TextCtrl1Font);
	TextCtrl2 = new wxTextCtrl(this, ID_TEXTCTRL2, wxEmptyString, wxPoint(336,80), wxSize(736,296), wxTE_MULTILINE, wxDefaultValidator, _T("ID_TEXTCTRL2"));
	wxFont TextCtrl2Font(12,wxFONTFAMILY_ROMAN,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_LIGHT,false,_T("Bookman Old Style"),wxFONTENCODING_DEFAULT);
	TextCtrl2->SetFont(TextCtrl2Font);
	StaticText1 = new wxStaticText(this, ID_STATICTEXT1, _("Podaj czego szukasz"), wxPoint(144,56), wxDefaultSize, 0, _T("ID_STATICTEXT1"));
	wxFont StaticText1Font(12,wxFONTFAMILY_ROMAN,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_LIGHT,false,_T("Bookman Old Style"),wxFONTENCODING_DEFAULT);
	StaticText1->SetFont(StaticText1Font);
	StaticText2 = new wxStaticText(this, ID_STATICTEXT2, _("Witaj w panelu klienta! Mozesz tutaj wyszukac interesujace cie ksiazki, a potem je zamowic."), wxPoint(128,16), wxDefaultSize, 0, _T("ID_STATICTEXT2"));
	wxFont StaticText2Font(14,wxFONTFAMILY_ROMAN,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_LIGHT,false,_T("Bookman Old Style"),wxFONTENCODING_DEFAULT);
	StaticText2->SetFont(StaticText2Font);
	Button1 = new wxButton(this, ID_BUTTON1, _("Wyswietl"), wxPoint(24,136), wxSize(100,35), 0, wxDefaultValidator, _T("ID_BUTTON1"));
	Button1->SetBackgroundColour(wxColour(235,245,238));
	wxFont Button1Font(12,wxFONTFAMILY_ROMAN,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_LIGHT,false,_T("Bookman Old Style"),wxFONTENCODING_DEFAULT);
	Button1->SetFont(Button1Font);
	Button3 = new wxButton(this, ID_BUTTON3, _("Zamow"), wxPoint(24,184), wxSize(100,35), 0, wxDefaultValidator, _T("ID_BUTTON3"));
	Button3->SetBackgroundColour(wxColour(235,245,238));
	wxFont Button3Font(12,wxFONTFAMILY_ROMAN,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_LIGHT,false,_T("Bookman Old Style"),wxFONTENCODING_DEFAULT);
	Button3->SetFont(Button3Font);
	Button4 = new wxButton(this, ID_BUTTON4, _("Wyswietl\nrecenzje"), wxPoint(24,232), wxSize(100,50), 0, wxDefaultValidator, _T("ID_BUTTON4"));
	Button4->SetBackgroundColour(wxColour(235,245,238));
	wxFont Button4Font(12,wxFONTFAMILY_ROMAN,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_LIGHT,false,_T("Bookman Old Style"),wxFONTENCODING_DEFAULT);
	Button4->SetFont(Button4Font);
	Choice1 = new wxChoice(this, ID_CHOICE1, wxPoint(136,240), wxSize(180,40), 0, 0, 0, wxDefaultValidator, _T("ID_CHOICE1"));
	Choice1->SetSelection( Choice1->Append(_("Harry Potter")) );
	Choice1->Append(_("Wiedzmin"));
	Choice1->Append(_("Narnia"));
	Choice1->Append(_("Kod da Vinci"));
	Choice1->Append(_("Kowboje w kosmosie"));
	Choice1->Append(_("Krotka historia czasu"));
	Choice1->Append(_("Sherlock"));
	Choice1->SetBackgroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_HIGHLIGHTTEXT));
	wxFont Choice1Font(12,wxFONTFAMILY_ROMAN,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_LIGHT,false,_T("Bookman Old Style"),wxFONTENCODING_DEFAULT);
	Choice1->SetFont(Choice1Font);
	Center();

	Connect(ID_BUTTON2,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&klient::OnButton2Click);
	Connect(ID_BUTTON1,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&klient::OnButton1Click2);
	Connect(ID_BUTTON3,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&klient::OnButton3Click);
	Connect(ID_BUTTON4,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&klient::OnButton4Click);
	Connect(ID_CHOICE1,wxEVT_COMMAND_CHOICE_SELECTED,(wxObjectEventFunction)&klient::OnChoice1Select);
	//*)
}

klient::~klient()
{
	//(*Destroy(klient)
	//*)
}

void klient::OnButton2Click(wxCommandEvent& event)
{
    wxTextFile file;
    wxString line;
    wxString pom;
    wxString szukana = TextCtrl1->GetValue();;
    if(szukana==""){ wxMessageBox("Podaj kryteria wyszukiwania!");
    TextCtrl2->Clear();}
    else{
    file.Open("ksiazki.txt");

    for(size_t i=0; i<file.GetLineCount(); i++){
        line << file.GetLine(i) <<("\n");
        if(line.find(szukana) != wxNOT_FOUND){
            pom << line;
        }
        line.Clear();
        TextCtrl2->SetValue(pom);
    }
    if(TextCtrl2->IsEmpty()) {
        TextCtrl2->SetValue("Brak wynikow!");
    }
    file.Close();}
}

void klient::OnButton1Click2(wxCommandEvent& event)
{
    wxTextFile file;
    wxString text;
    file.Open("ksiazki.txt");

    for(size_t i=0; i<file.GetLineCount(); i++){
        text << file.GetLine(i) <<("\n");
        TextCtrl2->SetValue(text);
    }
    file.Close();
}

void klient::OnButton3Click(wxCommandEvent& event)
{
    zamawianie* FrameZ = new zamawianie(0);
    	FrameZ->Show();
}

void klient::OnButton4Click(wxCommandEvent& event)
{
    wxString wartosc = Choice1->GetString(Choice1->GetCurrentSelection());
    if(wartosc=="") wxMessageBox("Wybierz recenzje!");
    else {
    wxTextFile file;
    wxString text;
    file.Open("recenzje/"+wartosc+".txt");

    for(size_t i=0; i<file.GetLineCount(); i++){
        text << file.GetLine(i) <<("\n");
        TextCtrl2->SetValue(text);
    }
    file.Close();}
}

void klient::OnChoice1Select(wxCommandEvent& event)
{
}
