#ifndef _MUSICTYPE_H
#define _MUSICTYPE_H

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

/**
*	Music information class.
*/
class MusicType {
public:
	/**
	*	default constructor.
	*/
	MusicType();
	/**
	*	copy constructor.
	*/
	MusicType(const MusicType& anMusic);
	/**
	*	destructor.
	*/
	~MusicType();


	/**
	*	@brief	Get music id.
	*	@pre	music id is set.
	*	@post	none.
	*	@return	music id.
	*/
	string GetId();

	/**
	*	@brief	Get music title.
	*	@pre	music title is set.
	*	@post	none.
	*	@return	music title.
	*/
	string GetTitle();

	/**
	*	@brief	Get music artist.
	*	@pre	music artist is set.
	*	@post	none.
	*	@return	music artist.
	*/
	string GetArtist();

	/**
	*	@brief	Get music album.
	*	@pre	music album is set.
	*	@post	none.
	*	@return	music album.
	*/
	string GetAlbum();

	/**
	*	@brief	Get music genre.
	*	@pre	music genre is set.
	*	@post	none.
	*	@return	music genre.
	*/
	string GetGenre();

	/**
	*	@brief	Get music lyrics.
	*	@pre	music lyrics is set.
	*	@post	none.
	*	@return	music lyrics.
	*/
	string GetLyrics();

	/**
	*	@brief	Get music release date.
	*	@pre	music release date is set.
	*	@post	none.
	*	@return	music release date.
	*/
	string GetReleaseDate();

	/**
	*	@brief	Get music play count.
	*	@pre	music play count is set.
	*	@post	none.
	*	@return	music play count.
	*/
	int GetCount();


	/**
	*	@brief	Set music Id.
	*	@pre	none.
	*	@post	music id is set.
	*	@param	inId    music id.
	*/
	void SetId(string inId);

	/**
	*	@brief	Set music title.
	*	@pre	none.
	*	@post	music title is set.
	*	@param	inTitle    music title.
	*/
	void SetTitle(string inTitle);

	/**
	*	@brief	Set music artist.
	*	@pre	none.
	*	@post	music artist is set.
	*	@param	inArtist    music artist.
	*/
	void SetArtist(string inArtist);

	/**
	*	@brief	Set music album.
	*	@pre	none.
	*	@post	music album is set.
	*	@param	inAlbum    music album.
	*/
	void SetAlbum(string inAlbum);

	/**
	*	@brief	Set music genre.
	*	@pre	none.
	*	@post	music genre is set.
	*	@param	inGenre    music genre.
	*/
	void SetGenre(string inGenre);

	/**
	*	@brief	Set music lyrics.
	*	@pre	none.
	*	@post	music lyrics is set.
	*	@param	inLyrics    music lyrics.
	*/
	void SetLyrics(string inLyrics);

	/**
	*	@brief	Set music release date.
	*	@pre	none.
	*	@post	music release date is set.
	*	@param	inRelease    music release date.
	*/
	void SetReleseDate(string inRelease);

	/**
	*	@brief	count Ƚ�� ����.
	*	@pre	none.
	*	@post	count�� Ƚ���� 1 ������Ų��.
	*/
	void PlayMusic(); 


	/**
	*	@brief	Set Music record.
	*	@pre	none.
	*	@post	music record is set.
	*	@param	inTitle    music title.
	*	@param	inArtist    music artist.
	*	@param	inAlbum 	music album.
	*	@param	inGenre 	music genre.
	*	@param	inLyrics	music lyrics.
	*	@param	inrelease	music release date.
	*/
	void SetRecord(string inTitle, string inArtist, string inAlbum, string inGenre, string inLyrics, string inrelease);

	/**
	*	@brief	Display music id on screen.
	*	@pre	music id is set.
	*	@post	music id is on screen.
	*/
	void DisplayIdOnScreen();

	/**
	*	@brief	Display music title on screen.
	*	@pre	music title is set.
	*	@post	music title is on screen.
	*/
	void DisplayTitleOnScreen();

	/**
	*	@brief	Display music artist on screen.
	*	@pre	music artist is set.
	*	@post	music artist is on screen.
	*/
	void DisplayArtistOnScreen();

	/**
	*	@brief	Display music album on screen.
	*	@pre	music album is set.
	*	@post	music album is on screen.
	*/
	void DisplayAlbumOnScreen();

	/**
	*	@brief	Display music genre on screen.
	*	@pre	music genre is set.
	*	@post	music genre is on screen.
	*/
	void DisplayGenreOnScreen();

	/**
	*	@brief	Display music lyrics on screen.
	*	@pre	music lyrics is set.
	*	@post	music lyrics is on screen.
	*/
	void DisplayLyricsOnScreen();

	/**
	*	@brief	Display music release date on screen.
	*	@pre	music release date is set.
	*	@post	music release date is on screen.
	*/
	void DisplayReleaseDateOnScreen();

