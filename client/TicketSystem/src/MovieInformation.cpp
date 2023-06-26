#include "pch.h"
#include "MovieInformation.hpp"

void MovieInformation::PanelMouseEnter(Object^ sender, EventArgs^ e) {
	Panel^ panel = dynamic_cast<Panel^>(sender);
	if (panel != nullptr) {
		panel->Cursor = Cursors::Hand;
		panel->BackColor = Color::DarkOrange;
	}
}

void MovieInformation::PanelMouseLeave(Object^ sender, EventArgs^ e) {
	Panel^ panel = dynamic_cast<Panel^>(sender);
	if (panel != nullptr) {
		panel->Cursor = Cursors::Default;
		panel->BackColor = Color::Orange;
	}
}

void MovieInformation::ButtonMouseEnter(Object^ sender, EventArgs^ e) {
	Button^ button = dynamic_cast<Button^>(sender);
	if (button != nullptr && !this->isHourSelected) {
		button->Cursor = Cursors::Hand;
		button->BackColor = Color::DarkOrange;
	}
}

void MovieInformation::ButtonMouseLeave(Object^ sender, EventArgs^ e) {
	Button^ button = dynamic_cast<Button^>(sender);
	if (button != nullptr && !this->isHourSelected) {
		button->Cursor = Cursors::Default;
		button->BackColor = Color::Orange;
	}
}

void MovieInformation::ButtonClick(Object^ sender, EventArgs^ e) {}

void MovieInformation::PanelMouseClick(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e)
{
	this->isHourSelected = true;
	Panel^ panel = dynamic_cast<Panel^>(sender);
	
	if (panel != nullptr) {
		panel->BackColor = this->isHourSelected ? Color::Red : Color::Orange;
	}
};

void MovieInformation::ButtonMouseClick(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {
	Button^ button = dynamic_cast<Button^>(sender);
	
	if (button != nullptr) {
		button->BackColor = this->isHourSelected ? Color::Red : Color::Orange;
	}
	
};