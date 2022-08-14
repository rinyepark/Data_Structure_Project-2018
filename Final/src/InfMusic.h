#ifndef INFMUSIC_H_
#define INFMUSIC_H_

#include "SortedList.h"
#include "BinarySearchTree.h"
#include "SimpleMusicType.h"
#include "MusicType.h"
#include <iostream>
#include <string>
#include <fstream>
#include <atlstr.h>

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
	*	default constructor with parameter.
	*/
	InfMusic(string name);

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
	*	@post	���ο� �����͸� �����Ͽ� m_List list�� �߰��Ѵ�.
	*	@param	item	�߰��ϰ��� �ϴ� ������.
	*/
	int AddItem(SimpleMusicType item);

	/**
	*	@brief	id�� �������� �׸��� �����Ѵ�.
	*	@pre	list should be initialized.
	*	@post	id�� ������ ���� item�� �̿��� m_List list���� ������ �����ϸ� �����Ѵ�.
	*	@param	item	�����ϰ��� �ϴ� ������.
	*/
	void DeleteItem(SimpleMusicType item);

	/**
	*	@brief	id�� �������� �׸��� �����Ѵ�.
	*	@pre	list should be initialized.
	*	@post	id�� ������ ���� item�� �̿��� m_List list���� �ش� �׸��� ������ �����Ѵ�.
	*	@param	item	�����ϰ��� �ϴ� ������.
	*/
	void RelaceItem(SimpleMusicType item);


	/**
	*	@brief	InfMusic �� m_List�� ����.
	*	@pre	m_List����.
	*	@post	m_List�� �� ����Ʈ�� ��.
	*	@param	command		name������ ���� ���Ǵ� ����..
	*/
	void MakeEmptyList(int& command);

	/**
	*	@brief	item�� ���� ������ �̷��� ������ �׸��� �����ϴ��� �Ǻ�.
	*	@pre	none.
	*	@post	none.
	*	@param	item	ã������ id�� ���� item.
	*	@return �ش� �׸��� ã���� true, ��ã���� false�� ����.
	*/
	bool SearchItem(SimpleMusicType item);


	/**
	*	@brief	ȭ�鿡 ����Ʈ �� ���� ���� �˻��� ���� �ش� ���� ���� ������ ��°� temp_list�� �ش� ���� ����
	*	@pre	m_List�� �����ؾ� ��.
	*	@post	����.
	*	@param	musiclist	�ڼ��� ������ ã���� �ϴ� ����Ʈ
	*	@param	button		������ ���, ��ü ����� �����ϴ� ���
	*	@param	f_title		����ڷκ��� �Է¹��� Ư�� �ܾ� ����.
	*/
	bool SearchDisplay(int button, SortedList<BinarySearchTree<MusicType>> &musiclist, string& f_title);


	/**
	*	@brief	PreOrder�� ������� m_List���� temp�� ������ ������ ������ ã��, ã�´ٸ� musiclist���� �˻��� �ش� ���Ǹ� �ڼ��� ���� ���.
	*	@pre	m_list�� �����ؾ� ��.
	*	@post	����.
	*	@param	musiclist	�ڼ��� ������ ã���� �ϴ� ����Ʈ.
	*	@param	iter		����Ʈ�� ��带 ����Ű�� iterator.
	*	@param	temp		ã���� �ϴ� ������ ����.
	*	@param	found		ã�Ҵ��� ��ã�Ҵ��� �Ǻ�.
	*/
	void SearchTree(const BinarySearchTree<MusicType> &musiclist, Iterator<SimpleMusicType> iter, const string& temp, bool& found);


	/**
	*	@brief	ȭ�鿡 ����Ʈ �� ��� ������ musiclist���� ã�� �ڼ��� ���, PreOrder����� ����� ����.
	*	@pre	m_List�� �����ؾ� ��.
	*	@post	����.
	*	@param	musiclist	�ڼ��� ������ ã���� �ϴ� ����Ʈ
	*	@param	iter		����Ʈ�� ��带 ����Ű�� iterator
	*/
	void DisplayInfList(SortedList<BinarySearchTree<MusicType>> &musiclist, Iterator<SimpleMusicType> iter);

	/**
	*	@brief	DisplaySimpleList�� ȣ���ϱ� ����, �ʿ��� �Ű������� ������ �ش� �Լ��� �����Ͽ� �����Ŵ.
	*	@pre	m_List�� �����ؾ� ��.
	*	@post	����.
	*	@param	command		������ �Ű����� �� �ϳ�.
	*/
	void DisplaySimpleListFirst(const int& command);


	/**
	*	@brief	iter�� ����Ű�� ����Ʈ �� ��Ҹ� ������ ������� ����Ѵ�(count���� ������ ǥ��).
	*	@pre	m_List�� �����ؾ� ��.
	*	@post	����.
	*	@param	iter	����ϰ��� �ϴ� ����Ʈ�� ����Ű�� iterator.	
	*	@param	count	����� ������ ���� ȭ�鿡 ����ϱ� ���� ����.
	*	@param	command	0�̸� count���� ǥ���ϰ�, �� ���� ���ڴ� count���� ǥ������ ����.
	*/
	void DisplaySimpleList(Iterator<SimpleMusicType> iter, int&count, const int& command);


	/**
	*	@brief	��������� ����Ǹ� ȭ�鿡 iter�� ����Ű�� ����Ʈ���� Ư���ܾ �����ϴ� ��Ҹ� �����ϰ� ����ϰ�, temp_list�� �ش� ��Ҹ� �����Ŵ.
	*	@pre	m_List�� �����ؾ� ��.
	*	@post	����.
	*	@param	iter		�˻��ϰ��� �ϴ� ����Ʈ�� ����Ű�� iterator.	
	*	@param	temp		����� ���񿡼� ���ԵǴ��� �˻��Ϸ��� Ư�� �ܾ�.
	*	@param	temp_list	�˻��� ��Ҹ� �ӽ÷� ������ ����Ʈ.
	*/
	void SearchAddTree(Iterator<SimpleMusicType> iter, const string& temp,
		BinarySearchTree<SimpleMusicType>& temp_list);


	/**
	*	@brief	SearchAddTree ȣ���� ���� �ʿ��� �Ű������� �����ϴ� �Լ�.
	*	@pre	m_List�� �����ؾ� ��.
	*	@post	����.
	*	@param	f_title		����� ���񿡼� ���ԵǴ��� �˻��Ϸ��� Ư�� �ܾ��, ����ڷκ��� �Է¹޾� ����.
	*	@param	temp_list	�˻��� ��Ҹ� �ӽ÷� ������ ����Ʈ.
	*/
	bool SearchAddDisplay(string& f_title, BinarySearchTree<SimpleMusicType>& temp_list);


	/**
	*	@brief	InfMusic�� m_List�� ������ ������ ��ȯ.
	*	@pre	m_List ����.
	*	@post	����.
	*	@return	InfMusic�� m_List�� ������ ������ ����.
	*/
	BinarySearchTree<SimpleMusicType>* GetPointInf();


	/**
	*	@brief	InfMusic�� m_List�� ���������� ��ȯ.
	*	@pre	m_List ����.
	*	@post	����.
	*	@return	InfMusic�� m_List�� ���������� ����.
	*/
	BinarySearchTree<SimpleMusicType>& GetAddrInf();



	/**
	*	@brief	����ڷκ��� ������ ����� ������ �Է¹��� ��, m_List ��Ͽ��� �ش� ��Ҹ� ã�� ����.
	*	@pre	m_List ����.
	*	@post	m_List���� Ư�� ��� ������.
	*/
	void SelectMusicDelete();
	

	/**
	*	@brief	�ѱ�, ����, ���� �� ��Ÿ�� ���е� 0~12�� �ε����� inTitle�� ù��° ������ ���� �ش��ϴ� �ε��� �� ��ȯ.
	*	@pre	none.
	*	@post	none.
	*	@param	inTitle		�� ��° �ε����� �������� �˱� ���� ���Ǵ� ����.
	*	@return	�ش� inTitle�� �´� MusicList �� �ε��� ��ȯ.
	*/
	int GetMusicIdx(string& inTitle);

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


	/**
	*	@brief	operator << overloading
	*	@pre	����.
	*	@post	InfMusicTypedml Name�� cout�Ǵ� ������ ����.
	*	@param	out		cout�� ���� ����.
	*	@param	item	cout�� ���
	*	@return item�� ��� ������ �ۼ��� out�� ������.
	*/
	friend ostream& operator<<(ostream& out, InfMusic& item) {
		out << "\t        " << item.GetName() << endl;
		return out;
	}

private:
	string name;								///<information name.
	BinarySearchTree<SimpleMusicType> m_List;   ///<information�� music list.
};

#endif // !INFMUSIC_H_
