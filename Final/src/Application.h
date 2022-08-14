#ifndef _APPLICATION_H
#define _APPLICATION_H

#include "Queue.h"
#include "InfMusic.h"
#include "DoublyLinkedList.h"


#include <Windows.h>
#include <mmsystem.h>
#include <conio.h>
#include <iostream>
#include <string>
#include <fstream>
#include <atlstr.h>

#pragma comment(lib, "winmm.lib")
using namespace std;


#define FILENAMESIZE 1024

/**
*	application class for item management simply.
*/
class Application
{
public:
	/**
	*	default constructor.
	*/
	Application();

	/**
	*	destructor.
	*/
	~Application();

	/**
	*	@brief	Program driver.
	*	@pre	program is started.
	*	@post	program is finished.
	*/
	void Run();

	/**
	*	@brief	genre로 해당 genre number를 찾아 리턴한다.
	*	@pre	genre is set.
	*	@post	genre로 일치하는 해당 genre number를 찾아 리턴한다.
	*	@param	genre	genre number를 찾으려는 genre명
	*	@return	해당 장르명에 맞는 genre number를 리턴하고, 일치하는 장르명이 없을 시, 11을 리턴(기타장르)한다.
	*/
	int SetGenreId(const string& genre);

	/**
	*	@brief	item의 id 생성
	*	@pre	id값을 제외한 나머지 item의 정보가 채워져 있어야 함.
	*	@post	item의 id값이 채워지
	*	@param	item	id를 생성하고자 하는 데이터.
	*/
	void SetMusicId(MusicType& item);

	/**
	*	@brief	inCommand가 int인지, int이면 해당 명령번호가 존재하는지 판별하여 사용자로부터 올바른 값을 입력받음.
	*	@pre	none.
	*	@post	inCommand에 올바른 입력값이 전달됨.
	*	@param	inCommand	사용자로부터 입력받아 전달되는 값.
	*	@param	a			최소명령번호.
	*	@param	b			최대명령번호.
	*/
	void CheckNum(int& inCommand, const int&a, const int&b);

	/**
	*	@brief	Display command on screen and get a input from keyboard.
	*	@pre	none.
	*	@post	none.
	*	@return	user's command.
	*/
	int MainGetCommand();

	/**
	*	@brief	전체, 장르, 아티스트, 앨범 등 카테고리를 나누어 음악을 검색.
	*	@pre	none.
	*	@post	none.
	*/
	void SearchMusic();

	/**
	*	@brief	음악 관리(추가, 삭제, 변경, 파일읽기, 파일저장)를 위한 함수.
	*	@pre	none.
	*	@post	none.
	*/
	void ManageMusic();

	/**
	*	@brief	재생 목록 관리(최근추가, 최근재생, 최다재생, 사용자 재생)를 위한 함수.
	*	@pre	none.
	*	@post	none.
	*/
	void ManagePlayList();
	
	/**
	*	@brief	재생목록에 대한 관리를 위한 명령어를 선택.
	*	@pre	none.
	*	@post	none.
	*	@param	content		재생목록 주체.
	*	@return	선택한 명령에 대한 command값을 반환.
	*/
	int DetailPlayListGetCommand(const string&content);


	/**
	*	@brief	여러 카테고리의 상세한 검색을 위한 명령어를 선택.
	*	@pre	none.
	*	@post	none.
	*	@param	content		검색할 카테고리.
	*	@return	선택한 명령에 대한 command값을 반환.
	*/
	int DetailSerachGetCommand(const string&content);

	/**
	*	@brief	해당 content 내에서의 음악 리스트 관리 혹은 정보 출력 명령어 선택.
	*	@pre	none.
	*	@post	none.
	*	@param	content		검색할 카테고리.
	*	@return	선택한 명령에 대한 command값을 반환.
	*/
	int DetailManageSerachGetCommand(const string&content);

	/**
	*	@brief	재생목록 추가 또는 정보출력을 위한 명령어를 선택.
	*	@pre	none.
	*	@post	none.
	*	@return	선택한 명령에 대한 command값을 반환.
	*/
	int DetailSearchMusicListGetCommand();

	/**
	*	@brief	DetailSearchMusicListGetCommand로부터 명령값을 받아와 해당 명령값에 대한 동작 실행.
	*	@pre	none.
	*	@post	none.
	*	@param	m_list	검색, 혹은 명령을 수행할 주체가 되는 리스트.
	*/
	void DetailManageSearchMusicList(BinarySearchTree<SimpleMusicType>& m_list);

