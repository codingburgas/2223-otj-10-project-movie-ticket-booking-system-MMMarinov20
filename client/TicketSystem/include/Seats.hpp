#pragma once
#include <string>
#include <iostream>
#include <array>
#using <System.dll>

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;
using namespace System::Net;
using namespace System::Text;
using namespace System::Runtime::InteropServices;
using namespace System::IO;

public ref class Seats : public System::Windows::Forms::Form {
public:
	Seats(void) {
		InitializeComponent();
	}

	value struct Seat {
		int number;
		int row;
		bool isTaken;
		bool isSelected;
		String^ seatType;
	};
	cli::array<System::Windows::Forms::Panel^>^ seats = gcnew cli::array<System::Windows::Forms::Panel^>(100);
	cli::array<Seat^>^ seatsArray = gcnew cli::array<Seat^>(100);
	System::Windows::Forms::Button^ bookButton;

private:
	void InitializeComponent(void) {
		this->SuspendLayout();
		this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
		this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
		this->BackColor = System::Drawing::Color::IndianRed;
		this->ClientSize = System::Drawing::Size(1264, 681);
		this->Name = L"Seats";
		this->Text = L"Seats";
		bookButton = gcnew System::Windows::Forms::Button();
		bookButton->Location = System::Drawing::Point(1000, 600);
		bookButton->Size = System::Drawing::Size(200, 50);
		bookButton->Text = "Book";
		bookButton->Click += gcnew System::EventHandler(this, &Seats::ButtonClick);
		this->Controls->Add(bookButton);

		int x = 160;
		int y = 100;
		int seatNumber = 0;
		for (int i = 0; i < 100; i++) {
			int row = i / 10;
			String^ seatType;
			//silver, gold, platinum
			if (i < 20) seatType = "silver";
			else if (i < 40) seatType = "gold";
			else seatType = "platinum";
			Seat seat = {seatNumber, row, false, false, seatType};
			seatsArray[i] = seat;
			seats[i] = (gcnew System::Windows::Forms::Panel());
			seats[i]->SuspendLayout();
			seats[i]->BackColor = System::Drawing::Color::Gray;
			seats[i]->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			seats[i]->Location = System::Drawing::Point(x, y);
			seats[i]->Name = "seat" + seatNumber;
			seats[i]->Size = System::Drawing::Size(50, 50);
			seats[i]->TabIndex = 0;
			this->Controls->Add(seats[i]);
			seats[i]->ResumeLayout(false);
			x += 100;
			seatNumber++;
			if (seatNumber % 10 == 0) {
				x = 160;
				y += 50;
			}
		}
		this->GenerateRandomSeats();

		for (int i = 0; i < 100; i++) {
			if (!seatsArray[i]->isTaken) {
				seats[i]->MouseEnter += gcnew System::EventHandler(this, &Seats::PanelMouseEnter);
				seats[i]->MouseLeave += gcnew System::EventHandler(this, &Seats::PanelMouseLeave);
				seats[i]->MouseClick += gcnew System::Windows::Forms::MouseEventHandler(this, &Seats::PanelMouseClick);
			}
		}
	}
private:
	void PanelMouseClick(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e);
	void PanelMouseEnter(System::Object^ sender, System::EventArgs^ e);
	void PanelMouseLeave(System::Object^ sender, System::EventArgs^ e);
	void ButtonClick(System::Object^ sender, System::EventArgs^ e);
	void GenerateRandomSeats();
};