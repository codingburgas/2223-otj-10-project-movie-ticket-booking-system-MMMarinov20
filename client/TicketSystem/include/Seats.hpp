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

	cli::array<System::Windows::Forms::Panel^>^ seats = gcnew cli::array<System::Windows::Forms::Panel^>(100);
private:
	void InitializeComponent(void) {
		this->SuspendLayout();
		this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
		this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
		this->BackColor = System::Drawing::Color::IndianRed;
		this->ClientSize = System::Drawing::Size(1264, 681);
		this->Name = L"Seats";
		this->Text = L"Seats";

		int x = 160;
		int y = 100;
		int seatNumber = 1;
		for (int i = 0; i < 100; i++) {
			seats[i] = (gcnew System::Windows::Forms::Panel());
			seats[i]->SuspendLayout();
			seats[i]->BackColor = System::Drawing::Color::Gray;
			seats[i]->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			seats[i]->Location = System::Drawing::Point(x, y);
			seats[i]->Name = L"seat" + seatNumber;
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
	}
};