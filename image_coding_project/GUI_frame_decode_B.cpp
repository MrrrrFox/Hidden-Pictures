#include "GUI_frame_decode_B.h"

GUI_frame_decode_B::GUI_frame_decode_B(wxWindow* parent) : frame_decode_B(parent), _logger(text_info)
{
	inputImage1 = std::make_shared<wxImage>(wxNullImage);
	inputImage2 = std::make_shared<wxImage>(wxNullImage);
	outputImage = std::make_shared<wxImage>(wxNullImage);
	gauge_progress->SetRange(100);
}

void GUI_frame_decode_B::frame_decode_B_OnUpdateUI(wxUpdateUIEvent& event)
{
	RepaintAll();
}

void GUI_frame_decode_B::button_load_input1_OnButtonClick(wxCommandEvent& event)
{
	LoadSaveManager loadFile(this);
	loadFile.Load();
	if (loadFile.getLoadedImage().IsOk())
	{
		inputImage1 = std::make_shared<wxImage>(loadFile.getLoadedImage());
		outputImage = std::make_shared<wxImage>(wxNullImage);
		panel_output_image->ClearBackground();
		RepaintAll();
		_logger.info("Poprawnie za�adowano pierwszy obraz do dekodowania");

	}
}

void GUI_frame_decode_B::button_load_input2_OnButtonClick(wxCommandEvent& event)
{
	LoadSaveManager loadFile(this);
	loadFile.Load();
	if (loadFile.getLoadedImage().IsOk())
	{
		inputImage2 = std::make_shared<wxImage>(loadFile.getLoadedImage());
		outputImage = std::make_shared<wxImage>(wxNullImage);
		panel_output_image->ClearBackground();
		RepaintAll();
		_logger.info("Poprawnie za�adowano drugi obraz do dekodowania");

	}
}

void GUI_frame_decode_B::button_decode_OnButtonClick(wxCommandEvent& event)
{
	try {
		Crypto crypto([=](int number, int all) {
			this->gauge_progress->SetValue(static_cast<double>(number) / all * 100 + 1);
		});
		crypto.decode(*inputImage1, *inputImage2, *outputImage);
		RepaintAll();
		_logger.info("Poprawnie odkodowano obraz");
	}
	catch (std::exception err) {
		_logger.error("Wyst�pi� b��d podczas dekodowania obrazu");
		_logger.error(err.what());
	}
}

void GUI_frame_decode_B::button_save_output_OnButtonClick(wxCommandEvent& event)
{
	if (outputImage != nullptr && outputImage->IsOk())
	{
		LoadSaveManager saveFile(this);
		saveFile.Save(*outputImage);
		_logger.info("Poprawnie zapisano odkodowany obraz");
	}
	else _logger.info("Wys�tpi� b��d podczas zapisu odkodowanego obrazu");

}

void GUI_frame_decode_B::button_return_OnButtonClick(wxCommandEvent& event)
{
	Destroy();
}


void GUI_frame_decode_B::RepaintAll()
{
	if (inputImage1 != nullptr && inputImage1->IsOk())
		Repaint(*inputImage1, panel_input_image1);

	if (inputImage2 != nullptr && inputImage2->IsOk())
		Repaint(*inputImage2, panel_input_image2);

	if (outputImage != nullptr && outputImage->IsOk())
		Repaint(*outputImage, panel_output_image);
}
//
//void GUI_frame_decode_B::progress(int number, int all) 
//{
//	gauge_progress->SetValue(static_cast<double>(number) / all * 100 + 1);
//}