	/**
	*	@brief	Display a music record on screen.
	*	@pre	music record is set.
	*	@post	music record is on screen.
	*/
	void DisplayRecordOnScreen();

	/**
	*	@brief	Display a music record on screen.
	*	@pre	music record is set.
	*	@post	music record is on screen.
	*/
	void DisplayCountOnScreen();

	/**
	*	@brief	Set music id from keyboard.
	*	@pre	none.
	*	@post	music id is set.
	*/
	void SetIdFromKB();

	/**
	*	@brief	Set music title from keyboard.
	*	@pre	none.
	*	@post	music title is set.
	*/
	void SetTitleFromKB();

	/**
	*	@brief	Set music artist from keyboard.
	*	@pre	none.
	*	@post	music artist is set.
	*/
	void SetArtistFromKB();

	/**
	*	@brief	Set music album from keyboard.
	*	@pre	none.
	*	@post	music album is set.
	*/
	void SetAlbumFromKB();

	/**
	*	@brief	Set music genre from keyboard.
	*	@pre	none.
	*	@post	music genre is set.
	*/
	void SetGenreFromKB();

	/**
	*	@brief	Set music lyrics from keyboard.
	*	@pre	none.
	*	@post	music lyrics is set.
	*/
	void SetLyricsFromKB();

	/**
	*	@brief	Set music release date from keyboard.
	*	@pre	none.
	*	@post	music release date is set.
	*/
	void SetReleaseDateFromKB();

	/**
	*	@brief	Set music record from keyboard.
	*	@pre	none.
	*	@post	music record is set.
	*/
	void SetRecordFromKB();


	/**
	*	@brief	Read a record from file.
	*	@pre	the target file is opened.
	*	@post	music record is set.
	*	@param	fin    file descriptor.
	*	@return	return 1 if this function works well, otherwise 0.
	*/
	int ReadDataFromFile(ifstream& fin);

	/**
	*	@brief	Write a record into file.
	*	@pre	the target file is opened. And the list should be initialized.
	*	@post	the target file is included the new music record.
	*	@param	fout	file descriptor.
	*	@return	return 1 if this function works well, otherwise 0.
	*/
	int WriteDataToFile(ofstream& fout);


	/**
	*	@brief	operator == overloading
	*	@pre	none.
	*	@post	id�� item�� id�� �������� �Ǻ�.
	*	@param	item	�񱳴��
	*	@return item�� id�� ��ġ�ϸ� true, �ƴϸ� false�� �����Ѵ�.
	*/
	bool operator==(MusicType &item);

	/**
	*	@brief	operator != overloading
	*	@pre	none.
	*	@post	id�� item�� id�� �ٸ��� �Ǻ�.
	*	@param	item	�񱳴��
	*	@return item�� id�� �ٸ��� true, ������ false�� �����Ѵ�.
	*/
	bool operator!=(MusicType &item);

	/**
	*	@brief	operator >= overloading
	*	@pre	none.
	*	@post	id�� item�� id���� ũ�ų� ������ �Ǻ�.
	*	@param	item	�񱳴��
	*	@return id�� item�� id���� ũ�ų� ������ true, �ƴϸ� false�� �����Ѵ�.
	*/
	bool operator>=(MusicType &item);

	/**
	*	@brief	operator <= overloading
	*	@pre	none.
	*	@post	id�� item�� id���� �۰ų� ������ �Ǻ�.
	*	@param	item	�񱳴��
	*	@return id�� item�� id���� �۰ų� ������ true, �ƴϸ� false�� �����Ѵ�.
	*/
	bool operator<=(MusicType &item);

	/**
	*	@brief	operator > overloading
	*	@pre	none.
	*	@post	id�� item�� id���� ū�� �Ǻ�.
	*	@param	item	�񱳴��
	*	@return id�� item�� id���� ũ�� true, �ƴϸ� false�� �����Ѵ�.
	*/
	bool operator>(MusicType &item);

	/**
	*	@brief	operator < overloading
	*	@pre	none.
	*	@post	id�� item�� id���� ������ �Ǻ�.
	*	@param	item	�񱳴��
	*	@return id�� item�� id���� ������ true, �ƴϸ� false�� �����Ѵ�.
	*/
	bool operator<(MusicType &item);

	/**
	*	@brief	operator = overloading
	*	@pre	none.
	*	@post	MusicType�� other�� ������ �����ϰ� �������ش�.
	*	@param	other	������ ������ ���.
	*	@return other�� ������ ������ this*�� ����.
	*/
	MusicType& operator=(const MusicType& other);

private:
	string id;		 ///< music primary key.
	string title;    ///< music title.
	string artist;   ///< music artist.
	string album;    ///< music album.
	string genre;    ///< music genre.
	string lyrics;	 ///< music lyrics.
	string releaseD; ///< music Release Date.
	int count;       ///< ��� Ƚ��
};

#endif // !MUSICTYPE_H_

