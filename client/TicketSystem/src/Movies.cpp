#include "pch.h"
#include "Movies.hpp"

using namespace std;
void Movies::fetchMovies() {
	String^ url = "https://api.themoviedb.org/3/movie/now_playing?api_key=1f54bd990f1cdfb230adb312546d765d";
	WebClient^ client = gcnew WebClient();
	String^ json = Encoding::UTF8->GetString(client->DownloadData(url));

    int length = json->Length;
    char* buffer = new char[length + 1];

    for (int i = 0; i < length; i++)
    {
        buffer[i] = static_cast<char>(json[i]);
    }
    buffer[length] = '\0';

    std::string str(buffer); // Convert from char* to std::string
    delete[] buffer;
    this->movieData = json;
	Console::WriteLine(json);
}

String^ Movies::getMovies() {
	return this->movieData;
}

//Movies* Movies::getInstance() {
//    if (!instance)
//    {
//        instance = new Movies();
//    }
//    return instance;
//}