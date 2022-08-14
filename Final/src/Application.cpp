#include "Application.h"


//default constructor
Application::Application(){
	count = 0;	//count값 초기화
	b = false;

	//SortedList 각각 필요 크기에 맞게 동적할당
	GenreList.Constructor(12);
	MusicList.Constructor(11);
	PlayList.Constructor(5);

	m_Command = 0;
	
	//GenreList 기본 설정 및 초기화
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

	//MusicList 기본 설정
	BinarySearchTree<MusicType> title;
	MusicList.Add(title); // ㄱ,ㄴ
	MusicList.Add(title); // ㄷ,ㄹ,ㅁ
	MusicList.Add(title); // ㅂ,ㅅ,ㅇ
	MusicList.Add(title); // ㅈ,ㅊ,ㅋ
	MusicList.Add(title); // ㅌ,ㅍ,ㅎ

	MusicList.Add(title); // a, b, c, d, e
	MusicList.Add(title); // f, g, h, i, j
	MusicList.Add(title); // k, l, m, n, o
	MusicList.Add(title); // p, q, r,s, t
	MusicList.Add(title); //u, v, w, x, y, z

	MusicList.Add(title); // 숫자(0~9) 및 기타

	//PlayList 기본 설정 및 초기화
	InfMusic p_list;
	p_list.SetName("빈 재생목록 1");
	PlayList.Add(p_list);
	p_list.SetName("빈 재생목록 2");
	PlayList.Add(p_list);
	p_list.SetName("빈 재생목록 3");
	PlayList.Add(p_list);
	p_list.SetName("빈 재생목록 4");
	PlayList.Add(p_list);
	p_list.SetName("빈 재생목록 5");
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
		case 1:		// 리스트 내 음악 검색.
			SearchMusic();
			break;
		case 2:		// 리스트 내 음악 관리.
			ManageMusic();
			break;
		case 3:		// 사용자 재생목록, 기본 재생목록 관리
			ManagePlayList();
			break;
		case 4:		// 음악 재생 관리.
			ManagePlayingMusic(1);
			break;
		case 5:		// 나의 음악 사용 패턴 분석.
			MyMusic();
			break;
		case 6:		// 현재 재생목록 관리.
			ManageNowPlayList();
			break;
		case 0:
			cout << "\n\n\t    ***** 프로그램 종료 *****" << endl;
			return;
		}
	}
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

