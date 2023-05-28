#include "pch.h"
#include "Movies.hpp"

using namespace std;
void Movies::fetchMovies() {
	// Create WebClient to make HTTP request
	WebClient^ client = gcnew WebClient();

	// Set API endpoint URL and headers
	Uri^ url = gcnew Uri("https://api.themoviedb.org/3/trending/movie/day?api_key=637a03d7ec7ceedefb130d64c7ce936e");
	client->Headers->Add("api_key", "637a03d7ec7ceedefb130d64c7ce936e");

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

					if (result.HasMember("title") && result["title"].IsString())
					{
						String^ title = gcnew String(result["title"].GetString());
						String^ url = "https://image.tmdb.org/t/p/w200";
						String^ year = "";
						String^ caption = "";
						String^ type = "";

						if (result.HasMember("poster_path") && result["poster_path"].IsString())
						{
							caption = gcnew String(result["overview"].GetString());
							url += gcnew String(result["poster_path"].GetString());
						}

						if (result.HasMember("release_date") && result["release_date"].IsString())
						{
							//year = result["release_date"].GetString();
						}
						this->movieArray[i]->title = title;
						this->movieArray[i]->caption = caption;
						this->movieArray[i]->url = url;
						this->movieArray[i]->year = year;
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
		this->movieInformation->moviePoster->ImageLocation = movieArray[index]->url;
		this->movieInformation->movieCaption->Text = movieArray[index]->caption;
	}
}


void Movies::handleMovieClick(Movie movie) {
	Console::Clear();
}