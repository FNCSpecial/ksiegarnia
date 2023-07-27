/***************************************************************
 * Name:      ksiegarniaMain.h
 * Purpose:   Defines Application Frame
 * Author:     ()
 * Created:   2020-12-29
 * Copyright:  ()
 * License:
 **************************************************************/

#ifndef KSIEGARNIAMAIN_H
#define KSIEGARNIAMAIN_H

//(*Headers(ksiegarniaFrame)
#include <wx/button.h>
#include <wx/frame.h>
#include <wx/stattext.h>
//*)

class ksiegarniaFrame: public wxFrame
{
    public:

        ksiegarniaFrame(wxWindow* parent,wxWindowID id = -1);
        virtual ~ksiegarniaFrame();

    private:

        //(*Handlers(ksiegarniaFrame)
        void OnQuit(wxCommandEvent& event);
        void OnAbout(wxCommandEvent& event);
        void OnClose(wxCloseEvent& event);
        void OnButton1Click(wxCommandEvent& event);
        void OnButton1Click1(wxCommandEvent& event);
        void OnButton1Click2(wxCommandEvent& event);
        void OnButton2Click(wxCommandEvent& event);
        //*)

        //(*Identifiers(ksiegarniaFrame)
        static const long ID_BUTTON1;
        static const long ID_BUTTON2;
        static const long ID_STATICTEXT1;
        //*)

        //(*Declarations(ksiegarniaFrame)
        wxButton* Button1;
        wxButton* Button2;
        wxStaticText* StaticText1;
        //*)

        DECLARE_EVENT_TABLE()
};

#endif // KSIEGARNIAMAIN_H
