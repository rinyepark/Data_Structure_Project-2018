#include "Application.h"

//default constructor
Application::Application() {
	m_Command = 0;
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
}

//destructor
Application::~Application() {}

// Program driver.
void Application::Run()
{
	while (1)
	{
		m_Command = GetCommand();

		switch (m_Command)
		{
		case 1: //���� ����
			ManageMusic();
			break;
		case 2: //���� �˻�
			SearchMusic();
			break;
		case 3: //�ֱ��߰����
			DisplayNewMusic();
			break;
		case 4: //�ֱ�������
			DisplayPlayMusic();
			break;
		case 5: //�ִ�������
			DisplayMostMusic();
			break;
		case 6:		//���Ͽ��� ���������� �о��.
			ReadFile();
			break;
		case 7:	//���Ͽ� ���������� ��.
			WriteDataToFile();
			break;
		case 8:		//��ü ���� ����Ʈ ���.
			DisplayAllMusic();
			break;
		case 0:
			return;
		default:
			cout << "\tIllegal selection...\n";
			break;
		}
	}
}

 //���ǰ���
void Application::ManageMusic() {
	int num;
	cout << endl << endl;
	cout << "\t----���� ����----- " << endl;
	cout << "\t   1 : ���� �߰�" << endl;
	cout << "\t   2 : ���� ����" << endl;
	cout << "\t   3 : ���� ���� ����" << endl;
	cout << "\t   0 : ����" << endl;

	cout << endl << "\t Choose a Command--> ";
	cin >> num;
	cout << endl;
	bool button = true;
	switch (num) {
	case 1:	//�����߰�
		int num2;

		cout << "\t----���� �߰�----- " << endl;
		cout << "\t   1 : ���� �߰�" << endl;
		cout << "\t   2 : ���� Top 100 �߰�" << endl;
		cout << "\t   0 : ����" << endl;

		cout << endl << "\t Choose a Command--> ";
		cin >> num2;
		cout << endl;

		if (num2 == 1) { //���� �Է��ؼ� �߰�
			while (button) {
				MusicType temp;
				AddMusic(temp);
				cout << endl << endl;
				cout << "\t---------------------- " << endl;
				cout << "\t   1 : ��� �߰��ϱ�" << endl;
				cout << "\t   2 : ����" << endl;
				int num3;
				while (1) {
					cout << endl << "\t Choose a Command--> ";
					cin >> num3;
					cout << endl;
					if (num3 == 1)
						break;
					else if (num3 == 2) {
						button = false;
						break;
					}
					else {
						cout << "\tIllegal selection...\n";
						continue;
					}
				}
			}
		}
		else if (num2 == 2) { //�ܺ� ���Ͽ��� �������� ������
			BringTop100();
		}
		else if (num2 == 0) { //����
			return;
		}
		else {	//�߸��� �Է�
			cout << "\tIllegal selection...\n";
		}

		break;

	case 2:		//��������
		while (button) {
			if (MusicList.IsEmpty()) {
				cout << "\t  ���Ǹ���Ʈ�� ��� �ֽ��ϴ�." << endl;
				button = false;
			}
			else {
				DeleteMusic();
				cout << endl << endl;
				cout << "\t---------------------- " << endl;
				cout << "\t   1 : ��� �����ϱ�" << endl;
				cout << "\t   2 : ����" << endl;
				int num3;
				while (1) {
					cout << endl << "\t Choose a Command--> ";
					cin >> num3;
					cout << endl;
					if (num3 == 1)
						break;	//��� ���� ����
					else if (num3 == 2) {	//����
						button = false;
						break;
					}
					else {		//�߸��� �Է�
						cout << "\tIllegal selection...\n";
						continue;
					}
				}
			}
		}
		break;
	case 3:	//���� ���� ����
		while (button) {
			if (MusicList.IsEmpty()) {
				cout << "\t  ���Ǹ���Ʈ�� ��� �ֽ��ϴ�." << endl;
				button = false;
			}
			else {
				ReplaceMusic();
				cout << endl << endl;
				cout << "\t---------------------- " << endl;
				cout << "\t   1 : ��� �����ϱ�" << endl;
				cout << "\t   2 : ����" << endl;
				int num3;
				while (1) {
					cout << endl << "\t Choose a Command--> ";
					cin >> num3;
					cout << endl;
					if (num3 == 1)
						break;
					else if (num3 == 2) {
						button = false;
						break;
					}
					else {
						cout << "\tIllegal selection...\n";
						continue;
					}
				}
			}
		}
		break;
	case 0:
		return;
	default:
		cout << "\tIllegal selection...\n";
		break;
	}
}

