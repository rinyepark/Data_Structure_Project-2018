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
	*	@brief	genre�� �ش� genre number�� ã�� �����Ѵ�.
	*	@pre	genre is set.
	*	@post	genre�� ��ġ�ϴ� �ش� genre number�� ã�� �����Ѵ�.
	*	@param	genre	genre number�� ã������ genre��
	*	@return	�ش� �帣�� �´� genre number�� �����ϰ�, ��ġ�ϴ� �帣���� ���� ��, 11�� �����Ѵ�.
	*/
	int SetGenreId(const string& genre);

	/**
	*	@brief	item�� id ����
	*	@pre	id���� ������ ������ item�� ������ ä���� �־�� ��.
	*	@post	���糯¥.ī��Ʈ.�߸���.������ ���� ������ ���� ���� id����
	*	@param	item	id�� �����ϰ��� �ϴ� ������.
	*	@return	�ش� item�� ���� ID ����.
	*/
	string SetMusicId(MusicType& item);


	/**
	*	@brief	�ܺο��� ����� �������� ������.
	*	@pre	"top100music"���� ���� ���� ����.
	*	@post	���� �� �ִ� ���������� ������ ��� ����Ʈ�� �߰� �� ����.
	*/
	void BringTop100();


	/**
	*	@brief	������ ������ ���.
	*	@pre	none.
	*	@post	����ϰ��� �ϴ� ���ǰ� musiclist������ index�� �̿��� ������ ����� ��, �ֱ����/�ִ���� ��� ����.
	*	@param	data	����ϰ��� �ϴ� ����
	*	@param	idx		data�� musiclist������ index
	*/
	void MusicSelect(MusicType data, int idx);

	/**
	*	@brief	���� ����.
	*	@pre	none.
	*	@post	���� �߰�, ���� ����, ���� ���� ���� ���� ������� ���� ������ ������.
	*/
	void ManageMusic();


	/**
	*	@brief	���� �˻�.
	*	@pre	musiclist�� ������� �ʾƾ� ��.
	*	@post	������ ��ü/�帣��/��Ƽ��Ʈ��/�ٹ����� �˻��� �� �ֵ��� ��.
	*/
	void SearchMusic();


	/**
	*	@brief	Add new record into list.
	*	@pre	list should be initialized.
	*	@post	new record is added into the list.
	*	@param	temp	�߰��ϰ��� �ϴ� data. ���� �� �������� ��� ����ڿ��� �Է¹޾� �߰��Ѵ�.
	*	@return	return 1 if this function works well, otherwise 0.
	*/
	int AddMusic(MusicType &temp);


	/**
	*	@brief	����ڿ��� primary key�� �Է¹޾� SortedList�� Delete�Լ��� �Ѱ��ִ� ������ �Ѵ�.
	*	@pre	����.
	*	@post	����ڰ� �Է��� primary key�� ������ �ִ� MusicType/SimpleMusicType�� m_List, �帣/��Ƽ��Ʈ/�ٹ�/�ֱ������� ���� ������.
	*	@return	return 1 if this function works well, otherwise 0.
	*/
	int DeleteMusic(); 


	/**
	*	@brief	����ڿ��� primary key�� �Է¹޾� SortedList�� Replace�Լ��� �Ѱ��ִ� ������ �Ѵ�.
	*	@pre	����.
	*	@post	����ڰ� �Է��� primary key�� ������ �ִ� MusicType/SimpleMusicType�� m_List/�帣/��Ƽ��Ʈ/�ٹ�����Ʈ���� �����Ѵ�.
	*	@return	return 1 if this function works well, otherwise 0.
	*/
	int ReplaceMusic(); 


	/**
	*	@brief	����Ʈ�� �ִ� ������ id�� �̿��� �˻��Ѵ�.
	*	@pre	����.
	*	@post	���̳ʸ� ��ġ�� �̿��� �ش� id�� ���� ������ musiclist�� �����ϴ��� ã��.
	*	@param	data	�ε����� ã���� �ϴ� data	
	*	@return ��ġ�ϴ� �׸��� ã�� ��� �ش� ������ �ε����� �����ϰ�, �׷��� ������ -1�� �����Ѵ�.
	*/
	int SearchById(MusicType &data);


	/**
	*	@brief	��ü�� ���� ��, ã���� �ϴ� Title�� �Է¹޴´�.
	*	@pre	����.
	*	@post	find �Լ��� �̿��� �Է¹��� Title�� ��ġ�ϴ� ���� ������ �����ϴ��� ã�� ����Ѵ�.(��, �˻�� ��� ���Եȴٸ� ����Ѵ�.)
	*	@return ��ġ�ϴ� �׸��� ã�� ��� 1�� �����ϰ�, �׷��� ������ 0�� �����Ѵ�.
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
	*	@brief	 ���ϸ��� ����ڷκ��� �Է¹޾� �ҷ���.
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
	*	@param	filename	�а��� �ϴ� ���ϸ�.
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

	SortedList<MusicType> MusicList;					///< ��� ���� ���� ���� ����Ʈ.
	SortedList<InfMusic> GenreList;						///< �帣���� ������ ����Ʈ


	SingleLinkedList<InfMusic> ArtistList;				///< ��Ƽ��Ʈ���� ������ ����Ʈ
	SingleLinkedList<InfMusic> AlbumList;				///< �ٹ����� ������ ����Ʈ

	Queue<SimpleMusicType> AddRecentlyMusicList;		///< �ֱ� �߰� ���

	LinkedList<SimpleMusicType> PlayRecentlyMusicList;	///< �ֱ� ��� ���

	LinkedList<InfMusic> MostPlaybackMusicList;			///< �ִ� ��� ���

	int m_Command;										///< current command number.
	int count = 0;										///< primary key ���� ���� count.
};

#endif //!APPLICATION_H_