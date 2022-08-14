#ifndef _APPLICATION_H
#define _APPLICATION_H

#include "InfMusic.h"
#include "Queue.h"
#include "LinkedList.h"
#include <iostream>
#include <fstream>
#include <ctime>
#include <cmath>
using namespace std;

#define FILENAMESIZE 1024

/**
*	application class for item management simply.
*/
class Application {
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
	*	@brief	Display command on screen and get a input from keyboard.
	*	@pre	none.
	*	@post	none.
	*	@return	user's command.
	*/
	int GetCommand();

	/**
	*	@brief	genre로 해당 genre number를 찾아 리턴한다.
	*	@pre	genre is set.
	*	@post	genre로 일치하는 해당 genre number를 찾아 리턴한다.
	*	@param	genre	genre number를 찾으려는 genre명
	*	@return	해당 장르명에 맞는 genre number를 리턴하고, 일치하는 장르명이 없을 시, 11을 리턴한다.
	*/
	int SetGenreId(const string& genre);

	/**
	*	@brief	item의 id 생성
	*	@pre	id값을 제외한 나머지 item의 정보가 채워져 있어야 함.
	*	@post	현재날짜.카운트.발매일.곡제목 으로 구성된 음악 고유 id리턴
	*	@param	item	id를 생성하고자 하는 데이터.
	*	@return	해당 item의 고유 ID 리턴.
	*/
	string SetMusicId(MusicType& item);


	/**
	*	@brief	외부에서 저장된 음악정보 가져옴.
	*	@pre	"top100music"명을 가진 파일 존재.
	*	@post	파일 내 있는 음악정보를 가져와 모든 리스트에 추가 및 정리.
	*/
	void BringTop100();


	/**
	*	@brief	음악을 선택해 재생.
	*	@pre	none.
	*	@post	재생하고자 하는 음악과 musiclist에서의 index를 이용해 음악을 재생한 후, 최근재생/최다재생 목록 갱신.
	*	@param	data	재생하고자 하는 음악
	*	@param	idx		data의 musiclist에서의 index
	*/
	void MusicSelect(MusicType data, int idx);

	/**
	*	@brief	음악 관리.
	*	@pre	none.
	*	@post	음악 추가, 음악 제거, 음악 정보 변경 등의 기능으로 음악 정보를 관리함.
	*/
	void ManageMusic();


	/**
	*	@brief	음악 검색.
	*	@pre	musiclist가 비어있지 않아야 함.
	*	@post	음악을 전체/장르별/아티스트별/앨범별로 검색할 수 있도록 함.
	*/
	void SearchMusic();


	/**
	*	@brief	Add new record into list.
	*	@pre	list should be initialized.
	*	@post	new record is added into the list.
	*	@param	temp	추가하고자 하는 data. 만일 빈 데이터일 경우 사용자에게 입력받아 추가한다.
	*	@return	return 1 if this function works well, otherwise 0.
	*/
	int AddMusic(MusicType &temp);


	/**
	*	@brief	사용자에게 primary key를 입력받아 SortedList의 Delete함수에 넘겨주는 역할을 한다.
	*	@pre	없다.
	*	@post	사용자가 입력한 primary key를 가지고 있는 MusicType/SimpleMusicType이 m_List, 장르/아티스트/앨범/최근재생목록 에서 삭제됨.
	*	@return	return 1 if this function works well, otherwise 0.
	*/
	int DeleteMusic(); 


	/**
	*	@brief	사용자에게 primary key를 입력받아 SortedList의 Replace함수에 넘겨주는 역할을 한다.
	*	@pre	없다.
	*	@post	사용자가 입력한 primary key를 가지고 있는 MusicType/SimpleMusicType을 m_List/장르/아티스트/앨범리스트에서 갱신한다.
	*	@return	return 1 if this function works well, otherwise 0.
	*/
	int ReplaceMusic(); 


	/**
	*	@brief	리스트에 있는 음악을 id를 이용해 검색한다.
	*	@pre	없다.
	*	@post	바이너리 서치를 이용해 해당 id를 가진 음악이 musiclist에 존재하는지 찾음.
	*	@param	data	인덱스를 찾고자 하는 data	
	*	@return 일치하는 항목을 찾은 경우 해당 정보의 인덱스를 리턴하고, 그렇지 않으면 -1을 리턴한다.
	*/
	int SearchById(MusicType &data);


	/**
	*	@brief	객체를 생성 후, 찾고자 하는 Title을 입력받는다.
	*	@pre	없다.
	*	@post	find 함수를 이용해 입력받은 Title과 일치하는 음악 정보가 존재하는지 찾아 출력한다.(단, 검색어가 곡명에 포함된다면 출력한다.)
	*	@return 일치하는 항목을 찾은 경우 1을 리턴하고, 그렇지 않으면 0을 리턴한다.
	*/
	int SearchByName();


	/**
	*	@brief	Display all records in the musiclist on screen.
	*	@pre	none.
	*	@post	none.
	*/
	void DisplayAllMusic();


	/**
	*	@brief	Display all records in the addrecentlymusic on screen.
	*	@pre	none.
	*	@post	none.
	*/
	void DisplayNewMusic(); 


	/**
	*	@brief	Display all records in the PlayRecentlyMusicList on screen.
	*	@pre	none.
	*	@post	none.
	*/
	void DisplayPlayMusic();

	/**
	*	@brief	 Display all records in the MostPlaybackMusicList on screen.
	*	@pre	none.
	*	@post	none.
	*/
	void DisplayMostMusic();

	/**
	*	@brief	 파일명을 사용자로부터 입력받아 불러옴.
	*	@pre	none.
	*	@post	none.
	*/
	void ReadFile();

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
	*	@brief	Open a file as a read mode, read all data on the file, and set list by the data.
	*	@pre	The file is not opened.
	*	@post	list holds all records from the file.
	*	@param	filename	읽고자 하는 파일명.
	*	@return	return 1 if this function works well, otherwise 0.
	*/
	int ReadDataFromFile(char* filename);


	/**
	*	@brief	Open a file as a write mode, and write all data into the file,
	*	@pre	The file is not opened.
	*	@post	the list is stored in the output file.
	*	@return	return 1 if this function works well, otherwise 0.
	*/
	int WriteDataToFile(); 

private:
	ifstream m_InFile;									///< input file descriptor.
	ofstream m_OutFile;									///< output file descriptor.

	SortedList<MusicType> MusicList;					///< 모든 음악 정보 가진 리스트.
	SortedList<InfMusic> GenreList;						///< 장르별로 정리한 리스트


	SingleLinkedList<InfMusic> ArtistList;				///< 아티스트별로 정리한 리스트
	SingleLinkedList<InfMusic> AlbumList;				///< 앨범별로 정리한 리스트

	Queue<SimpleMusicType> AddRecentlyMusicList;		///< 최근 추가 목록

	LinkedList<SimpleMusicType> PlayRecentlyMusicList;	///< 최근 재생 목록

	LinkedList<InfMusic> MostPlaybackMusicList;			///< 최다 재생 목록

	int m_Command;										///< current command number.
	int count = 0;										///< primary key 생성 위한 count.
};

#endif //!APPLICATION_H_