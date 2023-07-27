#include "pracownik.h"
#include <wx/textfile.h>
#include <wx/msgdlg.h>
#include "edycja.h"
#include "zamowienia.h"

//(*InternalHeaders(pracownik)
#include <wx/font.h>
#include <wx/intl.h>
#include <wx/string.h>
//*)

//(*IdInit(pracownik)
const long pracownik::ID_BUTTON1 = wxNewId();
const long pracownik::ID_BUTTON2 = wxNewId();
const long pracownik::ID_TEXTCTRL1 = wxNewId();
const long pracownik::ID_TEXTCTRL2 = wxNewId();
const long pracownik::ID_TEXTCTRL3 = wxNewId();
const long pracownik::ID_STATICTEXT1 = wxNewId();
const long pracownik::ID_STATICTEXT2 = wxNewId();
const long pracownik::ID_STATICTEXT3 = wxNewId();
const long pracownik::ID_STATICTEXT5 = wxNewId();
const long pracownik::ID_TEXTCTRL6 = wxNewId();
const long pracownik::ID_TEXTCTRL4 = wxNewId();
const long pracownik::ID_BUTTON3 = wxNewId();
const long pracownik::ID_BUTTON4 = wxNewId();
const long pracownik::ID_BUTTON5 = wxNewId();
const long pracownik::ID_BUTTON6 = wxNewId();
const long pracownik::ID_TEXTCTRL5 = wxNewId();
const long pracownik::ID_STATICTEXT4 = wxNewId();
//*)

BEGIN_EVENT_TABLE(pracownik,wxFrame)
	//(*EventTable(pracownik)
	//*)
END_EVENT_TABLE()

