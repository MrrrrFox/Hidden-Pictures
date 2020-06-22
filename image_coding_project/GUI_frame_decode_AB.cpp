#include "GUI_frame_decode_AB.h"

GUI_frame_decode_AB::GUI_frame_decode_AB( wxWindow* parent ) : frame_decode_AB( parent ), _logger(text_info)
{
	inputImage1 = std::make_shared<wxImage>(wxNullImage);
	inputImage2 = std::make_shared<wxImage>(wxNullImage);
	referenceImage = std::make_shared<wxImage>(wxNullImage);
	outputImage = std::make_shared<wxImage>(wxNullImage);
	gauge_progress->SetRange(100);
}

void GUI_frame_decode_AB::frame_decode_AB_OnUpdateUI( wxUpdateUIEvent& event )
{
	RepaintAll();
}

void GUI_frame_decode_AB::button_load_input1_OnButtonClick( wxCommandEvent& event )
{
	LoadSaveManager loadFile(this);
	loadFile.Load();
	if (loadFile.getLoadedImage().IsOk())
	{
		inputImage1 = std::make_shared<wxImage>(loadFile.getLoadedImage());
		Repaint(*inputImage1, panel_input_image1);
		_logger.info("Poprawnie za�adowano pierwszy obraz do dekodowania");

	}
	else _logger.error("Wyst�pi� b��d podczas �adowania pierszego obrazu do dekodowania");
}

void GUI_frame_decode_AB::button_load_input2_OnButtonClick( wxCommandEvent& event )
{
	LoadSaveManager loadFile(this);
	loadFile.Load();
	if (loadFile.getLoadedImage().IsOk())
	{
		inputImage2 = std::make_shared<wxImage>(loadFile.getLoadedImage());
		Repaint(*inputImage2, panel_input_image2);
		_logger.info("Poprawnie za�adowano drugi obraz do dekodowania");
	}
	else _logger.error("Wyst�pi� b��d podczas �adowania drugiego obrazu do dekodowania");
}

void GUI_frame_decode_AB::button_load_ref_OnButtonClick( wxCommandEvent& event )
{
	LoadSaveManager loadFile(this);
	loadFile.Load();
	if (loadFile.getLoadedImage().IsOk())
	{
		referenceImage = std::make_shared<wxImage>(loadFile.getLoadedImage());
		Repaint(*referenceImage, panel_input_ref);
		_logger.info("Poprawnie za�adowano obraz referencyjny");
	}
	else _logger.error("Wyst�pi� b��d podczas �adowania obrazu referencyjnego");
}

void GUI_frame_decode_AB::button_decode_OnButtonClick( wxCommandEvent& event )
{
	panel_output_image->ClearBackground();
	outputImage = std::make_shared<wxImage>(wxNullImage);
	try
	{
		Stegano meCoding1(*inputImage1, *referenceImage, [=](int number, int all) { this->gauge_progress->SetValue(static_cast<double>(number) / all * 25 + 1); });
		auto steganoDecoded1 = (*inputImage1).Copy();
		meCoding1.SteganoDec(steganoDecoded1);
		Repaint(steganoDecoded1, panel_output_image);
		_logger.info("Poprawnie odkodowano pierwszy obraz metod� steganograficzn�");

		Stegano meCoding2(*inputImage2, *referenceImage, [=](int number, int all) { this->gauge_progress->SetValue(static_cast<double>(number) / all * 25 + 26); });
		auto steganoDecoded2 = (*inputImage2).Copy();
		meCoding2.SteganoDec(steganoDecoded2);
		Repaint(steganoDecoded2, panel_output_image);
		_logger.info("Poprawnie odkodowano drugi obraz metod� steganograficzn�");
		RepaintAll();
	}
	catch(std::exception err)
	{
		_logger.error("Wyst�pi� b��d podczas dekodowania obrazu");
		_logger.error(err.what());
		return;
	}

	try {
		Crypto crypto([=](int number, int all) {
			this->gauge_progress->SetValue(static_cast<double>(number) / all * 50 + 51);
		});
		crypto.decode(*inputImage1, *inputImage2, *outputImage);
		_logger.info("Poprawnie odkodowano obraz metod� kryptograficzn�");
		RepaintAll();
	}
	catch (std::exception err) {
		_logger.error("Wyst�pi� b��d podczas dekodowania obrazu metod� kryptograficzn�");
		_logger.error(err.what());
	}
}

void GUI_frame_decode_AB::button_save_output_OnButtonClick( wxCommandEvent& event )
{
	if (outputImage != nullptr && outputImage->IsOk())
	{
		LoadSaveManager saveFile(this);
		saveFile.Save(*outputImage);
		_logger.info("Poprawnie zapisano odkodowany obraz");
	}
	else _logger.info("Wys�tpi� b��d podczas zapisu odkodowanego obrazu");
}

void GUI_frame_decode_AB::button_return_OnButtonClick( wxCommandEvent& event )
{
	Destroy();
}



void GUI_frame_decode_AB::RepaintAll()
{
	if (inputImage1 != nullptr && inputImage1->IsOk())
		Repaint(*inputImage1, panel_input_image1);
	
	if (inputImage2 != nullptr && inputImage2->IsOk())
		Repaint(*inputImage2, panel_input_image2);

	if (referenceImage != nullptr && referenceImage->IsOk())
		Repaint(*referenceImage, panel_input_ref);

	if (outputImage != nullptr && outputImage->IsOk())
		Repaint(*outputImage, panel_output_image);
}
