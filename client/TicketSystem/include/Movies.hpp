#pragma once
#include <string>
#include <iostream>
#using <System.dll>

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;
using namespace System::Net;
using namespace System::Text;

public ref class Movies : public System::Windows::Forms::Form {
public:
	Movies(void) {
		InitializeComponent();
	}
	void fetchMovies();
	String^ getMovies();

	private: System::Windows::Forms::Label^ movieName;

	void InitializeComponent(void) {
		this->movieName = (gcnew System::Windows::Forms::Label());
		this->SuspendLayout();
		
		this->movieName->AutoSize = true;
		this->movieName->Location = System::Drawing::Point(0, 100);
		this->movieName->Name = L"movieName";
		this->movieName->Size = System::Drawing::Size(35, 13);
		this->movieName->Text = L"label1";
		this->Controls->Add(this->movieName);
	}
private:
	String^ movieData;
};