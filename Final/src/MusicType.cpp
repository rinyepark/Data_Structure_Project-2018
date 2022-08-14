#include "MusicType.h"

// default constructor.
MusicType::MusicType() {
	num = "";
	title = "";
	genre = "";
	artist = "";
	album = "";
	lyrics = "";

	releaseD = "";
	filename = "";
	composer = "";
	lyricist = "";

	m_count = 0;
	heart = false;
	time = "";

	IsInPlaylist = "00000";

}
// copy constructor.
MusicType::MusicType(const MusicType& other) {
	num = other.num;
	title = other.title;
	genre = other.genre;
	artist = other.artist;
	album = other.album;
	lyrics = other.lyrics;

	releaseD = other.releaseD;
	filename = other.filename;
	composer = other.composer;
	lyricist = other.lyricist;

	m_count = other.m_count;
	heart = other.heart;
	time = other.time;

	IsInPlaylist = other.IsInPlaylist;
}
// default constructor with parameter.
MusicType::MusicType(string inNum) {
	num = inNum;
	title = "";
	genre = "";
	artist = "";
	album = "";
	lyrics = "";

	releaseD = "";
	filename = "";
	composer = "";
	lyricist = "";

	m_count = 0;
	heart = false;
	time = "";

	IsInPlaylist = "00000";
}
// destructor.
MusicType::~MusicType() {}



// 음악 번호 반환.
string MusicType::GetNum() {
	return num;
}


// 음악 제목 반환.
string MusicType::GetTitle() {
	return title;
}
// 장르명 반환.
string MusicType::GetGenre() {
	return genre;
}
// 가수명 반환.
string MusicType::GetArtist() {
	return artist;
}
// 앨범명 반환.
string MusicType::GetAlbum() {
	return album;
}
// 음악 가사 반환.
string MusicType::GetLyrics() {
	return lyrics;
}

//음악 발매일 반환.
string MusicType::GetReleaseD() {
	return releaseD;
}
//음악 파일명 반환.
string MusicType::GetFilename() {
	return filename;
}

//음악 작곡가 반환.
string MusicType::GetComposer() {
	return composer;
}

//음악 작사가 반환.
string MusicType::GetLyricist() {
	return lyricist;
}

//음악 좋아요 여부 반환.
bool MusicType::GetHeart() {
	return heart;
}

//음악 재생횟수 반환.
int MusicType::GetCount() {
	return m_count;
}

//음악 재생시간 반환.
string MusicType::GetTime() {
	return time;
}

//음악 재생횟수 초단위로 반환.
int MusicType::GetConvertSecond() {
	int m1, m2, s1, s2;

	m1 = time[0] - 48;
	m2 = time[1] - 48;

	s1 = time[3] - 48;
	s2 = time[4] - 48;

	int result = 0;
	result = m1 * 600 + m2 * 60 + s1 * 10 + s2;
	return result;
}

//재생목록 속한 여부 반환.
string MusicType::GetIsInPlaylist() {
	return IsInPlaylist;
}


// 음악 번호 설정.
void MusicType::SetNum(string inNum) {
	num = inNum;
}
// 음악 제목 설정.
void MusicType::SetTitle(string inTitle) {
	title = inTitle;
}
// 장르명 설정.
void MusicType::SetGenre(string inGenre) {
	genre = inGenre;
}
// 가수명 설정.
void MusicType::SetArtist(string inArtist) {
	artist = inArtist;
}
// 앨범명 설정.
void MusicType::SetAlbum(string inAlbum) {
	album = inAlbum;
}
// 음악 가사 설정.
void MusicType::SetLyrics(string inLyrics) {
	lyrics = inLyrics;
}


// 음악 발매일 설정.
void MusicType::SetReleaseD(string inReleaseD) {
	releaseD = inReleaseD;
}

//음악 작곡가 설정.
void MusicType::SetComposer(string inComposer) {
	composer = inComposer;
}

//음악 작사가 설정.
void MusicType::SetLyricist(string inLyricist) {
	lyricist = inLyricist;
}

//음악 파일명 설정.
void MusicType::SetFilename(string inFilename) {
	filename = inFilename;
}

//음악 좋아요 설정.
void MusicType::SetHeart(bool inHeart) {
	heart = inHeart;
}

