#include "SimpleMusicType.h"

// default constructor.
SimpleMusicType::SimpleMusicType() {
	num = "";
	title = "";
}

// copy constructor.
SimpleMusicType::SimpleMusicType(const SimpleMusicType& other) {
	num = other.num;
	title = other.title;
}

//default constructor with 1 parameter.
SimpleMusicType::SimpleMusicType(string inNum) {
	num = inNum;
	title = "";
}
//default constructor with 2 parameters.
SimpleMusicType::SimpleMusicType(string inNum, string inTitle) {
	num = inNum;
	title = inTitle;
}

// destructor.
SimpleMusicType::~SimpleMusicType() {}


// 음악 번호 반환.
string SimpleMusicType::GetNum() {
	return num;
}
// 음악 제목 반환.
string SimpleMusicType::GetTitle() {
	return title;
}


// 음악 번호 설정.
void SimpleMusicType::SetNum(string inNum) {
	num = inNum;
}
// 음악 제목 설정.
void SimpleMusicType::SetTitle(string inTitle) {
	title = inTitle;
}


// operator== overloading
bool SimpleMusicType::operator==(const SimpleMusicType& other) {
	if (this->num.compare(other.num) == 0)
		return true;
	else
		return false;
}
// operator!= overloading
bool SimpleMusicType::operator!=(const SimpleMusicType& other) {
	if (this->num.compare(other.num) != 0)
		return true;
	else
		return false;
}
// operator< overloading
bool SimpleMusicType::operator<(const SimpleMusicType& other) {
	if (this->num.compare(other.num) < 0)
		return true;
	else
		return false;
}
// operator> overloading
bool SimpleMusicType::operator>(const SimpleMusicType& other) {
	if (this->num.compare(other.num) > 0)
		return true;
	else
		return false;
}

// operator= overloading
SimpleMusicType& SimpleMusicType::operator=(const SimpleMusicType& other) {
	this->num = other.num;
	this->title = other.title;
	return *this;
}

//id를 title과 artist로 구분
void SimpleMusicType::ConvertIDtoTitleNArtist(string& inNum, string& title, string&artist) {
	string temp = "";
	int f = 0;
	int Maxsize = inNum.length();
	for (int i = 0;i < Maxsize;i++) {
		if (inNum[i] == '_') {
			title = temp;
			f = i;
			break;
		}
		else {
			temp += inNum[i];
		}
	}

	temp = "";
	for (int i = f+1;i < Maxsize;i++) {
		temp += inNum[i];
	}
	artist = temp;
}

//화면에 모든 정보 출력.
void SimpleMusicType::DisplayRecord() {
	string Intitle, Inartist;
	ConvertIDtoTitleNArtist(num, Intitle, Inartist);

	cout << "\n\t  *** MusicID: " << num << endl;
	cout << "\t  | 곡명: " << Intitle << endl;
	cout << "\t  | 가수: " << Inartist << endl;
	
}