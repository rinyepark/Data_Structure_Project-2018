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
	T data;					///< NodeType�� ����
	DoublyNode<T> *prev;	///< ���� ��带 ����ų ������
	DoublyNode<T> *next;   ///< ���� ��带 ����ų ������
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
	*	@brief	����Ʈ�� ����ִ��� Ȯ����.
	*	@pre	none.
	*	@post	none.
	*	@return	����Ʈ�� ��������� true, ������� ������ false�� ������.
	*/
	bool IsEmpty();


	/**
	*	@brief	����Ʈ�� �� ������ Ȯ����.
	*	@pre	none.
	*	@post	none.
	*	@return	����Ʈ�� �� �̻� ��Ҹ� �߰��� �� ������ true, �߰��� �� ������ false�� ������.
	*/
	bool IsFull();



	/**
	*	@brief	primary key(num)�� �������� ������ �ǵ��� ���ο� ���ڵ带 ����Ʈ�� ������.
	*	@pre	����Ʈ�� �����ؾ� ��.
	*	@post	���ο� �����͸� �����Ͽ� ����Ʈ�� �߰��Ѵ�.
	*	@param	item	�߰��ϰ��� �ϴ� ������.
	*/
	int Add(T item);


	/**
	*	@brief	Doubly sorted linked list�� ����� ���ڵ� ��� ����.
	*	@pre	none.
	*	@post	Doubly sorted linked list�� ����Ǿ� �ִ� node�� ��� �����Ͽ� m_pFirst�� m_pLast��常 �����ִ� list�� �����.
	*/
	void MakeEmpty();


	/**
	*	@brief	���� ����Ʈ �� �����ϴ� ���ڵ� ���� ��ȯ.
	*	@pre	none.
	*	@post	none.
	*	@return	���� ���ڵ� ���� ��ȯ
	*/
	int GetLength() const;


	/**
	*	@brief	operator = overloading
	*	@pre	none.
	*	@post	����Ʈ�� anList�� ����Ʈ�� �����ϰ� �������ش�.
	*	@param	anList		������ ������ ���
	*	@return anList�� ������ ������ this*�� ����.
	*/
	const DoublyLinkedList<T>& operator=(const DoublyLinkedList<T> &anList);



private:
	DoublyNode<T> *m_pFirst;	///< DoublyNodeType�� m_pFirst ������
	DoublyNode<T> *m_pLast;		///< DoublyNodeType�� m_pLast ������
	int m_nLength;				///< ����Ʈ�� ����� ���ڵ� ��
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
	MakeEmpty(); // First�� Last��忡 ����� ��� ��� ����
}


// ����Ʈ�� ����ִ��� Ȯ��.
template<typename T>
bool DoublyLinkedList<T>::IsEmpty() {
	if (m_nLength == 0) //���̰� 0�̸� ����ִ� ����Ʈ�̹Ƿ� true ����.
		return true;
	else
		return false;
}
// ����Ʈ�� �� ���ִ��� Ȯ��.
template<typename T>
bool DoublyLinkedList<T>::IsFull() {
	try {
		DoublyNode<T> *temp = new DoublyNode<T>;
		delete temp;
		return false;	// ���ο� ��带 �Ҵ��� �� ������ false�� ����.
	}
	catch (bad_alloc exception) {
		return true;	// ���ܰ� �߻��ϸ� true�� ����.
	}
}


//���ο� ���ڵ带 �����ϸ鼭 ����Ʈ�� ����
template<typename T>
int DoublyLinkedList<T>::Add(T item) {
	// add_node�� ������ item�� add_node�� data�� ����.
	DoublyNode<T> *add_node = new DoublyNode<T>;
	add_node->data = item;

	if (IsEmpty()) {	//ó�� �߰��ϴ� ���
		m_pFirst = add_node;
		m_pLast = add_node;
		add_node->prev = add_node;	//�ڱ��ڽ��� ����Ű���� ����
		add_node->next = add_node;
	}
	else {	// ó�� �߰��ϴ°� �ƴ� ���, Unsorted�̱� ������ �տ������� �߰���
		add_node->next = m_pFirst;
		add_node->prev = m_pLast;
		m_pFirst->prev = add_node;
		m_pFirst = add_node;
		m_pLast->next = add_node;
	}
	m_nLength++;
	return 1;

}


// Doubly sorted linked list�� ����� ���ڵ� ��� ����.
template<typename T>
void DoublyLinkedList<T>::MakeEmpty() {

	if (!IsEmpty()) {
		DoublyIterator<T> iter(*this);	//iterator ����

		// DoublyLinkedList�� ���̰� 0�̵Ǹ� �ݺ��� ����
		while (m_nLength !=0) {
			DoublyNode<T> *del_temp; // ������ ���� �� ����ϴ� �ӽ� ������ ����
			del_temp = iter.m_pCurPointer;	//�����Ͱ� ���� ��� ����Ű���� ����.

			//�յ� ���� ����
			iter.m_pCurPointer->next->prev = iter.m_pCurPointer->prev;
			iter.m_pCurPointer->prev->next = iter.m_pCurPointer->next;
			m_pFirst = iter.m_pCurPointer->next; //First�� ������� �ϴ� ����� ������带 ����Ű����

			//�������� �Ѿ��****(���� �� �������� �Ѿ���ϸ� dangling pointer �����߻�)
			iter.Next();

			//�ش� ��� ����
			delete del_temp;
			m_nLength--; //���̰���
		}
		m_pFirst = NULL;
		m_pLast = NULL;
	}


}

//���� ����Ʈ �� �����ϴ� ���ڵ� �� ��ȯ.
template<typename T>
int DoublyLinkedList<T>::GetLength() const {
	return m_nLength;
}

//operator = overoading
template<typename T>
const DoublyLinkedList<T>& DoublyLinkedList<T>::operator=(const DoublyLinkedList<T> &anList) {
	if (this != &anList) {	// this�� anList�� �ƴ� ���
		MakeEmpty();	// this�� �� list�� ����
	}
	return *this;	//this��ȯ
}