//음악 재생횟수 설정.
void MusicType::SetCount(int inCount) {
	m_count = inCount;
}

//음악 재생시간 설정.
void MusicType::SetTime(string inTime) {
	time = inTime;
}

//재생목록 속한 여부 설정.
void MusicType::SetIsInPlaylist(string inPL) {
	IsInPlaylist = inPL;
}


// 음악 정보 설정.
void MusicType::SetRecord(string inNum, string inTitle, string inGenre, string inArtist, string inAlbum, string inLyrics,
	string inReleaseD, string inComposer, string inLyricist, string inFilename, string inTime) {
	SetNum(inNum);
	SetTitle(inTitle);
	SetGenre(inGenre);
	SetArtist(inArtist);
	SetAlbum(inAlbum);
	SetLyrics(inLyrics);

	SetReleaseD(inReleaseD);
	SetComposer(inComposer);
	SetLyricist(inLyricist);
	SetFilename(inFilename);
	SetTime(inTime);
}

// 키보드로 음악 번호 설정.
void MusicType::SetNumFK() {
	cout << "\t    MusicID: ";
	getline(cin >> ws, num);	// 띄어쓰기 포함
}
// 키보드로 음악 제목 설정.
void MusicType::SetTitleFK() {
	cout << "\t    곡명: ";
	getline(cin >> ws, title);	// 띄어쓰기 포함
}
// 키보드로 장르명 설정.
void MusicType::SetGenreFK() {
	cout << "\t    장르: ";
	getline(cin >> ws, genre);	// 띄어쓰기 포함
}
// 키보드로 가수명 설정.
void MusicType::SetArtistFK() {
	cout << "\t    아티스트 (여러명인 경우 '_'로 구분)\n";
	cout << "\t        :";
	getline(cin >> ws, artist);	// 띄어쓰기 포함
}
// 키보드로 앨범명 설정.
void MusicType::SetAlbumFK() {
	cout << "\t    앨범: ";
	getline(cin >> ws, album);	// 띄어쓰기 포함
}
// 키보드로 음악 가사 설정.
void MusicType::SetLyricsFK() {
	cout << "\t    가사: ";
	getline(cin >> ws, lyrics);	// 띄어쓰기 포함
}

// 키보드로 음악 발매일 설정.
void MusicType::SetReleaseDFK() {
	cout << "\t    발매일(YYMMDD): ";
	getline(cin >> ws, releaseD);	// 띄어쓰기 포함
}

// 키보드로 음악 작곡가 설정.
void MusicType::SetComposerFK() {
	cout << "\t    작곡가: ";
	getline(cin >> ws, composer);	// 띄어쓰기 포함
}

// 키보드로 음악 작사가 설정.
void MusicType::SetLyricistFK() {
	cout << "\t    작사가: ";
	getline(cin >> ws, lyricist);	// 띄어쓰기 포함
}

// 키보드로 음악 파일명 설정.
void MusicType::SetFilenameFK() {
	cout << "\t    음악파일명: ";
	getline(cin >> ws, filename);	// 띄어쓰기 포함
}

// 키보드로 음악 재생시간 설정.
void MusicType::SetTimeFK() {
	while (1) {
		cout << "\t    재생시간(MM:SS): ";
		getline(cin >> ws, time);	// 띄어쓰기 포함
		if (time.length() != 5 || time[2] != ':') {
			cout << "\n\t\t  |시간 형식에 맞춰 다시 입력하시오|\n\n";
			continue;
		}
		else {
			break;
		}
	}
}

// 키보드로 음악 정보 설정.
void MusicType::SetRecordFK() {
	SetTitleFK();
	SetGenreFK();
	SetArtistFK();
	SetAlbumFK();
	SetLyricsFK();

	SetReleaseDFK();
	SetComposerFK();
	SetLyricistFK();
	SetFilenameFK();
	SetTimeFK();
}

