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
	//create array of type String^
	
	cli::array<String^>^ movies = gcnew cli::array<String^>(100);

	private: System::Windows::Forms::Label^ movieName;

	void InitializeComponent(void) {
		this->movieName = (gcnew System::Windows::Forms::Label());
		this->SuspendLayout();

		this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
		this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
		this->BackColor = System::Drawing::Color::IndianRed;
		this->ClientSize = System::Drawing::Size(1264, 681);
		this->Name = L"WelcomeScreen";
		this->Text = L"WelcomeScreen";
		this->ResumeLayout(false);
		this->PerformLayout();

		fetchMovies();
		this->movieName->Text = movies[0];
		this->Controls->Add(this->movieName);
		this->movieName->Location = System::Drawing::Point(100, 100);
		this->movieName->AutoSize = true;
		this->movieName->Name = L"movieName";
		this->movieName->Size = System::Drawing::Size(35, 13);
	}
private:
	String^ movieData;
};