	/**
	*	@brief	메인 음악검색(전체, 장르, 아티스트, 앨범)을 위한 선택 명령어 입력받아 반환.
	*	@pre	none.
	*	@post	none.
	*	@return	선택한 명령에 대한 command값을 반환.
	*/
	int SearchGetCommand();

	/**
	*	@brief	m_list에 대해 command를 통해 재귀적으로 해당 리스트에 관한 정보를 출력.(Inorder형식)
	*	@pre	none.
	*	@post	화면에 원하는 정보가 출력됨.
	*	@param	m_list	검색하고자 하는 리스트
	*	@param	b_iter	InfMusic의 name정보를 가져오기 위한 Iterator.
	*	@param	command	1이면 m_list의 상세한 정보를 찾아 출력, 2이면 m_list의 간단한 음악 정보만 출력, 나머지 숫자는 InfMusic의 name만을 출력
	*/
	void DisplayAllnestedBST(BinarySearchTree<InfMusic>& m_list, Iterator<InfMusic> b_iter, const int& command);

	/**
	*	@brief	m_list에 대해 command를 통해 재귀적으로 해당 리스트에 관한 정보를 출력.(내림차순)
	*	@pre	none.
	*	@post	화면에 원하는 정보가 출력됨.
	*	@param	m_list	검색하고자 하는 리스트
	*	@param	b_iter	InfMusic의 name정보를 가져오기 위한 Iterator.
	*	@param	command	1이면 m_list의 상세한 정보를 찾아 출력, 2이면 m_list의 간단한 음악 정보만 출력, 나머지 숫자는 InfMusic의 name만을 출력
	*/
	void DisplayAllnestedOrderBST(BinarySearchTree<InfMusic>& m_list, Iterator<InfMusic> b_iter, const int& command);

	/**
	*	@brief	list(BST-InfMusic)의 항목을 나의 재생목록에 추가시키기 위해 동작하는 함수.
	*	@pre	none.
	*	@post	나의 재생목록 내 정보가 추가됨.
	*	@param	str		리스트의 카테고리
	*	@param	list	검색하고자 하는 리스트.
	*	@param	input	추가하려는 InfMusic의 name으로 Need에 따라 사용자로부터 해당 함수내에서 입력받거나, 파라미터로 전달받은 값 바로 사용 가능.
	*	@param	Need	true이면 사용자에게 직접 input값을 해당 함수 내에서 입력받고, Need가 아니면 바로 input값 함수에 사용.
	*/
	void AddMyMusicbyBSTInf(const string& str, BinarySearchTree<InfMusic>& list, string& input, const bool& Need);

	/**
	*	@brief	list(BST-InfMusic)의 항목을  현재 재생목록에 추가시키기 위해 동작하는 함수.
	*	@pre	none.
	*	@post	나의 재생목록 내 정보가 추가됨.
	*	@param	str		리스트의 카테고리
	*	@param	list	검색하고자 하는 리스트.
	*	@param	input	추가하려는 InfMusic의 name으로 Need에 따라 사용자로부터 해당 함수내에서 입력받거나, 파라미터로 전달받은 값 바로 사용 가능.
	*	@param	Need	true이면 사용자에게 직접 input값을 해당 함수 내에서 입력받고, Need가 아니면 바로 input값 함수에 사용.
	*/
	void AddNowPlayListbyBSTInf(const string& str, BinarySearchTree<InfMusic>& list, string& input, const bool& Need);


	/**
	*	@brief	m_list(BST-SimpleMT)를 이용해 iterator를 생성해 DisplayAllInfobySimple 함수에 전달하기 위한 함수.
	*	@pre	none.
	*	@post	none.
	*	@param	m_list	Iterator로 검색하기 위한 리스트.
	*/
	void DisplayAllInfobySimpleFirst(BinarySearchTree<SimpleMusicType>& m_list);

	/**
	*	@brief	iter를 이용해 InOreder방식을 이용해 재귀적으로 앞서 m_list내의 항목의 상세한 정보를 검색해 화면에 출력.
	*	@pre	none.
	*	@post	상세한 정보 목록 화면에 출력됨.
	*	@param	iter	검색 및 출력하고자 하는 함수를 가리키는 iterator.
	*/
	void DisplayAllInfobySimple(Iterator<SimpleMusicType> iter);