// ���� �˻�
void Application::SearchMusic() {
	if (MusicList.IsEmpty()) {
		cout << "\t  ���Ǹ���Ʈ�� ��� �ֽ��ϴ�." << endl;
	}
	else {
		int num;
		cout << endl << endl;
		cout << "\t----���� �˻�----- " << endl;
		cout << "\t   1 : ��ü �˻�" << endl;
		cout << "\t   2 : �帣�� �˻�" << endl;
		cout << "\t   3 : ��Ƽ��Ʈ�� �˻�" << endl;
		cout << "\t   4 : �ٹ��� �˻�" << endl;
		cout << "\t   0 : ����" << endl;

		cout << endl << "\t Choose a Command--> ";
		cin >> num;
		cout << endl;

		if (num == 1) {	//��ü�˻�

			cout << endl << endl;
			cout << "\t-------��ü �˻�------- " << endl << endl;
			MusicType data;
			cout << "\t ã���� �ϴ� ����ID�� �Է��Ͻÿ�." << endl;

			int n = SearchById(data);
			if (n == -1)
				cout << endl << "\t �ش� �׸��� ã�� �� �����ϴ�." << endl;

			else {
				int n2;
				cout <<endl<< "\t---------------------- " << endl << endl;
				cout << "\t   1 : ���� ����" << endl;
				cout << "\t   0 : ����" << endl;

				cout << endl << "\t Choose a Command--> ";
				cin >> n2;
				cout << endl;
				if (n2 == 1) {
					MusicSelect(data, n);
				}
				else if (n2 == 0) {
					return;
				}
				else {
					cout << "\tIllegal selection...\n";
				}
			}


		}
		else if (num == 2) { //�帣�� �˻�
			int num2;

			cout << "\t----�帣�� �˻�----- " << endl;
			cout << "\t   1 : �帣 �˻�" << endl;
			cout << "\t   2 : ��� ���" << endl;
			cout << "\t   0 : ����" << endl;

			cout << endl << "\t Choose a Command--> ";
			cin >> num2;
			cout << endl;

			if (num2 == 1) {
				string ggenre;
				cout << "\t ã���� �ϴ� �帣�� �Է��Ͻÿ�: ";
				cin >> ggenre;

				int idx = SetGenreId(ggenre);

				InfMusic *Gen;
				Gen = GenreList.GetPoint(idx);

				int num3;

				cout << endl << "\t---------------------- " << endl;
				cout << "\t   1 : �������� �˻�" << endl;
				cout << "\t   2 : �ش� �帣 ���" << endl;
				cout << "\t   0 : ����" << endl;

				cout << endl << "\t Choose a Command--> ";
				cin >> num3;
				cout << endl;

				if (num3 == 1) {
					string s_title;
					cout << "\t ã���� �ϴ� ����� �Է��Ͻÿ�: ";
					getline(cin >> ws, s_title);

					Gen->DisplaySearchByTitle(s_title, &MusicList);
				}
				else if (num3 == 2) {
					Gen->DisplayInfList(&MusicList);
				}
				else if (num3 == 0) {
					return;
				}
				else {
					cout << "\tIllegal selection...\n";
				}
			}
			else if (num2 == 2) {
				InfMusic *p_gen;
				for (int i = 0;i < GenreList.GetLength();i++) {
					p_gen = GenreList.GetPoint(i);
					p_gen->DisplayInfList(&MusicList);
				}
			}
			else if (num2 == 0) {
				return;
			}
			else {
				cout << "\tIllegal selection...\n";
			}
		}
		else if (num == 3) {	//��Ƽ��Ʈ�� �˻�
			int num2;

			cout << "\t----��Ƽ��Ʈ�� �˻�----- " << endl;
			cout << "\t   1 : ��Ƽ��Ʈ �˻�" << endl;
			cout << "\t   2 : ��� ���" << endl;
			cout << "\t   0 : ����" << endl;

			cout << endl << "\t Choose a Command--> ";
			cin >> num2;
			cout << endl;

			if (num2 == 1) {
				cout << "\t ã���� �ϴ� ��Ƽ��Ʈ���� �Է��Ͻÿ�: ";
				string aartist;
				getline(cin >> ws, aartist);
				InfMusic data;
				data.SetName(aartist);

				InfMusic *Art;
				Art = ArtistList.GetPoint(data);

				if (Art != NULL) {
					int num3;

					cout << endl << "\t---------------------- " << endl;
					cout << "\t   1 : �������� �˻�" << endl;
					cout << "\t   2 : �ش� ��Ƽ��Ʈ ���" << endl;
					cout << "\t   0 : ����" << endl;

					cout << endl << "\t Choose a Command--> ";
					cin >> num3;
					cout << endl;

					if (num3 == 1) {
						string s_title;
						cout << "\t    ã���� �ϴ� ����� �Է��Ͻÿ�: ";
						getline(cin >> ws, s_title);

						Art->DisplaySearchByTitle(s_title, &MusicList);
					}
					else if (num3 == 2) {
						Art->DisplayInfList(&MusicList);
					}
					else if (num3 == 0) {
						return;
					}
					else {
						cout << "\tIllegal selection...\n";
					}
				}
				else {
					cout << endl << "\t \"" << aartist << "\" ��(��) �������� �ʽ��ϴ�.";
				}
			}
			else if (num2 == 2) {
				ArtistList.ResetList();
				InfMusic data;
				SimpleMusicType item;
				InfMusic* p_art;
				for (int i = 0;i < ArtistList.GetLength();i++) {
					ArtistList.GetNextItem(data);
					p_art = ArtistList.GetPoint(data);
					p_art->DisplayInfList(&MusicList);
				}
			}
			else if (num2 == 0) {
				return;
			}
			else {
				cout << "\tIllegal selection...\n";
			}
		}
		else if (num == 4) {	//�ٹ��� �˻�
			int num2;

			cout << "\t----�ٹ��� �˻�----- " << endl;
			cout << "\t   1 : �ٹ� �˻�" << endl;
			cout << "\t   2 : ��� ���" << endl;
			cout << "\t   0 : ����" << endl;

			cout << endl << "\t Choose a Command--> ";
			cin >> num2;
			cout << endl;

			if (num2 == 1) {
				cout << "\t ã���� �ϴ� �ٹ����� �Է��Ͻÿ�: ";
				string aalbum;
				getline(cin >> ws, aalbum);
				InfMusic data;
				data.SetName(aalbum);

				InfMusic *Alb;
				Alb = AlbumList.GetPoint(data);

				if (Alb != NULL) {
					int num3;

					cout << endl << "\t---------------------- " << endl;
					cout << "\t   1 : �������� �˻�" << endl;
					cout << "\t   2 : �ش� �ٹ� ���" << endl;
					cout << "\t   0 : ����" << endl;

					cout << endl << "\t Choose a Command--> ";
					cin >> num3;
					cout << endl;

					if (num3 == 1) {
						string s_title;
						cout << "\t ã���� �ϴ� ����� �Է��Ͻÿ�: ";
						getline(cin >> ws, s_title);

						Alb->DisplaySearchByTitle(s_title, &MusicList);
					}
					else if (num3 == 2) {
						Alb->DisplayInfList(&MusicList);
					}
					else if (num3 == 0) {
						return;
					}
					else {
						cout << "\tIllegal selection...\n";
					}
				}
				else {
					cout << endl << "\t \"" << aalbum << "\" ��(��) �������� �ʽ��ϴ�.";
				}
			}
			else if (num2 == 2) {
				AlbumList.ResetList();
				InfMusic data;
				SimpleMusicType item;
				InfMusic* p_alb;
				for (int i = 0;i < AlbumList.GetLength();i++) {
					AlbumList.GetNextItem(data);
					p_alb = AlbumList.GetPoint(data);
					p_alb->DisplayInfList(&MusicList);
				}
			}
			else if (num2 == 0) {
				return;
			}
			else {
				cout << "\tIllegal selection...\n";
			}

		}
		else if (num == 0) {
			return;
		}
		else {
			cout << "\tIllegal selection...\n";
		}
	}
}

