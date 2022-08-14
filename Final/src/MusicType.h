#ifndef MUSICTYPE_H_
#define MUSICTYPE_H_

#include <iostream>
#include <string>
#include <fstream>
using namespace std;

/**
*	���� ���� class.
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
	MusicType(const MusicType& other);

	/**
	*	default constructor with parameter.
	*/
	MusicType(string inNum);

	/**
	*	destructor.
	*/
	~MusicType();


	/**
	*	@brief	���� ��ȣ ��ȯ.
	*	@pre	���� ��ȣ ����.
	*	@post	����.
	*	@return	���� ��ȣ ����.
	*/
	string GetNum();

	/**
	*	@brief	���� ���� ��ȯ.
	*	@pre	���� ���� ����.
	*	@post	����.
	*	@return	���� ���� ����.
	*/
	string GetTitle();

	/**
	*	@brief	�帣�� ��ȯ.
	*	@pre	�帣�� ����.
	*	@post	����.
	*	@return	�帣�� ����.
	*/
	string GetGenre();

	/**
	*	@brief	������ ��ȯ.
	*	@pre	������ ����.
	*	@post	����.
	*	@return	������ ����.
	*/
	string GetArtist();

	/**
	*	@brief	�ٹ��� ��ȯ.
	*	@pre	�ٹ��� ����.
	*	@post	����.
	*	@return	�ٹ��� ����.
	*/
	string GetAlbum();

	/**
	*	@brief	���� ���� ��ȯ.
	*	@pre	���� ���� ����.
	*	@post	����.
	*	@return	���� ���� ����.
	*/
	string GetLyrics();
	
	/**
	*	@brief	���� �߸��� ��ȯ.
	*	@pre	���� �߸��� ����.
	*	@post	����.
	*	@return	���� �߸��� ����.
	*/
	string GetReleaseD();

	/**
	*	@brief	���� ���ϸ� ��ȯ.
	*	@pre	���� ���ϸ� ����.
	*	@post	����.
	*	@return	���� ���ϸ� ����.
	*/
	string GetFilename();

	/**
	*	@brief	���� �۰ ��ȯ.
	*	@pre	���� �۰ ����.
	*	@post	����.
	*	@return	���� �۰ ����.
	*/
	string GetComposer();

	/**
	*	@brief	���� �ۻ簡 ��ȯ.
	*	@pre	���� �ۻ簡 ����.
	*	@post	����.
	*	@return	���� �ۻ簡 ����.
	*/
	string GetLyricist();

	/**
	*	@brief	�ش� ���� ���ƿ� ���� ��ȯ.
	*	@pre	���ƿ� ���� ����.
	*	@post	����.
	*	@return	���ƿ��� ��� true, �ƴ� ���false ����.
	*/
	bool GetHeart();

	/**
	*	@brief	���� ���Ƚ�� ��ȯ.
	*	@pre	���Ƚ�� ����.
	*	@post	����.
	*	@return	���� ���Ƚ�� ����.
	*/
	int GetCount();

	/**
	*	@brief	���� ����ð� ��ȯ.
	*	@pre	����ð� ����.
	*	@post	����.
	*	@return	���� ����ð� ����.
	*/
	string GetTime();

	/**
	*	@brief	���� ����ð� �ʴ����� ��ȯ.
	*	@pre	����ð� ����.
	*	@post	����.
	*	@return	���� ����ð� �ʴ����� ����.
	*/
	int GetConvertSecond();

	/**
	*	@brief	������ ���� ���� ��ȯ.
	*	@pre	������ ���ߴ��� ���� ����.
	*	@post	����.
	*	@return	������ ���� ���� ����.
	*/
	string GetIsInPlaylist();



	/**
	*	@brief	���� ��ȣ ����.
	*	@pre	����.
	*	@post	���� ��ȣ�� ������.
	*	@param	inNum    �����ϰ��� �ϴ� ���� ��ȣ.
	*/
	void SetNum(string inNum);

	/**
	*	@brief	���� ���� ����.
	*	@pre	����.
	*	@post	���� ������ ������.
	*	@param	inTitle    �����ϰ��� �ϴ� ���� ����.
	*/
	void SetTitle(string inTitle);

	/**
	*	@brief	�帣�� ����.
	*	@pre	����.
	*	@post	�帣���� ������.
	*	@param	inGenre    �����ϰ��� �ϴ� �帣��.
	*/
	void SetGenre(string inGenre);

	/**
	*	@brief	������ ����.
	*	@pre	����.
	*	@post	�������� ������.
	*	@param	inArtist    �����ϰ��� �ϴ� ������.
	*/
	void SetArtist(string inArtist);

	/**
	*	@brief	�ٹ��� ����.
	*	@pre	����.
	*	@post	�ٹ����� ������.
	*	@param	inAlbum    �����ϰ��� �ϴ� �ٹ���.
	*/
	void SetAlbum(string inAlbum);

	/**
	*	@brief	���� ���� ����.
	*	@pre	����.
	*	@post	���� ���簡 ������.
	*	@param	inLyrics    �����ϰ��� �ϴ� ����.
	*/
	void SetLyrics(string inLyrics);

	/**
	*	@brief	���� �߸��� ����.
	*	@pre	����.
	*	@post	���� �߸����� ������.
	*	@param	inReleaseD    �����ϰ��� �ϴ� �߸���.
	*/
	void SetReleaseD(string inReleaseD);

	/**
	*	@brief	���� �۰ ����.
	*	@pre	����.
	*	@post	���� �۰�� ������.
	*	@param	inComposer    �����ϰ��� �ϴ� �۰.
	*/
	void SetComposer(string inComposer);

	/**
	*	@brief	���� �ۻ簡 ����.
	*	@pre	����.
	*	@post	���� �ۻ簡�� ������.
	*	@param	inLyricist    �����ϰ��� �ϴ� �ۻ簡.
	*/
	void SetLyricist(string inLyricist);

	/**
	*	@brief	���� ���ϸ� ����.
	*	@pre	����.
	*	@post	���� ���ϸ��� ������.
	*	@param	inFilename    �����ϰ��� �ϴ� ���ϸ�.
	*/
	void SetFilename(string inFilename);


	/**
	*	@brief	���� ���ƿ� ���� ����.
	*	@pre	����.
	*	@post	���� ���ƿ� ���ΰ� ������.
	*	@param	inHeart    �����ϰ��� �ϴ� ���ƿ� ����.
	*/
	void SetHeart(bool inHeart);


	/**
	*	@brief	���� ���Ƚ�� ����.
	*	@pre	����.
	*	@post	���� ���Ƚ���� ������.
	*	@param	inCount		�����ϰ��� �ϴ� ���Ƚ��.
	*/
	void SetCount(int inCount);


	/**
	*	@brief	���� ����ð� ����.
	*	@pre	����.
	*	@post	���� ����ð��� ������.
	*	@param	inTime    �����ϰ��� �ϴ� ����ð�.
	*/
	void SetTime(string inTime);


	/**
	*	@brief	������ ���� ���� ����.
	*	@pre	����.
	*	@post	������ ���� ���� ������.
	*	@param	inPL    �����ϰ��� �ϴ� ������ ���� ����.
	*/
	void SetIsInPlaylist(string inPL);


	/**
	*	@brief	���� ���� ����.
	*	@pre	����.
	*	@post	���� ������ ������.
	*	@param	inNum		�����ϰ��� �ϴ� ���� ��ȣ.
	*	@param	inTitle     �����ϰ��� �ϴ� ���� ����.
	*	@param	inGenre 	�����ϰ��� �ϴ� �帣��.
	*	@param	inArtist    �����ϰ��� �ϴ� ������.
	*	@param	inAlbum 	�����ϰ��� �ϴ� �ٹ���.
	*	@param	inLyrics	�����ϰ��� �ϴ� ���� ����.
	*	@param	inReleaseD	�����ϰ��� �ϴ� ���� �߸���.
	*	@param	inComposer	�����ϰ��� �ϴ� ���� �۰.
	*	@param	inLyricist	�����ϰ��� �ϴ� ���� �ۻ簡.
	*	@param	inFilename	�����ϰ��� �ϴ� ���� ���ϸ�.
	*	@param	inTime		�����ϰ��� �ϴ� ���� ����ð�.
	*/
	void SetRecord(string inNum, string inTitle, string inGenre, string inArtist, string inAlbum, string inLyrics, 
		string inReleaseD, string inComposer, string inLyricist, string inFilename, string inTime);


	/**
	*	@brief	Ű����� ���� ��ȣ ����.
	*	@pre	����.
	*	@post	�Է¹��� ������ ���� ��ȣ�� ������.
	*/
	void SetNumFK();

	/**
	*	@brief	Ű����� ���� ���� ����.
	*	@pre	����.
	*	@post	�Է¹��� ������ ���� ������ ������.
	*/
	void SetTitleFK();

	/**
	*	@brief	Ű����� �帣�� ����.
	*	@pre	����.
	*	@post	�Է¹��� ������ �帣�� ������.
	*/
	void SetGenreFK();

	/**
	*	@brief	Ű����� ������ ����.
	*	@pre	����.
	*	@post	�Է¹��� ������ ������ ������.
	*/
	void SetArtistFK();

	/**
	*	@brief	Ű����� �ٹ��� ����.
	*	@pre	����.
	*	@post	�Է¹��� ������ �ٹ��� ������.
	*/
	void SetAlbumFK();

	/**
	*	@brief	Ű����� ���� ���� ����.
	*	@pre	����.
	*	@post	�Է¹��� ������ ���� ���� ������.
	*/
	void SetLyricsFK();


	/**
	*	@brief	Ű����� �߸��� ����.
	*	@pre	����.
	*	@post	�Է¹��� ������ �߸��� ������.
	*/
	void SetReleaseDFK();

	/**
	*	@brief	Ű����� �۰ ����.
	*	@pre	����.
	*	@post	�Է¹��� ������ �۰ ������.
	*/
	void SetComposerFK();

	/**
	*	@brief	Ű����� �ۻ簡 ����.
	*	@pre	����.
	*	@post	�Է¹��� ������ �ۻ簡 ������.
	*/
	void SetLyricistFK();

	/**
	*	@brief	Ű����� ���ϸ� ����.
	*	@pre	����.
	*	@post	�Է¹��� ������ ���ϸ� ������.
	*/
	void SetFilenameFK();

	/**
	*	@brief	Ű����� ����ð� ����.
	*	@pre	����.
	*	@post	�Է¹��� ������ ����ð� ������.
	*/
	void SetTimeFK();

	/**
	*	@brief	Ű����� ���� ���� ����.
	*	@pre	����.
	*	@post	�Է¹��� ������ ���� ���� ������.
	*/
	void SetRecordFK();

	/**
	*	@brief	���� ��ȣ�� ȭ�鿡 ���.
	*	@pre	���� ��ȣ ����.
	*	@post	���� ��ȣ�� ȭ�鿡 ��Ÿ��.
	*/
	void DisplayNum();

	/**
	*	@brief	���� ������ ȭ�鿡 ���.
	*	@pre	���� ���� ����.
	*	@post	���� ������ ȭ�鿡 ��Ÿ��.
	*/
	void DisplayTitle();

	/**
	*	@brief	�帣���� ȭ�鿡 ���.
	*	@pre	�帣�� ����.
	*	@post	�帣���� ȭ�鿡 ��Ÿ��.
	*/
	void DisplayGenre();

	/**
	*	@brief	�������� ȭ�鿡 ���.
	*	@pre	������ ����.
	*	@post	�������� ȭ�鿡 ��Ÿ��.
	*/
	void DisplayArtist();

	/**
	*	@brief	�ٹ����� ȭ�鿡 ���.
	*	@pre	�ٹ��� ����.
	*	@post	�ٹ����� ȭ�鿡 ��Ÿ��.
	*/
	void DisplayAlbum();

	/**
	*	@brief	���� ���縦 ȭ�鿡 ���.
	*	@pre	���� ���� ����.
	*	@post	���� ���簡 ȭ�鿡 ��Ÿ��.
	*/
	void DisplayLyrics();

	/**
	*	@brief	���� �߸����� ȭ�鿡 ���.
	*	@pre	���� �߸��� ����.
	*	@post	���� �߸����� ȭ�鿡 ��Ÿ��.
	*/
	void DisplayReleaseD();

	/**
	*	@brief	���� �۰�� ȭ�鿡 ���.
	*	@pre	���� �۰ ����.
	*	@post	���� �۰�� ȭ�鿡 ��Ÿ��.
	*/
	void DisplayComposer();

	/**
	*	@brief	���� �ۻ簡�� ȭ�鿡 ���.
	*	@pre	���� �ۻ簡 ����.
	*	@post	���� �ۻ簡�� ȭ�鿡 ��Ÿ��.
	*/
	void DisplayLyricist();

	/**
	*	@brief	���� �����̸��� ȭ�鿡 ���.
	*	@pre	���� �����̸� ����.
	*	@post	���� �����̸��� ȭ�鿡 ��Ÿ��.
	*/
	void DisplayFilename();

	/**
	*	@brief	���� ����ð��� ȭ�鿡 ���.
	*	@pre	���� ����ð� ����.
	*	@post	���� ����ð��� ȭ�鿡 ��Ÿ��.
	*/
	void DisplayTime();

	/**
	*	@brief	���� ���Ƚ���� ȭ�鿡 ���.
	*	@pre	���� ���Ƚ�� ����.
	*	@post	���� ���Ƚ���� ȭ�鿡 ��Ÿ��.
	*/
	void DisplayCount();

	/**
	*	@brief	���� ���ƿ� ���� ȭ�鿡 ���.
	*	@pre	���� ���ƿ� ���� ����.
	*	@post	���� ���ƿ� ���ΰ� ȭ�鿡 ��Ÿ��.
	*/
	void DisplayHeart();

	/**
	*	@brief	���� ������ ȭ�鿡 ���.
	*	@pre	���� ���� ����.
	*	@post	���� ������ ȭ�鿡 ��Ÿ��.
	*/
	void DisplayRecord();




	/**
	*	@brief	operator == overloading
	*	@pre	����.
	*	@post	num�� other�� num�� �������� �Ǻ�.
	*	@param	other	�񱳴��
	*	@return other�� num�� ��ġ�ϸ� true, �ƴϸ� false�� �����Ѵ�.
	*/
	bool operator==(const MusicType& other);

	/**
	*	@brief	operator != overloading
	*	@pre	����.
	*	@post	num�� other�� num�� �ٸ��� �Ǻ�.
	*	@param	other	�񱳴��
	*	@return other�� num�� �ٸ��� true, ������ false�� �����Ѵ�.
	*/
	bool operator!=(const MusicType& other);

	/**
	*	@brief	operator < overloading
	*	@pre	����.
	*	@post	num�� other�� num���� ������ �Ǻ�.
	*	@param	other	�񱳴��
	*	@return num�� other�� num���� ������ true, �ƴϸ� false�� �����Ѵ�.
	*/
	bool operator<(const MusicType& other);

	/**
	*	@brief	operator > overloading
	*	@pre	����.
	*	@post	num�� other�� num���� ū�� �Ǻ�.
	*	@param	other	�񱳴��
	*	@return num�� other�� num���� ũ�� true, �ƴϸ� false�� �����Ѵ�.
	*/
	bool operator>(const MusicType& other);

	/**
	*	@brief	operator = overloading
	*	@pre	����.
	*	@post	MusicType�� other�� ������ �����ϰ� �������ش�.
	*	@param	other	������ ������ ���.
	*	@return other�� ������ ������ this*�� ����.
	*/
	MusicType& operator=(const MusicType& other);


	/**
	*	@brief	operator << overloading
	*	@pre	����.
	*	@post	MusicType�� cout�Ǵ� ������ ����.
	*	@param	out		cout�� ���� ����.
	*	@param	item	cout�� ���
	*	@return item�� ��� ������ �ۼ��� out�� ������.
	*/
	friend ostream& operator<<(ostream& out, MusicType& item) {
		out << "\n\t   *** MusicID: " << item.GetNum() << endl;
		out << "\t   | ����: " << item.GetTitle() << endl;
		out << "\t   | �帣: " << item.GetGenre() << endl;
		out <<  "\t   | ����: " << item.GetArtist() << endl;
		out <<  "\t   | �ٹ�: " << item.GetAlbum() << endl;
		out <<  "\t   | ����: " << item.GetLyrics() << endl;

		out << "\t   | �߸���: " << item.GetReleaseD() << endl;
		out << "\t   | �۰ " << item.GetComposer() << endl;
		out <<  "\t   | �ۻ簡: " << item.GetLyricist() << endl;

		out <<  "\t   | ����ð�: " << item.GetTime() << endl;
		out <<  "\t   | ���Ƚ��: " << item.GetCount() << endl;

		out <<  "\t   | ���ƿ�: " << item.GetHeart() << endl;
		return out;
	}

	/**
	*	@brief	���Ϸκ��� ������ �о��.
	*	@pre	������ �ϴ� ������ �����־�� ��.
	*	@post	���� ������ ������.
	*	@param	fin    file descriptor.
	*	@return	�Լ��� �� �۵��ϸ� 1��, �׷��� ������ 0�� ������.
	*/
	int ReadDataFromFile(ifstream& fin);

	/**
	*	@brief	���Ͽ� ���� �ۼ�.
	*	@pre	�ۼ��ϰ��� �ϴ� ������ �����־�� �ϸ�, ����Ʈ�� �����ؾ� ��.
	*	@post	�ۼ��ϰ��� �Ѵ� ������ ���ο� ���� ������ ������.
	*	@param	fout	file descriptor.
	*	@return	�Լ��� �� �۵��ϸ� 1��, �׷��� ������ 0�� ������.
	*/
	int WriteDataToFile(ofstream& fout);

private:
	string num;				 ///< ���� ���� ����(���� ��ȣ).
	string title;			 ///< ���� ����.
	string genre;			 ///< �帣��.
	string artist;			 ///< ������.
	string album;			 ///< �ٹ���.
	string lyrics;			 ///< ���� ����.

	string releaseD;		///< �߸���.
	string filename;		///< ���������̸�.
	string composer;		///< �۰.
	string lyricist;		///< �ۻ簡.

	string IsInPlaylist;	///<�����Ͽ� �����ϴ°�
	int m_count;			///< ���Ƚ��.
	bool heart;				///< ���ƿ�.
	string time;			 ///< ����ð�.

};

#endif // !MUSICTYPE_H_
