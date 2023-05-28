#pragma once
#include <string>
#include <iostream>
#include <array>
#include "rapidjson/document.h"
#include "rapidjson/writer.h"
#include "rapidjson/stringbuffer.h"
#include "rapidjson/istreamwrapper.h"
#include "rapidjson/error/en.h"
#include "MovieInformation.hpp"
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

	value struct Movie {
		String^ title;
		String^ url;
		String^ year;
		String^ caption;
		String^ type;
	};
	void fetchMovies();
	void handleMovieClick(Movie movie);
	void handleMovieClick(System::Object^ sender, System::EventArgs^ e);
	String^ getMovies();

	cli::array<String^>^ movies = gcnew cli::array<String^>(100);
	cli::array<String^>^ captions = gcnew cli::array<String^>(100);
	cli::array<String^>^ years = gcnew cli::array<String^>(100);
	cli::array<String^>^ url = gcnew cli::array<String^>(100);
	cli::array<Label^>^ movieLabels;
	cli::array<Label^>^ captionLabels;
	cli::array<PictureBox^>^ movieImages;
	cli::array<Movie^>^ movieArray = gcnew cli::array<Movie^>(100);

private:
	System::Windows::Forms::Label^ movieName;
	System::Windows::Forms::Label^ heading;
	MovieInformation^ movieInformation = gcnew MovieInformation();
	void InitializeComponent(void) {
		for (int i = 0; i < 100; i++) {
			movieArray[i] = gcnew Movie();
		}
		this->movieName = (gcnew System::Windows::Forms::Label());
		this->SuspendLayout();
		movieLabels = gcnew cli::array<Label^>(movies->Length * 4);
		captionLabels = gcnew cli::array<Label^>(movies->Length * 4);
		movieImages = gcnew cli::array<PictureBox^>(movies->Length * 4);
		this->heading = (gcnew System::Windows::Forms::Label());

		this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
		this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
		this->BackColor = System::Drawing::Color::IndianRed;
		this->ClientSize = System::Drawing::Size(1264, 681);
		this->Name = L"Movies";
		this->Text = L"Movies";
		this->ResumeLayout(false);
		this->PerformLayout();

		this->heading->AutoSize = true;
		this->heading->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 24, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
		this->heading->Location = System::Drawing::Point(420, 70);
		this->heading->Name = L"heading";
		this->heading->Size = System::Drawing::Size(500, 31);
		this->heading->TabIndex = 0;
		this->heading->Text = L"Available movies in cinema 1";
		this->heading->TextAlign = System::Drawing::ContentAlignment::TopCenter;
		this->Controls->Add(this->heading);
		
		
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
				movieImages[i * 4 + j] = gcnew PictureBox();
				movieImages[i * 4 + j]->Location = System::Drawing::Point(75 + (j * 300), 200 + (i * 350));
				movieImages[i * 4 + j]->Size = System::Drawing::Size(200, 300);
				movieImages[i * 4 + j]->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
				movieImages[i * 4 + j]->TabIndex = 0;
				movieImages[i * 4 + j]->TabStop = false;
				//handle movie click
				movieImages[i * 4 + j]->Click += gcnew System::EventHandler(this, &Movies::handleMovieClick);

				int index = (i * 4) + j;
				if (index < url->Length) {
					movieImages[index]->ImageLocation = this->movieArray[index]->url;
				}
				this->Controls->Add(movieLabels[i * 4 + j]);
				this->Controls->Add(captionLabels[i * 4 + j]);
				this->Controls->Add(movieImages[i * 4 + j]);
			}
		}

		for (int i = 0; i < movies->Length; i++)
		{
			//movieArray[i * 4]->title = movies[i];
			//movieArray[i * 4]->caption = captions[i];
			//movieLabels[i * 4]->Text = movieArray[i]->title;
			//captionLabels[i * 4]->Text = captions[i];
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