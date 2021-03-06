#ifndef __GUI_frame_decode_A__
#define __GUI_frame_decode_A__

/**
@file
Subclass of frame_decode_A, which is generated by wxFormBuilder.
*/

#include "GUI.h"

//// end generated include
#include "DrawManager.h"
#include "LoadSaveManager.h"
#include "Stegano.h"
#include "TextBoxLogger.h"
/** Implementing frame_decode_A */
class GUI_frame_decode_A : public frame_decode_A
{
	protected:
		// Handlers for frame_decode_A events.
		void frame_decode_A_OnUpdateUI( wxUpdateUIEvent& event );
		void button_load_input_OnButtonClick( wxCommandEvent& event );
		void button_load_ref_OnButtonClick( wxCommandEvent& event );
		void button_decode_OnButtonClick( wxCommandEvent& event );
		void button_save_output_OnButtonClick( wxCommandEvent& event );
		void button_return_OnButtonClick( wxCommandEvent& event );

	public:
		/** Constructor */
		GUI_frame_decode_A( wxWindow* parent );
	//// end generated class members
		void RepaintAll();

	protected:
		std::shared_ptr<wxImage> inputImage;
		std::shared_ptr<wxImage> refImage;
		std::shared_ptr<wxImage> outputImage;
		TextBoxLogger _logger;
};

#endif // __GUI_frame_decode_A__