//한글, 영어, 숫자 및 기타로 구분된 0~12의 인덱스를 inTitle의 첫번째 값을 유니코드를 이용해 비교해 해당하는 인덱스 값 반환.
int Application::GetMusicListIdx(string& inTitle) {
	int idx;
	CStringW cs(inTitle.c_str());	//C_string으로 변환
	idx = cs[0];

	//유니코드 이용
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

//title과 artist를 이용해 music id자동 생성
void Application::SetMusicId(MusicType& item) {
	item.SetNum(item.GetTitle() + "_" + item.GetArtist());
}

//inCommand가 int인지, int이면 해당 명령번호가 존재하는지 판별하여 사용자로부터 올바른 값을 입력받음.
void Application::CheckNum(int& inCommand, const int&a, const int&b) {
	while (1) {
		cout << endl << "\t\t  |입력| : ";
		cin >> inCommand;
		cout << endl;

		if (!cin.fail()) { //정수를 입력한 경우
			if (inCommand < a || inCommand > b) {	// 존재하지 않는 명령어 번호를 입력한 경우
				cout << "\t    존재하지 않는 번호입니다." << endl;
				cin.clear();
				cin.ignore(256, '\n');
				continue;
			}
			else {	//제대로 입력시 반복문 종료.
				break;
			}
		}
		else {	// 정수가 아닌 잘못된 입력을 한 경우.
			cout << "\t    잘못된 입력입니다." << endl;
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
	cout << "\t******* 음악 관리 프로그램 *******" << endl;
	cout << "\t**********************************\n\n";

	cout << "\t----------------------------------" << endl;

	cout << "\t\t   (1)음악검색" << endl;

	cout << "\t----------------------------------\n";
	cout << "\t    (2)음악관리    (3)재생목록" << endl;
	cout << "\t----------------------------------\n";
	cout << "\t    (4)음악재생    (5)마이뮤직" << endl;
	cout << "\t----------------------------------" << endl;
	cout << "\t--------현재 재생중인 음악--------" << endl << endl;

	PlayingMusic(IsPlaying);	//현재 재생중인 음악에 대한 간단 정보 표시

	cout << "\t----------------------------------" << endl;
	cout << "\t (6) 현재 재생목록         (0)종료" << endl;
	cout << "\t----------------------------------" << endl;


	//잘못된 명령어 입력시 예외처리
	CheckNum(command, 0, 6);
	return command;
}

//음악 검색에 대한 메인 출력화면
int Application::SearchGetCommand() {
	int command;

	cout << endl << endl;

	cout << "\t\t      *****" << endl << endl;
	cout << "\t\t  =============" << endl;
	cout << "\t\t  | 음악 검색 |" << endl;
	cout << "\t\t  =============" << endl << endl;


	cout << "\t\t  | (1) 전체\n\n";
	cout << "\t\t  | (2) 장르\n\n";
	cout << "\t\t  | (3) 아티스트\n\n";
	cout << "\t\t  | (4) 앨범\n\n\n";
	cout << "\t      --- Quit: Enter \'0\' ---\n\n";


	//잘못된 명령어 입력시 예외처리
	CheckNum(command, 0, 4);
	return command;
}

//해당 content 내에서의 음악 리스트 관리 혹은 정보 출력 명령어 선택.
int Application::DetailManageSerachGetCommand(const string&content) {
	int command;
	cout << "\n\t\t      *****" << endl << endl;
	cout << "\t\t  | \"" << content << "\" 검색 |\n" << endl;
	cout << "\t\t  ----------------------------\n\n";

	cout << "\t\t  | (1) 모든 음악정보 상세 출력\n\n";
	cout << "\t\t  | (2) \"" << content << "\" 현재 재생목록 추가\n\n";
	cout << "\t\t  | (3) \"" << content << "\" 나의 재생목록 추가\n\n";
	cout << "\t\t  | (4) \"" << content << "\" 세부 검색\n\n\n";
	cout << "\t      --- Quit: Enter \'0\' ---\n\n";

	CheckNum(command, 0, 4);
	return command;
}

//여러 카테고리의 상세한 검색을 위한 명령어를 선택.
int Application::DetailSerachGetCommand(const string&content) {
	int command;
	cout << "\n\t\t      *****" << endl << endl;
	cout << "\t\t  | "<< content <<" 검색 |" << endl;

	cout << "\t\t  ----------------------------\n\n";
	cout << "\t\t  | (1) "<< content <<" 모든 음악 출력\n\n";
	cout << "\t\t  | (2) "<< content << " 내 세부 검색\n\n\n";
	cout << "\t      --- Quit: Enter \'0\' ---\n\n";
	
	CheckNum(command, 0, 2);
	return command;
}

//전체, 장르, 아티스트, 앨범 등 카테고리를 나누어 음악을 검색.
void Application::SearchMusic() {
	int command;
	while (1)
	{
		if (count == 0) {	//추가된 음악이 없는 경우
			cout << endl << "\t   |음악이 존재하지않아 자동으로 종료합니다|" << endl;
			return;
		}
		int s_idx = SearchGetCommand();	//함수를 통해 명령값 받아옴
		if (s_idx == 1) {
			// 전체 리스트 검색
			cout << "\n\t\t      *****" << endl << endl;
			cout << "\t\t  =============" << endl;
			cout << "\t\t  | 전체 검색 |" << endl;
			cout << "\t\t  =============" << endl << endl;
			cout << "\t\t  | (1) 모든 음악 출력\n\n";
			cout << "\t\t  | (2) 전체 내 세부 검색\n\n\n";
			cout << "\t      --- Quit: Enter \'0\' ---\n\n";

			CheckNum(command, 0, 2);

			if (command == 1) {	//MusicList를 이용해 모든 음악 출력
				DisplayAllMusic();
			}
			else if (command == 2) {
				//전체리스트에서 제목,가사 일치하는 노래 찾을 수 있도록
				cout << "\n\t   |검색하려는 제목과 가사 입력|" << endl<<endl;

				MusicType sear_mt;
				sear_mt.SetNumFK();	//사용자로부터 입력받음
				sear_mt.SetLyricsFK();

				SearchByName(sear_mt);	//함수호출
			}
			else {
				cout << "\n\t    |전체음악 검색을 종료합니다|" << endl;
				return;
			}
		}
		else if (s_idx == 2) {	// 장르 리스트 검색
			command = DetailSerachGetCommand("장르");
			if (command == 1) {	//장르별로 음악 전체 출력
				InfMusic *p_gen;
				for (int i = 0;i < GenreList.GetLength();i++) {	//모든 장르에 대헤
					p_gen = GenreList.GetPoint(i);
					string temp = "";
					if (p_gen->GetListLength() != 0) { //해당 장르 내 음악이 없는 경우 출력하지 않도록 함.
						cout << "\n\t\t  ===|" << p_gen->GetName() << "|===" << endl;

						p_gen->SearchDisplay(1, MusicList, temp);	//음악 정보 자세히 출력
						cout << endl;
					}
				}
			}
			else if (command == 2) {
				SearchByGenre();	//장르 목록 내 세부 검색
			}
			else {
				cout << "\n\t\t    |장르별 검색을 종료합니다|" << endl;
				return;
			}
		}
		else if (s_idx == 3) {// 아티스트 리스트 검색
			Iterator<InfMusic> iter(ArtistList);

			//아티스트 목록 간단 출력
			DisplayAllnestedBST(ArtistList, iter,2);

			command = DetailSerachGetCommand("아티스트");
			if (command == 1) {	//아티스트별로 음악 전체 출력
				Iterator<InfMusic> iter(ArtistList);
				DisplayAllnestedBST(ArtistList, iter, 1);
			}
			else if (command == 2) {//아티스트 목록 내 세부 검색
				SearchByArtist();
			}
			else {
				cout << "\n\t    |아티스트별 검색을 종료합니다|" << endl;
				return;
			}

		}
		else if (s_idx == 4) {	// 앨범 리스트 검색
			Iterator<InfMusic> iter(AlbumList);

			//앨범 목록 간단 출력
			DisplayAllnestedBST(AlbumList, iter, 2);

			command = DetailSerachGetCommand("앨범");
			if (command == 1) {	//앨범 별 음악 전체 출력
				Iterator<InfMusic> iter(AlbumList);
				DisplayAllnestedBST(AlbumList, iter, 1);
			}
			else if (command == 2) {//앨범 목록 내 세부 검색
				SearchByAlbum();
			}
			else {
				cout << "\n\t    |앨범별 검색을 종료합니다|" << endl;
				return;
			}

		}
		else {
			cout << "\n\t    |음악 검색을 종료합니다|" << endl;
			return;
		}
	}
}

//m_list에 대해 command를 통해 재귀적으로 해당 리스트에 관한 정보를 출력.(내림차순 형식)
void Application::DisplayAllnestedOrderBST(BinarySearchTree<InfMusic>& m_list, Iterator<InfMusic> b_iter, const int& command) {
	if (b_iter.IsNotNull()) {	//iter가 NULL이 아니라면
		DisplayAllnestedOrderBST(m_list, b_iter.MoveRight(), command); //오른쪽 이동
		InfMusic *ptr;
		string name;
		name = b_iter.GetCurrentdata().GetName();	//name정보 받아옴
		InfMusic temp(name);
		ptr = m_list.GetPoint(temp);	//해당 name가진 InfMusic 포인터로 받아옴
		if (ptr->GetListLength() != 0) {	//InfMusic내 리스트에 음악이 있는경우
			cout << "\n\t\t  ===|" << name << "|===" << endl;
			if (command == 1) {	//모든 음악 상세히 출력
				ptr->SearchDisplay(1, MusicList, name);
			}
			else {//모든 음악 simple하게 출력
				ptr->DisplaySimpleListFirst(command);
			}
		}
		DisplayAllnestedOrderBST(m_list, b_iter.MoveLeft(), command);	//왼쪽 이동
	}
}

//m_list에 대해 command를 통해 재귀적으로 해당 리스트에 관한 정보를 출력.(Inorder형식)
void Application::DisplayAllnestedBST(BinarySearchTree<InfMusic>& m_list, Iterator<InfMusic> b_iter, const int& command) {
	if (b_iter.IsNotNull()) { //b_iter가 Null이 아닐 때
		DisplayAllnestedBST(m_list, b_iter.MoveLeft(),command);	//왼쪽 이동
		InfMusic *ptr;
		string name;
		name = b_iter.GetCurrentdata().GetName();	//name정보 받아옴
		InfMusic temp(name);
		ptr = m_list.GetPoint(temp);	//해당 name가진 InfMusic 포인터로 받아옴
		if (ptr->GetListLength() != 0) {
			cout << "\n\t\t  |" << name << "|" << endl;
			if (command == 1) { //자세한 정보 출력
				ptr->SearchDisplay(1, MusicList, name);
			}
			else { //간단한 정보 출력
				ptr->DisplaySimpleListFirst(command);
			}
		}
		DisplayAllnestedBST(m_list, b_iter.MoveRight(),command);//오른쪽 이동
	}
}

//메인 음악 관리 명령어 출력
int Application::ManageGetCommand() {
	int command;

	cout << endl << endl;

	cout << "\t\t      *****" << endl << endl;
	cout << "\t\t  =============" << endl;
	cout << "\t\t  | 음악 관리 |" << endl;
	cout << "\t\t  =============" << endl << endl;


	cout << "\t\t  | (1) 직접추가\n\n";
	cout << "\t\t  | (2) 자동추가\n\n";
	cout << "\t\t  | (3) 삭제\n\n";
	cout << "\t\t  | (4) 변경\n\n";
	cout << "\t\t  | (5) 파일 가져오기\n\n";
	cout << "\t\t  | (6) 파일 저장\n\n";
	cout << "\t      --- Quit: Enter \'0\' ---\n\n";


	//잘못된 명령어 입력시 예외처리
	CheckNum(command, 0, 6);
	return command;
}

//음악을 관리하는 함수
void Application::ManageMusic() {
	while (1)
	{
		switch (ManageGetCommand())
		{
		case 1:		//사용자로부터 직접 입력받아 추가
			AddMusicFromUser();
			break;
		case 2:		//자동으로 내장되어있는 목록 가져와 추가
			AutoReadFile();
			break;
		case 3:		//음악 제거
			DeleteMusicFromUser();
			break;
		case 4:		//특정 음악 정보 변경
			ReplaceMusic();
			break;
		case 5:		//파일로부터 읽어와서 추가
			ReadFile();
			break;
		case 6:		//모든 음악 파일로 저장
			WriteDataToFile();
			break;
		case 0:
			cout << "\n\t    |음악 관리를 종료합니다|" << endl;
			return;
		}
	}
}

//메인 재생 목록 명령어 출력 함수.
int Application::PlaylistGetCommnad() {
	int command;

	cout << endl << endl;

	cout << "\t\t      *****" << endl << endl;
	cout << "\t\t  =============" << endl;
	cout << "\t\t  | 재생 목록 |" << endl;
	cout << "\t\t  =============" << endl << endl;


	cout << "\t\t  | (1) 나의 재생목록\n\n"; 	// 이거 선택하자마자 재생목록 이름 모두 출력(사용자 한정)
	cout << "\t\t  | (2) 최근추가 목록\n\n";
	cout << "\t\t  | (3) 최근재생 목록\n\n";
	cout << "\t\t  | (4) 최다재생 목록\n\n";
	cout << "\t\t  | (5) 좋아요 한 음악목록\n\n";
	cout << "\t      --- Quit: Enter \'0\' ---\n\n";


	//잘못된 명령어 입력시 예외처리
	CheckNum(command, 0, 5);
	return command;
}

//상세한 리스트 관리를 위한 명령어 출력.
int Application::DetailPlayListGetCommand(const string&content) {
	int command;
	cout << "\n\t\t      *****" << endl << endl;
	cout << "\t\t  | " << content << " |" << endl;

	cout << "\t\t  ----------------------------\n\n";
	cout << "\t\t  | (1) 현재 재생목록 추가\n\n";
	cout << "\t\t  | (2) 나의 재생목록 추가\n\n";
	cout << "\t\t  | (3) 상세 정보 출력\n\n";
	cout << "\t\t  | (4) 전체 삭제\n\n\n";
	cout << "\t      --- Quit: Enter \'0\' ---\n\n";

	CheckNum(command, 0, 4); //예외처리
	return command;
}

// 나의 재생목목록 5가지 중 한가지 선택하여 관리
void Application::SelectMyPlayList(int& command) {
	InfMusic *i_ptr;
	i_ptr = PlayList.GetPoint(command - 1);	//특정 재생목록 접근
	if (i_ptr->GetListLength() == 0) {
		cout << "\n\t    |빈 재생목록 입니다|" << endl;
	}
	else {
		int com;
		string name = i_ptr->GetName();	//재생목록 이름 받아옴
		cout << "\t\t      *****" << endl;
		cout << "\n\t   ===| " << name << " (" << i_ptr->GetListLength() << ") |===" << endl;

		cout << endl;
		i_ptr->DisplaySimpleListFirst(0);	//간단하게 목록출력

		cout << "\n\n\t      ----------------------------------" << endl;

		string t_name;

		while (1) {
			if (i_ptr->GetListLength() != 0) {	//재생목록이 비어있지 않으면

				cout << "\n\n\t\t  | (1) 현재 재생목록 추가\n\n";
				cout << "\t\t  | (2) 상세 정보 출력\n\n\n";
				cout << "\t\t  | (3) 선택 음악 삭제\n\n";
				cout << "\t\t  | (4) 재생목록 비우기\n\n\n";
				cout << "\t\t  | (5) 재생목록 이름 변경\n\n\n";
				cout << "\t      --- Quit: Enter \'0\' ---\n\n";
				CheckNum(com, 0, 5); //선택

				switch (com)
				{
				case 1://현재 재생목록 추가
					AddNowPlayListManage(command); 
					break;
				case 2://상세 정보 출력
					if (i_ptr->GetListLength() != 0) {
						i_ptr->SearchDisplay(1, MusicList, name);
					}
					else {
						cout << "\n\t    |빈 재생목록 입니다|" << endl;
					}
					break;
				case 3://선택적 음악 삭제
					if (i_ptr->GetListLength() != 0) {
						i_ptr->SelectMusicDelete();
					}
					else {
						cout << "\n\t    |빈 재생목록 입니다|" << endl;
					}
					break;
				case 4: //재생목록 완전히 비움
					i_ptr->MakeEmptyList(command);
					cout << "\n\t    |재생목록을 비웠습니다|\n\n";
					break;
				case 5:	//재생목록 이름 변경
					cout << "\n\t  |변경이름 입력|: ";
					getline(cin >> ws, t_name);
					i_ptr->SetName(t_name);
					cout << "\n\t\t |\'" << t_name << "\'으로 변경되었습니다|" << endl << endl;
					name = t_name;
					break;
				case 0:
					cout << "\n\t    |\'" << name << "\' 관리를 종료합니다|" << endl << endl;
					return;
				}
			}
			else {
				cout << endl << "\t   |빈 재생목록이므로 자동으로 종료합니다|" << endl;
				return;
			}
		}
	}
}

//Queue-SimpleMusicType을 가진 Queue내 모든 요소를 command값에 따라 다른 특정 목록에 추가됨.
void Application::AddNowPlayListbyQue(Queue<SimpleMusicType>& Queue, const int& command) {
	if (command == 1) {// 현재 재생목록 추가
		Queue.ResetList();
		SimpleMusicType f_temp;
		MusicType f_music;
		int idx;
		string m_Id;
		BinarySearchTree<MusicType> *m_ptr;
		bool found;
		while (Queue.GetNextItem(f_temp) != -1) {	//모든 queue 내 요소 접근
			m_Id = f_temp.GetNum();//음악 아이디
			f_music.SetNum(m_Id); //MusicType 생성
			idx = GetMusicListIdx(m_Id); //MusicList 접근 위한 id 받아옴
			m_ptr = MusicList.GetPoint(idx); //MusicList 접근
			m_ptr->Retrieve(f_music, found); //MusicList에 해당 음악 존재하는 경우(Queue내 요소 선택적 삭제가 불가능하므로)
			if (found) {//찾은 경우
				if (NowPlayList.Add(f_temp)) {	//현재 재생목록에 저장
					cout << endl << "\t    |\"" << m_Id << "\" 파일 추가|" << endl;
				}
				else { //중복 존재
					cout << endl << "\t    |\"" << m_Id << "\" 은 이미 재생목록 내 존재합니다|" << endl;
				}
			}
		}
	}
	else {	//나의 재생목록 추가
		int command;
		command = SelectMyMuiscList();//나의 재생목록 중 특정 재생목록 접근 위해 인덱스 받아옴
		if (command == 0) { //0이면 종료
			cout << "\n\t    | 나의 재생목록 추가를 종료합니다|" << endl;
			return;
		}
		InfMusic *s_ptr;
		s_ptr = PlayList.GetPoint(command - 1);	//받아온 인덱스의 리스트에 접근


		Queue.ResetList();
		SimpleMusicType f_temp;
		MusicType f_music;
		int idx;
		string m_Id;
		BinarySearchTree<MusicType> *m_ptr;
		bool found;
		while (Queue.GetNextItem(f_temp) != -1) {	//모든 queue내 요소 접근
			m_Id = f_temp.GetNum();
			f_music.SetNum(m_Id);
			idx = GetMusicListIdx(m_Id);
			m_ptr = MusicList.GetPoint(idx);
			m_ptr->Retrieve(f_music, found);	//MusicList 내 존재하는지 확인


			if (found) {
				if (s_ptr->AddItem(f_temp)) { //해당 재생목록에 추가

					//해당 음악의 재생목록에 속했는지 알려주는 특정 값 변경
					string Inpl = f_music.GetIsInPlaylist();
					Inpl[command - 1] = '1'; 
					f_music.SetIsInPlaylist(Inpl);
					m_ptr->Replace(f_music);

					cout << endl << "\t    |\"" << m_Id << "\" 파일 추가|" << endl;
				}
				else { //중복되는 경우
					cout << endl << "\t    |\"" << m_Id << "\" 은 이미 재생목록 내 존재합니다|" << endl;
				}
			}
		}

	}
}

//command값에 해당하는 나의 재생목록에 대한 Iterator를 생성해 AddAllNowPlayList함수를 호출.
void Application::AddNowPlayListManage(int& command) {
	InfMusic *i_ptr;
	i_ptr = PlayList.GetPoint(command - 1); //특정 재생목록의 포인터 받아옴
	Iterator<SimpleMusicType> iter(i_ptr->GetAddrInf());// iterator 생성
	
	AddAllNowPlayList(iter); //함수로 보냄
	
}

//나의 재생목록 중 특정 목록을 가리키는 iter를 이용해 현재 재생목록에 추가.
void Application::AddAllNowPlayList(Iterator<SimpleMusicType> iter) {
	if (iter.IsNotNull()) { //iter가 NULL이 아니면
		SimpleMusicType item;
		item = iter.GetCurrentdata(); //iter가 가리키는 list내 요소의 정보 받아옴
		
		if (NowPlayList.Add(item)) { //현재 재생목록에 추가
			cout << endl << "\t    |\"" << item.GetNum() << "\" 파일 추가|" << endl;
		}
		else { //중복존재하는 경우
			cout << endl << "\t    |\"" << item.GetNum() << "\" 은 이미 재생목록 내 존재합니다|" << endl;
		}

		//iter->MoveLeft();
		AddAllNowPlayList(iter.MoveLeft());

		//iter->MoveRight();
		AddAllNowPlayList(iter.MoveRight());
	}
}

//나의 재생목록 중 command순번에 해당하는 재생목록 내 모든 요소를 현재 재생목록에 추가(중복검사 함)
void Application::AddNowPlayList(int& command) {
	InfMusic *i_ptr;
	string id;
	i_ptr = PlayList.GetPoint(command - 1); //특정 재생목록의 포인터 받아옴

	while (1) {
		cout << "\n\t  | 검색 ID 입력 (종료:\'-q\' 입력)|: ";
		getline(cin >> ws, id); //검색하려는 id 입력받음

		if (id == "-q") {//종료
			cout << "\n\t    | 현재 재생목록 추가를 종료합니다|" << endl;
			return;
		}
		else {
			SimpleMusicType f_music(id);
			bool found = false;

			BinarySearchTree<SimpleMusicType> *m_ptr;
			m_ptr = i_ptr->GetPointInf(); //m_ptr은 i_ptr이 가리키던 InfMusic의 m_List를 가리킴
			m_ptr->Retrieve(f_music, found); //m_List에 f_music 존재하는지 확인

			if (!found) {	//해당 아이디 가진 음악이 존재하지 않는 경우
				cout << "\t    |\'" << id << "\' 를 가진 음악은 재생목록 내 없습니다|" << endl << endl;
			}
			else {
				if (NowPlayList.Add(f_music)) {	//현재재생목록에 해당음악 저장
					cout << endl << "\t    |\"" << id << "\" 파일 추가|" << endl;
				}
				else {//중복
					cout << endl << "\t    |\"" << id << "\" 은 이미 재생목록 내 존재합니다|" << endl;
				}
			}
		}
	}
}

//나의 재생목록 리스트의 이름을 사용자에게 출력하여 보여준 후, 이 중 관리하고자 하는 리스트의 번호를 입력받음.
int Application::SelectMyMuiscList() {
	int command;

	InfMusic temp;
	cout << endl;

	for (int i = 0;i < PlayList.GetLength();i++) {
		InfMusic *ptr = PlayList.GetPoint(i);
		cout << "\t\t  | (" << i+1 << ") " << ptr->GetName() << "\n\n"; //재생목록 이름 출력
	}

	cout << "\t      --- Quit: Enter \'0\' ---\n\n";
	cout << endl;
	CheckNum(command, 0, 5); //예외처리
	return command;
}

//나의 재생목록 관리
void Application::ManageMyPlayList() {
	int command;
	cout << "\t\t      *****" << endl << endl;
	cout << "\t\t  ===============" << endl;
	cout << "\t\t  | 나의 재생목록 |" << endl;
	cout << "\t\t  ===============" << endl << endl;

	command = SelectMyMuiscList();	//특정 재생목록에 접근할 인덱스 전달받음

	if (command == 0) {	//종료
		cout << "\n\t    |나의 재생목록 관리를 종료합니다|" << endl;
		return;
	}
	else { //해당 인덱스로 함수 호출
		SelectMyPlayList(command);
	}
}

//DetailPlayListGetCommand로부터 값을 받아 Queue를 이용해 해당 명령을 실행하는 함수.
void Application::ManageQueueList(Queue<SimpleMusicType>& Queue, string& str) {
	if (count == 0 || Queue.IsEmpty()) { //음악이 하나도 없거나 Queue가 비어있는 경우 종료
		cout << endl << "\t   |빈 음악리스트이므로 자동으로 종료합니다|" << endl;
		return;
	}
	else {
			while (1)
			{
				if (!Queue.IsEmpty()) {	//Queue가 비어있지 않을 때
					switch (DetailPlayListGetCommand(str))
					{
					case 1:	//현재 재생목록에 추가
						AddNowPlayListbyQue(Queue, 1);
						break;
					case 2: //나의 재생목록에 추가
						AddNowPlayListbyQue(Queue, 2);
						break;
					case 3:	//상세 정보 출력
						cout << "\n\t\t   ===| " << str << " |===" << endl;
						DisplayQueue(Queue);
						break;
					case 4: //모든 Queue 요소 삭제
						Queue.ResetQueue();
						cout << "\n\t    |" << str << "은 빈 리스트가 되었습니다|" << endl;
						break;
					case 0:
						cout << "\n\t    |" << str << " 관리를 종료합니다|" << endl;
						return;
					}
				}
				else {
					cout << endl << "\t   |빈 음악리스트이므로 자동으로 종료합니다|" << endl;
					return;
				}
			}
		
	}
}

//Queue내 요소를 MusicList에서 검색하여 자세한 정보 화면에 출력
void Application::DisplayQueue(Queue<SimpleMusicType>& Queue) {
	Queue.ResetList();
	SimpleMusicType f_temp;
	MusicType f_music;
	int idx;
	string m_Id;
	BinarySearchTree<MusicType> *m_ptr;
	bool found;
	while (Queue.GetNextItem(f_temp) != -1) {	 //리스트내 모든 요소에 접근
		m_Id = f_temp.GetNum();
		f_music.SetNum(m_Id);
		idx = GetMusicListIdx(m_Id);
		m_ptr = MusicList.GetPoint(idx);
		m_ptr->Retrieve(f_music, found);	//MusicList에서 해당 요소 찾음과 동시에 값을 전달받음
		if (found) {	//찾은 경우
			f_music.DisplayRecord();	//화면에 출력
		}
	}
}

//최다재생목록 관리
void Application::ManageMostPlayList() {
	if (count == 0 || MostPlayList.IsEmpty()) {//음악이 한 곡도 없거나 최다재생목록이 비어있는 경우
		cout << endl << "\t   |빈 음악리스트이므로 자동으로 종료합니다|" << endl;
		return;
	}
	else {
		int command;
		cout << "\n\t\t      *****" << endl << endl;
		cout << "\t\t  ===============" << endl;
		cout << "\t\t  | 최다재생목록 |" << endl;
		cout << "\t\t  ===============" << endl << endl;

		Iterator<InfMusic> iter(MostPlayList);
		DisplayAllnestedOrderBST(MostPlayList, iter, 2); //최다 재생 목록 내 모든 음악 간단히 출력

		while (1) {
			cout << "\n\t\t  | (1) 현재 재생목록 추가\n\n";
			cout << "\t\t  | (2) 나의 재생목록 추가\n\n";
			cout << "\t\t  | (3) 상세 정보 출력\n\n\n";
			cout << "\t      --- Quit: Enter \'0\' ---\n\n";

			CheckNum(command, 0, 3);

			if (!MostPlayList.IsEmpty()) { //리스트가 비어있지 않은 경우
				if (command == 1) {	//현재 재생목록 추가
					string temp = ""; 
					AddNowPlayListbyBSTInf("재생횟수", MostPlayList, temp, true);
				}
				else if (command == 2) {//나의 재생목록 추가
					string temp = "";
					AddMyMusicbyBSTInf("재생횟수", MostPlayList, temp, true);
				}
				else if (command == 3) { //상세정보 출력
					Iterator<InfMusic> iter(MostPlayList);
					DisplayAllnestedOrderBST(MostPlayList, iter, 1);
				}
				else { //종료
					cout << "\n\t    |최다재생목록 관리를 종료합니다 |" << endl;
					return;
				}
			}
			else {
				cout << endl << "\t   |빈 음악리스트이므로 자동으로 종료합니다|" << endl;
				return;
			}
		}
	}

}

//list(BST-InfMusic)의 항목을 현재 재생목록에 추가시키기 위해 동작하는 함수.
void Application::AddNowPlayListbyBSTInf(const string& str, BinarySearchTree<InfMusic>& list, string& input, const bool& Need) {
	if (!list.IsEmpty()) { //리스트가 비어있지 않은 경우
		cout << endl << endl;
		cout << "\n\t\t      *****" << endl << endl;
		cout << "\t\t  ====================" << endl;
		cout << "\t\t  | 현재 재생목록 추가 |" << endl;
		cout << "\t\t  ====================" << endl << endl;

		if (Need) { // infMusic의 primary key값을 할 input이 정해지지 않은 경우
			while (1) {
				cout << "\t  | 추가하려는 " << str << "을(를) 입력하시오(종료: \'q\'입력)|: ";
				getline(cin >> ws, input);

				if (input == "q") { //입력 종료
					cout << "\t    |" << str << " - 현재 재생목록 추가를 종료|" << endl << endl;
					return;
				}

				InfMusic TempType(input);
				bool found;
				list.Isthere(TempType, found); //BST<InfMusic> 리스트 내 해당 infmusic 정보 가진 요소 있나 검색
				if (!found) { //없는 경우
					cout << "\n\t    |\'" << input << "\' 를 가진 음악이 존재하지 않습니다|" << endl << endl;
					continue;
				}
				else { //있는 경우
					InfMusic *m_ptr;
					m_ptr = list.GetPoint(TempType);
					if (m_ptr->GetListLength() == 0) { //만약 해당 요소 내 한 곡도 없는 경우
						cout << "\n\t    |\'" << input << "\' 를 가진 음악이 존재하지 않습니다|" << endl << endl;
						continue;
					}
					break;
				}
			}
		}

		InfMusic MusicType(input);
		InfMusic *m_ptr;
		m_ptr = list.GetPoint(MusicType); //input을 갖는 InfMusic의 포인터 반환

		Iterator<SimpleMusicType> iter(m_ptr->GetAddrInf());
		AddAllNowPlayList(iter);//이 목록에서 음악을 재생목록에 추가
	}
	else {
		cout << endl << "\t   |빈 음악리스트이므로 자동으로 종료합니다|" << endl;
	}
}

//list(BST-InfMusic)의 항목을 나의 재생목록에 추가시키기 위해 동작하는 함수.
void Application::AddMyMusicbyBSTInf(const string& str, BinarySearchTree<InfMusic>& list, string& input, const bool& Need) {
	cout << endl << endl;
	cout << "\n\t\t      *****" << endl << endl;
	cout << "\t\t   ====================" << endl;
	cout << "\t\t  | 나의 재생목록 추가 |" << endl;
	cout << "\t\t   ====================" << endl << endl;

	if (Need) {// infMusic의 primary key값을 할 input이 정해지지 않은 경우
		while (1) {
			cout << "\t  | 추가하려는 " << str << "을(를) 입력하시오(종료: \'q\'입력)|: ";
			getline(cin >> ws, input);

			if (input == "q") { //종료
				cout << "\t    |" << str <<" - 나의 재생목록 추가를 종료|" << endl << endl;
			}
			InfMusic TempType(input);
			bool found;
			list.Isthere(TempType, found);
			if (!found) { //찾지 못한 경우
				cout << "\t    |\'" << input << "\' 를 가진 음악이 존재하지 않습니다|" << endl << endl;
				continue;
			}
			else { //찾은경우
				InfMusic *m_ptr;
				m_ptr = list.GetPoint(TempType);
				if (m_ptr->GetListLength() == 0) { //해당 요소 내 음악이 한 곡도 존재하지 않는 경우
					cout << "\n\t    |\'" << input << "\' 를 가진 음악이 존재하지 않습니다|" << endl << endl;
					continue;
				}
				break;
			}
		}
	}

	InfMusic MusicType(input);

	InfMusic *m_ptr;
	m_ptr = list.GetPoint(MusicType);	//input값 갖는 infmusic 포인터 반환
	Iterator<SimpleMusicType> iter(m_ptr->GetAddrInf());	//이 목록에서 음악을 재생목록에 추가

	
	int command = SelectMyMuiscList();	//나의 재생목록 중 특정 재생목록의 인덱스 반환
	if (command == 0) {	//0이면 종료
		cout << endl << "\t   |나의 재생목록 관리를 종료합니다|" << endl;
		return;
	}
	InfMusic *s_ptr;
	s_ptr = PlayList.GetPoint(command - 1); //음악이 추가될 나의 재생목록

	AddMyPlayListbyBST(iter, s_ptr, command-1);	 //해당 재생목록에 음악 추가

}

//좋아요 한 음악목록 관리
void Application::ManageHeartList() {
	if (count == 0|| HeartList.IsEmpty()) {//음악이 없거나 좋아요 목록이 비어있는 경우 종료
		cout << endl << "\t   |빈 음악리스트이므로 자동으로 종료합니다|" << endl;
		return;
	}
	else {
		int command;
		cout << "\n\t\t      *****" << endl << endl;
		cout << "\t\t  =====================" << endl;
		cout << "\t\t  | 좋아요 한 음악목록 |" << endl;
		cout << "\t\t  =====================" << endl << endl;
		HeartList.PrintTree(cout); //음악 목록 내 요소 간단히 출력
		

		while (1) {
			cout << "\n\t\t  | (1) 현재 재생목록 추가\n\n";
			cout << "\t\t  | (2) 나의 재생목록 추가\n\n";
			cout << "\t\t  | (3) 상세 정보 출력\n\n";
			cout << "\t\t  | (4) 선택 음악 좋아요 해제\n\n\n";
			cout << "\t      --- Quit: Enter \'0\' ---\n\n";

			CheckNum(command, 0, 4);

			if (!HeartList.IsEmpty()) { //비어있지 않은경우
				switch (command) {
				case 1: //현재 재생목록에 추가
					AddNowPlayListbyHeart();
					break;
				case 2: //나의 재생목록에 추가
					AddMyPlayListbyBSTSim(HeartList);
					break;
				case 3: //상세한 정보 출력
					cout << "\n\n\t   ===| 좋아요 한 음악 목록 |===" << endl;
					DisplayAllInfobySimpleFirst(HeartList);
					break;
				case 4: //선택음악 좋아요 해제
					SelectMusicUnHeart();
					break;
				case 0:
					cout << "\n\t    |좋아요 한 음악목록 관리를 종료합니다 |" << endl;
					return;
				}
			}
			else {
				cout << endl << "\t   |빈 음악리스트이므로 자동으로 종료합니다|" << endl;
				return;
			}
		}
	}
}

//s_temp로 id를 가져와  MusicType을 만들어 자세한 정보를 저장한 후, 각각 command에 맞게 리스트 추가,삭제 및 정보 변경을 함
void Application::UpdateInfor(SimpleMusicType& s_item, const int& command, const int& IsUnset) {
	string inTitle = s_item.GetNum();
	MusicType m_temp(inTitle);
	int m_idx = GetMusicListIdx(inTitle);

	BinarySearchTree<MusicType> *m_ptr;
	m_ptr = MusicList.GetPoint(m_idx); //MusicList 내 s_item의 아이디를 가진 음악이 존재할 요소의 포인터

	bool found;
	m_ptr->Retrieve(m_temp, found); //존재하는지 찾아봄
	if (found) {//리스트에서 발견한 경우
		s_item.SetTitle(m_temp.GetTitle());
		if (command >=0 && command <=4) {//재생목록관리
			if (IsUnset) {//제거 1->0
				string Inpl = m_temp.GetIsInPlaylist();
				Inpl[command] = '0'; //해당 음악의 재생목록 포함 여부 정보값 수정
				m_temp.SetIsInPlaylist(Inpl);

				InfMusic *in_ptr;
				in_ptr = PlayList.GetPoint(command); //해당 재생목록에 접근
				in_ptr->DeleteItem(s_item); //해당 음악 제거
			}
			else { //추가 0->1
				string Inpl = m_temp.GetIsInPlaylist();
				Inpl[command] = '1'; //해당 음악의 재생목록 포함 여부 정보값 수정
				m_temp.SetIsInPlaylist(Inpl);

				InfMusic *in_ptr;
				in_ptr = PlayList.GetPoint(command);//해당 재생목록에 접근
				in_ptr->AddItem(s_item);//해당 음악 추가
			}
		}
		else if (command == 5) { // 하트
			if (IsUnset) {//좋아요해제
				m_temp.SetHeart(false);
				HeartList.Delete(s_item);//좋아요 목록에서 삭제
			}
			else {//좋아요설정
				m_temp.SetHeart(true);
				//좋아요 목록 추가
				HeartList.Add(s_item);
			}
		}
		else { //재생횟수 추가
			int bef_count = m_temp.GetCount();
			int temp_c = m_temp.GetCount()+1;
			m_temp.SetCount(temp_c);

			//최근재생목록추가
			PlayRecentlyList.EnQueue(s_item);

			//최다재생목록추가
			if (bef_count != 0) {//처음 추가가 아닌 경우
				InfMusic *in_ptr;
				InfMusic bef_Type(to_string(bef_count));
				// 이전 목록에서 제거
				in_ptr = MostPlayList.GetPoint(bef_Type);
				in_ptr->DeleteItem(s_item);
			}
			InfMusic aft_Type(to_string(temp_c));

			InfMusic *o_ptr;
			//새로 추가 후, 해당 목록에 다시 추가

			if(MostPlayList.GetLength() != temp_c)
			{
				MostPlayList.Add(aft_Type);
			}

			o_ptr = MostPlayList.GetPoint(aft_Type);
			o_ptr->AddItem(s_item); //추가
			
		}
		m_ptr->Replace(m_temp); //변경
	}

}

//좋아요 선택적 해제.
void Application::SelectMusicUnHeart() {
	while (1) {
		string id;
		cout << "\n\t\t  |좋아요 해제 ID 입력(종료: \'q\')|: ";
		getline(cin >> ws, id);//변경할 음악의 id 입력받음

		if (id.compare("q") == 0) {	//"q"를 입력받은 경우 반복문 종료.
			cout << "\n\t  |사용자의 입력으로 변경 종료|" << endl;
			return;
		}
		else {
			SimpleMusicType del_simple(id);
			bool found;
			HeartList.Retrieve(del_simple, found); //좋아요 목록에 존재하는지 확인

			if (found) {
				UpdateInfor(del_simple, 5, true);	//좋아요 해제
				cout << "\n\t    |\'" << id << "\' 를 좋아요를 해제하였습니다|" << endl << endl;
			}
			else {
				cout << "\n\t    |\'" << id << "\' 를 가진 음악이 존재하지 않습니다|" << endl << endl;
			}
		}
	}
}

//m_list(BST-SimpleMT)를 이용해 iterator를 생성해 DisplayAllInfobySimple 함수에 전달하기 위한 함수.
void Application::DisplayAllInfobySimpleFirst(BinarySearchTree<SimpleMusicType>& m_list) {
	Iterator<SimpleMusicType> iter(m_list);	//iterator 생성
	DisplayAllInfobySimple(iter);	//함수 호출
}

//iter를 이용해 InOreder방식을 이용해 재귀적으로 앞서 m_list내의 항목의 상세한 정보를 검색해 화면에 출력.
void Application::DisplayAllInfobySimple(Iterator<SimpleMusicType> iter) {
	if(iter.IsNotNull()) {
		//Inorder방식
		DisplayAllInfobySimple(iter.MoveLeft()); //왼쪽이동

		SimpleMusicType temp = iter.GetCurrentdata(); //현재 요소의 정보 받아옴
		string id = temp.GetNum(); //id
		MusicType f_music(id); // id정보만을 가진 musictype 생성

		int m_idx = GetMusicListIdx(id);//해당 id가 있을법한 musiclist요소의 인덱스 반환
		BinarySearchTree<MusicType> *m_ptr;
		m_ptr = MusicList.GetPoint(m_idx);	//해당 요소의 포인터

		bool found;
		m_ptr->Retrieve(f_music, found); //검색
		if (found) {//찾은 경우
			f_music.DisplayRecord();	//자세한 정보 출력
		}
		DisplayAllInfobySimple(iter.MoveRight()); //오른쪽 이동
	}
}

//BST-SimpleMusicType의 list내 모든 요소를 내 재생목록 내 특정 리스트에 추가.(PreOrder 방식)
void Application::AddMyPlayListbyBST(Iterator<SimpleMusicType> iter, InfMusic*& list, int com) {
	if (iter.IsNotNull()) {
		SimpleMusicType temp = iter.GetCurrentdata(); //정보받아옴
		string m_Id = temp.GetNum();
		
		bool duple;
		duple = list->SearchItem(temp);//list내 m_List에 해당 정보를 가진음악 존재하는지 판별

		if (!duple) {//존재 안하는 경우
			if (list->AddItem(temp)) { //추가

				BinarySearchTree<MusicType> *m_ptr = MusicList.GetPoint(GetMusicListIdx(m_Id));
				MusicType m_temp(m_Id);
				bool found;
				m_ptr->Retrieve(m_temp, found); //MusicList에서 자세한 정보 받아옴

				if (found) {//찾은경우
					string Inpl = m_temp.GetIsInPlaylist();
					Inpl[com] = '1'; 
					m_temp.SetIsInPlaylist(Inpl);
					m_ptr->Replace(m_temp); //정보수정하여 해당음악에 적용되도록 변경
				}

				cout << endl << "\t    |\"" << m_Id << "\" 파일 추가|" << endl;
			}
		}
		else {
			cout << endl << "\t    |\"" << m_Id << "\" 은 이미 재생목록 내 존재합니다|" << endl;
		}
		AddMyPlayListbyBST(iter.MoveLeft(), list, com);		//왼쪽이동
		AddMyPlayListbyBST(iter.MoveRight(), list, com);	//오른쪽이동
	}

}

//BST-SimpleMusicType의 list내 모든 요소를 내 재생목록 내 특정 리스트에 추가.
void Application::AddMyPlayListbyBSTSim(BinarySearchTree<SimpleMusicType>& list) {
	int command;
	command = SelectMyMuiscList(); //특정 리스트의 인덱스 반환
	if (command == 0) {//0이면 종료
		cout << endl << "\t   |나의 재생목록 관리를 종료합니다|" << endl;
		return;
	}
	Iterator<SimpleMusicType> iter(list);

	InfMusic *s_ptr;
	s_ptr = PlayList.GetPoint(command - 1);	//해당 리스트의 포인터

	AddMyPlayListbyBST(iter, s_ptr, command-1);	//함수호출
}

//좋아요 한 목록의 모든 요소를 현재 재생목록에 저장함
void Application::AddNowPlayListbyHeart() {
	if (!HeartList.IsEmpty()) { //비어있지 않다면
		Iterator<SimpleMusicType> iter(HeartList);
		AddAllNowPlayList(iter); //함수 호출해 좋아요 목록의 요소를 현재 재생목록에 저장
	}
	else {
		cout << endl << "\t   |빈 음악리스트|" << endl;
	}
}

//재생목록 관리 함수 호출
void Application::ManagePlayList() {
	string str;
	while (1)
	{
		switch (PlaylistGetCommnad())
		{
		case 1:// 나의 재생목록 관리
			ManageMyPlayList();
			break;
		case 2: //최근 추가목록 관리
			str = "최근추가목록";
			ManageQueueList(AddRecentlyList,str);
			break;
		case 3: //최근 재생목록 관리
			str = "최근재생목록";
			ManageQueueList(PlayRecentlyList, str);
			break;
		case 4:// 최다 재생목록 관리
			ManageMostPlayList();
			break;
		case 5://좋아요 한 목록 관리
			ManageHeartList();
			break;
		case 0:
			cout << "\n\t    |재생목록 관리를 종료합니다|" << endl;
			return;
		}
	}
}

//현재 재생목록 관리
void Application::ManageNowPlayList() {
	if (count == 0 || NowPlayList.IsEmpty()) { //음악이 없거나 리스트가 비어있는 경우 종료
		cout << "\n\t|빈 재생목록이므로 자동으로 종료합니다|" << endl;
		return;
	}
	int command;

	cout << "\n\t\t      *****" << endl << endl;
	cout << "\t\t  =================" << endl;
	cout << "\t\t  | 현재 재생목록 |" << endl;
	cout << "\t\t  =================" << endl << endl;

	cout << "\n\n\t   ===| 현재 재생목록 |===" << endl;
	NowPlayList.PrintTree(cout); //음악 목록 간단히 출력

	cout << "\n\t    ----------------------------------" << endl;

	cout << "\n\t\t  | (1) 전체 재생\n\n";
	cout << "\t\t  | (2) 나의 재생목록 추가\n\n";
	cout << "\t\t  | (3) 선택 음악 삭제\n\n";
	cout << "\t\t  | (4) 재생목록 비우기\n\n";
	cout << "\t\t  | (5) 상세 정보 출력\n\n\n";
	cout << "\t      --- Quit: Enter \'0\' ---\n\n";


	CheckNum(command, 0, 5); //입력

	if (command == 0) {
		cout << "\n\t    |현재재생목록 관리를 종료합니다|" << endl;
		return;
	}
	else if (command == 1) { //전체 재생
		//delete np_iter; //임시 재생 저장소 가리키는 포인터도 삭제
		//t_NowPlayList.MakeEmpty();	//임시 재생 저장소(Circular doubly unsorted linked list)
		cout << "\n\t|♩ ♩♪♬ ♩♪♬ 음악 재생중 ♩♪♬ ♩♪♬ ♩♪♬|" << endl;
		IsPlaying = true; //재생중 알림
		//임시리스트에 모두 저장
		Iterator<SimpleMusicType> iter(NowPlayList);
		AddTempNPL(iter, true); //현재 재생목록 내 모든 음악의 count 수 증가
		np_iter = new DoublyIterator<SimpleMusicType>(t_NowPlayList); //포인터 재 동적할당
	}
	else if (command == 2) { //나의 재생목록 추가
		AddMyPlayListbyBSTSim(NowPlayList);
	}
	else if (command == 3) { //선택음악 삭제
		IsPlaying = false; //음악 재생중 종료
		t_NowPlayList.MakeEmpty(); //임시 재생 저장소 삭제
		delete np_iter;//포인터 삭제

		SelectMusicListSimpleDelete(NowPlayList); //선택 삭제
	}
	else if (command == 4) { //재생목록 비우기
		NowPlayList.MakeEmpty(); //현재 재생목록 요소 모두 삭제
		t_NowPlayList.MakeEmpty(); //임시 저장소 삭제
		delete np_iter; //포인터 삭제
		IsPlaying = false; //음악 재생중 종료
		cout << "\n\t    |현재 재생목록을 모두 삭제하였습니다|" << endl;
	}
	else {//상세정보 출력
		cout << "\n\n\t   ===| 현재 재생목록 |===" << endl;
		DisplayAllInfobySimpleFirst(NowPlayList);
	}
}

//사용자로부터 음악 아이디를 입력받아 m_List 내 해당 아이디를 가진 요소를 제거.
void Application::SelectMusicListSimpleDelete(BinarySearchTree<SimpleMusicType>& m_List){
	if (!m_List.IsEmpty()) {
		SimpleMusicType userDel;
		string temp;
		while (1) {
			cout << "\n\t\t  |삭제 ID 입력 (종료: \'q\')|: ";
			getline(cin >> ws, temp);
			userDel.SetNum(temp);		//삭제할 음악의 id 입력받음

			if (userDel.GetNum().compare("q") == 0) {	//"q" 를 입력받은 경우 0리턴하며 종료.
				cout << "\n\t    |사용자의 입력으로 종료|" << endl;
				return;
			}
			else {
				bool duple;
				m_List.Retrieve(userDel, duple); //리스트에서 해당 id가진 음악 존재여부

				if (!duple) { //없는경우
					cout << "\n\t    |\'" << userDel.GetNum() << "\' 를 가진 음악은 재생목록 내 없습니다|" << endl << endl;
					return;
				}
				else { //있는경우
					m_List.Delete(userDel); //삭제
					cout << "\n\t\t  |\'" << userDel.GetNum() << "\' 삭제완료|" << endl << endl;
				}
			}
		}
	}
	else {
		cout << "\n\t   |빈 리스트 입니다| ";
		return;
	}

}

//iter가 가리키는 리스트 내 모든 요소의 count값을 +1한 후, 해당 모든 요소를 PreOrder의 방식으로 t_NowPlayList에 저장.
void Application::AddTempNPL(Iterator<SimpleMusicType> iter, const bool& IsPlay) {
	if (iter.IsNotNull()) {
		SimpleMusicType temp;
		temp = iter.GetCurrentdata();
		if (IsPlay) {
			UpdateInfor(temp, 6, IsPlay); //음악 카운트 값 증가
		}

		t_NowPlayList.Add(temp); //임시 재생 저장소에 음악 요소 추가

		AddTempNPL(iter.MoveLeft(), IsPlay); //왼쪽이동
		AddTempNPL(iter.MoveRight(), IsPlay); //오른쪽 이동
	}
}

//음악 재생 명령어 출력
int Application::PlayGetCommand(const bool&inHeart, const char*filename) {
	int command;
	cout << endl << endl;
	//filename을 이용해 해당 음악 재생
	PlaySound(TEXT(filename), NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);
	

	cout << "\t-----------------------------------\n";
	cout << "\t (1)이전곡<< |일시정지| >>(2)다음곡" << endl;
	cout << "\t-----------------------------------\n\n";

	if (!inHeart) { //좋아요 해제되어 있으면
		cout << "\t\t  | (3) 좋아요 설정\n\n";
	}
	else { //좋아요 설정되어 있으면
		cout << "\t\t  | (4) 좋아요 해제\n\n";
	}
	cout << "\t\t  | (5) 상세정보\n\n";
	cout << "\t      --- Quit: Enter \'0\' ---\n\n";


	//잘못된 명령어 입력시 예외처리
	CheckNum(command, 0, 5);
	return command;
}

//메인출력화면 내 간단히 음악 재생 정보 출력.
void Application::PlayingMusic(bool& IsPlaying) {
	if (IsPlaying) { //재생중인 경우
		if (!b) { //재생인자가 false인 경우
			ManagePlayingMusic(0);	//MusicItem을 초기화하기 위한 함수호출
			b = true;//true로 값 변경
		}
		//화면 출력
		cout << "\t---- " << MusicItem.GetTitle() << " ----"  << " | " << MusicItem.GetTime() << endl;
	}
	else {
		b = false;
		cout << "\t\t      <NONE>" << endl;
	}
}

//사용자의 음악 프로그램 사용 패턴을 분석해 화면에 출력
void Application::MyMusic() {
	//가장 많이 들은 음악
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
		most_m = "\t  |---선호하는 곡 불분명---|\n";
	}

	//선호하는 아티스트
	Iterator<InfMusic> iter(ArtistList);

	int i_temp = 0;
	string temp = "";
	Favorite(iter, i_temp, temp);


	//즐겨듣는 장르
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

	//출력
	cout << "\n\t\t       *****\n";
	cout << "\n\t  | 당신의 음악 취향을 분석하겠습니다 |\n\n";
	if (i_gen == 0) {
		cout << "\t  |---선호하는 장르 불분명---|\n";
	}
	else {
		cout << "\n\t  | 당신이 선호하는 장르: ";
		Sleep(500);
		cout << max_gen << endl;
		Sleep(500);
	}

	if (i_temp == 0) {
		cout << "\n\t  |---선호하는 가수 불분명---|\n";
	}
	else {
		cout << "\n\t  | 당신이 선호하는 가수: ";
		Sleep(500);
		cout << temp << endl;
		Sleep(500);
	}
	
	if (s_size == 0) {
		cout << endl << most_m;
	}
	else {
		cout << "\n\t  | 당신이 선호하는 곡: ";
		Sleep(500);
		cout << most_m << endl;
		Sleep(1200);
	}
}

//재귀적, BST-SimpleMT 가진 리스트 요소 중 가장 좋은 요소를 선정.
void Application::Favorite(Iterator<InfMusic> iter, int& i_temp, string& temp) {
	if (iter.IsNotNull()) { 

		InfMusic *st_ptr = ArtistList.GetPoint(iter.GetCurrentdata());
		int size =st_ptr->GetPointInf()->GetLength(); //한 아티스트의 곡 갯수 계산
		if (i_temp < size) { //개수비교
			i_temp = size;
			temp = iter.GetCurrentdata().GetName(); //가장 큰 아티스트 이름 저장
		}

		Favorite(iter.MoveLeft(), i_temp, temp); //왼쪽이동
		Favorite(iter.MoveRight(), i_temp, temp); //오른쪽이동
	}
}

//재생중인 음악에 대한 정보 출력
void Application::DisplayPlayingMusic(MusicType& m_temp) {
	cout << endl << endl;

	cout << "\t\t      *****" << endl << endl;
	cout << "\t\t  | 음악 재생 |" << endl;
	cout << "\t    ----------------------------\n" << endl;

	cout << "\t    | "<< m_temp.GetTitle() <<" ("<< m_temp.GetArtist() <<")|";

	cout << "\n\t\t        *" << endl << endl;

	cout << "\t      "<< m_temp.GetLyrics()<< endl;

	cout << "\n\t    --------| "<< m_temp.GetTime()<<" |---------" << endl << endl;

	cout << "\t     ";
	m_temp.DisplayHeart();

}

//재생중인 음악에 대한 관리.
void Application::ManagePlayingMusic(const int& command) {
	if (!IsPlaying) {
		cout << "\t\t      <NONE>" << endl;
		return;
	}
	SimpleMusicType temp;
	temp = np_iter->GetCurrentdata(); //현재 포인터가 가리키는 음악 전달받음
	MusicType m_temp;
	if (b) {
		m_temp = MusicItem;
	}
	bool found;
	PlayingMusicGetMT(temp, m_temp, found);
	if (!b) {//초기화되지 않은 경우
		MusicItem = m_temp; //MusicItem을 전달받은 음악으로 초기화
	}


	if (command!=0) {
		if (found) { //MusicList내 재생중인 음악 존재할 때
			int com;
			while (1) {
				DisplayPlayingMusic(m_temp);	//재생중인 음악 정보 화면 출력
				bool inHeart = m_temp.GetHeart();

				string fn = m_temp.GetFilename();

				com = PlayGetCommand(inHeart, fn.c_str());	//명령값 입력받음
				PlaySound(NULL, 0, 0); //음악재생파일종료
				//시각적 효과
				cout << "\t\t      ***" << endl;
				Sleep(500);
				cout << "\t\t      ***" << endl;
				Sleep(700);
				if (com == 1) { //이전 곡으로 이동
					temp = np_iter->Prev(); //포인터 이전으로 이동시킴
					PlayingMusicGetMT(temp, m_temp, found); //정보가져옴
					UpdateInfor(temp, 6, false); //재생횟수 증가
					MusicItem = m_temp;
				}
				else if (com == 2) { //다음곡으로 이동
					temp = np_iter->Next(); //포인터 다음으로 이동시킴
					PlayingMusicGetMT(temp, m_temp, found); //정보가져옴
					UpdateInfor(temp, 6, false);//재생횟수 증가
					MusicItem = m_temp;
				}
				else if (com == 3) { //좋아요 설정
					UpdateInfor(temp, 5, false);
					cout << endl << "\t   |좋아요 설정했습니다|" << endl;
					PlayingMusicGetMT(temp, m_temp, found);
				}
				else if (com == 4) {//좋아요 해제
					UpdateInfor(temp, 5, true);
					cout << endl << "\t   |좋아요 해제했습니다|" << endl;
					PlayingMusicGetMT(temp, m_temp, found);
				}
				else if (com == 5) { //해당 음악에 대한 상세 정보 출력
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

//temp의 아이디를 이용해 MusicList내 해당 인덱스에 접근 후, 해당 BST에서 m_temp에 대한 자세한 정보를 가져옴.
void Application::PlayingMusicGetMT(SimpleMusicType& temp, MusicType& m_temp, bool& found) {
	string id = temp.GetNum();
	m_temp.SetNum(id);

	int m_idx = GetMusicListIdx(id); //인덱스
	BinarySearchTree<MusicType> *m_ptr = MusicList.GetPoint(m_idx);
	m_ptr->Retrieve(m_temp, found); //정보 찾아서 가져옴
}

//언더바가 포함된 아티스트에서 구별
void Application::SplitArtist(string arr[], string& artist) {
	int idx = 0;
	string str;
	for (int i = 0;i < artist.length();i++) {
		if (artist[i] == '_') {//언더바인 경우
			arr[idx] = str;
			idx++;
			str.clear();
		}
		else {
			str += artist[i];
		}
	}
	arr[idx] = str; //구별된 아티스트 배열에 추가
}

//사용자로부터 정보를 입력받아 리스트에 추가
int Application::AddMusicFromUser() {
	//사용자로부터 정보 입력받음
	MusicType userAdd;
	userAdd.SetRecordFK();

	bool IsUser = true;

	if (AddMusic(userAdd, IsUser)) {	// AddMusic함수 사용
		return 1;	//성공적으로 추가 시 1을 리턴
	}
	else {
		return 0;	//추가에 실패하면 0을 리턴
	}

}

//음악 리스트에 새로운 데이터 추가
int Application::AddMusic(MusicType userAdd, const bool &IsUser) {

	string userT = userAdd.GetTitle();
	string userA = userAdd.GetArtist();
	//id를 음악 제목과 가수명 조합으로 자동설정.
	string m_ID = userT + "_" + userA;
	userAdd.SetNum(m_ID);

	bool duple = false;


	int idx = GetMusicListIdx(userT);
	BinarySearchTree<MusicType> *m_idx;
	m_idx = MusicList.GetPoint(idx);

	
	m_idx->Retrieve(userAdd, duple);
	

	if (duple) { //중복인 경우 사용자에게 알려준 후 0을 리턴.
		cout << endl << "\t   |제목: " << userT << ", 가수: " << userA << "] 이미 리스트 내 존재|" << endl;
		return 0;
	}
	else {	//중복이 아닌 경우 MusicList추가
		int button;
		button = m_idx->Add(userAdd);
		//button = MusicList.Add(userAdd);


		if (button) { //MusicList에 성공적 추가시
			count++;
			//SimpleMusictype 생성
			SimpleMusicType add_Simple(m_ID, userT);

			//Genre
			string genre = userAdd.GetGenre();

			//GenreList 내 GenreMusicList에 추가
			//장르 아이디 받아오기
			int g_idx = SetGenreId(genre);

			InfMusic *ptr;
			ptr = GenreList.GetPoint(g_idx);
			ptr->AddItem(add_Simple);



			//Artist ====> 아티스트 분류해서 추가
			string artist = userAdd.GetArtist();


			int icount = CountUnderVarArtist(artist);
			string *arr = new string[icount + 1];

			SplitArtist(arr, artist);
			for (int i = 0;i < icount+1;i++) {
				//InfType=>Artist명으로
				InfMusic ArtistType(arr[i]);
				//ArtistList 추가
				ArtistList.Add(ArtistType);
				//ArtistList 내 ArtistMusicList에 추가
				ptr = ArtistList.GetPoint(ArtistType);
				ptr->AddItem(add_Simple);
			}

			//Album
			//InfType=>Album명으로
			InfMusic AlbumType(userAdd.GetAlbum());
			//AlbumList 추가
			AlbumList.Add(AlbumType);
			//ArtistList 내 ArtistMusicList에 추가
			ptr = AlbumList.GetPoint(AlbumType);
			ptr->AddItem(add_Simple);
			
			//최근추가목록
			AddRecentlyList.EnQueue(add_Simple);


			if (IsUser) {
				cout << endl << "\t    \"" << userAdd.GetNum() << "\" 파일을 성공적으로 추가하였습니다." << endl;
			}
			return 1;	//데이터 추가에 성공하면 1을 리턴.
		}
		else {
			cout << endl << "\t    \"" << userAdd.GetNum() << "\" 파일 추가에 실패하였습니다." << endl;
			return 0;	//정보 추가에 실패하면 0을 리턴.
		}
	}
}

void Application::DeleteMusicFromUser() {
	//삭제할 음악의 id 입력받아 MusicType생성
	MusicType userDel;
	bool IsUser = true;

	while (1) {
		cout << "\n\t\t  |삭제 ID 입력 (종료: \'q\')|\n\n";
		userDel.SetNumFK();		//삭제할 음악의 id 입력받음

		if (userDel.GetNum().compare("q") == 0) {	//"q" 를 입력받은 경우 0리턴하며 종료.
			cout <<"\n\t    |사용자의 입력으로 종료|" << endl;
			break;
		}
		else {

			if (DeleteMusic(userDel, IsUser)) {	// DeleteMusic함수 사용
			}
			else {
				cout << "\t    |\'" << userDel.GetNum() << "\' 를 가진 음악이 존재하지 않습니다|" << endl << endl;
			}
		}
	}
	
}

//찾을 음악의 number를 사용자에게 입력받고 해당 정보 제거.
int Application::DeleteMusic(MusicType userDel, const bool &IsUser) {
	if (count == 0) {	//음악리스트가 비어있으면 0을 리턴 후 종료.
		cout << endl << "\t   |빈 음악리스트이므로 자동으로 종료합니다|" << endl;
		return 0;
	}
	else {	//음악리스트에 요소가 하나이상 존재하는 경우
		bool duple = false;

		string tmp_id = userDel.GetNum();
		int idx = GetMusicListIdx(tmp_id);
		BinarySearchTree<MusicType> *m_idx;
		m_idx = MusicList.GetPoint(idx);

		m_idx->Retrieve(userDel, duple);//검색

		if (!duple) {
			cout << endl << "\t[ " << tmp_id << " ] 음악은 이미 리스트 내 존재하지 않습니다." << endl;
			return 0;
		}
		else {	//중복인 경우 삭제
			int button;
			button = m_idx->Delete(userDel);

			if (button) {
				count--;
				//받아온 정보로 SimpleMusicType 생성
				SimpleMusicType del_Simple(userDel.GetNum());

				//Genre내 삭제
				//InfType=>Genre명으로
				//GenreList 내 GenreMusicList에서 삭제
				
				InfMusic *ptr;

				int g_idx = SetGenreId(userDel.GetGenre());
				ptr = GenreList.GetPoint(g_idx);
				ptr->DeleteItem(del_Simple);


				//Artist내 삭제
				//InfType=>Artist명으로
				string artist = userDel.GetArtist();

				//artistList 내 ArtistMusicList에서 삭제
				int icount = CountUnderVarArtist(artist);
				string *arr = new string[icount + 1];

				//아티스트 분류
				SplitArtist(arr, artist);
				for (int i = 0;i < icount + 1;i++) {
					//InfType=>Artist명으로
					InfMusic ArtistType(arr[i]);
					ptr = ArtistList.GetPoint(ArtistType);
					ptr->DeleteItem(del_Simple);
					if (ptr->GetListLength() == 0) {
						ArtistList.Delete(ArtistType);
					}
				}

				//Album내 삭제
				//InfType=>Artist명으로
				InfMusic AlbumType(userDel.GetAlbum());

				//GenreList 내 GenreMusicList에서 삭제
				ptr = AlbumList.GetPoint(AlbumType);
				ptr->DeleteItem(del_Simple);

				if (ptr->GetListLength() == 0) {
					AlbumList.Delete(AlbumType);
				}

				//좋아요 목록에 있는가
				if (userDel.GetHeart()) {
					HeartList.Delete(del_Simple);
				}

				//재생한적이 있는가
				int del_count = userDel.GetCount();
				if (del_count != 0) {	//최다재생 목록에서 삭제
					string del_scount = to_string(del_count);
					InfMusic Count(del_scount);
					ptr = MostPlayList.GetPoint(Count);
					ptr->DeleteItem(del_Simple);
				}

				//나의 재생목록에 있는가
				string InPL = userDel.GetIsInPlaylist();
				for (int i = 0;i < 5;i++) {
					if (InPL[i] == '1') { //있는 경우 삭제
						InfMusic *in_ptr;
						in_ptr = PlayList.GetPoint(i);
						in_ptr->DeleteItem(del_Simple);
					}
				}

				//현재재생목록에 있는가
				bool found;
				NowPlayList.Retrieve(del_Simple, found);
				if (found) {
					NowPlayList.Delete(del_Simple);
				}

				IsPlaying = false; //음악 재생 중단
				t_NowPlayList.MakeEmpty(); //임시 재생 저장소 삭제
				delete np_iter; //포인터 삭제

				
				cout << endl << "\n\t    |\"" << userDel.GetNum() << "\" 파일을 삭제하였습니다|" << endl;
				return 1;	//정보 삭제에 성공하면 1을 리턴.
			}
			else {
				cout << endl << "\n\t    |\"" << userDel.GetNum() << "\" 파일 삭제에 실패하였습니다|" << endl;
				return 0;	//삭제에 실패하면 0을 리턴.
			}

		}
	}
}


//갱신하고자 하는 음악 정보를 사용자로부터 입력받아 갱신.
int Application::ReplaceMusic() {
	if (count == 0) {//음악리스트가 비어있으면 0을 리턴 후 종료.
		cout << endl << "\t   |빈 음악리스트이므로 자동으로 종료합니다|" << endl;
		return 0;
	}
	else {
		//변경할 음악의 id 입력받아 MusicType 생성
		//단, 제목과 가수명은 바꿀 수 없음. (장르, 앨범, 가사 등만 변경 가능)
		MusicType userRep;
		bool ex = false;

		BinarySearchTree<MusicType> *m_ptr;
		string re_id;
		while (1) {
			cout << "\n\t\t  |변경 ID 입력|" << endl<<endl;
			userRep.SetNumFK();		//변경할 음악의 id 입력받음
			re_id = userRep.GetNum();
			if (re_id.compare("q") == 0) {	//"q"를 입력받은 경우 0리턴하며 종료.
				cout << "\n\t  |사용자의 입력으로 변경 종료|" << endl;
				return 0;
			}
			else {
				
				m_ptr = MusicList.GetPoint(GetMusicListIdx(re_id));
				//MusicList에서 검색후, 자세 정보 받아옴
				m_ptr->Retrieve(userRep, ex);
				if (!ex) {	//해당 num을 가진 음악을 찾을 수 없는 경우.
					cout << "\n\t    |\'" << userRep.GetNum() << "\' 를 가진 음악이 존재하지 않습니다. /종료: q를 입력/|" << endl << endl;
				}
				else {
					break;
				}
			}
		}
		string b_genre = userRep.GetGenre();	//변경 전 장르 저장
		string b_album = userRep.GetAlbum();	//변경 전 앨범 저장

		// 변경하고자 하는 데이터 사용자로부터 입력받음
		cout << "\n\t  |변경 정보 입력|\n\n";
		userRep.SetGenreFK();
		userRep.SetAlbumFK();
		userRep.SetLyricsFK();

		userRep.SetReleaseDFK();
		userRep.SetComposerFK();
		userRep.SetLyricistFK();
		userRep.SetFilenameFK();
		userRep.SetTimeFK();


		int button;
		button = m_ptr->Replace(userRep);	//MusicList에서 먼저 변경

		if (button) {	//변경이 잘 된 경우
			bool gen = true;
			bool alb = true;
			string a_genre = userRep.GetGenre();
			string a_album = userRep.GetAlbum();
			//Genre변경된 경우
			if (b_genre.compare(a_genre) != 0) {
				gen = false;
			}
			//Album변경된 경우
			if (b_album.compare(a_album) != 0) {
				alb = false;
			}

			if (gen&&alb) {	//장르와 앨범 모두 변경되지 않은 경우
				cout << endl << "\n\t    \"" << userRep.GetNum() << "\" 파일을 변경하였습니다." << endl;
				return 1;
			}
			else {
				//받아온 정보로 SimpleMusicType 생성
				SimpleMusicType del_Simple(userRep.GetNum());

				if (!gen) { //장르 변경된 경우

					//GenreList 내 GenreMusicList에서 삭제
					InfMusic *genre_ptr;
					genre_ptr = GenreList.GetPoint(SetGenreId(b_genre));
					genre_ptr->DeleteItem(del_Simple);

					//해당 장르의 GenreMusicList에 추가
					genre_ptr = GenreList.GetPoint(SetGenreId(a_genre));
					genre_ptr->AddItem(del_Simple);
				}

				//Album
				if (!alb) { //앨범 변경된 경우
					//InfType=>Album명으로
					InfMusic AlbumType(b_album);

					//AlbumList 내 AlbumMusicList에서 삭제
					InfMusic *album_ptr;
					album_ptr = AlbumList.GetPoint(AlbumType);
					album_ptr->DeleteItem(del_Simple);

					InfMusic NAlbumType(a_album);
					//AlbumList 추가
					AlbumList.Add(NAlbumType);

					//해당 앨범의 AlbumMusicList에 추가
					album_ptr = AlbumList.GetPoint(NAlbumType);
					album_ptr->AddItem(del_Simple);
				}
			}

			cout << endl << "\n\t    |\'" << userRep.GetNum() << "\' 파일을 변경하였습니다|" << endl;
			return 1;	//정보변경에 성공하면 1을 리턴.
		}
		else {
			cout << endl << "\n\t    |\'" << userRep.GetNum() << "\' 파일 변경에 실패하였습니다|" << endl;
			return 0;	//변경에 실패하면 0을 리턴.
		}

	}
}

//리스트에 있는 음악을 primary key를 이용해 검색한다.
int Application::SearchByName(MusicType& item) {
	if (MusicList.IsEmpty()) { //리스트가 비어있는지 확인.
		cout << endl << "\t   |빈 음악리스트이므로 자동으로 종료합니다|" << endl;
		return 0; //빈 리스트이면 메시지를 출력한 후 0을 리턴한다.
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
		else { //찾지 못했을 경우 메시지를 출력한다.
			cout << endl << "\t    |해당 조건에 맞는 단어를 찾지 못했습니다| \n\n";
		}

		if (result) {
			DetailManageSearchMusicList(m_list);
			return 1;
		}
		else
			return 0;
	}
}

//str내 inString 카테고리에서 list를 이용해 명령을 처리함.
int Application::SearchByBSTInfDetail(BinarySearchTree<InfMusic>& list, const string& str, string& inString) {

	//리스트에서 검색
	InfMusic TempType(inString);
	InfMusic *ptr;
	ptr = list.GetPoint(TempType);

	if (ptr == NULL) {
		cout << endl << "\n\t \"" << inString << "\"을(를) 찾을 수 없습니다." << endl;
		return 0;
	}
	else {
		int command;
		while (1) {
			command = DetailManageSerachGetCommand(inString); //명령값 받아옴

			if (command == 0) {
				cout << endl << "\n\t |" << str << " 음악 검색 종료|" << endl;
				return 0;
			}
			else if (command == 1) { //상세출력
				string s = "";
				ptr->SearchDisplay(1, MusicList, s);
			}
			else if (command == 2) { //현재 재생목록 추가
				AddNowPlayListbyBSTInf("", list, inString, false);
			}
			else if (command == 3) { //나의 재생목록 추가
				AddMyMusicbyBSTInf("", list, inString, false);
			}
			else { //세부검색
				string found;
				BinarySearchTree<SimpleMusicType> temp_list; //검색 결과를 임시로 저장할 리스트
				if (!ptr->SearchAddDisplay(found, temp_list)) { //특정 단어를 이용한 검색
					cout << endl << "\n\t \'" << found << "\' 을(를) 포함한 음악을 찾을 수 없습니다." << endl;
					return 0;
				}
				else {// 임시로 저장한 리스트 이용 다시 관리
					DetailManageSearchMusicList(temp_list);
				}
			}
		}
		return 1;
	}
}

//재생목록 추가 또는 정보출력을 위한 명령어를 선택.
int Application::DetailSearchMusicListGetCommand() {
	int command;
	cout << "\n\n\t\t  | (1) 현재 재생목록 추가\n\n";
	cout << "\t\t  | (2) 나의 재생목록 추가\n\n";
	cout << "\t\t  | (3) 상세 정보 출력\n\n\n";

	cout << "\t      --- Quit: Enter \'0\' ---\n\n";
	CheckNum(command, 0, 3);
	return command;
}

//DetailSearchMusicListGetCommand로부터 명령값을 받아와 해당 명령값에 대한 동작 실행.
void Application::DetailManageSearchMusicList(BinarySearchTree<SimpleMusicType>& m_list) {
	while (1) {
		if (!m_list.IsEmpty()) { //비어있지 않은 경우
			int command=DetailSearchMusicListGetCommand(); //명령값 받아옴
			if (command == 1) { //현재 재생목록에 추가
				Iterator<SimpleMusicType> iter(m_list);
				AddAllNowPlayList(iter);
			}
			else if (command == 2) { //나의 재생목록에 추가
				int com;
				com = SelectMyMuiscList(); //특정 재생목록 선택
				if (com == 0) {//0이면 종료
					cout << endl << "\t   |음악 검색을 종료합니다|" << endl;
					return;
				}
				Iterator<SimpleMusicType> iter(m_list);

				InfMusic *s_ptr;
				s_ptr = PlayList.GetPoint(com - 1);// 접근

				AddMyPlayListbyBST(iter, s_ptr, com-1);
			}
			else if (command == 3) { //상세정보출력
				DisplayAllInfobySimpleFirst(m_list);
			}
			else {
				cout << endl << "\t   |음악 검색을 종료합니다|" << endl;
				return;
			}

		}
		else {
			cout << endl << "\t   |선택된 음악이 없으므로 종료합니다|" << endl;
			return;
		}
	}
}

//아티스트 변수 내 언더 바 갯수 카운트
int Application::CountUnderVarArtist(string& inArtist) {
	int icount = 0;
	for (int i = 0;i < inArtist.length();i++) {
		if (inArtist[i] == '_') {
			icount++;
		}
	}
	return icount;
}

//리스트에 있는 음악을 아티스트를 이용해 검색한다.
int Application::SearchByArtist() {
	int ccount = 0;

	cout << "\n   |찾고자 하는 아티스트 입력|: ";
	string f_artist;
	getline(cin >> ws, f_artist); //사용자로부터 입력받음


	int icount = CountUnderVarArtist(f_artist);
	string *arr = new string[icount + 1]; //언더바 갯수로 구분한 아티스트 저장할 배열 동적할당하여 생성

	SplitArtist(arr, f_artist);
	for (int i = 0;i < icount + 1;i++) {
		if (SearchByBSTInfDetail(ArtistList, "아티스트", arr[i])) //검색
			ccount++;
	}
	
	if (ccount)
		return 1;
	else
		return 0;
}

//리스트에 있는 음악을 앨범을 이용해 검색한다.
int Application::SearchByAlbum() {

	cout << "\n   |찾고자 하는 앨범명 입력|: ";
	string f_album;
	getline(cin >> ws, f_album);

	return SearchByBSTInfDetail(AlbumList, "앨범", f_album);
}

//리스트에 있는 음악을 장르를 이용해 검색한다.
int Application::SearchByGenre() {

	cout << "\n   |찾고자 하는 장르 입력|: ";
	string f_genre;
	getline(cin >> ws, f_genre);

	//장르 리스트에서 검색
	int g_idx = SetGenreId(f_genre);

	InfMusic *genre_ptr;
	genre_ptr = GenreList.GetPoint(g_idx);


	if (genre_ptr->GetListLength() == 0) {
		cout << endl << "\t \'" << f_genre << "\' 장르를 가진 음악이 존재하지 않습니다." << endl;
		return 0;
	}
	else {
		while (1) {
			int command = DetailManageSerachGetCommand(f_genre); //해당 장르 리스트에서 어떤 동작을 할 지 선택.

			if (command == 0) {	//종료
				cout << endl << "\t 장르 음악 검색을 종료합니다." << endl;
				break;
			}
			else if (command == 1) { //해당 장르 모든 정보 자세히 출력
				string s = "";
				genre_ptr->SearchDisplay(1, MusicList, s);
			}
			else if (command == 2) {//해당 장르 현재 재생목록 추가
				cout << endl << endl;
				cout << "\n\t\t      *****" << endl << endl;
				cout << "\t\t  ====================" << endl;
				cout << "\t\t  | 현재 재생목록 추가 |" << endl;
				cout << "\t\t  ====================" << endl << endl;

				Iterator<SimpleMusicType> iter(genre_ptr->GetAddrInf());	//이 목록에서 음악을 재생목록에 추가

				AddAllNowPlayList(iter);
			}
			else if (command == 3) {//해당 장르 나의 재생목록 추가
				cout << endl << endl;
				cout << "\n\t\t      *****" << endl << endl;
				cout << "\t\t   ====================" << endl;
				cout << "\t\t  | 나의 재생목록 추가 |" << endl;
				cout << "\t\t   ====================" << endl << endl;

				Iterator<SimpleMusicType> iter(genre_ptr->GetAddrInf());	//이 목록에서 음악을 재생목록에 추가

				int command = SelectMyMuiscList();
				if (command == 0) {
					cout << endl << "\t   |나의 재생목록 관리를 종료합니다|" << endl;
					break;
				}
				InfMusic *s_ptr;
				s_ptr = PlayList.GetPoint(command - 1); //음악이 추가될 나의 재생목록

				AddMyPlayListbyBST(iter, s_ptr, command - 1);
			}
			else {//세부검색
				string f_title;
				BinarySearchTree<SimpleMusicType> temp_list;
				if (!genre_ptr->SearchAddDisplay(f_title,temp_list)) { //특정 단어를 제목에 포함한 음악을 찾지 못한 경우
					cout << endl << "\t \'" << f_title << "\' 을(를) 포함한 음악을 찾을 수 없습니다." << endl;
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
	if (count == 0) {	//빈 리스트인 경우
		cout << endl << "\t   |빈 음악리스트이므로 자동으로 종료합니다|" << endl;
	}
	else {	//빈 리스트가 아니면 전제 데이터 출력
		MusicType data;

		cout << "\n\t   ===| 전체 음악 목록 |===" << endl;

		// list의 모든 데이터를 화면에 출력
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

//자동으로 파일에서 정보 읽어옴
void Application::AutoReadFile() {
	char filename[] = { "auto" };
	ReadDataFromFile(filename);
}

//사용자로부터 파일이름 입력받아 해당 파일에서 정보 읽어옴
void Application::ReadFile() {
	char filename[FILENAMESIZE];
	cout << "\n\t |가져올 파일 이름| : ";
	cin >> filename;
	ReadDataFromFile(filename);
}

// Open a file as a read mode, read all data on the file, and set list by the data.
int Application::ReadDataFromFile(char *filename)
{
	//int index = 0;
	MusicType data;	// 읽기용 임시 변수


	// file open, open error가 발생하면 0을 리턴
	if (!OpenInFile(filename)) {
		cout << endl << "\t\" " << filename << "\" 파일을 열지 못했습니다." << endl;
		return 0;
	}

	bool IsUser = false;	//User 입력으로 데이터 생성하는 것이 아니므로 false 설정.
	int icount = 0;
	// 파일의 모든 내용을 읽어 list에 추가
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

		if (AddMusic(data, IsUser)) {	//모든 리스트에 파일에서 가져온 정보 추가
			icount++;
		}
	}

	m_InFile.close();	// file close

	cout << endl << "\t\"" << filename << "\" 파일로부터 " << icount << "개의 데이터를 성공적으로 추가하였습니다." << endl;

	return 1;
}


// Open a file as a write mode, and write all data into the file,
int Application::WriteDataToFile()
{
	if (count == 0) {
		cout << endl << "\t작성 가능한 데이터가 존재하지 않습니다." << endl;
		return 0;
	}
	else {
		MusicType data;	// 쓰기용 임시 변수

		char filename[FILENAMESIZE];
		cout << "\n\t |저장할 파일 이름| : ";
		cin >> filename;

		// file open, open error가 발생하면 0을 리턴
		if (!OpenOutFile(filename)) {
			cout << endl << "\t\" " << filename << "\" 파일을 열지 못했습니다." << endl;
			return 0;
		}


		int totalcount = 0;
		for (int i = 0;i < MusicList.GetLength();i++) {
			int icount = 0;
			Iterator<MusicType> iter(MusicList.GetAddr(i));
			WritePreOrder(iter, icount);
			totalcount += icount;
		}

		cout << endl << "\t\"" << filename << "\" 파일에 " << totalcount << "개의 데이터를 성공적으로 추가하였습니다." << endl;
		m_OutFile.close();	// file close


		return 1;
	}

}

//PreOrder 방식으로 BST내 모든 데이터 파일에 작성.
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

//iterator를 이용해 tree 내 특정 data를 가진 노드의 정보 출력
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