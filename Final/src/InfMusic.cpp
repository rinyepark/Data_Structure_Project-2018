#include "InfMusic.h"

// default constructor.
InfMusic::InfMusic() {
	name = "";
}

//default constructor with parameter.
InfMusic::InfMusic(string inName) {
	name = inName;
}

// copy constructor.
InfMusic::InfMusic(const InfMusic& anotherInf) {
	this->name = anotherInf.name;
}

// destructor.
InfMusic::~InfMusic() {}

// Get information list length.
int InfMusic::GetListLength() {
	return m_List.GetLength();
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
int InfMusic::AddItem(SimpleMusicType item) {
	return m_List.Add(item);
}


//  item을 information list에서 제거.
void InfMusic::DeleteItem(SimpleMusicType item) {
	m_List.Delete(item);
}

//  item을 information list에서 변경.
void InfMusic::RelaceItem(SimpleMusicType item) {
	m_List.Replace(item);
}

// item이 가진 정보로 이뤄진 음악이 항목이 존재하는지 판별.
bool InfMusic::SearchItem(SimpleMusicType item) {
	bool found = false;
	m_List.Isthere(item, found);
	return found;
}

// inTitle의 유니코드를 분석해 해당 항목이 들어갈 index 반환.
int InfMusic::GetMusicIdx(string& inTitle) {
	int idx;
	CStringW cs(inTitle.c_str());
	idx = cs[0];

	if (idx <= 55203 && idx >= 44032) { //한글
		if (idx <= 45795) {
			return 0;
		}
		else if (idx <= 48147) {
			return 1;
		}
		else if (idx <= 51087) {
			return 2;
		}
		else if (idx <= 53439) {
			return 3;
		}
		else {
			return 4;
		}
	}
	else if (idx <= 90 && idx >= 65) { //영어-대문자
		if (idx <= 69) {
			return 5;
		}
		else if (idx <= 74) {
			return 6;
		}
		else if (idx <= 79) {
			return 7;
		}
		else if (idx <= 84) {
			return 8;
		}
		else {
			return 9;
		}
	}
	else if (idx <= 122 && idx >= 97) { //영어 소문자
		if (idx <= 101) {
			return 5;
		}
		else if (idx <= 106) {
			return 6;
		}
		else if (idx <= 111) {
			return 7;
		}
		else if (idx <= 116) {
			return 8;
		}
		else {
			return 9;
		}
	}
	else {	//숫자 등 기타
		return 10;
	}
}

//m_List의 포인터 반환.
BinarySearchTree<SimpleMusicType>* InfMusic::GetPointInf() {
	return &m_List;
}

//m_List의 주소값 반환.
BinarySearchTree<SimpleMusicType>& InfMusic::GetAddrInf() {
	return m_List;
}

//m_List 초기화 및 name 재설정.
void InfMusic::MakeEmptyList(int& command) {
	m_List.MakeEmpty();	//m_list 초기화
	string num = to_string(command);
	name = "빈 재생목록 " + num;	//name 재설정
}

//DisplaySimpleList를 호출하기 이전, 필요한 매개변수를 생성해 해당 함수에 전달하여 실행시킴.
void InfMusic::DisplaySimpleListFirst(const int& command) {
	int count = 1;
	Iterator<SimpleMusicType> iter(m_List);	//iterator 생성
	DisplaySimpleList(iter, count, command);//함수호출
}

//화면에 리스트 내 모든 정보를 간단한 방식으로 출력. PreOrder방식의 출력을 가짐.
void InfMusic::DisplaySimpleList(Iterator<SimpleMusicType> iter, int& count, const int& command) {
	if (iter.IsNotNull()) {
		if (command == 0) {	//count 값 화면에 같이 출력
			cout << "\n\t\t  | " << count << " |\n\n";
		}
		SimpleMusicType item;
		item = iter.GetCurrentdata();
		item.DisplayRecord();	//simple data 화면에 출력
		count++;	//count값 증가

		//iter->MoveLeft();
		DisplaySimpleList(iter.MoveLeft(), count, command);	// 왼편으로 이동.

		//iter->MoveRight();
		DisplaySimpleList(iter.MoveRight(), count, command); //오른편으로 이동.
	}
}

//사용자로부터 삭제할 요소의 정보를 입력받은 후, m_List 목록에서 해당 요소를 찾아 삭제.
void InfMusic::SelectMusicDelete() {
	if (!m_List.IsEmpty()) {	//빈 리스트가 아닌 경우
		SimpleMusicType userDel;
		string temp;
		while (1) {
			cout << "\n\t\t  |삭제 ID 입력 (종료: \'q\')|: ";
			getline(cin >> ws, temp);
			userDel.SetNum(temp);		//삭제할 음악의 id 입력받음

			if (userDel.GetNum().compare("q") == 0) {	//"q" 를 입력받은 경우 0리턴하며 종료.
				cout << "\n\t    |사용자의 입력으로 종료|" << endl;
				break;
			}
			else {
				bool duple;
				m_List.Retrieve(userDel, duple);	//m_List 내 해당 아이디 가진 음악이 존재하는지 확인


				if (!duple) {
					cout << "\n\t    |\'" << userDel.GetNum() << "\' 를 가진 음악은 재생목록 내 없습니다|" << endl << endl;
					return;
				}
				else {
					m_List.Delete(userDel);	//삭제
					cout << "\n\t\t  |\'" << userDel.GetNum() << "\' 삭제완료|" << endl << endl;
				}
			}
		}
	}
	else {
		cout << "\n\t\n    |빈 리스트 입니다| ";
		return;
	}

}

//화면에 리스트 내 모든 정보를 musiclist에서 찾아 자세히 출력, PreOrder방식의 출력을 가짐.
void InfMusic::DisplayInfList(SortedList<BinarySearchTree<MusicType>> &musiclist, Iterator<SimpleMusicType> iter) {
	if (iter.IsNotNull()) {	//iterator가 NULL이 아닌 경우
		SimpleMusicType item;
		MusicType d_item;
		bool found;

		item = iter.GetCurrentdata();	//현재 iterator가 가리키는 노드의 data 가져옴.
		string m_id = item.GetNum();
		d_item.SetNum(m_id);		//primary key값만을 갖는 MusicType 생성.

		int m_idx = GetMusicIdx(m_id);	//인덱스로 musiclist 접근

		BinarySearchTree<MusicType> *m_ptr;
		m_ptr = musiclist.GetPoint(m_idx);	// 해당 음악이 존재하는 인덱스 내 BST 포인터를 받아옴.

		m_ptr->Retrieve(d_item, found);	//musiclist에서 해당 MusicType의 자세한 정보 받아옴
		if (found) {//찾은 경우
			d_item.DisplayRecord();	// 자세한 정보 출력.
		}

		//iter->MoveLeft();
		DisplayInfList(musiclist, iter.MoveLeft());	// 왼편으로 이동.

		//iter->MoveRight();
		DisplayInfList(musiclist, iter.MoveRight()); //오른편으로 이동.
	}
}

//화면에 리스트 내 모든 정보를 musiclist에서 찾아 자세히 출력하거나, 리스트 내 음악 제목 검색을 통해 해당 음악 정보 자세히 출력.
bool InfMusic::SearchDisplay(int button, SortedList<BinarySearchTree<MusicType>> &musiclist, string& f_title) {
	if (!m_List.IsEmpty()) {
		int count = 0;
		Iterator<SimpleMusicType> iter(m_List);	//iterator 생성
		bool result = false;
		if (button == 1) {	//1인 경우 리스트 내 모든 정보 자세히 출력
			DisplayInfList(musiclist, iter);
			count++;
		}
		else {	//1이 아닌 경우 리스트 내 특정 단어가 포함된 제목을 가진 음악의 정보 자세히 출력.
			cout << "\t    |검색 단어|: ";
			getline(cin >> ws, f_title);	//특정 단어 입력 받음.

			for (int i = 0;i < musiclist.GetLength();i++) {
				if (musiclist.GetPoint(i)->GetLength() != 0) {	//musiclist의 i번째 리스트가 비어있지 않다면
					SearchTree(musiclist.GetAddr(i), iter, f_title, result);	//함수 호출
					if (result)	//찾은 경우
						count++;
				}
			}
		}
		if (count == 0)	//찾지 못한 경우 false 리턴
			return false;
		else //찾은 경우 true 리턴
			return true;
	}
	else {
		cout << "\n\t\t  |빈 리스트 입니다| ";
		return false;
	}
}

//화면에 리스트 내 음악 제목 검색을 통해 해당 음악 정보 간단히 출력과 temp_list내 해당 음악 저장
bool InfMusic::SearchAddDisplay(string& f_title, BinarySearchTree<SimpleMusicType>& temp_list) {
	if (!m_List.IsEmpty()) {	//리스트가 비어있지 않을 때

		Iterator<SimpleMusicType> iter(m_List); //iterator 생성

		cout << "\t    |검색 단어|: ";
		getline(cin >> ws, f_title);	//특정 단어 입력 받음.
		

		SearchAddTree(iter, f_title, temp_list);	//함수 호출하여 정보 간단 출력 및 temp_list내 해당 음악 저장되어 전달받음

		if (temp_list.GetLength()==0)	//길이가 0이라면 찾지 못한 경우이므로 false 리턴.
			return false;
		else
			return true;
	}
	else {
		cout << "\n\t\t  |빈 리스트 입니다| ";
		return false;
	}
}

//재귀적으로 실행되며 화면에 iter가 가리키는 리스트에서 특정단어를 포함하는 요소를 간단하게 출력하고, temp_list에 해당 요소를 저장시킴.
void InfMusic::SearchAddTree(Iterator<SimpleMusicType> iter, const string& temp,
	BinarySearchTree<SimpleMusicType>& temp_list) {
	if (iter.IsNotNull()) {
		SimpleMusicType item;
		item = iter.GetCurrentdata();
		if (item.GetTitle().find(temp) != -1) {	//제목이 특정 단어를 포함하는 경우 
			temp_list.Add(item);	//temp_list에 추가
			item.DisplayRecord();	//화면에 출력.
		}

		//iter->MoveLeft();
		SearchAddTree(iter.MoveLeft(), temp, temp_list);

		//iter->MoveRight();
		SearchAddTree(iter.MoveRight(), temp, temp_list);
	}
}

//PreOrder의 방식으로 m_List에서 temp를 포함한 제목의 정보를 찾고, 찾는다면 musiclist에서 검색해 해당 음악만 자세한 정보 출력.
void InfMusic::SearchTree(const BinarySearchTree<MusicType> &musiclist, Iterator<SimpleMusicType> iter, const string& temp, bool& found) {
	if (iter.IsNotNull()) {
		SimpleMusicType item;
		MusicType d_item;
		item = iter.GetCurrentdata();
		if (item.GetTitle().find(temp) != -1) {	//제목이 특정 단어를 포함하는 경우 
			d_item.SetNum(item.GetNum());
			musiclist.Retrieve(d_item, found);	//musiclist에서 해당 단어의 자세한 정보 받아옴.
			if (found) {
				d_item.DisplayRecord();	//화면에 출력.
			}
		}

		//iter->MoveLeft();
		SearchTree(musiclist, iter.MoveLeft(), temp, found);

		//iter->MoveRight();
		SearchTree(musiclist, iter.MoveRight(), temp, found);
	}
}

// operator== overloading
bool InfMusic::operator==(InfMusic &item) {
	if (this->name.compare(item.name) == 0)
		return true;
	else
		return false;
}


// operator!= overloading
bool InfMusic::operator!=(InfMusic &item) {
	if (this->name.compare(item.name) != 0)
		return true;
	else
		return false;
}


// operator> overloading
bool InfMusic::operator>(InfMusic &item) {
	if (this->name.compare(item.name) > 0)
		return true;
	else
		return false;
}

// operator< overloading
bool InfMusic::operator<(InfMusic &item) {
	if (this->name.compare(item.name) < 0)
		return true;
	else
		return false;
}