	/**
	*	@brief	한글, 영어, 숫자 및 기타로 구분된 0~12의 인덱스를 inTitle의 첫번째 값으로 비교해 해당하는 인덱스 값 반환.
	*	@pre	none.
	*	@post	none.
	*	@param	inTitle		MusicList내에서 몇 번째 인덱스를 가졌는지 알아보기 위한 변수.
	*	@return	해당 inTitle에 맞는 MusicList 내 인덱스 반환.
	*/
	int GetMusicListIdx(string& inTitle);

	/**
	*	@brief	좋아요 목록 중, 좋아요를 해지하려는 요소의 ID값을 입력받아 해당 요소의 좋아요 해지 및 해당 리스트에서 삭제됨.
	*	@pre	none.
	*	@post	선택된 요소의 좋아요 값이 변경되며, 좋아요 목록에서 삭제됨.
	*/
	void SelectMusicUnHeart();


	/**
	*	@brief	메인 음악관리(직접추가, 자동추가, 삭제, 변경, 파일입출력)를 위한 명령어를 출력해, 사용자로부터 입력받아 반환하는 함수.
	*	@pre	none.
	*	@post	none.
	*	@return	사용자로부터 입력받은 명령어 반환.
	*/
	int ManageGetCommand();

	/**
	*	@brief	메인 재생목록 관리(나의 재생, 최근추가,최근재생, 최다재생, 좋아요)를 위한 명령어를 출력해, 사용자로부터 입력받아 반환하는 함수.
	*	@pre	none.
	*	@post	none.
	*	@return	사용자로부터 입력받은 명령어 반환.
	*/
	int PlaylistGetCommnad();


	/**
	*	@brief	음악 재생에 필요한 명령어 출력 및 해당 음악 재생 후, 명령값을 사용자로부터 입력받아 반환하는 함수.
	*	@pre	none.
	*	@post	none.
	*	@param	inHeart		해당 음악의 좋아요 여부 전달
	*	@param	filename	해당 음악의 파일이름
	*	@return	사용자로부터 입력받은 명령어 반환.
	*/
	int PlayGetCommand(const bool& inHeart, const char *filename);

	/**
	*	@brief	사용자의 음악 플레이어 사용패턴을 분석해 화면에 출력.
	*	@pre	none.
	*	@post	사용패턴이 화면에 출력됨.
	*/
	void MyMusic();

	/**
	*	@brief	BST-SimpleMT 가진 리스트 요소 중 가장 좋은 요소를 선정.
	*	@pre	none.
	*	@post	none.
	*	@param	iter		해당 리스트를 가리키는 iterator
	*	@param	i_temp		가장 좋은 요소의 갯수
	*	@param	temp		가장 좋은 요소의 이름
	*/
	void Favorite(Iterator<InfMusic> iter, int& i_temp, string& temp);

	/**
	*	@brief	artist를 언더바로 구분해 arr 배열에 저장
	*	@pre	none.
	*	@post	arr배열 내 요소가 추가됨
	*	@param	arr		구분된 아티스트를 저장하기 위한 배열.
	*	@param	artist	언더바로 구분하기 위한 아티스트 원형.
	*/
	void SplitArtist(string arr[], string& artist);


	/**
	*	@brief	현재 음악이 재생되고 있으면 메인 화면에서 간단 정보 출력하는 함수.
	*	@pre	음악이 재생되고 있어야함.
	*	@post	none.
	*	@param	IsPlaying	음악이 현재 재생되고 있는지 구분하는 변수.	
	*/
	void PlayingMusic(bool& IsPlaying);

	/**
	*	@brief	PlayGetCommand로부터 값을 받아 음악재생에서 해당 명령을 실행하는 함수.
	*	@pre	현재 재생목록 존재.
	*	@post	none.
	*	@param	command		해당 명령어로 iterator가 다시 초기화 되지 않도록 조절//아직 수정 필요
	*/
	void ManagePlayingMusic(const int& command);