// 음악 번호를 화면에 출력.
void MusicType::DisplayNum() {
	cout << "\t  *** MusicID: " << num << endl;
}
// 음악 제목을 화면에 출력.
void MusicType::DisplayTitle() {
	cout << "\t  | 곡명: " << title << endl;
}
// 장르명을 화면에 출력.
void MusicType::DisplayGenre() {
	cout << "\t  | 장르: " << genre << endl;
}
// 가수명을 화면에 출력.
void MusicType::DisplayArtist() {
	cout << "\t  | 가수: " << artist << endl;
}
// 앨범명을 화면에 출력.
void MusicType::DisplayAlbum() {
	cout << "\t  | 앨범: " << album << endl;
}
// 음악 가사를 화면에 출력.
void MusicType::DisplayLyrics() {
	cout << "\t  | 가사: " << lyrics << endl;
}
// 음악 발매일을 화면에 출력.
void MusicType::DisplayReleaseD() {
	cout << "\t  | 발매일: " << releaseD << endl;
}
// 음악 작곡가를 화면에 출력.
void MusicType::DisplayComposer() {
	cout << "\t  | 작곡가: " << composer << endl;
}
// 음악 작사가를 화면에 출력.
void MusicType::DisplayLyricist() {
	cout << "\t  | 작사가: " << lyricist << endl;
}
// 음악 파일명을 화면에 출력.
void MusicType::DisplayFilename() {
	cout << "\t  | 파일명: " << filename << endl;
}
// 음악 재생시간을 화면에 출력.
void MusicType::DisplayTime() {
	cout << "\t  | 재생시간: " << time << endl;
}

// 음악 재생횟수를 화면에 출력.
void MusicType::DisplayCount() {
	cout << "\t  | 재생횟수: " << m_count << endl;
}
// 좋아요 여부를 화면에 출력.
void MusicType::DisplayHeart() {
	if(heart)
		cout << "\t     ♥♥♥" << endl;
	else
		cout << "\t     ♡♡♡" << endl;
}

// 음악 정보를 화면에 출력.
void MusicType::DisplayRecord() {
	cout << endl;
	DisplayNum();
	DisplayTitle();
	DisplayGenre();
	DisplayArtist();
	DisplayAlbum();
	DisplayLyrics();
	
	DisplayReleaseD();
	DisplayComposer();
	DisplayLyricist();
	DisplayFilename();

	DisplayTime();

	DisplayCount();
	DisplayHeart();

	cout << endl;
}


// operator== overloading
bool MusicType::operator==(const MusicType& other) {
	if (this->num.compare(other.num) == 0)
		return true;
	else
		return false;
}
// operator!= overloading
bool MusicType::operator!=(const MusicType& other) {
	if (this->num.compare(other.num) != 0)
		return true;
	else
		return false;
}
// operator< overloading
bool MusicType::operator<(const MusicType& other) {
	if (this->num.compare(other.num) < 0)
		return true;
	else
		return false;
}
// operator> overloading
bool MusicType::operator>(const MusicType& other) {
	if (this->num.compare(other.num) > 0)
		return true;
	else
		return false;

}

// operator= overloading
MusicType& MusicType::operator=(const MusicType& other) {
	this->num = other.num;
	this->title = other.title;
	this->artist = other.artist;
	this->genre = other.genre;
	this->album = other.album;
	this->lyrics = other.lyrics;

	this->releaseD = other.releaseD;
	this->composer = other.composer;
	this->lyricist = other.lyricist;
	this->filename = other.filename;

	this->time = other.time;
	this->m_count = other.m_count;
	this->heart = other.heart;

	this->IsInPlaylist = other.IsInPlaylist;

	return *this;
}

// 파일로 부터 정보 가져옴.
int MusicType::ReadDataFromFile(ifstream& fin) {
	string temp;
	getline(fin, title);
	getline(fin, genre);
	getline(fin, artist);
	getline(fin, album);
	getline(fin, lyrics);

	getline(fin, releaseD);
	getline(fin, composer);
	getline(fin, lyricist);
	getline(fin, filename);
	getline(fin, temp);
	m_count = atoi(temp.c_str());
	getline(fin, temp);
	heart = atoi(temp.c_str());
	getline(fin, time);
	getline(fin, IsInPlaylist);
	return 1;
}

// 파일에 정보 작성.
int MusicType::WriteDataToFile(ofstream& fout) {
	fout << title << endl;
	fout << genre << endl;
	fout << artist << endl;
	fout << album << endl;
	fout << lyrics << endl;

	fout << releaseD << endl;
	fout << composer << endl;
	fout << lyricist << endl;
	fout << filename << endl;

	fout << m_count << endl;
	fout << heart << endl;

	fout << time << endl;
	fout << IsInPlaylist << endl;

	return 1;
}

