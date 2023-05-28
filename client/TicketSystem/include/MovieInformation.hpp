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

public ref class MovieInformation : public System::Windows::Forms::Form {
public:
	value struct Movie {
		String^ title;
		String^ url;
		int year;
		String^ caption;
		String^ type;
	};

	MovieInformation(void) {
		InitializeComponent();
	}

	Movie currMovie;
	System::Windows::Forms::Label^ movieName;
private:
    void InitializeComponent(void) {
        this->Hide();
        this->SuspendLayout();
        this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
        this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
        this->ClientSize = System::Drawing::Size(800, 450);

        // Update the Name and Text properties of the form
        this->Name = L"MovieInformationForm";
        this->Text = L"Movie Information";

        this->movieName = (gcnew System::Windows::Forms::Label());
        this->movieName->AutoSize = true;
        this->movieName->Location = System::Drawing::Point(12, 9);
        this->movieName->Name = L"movieName";
        this->movieName->Size = System::Drawing::Size(35, 13);
        this->movieName->TabIndex = 0;

        this->Controls->Add(this->movieName);
        this->ResumeLayout(false);
    }

};