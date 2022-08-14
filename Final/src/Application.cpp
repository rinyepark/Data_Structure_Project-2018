#include "Application.h"


//default constructor
Application::Application(){
	count = 0;	//count�� �ʱ�ȭ
	b = false;

	//SortedList ���� �ʿ� ũ�⿡ �°� �����Ҵ�
	GenreList.Constructor(12);
	MusicList.Constructor(11);
	PlayList.Constructor(5);

	m_Command = 0;
	
	//GenreList �⺻ ���� �� �ʱ�ȭ
	InfMusic genre;
	genre.SetName("�߶��");
	GenreList.Add(genre);
	genre.SetName("��");
	GenreList.Add(genre);
	genre.SetName("OST");
	GenreList.Add(genre);
	genre.SetName("��/����");
	GenreList.Add(genre);
	genre.SetName("R&B/SOUL");
	GenreList.Add(genre);

	genre.SetName("POP");
	GenreList.Add(genre);
	genre.SetName("��/��Ż");
	GenreList.Add(genre);
	genre.SetName("��ũ/��罺");
	GenreList.Add(genre);
	genre.SetName("�Ϸ�Ʈ�δ�ī");
	GenreList.Add(genre);
	genre.SetName("Ŭ����");
	GenreList.Add(genre);

	genre.SetName("Ʈ��Ʈ");
	GenreList.Add(genre);
	genre.SetName("��Ÿ");
	GenreList.Add(genre);

	//MusicList �⺻ ����
	BinarySearchTree<MusicType> title;
	MusicList.Add(title); // ��,��
	MusicList.Add(title); // ��,��,��
	MusicList.Add(title); // ��,��,��
	MusicList.Add(title); // ��,��,��
	MusicList.Add(title); // ��,��,��

	MusicList.Add(title); // a, b, c, d, e
	MusicList.Add(title); // f, g, h, i, j
	MusicList.Add(title); // k, l, m, n, o
	MusicList.Add(title); // p, q, r,s, t
	MusicList.Add(title); //u, v, w, x, y, z

	MusicList.Add(title); // ����(0~9) �� ��Ÿ

	//PlayList �⺻ ���� �� �ʱ�ȭ
	InfMusic p_list;
	p_list.SetName("�� ������ 1");
	PlayList.Add(p_list);
	p_list.SetName("�� ������ 2");
	PlayList.Add(p_list);
	p_list.SetName("�� ������ 3");
	PlayList.Add(p_list);
	p_list.SetName("�� ������ 4");
	PlayList.Add(p_list);
	p_list.SetName("�� ������ 5");
	PlayList.Add(p_list);
}

//destructor
Application::~Application(){}


// Program driver.
void Application::Run()
{
	while (1)
	{
		m_Command = MainGetCommand();
		switch (m_Command)
		{
		case 1:		// ����Ʈ �� ���� �˻�.
			SearchMusic();
			break;
		case 2:		// ����Ʈ �� ���� ����.
			ManageMusic();
			break;
		case 3:		// ����� ������, �⺻ ������ ����
			ManagePlayList();
			break;
		case 4:		// ���� ��� ����.
			ManagePlayingMusic(1);
			break;
		case 5:		// ���� ���� ��� ���� �м�.
			MyMusic();
			break;
		case 6:		// ���� ������ ����.
			ManageNowPlayList();
			break;
		case 0:
			cout << "\n\n\t    ***** ���α׷� ���� *****" << endl;
			return;
		}
	}
}

//genre�� �ش� genre index�� ã�� ����.
int Application::SetGenreId(const string& genre) {
	if (genre == "�߶��" || genre == "Ballad")
		return 0;
	else if (genre == "��" || genre == "Dance")
		return 1;
	else if (genre == "OST")
		return 2;
	else if (genre == "��/����" || genre == "Rap/Hip-hop")
		return 3;
	else if (genre == "R&B/SOUL")
		return 4;
	else if (genre == "POP" || genre == "��")
		return 5;
	else if (genre == "��/��Ż" || genre == "Rock")
		return 6;
	else if (genre == "��ũ/��罺" || genre == "Folk")
		return 7;
	else if (genre == "�Ϸ�Ʈ�δ�ī" || genre == "Electronica")
		return 8;
	else if (genre == "Ŭ����" || genre == "Classic")
		return 9;
	else if (genre == "Ʈ��Ʈ" || genre == "Adult Contemporary")
		return 10;
	else
		return 11;
}

