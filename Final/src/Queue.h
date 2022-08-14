#ifndef _QUEUE_H
#define _QUEUE_H
#include <iostream>
using namespace std;

#define maxQueue 31

/**
*	Circular queue list.
*/
template <typename T>
class Queue {
public:
	/**
	*	default constructor.
	*/
	Queue();

	/**
	*	destructor.
	*/
	~Queue();

	/**
	*	@brief	Check capacity of list is full.
	*	@pre	none.
	*	@post	none.
	*	@return	m_iFront�� m_iRear���� 1 ���϶��� �� �����̹Ƿ� true�� �����Ѵ�. m_iFront�� 0�϶��� m_iRear�� m_nMaxQueue-1�� ������ �� �����̴�.
	*/
	bool IsFull();

	/**
	*	@brief	Check capacity of list is empty.
	*	@pre	none.
	*	@post	none.
	*	@return	 m_iFront�� m_iRear�� ���� ���� queue�� ����ִ� �����̹Ƿ� true�� �����Ѵ�.
	*/
	bool IsEmpty();


	/**
	*	@brief	Queue����Ʈ ����.
	*	@pre	none.
	*	@post	m-iFront�� m_iRear�� m_nMaxQueue - 1�� �ʱ�ȭ��Ų��.
	*/
	void ResetQueue();

	/**
	*	@brief	���ο� �����͸� �߰��Ѵ�.
	*	@pre	list should be initialized.
	*	@post	���ο� �����͸� queue�� �߰��Ѵ�.
	*	@param	item	�߰��ϰ��� �ϴ� ������.
	*/
	void EnQueue(T item);

	/**
	*	@brief	������ �����͸� �����Ѵ�.
	*	@pre	list should be initialized.
	*	@post	������ �����͸� ������ ��, �� ���� �ٽ� item�� �����Ѵ�.
	*	@param	item	�����ϰ��� �ϴ� ������.
	*/
	void DeQueue(T &item);

	/**
	*	@brief	Initialize list iterator.
	*	@pre	list should be initialized.
	*	@post	iterator is reset.
	*/
	void ResetList();

	/**
	*	@brief	�����͸� ���ҽ�Ű��, ���� �����ϸ� -1�� �����ϰ�, �ƴϸ� ���� �����͸� �����ϸ�, �����Ͱ� ����Ű�� ���� data�� ���� ����
	*	@pre	list and list iterator should not be initialized.
	*	@post	iterator is moved to next item.
	*	@param	data	�����Ͱ� ����Ű�� ���� �����ϴ� ����.
	*/
	int GetNextItem(T& data);

private:
	int m_iFront;		///<index of one infront of the first element.
	int m_iRear;		///<index of the last element.
	int m_nMaxQueue;	///<max size of the queue.
	int m_pCurPointer;	///<Queue�� ��Ҹ� ����ų ������.
	T *m_pItems;		///<pointer for dynamic allocation.
};

//Allocate dynamic array whose size is maxQueue.
template <typename T>
Queue<T>::Queue() {
	m_pItems = new T[maxQueue]; //m_pItems�� ũ�Ⱑ maxQueue�� �迭�� �����.
	m_iFront = maxQueue - 1;
	m_iRear = maxQueue - 1;
	m_nMaxQueue = maxQueue;
	ResetList();
}
#endif _QUEUE_H


//Destruct the object. Free the array dynamically allocated.
template <typename T>
Queue<T>::~Queue() {
	delete[] m_pItems; 	//�����Ҵ��ߴ� �޸𸮸� �������ش�.
}

//Determines whether the queue is full.
template <typename T>
bool Queue<T>::IsFull() {
	if (m_iFront - m_iRear == 1 || m_iRear - m_iFront == m_nMaxQueue - 1) {
		return true; //m_iFront�� m_iRear���� 1 ���϶��� �� �����̹Ƿ� true�� �����Ѵ�. m_iFront�� 0�϶��� m_iRear�� m_nMaxQueue-1�� ������ �� �����̴�.
	}
	return false; //�� ���� �ʾ����� false�� �����Ѵ�.
}

//Determines whether the queue is empty.
template <typename T>
bool Queue<T>::IsEmpty() {
	if (m_iRear == m_iFront) {
		return true; //m_iFront�� m_iRear�� ���� ���� queue�� ����ִ� �����̹Ƿ� true�� �����Ѵ�.
	}
	return false; 	//������� ������ false�� �����Ѵ�.
}

//Reset the queue.
template <typename T>
void Queue<T>::ResetQueue() {
	m_iRear = m_nMaxQueue - 1;
	m_iFront = m_nMaxQueue - 1; //�����ڿ� ���� ������ m_iFront�� m_iRear�� �������ش�.
}


//Adds newItem to the last of the queue.
template <typename T>
void Queue<T>::EnQueue(T item) {
	if (!IsFull()) {
		m_iRear = (m_iRear + 1) % m_nMaxQueue;
		m_pItems[m_iRear] = item; //m_iRear�� 1���������ְ� item���� �־��ش�.
	}
}

//Removes first item from the queue.
template <typename T>
void Queue<T>::DeQueue(T &item) {
	if (!IsEmpty()) {
		m_iFront = (m_iFront + 1) % m_nMaxQueue;
		item = m_pItems[m_iFront]; 	//m_iFront�� 1 ���������ְ� ������ ���� item�� �������ش�.
	}
}

//�����͸� ���½�Ŵ.
template<typename T>
void Queue<T>::ResetList() {
	m_pCurPointer = (m_iRear + 1) % m_nMaxQueue;
}

//�����͸� ���ҽ�Ű��, ���� �����ϸ� -1�� �����ϰ�, �ƴϸ� ���� �����͸� �����ϸ�, �����Ͱ� ����Ű�� ���� data�� ���� ����
template<typename T>
int Queue<T>::GetNextItem(T& data) {
	m_pCurPointer = (m_pCurPointer - 1 + m_nMaxQueue) % m_nMaxQueue; // list pointer ����


	if (m_pCurPointer == m_iFront) {// end of list�̸� -1�� ����
		return -1;
	}
	data = m_pItems[m_pCurPointer]; // ���� list pointer�� ���ڵ带 ����

	return m_pCurPointer; // ���� pointer�� ����
}
