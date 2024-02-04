#include "Song.h"

Song::Song(const string& artist, const string&  title, const string& category, const string& content){
    this->artist = artist;
    this->title = title;
    this->category = category;
    this->content = content;
}

//getters
const string& Song::getArtist() const{
    return this->artist;
}

const string& Song::getCategory() const{
    return this->category;
}

const string& Song::getTitle() const{
    return this->title;
}

//mcheck if artist and title are equal
bool Song::matches(const string& artist, const string& title) const{
   return (this->artist == artist && this->title == title);
}

//print function
void Song::print(ostream& ost) const{
    ost << "Artist: " << artist << " title: " << title <<  "Category: " << category <<endl;
    //cout << "Artist: " << this->getArtist() << " title: " << this->getTitle() << endl;
}

void Song::play(ostream& ost) const{
   ost << "Artist: " << this->artist << " title: " << this->title << "Category: " << category << " Content: " << this->content << endl;
}

//overloading the << operator 
ostream& operator<<(ostream& ost, Song& song){
    ost << "Artist: " << song.artist << " Title: " << song.title << " Category: " << song.category << " Content: " << song.content<< endl;
    return ost;
}