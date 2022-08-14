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
	*	@brief	id를 기준으로 정렬이 되도록 알맞은 자리에 항목을 추가한다.
	*	@pre	list should be initialized.
	*	@post	새로운 데이터를 정렬하여 m_List list에 추가한다.
	*	@param	item	추가하고자 하는 데이터.
	*/
	int AddItem(SimpleMusicType item);

	/**
	*	@brief	id를 기준으로 항목을 제거한다.
	*	@pre	list should be initialized.
	*	@post	id의 정보만 가진 item을 이용해 m_List list에서 정렬을 유지하며 제거한다.
	*	@param	item	제거하고자 하는 데이터.
	*/
	void DeleteItem(SimpleMusicType item);

	/**
	*	@brief	id를 기준으로 항목을 변경한다.
	*	@pre	list should be initialized.
	*	@post	id의 정보만 가진 item을 이용해 m_List list에서 해당 항목의 정보를 변경한다.
	*	@param	item	변경하고자 하는 데이터.
	*/
	void RelaceItem(SimpleMusicType item);


	/**
	*	@brief	InfMusic 내 m_List를 비운다.
	*	@pre	m_List존재.
	*	@post	m_List가 빈 리스트가 됨.
	*	@param	command		name설정을 위해 사용되는 변수..
	*/
	void MakeEmptyList(int& command);

	/**
	*	@brief	item이 가진 정보로 이뤄진 음악이 항목이 존재하는지 판별.
	*	@pre	none.
	*	@post	none.
	*	@param	item	찾으려는 id를 가진 item.
	*	@return 해당 항목을 찾으면 true, 못찾으면 false를 리턴.
	*/
	bool SearchItem(SimpleMusicType item);


	/**
	*	@brief	화면에 리스트 내 음악 제목 검색을 통해 해당 음악 정보 간단히 출력과 temp_list내 해당 음악 저장
	*	@pre	m_List가 존재해야 함.
	*	@post	없다.
	*	@param	musiclist	자세한 정보를 찾고자 하는 리스트
	*	@param	button		선택적 출력, 전체 출력을 결정하는 요소
	*	@param	f_title		사용자로부터 입력받을 특정 단어 변수.
	*/
	bool SearchDisplay(int button, SortedList<BinarySearchTree<MusicType>> &musiclist, string& f_title);


	/**
	*	@brief	PreOrder의 방식으로 m_List에서 temp를 포함한 제목의 정보를 찾고, 찾는다면 musiclist에서 검색해 해당 음악만 자세한 정보 출력.
	*	@pre	m_list가 존재해야 함.
	*	@post	없다.
	*	@param	musiclist	자세한 정보를 찾고자 하는 리스트.
	*	@param	iter		리스트의 노드를 가리키는 iterator.
	*	@param	temp		찾고자 하는 제목의 정보.
	*	@param	found		찾았는지 못찾았는지 판별.
	*/
	void SearchTree(const BinarySearchTree<MusicType> &musiclist, Iterator<SimpleMusicType> iter, const string& temp, bool& found);


	/**
	*	@brief	화면에 리스트 내 모든 정보를 musiclist에서 찾아 자세히 출력, PreOrder방식의 출력을 가짐.
	*	@pre	m_List가 존재해야 함.
	*	@post	없다.
	*	@param	musiclist	자세한 정보를 찾고자 하는 리스트
	*	@param	iter		리스트의 노드를 가리키는 iterator
	*/
	void DisplayInfList(SortedList<BinarySearchTree<MusicType>> &musiclist, Iterator<SimpleMusicType> iter);

	/**
	*	@brief	DisplaySimpleList를 호출하기 이전, 필요한 매개변수를 생성해 해당 함수에 전달하여 실행시킴.
	*	@pre	m_List가 존재해야 함.
	*	@post	없다.
	*	@param	command		전달할 매개변수 중 하나.
	*/
	void DisplaySimpleListFirst(const int& command);


	/**
	*	@brief	iter가 가리키는 리스트 내 요소를 간단한 방식으로 출력한다(count값은 선택적 표기).
	*	@pre	m_List가 존재해야 함.
	*	@post	없다.
	*	@param	iter	출력하고자 하는 리스트를 가리키는 iterator.	
	*	@param	count	요소의 개수를 세어 화면에 출력하기 위한 변수.
	*	@param	command	0이면 count값을 표기하고, 그 외의 숫자는 count값을 표기하지 않음.
	*/
	void DisplaySimpleList(Iterator<SimpleMusicType> iter, int&count, const int& command);


	/**
	*	@brief	재귀적으로 실행되며 화면에 iter가 가리키는 리스트에서 특정단어를 포함하는 요소를 간단하게 출력하고, temp_list에 해당 요소를 저장시킴.
	*	@pre	m_List가 존재해야 함.
	*	@post	없다.
	*	@param	iter		검색하고자 하는 리스트를 가리키는 iterator.	
	*	@param	temp		요소의 제목에서 포함되는지 검색하려는 특정 단어.
	*	@param	temp_list	검색된 요소를 임시로 저장할 리스트.
	*/
	void SearchAddTree(Iterator<SimpleMusicType> iter, const string& temp,
		BinarySearchTree<SimpleMusicType>& temp_list);


	/**
	*	@brief	SearchAddTree 호출을 위해 필요한 매개변수를 전달하는 함수.
	*	@pre	m_List가 존재해야 함.
	*	@post	없다.
	*	@param	f_title		요소의 제목에서 포함되는지 검색하려는 특정 단어로, 사용자로부터 입력받아 생성.
	*	@param	temp_list	검색된 요소를 임시로 저장할 리스트.
	*/
	bool SearchAddDisplay(string& f_title, BinarySearchTree<SimpleMusicType>& temp_list);


	/**
	*	@brief	InfMusic의 m_List의 포인터 형으로 반환.
	*	@pre	m_List 존재.
	*	@post	없음.
	*	@return	InfMusic의 m_List의 포인터 형으로 리턴.
	*/
	BinarySearchTree<SimpleMusicType>* GetPointInf();


	/**
	*	@brief	InfMusic의 m_List의 참조변수로 반환.
	*	@pre	m_List 존재.
	*	@post	없음.
	*	@return	InfMusic의 m_List의 참조변수로 리턴.
	*/
	BinarySearchTree<SimpleMusicType>& GetAddrInf();



	/**
	*	@brief	사용자로부터 삭제할 요소의 정보를 입력받은 후, m_List 목록에서 해당 요소를 찾아 삭제.
	*	@pre	m_List 존재.
	*	@post	m_List에서 특정 요소 삭제됨.
	*/
	void SelectMusicDelete();
	

	/**
	*	@brief	한글, 영어, 숫자 및 기타로 구분된 0~12의 인덱스를 inTitle의 첫번째 값으로 비교해 해당하는 인덱스 값 반환.
	*	@pre	none.
	*	@post	none.
	*	@param	inTitle		몇 번째 인덱스를 가졌는지 알기 위해 사용되는 변수.
	*	@return	해당 inTitle에 맞는 MusicList 내 인덱스 반환.
	*/
	int GetMusicIdx(string& inTitle);

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


	/**
	*	@brief	operator << overloading
	*	@pre	없음.
	*	@post	InfMusicTypedml Name이 cout되는 형식을 결정.
	*	@param	out		cout할 형식 전달.
	*	@param	item	cout할 대상
	*	@return item의 출력 형식을 작성한 out을 리턴함.
	*/
	friend ostream& operator<<(ostream& out, InfMusic& item) {
		out << "\t        " << item.GetName() << endl;
		return out;
	}

private:
	string name;								///<information name.
	BinarySearchTree<SimpleMusicType> m_List;   ///<information별 music list.
};

#endif // !INFMUSIC_H_
