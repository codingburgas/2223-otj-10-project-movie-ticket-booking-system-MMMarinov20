#include "pch.h"
#include "Seats.hpp"

void Seats::GenerateRandomSeats() {
	srand(time(NULL));
	for (int i = 0; i < 20; i++) {
		int randomIndex = rand() % 100;
		if (seatsArray[randomIndex]->isTaken == false) {
			seatsArray[randomIndex]->isTaken = true;
			seats[randomIndex]->BackColor = System::Drawing::Color::Red;
		}
		else i--;
	}
}

void Seats::PanelMouseClick(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {
	System::Windows::Forms::Panel^ panel = (System::Windows::Forms::Panel^)sender;
	int index = Int32::Parse(panel->Name->Substring(4));
	if (seatsArray[index]->isTaken == false) {
		panel->Cursor = System::Windows::Forms::Cursors::Hand;
		if (seatsArray[index]->isSelected == false) {
			seatsArray[index]->isSelected = true;
			seats[index]->BackColor = System::Drawing::Color::Green;
		}
		else {
			seatsArray[index]->isSelected = false;
			seats[index]->BackColor = System::Drawing::Color::Gray;
		}
	}
}

void Seats::PanelMouseEnter(System::Object^ sender, System::EventArgs^ e) {
	System::Windows::Forms::Panel^ panel = (System::Windows::Forms::Panel^)sender;
	panel->Cursor = System::Windows::Forms::Cursors::Hand;
}

void Seats::PanelMouseLeave(System::Object^ sender, System::EventArgs^ e) {
	System::Windows::Forms::Panel^ panel = (System::Windows::Forms::Panel^)sender;
	panel->Cursor = System::Windows::Forms::Cursors::Default;
}

void Seats::ButtonClick(System::Object^ sender, System::EventArgs^ e) {
	System::Windows::Forms::Button^ button = (System::Windows::Forms::Button^)sender;
	for (int i = 0; i < 100; i++) {
		if (seatsArray[i]->isSelected == true) {
			seatsArray[i]->isTaken = true;
			seatsArray[i]->isSelected = false;
			seats[i]->BackColor = System::Drawing::Color::Red;
		}
	}
}