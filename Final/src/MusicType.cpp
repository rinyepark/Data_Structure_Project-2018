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



// ���� ��ȣ ��ȯ.
string MusicType::GetNum() {
	return num;
}


// ���� ���� ��ȯ.
string MusicType::GetTitle() {
	return title;
}
// �帣�� ��ȯ.
string MusicType::GetGenre() {
	return genre;
}
// ������ ��ȯ.
string MusicType::GetArtist() {
	return artist;
}
// �ٹ��� ��ȯ.
string MusicType::GetAlbum() {
	return album;
}
// ���� ���� ��ȯ.
string MusicType::GetLyrics() {
	return lyrics;
}

//���� �߸��� ��ȯ.
string MusicType::GetReleaseD() {
	return releaseD;
}
//���� ���ϸ� ��ȯ.
string MusicType::GetFilename() {
	return filename;
}

//���� �۰ ��ȯ.
string MusicType::GetComposer() {
	return composer;
}

//���� �ۻ簡 ��ȯ.
string MusicType::GetLyricist() {
	return lyricist;
}

//���� ���ƿ� ���� ��ȯ.
bool MusicType::GetHeart() {
	return heart;
}

//���� ���Ƚ�� ��ȯ.
int MusicType::GetCount() {
	return m_count;
}

//���� ����ð� ��ȯ.
string MusicType::GetTime() {
	return time;
}

//���� ���Ƚ�� �ʴ����� ��ȯ.
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

//������ ���� ���� ��ȯ.
string MusicType::GetIsInPlaylist() {
	return IsInPlaylist;
}


// ���� ��ȣ ����.
void MusicType::SetNum(string inNum) {
	num = inNum;
}
// ���� ���� ����.
void MusicType::SetTitle(string inTitle) {
	title = inTitle;
}
// �帣�� ����.
void MusicType::SetGenre(string inGenre) {
	genre = inGenre;
}
// ������ ����.
void MusicType::SetArtist(string inArtist) {
	artist = inArtist;
}
// �ٹ��� ����.
void MusicType::SetAlbum(string inAlbum) {
	album = inAlbum;
}
// ���� ���� ����.
void MusicType::SetLyrics(string inLyrics) {
	lyrics = inLyrics;
}


// ���� �߸��� ����.
void MusicType::SetReleaseD(string inReleaseD) {
	releaseD = inReleaseD;
}

//���� �۰ ����.
void MusicType::SetComposer(string inComposer) {
	composer = inComposer;
}

//���� �ۻ簡 ����.
void MusicType::SetLyricist(string inLyricist) {
	lyricist = inLyricist;
}

//���� ���ϸ� ����.
void MusicType::SetFilename(string inFilename) {
	filename = inFilename;
}

//���� ���ƿ� ����.
void MusicType::SetHeart(bool inHeart) {
	heart = inHeart;
}

//���� ���Ƚ�� ����.
void MusicType::SetCount(int inCount) {
	m_count = inCount;
}

//���� ����ð� ����.
void MusicType::SetTime(string inTime) {
	time = inTime;
}

//������ ���� ���� ����.
void MusicType::SetIsInPlaylist(string inPL) {
	IsInPlaylist = inPL;
}


// ���� ���� ����.
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

// Ű����� ���� ��ȣ ����.
void MusicType::SetNumFK() {
	cout << "\t    MusicID: ";
	getline(cin >> ws, num);	// ���� ����
}
// Ű����� ���� ���� ����.
void MusicType::SetTitleFK() {
	cout << "\t    ���: ";
	getline(cin >> ws, title);	// ���� ����
}
// Ű����� �帣�� ����.
void MusicType::SetGenreFK() {
	cout << "\t    �帣: ";
	getline(cin >> ws, genre);	// ���� ����
}
// Ű����� ������ ����.
void MusicType::SetArtistFK() {
	cout << "\t    ��Ƽ��Ʈ (�������� ��� '_'�� ����)\n";
	cout << "\t        :";
	getline(cin >> ws, artist);	// ���� ����
}
// Ű����� �ٹ��� ����.
void MusicType::SetAlbumFK() {
	cout << "\t    �ٹ�: ";
	getline(cin >> ws, album);	// ���� ����
}
// Ű����� ���� ���� ����.
void MusicType::SetLyricsFK() {
	cout << "\t    ����: ";
	getline(cin >> ws, lyrics);	// ���� ����
}

