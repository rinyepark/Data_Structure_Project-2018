#ifndef MUSICTYPE_H_
#define MUSICTYPE_H_

#include <iostream>
#include <string>
#include <fstream>
using namespace std;

/**
*	음악 정보 class.
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
	*	@brief	음악 번호 반환.
	*	@pre	음악 번호 존재.
	*	@post	없음.
	*	@return	음악 번호 리턴.
	*/
	string GetNum();

	/**
	*	@brief	음악 제목 반환.
	*	@pre	음악 제목 존재.
	*	@post	없음.
	*	@return	음악 제목 리턴.
	*/
	string GetTitle();

	/**
	*	@brief	장르명 반환.
	*	@pre	장르명 존재.
	*	@post	없음.
	*	@return	장르명 리턴.
	*/
	string GetGenre();

	/**
	*	@brief	가수명 반환.
	*	@pre	가수명 존재.
	*	@post	없음.
	*	@return	가수명 리턴.
	*/
	string GetArtist();

	/**
	*	@brief	앨범명 반환.
	*	@pre	앨범명 존재.
	*	@post	없음.
	*	@return	앨범명 리턴.
	*/
	string GetAlbum();

	/**
	*	@brief	음악 가사 반환.
	*	@pre	음악 가사 존재.
	*	@post	없음.
	*	@return	음악 가사 리턴.
	*/
	string GetLyrics();
	
	/**
	*	@brief	음악 발매일 반환.
	*	@pre	음악 발매일 존재.
	*	@post	없음.
	*	@return	음악 발매일 리턴.
	*/
	string GetReleaseD();

	/**
	*	@brief	음악 파일명 반환.
	*	@pre	음악 파일명 존재.
	*	@post	없음.
	*	@return	음악 파일명 리턴.
	*/
	string GetFilename();

	/**
	*	@brief	음악 작곡가 반환.
	*	@pre	음악 작곡가 존재.
	*	@post	없음.
	*	@return	음악 작곡가 리턴.
	*/
	string GetComposer();

	/**
	*	@brief	음악 작사가 반환.
	*	@pre	음악 작사가 존재.
	*	@post	없음.
	*	@return	음악 작사가 리턴.
	*/
	string GetLyricist();

	/**
	*	@brief	해당 음악 좋아요 여부 반환.
	*	@pre	좋아요 여부 존재.
	*	@post	없음.
	*	@return	좋아요인 경우 true, 아닌 경우false 리턴.
	*/
	bool GetHeart();

	/**
	*	@brief	음악 재생횟수 반환.
	*	@pre	재생횟수 존재.
	*	@post	없음.
	*	@return	음악 재생횟수 리턴.
	*/
	int GetCount();

	/**
	*	@brief	음악 재생시간 반환.
	*	@pre	재생시간 존재.
	*	@post	없음.
	*	@return	음악 재생시간 리턴.
	*/
	string GetTime();

	/**
	*	@brief	음악 재생시간 초단위로 반환.
	*	@pre	재생시간 존재.
	*	@post	없음.
	*	@return	음악 재생시간 초단위로 리턴.
	*/
	int GetConvertSecond();

	/**
	*	@brief	재생목록 속한 여부 반환.
	*	@pre	재생목록 속했는지 여부 존재.
	*	@post	없음.
	*	@return	재생목록 속한 여부 리턴.
	*/
	string GetIsInPlaylist();



	/**
	*	@brief	음악 번호 설정.
	*	@pre	없음.
	*	@post	음악 번호가 설정됨.
	*	@param	inNum    설정하고자 하는 음악 번호.
	*/
	void SetNum(string inNum);

	/**
	*	@brief	음악 제목 설정.
	*	@pre	없음.
	*	@post	음악 제목이 설정됨.
	*	@param	inTitle    설정하고자 하는 음악 제목.
	*/
	void SetTitle(string inTitle);

	/**
	*	@brief	장르명 설정.
	*	@pre	없음.
	*	@post	장르명이 설정됨.
	*	@param	inGenre    설정하고자 하는 장르명.
	*/
	void SetGenre(string inGenre);

	/**
	*	@brief	가수명 설정.
	*	@pre	없음.
	*	@post	가수명이 설정됨.
	*	@param	inArtist    설정하고자 하는 가수명.
	*/
	void SetArtist(string inArtist);

	/**
	*	@brief	앨범명 설정.
	*	@pre	없음.
	*	@post	앨범명이 설정됨.
	*	@param	inAlbum    설정하고자 하는 앨범명.
	*/
	void SetAlbum(string inAlbum);

	/**
	*	@brief	음악 가사 설정.
	*	@pre	없음.
	*	@post	음악 가사가 설정됨.
	*	@param	inLyrics    설정하고자 하는 가사.
	*/
	void SetLyrics(string inLyrics);

	/**
	*	@brief	음악 발매일 설정.
	*	@pre	없음.
	*	@post	음악 발매일이 설정됨.
	*	@param	inReleaseD    설정하고자 하는 발매일.
	*/
	void SetReleaseD(string inReleaseD);

	/**
	*	@brief	음악 작곡가 설정.
	*	@pre	없음.
	*	@post	음악 작곡가가 설정됨.
	*	@param	inComposer    설정하고자 하는 작곡가.
	*/
	void SetComposer(string inComposer);

	/**
	*	@brief	음악 작사가 설정.
	*	@pre	없음.
	*	@post	음악 작사가가 설정됨.
	*	@param	inLyricist    설정하고자 하는 작사가.
	*/
	void SetLyricist(string inLyricist);

	/**
	*	@brief	음악 파일명 설정.
	*	@pre	없음.
	*	@post	음악 파일명이 설정됨.
	*	@param	inFilename    설정하고자 하는 파일명.
	*/
	void SetFilename(string inFilename);


	/**
	*	@brief	음악 좋아요 여부 설정.
	*	@pre	없음.
	*	@post	음악 좋아요 여부가 설정됨.
	*	@param	inHeart    설정하고자 하는 좋아요 여부.
	*/
	void SetHeart(bool inHeart);


	/**
	*	@brief	음악 재생횟수 설정.
	*	@pre	없음.
	*	@post	음악 재생횟수가 설정됨.
	*	@param	inCount		설정하고자 하는 재생횟수.
	*/
	void SetCount(int inCount);


	/**
	*	@brief	음악 재생시간 설정.
	*	@pre	없음.
	*	@post	음악 재생시간이 설정됨.
	*	@param	inTime    설정하고자 하는 재생시간.
	*/
	void SetTime(string inTime);


	/**
	*	@brief	재생목록 속한 여부 설정.
	*	@pre	없음.
	*	@post	재생목록 속한 여부 설정됨.
	*	@param	inPL    설정하고자 하는 재생목록 속한 여부.
	*/
	void SetIsInPlaylist(string inPL);


	/**
	*	@brief	음악 정보 설정.
	*	@pre	없음.
	*	@post	음악 정보가 설정됨.
	*	@param	inNum		설정하고자 하는 음악 번호.
	*	@param	inTitle     설정하고자 하는 음악 제목.
	*	@param	inGenre 	설정하고자 하는 장르명.
	*	@param	inArtist    설정하고자 하는 가수명.
	*	@param	inAlbum 	설정하고자 하는 앨범명.
	*	@param	inLyrics	설정하고자 하는 음악 가사.
	*	@param	inReleaseD	설정하고자 하는 음악 발매일.
	*	@param	inComposer	설정하고자 하는 음악 작곡가.
	*	@param	inLyricist	설정하고자 하는 음악 작사가.
	*	@param	inFilename	설정하고자 하는 음악 파일명.
	*	@param	inTime		설정하고자 하는 음악 재생시간.
	*/
	void SetRecord(string inNum, string inTitle, string inGenre, string inArtist, string inAlbum, string inLyrics, 
		string inReleaseD, string inComposer, string inLyricist, string inFilename, string inTime);


	/**
	*	@brief	키보드로 음악 번호 설정.
	*	@pre	없음.
	*	@post	입력받은 값으로 음악 번호가 설정됨.
	*/
	void SetNumFK();

	/**
	*	@brief	키보드로 음악 제목 설정.
	*	@pre	없음.
	*	@post	입력받은 값으로 음악 제목이 설정됨.
	*/
	void SetTitleFK();

	/**
	*	@brief	키보드로 장르명 설정.
	*	@pre	없음.
	*	@post	입력받은 값으로 장르명 설정됨.
	*/
	void SetGenreFK();

	/**
	*	@brief	키보드로 가수명 설정.
	*	@pre	없음.
	*	@post	입력받은 값으로 가수명 설정됨.
	*/
	void SetArtistFK();

	/**
	*	@brief	키보드로 앨범명 설정.
	*	@pre	없음.
	*	@post	입력받은 값으로 앨범명 설정됨.
	*/
	void SetAlbumFK();

	/**
	*	@brief	키보드로 음악 가사 설정.
	*	@pre	없음.
	*	@post	입력받은 값으로 음악 가사 설정됨.
	*/
	void SetLyricsFK();


	/**
	*	@brief	키보드로 발매일 설정.
	*	@pre	없음.
	*	@post	입력받은 값으로 발매일 설정됨.
	*/
	void SetReleaseDFK();

	/**
	*	@brief	키보드로 작곡가 설정.
	*	@pre	없음.
	*	@post	입력받은 값으로 작곡가 설정됨.
	*/
	void SetComposerFK();

	/**
	*	@brief	키보드로 작사가 설정.
	*	@pre	없음.
	*	@post	입력받은 값으로 작사가 설정됨.
	*/
	void SetLyricistFK();

	/**
	*	@brief	키보드로 파일명 설정.
	*	@pre	없음.
	*	@post	입력받은 값으로 파일명 설정됨.
	*/
	void SetFilenameFK();

	/**
	*	@brief	키보드로 재생시간 설정.
	*	@pre	없음.
	*	@post	입력받은 값으로 재생시간 설정됨.
	*/
	void SetTimeFK();

	/**
	*	@brief	키보드로 음악 정보 설정.
	*	@pre	없음.
	*	@post	입력받은 값으로 음악 정보 설정됨.
	*/
	void SetRecordFK();

	/**
	*	@brief	음악 번호를 화면에 출력.
	*	@pre	음악 번호 존재.
	*	@post	음악 번호가 화면에 나타남.
	*/
	void DisplayNum();

	/**
	*	@brief	음악 제목을 화면에 출력.
	*	@pre	음악 제목 존재.
	*	@post	음악 제목이 화면에 나타남.
	*/
	void DisplayTitle();

	/**
	*	@brief	장르명을 화면에 출력.
	*	@pre	장르명 존재.
	*	@post	장르명이 화면에 나타남.
	*/
	void DisplayGenre();

	/**
	*	@brief	가수명을 화면에 출력.
	*	@pre	가수명 존재.
	*	@post	가수명이 화면에 나타남.
	*/
	void DisplayArtist();

	/**
	*	@brief	앨범명을 화면에 출력.
	*	@pre	앨범명 존재.
	*	@post	앨범명이 화면에 나타남.
	*/
	void DisplayAlbum();

	/**
	*	@brief	음악 가사를 화면에 출력.
	*	@pre	음악 가사 존재.
	*	@post	음악 가사가 화면에 나타남.
	*/
	void DisplayLyrics();

	/**
	*	@brief	음악 발매일을 화면에 출력.
	*	@pre	음악 발매일 존재.
	*	@post	음악 발매일이 화면에 나타남.
	*/
	void DisplayReleaseD();

	/**
	*	@brief	음악 작곡가를 화면에 출력.
	*	@pre	음악 작곡가 존재.
	*	@post	음악 작곡가가 화면에 나타남.
	*/
	void DisplayComposer();

	/**
	*	@brief	음악 작사가를 화면에 출력.
	*	@pre	음악 작사가 존재.
	*	@post	음악 작사가가 화면에 나타남.
	*/
	void DisplayLyricist();

	/**
	*	@brief	음악 파일이름을 화면에 출력.
	*	@pre	음악 파일이름 존재.
	*	@post	음악 파일이름이 화면에 나타남.
	*/
	void DisplayFilename();

	/**
	*	@brief	음악 재생시간을 화면에 출력.
	*	@pre	음악 재생시간 존재.
	*	@post	음악 재생시간이 화면에 나타남.
	*/
	void DisplayTime();

	/**
	*	@brief	음악 재생횟수를 화면에 출력.
	*	@pre	음악 재생횟수 존재.
	*	@post	음악 재생횟수가 화면에 나타남.
	*/
	void DisplayCount();

	/**
	*	@brief	음악 좋아요 여부 화면에 출력.
	*	@pre	음악 좋아요 여부 존재.
	*	@post	음악 좋아요 여부가 화면에 나타남.
	*/
	void DisplayHeart();

	/**
	*	@brief	음악 정보를 화면에 출력.
	*	@pre	음악 정보 존재.
	*	@post	음악 정보가 화면에 나타남.
	*/
	void DisplayRecord();




	/**
	*	@brief	operator == overloading
	*	@pre	없음.
	*	@post	num과 other의 num이 동일한지 판별.
	*	@param	other	비교대상
	*	@return other의 num과 일치하면 true, 아니면 false를 리턴한다.
	*/
	bool operator==(const MusicType& other);

	/**
	*	@brief	operator != overloading
	*	@pre	없음.
	*	@post	num과 other의 num이 다른지 판별.
	*	@param	other	비교대상
	*	@return other의 num과 다르면 true, 같으면 false를 리턴한다.
	*/
	bool operator!=(const MusicType& other);

	/**
	*	@brief	operator < overloading
	*	@pre	없음.
	*	@post	num이 other의 num보다 작은지 판별.
	*	@param	other	비교대상
	*	@return num이 other의 num보다 작으면 true, 아니면 false를 리턴한다.
	*/
	bool operator<(const MusicType& other);

	/**
	*	@brief	operator > overloading
	*	@pre	없음.
	*	@post	num이 other의 num보다 큰지 판별.
	*	@param	other	비교대상
	*	@return num이 other의 num보다 크면 true, 아니면 false를 리턴한다.
	*/
	bool operator>(const MusicType& other);

	/**
	*	@brief	operator = overloading
	*	@pre	없음.
	*	@post	MusicType을 other의 정보와 동일하게 정의해준다.
	*	@param	other	정보를 가져올 대상.
	*	@return other의 정보를 정의한 this*를 리턴.
	*/
	MusicType& operator=(const MusicType& other);


	/**
	*	@brief	operator << overloading
	*	@pre	없음.
	*	@post	MusicType이 cout되는 형식을 결정.
	*	@param	out		cout할 형식 전달.
	*	@param	item	cout할 대상
	*	@return item의 출력 형식을 작성한 out을 리턴함.
	*/
	friend ostream& operator<<(ostream& out, MusicType& item) {
		out << "\n\t   *** MusicID: " << item.GetNum() << endl;
		out << "\t   | 제목: " << item.GetTitle() << endl;
		out << "\t   | 장르: " << item.GetGenre() << endl;
		out <<  "\t   | 가수: " << item.GetArtist() << endl;
		out <<  "\t   | 앨범: " << item.GetAlbum() << endl;
		out <<  "\t   | 가사: " << item.GetLyrics() << endl;

		out << "\t   | 발매일: " << item.GetReleaseD() << endl;
		out << "\t   | 작곡가 " << item.GetComposer() << endl;
		out <<  "\t   | 작사가: " << item.GetLyricist() << endl;

		out <<  "\t   | 재생시간: " << item.GetTime() << endl;
		out <<  "\t   | 재생횟수: " << item.GetCount() << endl;

		out <<  "\t   | 좋아요: " << item.GetHeart() << endl;
		return out;
	}

	/**
	*	@brief	파일로부터 정보를 읽어옴.
	*	@pre	열고자 하는 파일이 열려있어야 함.
	*	@post	음악 정보가 설정됨.
	*	@param	fin    file descriptor.
	*	@return	함수가 잘 작동하면 1을, 그렇지 않으면 0을 리턴함.
	*/
	int ReadDataFromFile(ifstream& fin);

	/**
	*	@brief	파일에 정보 작성.
	*	@pre	작성하고자 하는 파일이 열려있어야 하며, 리스트가 존재해야 함.
	*	@post	작성하고자 한느 파일이 새로운 음악 정보를 포함함.
	*	@param	fout	file descriptor.
	*	@return	함수가 잘 작동하면 1을, 그렇지 않으면 0을 리턴함.
	*/
	int WriteDataToFile(ofstream& fout);

private:
	string num;				 ///< 음악 고유 정보(음악 번호).
	string title;			 ///< 음악 제목.
	string genre;			 ///< 장르명.
	string artist;			 ///< 가수명.
	string album;			 ///< 앨범명.
	string lyrics;			 ///< 음악 가사.

	string releaseD;		///< 발매일.
	string filename;		///< 음원파일이름.
	string composer;		///< 작곡가.
	string lyricist;		///< 작사가.

	string IsInPlaylist;	///<재생목록에 존재하는가
	int m_count;			///< 재생횟수.
	bool heart;				///< 좋아요.
	string time;			 ///< 재생시간.

};

#endif // !MUSICTYPE_H_
