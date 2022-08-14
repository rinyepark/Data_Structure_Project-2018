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
	*	@post	id와 item의  id가 동일한지 판별.
	*	@param	item	비교대상
	*	@return item의 id와 일치하면 true, 아니면 false를 리턴한다.
	*/
	bool operator==(SimpleMusicType &item);

	/**
	*	@brief	operator != overloading
	*	@pre	none.
	*	@post	id와 item의 id가 다른지 판별.
	*	@param	item	비교대상
	*	@return item의 id와 다르면 true, 같으면 false를 리턴한다.
	*/
	bool operator!=(SimpleMusicType &item);

	/**
	*	@brief	operator >= overloading
	*	@pre	none.
	*	@post	id가 item의 id보다 크거나 같은지 판별.
	*	@param	item	비교대상
	*	@return id가 item의  id보다 크거나 같으면 true, 아니면 false를 리턴한다.
	*/
	bool operator>=(SimpleMusicType &item);

	/**
	*	@brief	operator <= overloading
	*	@pre	none.
	*	@post	id가 item의 id보다 작거나 같은지 판별.
	*	@param	item	비교대상
	*	@return id가 item의 id보다 작거나 같으면 true, 아니면 false를 리턴한다.
	*/
	bool operator<=(SimpleMusicType &item);

	/**
	*	@brief	operator > overloading
	*	@pre	none.
	*	@post	id가 item의 id보다 큰지 판별.
	*	@param	item	비교대상
	*	@return id가 item의 id보다 크면 true, 아니면 false를 리턴한다.
	*/
	bool operator>(SimpleMusicType &item);

	/**
	*	@brief	operator < overloading
	*	@pre	none.
	*	@post	id가 item의 id보다 작은지 판별.
	*	@param	item	비교대상
	*	@return id가 item의 id보다 작으면 true, 아니면 false를 리턴한다.
	*/
	bool operator<(SimpleMusicType &item);

private:
	string id;		///< music primary key
	string title;   ///< music title
};

#endif // !_SIMPLEMUSICTYPE_H