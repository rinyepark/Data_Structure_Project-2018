#ifndef SIMPLEMUSICTYPE_H_
#define SIMPLEMUSICTYPE_H_

#include <iostream>
#include <string>
using namespace std;

/**
*	간단한 음악 정보 클래스
*/
class SimpleMusicType {
public:
	/**
	*	default constructor.
	*/
	SimpleMusicType();

	/**
	*	copy constructor.
	*/
	SimpleMusicType(const SimpleMusicType& other);

	/**
	*	default constructor with 1 parameter.
	*/
	SimpleMusicType(string inNum);

	/**
	*	default constructor with 2 parameters.
	*/
	SimpleMusicType(string inNum, string inTitle);

	/**
	*	destructor.
	*/
	~SimpleMusicType();

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
	*	@brief	음악 정보를 화면에 출력.
	*	@pre	음악 정보 존재.
	*	@post	음악 정보가 화면에 나타남.
	*/
	void DisplayRecord();

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
	*	@brief	음악 제목과 아티스트 구분
	*	@pre	없음.
	*	@post	없음.
	*	@param	inNum	   구분에 사용될 Music ID.
	*	@param	title      전달될 음악 제목 변수.
	*	@param	artist	   전달될 가수 변수.
	*/
	void ConvertIDtoTitleNArtist(string& inNum, string& title, string&artist);

	/**
	*	@brief	operator == overloading
	*	@pre	없음.
	*	@post	num과 other의 num이 동일한지 판별.
	*	@param	other	비교대상
	*	@return other의 num과 일치하면 true, 아니면 false를 리턴한다.
	*/
	bool operator==(const SimpleMusicType& other);

	/**
	*	@brief	operator != overloading
	*	@pre	없음.
	*	@post	num과 other의 num이 다른지 판별.
	*	@param	other	비교대상
	*	@return other의 num과 다르면 true, 같으면 false를 리턴한다.
	*/
	bool operator!=(const SimpleMusicType& other);

	/**
	*	@brief	operator < overloading
	*	@pre	없음.
	*	@post	num이 other의 num보다 작은지 판별.
	*	@param	other	비교대상
	*	@return num이 other의 num보다 작으면 true, 아니면 false를 리턴한다.
	*/
	bool operator<(const SimpleMusicType& other);

	/**
	*	@brief	operator > overloading
	*	@pre	없음.
	*	@post	num이 other의 num보다 큰지 판별.
	*	@param	other	비교대상
	*	@return num이 other의 num보다 크면 true, 아니면 false를 리턴한다.
	*/
	bool operator>(const SimpleMusicType& other);

	/**
	*	@brief	operator = overloading
	*	@pre	없음.
	*	@post	SimpleMusicType을 other의 정보와 동일하게 정의해준다.
	*	@param	other	정보를 가져올 대상.
	*	@return other의 정보를 정의한 this*를 리턴.
	*/
	SimpleMusicType& operator=(const SimpleMusicType& other);

	/**
	*	@brief	operator << overloading
	*	@pre	없음.
	*	@post	SimpleMusicType이 cout되는 형식을 결정.
	*	@param	out		cout할 형식 전달.
	*	@param	item	cout할 대상
	*	@return item의 출력 형식을 작성한 out을 리턴함.
	*/
	friend ostream& operator<<(ostream& out, SimpleMusicType& item) {

		out << "\n\t  *** MusicID: " << item.num << endl;
		out << "\t  | 곡명: " << item.title << endl;

		return out;
	}

private:
	string num;		///< 음악 고유 키.
	string title;   ///< 음악 제목.
};
#endif // !SIMPLEMUSICTYPE_H_

