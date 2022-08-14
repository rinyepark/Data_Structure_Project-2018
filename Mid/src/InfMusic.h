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
	*	@brief	id�� �������� ������ �ǵ��� �˸��� �ڸ��� �׸��� �߰��Ѵ�.
	*	@pre	list should be initialized.
	*	@post	���ο� �����͸� �����Ͽ� m_Inf list�� �߰��Ѵ�.
	*	@param	item	�߰��ϰ��� �ϴ� ������.
	*/
	void AddItem(SimpleMusicType item); 

	/**
	*	@brief	id�� �������� �׸��� �����Ѵ�.
	*	@pre	list should be initialized.
	*	@post	id�� ������ ���� item�� �̿��� m_Inf list���� ������ �����ϸ� �����Ѵ�.
	*	@param	item	�����ϰ��� �ϴ� ������.
	*/
	void DeleteItem(SimpleMusicType item); 

	/**
	*	@brief	id�� �������� �׸��� �����Ѵ�.
	*	@pre	list should be initialized.
	*	@post	id�� ������ ���� item�� �̿��� m_Inf list���� �ش� �׸��� ������ �����Ѵ�.
	*	@param	item	�����ϰ��� �ϴ� ������.
	*/
	void RelaceItem(SimpleMusicType item);


	/**
	*	@brief	id�� �������� �׸��� �����ϴ��� �Ǻ�.
	*	@pre	none.
	*	@post	id�� �������� �׸��� �����ϸ� true/false�� �����Ѵ�.
	*	@param	inId	ã������ id
	*	@return ������ id�� ã���� true, ��ã���� false�� ����.
	*/
	bool SearchItem(string inId);

	/**
	*	@brief	�� ���� �̿��� �ش� m_Inf list���� ��ġ�ϴ� ���� ã�� ���.
	*	@pre	m_Inf list�� �����ؾ� ��.
	*	@post	�� ���� �̿��� �ش� ���� Ÿ�Կ��� ��ġ�ϴ� ������ ã��, �� ������ musiclist���� ã�� �ڼ��� ���� ȭ�鿡 ���.
	*	@param	inTitle		ã���� �ϴ� ���.
	*	@param	musiclist	�ڼ��� ������ ã���� �ϴ� ����Ʈ�� ����������.
	*/
	void DisplaySearchByTitle(string inTitle, SortedList<MusicType> *musiclist);
	
	

	/**
	*	@brief	Display information list on screen.
	*	@pre	information list�� �����ؾ� ��.
	*	@post	information list�� �ִ� ������ musiclist���� ã�� �ڼ��� ���� ȭ�鿡 ���.
	*	@param	musiclist	�ڼ��� ������ ã���� �ϴ� ����Ʈ�� ����������.
	*/
	void DisplayInfList(SortedList<MusicType> *musiclist);
	

	/**
	*	@brief	operator == overloading
	*	@pre	none.
	*	@post	name�� item�� name�� �������� �Ǻ�.
	*	@param	item	�񱳴��
	*	@return name�� item�� name�� ��ġ�ϸ� true, �ƴϸ� false�� �����Ѵ�.
	*/
	bool operator==(InfMusic &item);

	/**
	*	@brief	operator != overloading
	*	@pre	none.
	*	@post	name�� item�� name�� �ٸ��� �Ǻ�.
	*	@param	item	�񱳴��
	*	@return item�� name�� �ٸ��� true, ������ false�� �����Ѵ�.
	*/
	bool operator!=(InfMusic &item);


	/**
	*	@brief	operator >= overloading
	*	@pre	none.
	*	@post	name�� item�� name���� ũ�ų� ������ �Ǻ�.
	*	@param	item	�񱳴��
	*	@return name�� item�� name���� ũ�ų� ������ true, �ƴϸ� false�� �����Ѵ�.
	*/
	bool operator>=(InfMusic &item);

	/**
	*	@brief	operator <= overloading
	*	@pre	none.
	*	@post	name�� item�� name���� �۰ų� ������ �Ǻ�.
	*	@param	item	�񱳴��
	*	@return name�� item�� name���� �۰ų� ������ true, �ƴϸ� false�� �����Ѵ�.
	*/
	bool operator<=(InfMusic &item);

	/**
	*	@brief	operator > overloading
	*	@pre	none.
	*	@post	name�� item�� name���� ū�� �Ǻ�.
	*	@param	item	�񱳴��
	*	@return name�� item�� name���� ũ�� true, �ƴϸ� false�� �����Ѵ�.
	*/
	bool operator>(InfMusic &item);

	/**
	*	@brief	operator < overloading
	*	@pre	none.
	*	@post	name�� item�� name���� ������ �Ǻ�.
	*	@param	item	�񱳴��
	*	@return name�� item�� name���� ������ true, �ƴϸ� false�� �����Ѵ�.
	*/
	bool operator<(InfMusic &item);

private:
	string name;								///<information name.
	SingleLinkedList<SimpleMusicType> m_Inf;    ///<information�� music list.
};

#endif // !INFMUSIC_H_