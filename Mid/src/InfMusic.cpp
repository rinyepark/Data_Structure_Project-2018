#include "InfMusic.h"

// default constructor.
InfMusic::InfMusic() {
	name = "";
}

// copy constructor.
InfMusic::InfMusic(const InfMusic& anotherInf) {

	this->name = anotherInf.name;
	this->m_Inf = anotherInf.m_Inf;
}

// destructor.
InfMusic::~InfMusic() {}

// Get information list length.
int InfMusic::GetListLength() {
	return m_Inf.GetLength();
}

// Get information name.
string InfMusic::GetName() {
	return name;
}

// Set information name.
void InfMusic::SetName(string inName) {
	name = inName;
}

// add a new data into list.
void InfMusic::AddItem(SimpleMusicType item) {
	m_Inf.Add(item);
}


//  item�� information list���� ����.
void InfMusic::DeleteItem(SimpleMusicType item) {
	m_Inf.Delete(item);
}

//  item�� information list���� ����.
void InfMusic::RelaceItem(SimpleMusicType item) {
	m_Inf.Replace(item);
}

 // id�� �������� �׸��� �����ϴ��� �Ǻ�.
bool InfMusic::SearchItem(string inId) {
	bool found = false;
	m_Inf.ResetList();
	SimpleMusicType temp;
	MusicType m_temp;
	for (int i = 0;i < m_Inf.GetLength();i++) {
		m_Inf.GetNextItem(temp);
		if (temp.GetId().find(inId) != -1) { //��ġ�ϴ� ������ ã�� ���
			found = true;
			break;
		}
	}
	return found;
}

//�� ���� �̿��� �ش� information type���� ��ġ�ϴ� ���� ã�� ���.
void InfMusic::DisplaySearchByTitle(string inTitle, SortedList<MusicType> *musiclist) {
	bool found = false;
	int count = 0;
	m_Inf.ResetList();
	SimpleMusicType temp;
	MusicType m_temp;
	for (int i = 0;i < m_Inf.GetLength();i++) {
		m_Inf.GetNextItem(temp);
		if (temp.GetTitle().find(inTitle) != -1) { //��ġ�ϴ� ������ ã�� ���
			m_temp.SetId(temp.GetId());
			musiclist->GetByBinarySearch(m_temp);
			if (!count) {
				cout << "\t ================= found ================" << endl;
			}
			m_temp.DisplayRecordOnScreen();
			found = true;
			count++;
		}

	}
	if (!found) // ã�� ���� ���
		cout << endl << "\t ���� ã�� �� �����ϴ�. " << endl;
	else {
		cout << endl << "\t ======================================" << endl;
	}
}

 //Display information list on screen.
void InfMusic::DisplayInfList(SortedList<MusicType> *musiclist) {
	if (this->GetListLength() != 0) {
		cout << "\t================= " << name << " =================\n";
		m_Inf.ResetList();
		SimpleMusicType temp;
		MusicType m_temp;
		for (int i = 0;i < m_Inf.GetLength();i++) {
			m_Inf.GetNextItem(temp);
			m_temp.SetId(temp.GetId());
			musiclist->GetByBinarySearch(m_temp);
			m_temp.DisplayRecordOnScreen();
		}
		cout << endl << "\t=============================\n" << endl;
	}
}


// operator== overloading
bool InfMusic::operator==(InfMusic &item) {
	if (this->name == item.name)
		return true;
	else
		return false;
}


// operator!= overloading
bool InfMusic::operator!=(InfMusic &item) {
	if (this->name != item.name)
		return true;
	else
		return false;
}


// operator> overloading
bool InfMusic::operator>(InfMusic &item) {
	if (this->name > item.name)
		return true;
	else
		return false;
}

// operator< overloading
bool InfMusic::operator<(InfMusic &item) {
	if (this->name < item.name)
		return true;
	else
		return false;
}

// operator>= overloading
bool InfMusic::operator>=(InfMusic &item) {
	if (this->name >= item.name)
		return true;
	else
		return false;
}

// operator<= overloading
bool InfMusic::operator<=(InfMusic &item) {
	if (this->name <= item.name)
		return true;
	else
		return false;
}
