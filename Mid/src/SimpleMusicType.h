#ifndef _SIMPLEMUSICTYPE_H
#define _SIMPLEMUSICTYPE_H

#include <iostream>
#include <string>
using namespace std;

/**
*	Simple music information class.
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
	SimpleMusicType(const SimpleMusicType& anSimp);

	/**
	*	destructor.
	*/
	~SimpleMusicType();

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
	*	@brief	Set music id.
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
	*	@brief	Set Music record.
	*	@pre	none.
	*	@post	music record is set.
	*	@param	inId		music id.
	*	@param	inTitle		music title.
	*/
	void SetRecord(string inId, string inTitle);

	/**
	*	@brief	Set music title from keyboard.
	*	@pre	none.
	*	@post	music title is set.
	*/
	void SetTitleFromKB();


	/**
	*	@brief	operator == overloading
	*	@pre	none.
	*	@post	id�� item��  id�� �������� �Ǻ�.
	*	@param	item	�񱳴��
	*	@return item�� id�� ��ġ�ϸ� true, �ƴϸ� false�� �����Ѵ�.
	*/
	bool operator==(SimpleMusicType &item);

	/**
	*	@brief	operator != overloading
	*	@pre	none.
	*	@post	id�� item�� id�� �ٸ��� �Ǻ�.
	*	@param	item	�񱳴��
	*	@return item�� id�� �ٸ��� true, ������ false�� �����Ѵ�.
	*/
	bool operator!=(SimpleMusicType &item);

	/**
	*	@brief	operator >= overloading
	*	@pre	none.
	*	@post	id�� item�� id���� ũ�ų� ������ �Ǻ�.
	*	@param	item	�񱳴��
	*	@return id�� item��  id���� ũ�ų� ������ true, �ƴϸ� false�� �����Ѵ�.
	*/
	bool operator>=(SimpleMusicType &item);

	/**
	*	@brief	operator <= overloading
	*	@pre	none.
	*	@post	id�� item�� id���� �۰ų� ������ �Ǻ�.
	*	@param	item	�񱳴��
	*	@return id�� item�� id���� �۰ų� ������ true, �ƴϸ� false�� �����Ѵ�.
	*/
	bool operator<=(SimpleMusicType &item);

	/**
	*	@brief	operator > overloading
	*	@pre	none.
	*	@post	id�� item�� id���� ū�� �Ǻ�.
	*	@param	item	�񱳴��
	*	@return id�� item�� id���� ũ�� true, �ƴϸ� false�� �����Ѵ�.
	*/
	bool operator>(SimpleMusicType &item);

	/**
	*	@brief	operator < overloading
	*	@pre	none.
	*	@post	id�� item�� id���� ������ �Ǻ�.
	*	@param	item	�񱳴��
	*	@return id�� item�� id���� ������ true, �ƴϸ� false�� �����Ѵ�.
	*/
	bool operator<(SimpleMusicType &item);

private:
	string id;		///< music primary key
	string title;   ///< music title
};

#endif // !_SIMPLEMUSICTYPE_H