	/**
	*	@brief	DetailPlayListGetCommand로부터 값을 받아 Queue를 이용해 해당 명령을 실행하는 함수.
	*	@pre	none.
	*	@post	none.
	*	@param	Queue	해당 리스트 내 요소를 이용.
	*	@param	str		카테고리를 나타내는 변수.
	*/
	void ManageQueueList(Queue<SimpleMusicType>& Queue, string& str);

	/**
	*	@brief	최다재생목록에 대한 명령어를 출력하고 입력받은 후, 해당 명령을 실행하는 함수로 최다재생목록을 관리함.
	*	@pre	none.
	*	@post	none.
	*/
	void ManageMostPlayList();

	/**
	*	@brief	현재재생목록에 대한 명령어를 출력하고 입력받은 후, 해당 명령을 실행하는 함수로 현재재생목록을 관리함.
	*	@pre	none.
	*	@post	none.
	*/
	void ManageNowPlayList();

	
	/**
	*	@brief	SelectMyMuiscList로부터 명렁값을 입력받은 후, 0이 아닌 값을 SelectMyPlayList로 전달하는 함수.
	*	@pre	none.
	*	@post	none.
	*/
	void ManageMyPlayList();

	/**
	*	@brief	command를 이용해 해당 순번의 빈 재생목록에 접근하여 해당 재생목록에 대한 관리를 시행.
	*	@pre	none.
	*	@post	none.
	*	@param	command	나의 재생목록 중 관리하고자 하는 순번의 재생목록.
	*/
	void SelectMyPlayList(int& command);

	/**
	*	@brief	command값에 해당하는 나의 재생목록에 대한 Iterator를 생성해 AddAllNowPlayList함수를 호출.
	*	@pre	none.
	*	@post	none.
	*	@param	command	나의 재생목록 중 관리하고자 하는 순번의 재생목록.
	*/
	void AddNowPlayListManage(int& command);

	/**
	*	@brief	나의 재생목록 리스트의 이름을 사용자에게 출력하여 보여준 후, 이 중 관리하고자 하는 리스트의 번호를 입력받음.
	*	@pre	none.
	*	@post	none.
	*	@return 나의 재생목록 중 관리하고자 하는 재생목록의 번호 반환.
	*/
	int SelectMyMuiscList();


	/**
	*	@brief	MusicList에서 QueueList내 요소에 대한 자세한 정보를 검색해 모든 정보를 화면에 출력해주는 함수..
	*	@pre	none.
	*	@post	none.
	*	@param	Queue	자세한 정보를 출력하고 하는 QueueList.
	*/
	void DisplayQueue(Queue<SimpleMusicType>& Queue);

	/**
	*	@brief	현재 재생되고 있는 한 음악에 대한 정보를 출력.
	*	@pre	none.
	*	@post	none.
	*	@param	item	현재 재생되고 있는 음악.
	*/
	void DisplayPlayingMusic(MusicType& item);

	/**
	*	@brief	temp의 아이디를 이용해 MusicList내 해당 인덱스에 접근 후, 해당 BST에서 m_temp에 대한 자세한 정보를 가져옴.
	*	@pre	none.
	*	@post	m_temp에 대한 자세한 정보 추가됨.
	*	@param	temp	ID를 가진 변수.
	*	@param	m_temp	temp의 ID를 이용해 MusicList에서 해당 ID의 자세한 정보를 받을 변수.
	*	@param	found	m_temp를 찾았을 경우 true, 아니면 false값을 가짐.
	*/
	void PlayingMusicGetMT(SimpleMusicType& temp, MusicType& m_temp, bool& found);

	/**
	*	@brief	iter가 가리키는 리스트 내 모든 요소의 count값을 +1한 후, 해당 모든 요소를 PreOrder의 방식으로 t_NowPlayList에 저장.
	*	@pre	none.
	*	@post	iter가 가리키는 요소의 count값 증가 및 t_NowPlayList에 요소 추가됨.
	*	@param	iter	재생하면서 임시 재생목록에 담기 위한 리스트를 가리키는 iterator.
	*	@param	IsPlay	UpdateInfor함수에 사용될 파라미터.
	*/
	void AddTempNPL(Iterator<SimpleMusicType> iter, const bool& IsPlay);

	/**
	*	@brief	좋아요 한 목록에 대한 명령어를 출력하고 입력받은 후, 해당 명령을 실행하는 함수로 좋아요 한 목록을 관리함.
	*	@pre	none.
	*	@post	none.
	*/
	void ManageHeartList();

