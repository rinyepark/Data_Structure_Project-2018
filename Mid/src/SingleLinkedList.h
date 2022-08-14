#ifndef _SINGLELINKEDLIST_H
#define _SINGLELINKEDLIST_H

#include <iostream>
#include <string>
using namespace std;


/**
*	node type struct.
*/
template<typename T>
struct NodeType {
	T info;				///< NodeType의 정보
	NodeType *next;		///< 다음 노드를 가리킬 포인터
};

/**
*	single linked list.
*/
template<typename T>
class SingleLinkedList {
public:
	/**
	*	default constructor.
	*/
	SingleLinkedList();

	/**
	*	copy constructor.
	*/
	SingleLinkedList(const SingleLinkedList<T> &anList);

	/**
	*	destructor.
	*/
	~SingleLinkedList();


	/**
	*	@brief	Check capacity of list is empty.
	*	@pre	none.
	*	@post	none.
	*	@return	return true if m_length is 0, otherwise return false.
	*/
	bool IsEmpty();

	/**
	*	@brief	linked list의 연결된 레코드 모두 삭제.
	*	@pre	none.
	*	@post	linked list에 연결되어 있는 node를 모두 삭제하여 빈 list를 만든다.
	*/
	void MakeEmpty();

	/**
	*	@brief	Get a number of records in current list.
	*	@pre	none.
	*	@post	none.
	*	@return	number of records in current list.
	*/
	int GetLength();


	/**
	*	@brief	list를 deep copy.
	*	@pre	list가 존재해야 함.
	*	@post	list의 모든 정보를 this->singlelinkedlist에 deep copy함.
	*	@param	list	deep copy하고자 하는 리스트의 주소값.
	*/
	void copySLL(const SingleLinkedList<T>& list);


	/**
	*	@brief	primary key를 기준으로 정렬이 되도록 새로운 레코드를 리스트에 삽입함.
	*	@pre	list should be initialized.
	*	@post	새로운 데이터를 정렬하여 리스트에 추가한다.
	*	@param	item	추가하고자 하는 데이터.
	*/
	int Add(T item);


	/**
	*	@brief	primary key를 기준으로 레코드를 리스트에서 제거한다.
	*	@pre	list should be initialized.
	*	@post	id의 정보만 가진 item을 이용해 리스트에서 정렬을 유지하며 제거한 후, 해당 데이터를 item에 전달한다.
	*	@param	item	제거하고자 하는 id값만 가진 데이터이며, 이후 제거된 데이터의 정보를 받는다.
	*/
	int Delete(T &item);

	/**
	*	@brief	primary key를 기준으로 항목을 변경한다.
	*	@pre	list should be initialized.
	*	@post	id의 정보만 가진 item을 이용해 리스트에서 해당 항목의 정보를 변경한다.
	*	@param	item	변경하고자 하는 데이터.
	*/
	int Replace(T item);


	/**
	*	@brief	Primary key를 기준으로 데이터를 검색하고 해당 데이터를 가져옴
	*	@pre	item이 찾고자하는 id값을 가지고 있어야 함.
	*	@post	리스트에서 item의 num값과 일치하는 값을 찾고, 해당 정보를 item에 전달한다.
	*	@param	item	id만 채워져 있는 데이터
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
	*	@brief	Primary key를 기준으로 데이터를 검색하고 해당 데이터의 포인터를 가져옴.
	*	@pre	item이 id값을 가지고 있어야 함.
	*	@post	리스트에서 item의 id값과 일치하는 값을 찾고, 일치하는 node 값을 가리키는 포인터를 리턴한다.
	*	@param	item	id값만 채워져 있는 데이터
	*	@return	찾으면 해당 node의 포인터를, 찾지 못하면 NULL을 리턴한다.
	*/
	T* GetPoint(T item);

	/**
	*	@brief	operator = overloading
	*	@pre	none.
	*	@post	리스트를 anLinked의 리스트와 동일하게 정의해준다.
	*	@param	anLinked	정보를 가져올 대상
	*	@return anLinked의 정보를 정의한 this*를 리턴.
	*/
	const SingleLinkedList<T>& operator =(const SingleLinkedList<T> & anLinked);

private:
	NodeType<T> *m_pList;		///< NodeType의 m_pList 포인터
	NodeType<T> *m_pCurPoint;   ///< current pointer
	int m_nLength;				///<리스트에 저장된 레코드 수
};
#endif // !_SINGLELINKEDLIST_H

// default constructor.
template<typename T>
SingleLinkedList<T>::SingleLinkedList() {
	m_pList = NULL;
	m_pCurPoint = NULL;
	m_nLength = 0;
}

// copy constructor.
template <typename T>
SingleLinkedList<T>::SingleLinkedList(const SingleLinkedList<T> &anList) {
	this->m_Length = anList.GetLength();
	this->ResetList();
	copySLL(anList);
}

