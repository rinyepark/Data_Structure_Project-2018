#include "Application.h"

//default constructor
Application::Application() {
	m_Command = 0;
	InfMusic genre;
	genre.SetName("발라드");
	GenreList.Add(genre);
	genre.SetName("댄스");
	GenreList.Add(genre);
	genre.SetName("OST");
	GenreList.Add(genre);
	genre.SetName("랩/힙합");
	GenreList.Add(genre);
	genre.SetName("R&B/SOUL");
	GenreList.Add(genre);
	genre.SetName("POP");
	GenreList.Add(genre);
	genre.SetName("록/메탈");
	GenreList.Add(genre);
	genre.SetName("포크/블루스");
	GenreList.Add(genre);
	genre.SetName("일렉트로니카");
	GenreList.Add(genre);
	genre.SetName("클래식");
	GenreList.Add(genre);
	genre.SetName("트로트");
	GenreList.Add(genre);
	genre.SetName("기타");
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
		case 1: //음악 관리
			ManageMusic();
			break;
		case 2: //음악 검색
			SearchMusic();
			break;
		case 3: //최근추가목록
			DisplayNewMusic();
			break;
		case 4: //최근재생목록
			DisplayPlayMusic();
			break;
		case 5: //최다재생목록
			DisplayMostMusic();
			break;
		case 6:		//파일에서 음악정보를 읽어옴.
			ReadFile();
			break;
		case 7:	//파일에 음악정보를 씀.
			WriteDataToFile();
			break;
		case 8:		//전체 음악 리스트 출력.
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

 //음악관리
void Application::ManageMusic() {
	int num;
	cout << endl << endl;
	cout << "\t----음악 관리----- " << endl;
	cout << "\t   1 : 음악 추가" << endl;
	cout << "\t   2 : 음악 제거" << endl;
	cout << "\t   3 : 음악 정보 변경" << endl;
	cout << "\t   0 : 종료" << endl;

	cout << endl << "\t Choose a Command--> ";
	cin >> num;
	cout << endl;
	bool button = true;
	switch (num) {
	case 1:	//음악추가
		int num2;

		cout << "\t----음악 추가----- " << endl;
		cout << "\t   1 : 직접 추가" << endl;
		cout << "\t   2 : 음원 Top 100 추가" << endl;
		cout << "\t   0 : 종료" << endl;

		cout << endl << "\t Choose a Command--> ";
		cin >> num2;
		cout << endl;

		if (num2 == 1) { //직접 입력해서 추가
			while (button) {
				MusicType temp;
				AddMusic(temp);
				cout << endl << endl;
				cout << "\t---------------------- " << endl;
				cout << "\t   1 : 계속 추가하기" << endl;
				cout << "\t   2 : 종료" << endl;
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
		else if (num2 == 2) { //외부 파일에서 음원정보 가져옴
			BringTop100();
		}
		else if (num2 == 0) { //종료
			return;
		}
		else {	//잘못된 입력
			cout << "\tIllegal selection...\n";
		}

		break;

	case 2:		//음악제거
		while (button) {
			if (MusicList.IsEmpty()) {
				cout << "\t  음악리스트가 비어 있습니다." << endl;
				button = false;
			}
			else {
				DeleteMusic();
				cout << endl << endl;
				cout << "\t---------------------- " << endl;
				cout << "\t   1 : 계속 삭제하기" << endl;
				cout << "\t   2 : 종료" << endl;
				int num3;
				while (1) {
					cout << endl << "\t Choose a Command--> ";
					cin >> num3;
					cout << endl;
					if (num3 == 1)
						break;	//계속 음악 제거
					else if (num3 == 2) {	//종료
						button = false;
						break;
					}
					else {		//잘못된 입력
						cout << "\tIllegal selection...\n";
						continue;
					}
				}
			}
		}
		break;
	case 3:	//음악 정보 변경
		while (button) {
			if (MusicList.IsEmpty()) {
				cout << "\t  음악리스트가 비어 있습니다." << endl;
				button = false;
			}
			else {
				ReplaceMusic();
				cout << endl << endl;
				cout << "\t---------------------- " << endl;
				cout << "\t   1 : 계속 변경하기" << endl;
				cout << "\t   2 : 종료" << endl;
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

// 음악 검색
void Application::SearchMusic() {
	if (MusicList.IsEmpty()) {
		cout << "\t  음악리스트가 비어 있습니다." << endl;
	}
	else {
		int num;
		cout << endl << endl;
		cout << "\t----음악 검색----- " << endl;
		cout << "\t   1 : 전체 검색" << endl;
		cout << "\t   2 : 장르별 검색" << endl;
		cout << "\t   3 : 아티스트별 검색" << endl;
		cout << "\t   4 : 앨범별 검색" << endl;
		cout << "\t   0 : 종료" << endl;

		cout << endl << "\t Choose a Command--> ";
		cin >> num;
		cout << endl;

		if (num == 1) {	//전체검색

			cout << endl << endl;
			cout << "\t-------전체 검색------- " << endl << endl;
			MusicType data;
			cout << "\t 찾고자 하는 음악ID를 입력하시오." << endl;

			int n = SearchById(data);
			if (n == -1)
				cout << endl << "\t 해당 항목을 찾을 수 없습니다." << endl;

			else {
				int n2;
				cout <<endl<< "\t---------------------- " << endl << endl;
				cout << "\t   1 : 음악 선택" << endl;
				cout << "\t   0 : 종료" << endl;

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
		else if (num == 2) { //장르별 검색
			int num2;

			cout << "\t----장르별 검색----- " << endl;
			cout << "\t   1 : 장르 검색" << endl;
			cout << "\t   2 : 모두 출력" << endl;
			cout << "\t   0 : 종료" << endl;

			cout << endl << "\t Choose a Command--> ";
			cin >> num2;
			cout << endl;

			if (num2 == 1) {
				string ggenre;
				cout << "\t 찾고자 하는 장르를 입력하시오: ";
				cin >> ggenre;

				int idx = SetGenreId(ggenre);

				InfMusic *Gen;
				Gen = GenreList.GetPoint(idx);

				int num3;

				cout << endl << "\t---------------------- " << endl;
				cout << "\t   1 : 제목으로 검색" << endl;
				cout << "\t   2 : 해당 장르 출력" << endl;
				cout << "\t   0 : 종료" << endl;

				cout << endl << "\t Choose a Command--> ";
				cin >> num3;
				cout << endl;

				if (num3 == 1) {
					string s_title;
					cout << "\t 찾고자 하는 곡명을 입력하시오: ";
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
		else if (num == 3) {	//아티스트별 검색
			int num2;

			cout << "\t----아티스트별 검색----- " << endl;
			cout << "\t   1 : 아티스트 검색" << endl;
			cout << "\t   2 : 모두 출력" << endl;
			cout << "\t   0 : 종료" << endl;

			cout << endl << "\t Choose a Command--> ";
			cin >> num2;
			cout << endl;

			if (num2 == 1) {
				cout << "\t 찾고자 하는 아티스트명을 입력하시오: ";
				string aartist;
				getline(cin >> ws, aartist);
				InfMusic data;
				data.SetName(aartist);

				InfMusic *Art;
				Art = ArtistList.GetPoint(data);

				if (Art != NULL) {
					int num3;

					cout << endl << "\t---------------------- " << endl;
					cout << "\t   1 : 제목으로 검색" << endl;
					cout << "\t   2 : 해당 아티스트 출력" << endl;
					cout << "\t   0 : 종료" << endl;

					cout << endl << "\t Choose a Command--> ";
					cin >> num3;
					cout << endl;

					if (num3 == 1) {
						string s_title;
						cout << "\t    찾고자 하는 곡명을 입력하시오: ";
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
					cout << endl << "\t \"" << aartist << "\" 는(은) 존재하지 않습니다.";
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
		else if (num == 4) {	//앨범별 검색
			int num2;

			cout << "\t----앨범별 검색----- " << endl;
			cout << "\t   1 : 앨범 검색" << endl;
			cout << "\t   2 : 모두 출력" << endl;
			cout << "\t   0 : 종료" << endl;

			cout << endl << "\t Choose a Command--> ";
			cin >> num2;
			cout << endl;

			if (num2 == 1) {
				cout << "\t 찾고자 하는 앨범명을 입력하시오: ";
				string aalbum;
				getline(cin >> ws, aalbum);
				InfMusic data;
				data.SetName(aalbum);

				InfMusic *Alb;
				Alb = AlbumList.GetPoint(data);

				if (Alb != NULL) {
					int num3;

					cout << endl << "\t---------------------- " << endl;
					cout << "\t   1 : 제목으로 검색" << endl;
					cout << "\t   2 : 해당 앨범 출력" << endl;
					cout << "\t   0 : 종료" << endl;

					cout << endl << "\t Choose a Command--> ";
					cin >> num3;
					cout << endl;

					if (num3 == 1) {
						string s_title;
						cout << "\t 찾고자 하는 곡명을 입력하시오: ";
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
					cout << endl << "\t \"" << aalbum << "\" 는(은) 존재하지 않습니다.";
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

//음악 선택
void Application::MusicSelect(MusicType data, int idx) {
	int num;
	cout << endl << "\t----------음악선택---------- " << endl;
	cout << "\t   1 : 재생" << endl;
	cout << "\t   0 : 종료" << endl;

	cout << endl << "\t Choose a Command--> ";
	cin >> num;
	cout << endl;

	if (num == 1) {	//음악 재생
		cout << "\t  ♩♪♬ ♩♪♬ 음악 재생중 ♩♪♬ ♩♪♬ ♩♪♬" << endl;

		//최근재생목록 추가
		SimpleMusicType s_data;
		s_data.SetRecord(data.GetId(), data.GetTitle());
		if (data.GetCount() == 0) {	//중복되는 값 리스트에 존재하는지 확인
			PlayRecentlyMusicList.Add(s_data);	//추가
		}
		else {	//중복되는 경우
			PlayRecentlyMusicList.Delete(s_data);
			PlayRecentlyMusicList.Add(s_data);
		}

		// count 추가
		MusicType *p_list;
		p_list = MusicList.GetPoint(idx);
		p_list->PlayMusic();

		data.PlayMusic();

		//최다 재생 목록 추가
		int c_val = data.GetCount();
		string c_name = to_string(c_val);
		InfMusic inf_c;
		inf_c.SetName(c_name);
		InfMusic *p_count;
		InfMusic *q_count;

		if (!MostPlaybackMusicList.Get(inf_c)) {	//해당 count값 존재 않는 경우
			MostPlaybackMusicList.Add(inf_c);
		}
		if (c_val > 1) {	//중복되는 값이 존재하는 경우
			string cs_name;
			cs_name = to_string(c_val - 1);
			InfMusic inf_tc;
			inf_tc.SetName(cs_name);
			p_count = MostPlaybackMusicList.GetPoint(inf_tc);
			p_count->DeleteItem(s_data);
		}

		//추가
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
	cout << "\t   1 : 음악 관리" << endl;
	cout << "\t   2 : 음악 검색" << endl;
	cout << "\t   3 : 최근 추가 목록" << endl;
	cout << "\t   4 : 최근 재생 목록" << endl;
	cout << "\t   5 : 최다 재생 목록" << endl;
	cout << "\t   6 : 음악 정보 가져오기" << endl;
	cout << "\t   7 : 음악 정보 내보내기" << endl;
	cout << "\t   8 : 전체 음악 목록" << endl;
	cout << "\t   0 : Quit" << endl;

	cout << endl << "\t Choose a Command--> ";
	cin >> command;
	cout << endl;

	return command;
}

 //외부에서 저장된 음악정보 가져옴.
void Application::BringTop100() {
	char filename[FILENAMESIZE];
	cout << "\t\"top100music\" 을 입력하시오: ";
	cin >> filename;
	ReadDataFromFile(filename);
}

//genre로 해당 genre index를 찾아 리턴.
int Application::SetGenreId(const string& genre) {
	if (genre == "발라드" || genre == "Ballad")
		return 0;
	else if (genre == "댄스" || genre == "Dance")
		return 1;
	else if (genre == "OST")
		return 2;
	else if (genre == "랩/힙합" || genre == "Rap/Hip-hop")
		return 3;
	else if (genre == "R&B/SOUL")
		return 4;
	else if (genre == "POP" || genre == "팝")
		return 5;
	else if (genre == "록/메탈" || genre == "Rock")
		return 6;
	else if (genre == "포크/블루스" || genre == "Folk")
		return 7;
	else if (genre == "일렉트로니카" || genre == "Electronica")
		return 8;
	else if (genre == "클래식" || genre == "Classic")
		return 9;
	else if (genre == "트로트" || genre == "Adult Contemporary")
		return 10;
	else
		return 11;
}

//현재날짜와 음악정보가 추가된 순서, 발매일, 곡 제목을 활용해 고유 번호를 자동으로 지정함.
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

	//각 정보는 점으로 구분
	string id3 = to_string(count);
	string id4 = item.GetReleaseDate();
	string id5 = item.GetTitle();
	string id = id1 + "." + id2 + id3 + "." + id4 + "." + id5;
	return id;
}


// Add new Music into list.
int Application::AddMusic(MusicType &item) {
	//음악 정보를 사용자로부터 입력받음.
	if (item.GetTitle() == "") {
		item.SetRecordFromKB();
	}
	//장르리스트에서 찾은 후 이미 존재하면 break, 없으면 추가
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
		cout << endl << "\t" << t_i2 << " 는(은) 이미 존재하는 음악입니다." << endl;
		return 0;
	}

	string id = SetMusicId(item);
	item.SetId(id);


	//입력받은 정보를 add후, 그 값을 n에 리턴받음.
	int n = MusicList.Add(item);

	if (n == -1) { //n의 값이 -1이면 일치하는 항목이 존재하는 경우로 알림 문구 출력.
		cout << endl << "\t    추가하지 못했습니다. 일치하는 항목이 이미 존재합니다." << endl;
	}
	else if (n == 1) { //n의 값이 1이면 입력받은 정보를 리스트에 추가한 경우로 1을 리턴.
		//DisplayAllMusic(); 	// 현재 list 출력

		
		SimpleMusicType data;
		data.SetRecord(id, item.GetTitle());


		//최근추가목록에 data 저장
		if (AddRecentlyMusicList.IsFull()) {
			SimpleMusicType idata;
			AddRecentlyMusicList.DeQueue(idata);
		}
		AddRecentlyMusicList.EnQueue(data);


		//장르 리스트에 data 저장
		InfMusic *p_genre;
		int idx_genre = SetGenreId(item.GetGenre());
		p_genre = GenreList.GetPoint(idx_genre);
		p_genre->AddItem(data);


		//아티스트 리스트에 data 저장
		InfMusic inf_art;
		inf_art.SetName(item.GetArtist());
		if (!ArtistList.Get(inf_art)) {
			ArtistList.Add(inf_art);
		}

		InfMusic *p_artist;
		p_artist = ArtistList.GetPoint(inf_art);
		p_artist->AddItem(data);


		//앨범 리스트에 data 저장
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
	else { //그 밖의 경우, 추가를 실패했다는 알림 문구 출력.
		cout << endl << "\t    추가를 실패했습니다." << endl;
	}

	return 0; //리스트에 정보 추가를 실패한 경우 0을 리턴.
}

//찾을 음악의 Id를 사용자에게 입력받고 SortedList의 Delete함수를 호출한다.
int Application::DeleteMusic() {
	MusicType item; //Delete함수는 MusicType을 파라미터로 갖기 때문에 임의로 만들어준다.
	cout << endl << "\t 삭제하고자 하는 곡의 ID" << endl;
	item.SetIdFromKB(); //사용자에게서 Number를 입력받는다.
	int n = MusicList.Delete(item); //Delete함수에 data를 넘겨주고, 그 값을 n에 리턴받음


	if (n == 0) { //n의 값이 -0이면 일치하는 항목이 존재하지 않는 경우로 알림 문구 출력.
		cout << endl << "\t 삭제하지 못했습니다. 일치하는 항목을 찾을 수 없습니다." << endl;
	}
	else if (n == 1) {
		SimpleMusicType data;
		data.SetId(item.GetId());

		//장르에서 제외
		InfMusic *p_genre;
		int idx_genre = SetGenreId(item.GetGenre());
		p_genre = GenreList.GetPoint(idx_genre);
		p_genre->DeleteItem(data);

		//아티스트에서 제외
		InfMusic gdata;
		gdata.SetName(item.GetArtist());
		InfMusic *p_artist;
		p_artist = ArtistList.GetPoint(gdata);
		if (p_artist != NULL) {
			p_artist->DeleteItem(data);
		}


		//앨범에서 제외
		gdata.SetName(item.GetAlbum());
		InfMusic *p_album;
		p_album = AlbumList.GetPoint(gdata);
		if (p_album != NULL) {
			p_album->DeleteItem(data);
		}

		cout << endl << "\t 삭제를 완료했습니다." << endl;

		//최근재생목록제외
		if (item.GetCount() != 0) {
			PlayRecentlyMusicList.Delete(data);
		}

		//최다 재생목록 제외
		if (item.GetCount() != 0) {
			gdata.SetName(to_string(item.GetCount()));
			InfMusic *p_play;
			p_play = MostPlaybackMusicList.GetPoint(gdata);
			if (p_play != NULL) {
				p_play->DeleteItem(data);
			}
		}


		return 1; //삭제에 성공했으면 메시지를 출력한 후, 1을 리턴한다.
	
	}
	else { //그 밖의 경우, 삭제를 실패했다는 알림 문구 출력.
		cout << endl << "\t 삭제를 실패했습니다." << endl;
	}
	return 0;  //리스트의 정보 삭제를 실패한 경우 0을 리턴.
}

//찾을 음악의 id를 사용자에게 입력받고 SortedList의 Replace함수를 호출한다.
int Application::ReplaceMusic() {
	MusicType item; //Replace함수는 MusicType을 파라미터로 갖기 때문에 임의로 만들어준다.
	cout << endl << "\t 수정하고자 하는 " << endl;
	item.SetIdFromKB(); //사용자에게서 수정할 항목의 id를 입력받는다.
	if (MusicList.GetByBinarySearch(item) == -1) { //사용자가 입력한 항목이 List에 있나 검색
		cout << endl << "\t 수정하지 못했습니다. 일치하는 항목을 찾을 수 없습니다." << endl; //찾을 수 없을때 메시지를 출력한다.
	}
	else { //찾을 수 있을때
		string t_genre = item.GetGenre();
		string t_artist = item.GetArtist();
		string t_album = item.GetAlbum();
		cout << endl << "\t 수정하려는 정보를 입력하시오" << endl;

		//id값이 변하지 않도록 장르, 아티스트, 앨범, 가사 정보만 갱신가능하도록 한다.
		item.SetGenreFromKB();
		item.SetArtistFromKB();
		item.SetAlbumFromKB();
		item.SetLyricsFromKB();
		if (MusicList.Replace(item)) { //Replace함수에 item을 넘겨준다.

			//장르리스트에서 정보 갱신
			SimpleMusicType temp;
			temp.SetRecord(item.GetId(), item.GetTitle());

			InfMusic gdata;
			InfMusic qdata;

			//장르가 바뀐 경우 기존 장르에서 해당 정보 삭제한 후, 새로운 장르 리스트에 정보 추가.
			if (item.GetGenre() != t_genre) { 
				SimpleMusicType d_temp = temp;
				//바뀌기 전 장르
				int p_idx = SetGenreId(t_genre);
				//바뀐 장르
				int q_idx = SetGenreId(item.GetGenre());
			
				qdata.SetName(item.GetGenre());

				InfMusic *p_genre;
				InfMusic *q_genre;

				//바뀌기전 장르타입
				p_genre = GenreList.GetPoint(p_idx);
				//바뀌기전 삭제
				p_genre->DeleteItem(d_temp);

				//장르 리스트에 data 저장
				if (!GenreList.GetByBinarySearch(qdata)) {
					GenreList.Add(qdata);
				}
				//바뀐 장르타입
				q_genre = GenreList.GetPoint(q_idx);
				//리스트에 새로 추가
				q_genre->AddItem(temp);


				//아티스트리스트에서 정보 갱신
				//아티스트가 바뀐 경우 기존 장르에서 해당 정보 삭제한 후, 새로운 아티스트 리스트에 정보 추가.
				if (item.GetArtist() != t_artist) { 
					SimpleMusicType ar_temp = temp;
	
					//바뀌기 전 아티스트
					gdata.SetName(t_artist);
					//바뀐 아티스트
					string aartist = item.GetArtist();
					qdata.SetName(aartist);

					InfMusic *p_artist;
					InfMusic *q_artist;

					//바뀌기전 아티스트타입
					p_artist = ArtistList.GetPoint(gdata);
					//바뀌기전 삭제
					p_artist->DeleteItem(ar_temp);

					//아티스트 리스트에 data 저장
					if (!ArtistList.Get(qdata)) {
						ArtistList.Add(qdata);
					}
					//바뀐 아티스트타입
					q_artist = ArtistList.GetPoint(qdata);
					//리스트에 새로 추가
					q_artist->AddItem(temp);
				}

				//앨범리스트에서 정보 갱신
				//아티스트가 바뀐 경우 기존 장르에서 해당 정보 삭제한 후, 새로운 아티스트 리스트에 정보 추가.
				if(item.GetAlbum() != t_album) { 
					SimpleMusicType al_temp = temp;
		
					//바뀌기 전 아티스트
					gdata.SetName(t_album);
					//바뀐 아티스트
					string aalbum = item.GetAlbum();
					qdata.SetName(aalbum);

					InfMusic *p_album;
					InfMusic *q_album;

					//바뀌기전 아티스트타입
					p_album = AlbumList.GetPoint(gdata);
					//바뀌기전 삭제
					p_album->DeleteItem(al_temp);

					//아티스트 리스트에 data 저장
					if (!AlbumList.Get(qdata)) {
						AlbumList.Add(qdata);
					}
					//바뀐 아티스트타입
					q_album = AlbumList.GetPoint(qdata);
					//리스트에 새로 추가
					q_album->AddItem(temp);
				}

			}
			cout << endl << "\t 수정을 완료했습니다." << endl;  //수정을 성공했을 때 메시지를 출력하고 1을 리턴한다.
			return 1;
		}
		else {
			cout << endl << "\t 수정을 실패했습니다." << endl; //수정에 실패했을 때 메시지를 출력한다.
		}
	}
	return 0; //리스트의 정보 수정을 실패한 경우 0을 리턴.
}


//리스트에 있는 음악을 id를 이용해 검색 해 해당 인덱스 찾음.
int Application::SearchById(MusicType& data) {
	if (MusicList.IsEmpty()) { //리스트가 비어있는지 확인.
		return 0;  //빈 리스트이면 0을 리턴.
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


//리스트에 있는 음악을 곡 명(Title)을 이용해 검색한다.
int Application::SearchByName() {
	if (MusicList.IsEmpty()) { //리스트가 비어있는지 확인.
		cout << endl << "\t 빈 리스트 입니다." << endl;
		return 0; //빈 리스트이면 메시지를 출력한 후 0을 리턴한다.
	}
	else {
		SimpleMusicType item;
		cout << endl << "\t 찾고자 하는 " << endl;
		item.SetTitleFromKB();


		int result = 0;
		MusicType temp; //MusicList의 값을 비교해주기 위한 임시 MusicType.
		MusicList.ResetList();
		while (MusicList.GetNextItem(temp) != -1) { //index가 length를 넘기 전까지, List의 끝까지 도달하면 GetNextItem함수는 -1을 리턴하기 전까지 반복하도록 한다.
			if (temp.GetTitle().find(item.GetTitle()) != -1) { //find함수에서는 일치하는 항목이 존재하지 않을때 -1을 리턴하므로 -1이 아니면 일치하는 문자열이 있는것이다.
															   //찾은 경우 메시지를 출력한다.
				if (!result) {
					cout << endl << "\t <============I FOUND ITEM !==========>" << endl;
				}
				temp.DisplayRecordOnScreen(); //일치하는 문자열을 포함하는 temp의 내용을 출력한다.
				result = 1;
			}
		}
		if (result) {
			cout << endl << "\t <====================================>" << endl;
		}
		else { //찾지 못했을 경우 메시지를 출력한다.
			cout << endl << "\t <========I CAN'T FIND ITEM !==========>" << endl;
		}
		return result; //result는 찾은 경우에는 1을, 찾지 못한 경우에는 0을 리턴한다.
	}
}

//최근 재생 음악 출력
void Application::DisplayPlayMusic() {
	if (PlayRecentlyMusicList.GetLength() == 0) {
		cout << "\t 최근 재생한 음악이 없습니다." << endl;
	}
	else {
		cout << "\n\t\t최근 재생한 음악" << endl << endl;
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

//최다 재생 음악 출력
void Application::DisplayMostMusic() {
	if (MostPlaybackMusicList.GetLength() == 0) {
		cout << "\t 재생한 음악이 없습니다." << endl;
	}
	else {
		cout << "\n\t\t가장 많이 재생한 음악" << endl << endl;
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
		cout << "\t 음악목록이 비어있습니다." << endl;
	}
	else {
		MusicType data;

		cout << "\n\t    Current list" << endl << endl;

		// list의 모든 데이터를 화면에 출력
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
		cout << "\t 최근 추가한 음악이 없습니다." << endl;
	}
	else {
		SimpleMusicType data;

		cout << "\n\t    최근 추가한 음악" << endl << endl;

		AddRecentlyMusicList.DisplayInfNew(&MusicList);
	}
}

// Open a file by file descriptor as an input file.
int Application::OpenInFile(char *fileName)
{
	m_InFile.open(fileName);	// file open for reading.

								// 파일 오픈에 성공하면 1, 그렇지 않다면 0을 리턴.
	if (!m_InFile)	return 0;
	else	return 1;
}


// Open a file by file descriptor as an output file.
int Application::OpenOutFile(char *fileName)
{
	m_OutFile.open(fileName);	// file open for writing.

								// 파일 오픈에 성공하면 1, 그렇지 않다면 0을 리턴.
	if (!m_OutFile)	return 0;
	else	return 1;
}

//파일 읽기
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
	MusicType data;	// 읽기용 임시 변수


	// file open, open error가 발생하면 0을 리턴
	if (!OpenInFile(filename)) {
		cout << "\t 파일을 열지 못했습니다." << endl;
		return 0;
	}

	// 파일의 모든 내용을 읽어 list에 추가
	int count = 0;
	while (!m_InFile.eof())
	{
		// array에 학생들의 정보가 들어있는 structure 저장
		data.ReadDataFromFile(m_InFile);
		if (data.GetId() == "") {
			break;
		}
		AddMusic(data);
		count++;
	}

	m_InFile.close();	// file close

						// 현재 list 출력
	DisplayAllMusic();

	return 1;
}


// Open a file as a write mode, and write all data into the file,
int Application::WriteDataToFile()
{
	if (MusicList.IsEmpty()) {

		cout << "\t 음악리스트가 비어있어 파일을 작성할 수 없습니다." << endl;
		return 0;
	}
	else {
		MusicType data;	// 쓰기용 임시 변수

		char filename[FILENAMESIZE];
		cout << "\n\tEnter Output file Name : ";
		cin >> filename;

		// file open, open error가 발생하면 0을 리턴
		if (!OpenOutFile(filename)) {
			cout << "\t 파일을 열지 못했습니다." << endl;
			return 0;
		}

		// list 포인터를 초기화
		MusicList.ResetList();

		// list의 모든 데이터를 파일에 쓰기
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
