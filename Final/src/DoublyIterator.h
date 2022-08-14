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
	*	����Ʈ ������
	*/
	DoublyIterator(const DoublyLinkedList<T>& list);


	/**
	*	@brief	list�� ���� ���Ұ� NULL�� �ƴ��� �˻�.
	*	@pre	Iterator�� �����ؾ���.
	*	@post	����
	*	@return	���� ���Ұ� NULL�� �ƴϸ� true��, NULL�̸� false�� ������.
	*/
	bool IsNotNull();

	/**
	*	@brief	list�� ���� ���Ұ� NULL�� �ƴ��� �˻�.
	*	@pre	Iterator�� �����ؾ���.
	*	@post	����.
	*	@return	���� ���Ұ� NULL�� �ƴϸ� true��, NULL�̸� false�� ������.
	*/
	bool IsNextNotNull();


	/**
	*	@brief	list�� ó�� node�� item�� ����.
	*	@pre	m_List�� m_pFirst�� data�� �����ؾ���
	*	@post	����.
	*	@return	m_List�� m_pFirst�� data�� ������.
	*/
	T First();

	/**
	*	@brief	���� node�� �̵��ϰ� �ش� node�� data�� ����.
	*	@pre	Iterator�� �����ؾ���.
	*	@post	m_pCurPointer�� ���� node�� �̵���.
	*	@return	m_pCurPointer�� ���� node�� ����Ű�� data�� ����.
	*/
	T Next();

	/**
	*	@brief	���� node�� �̵��ϰ� �ش� node�� data�� ����.
	*	@pre	Iterator�� �����ؾ���.
	*	@post	m_pCurPointer�� ���� node�� �̵���.
	*	@return	m_pCurPointer�� ���� node�� ����Ű�� data�� ����.
	*/
	T Prev();

	/**
	*	@brief	���� data�� ����.
	*	@pre	Iterator�� �����ؾ���.
	*	@post	����.
	*	@return	���� m_pCurPointer�� ����Ű�� data�� ����.
	*/
	T GetCurrentdata();

private:
	DoublyNode<T> *m_pCurPointer;		///< ��带 ����ų ������
	const DoublyLinkedList<T> &m_list;	///< ����� ����Ʈ�� ���� ����
};

#endif // !DOUBLYITERATOR_H_


// default constructor.
template <typename T>
DoublyIterator<T>::DoublyIterator(const DoublyLinkedList<T> &list) :
	m_list(list), m_pCurPointer(list.m_pFirst) {}



//list�� ���� ���Ұ� NULL�� �ƴ��� �˻�.
template <typename T>
bool DoublyIterator<T>::IsNotNull() {
	if (m_pCurPointer != NULL)
		return true;
	else
		return false;
}
//list�� ���� ���Ұ� NULL�� �ƴ��� �˻�.
template <typename T>
bool DoublyIterator<T>::IsNextNotNull() {
	if (m_pCurPointer->next != NULL)
		return true;
	else
		return false;
}


//list�� ó�� node�� item�� ����.
template <typename T>
T DoublyIterator<T>::First() {
	T result = m_list.m_pFirst->data;
	return result;
}

//���� node�� �̵��ϰ� �ش� node�� data�� ����.
template <typename T>
T DoublyIterator<T>::Next() {
	m_pCurPointer = m_pCurPointer->next;
	return m_pCurPointer->data;
}

//���� node�� �̵��ϰ� �ش� node�� data�� ����.
template <typename T>
T DoublyIterator<T>::Prev() {
	m_pCurPointer = m_pCurPointer->prev;
	return m_pCurPointer->data;
}


//���� node�� data�� ����.
template <typename T>
T DoublyIterator<T>::GetCurrentdata() {
	return m_pCurPointer->data;
}
