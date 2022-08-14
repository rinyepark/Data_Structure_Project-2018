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
	*	@brief	anSort list�� deep copy.
	*	@pre	anSort list�� �����ؾ� ��.
	*	@post	anSort list�� ��� ������ this->Sorteedlist�� deep copy��.
	*	@param	anSort	deep copy�ϰ��� �ϴ� ����Ʈ�� �ּҰ�.
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
	*	@brief	array�� �޸� ���Ҵ�
	*	@pre	array�� �޸𸮰� �� �� ���.
	*	@post	array �迭�� �޸𸮸� ���Ҵ��Ͽ� ũ�⸦ 10�� �÷��ش�.
	*	@return	�޸� ���Ҵ� ������ 1�� ����.
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
	*	@brief	primary key�� �������� ������ �ǵ��� �˸��� �ڸ��� �׸��� �߰��Ѵ�.
	*	@pre	list should be initialized.
	*	@post	���ο� �����͸� �����Ͽ� ����Ʈ�� �߰��Ѵ�. �̶�, �迭�� �� �� ��� �޸𸮸� �����Ͽ� �ٽ� �� ũ�� �����Ҵ� �� ��, ���ο� �����͸� �߰��Ѵ�.
	*	@param	data	�߰��ϰ��� �ϴ� ������.
	*	@return	�߰����� ���� ��� 0�� �����ϸ�, ���������� �߰��ϸ� 1��, �ߺ��Ǵ� ���� ������ -1�� ����.
	*/
	int Add(T data); 


	/**
	*	@brief	����ڰ� ������ data�� �迭���� �����Ѵ�.
	*	@pre	data�� primary key�� ä�����־�� �Ѵ�.
	*	@post	����ڰ� �Է��� �׸��� �����ǰ� length�� 1�پ���. �̶�, ���ĵǵ��� �迭�� �ٽ� �������Ѵ�.
	*	@param	data	primary key�� ���� ����.
	*	@return	�����Ͱ� �������� �ʴ� ��� 0�� �����ϸ�, ���������� �����ϸ� 1�� �����Ѵ�.
	*/
	int Delete(T& data); 

	/**
	*	@brief	����ڰ� ������ primary key�� �ش��ϴ� �迭�� �ڸ��� �Ķ������ ������ ������ ����.
	*	@pre	data�� ��� ������ ä�����־�� �Ѵ�.
	*	@post	����ڰ� ������ �׸��� data�� ��������.
	*	@param	data	�����ϰ��� �ϴ� data.
	*	@return	���������� ���������� 1, �ƴϸ� 0�� �����Ѵ�.
	*/
	int Replace(T data);


	/**
	*	@brief	�ε����� �����͸� �˻��ϰ� �ش� �������� �����͸� ������.
	*	@pre	none.
	*	@post	����Ʈ���� �ش� �ε����� ��ġ�ϴ� ���� ã��, ��ġ�ϴ� ���� ����Ű�� �����͸� �����Ѵ�.
	*	@param	idx		ã���� �ϴ� index
	*	@return	ã���� �ش� ���� �����͸�, ã�� ���ϸ� NULL�� �����Ѵ�.
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
	*	@brief	�Ϻθ� ä�����ִ� data�� �˸��� ������ �����Ѵ�. ����� ã���� Binary Search�� �̿��Ѵ�.
	*	@pre	data�� primary key�� ä�����־�� �Ѵ�.
	*	@post	data ���� ��� ������ ��� ä������, �ش� data�� index�� ��ȯ.
	*	@param	data	primary key�� ���� data.
	*	@return	ã���� �ش� �ε����� ��ȯ�ϰ�, ã�� ���ϸ� -1�� �����Ѵ�.
	*/
	int GetByBinarySearch(T& data); 


	/**
	*	@brief	operator = overloading
	*	@pre	none.
	*	@post	����Ʈ�� anSort�� ����Ʈ�� �����ϰ� �������ش�.
	*	@param	anSort	������ ������ ���
	*	@return anSort�� ������ ������ this*�� ����.
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

//anSort list�� deep copy.
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

	T *m_TempArray; //���������� �ӽ÷� ������ �� Array�� �����Ѵ�.
	m_TempArray = new T[MAXSIZE]; //MAXSIZE��ŭ �޸𸮸� �Ҵ��Ѵ�.

	for (int i = 0;i < MAXSIZE;i++) { // ���� ����Ʈ�� �ִ� ���� ������ �ӽ� Array�� ������� �����Ѵ�.
		m_TempArray[i] = m_Array[i];
	}

	delete[] m_Array; // ������ m_Array�� �޸𸮸� �����Ѵ�.

	MAXSIZE += 10; // MAXSIZE�� ũ�⸦ 10 �ø���.

	m_Array = new T[MAXSIZE]; // Ŀ�� MAXSIZE�� �̿��� �����Ҵ� �Ѵ�.

	for (int i = 0;i < m_Length;i++) { // �ӽ÷� ������ �� Array�κ��� ���������� �ٽ� �����Ѵ�.
		m_Array[i] = m_TempArray[i];
	}

	delete[] m_TempArray; // �ӽ÷� �����ߴ� �迭�� �޸𸮸� �����Ѵ�.
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


//primary key�� �������� ������ �ǵ��� �˸��� �ڸ��� �׸��� �߰�
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
			return -1; //�ߺ��Ǵ� �� ����
		else if (IsFull()) {
			SizeUp();
		}
		m_Array[m_Length] = data;
		m_Length++;
		return 1;
	}
	return 0; // �߰� �����ϸ� 0�� ��ȯ.

}

//����ڰ� ������� �ϴ� ������(primary key���� ����)�� �迭���� ����
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

//����ڰ� ������Ʈ �Ϸ��� �����͸� �迭���� ã�� ���뺯��
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

 // Primary key�� �������� �����͸� �˻��ϰ� �ش� �������� �����͸� ������.
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

//Binary Search�� �̿��� ��� ã��
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
