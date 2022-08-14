#ifndef DOUBLYITERATOR_H_
#define DOUBLYITERATOR_H_

template <typename T>
struct DoublyNode;
template <typename T>
class DoublyLinkedList;


/**
*	DoublyIterator class.
*/
template <typename T>
class DoublyIterator {
	friend class DoublyLinkedList<T>;
public:

	/**
	*	디폴트 생성자
	*/
	DoublyIterator(const DoublyLinkedList<T>& list);


	/**
	*	@brief	list의 현재 원소가 NULL이 아닌지 검사.
	*	@pre	Iterator가 존재해야함.
	*	@post	없다
	*	@return	현재 원소가 NULL이 아니면 true를, NULL이면 false를 리턴함.
	*/
	bool IsNotNull();

	/**
	*	@brief	list의 다음 원소가 NULL이 아닌지 검사.
	*	@pre	Iterator가 존재해야함.
	*	@post	없다.
	*	@return	다음 원소가 NULL이 아니면 true를, NULL이면 false를 리턴함.
	*/
	bool IsNextNotNull();


	/**
	*	@brief	list의 처음 node의 item을 리턴.
	*	@pre	m_List의 m_pFirst의 data가 존재해야함
	*	@post	없다.
	*	@return	m_List의 m_pFirst의 data를 리턴함.
	*/
	T First();

	/**
	*	@brief	다음 node로 이동하고 해당 node의 data를 리턴.
	*	@pre	Iterator가 존재해야함.
	*	@post	m_pCurPointer가 다음 node로 이동함.
	*	@return	m_pCurPointer의 다음 node가 가리키는 data를 리턴.
	*/
	T Next();

	/**
	*	@brief	이전 node로 이동하고 해당 node의 data를 리턴.
	*	@pre	Iterator가 존재해야함.
	*	@post	m_pCurPointer가 이전 node로 이동함.
	*	@return	m_pCurPointer의 이전 node가 가리키는 data를 리턴.
	*/
	T Prev();

	/**
	*	@brief	현재 data를 리턴.
	*	@pre	Iterator가 존재해야함.
	*	@post	없다.
	*	@return	현재 m_pCurPointer가 가리키는 data를 리턴.
	*/
	T GetCurrentdata();

private:
	DoublyNode<T> *m_pCurPointer;		///< 노드를 가리킬 포인터
	const DoublyLinkedList<T> &m_list;	///< 사용할 리스트의 참조 변수
};

#endif // !DOUBLYITERATOR_H_


// default constructor.
template <typename T>
DoublyIterator<T>::DoublyIterator(const DoublyLinkedList<T> &list) :
	m_list(list), m_pCurPointer(list.m_pFirst) {}



//list의 현재 원소가 NULL이 아닌지 검사.
template <typename T>
bool DoublyIterator<T>::IsNotNull() {
	if (m_pCurPointer != NULL)
		return true;
	else
		return false;
}
//list의 다음 원소가 NULL이 아닌지 검사.
template <typename T>
bool DoublyIterator<T>::IsNextNotNull() {
	if (m_pCurPointer->next != NULL)
		return true;
	else
		return false;
}


//list의 처음 node의 item을 리턴.
template <typename T>
T DoublyIterator<T>::First() {
	T result = m_list.m_pFirst->data;
	return result;
}

//다음 node로 이동하고 해당 node의 data를 리턴.
template <typename T>
T DoublyIterator<T>::Next() {
	m_pCurPointer = m_pCurPointer->next;
	return m_pCurPointer->data;
}

//이전 node로 이동하고 해당 node의 data를 리턴.
template <typename T>
T DoublyIterator<T>::Prev() {
	m_pCurPointer = m_pCurPointer->prev;
	return m_pCurPointer->data;
}


//현재 node의 data를 리턴.
template <typename T>
T DoublyIterator<T>::GetCurrentdata() {
	return m_pCurPointer->data;
}