pracownik::pracownik(wxWindow* parent,wxWindowID id,const wxPoint& pos,const wxSize& size)
{
	//(*Initialize(pracownik)
	Create(parent, id, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxDEFAULT_FRAME_STYLE, _T("id"));
	SetClientSize(wxSize(900,450));
	Move(wxDefaultPosition);
	SetBackgroundColour(wxColour(191,168,158));
	Button1 = new wxButton(this, ID_BUTTON1, _("Dodaj"), wxPoint(32,104), wxSize(100,35), 0, wxDefaultValidator, _T("ID_BUTTON1"));
	Button1->SetBackgroundColour(wxColour(235,245,238));
	wxFont Button1Font(14,wxFONTFAMILY_ROMAN,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_LIGHT,false,_T("Bookman Old Style"),wxFONTENCODING_DEFAULT);
	Button1->SetFont(Button1Font);
	Button2 = new wxButton(this, ID_BUTTON2, _("Wyswietl"), wxPoint(32,160), wxSize(100,35), 0, wxDefaultValidator, _T("ID_BUTTON2"));
	Button2->SetBackgroundColour(wxColour(235,245,238));
	wxFont Button2Font(14,wxFONTFAMILY_ROMAN,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_LIGHT,false,_T("Bookman Old Style"),wxFONTENCODING_DEFAULT);
	Button2->SetFont(Button2Font);
	TextCtrl1 = new wxTextCtrl(this, ID_TEXTCTRL1, wxEmptyString, wxPoint(32,56), wxSize(130,30), 0, wxDefaultValidator, _T("ID_TEXTCTRL1"));
	wxFont TextCtrl1Font(14,wxFONTFAMILY_ROMAN,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_LIGHT,false,_T("Bookman Old Style"),wxFONTENCODING_DEFAULT);
	TextCtrl1->SetFont(TextCtrl1Font);
	TextCtrl2 = new wxTextCtrl(this, ID_TEXTCTRL2, wxEmptyString, wxPoint(184,56), wxSize(130,30), 0, wxDefaultValidator, _T("ID_TEXTCTRL2"));
	wxFont TextCtrl2Font(14,wxFONTFAMILY_ROMAN,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_LIGHT,false,_T("Bookman Old Style"),wxFONTENCODING_DEFAULT);
	TextCtrl2->SetFont(TextCtrl2Font);
	TextCtrl3 = new wxTextCtrl(this, ID_TEXTCTRL3, wxEmptyString, wxPoint(336,56), wxSize(130,30), 0, wxDefaultValidator, _T("ID_TEXTCTRL3"));
	wxFont TextCtrl3Font(14,wxFONTFAMILY_ROMAN,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_LIGHT,false,_T("Bookman Old Style"),wxFONTENCODING_DEFAULT);
	TextCtrl3->SetFont(TextCtrl3Font);
	StaticText1 = new wxStaticText(this, ID_STATICTEXT1, _("ID"), wxPoint(88,24), wxDefaultSize, 0, _T("ID_STATICTEXT1"));
	wxFont StaticText1Font(14,wxFONTFAMILY_DEFAULT,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_NORMAL,false,_T("Arial"),wxFONTENCODING_DEFAULT);
	StaticText1->SetFont(StaticText1Font);
	StaticText2 = new wxStaticText(this, ID_STATICTEXT2, _("Tytul"), wxPoint(224,24), wxDefaultSize, 0, _T("ID_STATICTEXT2"));
	wxFont StaticText2Font(14,wxFONTFAMILY_ROMAN,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_LIGHT,false,_T("Bookman Old Style"),wxFONTENCODING_DEFAULT);
	StaticText2->SetFont(StaticText2Font);
	StaticText3 = new wxStaticText(this, ID_STATICTEXT3, _("Autor"), wxPoint(376,24), wxDefaultSize, 0, _T("ID_STATICTEXT3"));
	wxFont StaticText3Font(14,wxFONTFAMILY_ROMAN,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_LIGHT,false,_T("Bookman Old Style"),wxFONTENCODING_DEFAULT);
	StaticText3->SetFont(StaticText3Font);
	StaticText5 = new wxStaticText(this, ID_STATICTEXT5, _("Cena"), wxPoint(528,24), wxDefaultSize, 0, _T("ID_STATICTEXT5"));
	wxFont StaticText5Font(14,wxFONTFAMILY_ROMAN,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_LIGHT,false,_T("Bookman Old Style"),wxFONTENCODING_DEFAULT);
	StaticText5->SetFont(StaticText5Font);
	TextCtrl6 = new wxTextCtrl(this, ID_TEXTCTRL6, wxEmptyString, wxPoint(160,104), wxSize(720,256), wxTE_MULTILINE|wxTE_READONLY|wxBORDER_NONE|wxTRANSPARENT_WINDOW, wxDefaultValidator, _T("ID_TEXTCTRL6"));
	wxFont TextCtrl6Font(12,wxFONTFAMILY_ROMAN,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_LIGHT,false,_T("Bookman Old Style"),wxFONTENCODING_DEFAULT);
	TextCtrl6->SetFont(TextCtrl6Font);
	TextCtrl4 = new wxTextCtrl(this, ID_TEXTCTRL4, wxEmptyString, wxPoint(488,56), wxSize(130,30), 0, wxDefaultValidator, _T("ID_TEXTCTRL4"));
	wxFont TextCtrl4Font(14,wxFONTFAMILY_ROMAN,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_LIGHT,false,_T("Bookman Old Style"),wxFONTENCODING_DEFAULT);
	TextCtrl4->SetFont(TextCtrl4Font);
	Button3 = new wxButton(this, ID_BUTTON3, _("Usun"), wxPoint(32,216), wxSize(100,35), 0, wxDefaultValidator, _T("ID_BUTTON3"));
	Button3->SetBackgroundColour(wxColour(235,245,238));
	wxFont Button3Font(14,wxFONTFAMILY_ROMAN,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_LIGHT,false,_T("Bookman Old Style"),wxFONTENCODING_DEFAULT);
	Button3->SetFont(Button3Font);
	Button4 = new wxButton(this, ID_BUTTON4, _("Twardy\nReset"), wxPoint(784,384), wxSize(100,50), 0, wxDefaultValidator, _T("ID_BUTTON4"));
	Button4->SetBackgroundColour(wxColour(235,245,238));
	wxFont Button4Font(14,wxFONTFAMILY_ROMAN,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_LIGHT,false,_T("Bookman Old Style"),wxFONTENCODING_DEFAULT);
	Button4->SetFont(Button4Font);
	Button5 = new wxButton(this, ID_BUTTON5, _("Edytuj"), wxPoint(32,272), wxSize(100,35), 0, wxDefaultValidator, _T("ID_BUTTON5"));
	Button5->SetBackgroundColour(wxColour(235,245,238));
	wxFont Button5Font(14,wxFONTFAMILY_ROMAN,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_LIGHT,false,_T("Bookman Old Style"),wxFONTENCODING_DEFAULT);
	Button5->SetFont(Button5Font);
	Button6 = new wxButton(this, ID_BUTTON6, _("Zamowienia"), wxPoint(32,328), wxSize(100,35), 0, wxDefaultValidator, _T("ID_BUTTON6"));
	Button6->SetBackgroundColour(wxColour(235,245,238));
	wxFont Button6Font(12,wxFONTFAMILY_ROMAN,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_LIGHT,false,_T("Bookman Old Style"),wxFONTENCODING_DEFAULT);
	Button6->SetFont(Button6Font);
	TextCtrl5 = new wxTextCtrl(this, ID_TEXTCTRL5, wxEmptyString, wxPoint(640,56), wxSize(130,30), 0, wxDefaultValidator, _T("ID_TEXTCTRL5"));
	wxFont TextCtrl5Font(14,wxFONTFAMILY_ROMAN,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_LIGHT,false,_T("Bookman Old Style"),wxFONTENCODING_DEFAULT);
	TextCtrl5->SetFont(TextCtrl5Font);
	StaticText4 = new wxStaticText(this, ID_STATICTEXT4, _("Gatunek"), wxPoint(664,24), wxDefaultSize, 0, _T("ID_STATICTEXT4"));
	wxFont StaticText4Font(14,wxFONTFAMILY_ROMAN,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_LIGHT,false,_T("Bookman Old Style"),wxFONTENCODING_DEFAULT);
	StaticText4->SetFont(StaticText4Font);
	Center();

	Connect(ID_BUTTON1,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&pracownik::OnButton1Click);
	Connect(ID_BUTTON2,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&pracownik::OnButton2Click);
	Connect(ID_TEXTCTRL4,wxEVT_COMMAND_TEXT_UPDATED,(wxObjectEventFunction)&pracownik::OnTextCtrl4Text);
	Connect(ID_BUTTON3,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&pracownik::OnButton3Click);
	Connect(ID_BUTTON4,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&pracownik::OnButton4Click);
	Connect(ID_BUTTON5,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&pracownik::OnButton5Click);
	Connect(ID_BUTTON6,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&pracownik::OnButton6Click);
	//*)
}

