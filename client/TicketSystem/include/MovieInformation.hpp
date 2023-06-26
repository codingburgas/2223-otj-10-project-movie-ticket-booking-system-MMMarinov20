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
	System::Windows::Forms::Button^ bookButton;
	cli::array<System::Windows::Forms::Panel^>^ movieHours = gcnew cli::array<System::Windows::Forms::Panel^>(5);
	cli::array<System::Windows::Forms::Label^>^ movieHoursLabels = gcnew cli::array<System::Windows::Forms::Label^>(5);
private:
	bool isHourSelected = false;
	String^ selectedHour;
	cli::array<String^>^ hours = gcnew cli::array<String^>(5);
	void PanelMouseEnter(Object^ sender, EventArgs^ e);
	void PanelMouseLeave(Object^ sender, EventArgs^ e);
	void ButtonMouseEnter(Object^ sender, EventArgs^ e);
	void ButtonMouseLeave(Object^ sender, EventArgs^ e);
	void PanelMouseClick(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e);
	void ButtonMouseClick(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e);
	void ButtonClick(Object^ sender, EventArgs^ e);

private:
	void InitializeComponent(void) {
		for (int i = 0, j = 12; i < 5; i++) hours[i] = gcnew String(j++ + ":00");
		for (int i = 0; i < 5; i++) {
			movieHours[i] = (gcnew System::Windows::Forms::Panel());
			movieHoursLabels[i] = (gcnew System::Windows::Forms::Label());

			movieHours[i]->BackColor = Color::Orange;
			movieHours[i]->Size = System::Drawing::Size(80, 50);
			movieHours[i]->Location = System::Drawing::Point(550 + (i * 100), 470);
			movieHours[i]->Name = L"movieHours" + i;
			movieHours[i]->TabIndex = 0;
			movieHours[i]->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			movieHours[i]->MouseEnter += gcnew System::EventHandler(this, &MovieInformation::PanelMouseEnter);
			movieHours[i]->MouseLeave += gcnew System::EventHandler(this, &MovieInformation::PanelMouseLeave);
			movieHours[i]->MouseClick += gcnew System::Windows::Forms::MouseEventHandler(this, &MovieInformation::PanelMouseClick);

			movieHoursLabels[i]->AutoSize = true;
			movieHoursLabels[i]->Name = L"movieHoursLabel" + i;
			movieHoursLabels[i]->TabIndex = 0;
			movieHoursLabels[i]->Text = hours[i];
			movieHoursLabels[i]->Font = gcnew System::Drawing::Font("Microsoft Sans Serif", 12.0f, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0));
			movieHoursLabels[i]->ForeColor = System::Drawing::Color::White;
			movieHoursLabels[i]->Location = System::Drawing::Point(25 + (movieHours[i]->Width - movieHoursLabels[i]->Width) / 2, (movieHours[i]->Height - movieHoursLabels[i]->Height) / 2);
			movieHoursLabels[i]->MouseEnter += gcnew System::EventHandler(this, &MovieInformation::PanelMouseEnter);
			movieHoursLabels[i]->MouseLeave += gcnew System::EventHandler(this, &MovieInformation::PanelMouseLeave);
			movieHoursLabels[i]->MouseClick += gcnew System::Windows::Forms::MouseEventHandler(this, &MovieInformation::ButtonMouseClick);
			this->Controls->Add(this->movieHours[i]);
			this->movieHours[i]->Controls->Add(this->movieHoursLabels[i]);
		}
		this->Hide();
		this->SuspendLayout();
		this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
		this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
		this->BackColor = System::Drawing::Color::IndianRed;
		this->ClientSize = System::Drawing::Size(1264, 681);

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
		this->movieName->Name = L"movieName";
		this->movieName->Size = System::Drawing::Size(35, 13);
		this->movieName->Font = gcnew System::Drawing::Font("Arial", 24, FontStyle::Bold);
		this->movieName->Location = System::Drawing::Point(550, 100);
		this->movieName->TabIndex = 0;

		this->movieCaption = (gcnew System::Windows::Forms::Label());
		this->movieCaption->AutoSize = true;
		this->movieCaption->Name = L"movieCaption";
		this->movieCaption->Size = System::Drawing::Size(35, 13);
		this->movieCaption->Font = gcnew System::Drawing::Font("Arial", 18);
		this->movieCaption->Location = System::Drawing::Point(550, 200);
		this->movieCaption->MaximumSize = System::Drawing::Size(600, 0);
		this->movieCaption->TabIndex = 0;

		this->bookButton = (gcnew System::Windows::Forms::Button());
		this->bookButton->Location = System::Drawing::Point(550, 550);
		this->bookButton->Name = L"bookButton";
		this->bookButton->Size = System::Drawing::Size(200, 50);
		this->bookButton->TabIndex = 0;
		this->bookButton->Text = L"Book";
		this->bookButton->UseVisualStyleBackColor = true;
		this->bookButton->BackColor = Color::Orange;
		this->bookButton->ForeColor = Color::White;
		this->bookButton->Font = gcnew System::Drawing::Font("Arial", 18, FontStyle::Bold);
		this->bookButton->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
		this->bookButton->MouseEnter += gcnew System::EventHandler(this, &MovieInformation::ButtonMouseEnter);
		this->bookButton->MouseLeave += gcnew System::EventHandler(this, &MovieInformation::ButtonMouseLeave);
		this->bookButton->Click += gcnew System::EventHandler(this, &MovieInformation::ButtonClick);
		
		this->Controls->Add(this->bookButton);
		this->Controls->Add(this->movieName);
		this->Controls->Add(this->movieCaption);
		this->Controls->Add(this->moviePoster);
		this->ResumeLayout(false);
	}

};