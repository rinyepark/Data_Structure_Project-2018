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
	*	@brief	size���� �̿���, ũ�Ⱑ size�� �迭 ���� �Ҵ�.
	*	@pre	none.
	*	@post	none.
	*	@param	size	size��ŭ�� ũ��� �迭�� �����Ҵ� ���� ����.
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
	*	@brief	������ ������� �迭�� �����.
	*	@pre	list should be initialized.
	*	@post	���ο� �����͸� ����Ʈ�� �߰��Ѵ�.
	*	@param	data	�߰��ϰ��� �ϴ� ������.
	*	@return	���������� �߰��ϸ� 1�� ����.
	*/
	int Add(T data);


	/**
	*	@brief	�ε����� �����͸� �˻��ϰ� �ش� �������� �����͸� ������.
	*	@pre	none.
	*	@post	����.
	*	@param	idx		ã���� �ϴ� index
	*	@return	ã���� �ش� ���� �����͸�, ã�� ���ϸ� NULL�� �����Ѵ�.
	*/
	T* GetPoint(const int& idx);

	/**
	*	@brief	�ε����� �����͸� �˻��ϰ� �ش� �������� �ּҰ� ��ȯ.
	*	@pre	none.
	*	@post	����.
	*	@param	idx		ã���� �ϴ� index
	*	@return	ã���� �ش� ���� ���������� ����.
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
	*	@param	data	���� �����Ͱ� ����Ű�� ���� ���޹���.
	*	@return	�迭 ���� �����ϸ� -1��, �׷��� ������ ���� �������� ���� ����.
	*/
	int GetNextItem(T& data);

	/**
	*	@brief	operator = overloading
	*	@pre	none.
	*	@post	none.
	*	@param	anSort	������ ������ ���
	*	@return this*�� ����.
	*/
	const SortedList<T>& operator = (const SortedList<T> & anSort);

private:
	T * m_Array;		///< m_Array ������
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


//������ ������� �迭�� ����
template <typename T>
int SortedList<T>::Add(T data) {

	m_Array[m_Length] = data;
	m_Length++;
	return 1;

}

// idx�� �������� �ش� �������� �����͸� ������.
template<typename T>
T* SortedList<T>::GetPoint(const int& idx) {
	if (idx >= m_Length) {
		return NULL;
	}
	else {
		return &m_Array[idx];
	}
}

// idx�� �������� �ش� �������� �ּҰ��� ������.
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
