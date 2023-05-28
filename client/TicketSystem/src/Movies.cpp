#include "pch.h"
#include "Movies.hpp"

using namespace std;
void Movies::fetchMovies() {
	// Create WebClient to make HTTP request
	WebClient^ client = gcnew WebClient();

	// Set API endpoint URL and headers
	Uri^ url = gcnew Uri("https://moviesdatabase.p.rapidapi.com/titles/?year=2023");
	client->Headers->Add("X-RapidAPI-Key", "695f25458cmsh1b721beeecf3cf3p18466ejsn05afc1a3635f");
	client->Headers->Add("X-RapidAPI-Host", "moviesdatabase.p.rapidapi.com");

	try
	{
		Stream^ stream = client->OpenRead(url);
		StreamReader^ reader = gcnew StreamReader(stream);
		String^ json = reader->ReadToEnd();

		char* ch = static_cast<char*>(Marshal::StringToHGlobalAnsi(json).ToPointer());

		rapidjson::Document doc;
		doc.Parse(ch);

		Marshal::FreeHGlobal(IntPtr(ch));

		if (doc.IsObject())
		{
			// Access the "results" array
			if (doc.HasMember("results") && doc["results"].IsArray())
			{
				for (rapidjson::SizeType i = 0; i < doc["results"].Size(); i++)
				{
					const rapidjson::Value& result = doc["results"][i];

					if (result.HasMember("titleText") && result["titleText"].IsObject())
					{
						const rapidjson::Value& titleText = result["titleText"];
						if (titleText.HasMember("text") && titleText["text"].IsString())
						{
							String^ title = gcnew String(titleText["text"].GetString());
							String^ url = "";
							int year = 0;
							String^ caption = "";
							String^ type = "";

							if (result.HasMember("primaryImage") && result["primaryImage"].IsObject())
							{
								caption = gcnew String(result["primaryImage"]["caption"]["plainText"].GetString());
								url = gcnew String(result["primaryImage"]["url"].GetString());
							}

							if (result.HasMember("releaseYear") && result["releaseYear"].IsObject())
							{
								year = result["releaseYear"]["year"].GetInt();

								if (result.HasMember("type") && result["type"].IsObject()) type = gcnew String(result["type"].GetString());
							}
							//this->movies[i] = title;
							//this->captions[i] = caption;
							//this->url[i] = url;
							//this->years[i] = year.ToString();
							this->movieArray[i]->title = title;
							this->movieArray[i]->caption = caption;
							this->movieArray[i]->url = url;
							//this->movieArray[i]->year = year.ToString();
						}
					}
				}
			}
		}
	}
	catch (WebException^ e)
	{
		// Handle any exceptions thrown by the WebClient
		Console::WriteLine("WebException: {0}", e->Message);
	}
}

String^ Movies::getMovies() {
	return this->movieData;
}

void Movies::handleMovieClick(System::Object^ sender, System::EventArgs^ e)
{
	PictureBox^ clickedPictureBox = dynamic_cast<PictureBox^>(sender);
	if (clickedPictureBox != nullptr)
	{
		int index = Array::IndexOf(movieImages, clickedPictureBox);

		this->Hide();
		this->movieInformation->Show();
		this->movieInformation->movieName->Text = movieArray[index]->title;
	}
}


void Movies::handleMovieClick(Movie movie) {
	Console::Clear();
}