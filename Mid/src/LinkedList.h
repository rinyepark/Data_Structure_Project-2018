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
	*	@brief	anList�� deep copy.
	*	@pre	anList�� �����ؾ� ��.
	*	@post	anList�� ��� ������ this->LinedList�� deep copy��.
	*	@param	anList	deep copy�ϰ��� �ϴ� ����Ʈ�� �ּҰ�.
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
	*	@brief	linked list�� ����� ���ڵ� ��� ����.
	*	@pre	none.
	*	@post	linked list�� ����Ǿ� �ִ� node�� ��� �����Ͽ� �� list�� �����.
	*/
	void MakeEmpty();


	/**
	*	@brief	���ο� ���ڵ带 ����Ʈ�� ������.
	*	@pre	list should be initialized.
	*	@post	���ο� �����͸� ����Ʈ�� �߰��Ѵ�.
	*	@param	item	�߰��ϰ��� �ϴ� ������.
	*/
	int Add(T item);

	/**
	*	@brief	Ư�� �����͸� ����Ʈ���� ����.
	*	@pre	list should be initialized.
	*	@post	Ư�� �����͸� ����Ʈ���� �����Ѵ�.
	*	@param	item	�����ϰ��� �ϴ� ������.
	*/
	int Delete(T item);

	/**
	*	@brief	Primary key�� �������� �����͸� �˻��ϰ� �ش� �������� �����͸� ������.
	*	@pre	item�� ã�����ϴ� num���� ������ �־�� ��.
	*	@post	����Ʈ���� item�� num���� ��ġ�ϴ� ���� ã��, ��ġ�ϴ� node ���� ����Ű�� �����͸� �����Ѵ�.
	*	@param	item	num���� ä���� �ִ� ������
	*	@return	ã���� �ش� node�� �����͸�, ã�� ���ϸ� NULL�� �����Ѵ�.
	*/
	T* GetPoint(T item);


	/**
	*	@brief	Primary key�� �������� �����͸� �˻��ϰ� �ش� �����͸� ������
	*	@pre	item�� ã�����ϴ� id���� ������ �־�� ��.
	*	@post	����Ʈ���� item�� id���� ��ġ�ϴ� ���� ã��, �ش� ������ item�� �����Ѵ�.
	*	@param	item	id���� ä���� �ִ� ������
	*	@return	ã���� 1, ã�� ���ϸ� 0�� �����Ѵ�.
	*/
	int Get(T &item);

	/**
	*	@brief	Initialize list iterator.
	*	@pre	list should be initialized.
	*	@post	iterator is reset.
	*/
	void ResetList();


	/**
	*	@brief	Current Pointer�� ���� node�� ����Ű���� �̵� �� �ش� ���ڵ带 ������
	*	@pre	list and list iterator should not be initialized.
	*	@post	iterator is moved to next item.
	*	@param	item	get current iterator's item. it does not need to be initialized.
	*/
	void GetNextItem(T &item);


	/**
	*	@brief	operator = overloading
	*	@pre	none.
	*	@post	����Ʈ�� anLinked�� ����Ʈ�� �����ϰ� �������ش�.
	*	@param	anLinked	������ ������ ���
	*	@return anLinked�� ������ ������ this*�� ����.
	*/
	const LinkedList<T>& operator =(const LinkedList<T> & anLinked);

private:
	NodeType<T> *m_pList;		///< NodeType�� m_pList ������
	NodeType<T> *m_pCurPoint;   ///< current pointer
	int m_nLength;				///<����Ʈ�� ����� ���ڵ� ��
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

// linked list�� ����� ���ڵ� ��� ����.
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

//���ο� ���ڵ带 ����Ʈ�� ����
template<typename T>
int LinkedList<T>::Add(T item) {
	NodeType<T> *Next_item;
	Next_item = new NodeType<T>;

	Next_item->info = item;
	Next_item->next = NULL;

	if (!m_nLength) { //�� ����Ʈ�̸� �ٷ� �߰��Ѵ�.
		m_pList = Next_item;
	}
	else {
		Next_item->next = m_pList;
		m_pList = Next_item;
	}

	m_nLength++; //���� ����
	return 1;	//add�� �����Ͽ������� 1�� ����.
}

//���ο� ���ڵ带 ����Ʈ���� ����
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

		if (data == item) { //��ġ�ϴ� item�� ã���� ��
			if (pre == NULL) {	// ���Ŵ���� ù��° ��ġ�ϴ� ���.
				temp = m_pCurPoint;
				m_pList = m_pList->next;
				found = 1;
				delete temp;
				break;
			}
			else {	// ���Ŵ���� ù��°�� �ƴ� ���� ��ġ�ϴ� ���.
				temp = m_pCurPoint;
				pre->next = m_pCurPoint->next;
				found = 1;
				delete temp;
				break;
			}
		}
		if (m_pCurPoint->next == NULL) { // �� �̻� ã�� �� �ִ� node�� �����Ƿ� �ݺ��� ����.
			break;
		}
	}
	m_nLength--;
	return found;
}


 // Primary key�� �������� �����͸� �˻��ϰ� �ش� �������� �����͸� ����.
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


// Primary key�� �������� �����͸� �˻��ϰ� �ش� �����͸� ������
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


// ���ڵ� ������ �ʱ�ȭ
template<typename T>
void LinkedList<T>::ResetList() {
	m_pCurPoint = NULL;
}

// Current Pointer�� ���� node�� ����Ű���� �̵� �� �ش� ���ڵ带 ������
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