//���� ����
void Application::MusicSelect(MusicType data, int idx) {
	int num;
	cout << endl << "\t----------���Ǽ���---------- " << endl;
	cout << "\t   1 : ���" << endl;
	cout << "\t   0 : ����" << endl;

	cout << endl << "\t Choose a Command--> ";
	cin >> num;
	cout << endl;

	if (num == 1) {	//���� ���
		cout << "\t  �ۢܢ� �ۢܢ� ���� ����� �ۢܢ� �ۢܢ� �ۢܢ�" << endl;

		//�ֱ������� �߰�
		SimpleMusicType s_data;
		s_data.SetRecord(data.GetId(), data.GetTitle());
		if (data.GetCount() == 0) {	//�ߺ��Ǵ� �� ����Ʈ�� �����ϴ��� Ȯ��
			PlayRecentlyMusicList.Add(s_data);	//�߰�
		}
		else {	//�ߺ��Ǵ� ���
			PlayRecentlyMusicList.Delete(s_data);
			PlayRecentlyMusicList.Add(s_data);
		}

		// count �߰�
		MusicType *p_list;
		p_list = MusicList.GetPoint(idx);
		p_list->PlayMusic();

		data.PlayMusic();

		//�ִ� ��� ��� �߰�
		int c_val = data.GetCount();
		string c_name = to_string(c_val);
		InfMusic inf_c;
		inf_c.SetName(c_name);
		InfMusic *p_count;
		InfMusic *q_count;

		if (!MostPlaybackMusicList.Get(inf_c)) {	//�ش� count�� ���� �ʴ� ���
			MostPlaybackMusicList.Add(inf_c);
		}
		if (c_val > 1) {	//�ߺ��Ǵ� ���� �����ϴ� ���
			string cs_name;
			cs_name = to_string(c_val - 1);
			InfMusic inf_tc;
			inf_tc.SetName(cs_name);
			p_count = MostPlaybackMusicList.GetPoint(inf_tc);
			p_count->DeleteItem(s_data);
		}

		//�߰�
		q_count = MostPlaybackMusicList.GetPoint(inf_c);
		q_count->AddItem(s_data);
	}
	else if (num == 0) {
		return;
	}
	else {
		cout << "\tIllegal selection...\n";
	}

}