// deep copy.
template<typename T>
void SingleLinkedList<T>::copySLL(const SingleLinkedList<T>& anList) {

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

// destructor
template<typename T>
SingleLinkedList<T>::~SingleLinkedList() {
	MakeEmpty();
}

// 리스트가 비어있는지 확인.
template<typename T>
bool SingleLinkedList<T>::IsEmpty() {
	if (m_nLength == 0) {
		return true;
	}
	else
		return false;
}

// linked list의 연결된 레코드 모두 삭제.
template<typename T>
void SingleLinkedList<T>::MakeEmpty() {
	NodeType<T> *temp;
	while (m_pList != NULL) {
		temp = m_pList;
		m_pList = m_pList->next;
		delete temp;
	}

	m_nLength = 0;
}

// Get a number of records in current list.
template<typename T>
int SingleLinkedList<T>::GetLength() {
	return m_nLength;
}

//새로운 레코드를 리스트에 삽입
template<typename T>
int SingleLinkedList<T>::Add(T item) {
	NodeType<T> *Next_item;
	Next_item = new NodeType<T>;

	Next_item->info = item;
	Next_item->next = NULL;

	if (!m_nLength) { //빈 리스트이면 바로 추가한다.
		m_pList = Next_item;
	}
	else {
		ResetList();
		NodeType<T> *pre_temp;
		T temp;
		while (true) {
			pre_temp = m_pCurPoint;
			GetNextItem(temp);

			if (Next_item->info < temp) { //연결되어야 하는 자리를 찾는 경우

				//pre_temp가 NULL이면 첫번째 자리에 연결하는 경우
				if (pre_temp == NULL) {
					Next_item->next = m_pCurPoint;
					m_pList = Next_item;
					break;
				}

				//중간에 연결하는 경우
				else {
					Next_item->next = m_pCurPoint;
					pre_temp->next = Next_item;
					break;
				}
			}

			//current pointer의 next가 NULL이 되면 마지막 노드에 도달하였음으로, 마지막에 연결하는 경우.
			if (m_pCurPoint->next == NULL) {
				m_pCurPoint->next = Next_item;
				break;
			}
		}
	}
	m_nLength++; //길이 증가
	return 1;	//add를 성공하였음으로 1을 리턴.
}

//새로운 레코드를 리스트에서 제거
template<typename T>
int SingleLinkedList<T>::Delete(T& item) {
	bool found = false;

	if (Get(item)) { //리스트에서 일치하는 item을 존재하는 경우.
		ResetList();
		T data;
		NodeType<T> *pre;
		NodeType<T> *temp;

		while (1) {
			pre = m_pCurPoint;
			GetNextItem(data);

			if (data == item) { //일치하는 item을 찾았을 때
				item = data;   //해당 data의 정보를 item에 전달.
				if (pre == NULL) {	// 제거대상이 첫번째 위치하는 경우.
					temp = m_pCurPoint;
					m_pList = m_pList->next;
					found = true;
					delete temp;
					break;
				}
				else {	// 제거대상이 첫번째가 아닌 곳에 위치하는 경우.
					temp = m_pCurPoint;
					pre->next = m_pCurPoint->next;
					found = true;
					delete temp;
					break;
				}
			}
			if (m_pCurPoint->next == NULL) { // 더 이상 찾을 수 있는 node가 없으므로 반복문 종료.
				break;
			}
		}
	}

	//성공적으로 삭제하면 길이를 하나 줄이고 1을 리턴.
	if (found) {
		m_nLength--;
		return 1;
	}
	//삭제하지 못했을 때 -1을 리턴.
	else {
		return -1;
	}
}

// 해당 레코드를 리스트에서 내용 변경
template<typename T>
int SingleLinkedList<T>::Replace(T item) {
	T iTemp = item;
	bool found = 0;
	if (!Get(iTemp)) { //해당 데이터를 찾지 못하면 종료.
		return 0;
	}
	else {	//데이터를 찾으면 정보 변경
		ResetList();
		T tmp;
		while (1) {
			GetNextItem(tmp);
			if (tmp == item) {
				m_pCurPoint->info = item;
				found = 1;
				break;
			}
			if (m_pCurPoint->next == NULL) {
				break;
			}
		}
	}

	if (found) {	//변경에 성공하면 1을, 실패하면 0을 리턴.
		return 1;
	}
	else
		return 0;
}

// Primary key를 기준으로 데이터를 검색하고 해당 데이터를 가져옴
template<typename T>
int SingleLinkedList<T>::Get(T &item) {
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
void SingleLinkedList<T>::ResetList() {
	m_pCurPoint = NULL;
}

// Current Pointer가 다음 node를 가리키도록 이동 후 해당 레코드를 가져옴
template<typename T>
void SingleLinkedList<T>::GetNextItem(T &item) {
	if (m_pCurPoint == NULL) {
		m_pCurPoint = m_pList;
	}
	else {
		m_pCurPoint = m_pCurPoint->next;
	}
	item = m_pCurPoint->info;
}

// Primary key를 기준으로 데이터를 검색하고 해당 데이터의 포인터를 리턴.
template<typename T>
T* SingleLinkedList<T>::GetPoint(T item) {
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

// operator= overloading
template <typename T>
const SingleLinkedList<T>& SingleLinkedList<T>::operator = (const SingleLinkedList<T> & anLinked) {
	if (this == &anLinked)
		return *this;
	else {
		MakeEmpty();
		copySLL(anLinked);
		return *this;
	}
}
