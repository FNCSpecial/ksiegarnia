#ifndef ZAMOWIENIA_H
#define ZAMOWIENIA_H

//(*Headers(zamowienia)
#include <wx/button.h>
#include <wx/frame.h>
#include <wx/textctrl.h>
//*)

class zamowienia: public wxFrame
{
	public:

		zamowienia(wxWindow* parent,wxWindowID id=wxID_ANY,const wxPoint& pos=wxDefaultPosition,const wxSize& size=wxDefaultSize);
		virtual ~zamowienia();

		//(*Declarations(zamowienia)
		wxButton* Button1;
		wxButton* Button2;
		wxTextCtrl* TextCtrl1;
		//*)

	protected:

		//(*Identifiers(zamowienia)
		static const long ID_BUTTON1;
		static const long ID_BUTTON2;
		static const long ID_TEXTCTRL1;
		//*)

	private:

		//(*Handlers(zamowienia)
		void OnButton1Click(wxCommandEvent& event);
		void OnButton2Click(wxCommandEvent& event);
		void OnTextCtrl1Text(wxCommandEvent& event);
		//*)

		DECLARE_EVENT_TABLE()
};

#endif