pracownik::~pracownik()
{
	//(*Destroy(pracownik)
	//*)
}


void pracownik::OnButton1Click(wxCommandEvent& event)
{
    wxTextFile file( wxT("ksiazki.txt") );
    file.Open();
    wxString id_ksiazki = TextCtrl1->GetValue();
    wxString tytul = TextCtrl2->GetValue();
    wxString autor = TextCtrl3->GetValue();
    wxString cena = TextCtrl4->GetValue();
    wxString gatunek = TextCtrl5->GetValue();

    wxString ogranicznik1 = "|: ";
    wxString ogranicznik2 = " |";
    wxString szukana = ogranicznik1+id_ksiazki+ogranicznik2;
    wxTextFile file2;
    wxString line;
    bool check=false;

    file2.Open("ksiazki.txt");

    for(size_t i=0; i<file2.GetLineCount(); i++){
        line << file2.GetLine(i) <<("\n");
        if(line.find(szukana) != wxNOT_FOUND){
        check=true;
        }
    }
    file2.Close();

    if(id_ksiazki.find_first_not_of("0123456789")!=std::string::npos || cena.find_first_not_of("0123456789")!=std::string::npos || check==true) {
            wxMessageBox("Bledne dane!");}
    else {
        file.AddLine("|: " + id_ksiazki + " | " + tytul + " | " + autor + " | " + cena + " | " + gatunek + " |");
        file.Write();
        wxMessageBox("Dodano dane!");
        file.Close();
        TextCtrl1->Clear();
        TextCtrl2->Clear();
        TextCtrl3->Clear();
        TextCtrl4->Clear();
        TextCtrl5->Clear();
    }
}

void pracownik::OnButton2Click(wxCommandEvent& event)
{
    wxTextFile file;
    wxString text;
    file.Open("ksiazki.txt");

    for(size_t i=0; i<file.GetLineCount(); i++){
        text << file.GetLine(i) <<("\n");
        TextCtrl6->SetValue(text);
    }
    file.Close();
}

void pracownik::OnTextCtrl4Text(wxCommandEvent& event)
{
}

void pracownik::OnButton3Click(wxCommandEvent& event)
{
    wxTextFile file;
    wxString text;
    file.Open("ksiazki.txt");
    file.RemoveLine(file.GetLineCount()-1);
    for(size_t i=0; i<file.GetLineCount(); i++){
        text << file.GetLine(i) <<("\n");
        TextCtrl6->SetValue(text);
    }
    if(file.GetLineCount()==0) {
            TextCtrl6->Clear();
        }
    file.Write();
    file.Close();
}

void pracownik::OnButton4Click(wxCommandEvent& event)
{
    wxTextFile file;
    file.Open("ksiazki.txt");
    file.Clear();
    file.Write();
    TextCtrl6->Clear();
    file.Close();
}

void pracownik::OnButton5Click(wxCommandEvent& event)
{
    edycja* FrameE = new edycja(0);
    	FrameE->Show();
}

void pracownik::OnButton6Click(wxCommandEvent& event)
{
    zamowienia* FrameZ2 = new zamowienia(0);
    	FrameZ2->Show();
}
