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
		String^ year;
		String^ caption;
		String^ type;
	};

	MovieInformation(void) {
		InitializeComponent();
	}

	Movie currMovie;
	System::Windows::Forms::Label^ movieName;
	System::Windows::Forms::PictureBox^ moviePoster;
	System::Windows::Forms::Label^ movieCaption;
private:
    void InitializeComponent(void) {
        this->Hide();
        this->SuspendLayout();
		this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
		this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
		this->BackColor = System::Drawing::Color::IndianRed;
		this->ClientSize = System::Drawing::Size(1264, 681);

        // Update the Name and Text properties of the form
        this->Name = L"MovieInformationForm";
        this->Text = L"Movie Information";

		this->moviePoster = (gcnew System::Windows::Forms::PictureBox());
		this->moviePoster->Location = System::Drawing::Point(100, 100);
		this->moviePoster->Name = L"moviePoster";
		this->moviePoster->Size = System::Drawing::Size(400, 500);
		this->moviePoster->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
		this->moviePoster->TabIndex = 0;
		this->moviePoster->TabStop = false;
		

        this->movieName = (gcnew System::Windows::Forms::Label());
        this->movieName->AutoSize = true;
        this->movieName->Location = System::Drawing::Point(12, 9);
        this->movieName->Name = L"movieName";
        this->movieName->Size = System::Drawing::Size(35, 13);
        this->movieName->TabIndex = 0;

		this->movieCaption = (gcnew System::Windows::Forms::Label());
		this->movieCaption->AutoSize = true;
		this->movieCaption->Location = System::Drawing::Point(12, 9);
		this->movieCaption->Name = L"movieCaption";
		this->movieCaption->Size = System::Drawing::Size(35, 13);
		this->movieCaption->TabIndex = 0;

        this->Controls->Add(this->movieName);
		this->Controls->Add(this->movieCaption);
		this->Controls->Add(this->moviePoster);
        this->ResumeLayout(false);
    }

};