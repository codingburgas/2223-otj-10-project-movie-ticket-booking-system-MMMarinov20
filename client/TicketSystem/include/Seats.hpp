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

		this->ResumeLayout(false);
	};
};