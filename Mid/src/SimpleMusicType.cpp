#include "SimpleMusicType.h"

// default constructor.
SimpleMusicType::SimpleMusicType() {
	id = "";
	title = "";
}

// copy constructor.
SimpleMusicType::SimpleMusicType(const SimpleMusicType& anSimp) {
	this->id = anSimp.id;
	this->title = anSimp.title;
}

// destructor.
SimpleMusicType::~SimpleMusicType() {
}



// Get music id.
string SimpleMusicType::GetId() {
	return id;
}

// Get music title.
string SimpleMusicType::GetTitle() {
	return title;
}



// Set music id.
void SimpleMusicType::SetId(string inId) {
	id = inId;
}

// Set music title.
void SimpleMusicType::SetTitle(string inTitle) {
	title = inTitle;
}

// Set music record.
void SimpleMusicType::SetRecord(string inId, string inTitle) {
	SetId(inId);
	SetTitle(inTitle);
}

// Set music title from keyboard.
void SimpleMusicType::SetTitleFromKB() {
	cout << "\t Title: ";
	getline(cin >> ws, title);
}


// operator== overloading
bool SimpleMusicType::operator==(SimpleMusicType &item) {
	if (this->id == item.id)
		return true;
	else
		return false;
}

// operator!= overloading
bool SimpleMusicType::operator!=(SimpleMusicType &item) {
	if (this->id != item.id)
		return true;
	else
		return false;
}

// operator> overloading
bool SimpleMusicType::operator>(SimpleMusicType &item) {
	if (this->id > item.id)
		return true;
	else
		return false;
}

// operator< overloading
bool SimpleMusicType::operator<(SimpleMusicType &item) {
	if (this->id < item.id)
		return true;
	else
		return false;
}

// operator>= overloading
bool SimpleMusicType::operator>=(SimpleMusicType &item) {
	if (this->id >= item.id)
		return true;
	else
		return false;
}

// operator<= overloading
bool SimpleMusicType::operator<=(SimpleMusicType &item) {
	if (this->id <= item.id)
		return true;
	else
		return false;
}