// Display command on screen and get a input from keyboard.
int Application::GetCommand()
{
	int command;
	cout << endl << endl;
	cout << "\t-----------Music Player----------- " << endl;
	cout << "\t   1 : ���� ����" << endl;
	cout << "\t   2 : ���� �˻�" << endl;
	cout << "\t   3 : �ֱ� �߰� ���" << endl;
	cout << "\t   4 : �ֱ� ��� ���" << endl;
	cout << "\t   5 : �ִ� ��� ���" << endl;
	cout << "\t   6 : ���� ���� ��������" << endl;
	cout << "\t   7 : ���� ���� ��������" << endl;
	cout << "\t   8 : ��ü ���� ���" << endl;
	cout << "\t   0 : Quit" << endl;

	cout << endl << "\t Choose a Command--> ";
	cin >> command;
	cout << endl;

	return command;
}

 //�ܺο��� ����� �������� ������.
void Application::BringTop100() {
	char filename[FILENAMESIZE];
	cout << "\t\"top100music\" �� �Է��Ͻÿ�: ";
	cin >> filename;
	ReadDataFromFile(filename);
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

//���糯¥�� ���������� �߰��� ����, �߸���, �� ������ Ȱ���� ���� ��ȣ�� �ڵ����� ������.
string Application::SetMusicId(MusicType& item) {
	
	count++;
	time_t t;
	t = time(NULL);
	struct tm curr;
	localtime_s(&curr, &t);

	int M_num = (curr.tm_year - 100) * 10000 + (curr.tm_mon + 1) * 100 + curr.tm_mday;
	string id1 = to_string(M_num);
	string id2;
	if (count / 1000 != 0) {
		id2 = "";
	}
	else if (count / 100 != 0) {
		id2 = "0";
	}
	else if (count / 10 != 0) {
		id2 = "00";
	}
	else {
		id2 = "000";
	}

	//�� ������ ������ ����
	string id3 = to_string(count);
	string id4 = item.GetReleaseDate();
	string id5 = item.GetTitle();
	string id = id1 + "." + id2 + id3 + "." + id4 + "." + id5;
	return id;
}


// Add new Music into list.
int Application::AddMusic(MusicType &item) {
	//���� ������ ����ڷκ��� �Է¹���.
	if (item.GetTitle() == "") {
		item.SetRecordFromKB();
	}
	//�帣����Ʈ���� ã�� �� �̹� �����ϸ� break, ������ �߰�
	InfMusic Gdata;
	string g_temp = item.GetGenre();
	Gdata.SetName(g_temp);
	int idx = SetGenreId(g_temp);

	string t_i2 = item.GetTitle();
	string t_i3 = item.GetReleaseDate();
	string t_id = t_i3 + "." + t_i2;

	InfMusic *t_Gdata;
	t_Gdata = GenreList.GetPoint(idx);
	if (t_Gdata->SearchItem(t_id)) {
		cout << endl << "\t" << t_i2 << " ��(��) �̹� �����ϴ� �����Դϴ�." << endl;
		return 0;
	}

	string id = SetMusicId(item);
	item.SetId(id);


	//�Է¹��� ������ add��, �� ���� n�� ���Ϲ���.
	int n = MusicList.Add(item);

	if (n == -1) { //n�� ���� -1�̸� ��ġ�ϴ� �׸��� �����ϴ� ���� �˸� ���� ���.
		cout << endl << "\t    �߰����� ���߽��ϴ�. ��ġ�ϴ� �׸��� �̹� �����մϴ�." << endl;
	}
	else if (n == 1) { //n�� ���� 1�̸� �Է¹��� ������ ����Ʈ�� �߰��� ���� 1�� ����.
		//DisplayAllMusic(); 	// ���� list ���

		
		SimpleMusicType data;
		data.SetRecord(id, item.GetTitle());


		//�ֱ��߰���Ͽ� data ����
		if (AddRecentlyMusicList.IsFull()) {
			SimpleMusicType idata;
			AddRecentlyMusicList.DeQueue(idata);
		}
		AddRecentlyMusicList.EnQueue(data);


		//�帣 ����Ʈ�� data ����
		InfMusic *p_genre;
		int idx_genre = SetGenreId(item.GetGenre());
		p_genre = GenreList.GetPoint(idx_genre);
		p_genre->AddItem(data);


		//��Ƽ��Ʈ ����Ʈ�� data ����
		InfMusic inf_art;
		inf_art.SetName(item.GetArtist());
		if (!ArtistList.Get(inf_art)) {
			ArtistList.Add(inf_art);
		}

		InfMusic *p_artist;
		p_artist = ArtistList.GetPoint(inf_art);
		p_artist->AddItem(data);


		//�ٹ� ����Ʈ�� data ����
		InfMusic inf_alb;
		inf_alb.SetName(item.GetAlbum());
		if (!AlbumList.Get(inf_alb)) {
			AlbumList.Add(inf_alb);
		}

		InfMusic *p_album;
		p_album = AlbumList.GetPoint(inf_alb);
		p_album->AddItem(data);



		return 1;
	}
	else { //�� ���� ���, �߰��� �����ߴٴ� �˸� ���� ���.
		cout << endl << "\t    �߰��� �����߽��ϴ�." << endl;
	}

	return 0; //����Ʈ�� ���� �߰��� ������ ��� 0�� ����.
}

//ã�� ������ Id�� ����ڿ��� �Է¹ް� SortedList�� Delete�Լ��� ȣ���Ѵ�.
int Application::DeleteMusic() {
	MusicType item; //Delete�Լ��� MusicType�� �Ķ���ͷ� ���� ������ ���Ƿ� ������ش�.
	cout << endl << "\t �����ϰ��� �ϴ� ���� ID" << endl;
	item.SetIdFromKB(); //����ڿ��Լ� Number�� �Է¹޴´�.
	int n = MusicList.Delete(item); //Delete�Լ��� data�� �Ѱ��ְ�, �� ���� n�� ���Ϲ���


	if (n == 0) { //n�� ���� -0�̸� ��ġ�ϴ� �׸��� �������� �ʴ� ���� �˸� ���� ���.
		cout << endl << "\t �������� ���߽��ϴ�. ��ġ�ϴ� �׸��� ã�� �� �����ϴ�." << endl;
	}
	else if (n == 1) {
		SimpleMusicType data;
		data.SetId(item.GetId());

		//�帣���� ����
		InfMusic *p_genre;
		int idx_genre = SetGenreId(item.GetGenre());
		p_genre = GenreList.GetPoint(idx_genre);
		p_genre->DeleteItem(data);

		//��Ƽ��Ʈ���� ����
		InfMusic gdata;
		gdata.SetName(item.GetArtist());
		InfMusic *p_artist;
		p_artist = ArtistList.GetPoint(gdata);
		if (p_artist != NULL) {
			p_artist->DeleteItem(data);
		}


		//�ٹ����� ����
		gdata.SetName(item.GetAlbum());
		InfMusic *p_album;
		p_album = AlbumList.GetPoint(gdata);
		if (p_album != NULL) {
			p_album->DeleteItem(data);
		}

		cout << endl << "\t ������ �Ϸ��߽��ϴ�." << endl;

		//�ֱ�����������
		if (item.GetCount() != 0) {
			PlayRecentlyMusicList.Delete(data);
		}

		//�ִ� ������ ����
		if (item.GetCount() != 0) {
			gdata.SetName(to_string(item.GetCount()));
			InfMusic *p_play;
			p_play = MostPlaybackMusicList.GetPoint(gdata);
			if (p_play != NULL) {
				p_play->DeleteItem(data);
			}
		}


		return 1; //������ ���������� �޽����� ����� ��, 1�� �����Ѵ�.
	
	}
	else { //�� ���� ���, ������ �����ߴٴ� �˸� ���� ���.
		cout << endl << "\t ������ �����߽��ϴ�." << endl;
	}
	return 0;  //����Ʈ�� ���� ������ ������ ��� 0�� ����.
}

//ã�� ������ id�� ����ڿ��� �Է¹ް� SortedList�� Replace�Լ��� ȣ���Ѵ�.
int Application::ReplaceMusic() {
	MusicType item; //Replace�Լ��� MusicType�� �Ķ���ͷ� ���� ������ ���Ƿ� ������ش�.
	cout << endl << "\t �����ϰ��� �ϴ� " << endl;
	item.SetIdFromKB(); //����ڿ��Լ� ������ �׸��� id�� �Է¹޴´�.
	if (MusicList.GetByBinarySearch(item) == -1) { //����ڰ� �Է��� �׸��� List�� �ֳ� �˻�
		cout << endl << "\t �������� ���߽��ϴ�. ��ġ�ϴ� �׸��� ã�� �� �����ϴ�." << endl; //ã�� �� ������ �޽����� ����Ѵ�.
	}
	else { //ã�� �� ������
		string t_genre = item.GetGenre();
		string t_artist = item.GetArtist();
		string t_album = item.GetAlbum();
		cout << endl << "\t �����Ϸ��� ������ �Է��Ͻÿ�" << endl;

		//id���� ������ �ʵ��� �帣, ��Ƽ��Ʈ, �ٹ�, ���� ������ ���Ű����ϵ��� �Ѵ�.
		item.SetGenreFromKB();
		item.SetArtistFromKB();
		item.SetAlbumFromKB();
		item.SetLyricsFromKB();
		if (MusicList.Replace(item)) { //Replace�Լ��� item�� �Ѱ��ش�.

			//�帣����Ʈ���� ���� ����
			SimpleMusicType temp;
			temp.SetRecord(item.GetId(), item.GetTitle());

			InfMusic gdata;
			InfMusic qdata;

			//�帣�� �ٲ� ��� ���� �帣���� �ش� ���� ������ ��, ���ο� �帣 ����Ʈ�� ���� �߰�.
			if (item.GetGenre() != t_genre) { 
				SimpleMusicType d_temp = temp;
				//�ٲ�� �� �帣
				int p_idx = SetGenreId(t_genre);
				//�ٲ� �帣
				int q_idx = SetGenreId(item.GetGenre());
			
				qdata.SetName(item.GetGenre());

				InfMusic *p_genre;
				InfMusic *q_genre;

				//�ٲ���� �帣Ÿ��
				p_genre = GenreList.GetPoint(p_idx);
				//�ٲ���� ����
				p_genre->DeleteItem(d_temp);

				//�帣 ����Ʈ�� data ����
				if (!GenreList.GetByBinarySearch(qdata)) {
					GenreList.Add(qdata);
				}
				//�ٲ� �帣Ÿ��
				q_genre = GenreList.GetPoint(q_idx);
				//����Ʈ�� ���� �߰�
				q_genre->AddItem(temp);


				//��Ƽ��Ʈ����Ʈ���� ���� ����
				//��Ƽ��Ʈ�� �ٲ� ��� ���� �帣���� �ش� ���� ������ ��, ���ο� ��Ƽ��Ʈ ����Ʈ�� ���� �߰�.
				if (item.GetArtist() != t_artist) { 
					SimpleMusicType ar_temp = temp;
	
					//�ٲ�� �� ��Ƽ��Ʈ
					gdata.SetName(t_artist);
					//�ٲ� ��Ƽ��Ʈ
					string aartist = item.GetArtist();
					qdata.SetName(aartist);

					InfMusic *p_artist;
					InfMusic *q_artist;

					//�ٲ���� ��Ƽ��ƮŸ��
					p_artist = ArtistList.GetPoint(gdata);
					//�ٲ���� ����
					p_artist->DeleteItem(ar_temp);

					//��Ƽ��Ʈ ����Ʈ�� data ����
					if (!ArtistList.Get(qdata)) {
						ArtistList.Add(qdata);
					}
					//�ٲ� ��Ƽ��ƮŸ��
					q_artist = ArtistList.GetPoint(qdata);
					//����Ʈ�� ���� �߰�
					q_artist->AddItem(temp);
				}

				//�ٹ�����Ʈ���� ���� ����
				//��Ƽ��Ʈ�� �ٲ� ��� ���� �帣���� �ش� ���� ������ ��, ���ο� ��Ƽ��Ʈ ����Ʈ�� ���� �߰�.
				if(item.GetAlbum() != t_album) { 
					SimpleMusicType al_temp = temp;
		
					//�ٲ�� �� ��Ƽ��Ʈ
					gdata.SetName(t_album);
					//�ٲ� ��Ƽ��Ʈ
					string aalbum = item.GetAlbum();
					qdata.SetName(aalbum);

					InfMusic *p_album;
					InfMusic *q_album;

					//�ٲ���� ��Ƽ��ƮŸ��
					p_album = AlbumList.GetPoint(gdata);
					//�ٲ���� ����
					p_album->DeleteItem(al_temp);

					//��Ƽ��Ʈ ����Ʈ�� data ����
					if (!AlbumList.Get(qdata)) {
						AlbumList.Add(qdata);
					}
					//�ٲ� ��Ƽ��ƮŸ��
					q_album = AlbumList.GetPoint(qdata);
					//����Ʈ�� ���� �߰�
					q_album->AddItem(temp);
				}

			}
			cout << endl << "\t ������ �Ϸ��߽��ϴ�." << endl;  //������ �������� �� �޽����� ����ϰ� 1�� �����Ѵ�.
			return 1;
		}
		else {
			cout << endl << "\t ������ �����߽��ϴ�." << endl; //������ �������� �� �޽����� ����Ѵ�.
		}
	}
	return 0; //����Ʈ�� ���� ������ ������ ��� 0�� ����.
}


//����Ʈ�� �ִ� ������ id�� �̿��� �˻� �� �ش� �ε��� ã��.
int Application::SearchById(MusicType& data) {
	if (MusicList.IsEmpty()) { //����Ʈ�� ����ִ��� Ȯ��.
		return 0;  //�� ����Ʈ�̸� 0�� ����.
	}
	else {

		MusicType item;

		item.SetIdFromKB();

		cout << "\n\n\t---------------------- " << endl;
		int idx = MusicList.GetByBinarySearch(item);

		if (idx == -1)
			return -1;
		else
			data = item;
		item.DisplayRecordOnScreen();
		return idx;
	}
}


//����Ʈ�� �ִ� ������ �� ��(Title)�� �̿��� �˻��Ѵ�.
int Application::SearchByName() {
	if (MusicList.IsEmpty()) { //����Ʈ�� ����ִ��� Ȯ��.
		cout << endl << "\t �� ����Ʈ �Դϴ�." << endl;
		return 0; //�� ����Ʈ�̸� �޽����� ����� �� 0�� �����Ѵ�.
	}
	else {
		SimpleMusicType item;
		cout << endl << "\t ã���� �ϴ� " << endl;
		item.SetTitleFromKB();


		int result = 0;
		MusicType temp; //MusicList�� ���� �����ֱ� ���� �ӽ� MusicType.
		MusicList.ResetList();
		while (MusicList.GetNextItem(temp) != -1) { //index�� length�� �ѱ� ������, List�� ������ �����ϸ� GetNextItem�Լ��� -1�� �����ϱ� ������ �ݺ��ϵ��� �Ѵ�.
			if (temp.GetTitle().find(item.GetTitle()) != -1) { //find�Լ������� ��ġ�ϴ� �׸��� �������� ������ -1�� �����ϹǷ� -1�� �ƴϸ� ��ġ�ϴ� ���ڿ��� �ִ°��̴�.
															   //ã�� ��� �޽����� ����Ѵ�.
				if (!result) {
					cout << endl << "\t <============I FOUND ITEM !==========>" << endl;
				}
				temp.DisplayRecordOnScreen(); //��ġ�ϴ� ���ڿ��� �����ϴ� temp�� ������ ����Ѵ�.
				result = 1;
			}
		}
		if (result) {
			cout << endl << "\t <====================================>" << endl;
		}
		else { //ã�� ������ ��� �޽����� ����Ѵ�.
			cout << endl << "\t <========I CAN'T FIND ITEM !==========>" << endl;
		}
		return result; //result�� ã�� ��쿡�� 1��, ã�� ���� ��쿡�� 0�� �����Ѵ�.
	}
}

//�ֱ� ��� ���� ���
void Application::DisplayPlayMusic() {
	if (PlayRecentlyMusicList.GetLength() == 0) {
		cout << "\t �ֱ� ����� ������ �����ϴ�." << endl;
	}
	else {
		cout << "\n\t\t�ֱ� ����� ����" << endl << endl;
		PlayRecentlyMusicList.ResetList();
		SimpleMusicType temp;
		MusicType t_temp;
		for (int i = 0;i < PlayRecentlyMusicList.GetLength();i++) {
			PlayRecentlyMusicList.GetNextItem(temp);
			t_temp.SetId(temp.GetId());
			MusicList.GetByBinarySearch(t_temp);
			t_temp.DisplayRecordOnScreen();
		}
	}
}

//�ִ� ��� ���� ���
void Application::DisplayMostMusic() {
	if (MostPlaybackMusicList.GetLength() == 0) {
		cout << "\t ����� ������ �����ϴ�." << endl;
	}
	else {
		cout << "\n\t\t���� ���� ����� ����" << endl << endl;
		MostPlaybackMusicList.ResetList();
		InfMusic data;
		SimpleMusicType item;
		InfMusic* p_most;
		for (int i = 0;i < MostPlaybackMusicList.GetLength();i++) {
			MostPlaybackMusicList.GetNextItem(data);
			p_most = MostPlaybackMusicList.GetPoint(data);
			p_most->DisplayInfList(&MusicList);
		}
	}
}

// Display all records in the list on screen.
void Application::DisplayAllMusic() {
	if (MusicList.GetLength() == 0) {
		cout << "\t ���Ǹ���� ����ֽ��ϴ�." << endl;
	}
	else {
		MusicType data;

		cout << "\n\t    Current list" << endl << endl;

		// list�� ��� �����͸� ȭ�鿡 ���
		MusicList.ResetList();
		int length = MusicList.GetLength();
		int curIndex = MusicList.GetNextItem(data);
		while (curIndex < length && curIndex != -1)
		{
			cout << endl;
			data.DisplayRecordOnScreen();
			curIndex = MusicList.GetNextItem(data);
		}
	}
}

// Display all records in the AddRecentlyList on screen.
void Application::DisplayNewMusic() {
	if (AddRecentlyMusicList.IsEmpty()) {
		cout << "\t �ֱ� �߰��� ������ �����ϴ�." << endl;
	}
	else {
		SimpleMusicType data;

		cout << "\n\t    �ֱ� �߰��� ����" << endl << endl;

		AddRecentlyMusicList.DisplayInfNew(&MusicList);
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

//���� �б�
void Application::ReadFile() {
	char filename[FILENAMESIZE];
	cout << "\n\tEnter Input file Name : ";
	cin >> filename;
	ReadDataFromFile(filename);
}

// Open a file as a read mode, read all data on the file, and set list by the data.
int Application::ReadDataFromFile(char* filename)
{
	int index = 0;
	MusicType data;	// �б�� �ӽ� ����


	// file open, open error�� �߻��ϸ� 0�� ����
	if (!OpenInFile(filename)) {
		cout << "\t ������ ���� ���߽��ϴ�." << endl;
		return 0;
	}

	// ������ ��� ������ �о� list�� �߰�
	int count = 0;
	while (!m_InFile.eof())
	{
		// array�� �л����� ������ ����ִ� structure ����
		data.ReadDataFromFile(m_InFile);
		if (data.GetId() == "") {
			break;
		}
		AddMusic(data);
		count++;
	}

	m_InFile.close();	// file close

						// ���� list ���
	DisplayAllMusic();

	return 1;
}


// Open a file as a write mode, and write all data into the file,
int Application::WriteDataToFile()
{
	if (MusicList.IsEmpty()) {

		cout << "\t ���Ǹ���Ʈ�� ����־� ������ �ۼ��� �� �����ϴ�." << endl;
		return 0;
	}
	else {
		MusicType data;	// ����� �ӽ� ����

		char filename[FILENAMESIZE];
		cout << "\n\tEnter Output file Name : ";
		cin >> filename;

		// file open, open error�� �߻��ϸ� 0�� ����
		if (!OpenOutFile(filename)) {
			cout << "\t ������ ���� ���߽��ϴ�." << endl;
			return 0;
		}

		// list �����͸� �ʱ�ȭ
		MusicList.ResetList();

		// list�� ��� �����͸� ���Ͽ� ����
		int length = MusicList.GetLength();
		int curIndex = MusicList.GetNextItem(data);
		while (curIndex < length && curIndex != -1)
		{
			data.WriteDataToFile(m_OutFile);
			curIndex = MusicList.GetNextItem(data);
		}

		m_OutFile.close();	// file close

		return 1;
	}
}
