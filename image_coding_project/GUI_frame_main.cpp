#include "GUI_frame_main.h"

GUI_frame_main::GUI_frame_main(wxWindow* parent)
	:
	frame_main(parent)
{

}

void GUI_frame_main::button_encode_A_OnButtonClick(wxCommandEvent& event)
{
	wxFrame *encodeAFrame = new GUI_frame_encode_A(nullptr);
	encodeAFrame->Show(true);
}

void GUI_frame_main::button_decode_A_OnButtonClick(wxCommandEvent& event)
{
	wxFrame *decodeAFrame = new GUI_frame_decode_A(nullptr);
	decodeAFrame->Show(true);
}

void GUI_frame_main::button_encode_B_OnButtonClick(wxCommandEvent& event)
{
	wxFrame *encodeBFrame = new GUI_frame_encode_B(nullptr);
	encodeBFrame->Show(true);
}

void GUI_frame_main::button_decode_B_OnButtonClick(wxCommandEvent& event)
{
	wxFrame *decodeBFrame = new GUI_frame_decode_B(nullptr);
	decodeBFrame->Show(true);
}

void GUI_frame_main::button_encode_AB_OnButtonClick(wxCommandEvent& event)
{
	wxFrame *encodeABFrame = new GUI_frame_encode_AB(nullptr);
	encodeABFrame->Show(true);
}

void GUI_frame_main::button_decode_AB_OnButtonClick(wxCommandEvent& event)
{
	wxFrame *decodeABFrame = new GUI_frame_decode_AB(nullptr);
	decodeABFrame->Show(true);
}
