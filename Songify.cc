#include "Songify.h"

Songify::Songify(): factory(new MediaFactory()){

}

Songify::~Songify(){
    delete factory;
    for (int i = 0; i < albums.getSize(); ++i){
        delete albums[i];
    }
}

//adds an new album
bool Songify::addAlbum(const string & artist , const string & albumTitle){
    if (albums.getSize() >= MAX_ARRAY) return false;
    Album* a;
    factory->createAlbum(artist, albumTitle, &a);
    albums += a;
    return true;
}

//adds a new song
bool Songify::addSong(const string & artist , const string & songTitle , const string & albumTitle){
    Song* s;
    if (!factory->createSong(artist, songTitle, &s)){
        return false;
    }

    // cout << "add in songify" << endl;
    // cout << artist <<  " " << albumTitle << endl;
    for (int i = 0; i < albums.getSize(); ++i){
        // cout << " Artist: "<< albums[i]->getArtist() <<  " Title: " << albums[i]->getTitle() << endl;
        if (albums[i]->getTitle() == albumTitle && albums[i]->getArtist() == artist && albums[i]->getSize() < MAX_ARRAY){
            // cout << "add worked" << endl;
            return albums[i]->addSong(s);
        }
    }
    // cout << "FALSE???" << endl;
    return false;
}

//removes a song from an album
bool Songify::removeSong(const string & artist , const string & songTitle , const string & albumTitle){
    Song* s;
    for (int i = 0; i < albums.getSize(); ++i){
        if (albums[i]->getTitle() == albumTitle && albums[i]->getArtist() == artist){
            return albums[i]->removeSong(songTitle, &s);
        }
    }
    return false;
}

//removes the album from the albums list
bool Songify::removeAlbum(const string & artist, const string & albumTitle){
    for (int i =0; i < albums.getSize(); ++i){
        if (albums[i]->getTitle() == albumTitle && albums[i]->getArtist() == artist){
            albums -= albums[i];
            return true;
        }
    }
    return false;
}

//gets an album with output param
bool Songify::getAlbum(int index, Album** a) const{
    if (index < 0 || index >= albums.getSize()){
        *a = NULL;
        return false;
    }
    *a = albums[index];
    return true;
}

//gets an array of albums 
const Array<Album*>& Songify::getAlbums() const{
    return albums;
}

//gets the playlist
void Songify::getPlaylist(string artist, string category, Array<Song*>& playlist) const{
    Criteria* crit;
    if (!factory->createCriteria(artist, category, &crit)){
        return;
    }

    for (int i = 0; i < albums.getSize(); ++i){
        // if (albums[i]->getArtist() == artist){
        // cout << "artist: " << albums[i]->getArtist() << " Size: "<< albums[i]->getSize() << endl;
        for (int k = 0; k < albums[i]->getSize(); ++k){
            // cout << k << endl;
            if (crit->matches(*(*albums[i])[k])){
                Song* s = (*albums[i])[k];
                playlist += s;
                // cout << "added to playlist the current size is: "<< playlist.getSize() << endl;
            }
        }
        // }
    }
    delete crit;
}