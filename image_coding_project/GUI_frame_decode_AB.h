#ifndef __GUI_frame_decode_AB__
#define __GUI_frame_decode_AB__

/**
@file
Subclass of frame_decode_AB, which is generated by wxFormBuilder.
*/

#include "GUI.h"

//// end generated include

#include "TextBoxLogger.h"
#include "DrawManager.h"
#include "LoadSaveManager.h"
#include "Crypto.h"
#include "TextBoxLogger.h"
#include "Stegano.h"



/** Implementing frame_decode_AB */
class GUI_frame_decode_AB : public frame_decode_AB
{
	protected:
		// Handlers for frame_decode_AB events.
		void frame_decode_AB_OnUpdateUI( wxUpdateUIEvent& event );
		void button_load_input1_OnButtonClick( wxCommandEvent& event );
		void button_load_input2_OnButtonClick( wxCommandEvent& event );
		void button_load_ref_OnButtonClick( wxCommandEvent& event );
		void button_decode_OnButtonClick( wxCommandEvent& event );
		void button_save_output_OnButtonClick( wxCommandEvent& event );
		void button_return_OnButtonClick( wxCommandEvent& event );

	public:
		/** Constructor */
		GUI_frame_decode_AB( wxWindow* parent );
	//// end generated class members
		void RepaintAll();

	protected:
		TextBoxLogger _logger;
		std::shared_ptr<wxImage> inputImage1;
		std::shared_ptr<wxImage> inputImage2;
		std::shared_ptr<wxImage> referenceImage;
		std::shared_ptr<wxImage> outputImage;





};

#endif // __GUI_frame_decode_AB__
