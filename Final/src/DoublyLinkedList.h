#ifndef DOUBLYSORTEDLINKEDLIST_H_
#define DOUBLYSORTEDLINKEDLIST_H_

#include "DoublyIterator.h"

template<typename T>
class DoublyIterator;


/**
*	node type struct.
*/
template <typename T>
struct DoublyNode {
	T data;					///< NodeType의 정보
	DoublyNode<T> *prev;	///< 이전 노드를 가리킬 포인터
	DoublyNode<T> *next;   ///< 다음 노드를 가리킬 포인터
};


/**
*	doubly unsorted circular linked list.
*/
template <typename T>
class DoublyLinkedList {
	friend class DoublyIterator<T>;
public:

	/**
	*	defalut constructor.
	*/
	DoublyLinkedList();

	/**
	*	copy constructor.
	*/
	DoublyLinkedList(const DoublyLinkedList<T>& anList);

	/**
	*	destructor.
	*/
	~DoublyLinkedList();



	/**
	*	@brief	리스트가 비어있는지 확인함.
	*	@pre	none.
	*	@post	none.
	*	@return	리스트가 비어있으면 true, 비어있지 않으면 false를 리턴함.
	*/
	bool IsEmpty();


	/**
	*	@brief	리스트가 꽉 차는지 확인함.
	*	@pre	none.
	*	@post	none.
	*	@return	리스트에 더 이상 요소를 추가할 수 없으면 true, 추가할 수 있으면 false를 리턴함.
	*/
	bool IsFull();



	/**
	*	@brief	primary key(num)를 기준으로 정렬이 되도록 새로운 레코드를 리스트에 삽입함.
	*	@pre	리스트가 존재해야 함.
	*	@post	새로운 데이터를 정렬하여 리스트에 추가한다.
	*	@param	item	추가하고자 하는 데이터.
	*/
	int Add(T item);


	/**
	*	@brief	Doubly sorted linked list에 연결된 레코드 모두 삭제.
	*	@pre	none.
	*	@post	Doubly sorted linked list에 연결되어 있는 node를 모두 삭제하여 m_pFirst와 m_pLast노드만 남아있는 list를 만든다.
	*/
	void MakeEmpty();


	/**
	*	@brief	현재 리스트 내 존재하는 레코드 수를 반환.
	*	@pre	none.
	*	@post	none.
	*	@return	현재 레코드 수를 반환
	*/
	int GetLength() const;


	/**
	*	@brief	operator = overloading
	*	@pre	none.
	*	@post	리스트를 anList의 리스트와 동일하게 정의해준다.
	*	@param	anList		정보를 가져올 대상
	*	@return anList의 정보를 정의한 this*를 리턴.
	*/
	const DoublyLinkedList<T>& operator=(const DoublyLinkedList<T> &anList);



private:
	DoublyNode<T> *m_pFirst;	///< DoublyNodeType의 m_pFirst 포인터
	DoublyNode<T> *m_pLast;		///< DoublyNodeType의 m_pLast 포인터
	int m_nLength;				///< 리스트에 저장된 레코드 수
};

#endif // !DOUBLYSORTEDLINKEDLIST_H_

// default constructor.
template<typename T>
DoublyLinkedList<T>::DoublyLinkedList() {
	m_nLength = 0;
	m_pFirst = NULL;
	m_pLast = NULL;
}

// copy constructor.
template<typename T>
DoublyLinkedList<T>::DoublyLinkedList(const DoublyLinkedList<T>& anList) {
}

// destructor
template<typename T>
DoublyLinkedList<T>::~DoublyLinkedList() {
	MakeEmpty(); // First와 Last노드에 연결된 모든 노드 삭제
}


// 리스트가 비어있는지 확인.
template<typename T>
bool DoublyLinkedList<T>::IsEmpty() {
	if (m_nLength == 0) //길이가 0이면 비어있는 리스트이므로 true 리턴.
		return true;
	else
		return false;
}
// 리스트가 꽉 차있는지 확인.
template<typename T>
bool DoublyLinkedList<T>::IsFull() {
	try {
		DoublyNode<T> *temp = new DoublyNode<T>;
		delete temp;
		return false;	// 새로운 노드를 할당할 수 있으면 false를 리턴.
	}
	catch (bad_alloc exception) {
		return true;	// 예외가 발생하면 true를 리턴.
	}
}


//새로운 레코드를 정렬하면서 리스트에 삽입
template<typename T>
int DoublyLinkedList<T>::Add(T item) {
	// add_node를 생성해 item을 add_node의 data에 지정.
	DoublyNode<T> *add_node = new DoublyNode<T>;
	add_node->data = item;

	if (IsEmpty()) {	//처음 추가하는 경우
		m_pFirst = add_node;
		m_pLast = add_node;
		add_node->prev = add_node;	//자기자신을 가리키도록 설정
		add_node->next = add_node;
	}
	else {	// 처음 추가하는게 아닌 경우, Unsorted이기 때문에 앞에서부터 추가됨
		add_node->next = m_pFirst;
		add_node->prev = m_pLast;
		m_pFirst->prev = add_node;
		m_pFirst = add_node;
		m_pLast->next = add_node;
	}
	m_nLength++;
	return 1;

}


// Doubly sorted linked list에 연결된 레코드 모두 삭제.
template<typename T>
void DoublyLinkedList<T>::MakeEmpty() {

	if (!IsEmpty()) {
		DoublyIterator<T> iter(*this);	//iterator 생성

		// DoublyLinkedList의 길이가 0이되면 반복문 종료
		while (m_nLength !=0) {
			DoublyNode<T> *del_temp; // 데이터 삭제 시 사용하는 임시 포인터 생성
			del_temp = iter.m_pCurPointer;	//포인터가 현재 노드 가리키도록 지정.

			//앞뒤 새로 연결
			iter.m_pCurPointer->next->prev = iter.m_pCurPointer->prev;
			iter.m_pCurPointer->prev->next = iter.m_pCurPointer->next;
			m_pFirst = iter.m_pCurPointer->next; //First가 지우고자 하는 노드의 다음노드를 가리키도록

			//다음으로 넘어가기****(삭제 후 다음으로 넘어가려하면 dangling pointer 에러발생)
			iter.Next();

			//해당 노드 삭제
			delete del_temp;
			m_nLength--; //길이감소
		}
		m_pFirst = NULL;
		m_pLast = NULL;
	}


}

//현재 리스트 내 존재하는 레코드 수 반환.
template<typename T>
int DoublyLinkedList<T>::GetLength() const {
	return m_nLength;
}

//operator = overoading
template<typename T>
const DoublyLinkedList<T>& DoublyLinkedList<T>::operator=(const DoublyLinkedList<T> &anList) {
	if (this != &anList) {	// this가 anList가 아닌 경우
		MakeEmpty();	// this를 빈 list로 만듦
	}
	return *this;	//this반환
}


