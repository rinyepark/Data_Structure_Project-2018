#ifndef LINKEDLIST_H_
#define LINKEDLIST_H_

/**
*	Unsorted linked list.
*/
template<typename T>
class LinkedList {
public:

	/**
	*	default constructor.
	*/
	LinkedList();

	/**
	*	copy constructor.
	*/
	LinkedList(const LinkedList<T>& anList);

	/**
	*	destructor.
	*/
	~LinkedList();


	/**
	*	@brief	anList를 deep copy.
	*	@pre	anList가 존재해야 함.
	*	@post	anList의 모든 정보를 this->LinedList에 deep copy함.
	*	@param	anList	deep copy하고자 하는 리스트의 주소값.
	*/
	void copyLL(const LinkedList<T>& anList);


	/**
	*	@brief	Get a number of records in current list.
	*	@pre	none.
	*	@post	none.
	*	@return	number of records in current list.
	*/
	int GetLength();


	/**
	*	@brief	linked list의 연결된 레코드 모두 삭제.
	*	@pre	none.
	*	@post	linked list에 연결되어 있는 node를 모두 삭제하여 빈 list를 만든다.
	*/
	void MakeEmpty();


	/**
	*	@brief	새로운 레코드를 리스트에 삽입함.
	*	@pre	list should be initialized.
	*	@post	새로운 데이터를 리스트에 추가한다.
	*	@param	item	추가하고자 하는 데이터.
	*/
	int Add(T item);

	/**
	*	@brief	특정 데이터를 리스트에서 제거.
	*	@pre	list should be initialized.
	*	@post	특정 데이터를 리스트에서 제거한다.
	*	@param	item	제거하고자 하는 데이터.
	*/
	int Delete(T item);

	/**
	*	@brief	Primary key를 기준으로 데이터를 검색하고 해당 데이터의 포인터를 가져옴.
	*	@pre	item이 찾고자하는 num값을 가지고 있어야 함.
	*	@post	리스트에서 item의 num값과 일치하는 값을 찾고, 일치하는 node 값을 가리키는 포인터를 리턴한다.
	*	@param	item	num값만 채워져 있는 데이터
	*	@return	찾으면 해당 node의 포인터를, 찾지 못하면 NULL을 리턴한다.
	*/
	T* GetPoint(T item);


	/**
	*	@brief	Primary key를 기준으로 데이터를 검색하고 해당 데이터를 가져옴
	*	@pre	item이 찾고자하는 id값을 가지고 있어야 함.
	*	@post	리스트에서 item의 id값과 일치하는 값을 찾고, 해당 정보를 item에 전달한다.
	*	@param	item	id값만 채워져 있는 데이터
	*	@return	찾으면 1, 찾지 못하면 0을 리턴한다.
	*/
	int Get(T &item);

	/**
	*	@brief	Initialize list iterator.
	*	@pre	list should be initialized.
	*	@post	iterator is reset.
	*/
	void ResetList();


	/**
	*	@brief	Current Pointer가 다음 node를 가리키도록 이동 후 해당 레코드를 가져옴
	*	@pre	list and list iterator should not be initialized.
	*	@post	iterator is moved to next item.
	*	@param	item	get current iterator's item. it does not need to be initialized.
	*/
	void GetNextItem(T &item);


	/**
	*	@brief	operator = overloading
	*	@pre	none.
	*	@post	리스트를 anLinked의 리스트와 동일하게 정의해준다.
	*	@param	anLinked	정보를 가져올 대상
	*	@return anLinked의 정보를 정의한 this*를 리턴.
	*/
	const LinkedList<T>& operator =(const LinkedList<T> & anLinked);

private:
	NodeType<T> *m_pList;		///< NodeType의 m_pList 포인터
	NodeType<T> *m_pCurPoint;   ///< current pointer
	int m_nLength;				///<리스트에 저장된 레코드 수
};
#endif // !LINKEDLIST_H_

// default constructor.
template<typename T>
LinkedList<T>::LinkedList() {
	m_pList = NULL;
	m_pCurPoint = NULL;
	m_nLength = 0;
}

// copy constructor.
template <typename T>
LinkedList<T>::LinkedList(const LinkedList<T> &anList) {
	this->m_Length = anList.GetLength();
	this->ResetList();
	copySLL(anList);
}

// destructor
template<typename T>
LinkedList<T>::~LinkedList() {
	MakeEmpty();
}