	/**
	*	@brief	나의 재생목록 중 command순번에 해당하는 재생목록 내 모든 요소를 현재 재생목록에 추가(중복검사 함)
	*	@pre	none.
	*	@post	현재 재생목록에 요소 추가됨.
	*	@param	command		나의 재생목록 중 한 리스트의 순번.
	*/
	void AddNowPlayList(int& command);

	/**
	*	@brief	Queue-SimpleMusicType을 가진 Queue내 모든 요소를 command값에 따라 다른 특정 목록에 추가됨.
	*	@pre	none.
	*	@post	특정 리스트 내 요소 추가.
	*	@param	Queue		해당 리스트 내 요소가 다른 리스트에 추가됨.
	*	@param	command		1이면 현재재생목록에, 나머지 숫자는 나의 재생목록 중 추가하고자 하는 순번을 받아와 해당 리스트에 저장.
	*/
	void AddNowPlayListbyQue(Queue<SimpleMusicType>& Queue, const int& command);

	/**
	*	@brief	좋아요 한 목록의 모든 요소를 현재 재생목록에 저장함.
	*	@pre	none.
	*	@post	현재 재생목록에 요소 추가됨.
	*/
	void AddNowPlayListbyHeart();

	/**
	*	@brief	BST-SimpleMusicType의 list내 모든 요소를 내 재생목록 내 특정 리스트에 추가.
	*	@pre	none.
	*	@post	none.
	*	@param	list	특정 리스트에 추가하고자 하는 요소를 가진 리스트.
	*/
	void AddMyPlayListbyBSTSim(BinarySearchTree<SimpleMusicType>& list);

	/**
	*	@brief	BST-SimpleMusicType의 list내 모든 요소를 내 재생목록 내 특정 리스트에 추가.
	*	@pre	none.
	*	@post	none.
	*	@param	iter	리스트의 요소에 접근하는 iterator.
	*	@param	list	특정 리스트에 추가하고자 하는 요소를 가진 리스트.
	*	@param	com		특정 리스트의 순번.
	*/
	void AddMyPlayListbyBST(Iterator<SimpleMusicType> iter, InfMusic*& list, int com);


	/**
	*	@brief	나의 재생목록 중 특정 목록을 가리키는 iter를 이용해 현재 재생목록에 추가.
	*	@pre	현재 재생목록 존재.
	*	@post	현재 재생목록에 추가
	*	@param	iter	리스트의 요소에 접근하는 iterator.
	*/
	void AddAllNowPlayList(Iterator<SimpleMusicType> iter);


	/**
	*	@brief	s_temp로 id를 가져와  MusicType을 만들어 자세한 정보를 저장한 후, 각각 command에 맞게 리스트 추가,삭제 및 정보 변경을 함
	*	@pre	none.
	*	@post	리스트 혹은 음악 요소 일부 정보 변경.
	*	@param	s_item		Id를 가진 변수.
	*	@param	command		0~4면 나의 재생목록 해당 인덱스 내 추가 혹은 제거, 5이면 좋아요 여부 따라 추가, 제거, 그 외의 숫자는 재생횟수 증가 및 관련 리스트 내 추가
	*	@param	IsUnset		true면 제거, false면 추가. 재생횟수 증가는 해당 변수에 영향을 받지 않음.
	*/
	void UpdateInfor(SimpleMusicType& s_item, const int& command, const int& IsUnset);

	/**
	*	@brief	사용자로부터 음악 아이디를 입력받아 m_List 내 해당 아이디를 가진 요소를 제거.
	*	@pre	m_List존재
	*	@post	m_List내에서 특정 요소 삭제
	*	@param	m_List		해당 리스트에서 입력받은 아이디 가진 요소 제거.
	*/
	void SelectMusicListSimpleDelete(BinarySearchTree<SimpleMusicType>& m_List);

	/**
	*	@brief	사용자로부터 추가하고자 하는 정보를 입력받아 AddMusic함수에 true값과 함께 전달해 리스트에 새로운 레코드 추가.
	*	@pre	리스트 존재.
	*	@post	새로운 레코드가 리스트에 추가됨.
	*	@return	잘 추가되면 1을, 아니면 0을 리턴함.
	*/
	int AddMusicFromUser();

