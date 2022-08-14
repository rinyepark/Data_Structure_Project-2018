#ifndef INFMUSIC_H_
#define INFMUSIC_H_

#include "SingleLinkedList.h"
#include "SortedList.h"
#include "SimpleMusicType.h"
#include "MusicType.h"
#include <iostream>
#include <string>
#include <fstream>

using namespace std;


/**
*	information class.
*/
class InfMusic {
public:

	/**
	*	default constructor.
	*/
	InfMusic();

	/**
	*	copy constructor.
	*/
	InfMusic(const InfMusic& anotherInf);

	/**
	*	destructor.
	*/
	~InfMusic();

	/**
	*	@brief	Get a number of records in list.
	*	@pre	none.
	*	@post	none.
	*	@return	number of records in list.
	*/
	int GetListLength();


	/**
	*	@brief	Get information name.
	*	@pre	information name is set.
	*	@post	none.
	*	@return	information name.
	*/
	string GetName();

	/**
	*	@brief	Set information name.
	*	@pre	none.
	*	@post	information name is set.
	*	@param	inName    information name.
	*/
	void SetName(string inName);

	/**
	*	@brief	id를 기준으로 정렬이 되도록 알맞은 자리에 항목을 추가한다.
	*	@pre	list should be initialized.
	*	@post	새로운 데이터를 정렬하여 m_Inf list에 추가한다.
	*	@param	item	추가하고자 하는 데이터.
	*/
	void AddItem(SimpleMusicType item); 

	/**
	*	@brief	id를 기준으로 항목을 제거한다.
	*	@pre	list should be initialized.
	*	@post	id의 정보만 가진 item을 이용해 m_Inf list에서 정렬을 유지하며 제거한다.
	*	@param	item	제거하고자 하는 데이터.
	*/
	void DeleteItem(SimpleMusicType item); 

	/**
	*	@brief	id를 기준으로 항목을 변경한다.
	*	@pre	list should be initialized.
	*	@post	id의 정보만 가진 item을 이용해 m_Inf list에서 해당 항목의 정보를 변경한다.
	*	@param	item	변경하고자 하는 데이터.
	*/
	void RelaceItem(SimpleMusicType item);


	/**
	*	@brief	id를 기준으로 항목이 존재하는지 판별.
	*	@pre	none.
	*	@post	id를 기준으로 항목이 존재하면 true/false를 리턴한다.
	*	@param	inId	찾으려는 id
	*	@return 동일한 id를 찾으면 true, 못찾으면 false를 리턴.
	*/
	bool SearchItem(string inId);

	/**
	*	@brief	곡 명을 이용해 해당 m_Inf list에서 일치하는 정보 찾아 출력.
	*	@pre	m_Inf list가 존재해야 함.
	*	@post	곡 명을 이용해 해당 정보 타입에서 일치하는 정보를 찾고, 그 정보를 musiclist에서 찾아 자세한 내용 화면에 출력.
	*	@param	inTitle		찾고자 하는 곡명.
	*	@param	musiclist	자세한 정보를 찾고자 하는 리스트의 포인터형식.
	*/
	void DisplaySearchByTitle(string inTitle, SortedList<MusicType> *musiclist);
	
	

	/**
	*	@brief	Display information list on screen.
	*	@pre	information list가 존재해야 함.
	*	@post	information list에 있는 정보를 musiclist에서 찾아 자세한 내용 화면에 출력.
	*	@param	musiclist	자세한 정보를 찾고자 하는 리스트의 포인터형식.
	*/
	void DisplayInfList(SortedList<MusicType> *musiclist);
	

	/**
	*	@brief	operator == overloading
	*	@pre	none.
	*	@post	name과 item의 name이 동일한지 판별.
	*	@param	item	비교대상
	*	@return name이 item의 name과 일치하면 true, 아니면 false를 리턴한다.
	*/
	bool operator==(InfMusic &item);

	/**
	*	@brief	operator != overloading
	*	@pre	none.
	*	@post	name과 item의 name이 다른지 판별.
	*	@param	item	비교대상
	*	@return item의 name과 다르면 true, 같으면 false를 리턴한다.
	*/
	bool operator!=(InfMusic &item);


	/**
	*	@brief	operator >= overloading
	*	@pre	none.
	*	@post	name이 item의 name보다 크거나 같은지 판별.
	*	@param	item	비교대상
	*	@return name이 item의 name보다 크거나 같으면 true, 아니면 false를 리턴한다.
	*/
	bool operator>=(InfMusic &item);

	/**
	*	@brief	operator <= overloading
	*	@pre	none.
	*	@post	name이 item의 name보다 작거나 같은지 판별.
	*	@param	item	비교대상
	*	@return name이 item의 name보다 작거나 같으면 true, 아니면 false를 리턴한다.
	*/
	bool operator<=(InfMusic &item);

	/**
	*	@brief	operator > overloading
	*	@pre	none.
	*	@post	name이 item의 name보다 큰지 판별.
	*	@param	item	비교대상
	*	@return name이 item의 name보다 크면 true, 아니면 false를 리턴한다.
	*/
	bool operator>(InfMusic &item);

	/**
	*	@brief	operator < overloading
	*	@pre	none.
	*	@post	name이 item의 name보다 작은지 판별.
	*	@param	item	비교대상
	*	@return name이 item의 name보다 작으면 true, 아니면 false를 리턴한다.
	*/
	bool operator<(InfMusic &item);

private:
	string name;								///<information name.
	SingleLinkedList<SimpleMusicType> m_Inf;    ///<information별 music list.
};

#endif // !INFMUSIC_H_