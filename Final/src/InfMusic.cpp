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


//  item�� information list���� ����.
void InfMusic::DeleteItem(SimpleMusicType item) {
	m_List.Delete(item);
}

//  item�� information list���� ����.
void InfMusic::RelaceItem(SimpleMusicType item) {
	m_List.Replace(item);
}

// item�� ���� ������ �̷��� ������ �׸��� �����ϴ��� �Ǻ�.
bool InfMusic::SearchItem(SimpleMusicType item) {
	bool found = false;
	m_List.Isthere(item, found);
	return found;
}

// inTitle�� �����ڵ带 �м��� �ش� �׸��� �� index ��ȯ.
int InfMusic::GetMusicIdx(string& inTitle) {
	int idx;
	CStringW cs(inTitle.c_str());
	idx = cs[0];

	if (idx <= 55203 && idx >= 44032) { //�ѱ�
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
	else if (idx <= 90 && idx >= 65) { //����-�빮��
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
	else if (idx <= 122 && idx >= 97) { //���� �ҹ���
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
	else {	//���� �� ��Ÿ
		return 10;
	}
}

//m_List�� ������ ��ȯ.
BinarySearchTree<SimpleMusicType>* InfMusic::GetPointInf() {
	return &m_List;
}

//m_List�� �ּҰ� ��ȯ.
BinarySearchTree<SimpleMusicType>& InfMusic::GetAddrInf() {
	return m_List;
}

//m_List �ʱ�ȭ �� name �缳��.
void InfMusic::MakeEmptyList(int& command) {
	m_List.MakeEmpty();	//m_list �ʱ�ȭ
	string num = to_string(command);
	name = "�� ������ " + num;	//name �缳��
}

//DisplaySimpleList�� ȣ���ϱ� ����, �ʿ��� �Ű������� ������ �ش� �Լ��� �����Ͽ� �����Ŵ.
void InfMusic::DisplaySimpleListFirst(const int& command) {
	int count = 1;
	Iterator<SimpleMusicType> iter(m_List);	//iterator ����
	DisplaySimpleList(iter, count, command);//�Լ�ȣ��
}

//ȭ�鿡 ����Ʈ �� ��� ������ ������ ������� ���. PreOrder����� ����� ����.
void InfMusic::DisplaySimpleList(Iterator<SimpleMusicType> iter, int& count, const int& command) {
	if (iter.IsNotNull()) {
		if (command == 0) {	//count �� ȭ�鿡 ���� ���
			cout << "\n\t\t  | " << count << " |\n\n";
		}
		SimpleMusicType item;
		item = iter.GetCurrentdata();
		item.DisplayRecord();	//simple data ȭ�鿡 ���
		count++;	//count�� ����

		//iter->MoveLeft();
		DisplaySimpleList(iter.MoveLeft(), count, command);	// �������� �̵�.

		//iter->MoveRight();
		DisplaySimpleList(iter.MoveRight(), count, command); //���������� �̵�.
	}
}

//����ڷκ��� ������ ����� ������ �Է¹��� ��, m_List ��Ͽ��� �ش� ��Ҹ� ã�� ����.
void InfMusic::SelectMusicDelete() {
	if (!m_List.IsEmpty()) {	//�� ����Ʈ�� �ƴ� ���
		SimpleMusicType userDel;
		string temp;
		while (1) {
			cout << "\n\t\t  |���� ID �Է� (����: \'q\')|: ";
			getline(cin >> ws, temp);
			userDel.SetNum(temp);		//������ ������ id �Է¹���

			if (userDel.GetNum().compare("q") == 0) {	//"q" �� �Է¹��� ��� 0�����ϸ� ����.
				cout << "\n\t    |������� �Է����� ����|" << endl;
				break;
			}
			else {
				bool duple;
				m_List.Retrieve(userDel, duple);	//m_List �� �ش� ���̵� ���� ������ �����ϴ��� Ȯ��


				if (!duple) {
					cout << "\n\t    |\'" << userDel.GetNum() << "\' �� ���� ������ ������ �� �����ϴ�|" << endl << endl;
					return;
				}
				else {
					m_List.Delete(userDel);	//����
					cout << "\n\t\t  |\'" << userDel.GetNum() << "\' �����Ϸ�|" << endl << endl;
				}
			}
		}
	}
	else {
		cout << "\n\t\n    |�� ����Ʈ �Դϴ�| ";
		return;
	}

}

//ȭ�鿡 ����Ʈ �� ��� ������ musiclist���� ã�� �ڼ��� ���, PreOrder����� ����� ����.
void InfMusic::DisplayInfList(SortedList<BinarySearchTree<MusicType>> &musiclist, Iterator<SimpleMusicType> iter) {
	if (iter.IsNotNull()) {	//iterator�� NULL�� �ƴ� ���
		SimpleMusicType item;
		MusicType d_item;
		bool found;

		item = iter.GetCurrentdata();	//���� iterator�� ����Ű�� ����� data ������.
		string m_id = item.GetNum();
		d_item.SetNum(m_id);		//primary key������ ���� MusicType ����.

		int m_idx = GetMusicIdx(m_id);	//�ε����� musiclist ����

		BinarySearchTree<MusicType> *m_ptr;
		m_ptr = musiclist.GetPoint(m_idx);	// �ش� ������ �����ϴ� �ε��� �� BST �����͸� �޾ƿ�.

		m_ptr->Retrieve(d_item, found);	//musiclist���� �ش� MusicType�� �ڼ��� ���� �޾ƿ�
		if (found) {//ã�� ���
			d_item.DisplayRecord();	// �ڼ��� ���� ���.
		}

		//iter->MoveLeft();
		DisplayInfList(musiclist, iter.MoveLeft());	// �������� �̵�.

		//iter->MoveRight();
		DisplayInfList(musiclist, iter.MoveRight()); //���������� �̵�.
	}
}

//ȭ�鿡 ����Ʈ �� ��� ������ musiclist���� ã�� �ڼ��� ����ϰų�, ����Ʈ �� ���� ���� �˻��� ���� �ش� ���� ���� �ڼ��� ���.
bool InfMusic::SearchDisplay(int button, SortedList<BinarySearchTree<MusicType>> &musiclist, string& f_title) {
	if (!m_List.IsEmpty()) {
		int count = 0;
		Iterator<SimpleMusicType> iter(m_List);	//iterator ����
		bool result = false;
		if (button == 1) {	//1�� ��� ����Ʈ �� ��� ���� �ڼ��� ���
			DisplayInfList(musiclist, iter);
			count++;
		}
		else {	//1�� �ƴ� ��� ����Ʈ �� Ư�� �ܾ ���Ե� ������ ���� ������ ���� �ڼ��� ���.
			cout << "\t    |�˻� �ܾ�|: ";
			getline(cin >> ws, f_title);	//Ư�� �ܾ� �Է� ����.

			for (int i = 0;i < musiclist.GetLength();i++) {
				if (musiclist.GetPoint(i)->GetLength() != 0) {	//musiclist�� i��° ����Ʈ�� ������� �ʴٸ�
					SearchTree(musiclist.GetAddr(i), iter, f_title, result);	//�Լ� ȣ��
					if (result)	//ã�� ���
						count++;
				}
			}
		}
		if (count == 0)	//ã�� ���� ��� false ����
			return false;
		else //ã�� ��� true ����
			return true;
	}
	else {
		cout << "\n\t\t  |�� ����Ʈ �Դϴ�| ";
		return false;
	}
}

//ȭ�鿡 ����Ʈ �� ���� ���� �˻��� ���� �ش� ���� ���� ������ ��°� temp_list�� �ش� ���� ����
bool InfMusic::SearchAddDisplay(string& f_title, BinarySearchTree<SimpleMusicType>& temp_list) {
	if (!m_List.IsEmpty()) {	//����Ʈ�� ������� ���� ��

		Iterator<SimpleMusicType> iter(m_List); //iterator ����

		cout << "\t    |�˻� �ܾ�|: ";
		getline(cin >> ws, f_title);	//Ư�� �ܾ� �Է� ����.
		

		SearchAddTree(iter, f_title, temp_list);	//�Լ� ȣ���Ͽ� ���� ���� ��� �� temp_list�� �ش� ���� ����Ǿ� ���޹���

		if (temp_list.GetLength()==0)	//���̰� 0�̶�� ã�� ���� ����̹Ƿ� false ����.
			return false;
		else
			return true;
	}
	else {
		cout << "\n\t\t  |�� ����Ʈ �Դϴ�| ";
		return false;
	}
}

//��������� ����Ǹ� ȭ�鿡 iter�� ����Ű�� ����Ʈ���� Ư���ܾ �����ϴ� ��Ҹ� �����ϰ� ����ϰ�, temp_list�� �ش� ��Ҹ� �����Ŵ.
void InfMusic::SearchAddTree(Iterator<SimpleMusicType> iter, const string& temp,
	BinarySearchTree<SimpleMusicType>& temp_list) {
	if (iter.IsNotNull()) {
		SimpleMusicType item;
		item = iter.GetCurrentdata();
		if (item.GetTitle().find(temp) != -1) {	//������ Ư�� �ܾ �����ϴ� ��� 
			temp_list.Add(item);	//temp_list�� �߰�
			item.DisplayRecord();	//ȭ�鿡 ���.
		}

		//iter->MoveLeft();
		SearchAddTree(iter.MoveLeft(), temp, temp_list);

		//iter->MoveRight();
		SearchAddTree(iter.MoveRight(), temp, temp_list);
	}
}

//PreOrder�� ������� m_List���� temp�� ������ ������ ������ ã��, ã�´ٸ� musiclist���� �˻��� �ش� ���Ǹ� �ڼ��� ���� ���.
void InfMusic::SearchTree(const BinarySearchTree<MusicType> &musiclist, Iterator<SimpleMusicType> iter, const string& temp, bool& found) {
	if (iter.IsNotNull()) {
		SimpleMusicType item;
		MusicType d_item;
		item = iter.GetCurrentdata();
		if (item.GetTitle().find(temp) != -1) {	//������ Ư�� �ܾ �����ϴ� ��� 
			d_item.SetNum(item.GetNum());
			musiclist.Retrieve(d_item, found);	//musiclist���� �ش� �ܾ��� �ڼ��� ���� �޾ƿ�.
			if (found) {
				d_item.DisplayRecord();	//ȭ�鿡 ���.
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