	/**
	*	@brief	리스트에 새로운 레코드 추가.
	*	@pre	리스트 존재.
	*	@post	IsUser가 true면 중복 검사를 하며, 새로운 레코드가 리스트에 추가됨.
	*	@param	userAdd	추가하려는 데이터
	*	@param	IsUser	User입력으로 데이터를 생성한건지 아닌지 가리키는 값.
	*	@return	잘 추가되면 1을, 아니면 0을 리턴함.
	*/
	int AddMusic(MusicType userAdd, const bool &IsUser);


	/**
	*	@brief	리스트에서 기존 레코드 삭제.
	*	@pre	리스트 존재.
	*	@post	리스트에 존재하는 기존 레코드가 리스트에서 삭제됨.
	*	@param	userDel	삭제하려는 데이터
	*	@param	IsUser	User입력으로 데이터를 생성한건지 아닌지 가리키는 값.
	*	@return	잘 삭제되면 1을, 아니면 0을 리턴함.
	*/
	int DeleteMusic(MusicType userDel, const bool &IsUser);


	/**
	*	@brief	사용자에게 삭제할 정보를 입력받아 DeleteMusic함수에 넘겨주는 역할을 한다.
	*	@pre	리스트 내 음악 정보 존재.
	*	@post	사용자가 입력한 num을 가지고 있는 정보가 모든 리스트에서 사라짐.
	*	@return	잘 제거되면 1을, 아니면 0을 리턴함.
	*/
	void DeleteMusicFromUser();

	/**
	*	@brief	사용자에게 num을 입력받아 Replace함수에 넘겨주는 역할을 한다.
	*	@pre	리스트 내 음악 정보 존재.
	*	@post	사용자가 입력한 num을 가지고 있는 정보가 모든 리스트에서 갱신함.
	*	@return	잘 변경되면 1을, 아니면 0을 리턴함.
	*/
	int ReplaceMusic();


	/**
	*	@brief	객체를 생성 후, 찾고자 하는 Title을 입력받는다.
	*	@pre	없다.
	*	@post	find 함수를 이용해 입력받은 Title과 일치하는 음악 정보가 존재하는지 찾아 출력한다.(단, 검색어가 곡명에 포함된다면 출력한다.)
	*	@return 일치하는 항목을 찾은 경우 1을 리턴하고, 그렇지 않으면 0을 리턴한다.
	*/
	int SearchByName(MusicType & item);

	/**
	*	@brief	객체를 생성 후, 찾고자 하는 Artist를 입력받는다.
	*	@pre	없다.
	*	@post	find 함수를 이용해 입력받은 Artist와 일치하는 음악 정보가 존재하는지 찾아 출력한다.(단, 검색어가 가수명에 포함된다면 출력한다.)
	*	@return 일치하는 항목을 찾은 경우 1을 리턴하고, 그렇지 않으면 0을 리턴한다.
	*/
	int SearchByArtist();



	/**
	*	@brief	str내 inString 카테고리에서 list를 이용해 명령을 처리함.
	*	@pre	없다.
	*	@post	없다.
	*	@param	list		해당 list로 특정 함수를 통해 전달받은 명령값이 수행되도록 함.
	*	@param	str			큰 카테고리
	*	@param	inString	세부 카테고리
	*	@return 일치하는 항목을 찾은 경우 1을 리턴하고, 그렇지 않으면 0을 리턴한다.
	*/
	int SearchByBSTInfDetail(BinarySearchTree<InfMusic>& list, const string& str, string& inString);

	/**
	*	@brief	아티스트 내 존재하는 언더바 갯수 계산.
	*	@pre	없다.
	*	@post	없다.
	*   @param  inArtist	아티스트 변수.
	*	@return 언더바의 갯수를 반환.
	*/
	int CountUnderVarArtist(string& inArtist);

	/**
	*	@brief	객체를 생성 후, 찾고자 하는 Album을 입력받는다.
	*	@pre	없다.
	*	@post	없다.
	*/
	int SearchByAlbum();

	/**
	*	@brief	객체를 생성 후, 찾고자 하는 Genre를 입력받는다.
	*	@pre	없다.
	*	@post	없다.
	*/
	int SearchByGenre();

	/**
	*	@brief	Display all records in the musiclist on screen.
	*	@pre	none.
	*	@post	none.
	*/
	void DisplayAllMusic();

