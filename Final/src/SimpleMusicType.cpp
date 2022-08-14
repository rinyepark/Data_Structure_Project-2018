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


// ���� ��ȣ ��ȯ.
string SimpleMusicType::GetNum() {
	return num;
}
// ���� ���� ��ȯ.
string SimpleMusicType::GetTitle() {
	return title;
}


// ���� ��ȣ ����.
void SimpleMusicType::SetNum(string inNum) {
	num = inNum;
}
// ���� ���� ����.
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

//id�� title�� artist�� ����
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

//ȭ�鿡 ��� ���� ���.
void SimpleMusicType::DisplayRecord() {
	string Intitle, Inartist;
	ConvertIDtoTitleNArtist(num, Intitle, Inartist);

	cout << "\n\t  *** MusicID: " << num << endl;
	cout << "\t  | ���: " << Intitle << endl;
	cout << "\t  | ����: " << Inartist << endl;
	
}