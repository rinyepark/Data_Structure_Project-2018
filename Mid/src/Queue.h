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
	*	@brief	Display queue on screen.
	*	@pre	queue list�� �����ؾ� ��.
	*	@post	queue�� �ִ� ������ musiclist���� ã�� �ڼ��� ���� ȭ�鿡 ���.
	*	@param	musiclist	�ڼ��� ������ ã���� �ϴ� ����Ʈ�� ����������.
	*/
	void DisplayInfNew(SortedList<MusicType> *musiclist);


	/**
	*	@brief	Initialize list iterator.
	*	@pre	list should be initialized.
	*	@post	iterator is reset.
	*/
	void ResetListD();

	/**
	*	@brief	Initialize list iterator.
	*	@pre	list should be initialized.
	*	@post	iterator is reset.
	*/
	void ResetList();

	/**
*	@brief	move list iterator to the next item in list and get that item.
*	@pre	list and list iterator should not be initialized.
*	@post	iterator is moved to next item.
*	@param	item	get current iterator's item. it does not need to be initialized.
*	@return	index of current iterator's item if is not end of list, oterwise return -1.
*/
	int GetNextItemD(T &item);

	/**
	*	@brief	move list iterator to the next item in list and get that item.
	*	@pre	list and list iterator should not be initialized.
	*	@post	iterator is moved to next item.
	*	@param	item	get current iterator's item. it does not need to be initialized.
	*	@return	index of current iterator's item if is not end of list, oterwise return -1.
	*/
	int GetNextItem(T &item);

private:
	int m_iFront;		///<index of one infront of the first element.
	int m_iRear;		///<index of the last element.
	int m_nMaxQueue;	///<max size of the queue.
	T *m_pItems;		///<pointer for dynamic allocation.
	int m_CurPointer;   ///<current pointer
};

//Allocate dynamic array whose size is maxQueue.
template <typename T>
Queue<T>::Queue() {
	m_pItems = new T[maxQueue]; //m_pItems�� ũ�Ⱑ maxQueue�� �迭�� �����.
	m_iFront = maxQueue - 1;
	m_iRear = maxQueue - 1;
	m_nMaxQueue = maxQueue;
	ResetList(); //��� �������� �ʱ�ȭ�����ش�.

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

//Display detail information in queue by searching musiclist.
template<typename T>
void Queue<T>::DisplayInfNew(SortedList<MusicType> *musiclist) {
	ResetListD();
	SimpleMusicType temp;
	MusicType m_temp;

	while (m_CurPointer != (m_iFront+1)%m_nMaxQueue) {
		GetNextItemD(temp);
		m_temp.SetId(temp.GetId());
		int n;
		n = musiclist->GetByBinarySearch(m_temp);
		if (n != -1) {
			m_temp.DisplayRecordOnScreen();
		}
	}
}


// Initialize list iterator.
template <typename T>
void Queue<T>::ResetListD() {
	m_CurPointer = (m_iRear + 1) % m_nMaxQueue;
}

// Initialize list iterator.
template <typename T>
void Queue<T>::ResetList() {
	m_CurPointer = m_iFront;
}
// move list iterator to the next item in list and get that item.
template <typename T>
int Queue<T>::GetNextItemD(T &item) {
	m_CurPointer = (m_CurPointer - 1 + m_nMaxQueue) % m_nMaxQueue; // list pointer ����


	if (m_CurPointer == m_iFront) {// end of list�̸� -1�� ����
		return -1;
	}
	item = m_pItems[m_CurPointer]; // ���� list pointer�� ���ڵ带 ����

	return m_CurPointer; // ���� pointer�� ����
}


// move list iterator to the next item in list and get that item.
template <typename T>
int Queue<T>::GetNextItem(T &item) {
	m_CurPointer = (m_CurPointer + 1) % m_nMaxQueue; // list pointer ����


	if (m_CurPointer == m_iRear + 1) {// end of list�̸� -1�� ����
		return -1;
	}
	item = m_pItems[m_CurPointer]; // ���� list pointer�� ���ڵ带 ����

	return m_CurPointer; // ���� pointer�� ����
}