	/**
	*	@brief	Open a file by file descriptor as an input file.
	*	@pre	a file for reading is exist.
	*	@post	open the file for reading.
	*	@param	fileName	a filename to open for reading.
	*	@return	return 1 if this function works well, otherwise 0.
	*/
	int OpenInFile(char *fileName);

	/**
	*	@brief	Open a file by file descriptor as an output file.
	*	@pre	list should be initialized.
	*	@post	open the file for writing.
	*	@param	fileName	a filename to open for writing.
	*	@return	return 1 if this function works well, otherwise 0.
	*/
	int OpenOutFile(char *fileName);

	/**
	*	@brief	미리 입력된 파일명을 이용해 파일을 읽음.
	*	@pre	none.
	*	@post	none.
	*/
	void AutoReadFile();

	/**
	*	@brief	 파일명을 사용자로부터 입력받아 불러옴.
	*	@pre	none.
	*	@post	none.
	*/
	void ReadFile();

	/**
	*	@brief	Open a file as a read mode, read all data on the file, and set list by the data.
	*	@pre	The file is not opened.
	*	@post	list holds all records from the file.
	*	@param	filename	읽고자 하는 파일명.
	*	@return	return 1 if this function works well, otherwise 0.
	*/
	int ReadDataFromFile(char *filename);

	/**
	*	@brief	Open a file as a write mode, and write all data into the file,
	*	@pre	The file is not opened.
	*	@post	the list is stored in the output file.
	*	@return	return 1 if this function works well, otherwise 0.
	*/
	int WriteDataToFile();


	/**
	*	@brief	PreOrder 방식으로 BST내 모든 데이터 파일에 작성.
	*	@pre	리스트 존재하며, 작성하고자 하는 특정 파일 열려있어야 함.
	*	@post	파일에 리스트 내 데이터의 정보 작성
	*	@param	iter	Tree 내부를 탐색할 iterator.
	*	@param	count	몇개의 data를 작성했는지에 대한 정보.
	*/
	void WritePreOrder(Iterator<MusicType> iter, int& count);


	/**
	*	@brief	iterator를 이용해 tree 내 특정 data를 가진 노드의 정보 출력.
	*	@pre	리스트 존재.
	*	@post	없음.
	*	@param	iter	Tree 내부를 탐색할 iterator.
	*	@param	temp	찾아야 하는 정보를 가진 MusicType
	*	@param	found	data 찾았는지 판별 여부
	*	@param	m_list	찾은 데이터 형식을 SimpleMusicType으로 바꾸어 임시 저장하여 전달
	*/
	void SearchTree(Iterator<MusicType> iter, MusicType& temp, bool& found, BinarySearchTree<SimpleMusicType>& m_list);


	
private:
	ifstream m_InFile;										///< input file descriptor.
	ofstream m_OutFile;										///< output file descriptor.


	SortedList<BinarySearchTree<MusicType>> MusicList;		///< 모든 음악 정보 가진 리스트.
	SortedList<InfMusic> GenreList;							///< 장르별로 정리한 리스트

	BinarySearchTree<InfMusic> ArtistList;					///< 아티스트별로 정리한 리스트
	BinarySearchTree<InfMusic> AlbumList;					///< 앨범별로 정리한 리스트


	Queue<SimpleMusicType> AddRecentlyList;					///<최근추가목록
	Queue<SimpleMusicType> PlayRecentlyList;				///<최근재생목록

	BinarySearchTree<InfMusic> MostPlayList;				///<최다재생목록

	SortedList<InfMusic> PlayList;							///<재생목록
	BinarySearchTree<SimpleMusicType> HeartList;			///<좋아요 한 리스트

	BinarySearchTree<SimpleMusicType> NowPlayList;			///<현재재생목록
	DoublyLinkedList<SimpleMusicType> t_NowPlayList;		///<현재재생목록 재생용

	DoublyIterator<SimpleMusicType> *np_iter;

	MusicType MusicItem;									///< 재생할 음악 정보


	bool IsPlaying;				///< 재생 누르면 true되어서 화면에 어떤 곡이 몇분동안 얼마나 플레이되고 잇는지 표시됨, PlayingMusic의 파라미터
	bool b;						///< 음악 재생을 위한 변수
	int count;					///< 전체 음악 갯수
	int m_Command;				///< current command number.

};


#endif // !_APPLICATION_H