//�ѱ�, ����, ���� �� ��Ÿ�� ���е� 0~12�� �ε����� inTitle�� ù��° ���� �����ڵ带 �̿��� ���� �ش��ϴ� �ε��� �� ��ȯ.
int Application::GetMusicListIdx(string& inTitle) {
	int idx;
	CStringW cs(inTitle.c_str());	//C_string���� ��ȯ
	idx = cs[0];

	//�����ڵ� �̿�
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

//title�� artist�� �̿��� music id�ڵ� ����
void Application::SetMusicId(MusicType& item) {
	item.SetNum(item.GetTitle() + "_" + item.GetArtist());
}

//inCommand�� int����, int�̸� �ش� ��ɹ�ȣ�� �����ϴ��� �Ǻ��Ͽ� ����ڷκ��� �ùٸ� ���� �Է¹���.
void Application::CheckNum(int& inCommand, const int&a, const int&b) {
	while (1) {
		cout << endl << "\t\t  |�Է�| : ";
		cin >> inCommand;
		cout << endl;

		if (!cin.fail()) { //������ �Է��� ���
			if (inCommand < a || inCommand > b) {	// �������� �ʴ� ��ɾ� ��ȣ�� �Է��� ���
				cout << "\t    �������� �ʴ� ��ȣ�Դϴ�." << endl;
				cin.clear();
				cin.ignore(256, '\n');
				continue;
			}
			else {	//����� �Է½� �ݺ��� ����.
				break;
			}
		}
		else {	// ������ �ƴ� �߸��� �Է��� �� ���.
			cout << "\t    �߸��� �Է��Դϴ�." << endl;
			cin.clear();
			cin.ignore(256, '\n');
			continue;
		}
	}
}

// Display command on screen and get a input from keyboard.
int Application::MainGetCommand()
{
	int command;

	cout << endl << endl << endl;


	cout << "\t**********************************" << endl;
	cout << "\t******* ���� ���� ���α׷� *******" << endl;
	cout << "\t**********************************\n\n";

	cout << "\t----------------------------------" << endl;

	cout << "\t\t   (1)���ǰ˻�" << endl;

	cout << "\t----------------------------------\n";
	cout << "\t    (2)���ǰ���    (3)������" << endl;
	cout << "\t----------------------------------\n";
	cout << "\t    (4)�������    (5)���̹���" << endl;
	cout << "\t----------------------------------" << endl;
	cout << "\t--------���� ������� ����--------" << endl << endl;

	PlayingMusic(IsPlaying);	//���� ������� ���ǿ� ���� ���� ���� ǥ��

	cout << "\t----------------------------------" << endl;
	cout << "\t (6) ���� ������         (0)����" << endl;
	cout << "\t----------------------------------" << endl;


	//�߸��� ��ɾ� �Է½� ����ó��
	CheckNum(command, 0, 6);
	return command;
}

//���� �˻��� ���� ���� ���ȭ��
int Application::SearchGetCommand() {
	int command;

	cout << endl << endl;

	cout << "\t\t      *****" << endl << endl;
	cout << "\t\t  =============" << endl;
	cout << "\t\t  | ���� �˻� |" << endl;
	cout << "\t\t  =============" << endl << endl;


	cout << "\t\t  | (1) ��ü\n\n";
	cout << "\t\t  | (2) �帣\n\n";
	cout << "\t\t  | (3) ��Ƽ��Ʈ\n\n";
	cout << "\t\t  | (4) �ٹ�\n\n\n";
	cout << "\t      --- Quit: Enter \'0\' ---\n\n";


	//�߸��� ��ɾ� �Է½� ����ó��
	CheckNum(command, 0, 4);
	return command;
}

//�ش� content �������� ���� ����Ʈ ���� Ȥ�� ���� ��� ��ɾ� ����.
int Application::DetailManageSerachGetCommand(const string&content) {
	int command;
	cout << "\n\t\t      *****" << endl << endl;
	cout << "\t\t  | \"" << content << "\" �˻� |\n" << endl;
	cout << "\t\t  ----------------------------\n\n";

	cout << "\t\t  | (1) ��� �������� �� ���\n\n";
	cout << "\t\t  | (2) \"" << content << "\" ���� ������ �߰�\n\n";
	cout << "\t\t  | (3) \"" << content << "\" ���� ������ �߰�\n\n";
	cout << "\t\t  | (4) \"" << content << "\" ���� �˻�\n\n\n";
	cout << "\t      --- Quit: Enter \'0\' ---\n\n";

	CheckNum(command, 0, 4);
	return command;
}

//���� ī�װ��� ���� �˻��� ���� ��ɾ ����.
int Application::DetailSerachGetCommand(const string&content) {
	int command;
	cout << "\n\t\t      *****" << endl << endl;
	cout << "\t\t  | "<< content <<" �˻� |" << endl;

	cout << "\t\t  ----------------------------\n\n";
	cout << "\t\t  | (1) "<< content <<" ��� ���� ���\n\n";
	cout << "\t\t  | (2) "<< content << " �� ���� �˻�\n\n\n";
	cout << "\t      --- Quit: Enter \'0\' ---\n\n";
	
	CheckNum(command, 0, 2);
	return command;
}

//��ü, �帣, ��Ƽ��Ʈ, �ٹ� �� ī�װ��� ������ ������ �˻�.
void Application::SearchMusic() {
	int command;
	while (1)
	{
		if (count == 0) {	//�߰��� ������ ���� ���
			cout << endl << "\t   |������ ���������ʾ� �ڵ����� �����մϴ�|" << endl;
			return;
		}
		int s_idx = SearchGetCommand();	//�Լ��� ���� ��ɰ� �޾ƿ�
		if (s_idx == 1) {
			// ��ü ����Ʈ �˻�
			cout << "\n\t\t      *****" << endl << endl;
			cout << "\t\t  =============" << endl;
			cout << "\t\t  | ��ü �˻� |" << endl;
			cout << "\t\t  =============" << endl << endl;
			cout << "\t\t  | (1) ��� ���� ���\n\n";
			cout << "\t\t  | (2) ��ü �� ���� �˻�\n\n\n";
			cout << "\t      --- Quit: Enter \'0\' ---\n\n";

			CheckNum(command, 0, 2);

			if (command == 1) {	//MusicList�� �̿��� ��� ���� ���
				DisplayAllMusic();
			}
			else if (command == 2) {
				//��ü����Ʈ���� ����,���� ��ġ�ϴ� �뷡 ã�� �� �ֵ���
				cout << "\n\t   |�˻��Ϸ��� ����� ���� �Է�|" << endl<<endl;

				MusicType sear_mt;
				sear_mt.SetNumFK();	//����ڷκ��� �Է¹���
				sear_mt.SetLyricsFK();

				SearchByName(sear_mt);	//�Լ�ȣ��
			}
			else {
				cout << "\n\t    |��ü���� �˻��� �����մϴ�|" << endl;
				return;
			}
		}
		else if (s_idx == 2) {	// �帣 ����Ʈ �˻�
			command = DetailSerachGetCommand("�帣");
			if (command == 1) {	//�帣���� ���� ��ü ���
				InfMusic *p_gen;
				for (int i = 0;i < GenreList.GetLength();i++) {	//��� �帣�� ����
					p_gen = GenreList.GetPoint(i);
					string temp = "";
					if (p_gen->GetListLength() != 0) { //�ش� �帣 �� ������ ���� ��� ������� �ʵ��� ��.
						cout << "\n\t\t  ===|" << p_gen->GetName() << "|===" << endl;

						p_gen->SearchDisplay(1, MusicList, temp);	//���� ���� �ڼ��� ���
						cout << endl;
					}
				}
			}
			else if (command == 2) {
				SearchByGenre();	//�帣 ��� �� ���� �˻�
			}
			else {
				cout << "\n\t\t    |�帣�� �˻��� �����մϴ�|" << endl;
				return;
			}
		}
		else if (s_idx == 3) {// ��Ƽ��Ʈ ����Ʈ �˻�
			Iterator<InfMusic> iter(ArtistList);

			//��Ƽ��Ʈ ��� ���� ���
			DisplayAllnestedBST(ArtistList, iter,2);

			command = DetailSerachGetCommand("��Ƽ��Ʈ");
			if (command == 1) {	//��Ƽ��Ʈ���� ���� ��ü ���
				Iterator<InfMusic> iter(ArtistList);
				DisplayAllnestedBST(ArtistList, iter, 1);
			}
			else if (command == 2) {//��Ƽ��Ʈ ��� �� ���� �˻�
				SearchByArtist();
			}
			else {
				cout << "\n\t    |��Ƽ��Ʈ�� �˻��� �����մϴ�|" << endl;
				return;
			}

		}
		else if (s_idx == 4) {	// �ٹ� ����Ʈ �˻�
			Iterator<InfMusic> iter(AlbumList);

			//�ٹ� ��� ���� ���
			DisplayAllnestedBST(AlbumList, iter, 2);

			command = DetailSerachGetCommand("�ٹ�");
			if (command == 1) {	//�ٹ� �� ���� ��ü ���
				Iterator<InfMusic> iter(AlbumList);
				DisplayAllnestedBST(AlbumList, iter, 1);
			}
			else if (command == 2) {//�ٹ� ��� �� ���� �˻�
				SearchByAlbum();
			}
			else {
				cout << "\n\t    |�ٹ��� �˻��� �����մϴ�|" << endl;
				return;
			}

		}
		else {
			cout << "\n\t    |���� �˻��� �����մϴ�|" << endl;
			return;
		}
	}
}

//m_list�� ���� command�� ���� ��������� �ش� ����Ʈ�� ���� ������ ���.(�������� ����)
void Application::DisplayAllnestedOrderBST(BinarySearchTree<InfMusic>& m_list, Iterator<InfMusic> b_iter, const int& command) {
	if (b_iter.IsNotNull()) {	//iter�� NULL�� �ƴ϶��
		DisplayAllnestedOrderBST(m_list, b_iter.MoveRight(), command); //������ �̵�
		InfMusic *ptr;
		string name;
		name = b_iter.GetCurrentdata().GetName();	//name���� �޾ƿ�
		InfMusic temp(name);
		ptr = m_list.GetPoint(temp);	//�ش� name���� InfMusic �����ͷ� �޾ƿ�
		if (ptr->GetListLength() != 0) {	//InfMusic�� ����Ʈ�� ������ �ִ°��
			cout << "\n\t\t  ===|" << name << "|===" << endl;
			if (command == 1) {	//��� ���� ���� ���
				ptr->SearchDisplay(1, MusicList, name);
			}
			else {//��� ���� simple�ϰ� ���
				ptr->DisplaySimpleListFirst(command);
			}
		}
		DisplayAllnestedOrderBST(m_list, b_iter.MoveLeft(), command);	//���� �̵�
	}
}

//m_list�� ���� command�� ���� ��������� �ش� ����Ʈ�� ���� ������ ���.(Inorder����)
void Application::DisplayAllnestedBST(BinarySearchTree<InfMusic>& m_list, Iterator<InfMusic> b_iter, const int& command) {
	if (b_iter.IsNotNull()) { //b_iter�� Null�� �ƴ� ��
		DisplayAllnestedBST(m_list, b_iter.MoveLeft(),command);	//���� �̵�
		InfMusic *ptr;
		string name;
		name = b_iter.GetCurrentdata().GetName();	//name���� �޾ƿ�
		InfMusic temp(name);
		ptr = m_list.GetPoint(temp);	//�ش� name���� InfMusic �����ͷ� �޾ƿ�
		if (ptr->GetListLength() != 0) {
			cout << "\n\t\t  |" << name << "|" << endl;
			if (command == 1) { //�ڼ��� ���� ���
				ptr->SearchDisplay(1, MusicList, name);
			}
			else { //������ ���� ���
				ptr->DisplaySimpleListFirst(command);
			}
		}
		DisplayAllnestedBST(m_list, b_iter.MoveRight(),command);//������ �̵�
	}
}

//���� ���� ���� ��ɾ� ���
int Application::ManageGetCommand() {
	int command;

	cout << endl << endl;

	cout << "\t\t      *****" << endl << endl;
	cout << "\t\t  =============" << endl;
	cout << "\t\t  | ���� ���� |" << endl;
	cout << "\t\t  =============" << endl << endl;


	cout << "\t\t  | (1) �����߰�\n\n";
	cout << "\t\t  | (2) �ڵ��߰�\n\n";
	cout << "\t\t  | (3) ����\n\n";
	cout << "\t\t  | (4) ����\n\n";
	cout << "\t\t  | (5) ���� ��������\n\n";
	cout << "\t\t  | (6) ���� ����\n\n";
	cout << "\t      --- Quit: Enter \'0\' ---\n\n";


	//�߸��� ��ɾ� �Է½� ����ó��
	CheckNum(command, 0, 6);
	return command;
}

//������ �����ϴ� �Լ�
void Application::ManageMusic() {
	while (1)
	{
		switch (ManageGetCommand())
		{
		case 1:		//����ڷκ��� ���� �Է¹޾� �߰�
			AddMusicFromUser();
			break;
		case 2:		//�ڵ����� ����Ǿ��ִ� ��� ������ �߰�
			AutoReadFile();
			break;
		case 3:		//���� ����
			DeleteMusicFromUser();
			break;
		case 4:		//Ư�� ���� ���� ����
			ReplaceMusic();
			break;
		case 5:		//���Ϸκ��� �о�ͼ� �߰�
			ReadFile();
			break;
		case 6:		//��� ���� ���Ϸ� ����
			WriteDataToFile();
			break;
		case 0:
			cout << "\n\t    |���� ������ �����մϴ�|" << endl;
			return;
		}
	}
}

//���� ��� ��� ��ɾ� ��� �Լ�.
int Application::PlaylistGetCommnad() {
	int command;

	cout << endl << endl;

	cout << "\t\t      *****" << endl << endl;
	cout << "\t\t  =============" << endl;
	cout << "\t\t  | ��� ��� |" << endl;
	cout << "\t\t  =============" << endl << endl;


	cout << "\t\t  | (1) ���� ������\n\n"; 	// �̰� �������ڸ��� ������ �̸� ��� ���(����� ����)
	cout << "\t\t  | (2) �ֱ��߰� ���\n\n";
	cout << "\t\t  | (3) �ֱ���� ���\n\n";
	cout << "\t\t  | (4) �ִ���� ���\n\n";
	cout << "\t\t  | (5) ���ƿ� �� ���Ǹ��\n\n";
	cout << "\t      --- Quit: Enter \'0\' ---\n\n";


	//�߸��� ��ɾ� �Է½� ����ó��
	CheckNum(command, 0, 5);
	return command;
}

//���� ����Ʈ ������ ���� ��ɾ� ���.
int Application::DetailPlayListGetCommand(const string&content) {
	int command;
	cout << "\n\t\t      *****" << endl << endl;
	cout << "\t\t  | " << content << " |" << endl;

	cout << "\t\t  ----------------------------\n\n";
	cout << "\t\t  | (1) ���� ������ �߰�\n\n";
	cout << "\t\t  | (2) ���� ������ �߰�\n\n";
	cout << "\t\t  | (3) �� ���� ���\n\n";
	cout << "\t\t  | (4) ��ü ����\n\n\n";
	cout << "\t      --- Quit: Enter \'0\' ---\n\n";

	CheckNum(command, 0, 4); //����ó��
	return command;
}

// ���� ������� 5���� �� �Ѱ��� �����Ͽ� ����
void Application::SelectMyPlayList(int& command) {
	InfMusic *i_ptr;
	i_ptr = PlayList.GetPoint(command - 1);	//Ư�� ������ ����
	if (i_ptr->GetListLength() == 0) {
		cout << "\n\t    |�� ������ �Դϴ�|" << endl;
	}
	else {
		int com;
		string name = i_ptr->GetName();	//������ �̸� �޾ƿ�
		cout << "\t\t      *****" << endl;
		cout << "\n\t   ===| " << name << " (" << i_ptr->GetListLength() << ") |===" << endl;

		cout << endl;
		i_ptr->DisplaySimpleListFirst(0);	//�����ϰ� ������

		cout << "\n\n\t      ----------------------------------" << endl;

		string t_name;

		while (1) {
			if (i_ptr->GetListLength() != 0) {	//�������� ������� ������

				cout << "\n\n\t\t  | (1) ���� ������ �߰�\n\n";
				cout << "\t\t  | (2) �� ���� ���\n\n\n";
				cout << "\t\t  | (3) ���� ���� ����\n\n";
				cout << "\t\t  | (4) ������ ����\n\n\n";
				cout << "\t\t  | (5) ������ �̸� ����\n\n\n";
				cout << "\t      --- Quit: Enter \'0\' ---\n\n";
				CheckNum(com, 0, 5); //����

				switch (com)
				{
				case 1://���� ������ �߰�
					AddNowPlayListManage(command); 
					break;
				case 2://�� ���� ���
					if (i_ptr->GetListLength() != 0) {
						i_ptr->SearchDisplay(1, MusicList, name);
					}
					else {
						cout << "\n\t    |�� ������ �Դϴ�|" << endl;
					}
					break;
				case 3://������ ���� ����
					if (i_ptr->GetListLength() != 0) {
						i_ptr->SelectMusicDelete();
					}
					else {
						cout << "\n\t    |�� ������ �Դϴ�|" << endl;
					}
					break;
				case 4: //������ ������ ���
					i_ptr->MakeEmptyList(command);
					cout << "\n\t    |�������� ������ϴ�|\n\n";
					break;
				case 5:	//������ �̸� ����
					cout << "\n\t  |�����̸� �Է�|: ";
					getline(cin >> ws, t_name);
					i_ptr->SetName(t_name);
					cout << "\n\t\t |\'" << t_name << "\'���� ����Ǿ����ϴ�|" << endl << endl;
					name = t_name;
					break;
				case 0:
					cout << "\n\t    |\'" << name << "\' ������ �����մϴ�|" << endl << endl;
					return;
				}
			}
			else {
				cout << endl << "\t   |�� �������̹Ƿ� �ڵ����� �����մϴ�|" << endl;
				return;
			}
		}
	}
}

//Queue-SimpleMusicType�� ���� Queue�� ��� ��Ҹ� command���� ���� �ٸ� Ư�� ��Ͽ� �߰���.
void Application::AddNowPlayListbyQue(Queue<SimpleMusicType>& Queue, const int& command) {
	if (command == 1) {// ���� ������ �߰�
		Queue.ResetList();
		SimpleMusicType f_temp;
		MusicType f_music;
		int idx;
		string m_Id;
		BinarySearchTree<MusicType> *m_ptr;
		bool found;
		while (Queue.GetNextItem(f_temp) != -1) {	//��� queue �� ��� ����
			m_Id = f_temp.GetNum();//���� ���̵�
			f_music.SetNum(m_Id); //MusicType ����
			idx = GetMusicListIdx(m_Id); //MusicList ���� ���� id �޾ƿ�
			m_ptr = MusicList.GetPoint(idx); //MusicList ����
			m_ptr->Retrieve(f_music, found); //MusicList�� �ش� ���� �����ϴ� ���(Queue�� ��� ������ ������ �Ұ����ϹǷ�)
			if (found) {//ã�� ���
				if (NowPlayList.Add(f_temp)) {	//���� �����Ͽ� ����
					cout << endl << "\t    |\"" << m_Id << "\" ���� �߰�|" << endl;
				}
				else { //�ߺ� ����
					cout << endl << "\t    |\"" << m_Id << "\" �� �̹� ������ �� �����մϴ�|" << endl;
				}
			}
		}
	}
	else {	//���� ������ �߰�
		int command;
		command = SelectMyMuiscList();//���� ������ �� Ư�� ������ ���� ���� �ε��� �޾ƿ�
		if (command == 0) { //0�̸� ����
			cout << "\n\t    | ���� ������ �߰��� �����մϴ�|" << endl;
			return;
		}
		InfMusic *s_ptr;
		s_ptr = PlayList.GetPoint(command - 1);	//�޾ƿ� �ε����� ����Ʈ�� ����


		Queue.ResetList();
		SimpleMusicType f_temp;
		MusicType f_music;
		int idx;
		string m_Id;
		BinarySearchTree<MusicType> *m_ptr;
		bool found;
		while (Queue.GetNextItem(f_temp) != -1) {	//��� queue�� ��� ����
			m_Id = f_temp.GetNum();
			f_music.SetNum(m_Id);
			idx = GetMusicListIdx(m_Id);
			m_ptr = MusicList.GetPoint(idx);
			m_ptr->Retrieve(f_music, found);	//MusicList �� �����ϴ��� Ȯ��


			if (found) {
				if (s_ptr->AddItem(f_temp)) { //�ش� �����Ͽ� �߰�

					//�ش� ������ �����Ͽ� ���ߴ��� �˷��ִ� Ư�� �� ����
					string Inpl = f_music.GetIsInPlaylist();
					Inpl[command - 1] = '1'; 
					f_music.SetIsInPlaylist(Inpl);
					m_ptr->Replace(f_music);

					cout << endl << "\t    |\"" << m_Id << "\" ���� �߰�|" << endl;
				}
				else { //�ߺ��Ǵ� ���
					cout << endl << "\t    |\"" << m_Id << "\" �� �̹� ������ �� �����մϴ�|" << endl;
				}
			}
		}

	}
}

//command���� �ش��ϴ� ���� �����Ͽ� ���� Iterator�� ������ AddAllNowPlayList�Լ��� ȣ��.
void Application::AddNowPlayListManage(int& command) {
	InfMusic *i_ptr;
	i_ptr = PlayList.GetPoint(command - 1); //Ư�� �������� ������ �޾ƿ�
	Iterator<SimpleMusicType> iter(i_ptr->GetAddrInf());// iterator ����
	
	AddAllNowPlayList(iter); //�Լ��� ����
	
}

//���� ������ �� Ư�� ����� ����Ű�� iter�� �̿��� ���� �����Ͽ� �߰�.
void Application::AddAllNowPlayList(Iterator<SimpleMusicType> iter) {
	if (iter.IsNotNull()) { //iter�� NULL�� �ƴϸ�
		SimpleMusicType item;
		item = iter.GetCurrentdata(); //iter�� ����Ű�� list�� ����� ���� �޾ƿ�
		
		if (NowPlayList.Add(item)) { //���� �����Ͽ� �߰�
			cout << endl << "\t    |\"" << item.GetNum() << "\" ���� �߰�|" << endl;
		}
		else { //�ߺ������ϴ� ���
			cout << endl << "\t    |\"" << item.GetNum() << "\" �� �̹� ������ �� �����մϴ�|" << endl;
		}

		//iter->MoveLeft();
		AddAllNowPlayList(iter.MoveLeft());

		//iter->MoveRight();
		AddAllNowPlayList(iter.MoveRight());
	}
}

//���� ������ �� command������ �ش��ϴ� ������ �� ��� ��Ҹ� ���� �����Ͽ� �߰�(�ߺ��˻� ��)
void Application::AddNowPlayList(int& command) {
	InfMusic *i_ptr;
	string id;
	i_ptr = PlayList.GetPoint(command - 1); //Ư�� �������� ������ �޾ƿ�

	while (1) {
		cout << "\n\t  | �˻� ID �Է� (����:\'-q\' �Է�)|: ";
		getline(cin >> ws, id); //�˻��Ϸ��� id �Է¹���

		if (id == "-q") {//����
			cout << "\n\t    | ���� ������ �߰��� �����մϴ�|" << endl;
			return;
		}
		else {
			SimpleMusicType f_music(id);
			bool found = false;

			BinarySearchTree<SimpleMusicType> *m_ptr;
			m_ptr = i_ptr->GetPointInf(); //m_ptr�� i_ptr�� ����Ű�� InfMusic�� m_List�� ����Ŵ
			m_ptr->Retrieve(f_music, found); //m_List�� f_music �����ϴ��� Ȯ��

			if (!found) {	//�ش� ���̵� ���� ������ �������� �ʴ� ���
				cout << "\t    |\'" << id << "\' �� ���� ������ ������ �� �����ϴ�|" << endl << endl;
			}
			else {
				if (NowPlayList.Add(f_music)) {	//���������Ͽ� �ش����� ����
					cout << endl << "\t    |\"" << id << "\" ���� �߰�|" << endl;
				}
				else {//�ߺ�
					cout << endl << "\t    |\"" << id << "\" �� �̹� ������ �� �����մϴ�|" << endl;
				}
			}
		}
	}
}

//���� ������ ����Ʈ�� �̸��� ����ڿ��� ����Ͽ� ������ ��, �� �� �����ϰ��� �ϴ� ����Ʈ�� ��ȣ�� �Է¹���.
int Application::SelectMyMuiscList() {
	int command;

	InfMusic temp;
	cout << endl;

	for (int i = 0;i < PlayList.GetLength();i++) {
		InfMusic *ptr = PlayList.GetPoint(i);
		cout << "\t\t  | (" << i+1 << ") " << ptr->GetName() << "\n\n"; //������ �̸� ���
	}

	cout << "\t      --- Quit: Enter \'0\' ---\n\n";
	cout << endl;
	CheckNum(command, 0, 5); //����ó��
	return command;
}

//���� ������ ����
void Application::ManageMyPlayList() {
	int command;
	cout << "\t\t      *****" << endl << endl;
	cout << "\t\t  ===============" << endl;
	cout << "\t\t  | ���� ������ |" << endl;
	cout << "\t\t  ===============" << endl << endl;

	command = SelectMyMuiscList();	//Ư�� �����Ͽ� ������ �ε��� ���޹���

	if (command == 0) {	//����
		cout << "\n\t    |���� ������ ������ �����մϴ�|" << endl;
		return;
	}
	else { //�ش� �ε����� �Լ� ȣ��
		SelectMyPlayList(command);
	}
}

//DetailPlayListGetCommand�κ��� ���� �޾� Queue�� �̿��� �ش� ����� �����ϴ� �Լ�.
void Application::ManageQueueList(Queue<SimpleMusicType>& Queue, string& str) {
	if (count == 0 || Queue.IsEmpty()) { //������ �ϳ��� ���ų� Queue�� ����ִ� ��� ����
		cout << endl << "\t   |�� ���Ǹ���Ʈ�̹Ƿ� �ڵ����� �����մϴ�|" << endl;
		return;
	}
	else {
			while (1)
			{
				if (!Queue.IsEmpty()) {	//Queue�� ������� ���� ��
					switch (DetailPlayListGetCommand(str))
					{
					case 1:	//���� �����Ͽ� �߰�
						AddNowPlayListbyQue(Queue, 1);
						break;
					case 2: //���� �����Ͽ� �߰�
						AddNowPlayListbyQue(Queue, 2);
						break;
					case 3:	//�� ���� ���
						cout << "\n\t\t   ===| " << str << " |===" << endl;
						DisplayQueue(Queue);
						break;
					case 4: //��� Queue ��� ����
						Queue.ResetQueue();
						cout << "\n\t    |" << str << "�� �� ����Ʈ�� �Ǿ����ϴ�|" << endl;
						break;
					case 0:
						cout << "\n\t    |" << str << " ������ �����մϴ�|" << endl;
						return;
					}
				}
				else {
					cout << endl << "\t   |�� ���Ǹ���Ʈ�̹Ƿ� �ڵ����� �����մϴ�|" << endl;
					return;
				}
			}
		
	}
}

//Queue�� ��Ҹ� MusicList���� �˻��Ͽ� �ڼ��� ���� ȭ�鿡 ���
void Application::DisplayQueue(Queue<SimpleMusicType>& Queue) {
	Queue.ResetList();
	SimpleMusicType f_temp;
	MusicType f_music;
	int idx;
	string m_Id;
	BinarySearchTree<MusicType> *m_ptr;
	bool found;
	while (Queue.GetNextItem(f_temp) != -1) {	 //����Ʈ�� ��� ��ҿ� ����
		m_Id = f_temp.GetNum();
		f_music.SetNum(m_Id);
		idx = GetMusicListIdx(m_Id);
		m_ptr = MusicList.GetPoint(idx);
		m_ptr->Retrieve(f_music, found);	//MusicList���� �ش� ��� ã���� ���ÿ� ���� ���޹���
		if (found) {	//ã�� ���
			f_music.DisplayRecord();	//ȭ�鿡 ���
		}
	}
}

//�ִ������� ����
void Application::ManageMostPlayList() {
	if (count == 0 || MostPlayList.IsEmpty()) {//������ �� � ���ų� �ִ��������� ����ִ� ���
		cout << endl << "\t   |�� ���Ǹ���Ʈ�̹Ƿ� �ڵ����� �����մϴ�|" << endl;
		return;
	}
	else {
		int command;
		cout << "\n\t\t      *****" << endl << endl;
		cout << "\t\t  ===============" << endl;
		cout << "\t\t  | �ִ������� |" << endl;
		cout << "\t\t  ===============" << endl << endl;

		Iterator<InfMusic> iter(MostPlayList);
		DisplayAllnestedOrderBST(MostPlayList, iter, 2); //�ִ� ��� ��� �� ��� ���� ������ ���

		while (1) {
			cout << "\n\t\t  | (1) ���� ������ �߰�\n\n";
			cout << "\t\t  | (2) ���� ������ �߰�\n\n";
			cout << "\t\t  | (3) �� ���� ���\n\n\n";
			cout << "\t      --- Quit: Enter \'0\' ---\n\n";

			CheckNum(command, 0, 3);

			if (!MostPlayList.IsEmpty()) { //����Ʈ�� ������� ���� ���
				if (command == 1) {	//���� ������ �߰�
					string temp = ""; 
					AddNowPlayListbyBSTInf("���Ƚ��", MostPlayList, temp, true);
				}
				else if (command == 2) {//���� ������ �߰�
					string temp = "";
					AddMyMusicbyBSTInf("���Ƚ��", MostPlayList, temp, true);
				}
				else if (command == 3) { //������ ���
					Iterator<InfMusic> iter(MostPlayList);
					DisplayAllnestedOrderBST(MostPlayList, iter, 1);
				}
				else { //����
					cout << "\n\t    |�ִ������� ������ �����մϴ� |" << endl;
					return;
				}
			}
			else {
				cout << endl << "\t   |�� ���Ǹ���Ʈ�̹Ƿ� �ڵ����� �����մϴ�|" << endl;
				return;
			}
		}
	}

}

//list(BST-InfMusic)�� �׸��� ���� �����Ͽ� �߰���Ű�� ���� �����ϴ� �Լ�.
void Application::AddNowPlayListbyBSTInf(const string& str, BinarySearchTree<InfMusic>& list, string& input, const bool& Need) {
	if (!list.IsEmpty()) { //����Ʈ�� ������� ���� ���
		cout << endl << endl;
		cout << "\n\t\t      *****" << endl << endl;
		cout << "\t\t  ====================" << endl;
		cout << "\t\t  | ���� ������ �߰� |" << endl;
		cout << "\t\t  ====================" << endl << endl;

		if (Need) { // infMusic�� primary key���� �� input�� �������� ���� ���
			while (1) {
				cout << "\t  | �߰��Ϸ��� " << str << "��(��) �Է��Ͻÿ�(����: \'q\'�Է�)|: ";
				getline(cin >> ws, input);

				if (input == "q") { //�Է� ����
					cout << "\t    |" << str << " - ���� ������ �߰��� ����|" << endl << endl;
					return;
				}

				InfMusic TempType(input);
				bool found;
				list.Isthere(TempType, found); //BST<InfMusic> ����Ʈ �� �ش� infmusic ���� ���� ��� �ֳ� �˻�
				if (!found) { //���� ���
					cout << "\n\t    |\'" << input << "\' �� ���� ������ �������� �ʽ��ϴ�|" << endl << endl;
					continue;
				}
				else { //�ִ� ���
					InfMusic *m_ptr;
					m_ptr = list.GetPoint(TempType);
					if (m_ptr->GetListLength() == 0) { //���� �ش� ��� �� �� � ���� ���
						cout << "\n\t    |\'" << input << "\' �� ���� ������ �������� �ʽ��ϴ�|" << endl << endl;
						continue;
					}
					break;
				}
			}
		}

		InfMusic MusicType(input);
		InfMusic *m_ptr;
		m_ptr = list.GetPoint(MusicType); //input�� ���� InfMusic�� ������ ��ȯ

		Iterator<SimpleMusicType> iter(m_ptr->GetAddrInf());
		AddAllNowPlayList(iter);//�� ��Ͽ��� ������ �����Ͽ� �߰�
	}
	else {
		cout << endl << "\t   |�� ���Ǹ���Ʈ�̹Ƿ� �ڵ����� �����մϴ�|" << endl;
	}
}

//list(BST-InfMusic)�� �׸��� ���� �����Ͽ� �߰���Ű�� ���� �����ϴ� �Լ�.
void Application::AddMyMusicbyBSTInf(const string& str, BinarySearchTree<InfMusic>& list, string& input, const bool& Need) {
	cout << endl << endl;
	cout << "\n\t\t      *****" << endl << endl;
	cout << "\t\t   ====================" << endl;
	cout << "\t\t  | ���� ������ �߰� |" << endl;
	cout << "\t\t   ====================" << endl << endl;

	if (Need) {// infMusic�� primary key���� �� input�� �������� ���� ���
		while (1) {
			cout << "\t  | �߰��Ϸ��� " << str << "��(��) �Է��Ͻÿ�(����: \'q\'�Է�)|: ";
			getline(cin >> ws, input);

			if (input == "q") { //����
				cout << "\t    |" << str <<" - ���� ������ �߰��� ����|" << endl << endl;
			}
			InfMusic TempType(input);
			bool found;
			list.Isthere(TempType, found);
			if (!found) { //ã�� ���� ���
				cout << "\t    |\'" << input << "\' �� ���� ������ �������� �ʽ��ϴ�|" << endl << endl;
				continue;
			}
			else { //ã�����
				InfMusic *m_ptr;
				m_ptr = list.GetPoint(TempType);
				if (m_ptr->GetListLength() == 0) { //�ش� ��� �� ������ �� � �������� �ʴ� ���
					cout << "\n\t    |\'" << input << "\' �� ���� ������ �������� �ʽ��ϴ�|" << endl << endl;
					continue;
				}
				break;
			}
		}
	}

	InfMusic MusicType(input);

	InfMusic *m_ptr;
	m_ptr = list.GetPoint(MusicType);	//input�� ���� infmusic ������ ��ȯ
	Iterator<SimpleMusicType> iter(m_ptr->GetAddrInf());	//�� ��Ͽ��� ������ �����Ͽ� �߰�

	
	int command = SelectMyMuiscList();	//���� ������ �� Ư�� �������� �ε��� ��ȯ
	if (command == 0) {	//0�̸� ����
		cout << endl << "\t   |���� ������ ������ �����մϴ�|" << endl;
		return;
	}
	InfMusic *s_ptr;
	s_ptr = PlayList.GetPoint(command - 1); //������ �߰��� ���� ������

	AddMyPlayListbyBST(iter, s_ptr, command-1);	 //�ش� �����Ͽ� ���� �߰�

}

//���ƿ� �� ���Ǹ�� ����
void Application::ManageHeartList() {
	if (count == 0|| HeartList.IsEmpty()) {//������ ���ų� ���ƿ� ����� ����ִ� ��� ����
		cout << endl << "\t   |�� ���Ǹ���Ʈ�̹Ƿ� �ڵ����� �����մϴ�|" << endl;
		return;
	}
	else {
		int command;
		cout << "\n\t\t      *****" << endl << endl;
		cout << "\t\t  =====================" << endl;
		cout << "\t\t  | ���ƿ� �� ���Ǹ�� |" << endl;
		cout << "\t\t  =====================" << endl << endl;
		HeartList.PrintTree(cout); //���� ��� �� ��� ������ ���
		

		while (1) {
			cout << "\n\t\t  | (1) ���� ������ �߰�\n\n";
			cout << "\t\t  | (2) ���� ������ �߰�\n\n";
			cout << "\t\t  | (3) �� ���� ���\n\n";
			cout << "\t\t  | (4) ���� ���� ���ƿ� ����\n\n\n";
			cout << "\t      --- Quit: Enter \'0\' ---\n\n";

			CheckNum(command, 0, 4);

			if (!HeartList.IsEmpty()) { //������� �������
				switch (command) {
				case 1: //���� �����Ͽ� �߰�
					AddNowPlayListbyHeart();
					break;
				case 2: //���� �����Ͽ� �߰�
					AddMyPlayListbyBSTSim(HeartList);
					break;
				case 3: //���� ���� ���
					cout << "\n\n\t   ===| ���ƿ� �� ���� ��� |===" << endl;
					DisplayAllInfobySimpleFirst(HeartList);
					break;
				case 4: //�������� ���ƿ� ����
					SelectMusicUnHeart();
					break;
				case 0:
					cout << "\n\t    |���ƿ� �� ���Ǹ�� ������ �����մϴ� |" << endl;
					return;
				}
			}
			else {
				cout << endl << "\t   |�� ���Ǹ���Ʈ�̹Ƿ� �ڵ����� �����մϴ�|" << endl;
				return;
			}
		}
	}
}

//s_temp�� id�� ������  MusicType�� ����� �ڼ��� ������ ������ ��, ���� command�� �°� ����Ʈ �߰�,���� �� ���� ������ ��
void Application::UpdateInfor(SimpleMusicType& s_item, const int& command, const int& IsUnset) {
	string inTitle = s_item.GetNum();
	MusicType m_temp(inTitle);
	int m_idx = GetMusicListIdx(inTitle);

	BinarySearchTree<MusicType> *m_ptr;
	m_ptr = MusicList.GetPoint(m_idx); //MusicList �� s_item�� ���̵� ���� ������ ������ ����� ������

	bool found;
	m_ptr->Retrieve(m_temp, found); //�����ϴ��� ã�ƺ�
	if (found) {//����Ʈ���� �߰��� ���
		s_item.SetTitle(m_temp.GetTitle());
		if (command >=0 && command <=4) {//�����ϰ���
			if (IsUnset) {//���� 1->0
				string Inpl = m_temp.GetIsInPlaylist();
				Inpl[command] = '0'; //�ش� ������ ������ ���� ���� ������ ����
				m_temp.SetIsInPlaylist(Inpl);

				InfMusic *in_ptr;
				in_ptr = PlayList.GetPoint(command); //�ش� �����Ͽ� ����
				in_ptr->DeleteItem(s_item); //�ش� ���� ����
			}
			else { //�߰� 0->1
				string Inpl = m_temp.GetIsInPlaylist();
				Inpl[command] = '1'; //�ش� ������ ������ ���� ���� ������ ����
				m_temp.SetIsInPlaylist(Inpl);

				InfMusic *in_ptr;
				in_ptr = PlayList.GetPoint(command);//�ش� �����Ͽ� ����
				in_ptr->AddItem(s_item);//�ش� ���� �߰�
			}
		}
		else if (command == 5) { // ��Ʈ
			if (IsUnset) {//���ƿ�����
				m_temp.SetHeart(false);
				HeartList.Delete(s_item);//���ƿ� ��Ͽ��� ����
			}
			else {//���ƿ伳��
				m_temp.SetHeart(true);
				//���ƿ� ��� �߰�
				HeartList.Add(s_item);
			}
		}
		else { //���Ƚ�� �߰�
			int bef_count = m_temp.GetCount();
			int temp_c = m_temp.GetCount()+1;
			m_temp.SetCount(temp_c);

			//�ֱ��������߰�
			PlayRecentlyList.EnQueue(s_item);

			//�ִ��������߰�
			if (bef_count != 0) {//ó�� �߰��� �ƴ� ���
				InfMusic *in_ptr;
				InfMusic bef_Type(to_string(bef_count));
				// ���� ��Ͽ��� ����
				in_ptr = MostPlayList.GetPoint(bef_Type);
				in_ptr->DeleteItem(s_item);
			}
			InfMusic aft_Type(to_string(temp_c));

			InfMusic *o_ptr;
			//���� �߰� ��, �ش� ��Ͽ� �ٽ� �߰�

			if(MostPlayList.GetLength() != temp_c)
			{
				MostPlayList.Add(aft_Type);
			}

			o_ptr = MostPlayList.GetPoint(aft_Type);
			o_ptr->AddItem(s_item); //�߰�
			
		}
		m_ptr->Replace(m_temp); //����
	}

}

//���ƿ� ������ ����.
void Application::SelectMusicUnHeart() {
	while (1) {
		string id;
		cout << "\n\t\t  |���ƿ� ���� ID �Է�(����: \'q\')|: ";
		getline(cin >> ws, id);//������ ������ id �Է¹���

		if (id.compare("q") == 0) {	//"q"�� �Է¹��� ��� �ݺ��� ����.
			cout << "\n\t  |������� �Է����� ���� ����|" << endl;
			return;
		}
		else {
			SimpleMusicType del_simple(id);
			bool found;
			HeartList.Retrieve(del_simple, found); //���ƿ� ��Ͽ� �����ϴ��� Ȯ��

			if (found) {
				UpdateInfor(del_simple, 5, true);	//���ƿ� ����
				cout << "\n\t    |\'" << id << "\' �� ���ƿ並 �����Ͽ����ϴ�|" << endl << endl;
			}
			else {
				cout << "\n\t    |\'" << id << "\' �� ���� ������ �������� �ʽ��ϴ�|" << endl << endl;
			}
		}
	}
}

//m_list(BST-SimpleMT)�� �̿��� iterator�� ������ DisplayAllInfobySimple �Լ��� �����ϱ� ���� �Լ�.
void Application::DisplayAllInfobySimpleFirst(BinarySearchTree<SimpleMusicType>& m_list) {
	Iterator<SimpleMusicType> iter(m_list);	//iterator ����
	DisplayAllInfobySimple(iter);	//�Լ� ȣ��
}

//iter�� �̿��� InOreder����� �̿��� ��������� �ռ� m_list���� �׸��� ���� ������ �˻��� ȭ�鿡 ���.
void Application::DisplayAllInfobySimple(Iterator<SimpleMusicType> iter) {
	if(iter.IsNotNull()) {
		//Inorder���
		DisplayAllInfobySimple(iter.MoveLeft()); //�����̵�

		SimpleMusicType temp = iter.GetCurrentdata(); //���� ����� ���� �޾ƿ�
		string id = temp.GetNum(); //id
		MusicType f_music(id); // id�������� ���� musictype ����

		int m_idx = GetMusicListIdx(id);//�ش� id�� �������� musiclist����� �ε��� ��ȯ
		BinarySearchTree<MusicType> *m_ptr;
		m_ptr = MusicList.GetPoint(m_idx);	//�ش� ����� ������

		bool found;
		m_ptr->Retrieve(f_music, found); //�˻�
		if (found) {//ã�� ���
			f_music.DisplayRecord();	//�ڼ��� ���� ���
		}
		DisplayAllInfobySimple(iter.MoveRight()); //������ �̵�
	}
}

//BST-SimpleMusicType�� list�� ��� ��Ҹ� �� ������ �� Ư�� ����Ʈ�� �߰�.(PreOrder ���)
void Application::AddMyPlayListbyBST(Iterator<SimpleMusicType> iter, InfMusic*& list, int com) {
	if (iter.IsNotNull()) {
		SimpleMusicType temp = iter.GetCurrentdata(); //�����޾ƿ�
		string m_Id = temp.GetNum();
		
		bool duple;
		duple = list->SearchItem(temp);//list�� m_List�� �ش� ������ �������� �����ϴ��� �Ǻ�

		if (!duple) {//���� ���ϴ� ���
			if (list->AddItem(temp)) { //�߰�

				BinarySearchTree<MusicType> *m_ptr = MusicList.GetPoint(GetMusicListIdx(m_Id));
				MusicType m_temp(m_Id);
				bool found;
				m_ptr->Retrieve(m_temp, found); //MusicList���� �ڼ��� ���� �޾ƿ�

				if (found) {//ã�����
					string Inpl = m_temp.GetIsInPlaylist();
					Inpl[com] = '1'; 
					m_temp.SetIsInPlaylist(Inpl);
					m_ptr->Replace(m_temp); //���������Ͽ� �ش����ǿ� ����ǵ��� ����
				}

				cout << endl << "\t    |\"" << m_Id << "\" ���� �߰�|" << endl;
			}
		}
		else {
			cout << endl << "\t    |\"" << m_Id << "\" �� �̹� ������ �� �����մϴ�|" << endl;
		}
		AddMyPlayListbyBST(iter.MoveLeft(), list, com);		//�����̵�
		AddMyPlayListbyBST(iter.MoveRight(), list, com);	//�������̵�
	}

}

//BST-SimpleMusicType�� list�� ��� ��Ҹ� �� ������ �� Ư�� ����Ʈ�� �߰�.
void Application::AddMyPlayListbyBSTSim(BinarySearchTree<SimpleMusicType>& list) {
	int command;
	command = SelectMyMuiscList(); //Ư�� ����Ʈ�� �ε��� ��ȯ
	if (command == 0) {//0�̸� ����
		cout << endl << "\t   |���� ������ ������ �����մϴ�|" << endl;
		return;
	}
	Iterator<SimpleMusicType> iter(list);

	InfMusic *s_ptr;
	s_ptr = PlayList.GetPoint(command - 1);	//�ش� ����Ʈ�� ������

	AddMyPlayListbyBST(iter, s_ptr, command-1);	//�Լ�ȣ��
}

//���ƿ� �� ����� ��� ��Ҹ� ���� �����Ͽ� ������
void Application::AddNowPlayListbyHeart() {
	if (!HeartList.IsEmpty()) { //������� �ʴٸ�
		Iterator<SimpleMusicType> iter(HeartList);
		AddAllNowPlayList(iter); //�Լ� ȣ���� ���ƿ� ����� ��Ҹ� ���� �����Ͽ� ����
	}
	else {
		cout << endl << "\t   |�� ���Ǹ���Ʈ|" << endl;
	}
}

//������ ���� �Լ� ȣ��
void Application::ManagePlayList() {
	string str;
	while (1)
	{
		switch (PlaylistGetCommnad())
		{
		case 1:// ���� ������ ����
			ManageMyPlayList();
			break;
		case 2: //�ֱ� �߰���� ����
			str = "�ֱ��߰����";
			ManageQueueList(AddRecentlyList,str);
			break;
		case 3: //�ֱ� ������ ����
			str = "�ֱ�������";
			ManageQueueList(PlayRecentlyList, str);
			break;
		case 4:// �ִ� ������ ����
			ManageMostPlayList();
			break;
		case 5://���ƿ� �� ��� ����
			ManageHeartList();
			break;
		case 0:
			cout << "\n\t    |������ ������ �����մϴ�|" << endl;
			return;
		}
	}
}

//���� ������ ����
void Application::ManageNowPlayList() {
	if (count == 0 || NowPlayList.IsEmpty()) { //������ ���ų� ����Ʈ�� ����ִ� ��� ����
		cout << "\n\t|�� �������̹Ƿ� �ڵ����� �����մϴ�|" << endl;
		return;
	}
	int command;

	cout << "\n\t\t      *****" << endl << endl;
	cout << "\t\t  =================" << endl;
	cout << "\t\t  | ���� ������ |" << endl;
	cout << "\t\t  =================" << endl << endl;

	cout << "\n\n\t   ===| ���� ������ |===" << endl;
	NowPlayList.PrintTree(cout); //���� ��� ������ ���

	cout << "\n\t    ----------------------------------" << endl;

	cout << "\n\t\t  | (1) ��ü ���\n\n";
	cout << "\t\t  | (2) ���� ������ �߰�\n\n";
	cout << "\t\t  | (3) ���� ���� ����\n\n";
	cout << "\t\t  | (4) ������ ����\n\n";
	cout << "\t\t  | (5) �� ���� ���\n\n\n";
	cout << "\t      --- Quit: Enter \'0\' ---\n\n";


	CheckNum(command, 0, 5); //�Է�

	if (command == 0) {
		cout << "\n\t    |���������� ������ �����մϴ�|" << endl;
		return;
	}
	else if (command == 1) { //��ü ���
		//delete np_iter; //�ӽ� ��� ����� ����Ű�� �����͵� ����
		//t_NowPlayList.MakeEmpty();	//�ӽ� ��� �����(Circular doubly unsorted linked list)
		cout << "\n\t|�� �ۢܢ� �ۢܢ� ���� ����� �ۢܢ� �ۢܢ� �ۢܢ�|" << endl;
		IsPlaying = true; //����� �˸�
		//�ӽø���Ʈ�� ��� ����
		Iterator<SimpleMusicType> iter(NowPlayList);
		AddTempNPL(iter, true); //���� ������ �� ��� ������ count �� ����
		np_iter = new DoublyIterator<SimpleMusicType>(t_NowPlayList); //������ �� �����Ҵ�
	}
	else if (command == 2) { //���� ������ �߰�
		AddMyPlayListbyBSTSim(NowPlayList);
	}
	else if (command == 3) { //�������� ����
		IsPlaying = false; //���� ����� ����
		t_NowPlayList.MakeEmpty(); //�ӽ� ��� ����� ����
		delete np_iter;//������ ����

		SelectMusicListSimpleDelete(NowPlayList); //���� ����
	}
	else if (command == 4) { //������ ����
		NowPlayList.MakeEmpty(); //���� ������ ��� ��� ����
		t_NowPlayList.MakeEmpty(); //�ӽ� ����� ����
		delete np_iter; //������ ����
		IsPlaying = false; //���� ����� ����
		cout << "\n\t    |���� �������� ��� �����Ͽ����ϴ�|" << endl;
	}
	else {//������ ���
		cout << "\n\n\t   ===| ���� ������ |===" << endl;
		DisplayAllInfobySimpleFirst(NowPlayList);
	}
}

//����ڷκ��� ���� ���̵� �Է¹޾� m_List �� �ش� ���̵� ���� ��Ҹ� ����.
void Application::SelectMusicListSimpleDelete(BinarySearchTree<SimpleMusicType>& m_List){
	if (!m_List.IsEmpty()) {
		SimpleMusicType userDel;
		string temp;
		while (1) {
			cout << "\n\t\t  |���� ID �Է� (����: \'q\')|: ";
			getline(cin >> ws, temp);
			userDel.SetNum(temp);		//������ ������ id �Է¹���

			if (userDel.GetNum().compare("q") == 0) {	//"q" �� �Է¹��� ��� 0�����ϸ� ����.
				cout << "\n\t    |������� �Է����� ����|" << endl;
				return;
			}
			else {
				bool duple;
				m_List.Retrieve(userDel, duple); //����Ʈ���� �ش� id���� ���� ���翩��

				if (!duple) { //���°��
					cout << "\n\t    |\'" << userDel.GetNum() << "\' �� ���� ������ ������ �� �����ϴ�|" << endl << endl;
					return;
				}
				else { //�ִ°��
					m_List.Delete(userDel); //����
					cout << "\n\t\t  |\'" << userDel.GetNum() << "\' �����Ϸ�|" << endl << endl;
				}
			}
		}
	}
	else {
		cout << "\n\t   |�� ����Ʈ �Դϴ�| ";
		return;
	}

}

//iter�� ����Ű�� ����Ʈ �� ��� ����� count���� +1�� ��, �ش� ��� ��Ҹ� PreOrder�� ������� t_NowPlayList�� ����.
void Application::AddTempNPL(Iterator<SimpleMusicType> iter, const bool& IsPlay) {
	if (iter.IsNotNull()) {
		SimpleMusicType temp;
		temp = iter.GetCurrentdata();
		if (IsPlay) {
			UpdateInfor(temp, 6, IsPlay); //���� ī��Ʈ �� ����
		}

		t_NowPlayList.Add(temp); //�ӽ� ��� ����ҿ� ���� ��� �߰�

		AddTempNPL(iter.MoveLeft(), IsPlay); //�����̵�
		AddTempNPL(iter.MoveRight(), IsPlay); //������ �̵�
	}
}

//���� ��� ��ɾ� ���
int Application::PlayGetCommand(const bool&inHeart, const char*filename) {
	int command;
	cout << endl << endl;
	//filename�� �̿��� �ش� ���� ���
	PlaySound(TEXT(filename), NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);
	

	cout << "\t-----------------------------------\n";
	cout << "\t (1)������<< |�Ͻ�����| >>(2)������" << endl;
	cout << "\t-----------------------------------\n\n";

	if (!inHeart) { //���ƿ� �����Ǿ� ������
		cout << "\t\t  | (3) ���ƿ� ����\n\n";
	}
	else { //���ƿ� �����Ǿ� ������
		cout << "\t\t  | (4) ���ƿ� ����\n\n";
	}
	cout << "\t\t  | (5) ������\n\n";
	cout << "\t      --- Quit: Enter \'0\' ---\n\n";


	//�߸��� ��ɾ� �Է½� ����ó��
	CheckNum(command, 0, 5);
	return command;
}

//�������ȭ�� �� ������ ���� ��� ���� ���.
void Application::PlayingMusic(bool& IsPlaying) {
	if (IsPlaying) { //������� ���
		if (!b) { //������ڰ� false�� ���
			ManagePlayingMusic(0);	//MusicItem�� �ʱ�ȭ�ϱ� ���� �Լ�ȣ��
			b = true;//true�� �� ����
		}
		//ȭ�� ���
		cout << "\t---- " << MusicItem.GetTitle() << " ----"  << " | " << MusicItem.GetTime() << endl;
	}
	else {
		b = false;
		cout << "\t\t      <NONE>" << endl;
	}
}

//������� ���� ���α׷� ��� ������ �м��� ȭ�鿡 ���
void Application::MyMusic() {
	//���� ���� ���� ����
	InfMusic *s_ptr;
	int s_size = MostPlayList.GetLength();
	string name = to_string(s_size);
	string most_m = "";
	if (s_size != 0) {
		InfMusic TempType(name);
		s_ptr = MostPlayList.GetPoint(TempType);

		Iterator<SimpleMusicType> m_iter(s_ptr->GetAddrInf());
		most_m = m_iter.GetCurrentdata().GetTitle();
	}
	else {
		most_m = "\t  |---��ȣ�ϴ� �� �Һи�---|\n";
	}

	//��ȣ�ϴ� ��Ƽ��Ʈ
	Iterator<InfMusic> iter(ArtistList);

	int i_temp = 0;
	string temp = "";
	Favorite(iter, i_temp, temp);


	//��ܵ�� �帣
	int i_gen = 0;
	string max_gen = "";
	for (int i = 0;i < GenreList.GetLength() - 1;i++) {
		int size;
		s_ptr = GenreList.GetPoint(i);
		size = s_ptr->GetListLength();
		if (i_gen < size) {
			i_gen = size;
			max_gen = s_ptr->GetName();
		}
	}

	//���
	cout << "\n\t\t       *****\n";
	cout << "\n\t  | ����� ���� ������ �м��ϰڽ��ϴ� |\n\n";
	if (i_gen == 0) {
		cout << "\t  |---��ȣ�ϴ� �帣 �Һи�---|\n";
	}
	else {
		cout << "\n\t  | ����� ��ȣ�ϴ� �帣: ";
		Sleep(500);
		cout << max_gen << endl;
		Sleep(500);
	}

	if (i_temp == 0) {
		cout << "\n\t  |---��ȣ�ϴ� ���� �Һи�---|\n";
	}
	else {
		cout << "\n\t  | ����� ��ȣ�ϴ� ����: ";
		Sleep(500);
		cout << temp << endl;
		Sleep(500);
	}
	
	if (s_size == 0) {
		cout << endl << most_m;
	}
	else {
		cout << "\n\t  | ����� ��ȣ�ϴ� ��: ";
		Sleep(500);
		cout << most_m << endl;
		Sleep(1200);
	}
}

//�����, BST-SimpleMT ���� ����Ʈ ��� �� ���� ���� ��Ҹ� ����.
void Application::Favorite(Iterator<InfMusic> iter, int& i_temp, string& temp) {
	if (iter.IsNotNull()) { 

		InfMusic *st_ptr = ArtistList.GetPoint(iter.GetCurrentdata());
		int size =st_ptr->GetPointInf()->GetLength(); //�� ��Ƽ��Ʈ�� �� ���� ���
		if (i_temp < size) { //������
			i_temp = size;
			temp = iter.GetCurrentdata().GetName(); //���� ū ��Ƽ��Ʈ �̸� ����
		}

		Favorite(iter.MoveLeft(), i_temp, temp); //�����̵�
		Favorite(iter.MoveRight(), i_temp, temp); //�������̵�
	}
}

//������� ���ǿ� ���� ���� ���
void Application::DisplayPlayingMusic(MusicType& m_temp) {
	cout << endl << endl;

	cout << "\t\t      *****" << endl << endl;
	cout << "\t\t  | ���� ��� |" << endl;
	cout << "\t    ----------------------------\n" << endl;

	cout << "\t    | "<< m_temp.GetTitle() <<" ("<< m_temp.GetArtist() <<")|";

	cout << "\n\t\t        *" << endl << endl;

	cout << "\t      "<< m_temp.GetLyrics()<< endl;

	cout << "\n\t    --------| "<< m_temp.GetTime()<<" |---------" << endl << endl;

	cout << "\t     ";
	m_temp.DisplayHeart();

}

//������� ���ǿ� ���� ����.
void Application::ManagePlayingMusic(const int& command) {
	if (!IsPlaying) {
		cout << "\t\t      <NONE>" << endl;
		return;
	}
	SimpleMusicType temp;
	temp = np_iter->GetCurrentdata(); //���� �����Ͱ� ����Ű�� ���� ���޹���
	MusicType m_temp;
	if (b) {
		m_temp = MusicItem;
	}
	bool found;
	PlayingMusicGetMT(temp, m_temp, found);
	if (!b) {//�ʱ�ȭ���� ���� ���
		MusicItem = m_temp; //MusicItem�� ���޹��� �������� �ʱ�ȭ
	}


	if (command!=0) {
		if (found) { //MusicList�� ������� ���� ������ ��
			int com;
			while (1) {
				DisplayPlayingMusic(m_temp);	//������� ���� ���� ȭ�� ���
				bool inHeart = m_temp.GetHeart();

				string fn = m_temp.GetFilename();

				com = PlayGetCommand(inHeart, fn.c_str());	//��ɰ� �Է¹���
				PlaySound(NULL, 0, 0); //���������������
				//�ð��� ȿ��
				cout << "\t\t      ***" << endl;
				Sleep(500);
				cout << "\t\t      ***" << endl;
				Sleep(700);
				if (com == 1) { //���� ������ �̵�
					temp = np_iter->Prev(); //������ �������� �̵���Ŵ
					PlayingMusicGetMT(temp, m_temp, found); //����������
					UpdateInfor(temp, 6, false); //���Ƚ�� ����
					MusicItem = m_temp;
				}
				else if (com == 2) { //���������� �̵�
					temp = np_iter->Next(); //������ �������� �̵���Ŵ
					PlayingMusicGetMT(temp, m_temp, found); //����������
					UpdateInfor(temp, 6, false);//���Ƚ�� ����
					MusicItem = m_temp;
				}
				else if (com == 3) { //���ƿ� ����
					UpdateInfor(temp, 5, false);
					cout << endl << "\t   |���ƿ� �����߽��ϴ�|" << endl;
					PlayingMusicGetMT(temp, m_temp, found);
				}
				else if (com == 4) {//���ƿ� ����
					UpdateInfor(temp, 5, true);
					cout << endl << "\t   |���ƿ� �����߽��ϴ�|" << endl;
					PlayingMusicGetMT(temp, m_temp, found);
				}
				else if (com == 5) { //�ش� ���ǿ� ���� �� ���� ���
					cout << endl;
					m_temp.DisplayRecord();
				}
				else {
					return;
				}
			}
		}
	}
	
}

//temp�� ���̵� �̿��� MusicList�� �ش� �ε����� ���� ��, �ش� BST���� m_temp�� ���� �ڼ��� ������ ������.
void Application::PlayingMusicGetMT(SimpleMusicType& temp, MusicType& m_temp, bool& found) {
	string id = temp.GetNum();
	m_temp.SetNum(id);

	int m_idx = GetMusicListIdx(id); //�ε���
	BinarySearchTree<MusicType> *m_ptr = MusicList.GetPoint(m_idx);
	m_ptr->Retrieve(m_temp, found); //���� ã�Ƽ� ������
}

//����ٰ� ���Ե� ��Ƽ��Ʈ���� ����
void Application::SplitArtist(string arr[], string& artist) {
	int idx = 0;
	string str;
	for (int i = 0;i < artist.length();i++) {
		if (artist[i] == '_') {//������� ���
			arr[idx] = str;
			idx++;
			str.clear();
		}
		else {
			str += artist[i];
		}
	}
	arr[idx] = str; //������ ��Ƽ��Ʈ �迭�� �߰�
}

//����ڷκ��� ������ �Է¹޾� ����Ʈ�� �߰�
int Application::AddMusicFromUser() {
	//����ڷκ��� ���� �Է¹���
	MusicType userAdd;
	userAdd.SetRecordFK();

	bool IsUser = true;

	if (AddMusic(userAdd, IsUser)) {	// AddMusic�Լ� ���
		return 1;	//���������� �߰� �� 1�� ����
	}
	else {
		return 0;	//�߰��� �����ϸ� 0�� ����
	}

}

//���� ����Ʈ�� ���ο� ������ �߰�
int Application::AddMusic(MusicType userAdd, const bool &IsUser) {

	string userT = userAdd.GetTitle();
	string userA = userAdd.GetArtist();
	//id�� ���� ����� ������ �������� �ڵ�����.
	string m_ID = userT + "_" + userA;
	userAdd.SetNum(m_ID);

	bool duple = false;


	int idx = GetMusicListIdx(userT);
	BinarySearchTree<MusicType> *m_idx;
	m_idx = MusicList.GetPoint(idx);

	
	m_idx->Retrieve(userAdd, duple);
	

	if (duple) { //�ߺ��� ��� ����ڿ��� �˷��� �� 0�� ����.
		cout << endl << "\t   |����: " << userT << ", ����: " << userA << "] �̹� ����Ʈ �� ����|" << endl;
		return 0;
	}
	else {	//�ߺ��� �ƴ� ��� MusicList�߰�
		int button;
		button = m_idx->Add(userAdd);
		//button = MusicList.Add(userAdd);


		if (button) { //MusicList�� ������ �߰���
			count++;
			//SimpleMusictype ����
			SimpleMusicType add_Simple(m_ID, userT);

			//Genre
			string genre = userAdd.GetGenre();

			//GenreList �� GenreMusicList�� �߰�
			//�帣 ���̵� �޾ƿ���
			int g_idx = SetGenreId(genre);

			InfMusic *ptr;
			ptr = GenreList.GetPoint(g_idx);
			ptr->AddItem(add_Simple);



			//Artist ====> ��Ƽ��Ʈ �з��ؼ� �߰�
			string artist = userAdd.GetArtist();


			int icount = CountUnderVarArtist(artist);
			string *arr = new string[icount + 1];

			SplitArtist(arr, artist);
			for (int i = 0;i < icount+1;i++) {
				//InfType=>Artist������
				InfMusic ArtistType(arr[i]);
				//ArtistList �߰�
				ArtistList.Add(ArtistType);
				//ArtistList �� ArtistMusicList�� �߰�
				ptr = ArtistList.GetPoint(ArtistType);
				ptr->AddItem(add_Simple);
			}

			//Album
			//InfType=>Album������
			InfMusic AlbumType(userAdd.GetAlbum());
			//AlbumList �߰�
			AlbumList.Add(AlbumType);
			//ArtistList �� ArtistMusicList�� �߰�
			ptr = AlbumList.GetPoint(AlbumType);
			ptr->AddItem(add_Simple);
			
			//�ֱ��߰����
			AddRecentlyList.EnQueue(add_Simple);


			if (IsUser) {
				cout << endl << "\t    \"" << userAdd.GetNum() << "\" ������ ���������� �߰��Ͽ����ϴ�." << endl;
			}
			return 1;	//������ �߰��� �����ϸ� 1�� ����.
		}
		else {
			cout << endl << "\t    \"" << userAdd.GetNum() << "\" ���� �߰��� �����Ͽ����ϴ�." << endl;
			return 0;	//���� �߰��� �����ϸ� 0�� ����.
		}
	}
}

void Application::DeleteMusicFromUser() {
	//������ ������ id �Է¹޾� MusicType����
	MusicType userDel;
	bool IsUser = true;

	while (1) {
		cout << "\n\t\t  |���� ID �Է� (����: \'q\')|\n\n";
		userDel.SetNumFK();		//������ ������ id �Է¹���

		if (userDel.GetNum().compare("q") == 0) {	//"q" �� �Է¹��� ��� 0�����ϸ� ����.
			cout <<"\n\t    |������� �Է����� ����|" << endl;
			break;
		}
		else {

			if (DeleteMusic(userDel, IsUser)) {	// DeleteMusic�Լ� ���
			}
			else {
				cout << "\t    |\'" << userDel.GetNum() << "\' �� ���� ������ �������� �ʽ��ϴ�|" << endl << endl;
			}
		}
	}
	
}

//ã�� ������ number�� ����ڿ��� �Է¹ް� �ش� ���� ����.
int Application::DeleteMusic(MusicType userDel, const bool &IsUser) {
	if (count == 0) {	//���Ǹ���Ʈ�� ��������� 0�� ���� �� ����.
		cout << endl << "\t   |�� ���Ǹ���Ʈ�̹Ƿ� �ڵ����� �����մϴ�|" << endl;
		return 0;
	}
	else {	//���Ǹ���Ʈ�� ��Ұ� �ϳ��̻� �����ϴ� ���
		bool duple = false;

		string tmp_id = userDel.GetNum();
		int idx = GetMusicListIdx(tmp_id);
		BinarySearchTree<MusicType> *m_idx;
		m_idx = MusicList.GetPoint(idx);

		m_idx->Retrieve(userDel, duple);//�˻�

		if (!duple) {
			cout << endl << "\t[ " << tmp_id << " ] ������ �̹� ����Ʈ �� �������� �ʽ��ϴ�." << endl;
			return 0;
		}
		else {	//�ߺ��� ��� ����
			int button;
			button = m_idx->Delete(userDel);

			if (button) {
				count--;
				//�޾ƿ� ������ SimpleMusicType ����
				SimpleMusicType del_Simple(userDel.GetNum());

				//Genre�� ����
				//InfType=>Genre������
				//GenreList �� GenreMusicList���� ����
				
				InfMusic *ptr;

				int g_idx = SetGenreId(userDel.GetGenre());
				ptr = GenreList.GetPoint(g_idx);
				ptr->DeleteItem(del_Simple);


				//Artist�� ����
				//InfType=>Artist������
				string artist = userDel.GetArtist();

				//artistList �� ArtistMusicList���� ����
				int icount = CountUnderVarArtist(artist);
				string *arr = new string[icount + 1];

				//��Ƽ��Ʈ �з�
				SplitArtist(arr, artist);
				for (int i = 0;i < icount + 1;i++) {
					//InfType=>Artist������
					InfMusic ArtistType(arr[i]);
					ptr = ArtistList.GetPoint(ArtistType);
					ptr->DeleteItem(del_Simple);
					if (ptr->GetListLength() == 0) {
						ArtistList.Delete(ArtistType);
					}
				}

				//Album�� ����
				//InfType=>Artist������
				InfMusic AlbumType(userDel.GetAlbum());

				//GenreList �� GenreMusicList���� ����
				ptr = AlbumList.GetPoint(AlbumType);
				ptr->DeleteItem(del_Simple);

				if (ptr->GetListLength() == 0) {
					AlbumList.Delete(AlbumType);
				}

				//���ƿ� ��Ͽ� �ִ°�
				if (userDel.GetHeart()) {
					HeartList.Delete(del_Simple);
				}

				//��������� �ִ°�
				int del_count = userDel.GetCount();
				if (del_count != 0) {	//�ִ���� ��Ͽ��� ����
					string del_scount = to_string(del_count);
					InfMusic Count(del_scount);
					ptr = MostPlayList.GetPoint(Count);
					ptr->DeleteItem(del_Simple);
				}

				//���� �����Ͽ� �ִ°�
				string InPL = userDel.GetIsInPlaylist();
				for (int i = 0;i < 5;i++) {
					if (InPL[i] == '1') { //�ִ� ��� ����
						InfMusic *in_ptr;
						in_ptr = PlayList.GetPoint(i);
						in_ptr->DeleteItem(del_Simple);
					}
				}

				//���������Ͽ� �ִ°�
				bool found;
				NowPlayList.Retrieve(del_Simple, found);
				if (found) {
					NowPlayList.Delete(del_Simple);
				}

				IsPlaying = false; //���� ��� �ߴ�
				t_NowPlayList.MakeEmpty(); //�ӽ� ��� ����� ����
				delete np_iter; //������ ����

				
				cout << endl << "\n\t    |\"" << userDel.GetNum() << "\" ������ �����Ͽ����ϴ�|" << endl;
				return 1;	//���� ������ �����ϸ� 1�� ����.
			}
			else {
				cout << endl << "\n\t    |\"" << userDel.GetNum() << "\" ���� ������ �����Ͽ����ϴ�|" << endl;
				return 0;	//������ �����ϸ� 0�� ����.
			}

		}
	}
}


//�����ϰ��� �ϴ� ���� ������ ����ڷκ��� �Է¹޾� ����.
int Application::ReplaceMusic() {
	if (count == 0) {//���Ǹ���Ʈ�� ��������� 0�� ���� �� ����.
		cout << endl << "\t   |�� ���Ǹ���Ʈ�̹Ƿ� �ڵ����� �����մϴ�|" << endl;
		return 0;
	}
	else {
		//������ ������ id �Է¹޾� MusicType ����
		//��, ����� �������� �ٲ� �� ����. (�帣, �ٹ�, ���� � ���� ����)
		MusicType userRep;
		bool ex = false;

		BinarySearchTree<MusicType> *m_ptr;
		string re_id;
		while (1) {
			cout << "\n\t\t  |���� ID �Է�|" << endl<<endl;
			userRep.SetNumFK();		//������ ������ id �Է¹���
			re_id = userRep.GetNum();
			if (re_id.compare("q") == 0) {	//"q"�� �Է¹��� ��� 0�����ϸ� ����.
				cout << "\n\t  |������� �Է����� ���� ����|" << endl;
				return 0;
			}
			else {
				
				m_ptr = MusicList.GetPoint(GetMusicListIdx(re_id));
				//MusicList���� �˻���, �ڼ� ���� �޾ƿ�
				m_ptr->Retrieve(userRep, ex);
				if (!ex) {	//�ش� num�� ���� ������ ã�� �� ���� ���.
					cout << "\n\t    |\'" << userRep.GetNum() << "\' �� ���� ������ �������� �ʽ��ϴ�. /����: q�� �Է�/|" << endl << endl;
				}
				else {
					break;
				}
			}
		}
		string b_genre = userRep.GetGenre();	//���� �� �帣 ����
		string b_album = userRep.GetAlbum();	//���� �� �ٹ� ����

		// �����ϰ��� �ϴ� ������ ����ڷκ��� �Է¹���
		cout << "\n\t  |���� ���� �Է�|\n\n";
		userRep.SetGenreFK();
		userRep.SetAlbumFK();
		userRep.SetLyricsFK();

		userRep.SetReleaseDFK();
		userRep.SetComposerFK();
		userRep.SetLyricistFK();
		userRep.SetFilenameFK();
		userRep.SetTimeFK();


		int button;
		button = m_ptr->Replace(userRep);	//MusicList���� ���� ����

		if (button) {	//������ �� �� ���
			bool gen = true;
			bool alb = true;
			string a_genre = userRep.GetGenre();
			string a_album = userRep.GetAlbum();
			//Genre����� ���
			if (b_genre.compare(a_genre) != 0) {
				gen = false;
			}
			//Album����� ���
			if (b_album.compare(a_album) != 0) {
				alb = false;
			}

			if (gen&&alb) {	//�帣�� �ٹ� ��� ������� ���� ���
				cout << endl << "\n\t    \"" << userRep.GetNum() << "\" ������ �����Ͽ����ϴ�." << endl;
				return 1;
			}
			else {
				//�޾ƿ� ������ SimpleMusicType ����
				SimpleMusicType del_Simple(userRep.GetNum());

				if (!gen) { //�帣 ����� ���

					//GenreList �� GenreMusicList���� ����
					InfMusic *genre_ptr;
					genre_ptr = GenreList.GetPoint(SetGenreId(b_genre));
					genre_ptr->DeleteItem(del_Simple);

					//�ش� �帣�� GenreMusicList�� �߰�
					genre_ptr = GenreList.GetPoint(SetGenreId(a_genre));
					genre_ptr->AddItem(del_Simple);
				}

				//Album
				if (!alb) { //�ٹ� ����� ���
					//InfType=>Album������
					InfMusic AlbumType(b_album);

					//AlbumList �� AlbumMusicList���� ����
					InfMusic *album_ptr;
					album_ptr = AlbumList.GetPoint(AlbumType);
					album_ptr->DeleteItem(del_Simple);

					InfMusic NAlbumType(a_album);
					//AlbumList �߰�
					AlbumList.Add(NAlbumType);

					//�ش� �ٹ��� AlbumMusicList�� �߰�
					album_ptr = AlbumList.GetPoint(NAlbumType);
					album_ptr->AddItem(del_Simple);
				}
			}

			cout << endl << "\n\t    |\'" << userRep.GetNum() << "\' ������ �����Ͽ����ϴ�|" << endl;
			return 1;	//�������濡 �����ϸ� 1�� ����.
		}
		else {
			cout << endl << "\n\t    |\'" << userRep.GetNum() << "\' ���� ���濡 �����Ͽ����ϴ�|" << endl;
			return 0;	//���濡 �����ϸ� 0�� ����.
		}

	}
}

//����Ʈ�� �ִ� ������ primary key�� �̿��� �˻��Ѵ�.
int Application::SearchByName(MusicType& item) {
	if (MusicList.IsEmpty()) { //����Ʈ�� ����ִ��� Ȯ��.
		cout << endl << "\t   |�� ���Ǹ���Ʈ�̹Ƿ� �ڵ����� �����մϴ�|" << endl;
		return 0; //�� ����Ʈ�̸� �޽����� ����� �� 0�� �����Ѵ�.
	}
	else {

		bool result = false;

		BinarySearchTree<SimpleMusicType> m_list;
		for (int i = 0;i < MusicList.GetLength();i++) {
			Iterator<MusicType> iter(MusicList.GetAddr(i));
			SearchTree(iter, item, result, m_list);
		}

		if (result) {
			cout << endl << "\t ==========================" << endl;
		}
		else { //ã�� ������ ��� �޽����� ����Ѵ�.
			cout << endl << "\t    |�ش� ���ǿ� �´� �ܾ ã�� ���߽��ϴ�| \n\n";
		}

		if (result) {
			DetailManageSearchMusicList(m_list);
			return 1;
		}
		else
			return 0;
	}
}

//str�� inString ī�װ����� list�� �̿��� ����� ó����.
int Application::SearchByBSTInfDetail(BinarySearchTree<InfMusic>& list, const string& str, string& inString) {

	//����Ʈ���� �˻�
	InfMusic TempType(inString);
	InfMusic *ptr;
	ptr = list.GetPoint(TempType);

	if (ptr == NULL) {
		cout << endl << "\n\t \"" << inString << "\"��(��) ã�� �� �����ϴ�." << endl;
		return 0;
	}
	else {
		int command;
		while (1) {
			command = DetailManageSerachGetCommand(inString); //��ɰ� �޾ƿ�

			if (command == 0) {
				cout << endl << "\n\t |" << str << " ���� �˻� ����|" << endl;
				return 0;
			}
			else if (command == 1) { //�����
				string s = "";
				ptr->SearchDisplay(1, MusicList, s);
			}
			else if (command == 2) { //���� ������ �߰�
				AddNowPlayListbyBSTInf("", list, inString, false);
			}
			else if (command == 3) { //���� ������ �߰�
				AddMyMusicbyBSTInf("", list, inString, false);
			}
			else { //���ΰ˻�
				string found;
				BinarySearchTree<SimpleMusicType> temp_list; //�˻� ����� �ӽ÷� ������ ����Ʈ
				if (!ptr->SearchAddDisplay(found, temp_list)) { //Ư�� �ܾ �̿��� �˻�
					cout << endl << "\n\t \'" << found << "\' ��(��) ������ ������ ã�� �� �����ϴ�." << endl;
					return 0;
				}
				else {// �ӽ÷� ������ ����Ʈ �̿� �ٽ� ����
					DetailManageSearchMusicList(temp_list);
				}
			}
		}
		return 1;
	}
}

//������ �߰� �Ǵ� ��������� ���� ��ɾ ����.
int Application::DetailSearchMusicListGetCommand() {
	int command;
	cout << "\n\n\t\t  | (1) ���� ������ �߰�\n\n";
	cout << "\t\t  | (2) ���� ������ �߰�\n\n";
	cout << "\t\t  | (3) �� ���� ���\n\n\n";

	cout << "\t      --- Quit: Enter \'0\' ---\n\n";
	CheckNum(command, 0, 3);
	return command;
}

//DetailSearchMusicListGetCommand�κ��� ��ɰ��� �޾ƿ� �ش� ��ɰ��� ���� ���� ����.
void Application::DetailManageSearchMusicList(BinarySearchTree<SimpleMusicType>& m_list) {
	while (1) {
		if (!m_list.IsEmpty()) { //������� ���� ���
			int command=DetailSearchMusicListGetCommand(); //��ɰ� �޾ƿ�
			if (command == 1) { //���� �����Ͽ� �߰�
				Iterator<SimpleMusicType> iter(m_list);
				AddAllNowPlayList(iter);
			}
			else if (command == 2) { //���� �����Ͽ� �߰�
				int com;
				com = SelectMyMuiscList(); //Ư�� ������ ����
				if (com == 0) {//0�̸� ����
					cout << endl << "\t   |���� �˻��� �����մϴ�|" << endl;
					return;
				}
				Iterator<SimpleMusicType> iter(m_list);

				InfMusic *s_ptr;
				s_ptr = PlayList.GetPoint(com - 1);// ����

				AddMyPlayListbyBST(iter, s_ptr, com-1);
			}
			else if (command == 3) { //���������
				DisplayAllInfobySimpleFirst(m_list);
			}
			else {
				cout << endl << "\t   |���� �˻��� �����մϴ�|" << endl;
				return;
			}

		}
		else {
			cout << endl << "\t   |���õ� ������ �����Ƿ� �����մϴ�|" << endl;
			return;
		}
	}
}

//��Ƽ��Ʈ ���� �� ��� �� ���� ī��Ʈ
int Application::CountUnderVarArtist(string& inArtist) {
	int icount = 0;
	for (int i = 0;i < inArtist.length();i++) {
		if (inArtist[i] == '_') {
			icount++;
		}
	}
	return icount;
}

//����Ʈ�� �ִ� ������ ��Ƽ��Ʈ�� �̿��� �˻��Ѵ�.
int Application::SearchByArtist() {
	int ccount = 0;

	cout << "\n   |ã���� �ϴ� ��Ƽ��Ʈ �Է�|: ";
	string f_artist;
	getline(cin >> ws, f_artist); //����ڷκ��� �Է¹���


	int icount = CountUnderVarArtist(f_artist);
	string *arr = new string[icount + 1]; //����� ������ ������ ��Ƽ��Ʈ ������ �迭 �����Ҵ��Ͽ� ����

	SplitArtist(arr, f_artist);
	for (int i = 0;i < icount + 1;i++) {
		if (SearchByBSTInfDetail(ArtistList, "��Ƽ��Ʈ", arr[i])) //�˻�
			ccount++;
	}
	
	if (ccount)
		return 1;
	else
		return 0;
}

//����Ʈ�� �ִ� ������ �ٹ��� �̿��� �˻��Ѵ�.
int Application::SearchByAlbum() {

	cout << "\n   |ã���� �ϴ� �ٹ��� �Է�|: ";
	string f_album;
	getline(cin >> ws, f_album);

	return SearchByBSTInfDetail(AlbumList, "�ٹ�", f_album);
}

//����Ʈ�� �ִ� ������ �帣�� �̿��� �˻��Ѵ�.
int Application::SearchByGenre() {

	cout << "\n   |ã���� �ϴ� �帣 �Է�|: ";
	string f_genre;
	getline(cin >> ws, f_genre);

	//�帣 ����Ʈ���� �˻�
	int g_idx = SetGenreId(f_genre);

	InfMusic *genre_ptr;
	genre_ptr = GenreList.GetPoint(g_idx);


	if (genre_ptr->GetListLength() == 0) {
		cout << endl << "\t \'" << f_genre << "\' �帣�� ���� ������ �������� �ʽ��ϴ�." << endl;
		return 0;
	}
	else {
		while (1) {
			int command = DetailManageSerachGetCommand(f_genre); //�ش� �帣 ����Ʈ���� � ������ �� �� ����.

			if (command == 0) {	//����
				cout << endl << "\t �帣 ���� �˻��� �����մϴ�." << endl;
				break;
			}
			else if (command == 1) { //�ش� �帣 ��� ���� �ڼ��� ���
				string s = "";
				genre_ptr->SearchDisplay(1, MusicList, s);
			}
			else if (command == 2) {//�ش� �帣 ���� ������ �߰�
				cout << endl << endl;
				cout << "\n\t\t      *****" << endl << endl;
				cout << "\t\t  ====================" << endl;
				cout << "\t\t  | ���� ������ �߰� |" << endl;
				cout << "\t\t  ====================" << endl << endl;

				Iterator<SimpleMusicType> iter(genre_ptr->GetAddrInf());	//�� ��Ͽ��� ������ �����Ͽ� �߰�

				AddAllNowPlayList(iter);
			}
			else if (command == 3) {//�ش� �帣 ���� ������ �߰�
				cout << endl << endl;
				cout << "\n\t\t      *****" << endl << endl;
				cout << "\t\t   ====================" << endl;
				cout << "\t\t  | ���� ������ �߰� |" << endl;
				cout << "\t\t   ====================" << endl << endl;

				Iterator<SimpleMusicType> iter(genre_ptr->GetAddrInf());	//�� ��Ͽ��� ������ �����Ͽ� �߰�

				int command = SelectMyMuiscList();
				if (command == 0) {
					cout << endl << "\t   |���� ������ ������ �����մϴ�|" << endl;
					break;
				}
				InfMusic *s_ptr;
				s_ptr = PlayList.GetPoint(command - 1); //������ �߰��� ���� ������

				AddMyPlayListbyBST(iter, s_ptr, command - 1);
			}
			else {//���ΰ˻�
				string f_title;
				BinarySearchTree<SimpleMusicType> temp_list;
				if (!genre_ptr->SearchAddDisplay(f_title,temp_list)) { //Ư�� �ܾ ���� ������ ������ ã�� ���� ���
					cout << endl << "\t \'" << f_title << "\' ��(��) ������ ������ ã�� �� �����ϴ�." << endl;
					return 0;
				}
				else {
					DetailManageSearchMusicList(temp_list);
				}
			}
		}
		return 1;
	}
}

// Display all records in the list on screen.
void Application::DisplayAllMusic() {
	if (count == 0) {	//�� ����Ʈ�� ���
		cout << endl << "\t   |�� ���Ǹ���Ʈ�̹Ƿ� �ڵ����� �����մϴ�|" << endl;
	}
	else {	//�� ����Ʈ�� �ƴϸ� ���� ������ ���
		MusicType data;

		cout << "\n\t   ===| ��ü ���� ��� |===" << endl;

		// list�� ��� �����͸� ȭ�鿡 ���
		BinarySearchTree<MusicType> *m_ptr;
		for (int i = 0;i < MusicList.GetLength();i++) {
			m_ptr = MusicList.GetPoint(i);
			m_ptr->PrintTree(cout);
		}
	}
}


// Open a file by file descriptor as an input file.
int Application::OpenInFile(char *fileName)
{
	m_InFile.open(fileName);	// file open for reading.

								// ���� ���¿� �����ϸ� 1, �׷��� �ʴٸ� 0�� ����.
	if (!m_InFile)	return 0;
	else	return 1;
}


// Open a file by file descriptor as an output file.
int Application::OpenOutFile(char *fileName)
{
	m_OutFile.open(fileName);	// file open for writing.

								// ���� ���¿� �����ϸ� 1, �׷��� �ʴٸ� 0�� ����.
	if (!m_OutFile)	return 0;
	else	return 1;
}

//�ڵ����� ���Ͽ��� ���� �о��
void Application::AutoReadFile() {
	char filename[] = { "auto" };
	ReadDataFromFile(filename);
}

//����ڷκ��� �����̸� �Է¹޾� �ش� ���Ͽ��� ���� �о��
void Application::ReadFile() {
	char filename[FILENAMESIZE];
	cout << "\n\t |������ ���� �̸�| : ";
	cin >> filename;
	ReadDataFromFile(filename);
}

// Open a file as a read mode, read all data on the file, and set list by the data.
int Application::ReadDataFromFile(char *filename)
{
	//int index = 0;
	MusicType data;	// �б�� �ӽ� ����


	// file open, open error�� �߻��ϸ� 0�� ����
	if (!OpenInFile(filename)) {
		cout << endl << "\t\" " << filename << "\" ������ ���� ���߽��ϴ�." << endl;
		return 0;
	}

	bool IsUser = false;	//User �Է����� ������ �����ϴ� ���� �ƴϹǷ� false ����.
	int icount = 0;
	// ������ ��� ������ �о� list�� �߰�
	string temp_title = "";
	while (!m_InFile.eof())
	{
		data.ReadDataFromFile(m_InFile);
		string data_title = data.GetTitle();
		if (data.GetTitle().length() == 0) {
			break;
		}
		else {
			temp_title = data_title;
		}

		if (AddMusic(data, IsUser)) {	//��� ����Ʈ�� ���Ͽ��� ������ ���� �߰�
			icount++;
		}
	}

	m_InFile.close();	// file close

	cout << endl << "\t\"" << filename << "\" ���Ϸκ��� " << icount << "���� �����͸� ���������� �߰��Ͽ����ϴ�." << endl;

	return 1;
}


// Open a file as a write mode, and write all data into the file,
int Application::WriteDataToFile()
{
	if (count == 0) {
		cout << endl << "\t�ۼ� ������ �����Ͱ� �������� �ʽ��ϴ�." << endl;
		return 0;
	}
	else {
		MusicType data;	// ����� �ӽ� ����

		char filename[FILENAMESIZE];
		cout << "\n\t |������ ���� �̸�| : ";
		cin >> filename;

		// file open, open error�� �߻��ϸ� 0�� ����
		if (!OpenOutFile(filename)) {
			cout << endl << "\t\" " << filename << "\" ������ ���� ���߽��ϴ�." << endl;
			return 0;
		}


		int totalcount = 0;
		for (int i = 0;i < MusicList.GetLength();i++) {
			int icount = 0;
			Iterator<MusicType> iter(MusicList.GetAddr(i));
			WritePreOrder(iter, icount);
			totalcount += icount;
		}

		cout << endl << "\t\"" << filename << "\" ���Ͽ� " << totalcount << "���� �����͸� ���������� �߰��Ͽ����ϴ�." << endl;
		m_OutFile.close();	// file close


		return 1;
	}

}

//PreOrder ������� BST�� ��� ������ ���Ͽ� �ۼ�.
void Application::WritePreOrder(Iterator<MusicType> iter, int& icount) {//cos
	if (iter.IsNotNull()) {
		MusicType item;
		item = iter.GetCurrentdata();
		item.WriteDataToFile(m_OutFile);
		icount++;

		//iter->MoveLeft();
		WritePreOrder(iter.MoveLeft(), icount);

		//iter->MoveRight();
		WritePreOrder(iter.MoveRight(), icount);

	}
}

//iterator�� �̿��� tree �� Ư�� data�� ���� ����� ���� ���
void Application::SearchTree(Iterator<MusicType> iter, MusicType& temp, bool& found, BinarySearchTree<SimpleMusicType>& m_list) {
	if (iter.IsNotNull()) {
		MusicType item;
		item = iter.GetCurrentdata();

		if (item.GetTitle().find(temp.GetNum()) != -1) {
			if (item.GetLyrics().find(temp.GetLyrics()) != -1) {
				item.DisplayRecord();
				SimpleMusicType temp(item.GetNum(), item.GetTitle());
				m_list.Add(temp);
				found = true;
			}
		}

		//iter->MoveLeft();
		SearchTree(iter.MoveLeft(), temp, found, m_list);

		//iter->MoveRight();
		SearchTree(iter.MoveRight(), temp, found,m_list);
	}
}