// deep copy.
template<typename T>
void LinkedList<T>::copyLL(const LinkedList<T>& anList) {

	if (anList.m_pList == NULL)
		this->m_pList = NULL;
	else {
		NodeType<T> *temp;
		temp = anList.m_pList;
		T item = temp->info;

		NodeType<T> *pre;
		pre = new NodeType<T>;
		pre->info = item;
		pre->next = NULL;
		m_pList = pre;

		m_pCurPoint = m_pList;
		this->m_nLength++;

		for (int i = 1;i < anList.m_nLength;i++) {
			temp = temp->next;
			item = temp->info;

			NodeType<T> *con;
			con = new NodeType<T>;
			con->info = item;
			con->next = NULL;
			this->m_pCurPoint->next = con;
			this->m_pCurPoint = con;
			this->m_nLength++;


		}
	}
}

// Get a number of records in current list.
template<typename T>
int LinkedList<T>::GetLength() {
	return m_nLength;
}

// linked list의 연결된 레코드 모두 삭제.
template<typename T>
void LinkedList<T>::MakeEmpty() {
	NodeType<T> *temp;
	while (m_pList != NULL) {
		temp = m_pList;
		m_pList = m_pList->next;
		delete temp;
	}

	m_nLength = 0;
}

//새로운 레코드를 리스트에 삽입
template<typename T>
int LinkedList<T>::Add(T item) {
	NodeType<T> *Next_item;
	Next_item = new NodeType<T>;

	Next_item->info = item;
	Next_item->next = NULL;

	if (!m_nLength) { //빈 리스트이면 바로 추가한다.
		m_pList = Next_item;
	}
	else {
		Next_item->next = m_pList;
		m_pList = Next_item;
	}

	m_nLength++; //길이 증가
	return 1;	//add를 성공하였음으로 1을 리턴.
}

//새로운 레코드를 리스트에서 제거
template<typename T>
int LinkedList<T>::Delete(T item) {
	int found = 0;
	ResetList();
	T data;
	NodeType<T> *pre;
	NodeType<T> *temp;

	while (1) {
		pre = m_pCurPoint;
		GetNextItem(data);

		if (data == item) { //일치하는 item을 찾았을 때
			if (pre == NULL) {	// 제거대상이 첫번째 위치하는 경우.
				temp = m_pCurPoint;
				m_pList = m_pList->next;
				found = 1;
				delete temp;
				break;
			}
			else {	// 제거대상이 첫번째가 아닌 곳에 위치하는 경우.
				temp = m_pCurPoint;
				pre->next = m_pCurPoint->next;
				found = 1;
				delete temp;
				break;
			}
		}
		if (m_pCurPoint->next == NULL) { // 더 이상 찾을 수 있는 node가 없으므로 반복문 종료.
			break;
		}
	}
	m_nLength--;
	return found;
}


 // Primary key를 기준으로 데이터를 검색하고 해당 데이터의 포인터를 리턴.
template<typename T>
T* LinkedList<T>::GetPoint(T item) {
	ResetList();
	T temp;
	GetNextItem(temp);
	if (m_pCurPoint != NULL) {
		while (1) {
			if (temp == item) {
				return &(m_pCurPoint->info);
			}
			else if (m_pCurPoint->next == NULL) {
				break;
			}
			GetNextItem(temp);
		}
	}
	return NULL;
}


// Primary key를 기준으로 데이터를 검색하고 해당 데이터를 가져옴
template<typename T>
int LinkedList<T>::Get(T &item) {
	if (m_nLength == 0) {
		return 0;
	}
	else {
		bool found = 0;
		ResetList();
		T temp;

		while (1) {
			GetNextItem(temp);
			if (temp == item) {
				found = 1;
				item = temp;
				break;
			}
			else if (m_pCurPoint->next == NULL) {
				break;
			}
		}
		return found;
	}
}


// 레코드 포인터 초기화
template<typename T>
void LinkedList<T>::ResetList() {
	m_pCurPoint = NULL;
}

// Current Pointer가 다음 node를 가리키도록 이동 후 해당 레코드를 가져옴
template<typename T>
void LinkedList<T>::GetNextItem(T &item) {
	if (m_pCurPoint == NULL) {
		m_pCurPoint = m_pList;
	}
	else {
		m_pCurPoint = m_pCurPoint->next;
	}
	item = m_pCurPoint->info;
}


// operator= overloading
template <typename T>
const LinkedList<T>& LinkedList<T>::operator =(const LinkedList<T> & anLinked) {
	if (this == &anLinked)
		return *this;
	else {
		MakeEmpty();
		copyLL(anLinked);
		return *this;
	}
}