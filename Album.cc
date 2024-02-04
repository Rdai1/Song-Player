#include "Album.h"
#include "Array.h"
#include "Song.h"

Album::Album(const string& artist, const string& title): artist(artist), title(title){
    
}

Album::~Album(){
    // cout << "Dtor album" << endl;
    for (int i =0; i < getSize(); ++i){
        delete songs[i];
    }
}

// Album::Album(const Album& abl): artist(abl.artist), title(abl.title){
//     Song* s;
//     //deep copying the songArray
//     for (int i = 0; i < abl.songs->getSize(); ++i){
//         abl.getSong(i, &s);
//         addSong(new Song(*s));
//     }
// }

//overloading the [] operator for songs
Song* Album::operator[](int index) const{
    return songs[index];
}

//checks if the artist and title matches 
bool Album::matches(const string& artist, const string& albumTitle) const{
    return (this->artist == artist && this->title == albumTitle);
}

//checks if song is less than
bool Album::lessThan(const Album& alb) const{
    if (this->artist < alb.artist)return true;
    if (this->artist > alb.artist)return false;

    if (this->title < alb.title)return true;
    return false;
}

bool Album::addSong(Song* s){
    // cout << "add in Album" << endl;
    if ((this->artist).compare(s->getArtist()) == 0){
        songs += s;
        return true;
    }
    // cout << "F" << endl;
    return false;
}

//getter
int Album::getSize() const{
    return songs.getSize();
}

//get song based on title
bool Album::getSong(const string& title, Song** s) const{
    for (int i = 0; i < getSize(); ++i){
        if (songs[i]->matches(this->artist, title)){
            *s = songs[i];
            return true;
        }
    }
    return false;
}

//remove song  based on song title
bool Album::removeSong(const string& songTitle, Song** s){

    if (getSong(songTitle, s)){
        songs -= *s;
        return true;
    }
    return false;
}

//overloading the << operator
ostream& operator<<(ostream& ost, Album& a){
    a.printShort(ost);
    return ost;
}

//prints metadata
void Album::printShort(ostream& ost) const{
    ost << "Title: " << this->title << " Artist: " << this->artist << endl;
    // return ost;
}

//prints metadata and each song's metadata
void Album::print(ostream& ost) const{
    ost << "Title: " <<  this->title << " Artist: " << this->artist << endl;
    // ost << "THE CURRENT SIZE: " << getSize() << endl;
    for (int i = 0; i < getSize(); ++i){
        ost << *songs[i];
    }
    // ost << "why man" << endl;
    // // return ost;
}