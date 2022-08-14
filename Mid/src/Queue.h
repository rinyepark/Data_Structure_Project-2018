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
	*	@return	m_iFront가 m_iRear보다 1 앞일때는 꽉 찬것이므로 true를 리턴한다. m_iFront가 0일때는 m_iRear가 m_nMaxQueue-1과 같을때 꽉 찬것이다.
	*/
	bool IsFull();

	/**
	*	@brief	Check capacity of list is empty.
	*	@pre	none.
	*	@post	none.
	*	@return	 m_iFront와 m_iRear가 같은 경우는 queue가 비어있는 상태이므로 true를 리턴한다.
	*/
	bool IsEmpty();


	/**
	*	@brief	Queue리스트 리셋.
	*	@pre	none.
	*	@post	m-iFront와 m_iRear를 m_nMaxQueue - 1로 초기화시킨다.
	*/
	void ResetQueue();

	/**
	*	@brief	새로운 데이터를 추가한다.
	*	@pre	list should be initialized.
	*	@post	새로운 데이터를 queue에 추가한다.
	*	@param	item	추가하고자 하는 데이터.
	*/
	void EnQueue(T item);

	/**
	*	@brief	기존의 데이터를 제거한다.
	*	@pre	list should be initialized.
	*	@post	기존의 데이터를 제거한 후, 그 값을 다시 item에 전달한다.
	*	@param	item	제거하고자 하는 데이터.
	*/
	void DeQueue(T &item);


	/**
	*	@brief	Display queue on screen.
	*	@pre	queue list가 존재해야 함.
	*	@post	queue에 있는 정보를 musiclist에서 찾아 자세한 내용 화면에 출력.
	*	@param	musiclist	자세한 정보를 찾고자 하는 리스트의 포인터형식.
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
	m_pItems = new T[maxQueue]; //m_pItems에 크기가 maxQueue인 배열을 만든다.
	m_iFront = maxQueue - 1;
	m_iRear = maxQueue - 1;
	m_nMaxQueue = maxQueue;
	ResetList(); //멤버 변수들을 초기화시켜준다.

}
#endif _QUEUE_H


//Destruct the object. Free the array dynamically allocated.
template <typename T>
Queue<T>::~Queue() {
	delete[] m_pItems; 	//동적할당했던 메모리를 해제해준다.
}

//Determines whether the queue is full.
template <typename T>
bool Queue<T>::IsFull() {
	if (m_iFront - m_iRear == 1 || m_iRear - m_iFront == m_nMaxQueue - 1) {
		return true; //m_iFront가 m_iRear보다 1 앞일때는 꽉 찬것이므로 true를 리턴한다. m_iFront가 0일때는 m_iRear가 m_nMaxQueue-1과 같을때 꽉 찬것이다.
	}
	return false; //꽉 차지 않았으면 false를 리턴한다.
}

//Determines whether the queue is empty.
template <typename T>
bool Queue<T>::IsEmpty() {
	if (m_iRear == m_iFront) {
		return true; //m_iFront와 m_iRear가 같은 경우는 queue가 비어있는 상태이므로 true를 리턴한다.
	}
	return false; 	//비어있지 않으면 false를 리턴한다.
}

//Reset the queue.
template <typename T>
void Queue<T>::ResetQueue() {
	m_iRear = m_nMaxQueue - 1;
	m_iFront = m_nMaxQueue - 1; //생성자와 같은 값으로 m_iFront와 m_iRear를 변경해준다.
}


//Adds newItem to the last of the queue.
template <typename T>
void Queue<T>::EnQueue(T item) {
	if (!IsFull()) {
		m_iRear = (m_iRear + 1) % m_nMaxQueue;
		m_pItems[m_iRear] = item; //m_iRear를 1증가시켜주고 item값을 넣어준다.
	}
}

//Removes first item from the queue.
template <typename T>
void Queue<T>::DeQueue(T &item) {
	if (!IsEmpty()) {
		m_iFront = (m_iFront + 1) % m_nMaxQueue;
		item = m_pItems[m_iFront]; 	//m_iFront를 1 증가시켜주고 삭제될 값을 item에 복사해준다.
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
	m_CurPointer = (m_CurPointer - 1 + m_nMaxQueue) % m_nMaxQueue; // list pointer 감소


	if (m_CurPointer == m_iFront) {// end of list이면 -1을 리턴
		return -1;
	}
	item = m_pItems[m_CurPointer]; // 현재 list pointer의 레코드를 복사

	return m_CurPointer; // 현재 pointer를 리턴
}


// move list iterator to the next item in list and get that item.
template <typename T>
int Queue<T>::GetNextItem(T &item) {
	m_CurPointer = (m_CurPointer + 1) % m_nMaxQueue; // list pointer 증가


	if (m_CurPointer == m_iRear + 1) {// end of list이면 -1을 리턴
		return -1;
	}
	item = m_pItems[m_CurPointer]; // 현재 list pointer의 레코드를 복사

	return m_CurPointer; // 현재 pointer를 리턴
}
