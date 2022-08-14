#ifndef SORTEDLIST_H_
#define SORTEDLIST_H_

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
	*	copy constructor.
	*/
	SortedList(const SortedList<T>& anSort);

	/**
	*	destructor.
	*/
	~SortedList();


	/**
	*	@brief	anSort list를 deep copy.
	*	@pre	anSort list가 존재해야 함.
	*	@post	anSort list의 모든 정보를 this->Sorteedlist에 deep copy함.
	*	@param	anSort	deep copy하고자 하는 리스트의 주소값.
	*/
	void copySL(const SortedList<T>& anSort);


	/**
	*	@brief	Get a number of records in current list.
	*	@pre	none.
	*	@post	none.
	*	@return	number of records in current list.
	*/
	int GetLength();


	/**
	*	@brief	array의 메모리 재할당
	*	@pre	array의 메모리가 꽉 찬 경우.
	*	@post	array 배열의 메모리를 재할당하여 크기를 10씩 늘려준다.
	*	@return	메모리 재할당 성공시 1을 리턴.
	*/
	int SizeUp();


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
	*	@brief	primary key를 기준으로 정렬이 되도록 알맞은 자리에 항목을 추가한다.
	*	@pre	list should be initialized.
	*	@post	새로운 데이터를 정렬하여 리스트에 추가한다. 이때, 배열이 꽉 찬 경우 메모리를 해제하여 다시 더 크게 동적할당 한 후, 새로운 데이터를 추가한다.
	*	@param	data	추가하고자 하는 데이터.
	*	@return	추가하지 못한 경우 0을 리턴하며, 성공적으로 추가하면 1을, 중복되는 값이 있으면 -1을 리턴.
	*/
	int Add(T data); 


	/**
	*	@brief	사용자가 지정한 data를 배열에서 삭제한다.
	*	@pre	data의 primary key는 채워져있어야 한다.
	*	@post	사용자가 입력한 항목은 삭제되고 length가 1줄어든다. 이때, 정렬되도록 배열을 다시 재조정한다.
	*	@param	data	primary key를 가진 정보.
	*	@return	데이터가 존재하지 않는 경우 0을 리턴하며, 성공적으로 삭제하면 1을 리턴한다.
	*/
	int Delete(T& data); 

	/**
	*	@brief	사용자가 지정한 primary key에 해당하는 배열의 자리에 파라미터의 내용을 복사해 변경.
	*	@pre	data의 모든 변수가 채워져있어야 한다.
	*	@post	사용자가 지정한 항목이 data와 같아진다.
	*	@param	data	변경하고자 하는 data.
	*	@return	성공적으로 수정했으면 1, 아니면 0을 리턴한다.
	*/
	int Replace(T data);


	/**
	*	@brief	인덱스로 데이터를 검색하고 해당 데이터의 포인터를 가져옴.
	*	@pre	none.
	*	@post	리스트에서 해당 인덱스에 일치하는 값을 찾고, 일치하는 값을 가리키는 포인터를 리턴한다.
	*	@param	idx		찾고자 하는 index
	*	@return	찾으면 해당 값의 포인터를, 찾지 못하면 NULL을 리턴한다.
	*/
	T* GetPoint(const int& idx);


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
	*	@param	data	get current iterator's item. it does not need to be initialized.
	*/
	int GetNextItem(T& data);


	/**
	*	@brief	일부만 채워져있는 data에 알맞은 정보를 저장한다. 대상을 찾을때 Binary Search를 이용한다.
	*	@pre	data의 primary key는 채워져있어야 한다.
	*	@post	data 안의 멤버 변수가 모두 채워지며, 해당 data의 index를 반환.
	*	@param	data	primary key를 가진 data.
	*	@return	찾으면 해당 인덱스를 반환하고, 찾지 못하면 -1을 리턴한다.
	*/
	int GetByBinarySearch(T& data); 


	/**
	*	@brief	operator = overloading
	*	@pre	none.
	*	@post	리스트를 anSort의 리스트와 동일하게 정의해준다.
	*	@param	anSort	정보를 가져올 대상
	*	@return anSort의 정보를 정의한 this*를 리턴.
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
	MAXSIZE = 100;
	m_Array = new T[MAXSIZE];
	m_Length = 0;
	ResetList();
}

//copy constructor.
template <typename T>
SortedList<T>::SortedList(const SortedList<T>& anSort) {
	m_Array = anSort.m_Array;

	MAXSIZE = 100;
	m_Array = new T[MAXSIZE];
	copySL(anSort);
	m_Length = anSort.m_Length;
	ResetList();
}

//destructor.
template <typename T>
SortedList<T>::~SortedList() {
	delete[] m_Array;
}

//anSort list를 deep copy.
template <typename T>
void SortedList<T>::copySL(const SortedList<T>& anSort) {
	if (anSort.IsEmpty())
		return;
	else {
		for (int i = 0;i < anSort.m_Length;i++) {
			this->m_Array[i] = anSort[i];
		}
	}
}


// Get a number of records in current list.
template <typename T>
int SortedList<T>::GetLength() { //Get a number of records in current list.
	return m_Length;
}
template<typename T>
int SortedList<T>::SizeUp() {

	T *m_TempArray; //음악정보를 임시로 저장해 둘 Array를 생성한다.
	m_TempArray = new T[MAXSIZE]; //MAXSIZE만큼 메모리를 할당한다.

	for (int i = 0;i < MAXSIZE;i++) { // 원래 리스트에 있던 음악 정보를 임시 Array에 순서대로 저장한다.
		m_TempArray[i] = m_Array[i];
	}

	delete[] m_Array; // 기존의 m_Array의 메모리를 해제한다.

	MAXSIZE += 10; // MAXSIZE의 크기를 10 늘린다.

	m_Array = new T[MAXSIZE]; // 커진 MAXSIZE를 이용해 동적할당 한다.

	for (int i = 0;i < m_Length;i++) { // 임시로 저장해 둔 Array로부터 음악정보를 다시 복사한다.
		m_Array[i] = m_TempArray[i];
	}

	delete[] m_TempArray; // 임시로 생성했던 배열의 메모리를 해제한다.
	return 1;
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


//primary key를 기준으로 정렬이 되도록 알맞은 자리에 항목을 추가
template <typename T>
int SortedList<T>::Add(T data) { 
	if (IsEmpty()) {
		m_Array[m_Length] = data;
		m_Length++;
		return 1;
	}
	else {
		int idx = GetByBinarySearch(data);
		if (idx != -1)
			return -1; //중복되는 값 존재
		else if (IsFull()) {
			SizeUp();
		}
		m_Array[m_Length] = data;
		m_Length++;
		return 1;
	}
	return 0; // 추가 실패하면 0을 반환.

}

//사용자가 지우고자 하는 데이터(primary key값만 존재)를 배열에서 삭제
template <typename T>
int SortedList<T>::Delete(T& data) { 
	int idx = GetByBinarySearch(data);
	if (idx == -1)
		return 0;
	else {
		for (int i = idx;i < m_Length;i++) {
			m_Array[i] = m_Array[i + 1];
		}
		m_Length--;
		return 1;
	}
}

//사용자가 업데이트 하려는 데이터를 배열에서 찾아 내용변경
template <typename T>
int SortedList<T>::Replace(T data) {
	T temp_data = data;
	int idx = GetByBinarySearch(temp_data);
	if (idx == -1) {
		return 0;
	}
	else {
		m_Array[idx] = data;
		return 1;
	}
}

 // Primary key를 기준으로 데이터를 검색하고 해당 데이터의 포인터를 가져옴.
template<typename T>
T* SortedList<T>::GetPoint(const int& idx) {
	if (idx >= m_Length) {
		return NULL;
	}
	else {
		return &m_Array[idx];
	}
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

//Binary Search를 이용해 대상 찾음
template <typename T>
int SortedList<T>::GetByBinarySearch(T& data) { 
	int idx = -1;
	int first = 0;
	int last = m_Length - 1;
	int middle = (first + last) / 2;
	bool found = false;
	while (first <= last && !found) {
		middle = (first + last) / 2;
		if (m_Array[middle] > data) {
			last = middle - 1;
		}
		else if (m_Array[middle] < data) {
			first = middle + 1;
		}
		else {
			data = m_Array[middle];
			idx = middle;
			found = true;
		}
	}
	return idx;
}

// operator= overloading
template <typename T>
const SortedList<T>& SortedList<T>::operator= (const SortedList<T> & anSort) {
	if (this == &anSort)
		return *this;
	else {
		copySL(anSort);
		return *this;
	}
}