// Ű����� ���� �߸��� ����.
void MusicType::SetReleaseDFK() {
	cout << "\t    �߸���(YYMMDD): ";
	getline(cin >> ws, releaseD);	// ���� ����
}

// Ű����� ���� �۰ ����.
void MusicType::SetComposerFK() {
	cout << "\t    �۰: ";
	getline(cin >> ws, composer);	// ���� ����
}

// Ű����� ���� �ۻ簡 ����.
void MusicType::SetLyricistFK() {
	cout << "\t    �ۻ簡: ";
	getline(cin >> ws, lyricist);	// ���� ����
}

// Ű����� ���� ���ϸ� ����.
void MusicType::SetFilenameFK() {
	cout << "\t    �������ϸ�: ";
	getline(cin >> ws, filename);	// ���� ����
}

// Ű����� ���� ����ð� ����.
void MusicType::SetTimeFK() {
	while (1) {
		cout << "\t    ����ð�(MM:SS): ";
		getline(cin >> ws, time);	// ���� ����
		if (time.length() != 5 || time[2] != ':') {
			cout << "\n\t\t  |�ð� ���Ŀ� ���� �ٽ� �Է��Ͻÿ�|\n\n";
			continue;
		}
		else {
			break;
		}
	}
}

// Ű����� ���� ���� ����.
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

// ���� ��ȣ�� ȭ�鿡 ���.
void MusicType::DisplayNum() {
	cout << "\t  *** MusicID: " << num << endl;
}
// ���� ������ ȭ�鿡 ���.
void MusicType::DisplayTitle() {
	cout << "\t  | ���: " << title << endl;
}
// �帣���� ȭ�鿡 ���.
void MusicType::DisplayGenre() {
	cout << "\t  | �帣: " << genre << endl;
}
// �������� ȭ�鿡 ���.
void MusicType::DisplayArtist() {
	cout << "\t  | ����: " << artist << endl;
}
// �ٹ����� ȭ�鿡 ���.
void MusicType::DisplayAlbum() {
	cout << "\t  | �ٹ�: " << album << endl;
}
// ���� ���縦 ȭ�鿡 ���.
void MusicType::DisplayLyrics() {
	cout << "\t  | ����: " << lyrics << endl;
}
// ���� �߸����� ȭ�鿡 ���.
void MusicType::DisplayReleaseD() {
	cout << "\t  | �߸���: " << releaseD << endl;
}
// ���� �۰�� ȭ�鿡 ���.
void MusicType::DisplayComposer() {
	cout << "\t  | �۰: " << composer << endl;
}
// ���� �ۻ簡�� ȭ�鿡 ���.
void MusicType::DisplayLyricist() {
	cout << "\t  | �ۻ簡: " << lyricist << endl;
}
// ���� ���ϸ��� ȭ�鿡 ���.
void MusicType::DisplayFilename() {
	cout << "\t  | ���ϸ�: " << filename << endl;
}
// ���� ����ð��� ȭ�鿡 ���.
void MusicType::DisplayTime() {
	cout << "\t  | ����ð�: " << time << endl;
}

// ���� ���Ƚ���� ȭ�鿡 ���.
void MusicType::DisplayCount() {
	cout << "\t  | ���Ƚ��: " << m_count << endl;
}
// ���ƿ� ���θ� ȭ�鿡 ���.
void MusicType::DisplayHeart() {
	if(heart)
		cout << "\t     ������" << endl;
	else
		cout << "\t     ������" << endl;
}

// ���� ������ ȭ�鿡 ���.
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

// ���Ϸ� ���� ���� ������.
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

// ���Ͽ� ���� �ۼ�.
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

