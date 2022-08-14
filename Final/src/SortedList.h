#ifndef SORTEDLIST_H_
#define SORTEDLIST_H_

#include <iostream>
using namespace std;

/**
*	array based sorted list.
*/
template <typename T>
class SortedList {
public:

	/**
	*	default constructor.
	*/
	SortedList();

	/**
	*	default constructor with maxSize.
	*/
	SortedList(int maxSize);

	/**
	*	copy constructor.
	*/
	SortedList(const SortedList<T>& anSort);

	/**
	*	destructor.
	*/
	~SortedList();

	/**
	*	@brief	size값을 이용해, 크기가 size인 배열 동적 할당.
	*	@pre	none.
	*	@post	none.
	*	@param	size	size만큼의 크기로 배열을 동적할당 시켜 생성.
	*/
	void Constructor(int size);

	/**
	*	@brief	Get a number of records in current list.
	*	@pre	none.
	*	@post	none.
	*	@return	number of records in current list.
	*/
	int GetLength();


	/**
	*	@brief	Check capacity of list is full.
	*	@pre	none.
	*	@post	none.
	*	@return	return true if list capacity reached to the upper bound, otherwise return false.
	*/
	bool IsFull();

	/**
	*	@brief	Check capacity of list is empty.
	*	@pre	none.
	*	@post	none.
	*	@return	return true if m_length is 0, otherwise return false.
	*/
	bool IsEmpty();

	/**
	*	@brief	들어오는 순서대로 배열에 저장됨.
	*	@pre	list should be initialized.
	*	@post	새로운 데이터를 리스트에 추가한다.
	*	@param	data	추가하고자 하는 데이터.
	*	@return	성공적으로 추가하면 1을 리턴.
	*/
	int Add(T data);


	/**
	*	@brief	인덱스로 데이터를 검색하고 해당 데이터의 포인터를 가져옴.
	*	@pre	none.
	*	@post	없다.
	*	@param	idx		찾고자 하는 index
	*	@return	찾으면 해당 값의 포인터를, 찾지 못하면 NULL을 리턴한다.
	*/
	T* GetPoint(const int& idx);

	/**
	*	@brief	인덱스로 데이터를 검색하고 해당 데이터의 주소값 반환.
	*	@pre	none.
	*	@post	없다.
	*	@param	idx		찾고자 하는 index
	*	@return	찾으면 해당 값의 참조변수를 리턴.
	*/
	T& GetAddr(const int& idx);

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
	*	@param	data	현재 포인터가 가리키는 값을 전달받음.
	*	@return	배열 끝에 도달하면 -1을, 그렇지 않으면 현재 포인터의 값을 리턴.
	*/
	int GetNextItem(T& data);

	/**
	*	@brief	operator = overloading
	*	@pre	none.
	*	@post	none.
	*	@param	anSort	정보를 가져올 대상
	*	@return this*를 리턴.
	*/
	const SortedList<T>& operator = (const SortedList<T> & anSort);

private:
	T * m_Array;		///< m_Array 포인터
	int MAXSIZE;		///< list size.
	int m_Length;		///< number of elements in list.
	int m_CurPointer;   ///< iterator pointer.
};

#endif // !SORTEDLIST_H_


//default constructor.
template <typename T>
SortedList<T>::SortedList() {
	m_Length = 0;
	ResetList();
}

template <typename T>
void SortedList<T>::Constructor(int size) {
	MAXSIZE = size;
	m_Array = new T[MAXSIZE];
	//ResetList();
}

//default constructor with Maxsize.
template <typename T>
SortedList<T>::SortedList(int maxSize) {
	MAXSIZE = maxSize;
	m_Array = new T[MAXSIZE];
	m_Length = 0;
	ResetList();
}



//copy constructor.
template <typename T>
SortedList<T>::SortedList(const SortedList<T>& anSort) {
	MAXSIZE = anSort.MAXSIZE;
	m_Array = new T[MAXSIZE];
	copySL(anSort);
	m_Length = anSort.m_Length;
}

//destructor.
template <typename T>
SortedList<T>::~SortedList() {
	delete[] m_Array;
}


// Get a number of records in current list.
template <typename T>
int SortedList<T>::GetLength() { //Get a number of records in current list.
	return m_Length;
}


// Check capacity of list is full.
template <typename T>
bool SortedList<T>::IsFull() {
	if (m_Length == MAXSIZE)
		return true;
	else
		return false;
}

//Check capacity of list is empty.
template <typename T>
bool SortedList<T>::IsEmpty() {
	if (m_Length == 0)
		return true;
	else
		return false;
}


//들어오는 순서대로 배열에 저장
template <typename T>
int SortedList<T>::Add(T data) {

	m_Array[m_Length] = data;
	m_Length++;
	return 1;

}

// idx를 기준으로 해당 데이터의 포인터를 가져옴.
template<typename T>
T* SortedList<T>::GetPoint(const int& idx) {
	if (idx >= m_Length) {
		return NULL;
	}
	else {
		return &m_Array[idx];
	}
}

// idx를 기준으로 해당 데이터의 주소값을 가져옴.
template<typename T>
T& SortedList<T>::GetAddr(const int& idx) {
	return m_Array[idx];
}


//Initialize list iterator.
template <typename T>
void SortedList<T>::ResetList() {
	m_CurPointer = -1;
}

//move list iterator to the next item in list and get that item.
template <typename T>
int SortedList<T>::GetNextItem(T& data) {
	m_CurPointer++;
	if (m_CurPointer != MAXSIZE) {
		data = m_Array[m_CurPointer];
		return m_CurPointer;
	}
	else
		return -1;
}

// operator= overloading
template <typename T>
const SortedList<T>& SortedList<T>::operator= (const SortedList<T> & anSort) {
	return *this;
}
