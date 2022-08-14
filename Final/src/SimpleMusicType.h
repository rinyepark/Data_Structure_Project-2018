#ifndef SIMPLEMUSICTYPE_H_
#define SIMPLEMUSICTYPE_H_

#include <iostream>
#include <string>
using namespace std;

/**
*	������ ���� ���� Ŭ����
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
	*	@brief	���� ������ ȭ�鿡 ���.
	*	@pre	���� ���� ����.
	*	@post	���� ������ ȭ�鿡 ��Ÿ��.
	*/
	void DisplayRecord();

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
	*	@brief	���� ����� ��Ƽ��Ʈ ����
	*	@pre	����.
	*	@post	����.
	*	@param	inNum	   ���п� ���� Music ID.
	*	@param	title      ���޵� ���� ���� ����.
	*	@param	artist	   ���޵� ���� ����.
	*/
	void ConvertIDtoTitleNArtist(string& inNum, string& title, string&artist);

	/**
	*	@brief	operator == overloading
	*	@pre	����.
	*	@post	num�� other�� num�� �������� �Ǻ�.
	*	@param	other	�񱳴��
	*	@return other�� num�� ��ġ�ϸ� true, �ƴϸ� false�� �����Ѵ�.
	*/
	bool operator==(const SimpleMusicType& other);

	/**
	*	@brief	operator != overloading
	*	@pre	����.
	*	@post	num�� other�� num�� �ٸ��� �Ǻ�.
	*	@param	other	�񱳴��
	*	@return other�� num�� �ٸ��� true, ������ false�� �����Ѵ�.
	*/
	bool operator!=(const SimpleMusicType& other);

	/**
	*	@brief	operator < overloading
	*	@pre	����.
	*	@post	num�� other�� num���� ������ �Ǻ�.
	*	@param	other	�񱳴��
	*	@return num�� other�� num���� ������ true, �ƴϸ� false�� �����Ѵ�.
	*/
	bool operator<(const SimpleMusicType& other);

	/**
	*	@brief	operator > overloading
	*	@pre	����.
	*	@post	num�� other�� num���� ū�� �Ǻ�.
	*	@param	other	�񱳴��
	*	@return num�� other�� num���� ũ�� true, �ƴϸ� false�� �����Ѵ�.
	*/
	bool operator>(const SimpleMusicType& other);

	/**
	*	@brief	operator = overloading
	*	@pre	����.
	*	@post	SimpleMusicType�� other�� ������ �����ϰ� �������ش�.
	*	@param	other	������ ������ ���.
	*	@return other�� ������ ������ this*�� ����.
	*/
	SimpleMusicType& operator=(const SimpleMusicType& other);

	/**
	*	@brief	operator << overloading
	*	@pre	����.
	*	@post	SimpleMusicType�� cout�Ǵ� ������ ����.
	*	@param	out		cout�� ���� ����.
	*	@param	item	cout�� ���
	*	@return item�� ��� ������ �ۼ��� out�� ������.
	*/
	friend ostream& operator<<(ostream& out, SimpleMusicType& item) {

		out << "\n\t  *** MusicID: " << item.num << endl;
		out << "\t  | ���: " << item.title << endl;

		return out;
	}

private:
	string num;		///< ���� ���� Ű.
	string title;   ///< ���� ����.
};
#endif // !SIMPLEMUSICTYPE_H_

