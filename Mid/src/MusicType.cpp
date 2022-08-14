#include "MusicType.h"

// default constructor.
MusicType::MusicType() {
	id = "";
	title = "";
	artist = "";
	album = "";
	genre = "";
	lyrics = "";
	releaseD = "";
	count = 0;
}

// copy constructor.
MusicType::MusicType(const MusicType& anMusic) {
	this->id = anMusic.id;
	this->title = anMusic.title;
	this->artist = anMusic.artist;
	this->album = anMusic.album;
	this->genre = anMusic.genre;
	this->lyrics = anMusic.lyrics;
	this->releaseD = anMusic.releaseD;
	this->count = anMusic.count;
}

// destructor.
MusicType::~MusicType() {
}

// Get music id.
string MusicType::GetId() {
	return id;
}

// Get music title.
string MusicType::GetTitle() {
	return title;
}

// Get music artist.
string MusicType::GetArtist() {
	return artist;
}

// Get music album.
string MusicType::GetAlbum() {
	return album;
}

// Get music genre.
string MusicType::GetGenre() {
	return genre;
}

// Get music lyrics.
string MusicType::GetLyrics() {
	return lyrics;
}

// Get music release date.
string MusicType::GetReleaseDate() {
	return releaseD;
}

// Get music play number.
int MusicType::GetCount() {
	return count;
}


// Set music id.
void MusicType::SetId(string inId) {
	id = inId;
}

// Set music title.
void MusicType::SetTitle(string inTitle) {
	title = inTitle;
}

// Set music artist.
void MusicType::SetArtist(string inArtist) {
	artist = inArtist;
}

// Set music album.
void MusicType::SetAlbum(string inAlbum) {
	album = inAlbum;
}

// Set music genre.
void MusicType::SetGenre(string inGenre) {
	genre = inGenre;
}

// Set music lyrics.
void MusicType::SetLyrics(string inLyrics) {
	lyrics = inLyrics;
}

// Set music release date.
void MusicType::SetReleseDate(string inRelease) {
	releaseD = inRelease;
}

 //count 값을 늘림
void MusicType::PlayMusic() {
	count++;
}


// Set music record.
void MusicType::SetRecord(string inTitle, string inArtist, string inAlbum, string inGenre, string inLyrics, string inrelease) {
	SetTitle(inTitle);
	SetArtist(inArtist);
	SetAlbum(inAlbum);
	SetGenre(inGenre);
	SetLyrics(inLyrics);
	SetReleseDate(inrelease);
}



// Display music id on screen.
void MusicType::DisplayIdOnScreen() {
	cout << "\t 음악 ID: " << id << endl;
}

// Display music title on screen.
void MusicType::DisplayTitleOnScreen() {
	cout << "\t 곡 제목: " << title << endl;
}

// Display music artist on screen.
void MusicType::DisplayArtistOnScreen() {
	cout << "\t 아티스트: " << artist << endl;
}

// Display music album on screen.
void MusicType::DisplayAlbumOnScreen() {
	cout << "\t 앨범: " << album << endl;
}

// Display music genre on screen.
void MusicType::DisplayGenreOnScreen() {
	cout << "\t 장르: " << genre << endl;
}

// Display music lyrics on screen.
void MusicType::DisplayLyricsOnScreen() {
	cout << "\t 가사: " << lyrics << endl;
}

// Display music release date on screen.
void MusicType::DisplayReleaseDateOnScreen() {
	cout << "\t 발매일: " << releaseD << endl;
}

// Display music play count on screen.
void MusicType::DisplayCountOnScreen() {
	cout << "\t 재생횟수: " << count << endl;
}

// Display music record on screen.
void MusicType::DisplayRecordOnScreen() {
	cout << endl;
	DisplayIdOnScreen();
	DisplayTitleOnScreen();
	DisplayArtistOnScreen();
	DisplayAlbumOnScreen();
	DisplayGenreOnScreen();
	DisplayLyricsOnScreen();
	DisplayReleaseDateOnScreen();
}


// Set music id from keyboard.
void MusicType::SetIdFromKB() {
	cout << "\t 음악 ID: ";
	getline(cin >> ws, id);
}

// Set music title from keyboard.
void MusicType::SetTitleFromKB() {
	cout << "\t 곡 제목: ";
	getline(cin >> ws, title);
}

// Set music artist from keyboard.
void MusicType::SetArtistFromKB() {
	cout << "\t 아티스트: ";
	getline(cin >> ws, artist);
}

// Set music album from keyboard.
void MusicType::SetAlbumFromKB() {
	cout << "\t 앨범: ";
	getline(cin >> ws, album);
}

// Set music genre from keyboard.
void MusicType::SetGenreFromKB() {
	cout << "\t 장르: ";
	getline(cin >> ws, genre);
}

// Set music lyrics from keyboard.
void MusicType::SetLyricsFromKB() {
	cout << "\t 가사: ";
	getline(cin >> ws, lyrics);
}

// Set music release date from keyboard.
void MusicType::SetReleaseDateFromKB() {
	cout << "\t 발매일(YYMMDD): ";
	getline(cin >> ws, releaseD);
}

// Set music record from keyboard.
void MusicType::SetRecordFromKB() {
	SetTitleFromKB();
	SetArtistFromKB();
	SetAlbumFromKB();
	SetGenreFromKB();
	SetLyricsFromKB();
	SetReleaseDateFromKB();
}


// Read a record from file.
int MusicType::ReadDataFromFile(ifstream& fin) {
	getline(fin, id);
	getline(fin, title);
	getline(fin, artist);
	getline(fin, album);
	getline(fin, genre);
	getline(fin, lyrics);
	getline(fin, releaseD);

	return 1;
}

// Write a record into file.
int MusicType::WriteDataToFile(ofstream& fout) {
	fout << id << endl;
	fout << title << endl;
	fout << artist << endl;
	fout << album << endl;
	fout << genre << endl;
	fout << lyrics << endl;
	fout << releaseD << endl;


	return 1;
}



// operator== overloading
bool MusicType::operator==(MusicType &item) {
	if (this->id == item.id)
		return true;
	else
		return false;
}

// operator!= overloading
bool MusicType::operator!=(MusicType &item) {
	if (this->id != item.id)
		return true;
	else
		return false;
}

// operator> overloading
bool MusicType::operator>(MusicType &item) {
	if (this->id > item.id)
		return true;
	else
		return false;
}

// operator< overloading
bool MusicType::operator<(MusicType &item) {
	if (this->id < item.id)
		return true;
	else
		return false;
}

// operator>= overloading
bool MusicType::operator>=(MusicType &item) {
	if (this->id >= item.id)
		return true;
	else
		return false;
}

// operator<= overloading
bool MusicType::operator<=(MusicType &item) {
	if (this->id <= item.id)
		return true;
	else
		return false;
}

// operator= overloading
MusicType& MusicType::operator=(const MusicType &other) {
	this->id = other.id;
	this->title = other.title;
	this->artist = other.artist;
	this->genre = other.genre;
	this->album = other.album;
	this->lyrics = other.lyrics;
	this->releaseD = other.releaseD;
	this->count = other.count;
	return *this;
}