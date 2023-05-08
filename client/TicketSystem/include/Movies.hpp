#pragma once
#include <string>
#include <iostream>
#include <array>
#include "rapidjson/document.h"
#include "rapidjson/writer.h"
#include "rapidjson/stringbuffer.h"
#include "rapidjson/istreamwrapper.h"
#include "rapidjson/error/en.h"
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

public ref class Movies : public System::Windows::Forms::Form {
public:
	Movies(void) {
		InitializeComponent();
	}
	void fetchMovies();
	String^ getMovies();

	cli::array<String^>^ movies = gcnew cli::array<String^>(100);
	cli::array<String^>^ captions = gcnew cli::array<String^>(100);
	cli::array<String^>^ years = gcnew cli::array<String^>(100);
	cli::array<String^>^ url = gcnew cli::array<String^>(100);
	cli::array<Label^>^ movieLabels;
	cli::array<Label^>^ captionLabels;
	cli::array<PictureBox^>^ movieImages;

private:
	System::Windows::Forms::Label^ movieName;

	void InitializeComponent(void) {
		this->movieName = (gcnew System::Windows::Forms::Label());
		this->SuspendLayout();
		movieLabels = gcnew cli::array<Label^>(movies->Length * 4);
		captionLabels = gcnew cli::array<Label^>(movies->Length * 4);
		movieImages = gcnew cli::array<PictureBox^>(movies->Length * 4);

		this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
		this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
		this->BackColor = System::Drawing::Color::IndianRed;
		this->ClientSize = System::Drawing::Size(1264, 681);
		this->Name = L"WelcomeScreen";
		this->Text = L"WelcomeScreen";
		this->ResumeLayout(false);
		this->PerformLayout();

		fetchMovies();

		this->AutoScroll = true;

		for (int i = 0; i < movies->Length; i++)
		{
			for (int j = 0; j < 4; j++)
			{
				movieLabels[i * 4 + j] = gcnew Label();
				movieLabels[i * 4 + j]->AutoSize = true;
				movieLabels[i * 4 + j]->Font = (gcnew System::Drawing::Font(L"Arial", 20, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
					static_cast<System::Byte>(0)));
				movieLabels[i * 4 + j]->Location = System::Drawing::Point(100 + (j * 300), 100 + (i * 300));

				captionLabels[i * 4 + j] = (gcnew System::Windows::Forms::Label());
				captionLabels[i * 4 + j]->AutoSize = true;
				captionLabels[i * 4 + j]->Font = (gcnew System::Drawing::Font(L"Arial", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
					static_cast<System::Byte>(0)));
				captionLabels[i * 4 + j]->Location = System::Drawing::Point(100 + (j * 300), 150 + (i * 300));
				/*movieImages[i * 4 + j] = gcnew PictureBox();
				movieImages[i * 4 + j]->Location = System::Drawing::Point(100 + j * 200, 100 + i * 50);
				movieImages[i * 4 + j]->Size = System::Drawing::Size(100, 50);
				movieImages[i * 4 + j]->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
				movieImages[i * 4 + j]->TabIndex = 0;
				movieImages[i * 4 + j]->TabStop = false;*/
				this->Controls->Add(movieLabels[i * 4 + j]);
				this->Controls->Add(captionLabels[i * 4 + j]);
				this->Controls->Add(movieImages[i * 4 + j]);
			}
		}

		for (int i = 0; i < movies->Length; i++)
		{
			movieLabels[i * 4]->Text = movies[i];
	
			captionLabels[i * 4]->Text = captions[i];
			//movieImages[i]->ImageLocation = url[i];
			//movieImages[i]->Load(url[i]);
		}
		this->Controls->Add(this->movieName);
		this->movieName->Location = System::Drawing::Point(100, 100);
		this->movieName->AutoSize = true;
		this->movieName->Name = L"movieName";
		this->movieName->Size = System::Drawing::Size(35, 13);
	}
private:
	String^ movieData;
};