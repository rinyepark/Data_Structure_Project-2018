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
	T info;				///< NodeType�� ����
	NodeType *next;		///< ���� ��带 ����ų ������
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
	*	@brief	linked list�� ����� ���ڵ� ��� ����.
	*	@pre	none.
	*	@post	linked list�� ����Ǿ� �ִ� node�� ��� �����Ͽ� �� list�� �����.
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
	*	@brief	list�� deep copy.
	*	@pre	list�� �����ؾ� ��.
	*	@post	list�� ��� ������ this->singlelinkedlist�� deep copy��.
	*	@param	list	deep copy�ϰ��� �ϴ� ����Ʈ�� �ּҰ�.
	*/
	void copySLL(const SingleLinkedList<T>& list);


	/**
	*	@brief	primary key�� �������� ������ �ǵ��� ���ο� ���ڵ带 ����Ʈ�� ������.
	*	@pre	list should be initialized.
	*	@post	���ο� �����͸� �����Ͽ� ����Ʈ�� �߰��Ѵ�.
	*	@param	item	�߰��ϰ��� �ϴ� ������.
	*/
	int Add(T item);


	/**
	*	@brief	primary key�� �������� ���ڵ带 ����Ʈ���� �����Ѵ�.
	*	@pre	list should be initialized.
	*	@post	id�� ������ ���� item�� �̿��� ����Ʈ���� ������ �����ϸ� ������ ��, �ش� �����͸� item�� �����Ѵ�.
	*	@param	item	�����ϰ��� �ϴ� id���� ���� �������̸�, ���� ���ŵ� �������� ������ �޴´�.
	*/
	int Delete(T &item);

	/**
	*	@brief	primary key�� �������� �׸��� �����Ѵ�.
	*	@pre	list should be initialized.
	*	@post	id�� ������ ���� item�� �̿��� ����Ʈ���� �ش� �׸��� ������ �����Ѵ�.
	*	@param	item	�����ϰ��� �ϴ� ������.
	*/
	int Replace(T item);


	/**
	*	@brief	Primary key�� �������� �����͸� �˻��ϰ� �ش� �����͸� ������
	*	@pre	item�� ã�����ϴ� id���� ������ �־�� ��.
	*	@post	����Ʈ���� item�� num���� ��ġ�ϴ� ���� ã��, �ش� ������ item�� �����Ѵ�.
	*	@param	item	id�� ä���� �ִ� ������
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
	*	@brief	Primary key�� �������� �����͸� �˻��ϰ� �ش� �������� �����͸� ������.
	*	@pre	item�� id���� ������ �־�� ��.
	*	@post	����Ʈ���� item�� id���� ��ġ�ϴ� ���� ã��, ��ġ�ϴ� node ���� ����Ű�� �����͸� �����Ѵ�.
	*	@param	item	id���� ä���� �ִ� ������
	*	@return	ã���� �ش� node�� �����͸�, ã�� ���ϸ� NULL�� �����Ѵ�.
	*/
	T* GetPoint(T item);

	/**
	*	@brief	operator = overloading
	*	@pre	none.
	*	@post	����Ʈ�� anLinked�� ����Ʈ�� �����ϰ� �������ش�.
	*	@param	anLinked	������ ������ ���
	*	@return anLinked�� ������ ������ this*�� ����.
	*/
	const SingleLinkedList<T>& operator =(const SingleLinkedList<T> & anLinked);

private:
	NodeType<T> *m_pList;		///< NodeType�� m_pList ������
	NodeType<T> *m_pCurPoint;   ///< current pointer
	int m_nLength;				///<����Ʈ�� ����� ���ڵ� ��
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

// ����Ʈ�� ����ִ��� Ȯ��.
template<typename T>
bool SingleLinkedList<T>::IsEmpty() {
	if (m_nLength == 0) {
		return true;
	}
	else
		return false;
}

// linked list�� ����� ���ڵ� ��� ����.
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

//���ο� ���ڵ带 ����Ʈ�� ����
template<typename T>
int SingleLinkedList<T>::Add(T item) {
	NodeType<T> *Next_item;
	Next_item = new NodeType<T>;

	Next_item->info = item;
	Next_item->next = NULL;

	if (!m_nLength) { //�� ����Ʈ�̸� �ٷ� �߰��Ѵ�.
		m_pList = Next_item;
	}
	else {
		ResetList();
		NodeType<T> *pre_temp;
		T temp;
		while (true) {
			pre_temp = m_pCurPoint;
			GetNextItem(temp);

			if (Next_item->info < temp) { //����Ǿ�� �ϴ� �ڸ��� ã�� ���

				//pre_temp�� NULL�̸� ù��° �ڸ��� �����ϴ� ���
				if (pre_temp == NULL) {
					Next_item->next = m_pCurPoint;
					m_pList = Next_item;
					break;
				}

				//�߰��� �����ϴ� ���
				else {
					Next_item->next = m_pCurPoint;
					pre_temp->next = Next_item;
					break;
				}
			}

			//current pointer�� next�� NULL�� �Ǹ� ������ ��忡 �����Ͽ�������, �������� �����ϴ� ���.
			if (m_pCurPoint->next == NULL) {
				m_pCurPoint->next = Next_item;
				break;
			}
		}
	}
	m_nLength++; //���� ����
	return 1;	//add�� �����Ͽ������� 1�� ����.
}

//���ο� ���ڵ带 ����Ʈ���� ����
template<typename T>
int SingleLinkedList<T>::Delete(T& item) {
	bool found = false;

	if (Get(item)) { //����Ʈ���� ��ġ�ϴ� item�� �����ϴ� ���.
		ResetList();
		T data;
		NodeType<T> *pre;
		NodeType<T> *temp;

		while (1) {
			pre = m_pCurPoint;
			GetNextItem(data);

			if (data == item) { //��ġ�ϴ� item�� ã���� ��
				item = data;   //�ش� data�� ������ item�� ����.
				if (pre == NULL) {	// ���Ŵ���� ù��° ��ġ�ϴ� ���.
					temp = m_pCurPoint;
					m_pList = m_pList->next;
					found = true;
					delete temp;
					break;
				}
				else {	// ���Ŵ���� ù��°�� �ƴ� ���� ��ġ�ϴ� ���.
					temp = m_pCurPoint;
					pre->next = m_pCurPoint->next;
					found = true;
					delete temp;
					break;
				}
			}
			if (m_pCurPoint->next == NULL) { // �� �̻� ã�� �� �ִ� node�� �����Ƿ� �ݺ��� ����.
				break;
			}
		}
	}

	//���������� �����ϸ� ���̸� �ϳ� ���̰� 1�� ����.
	if (found) {
		m_nLength--;
		return 1;
	}
	//�������� ������ �� -1�� ����.
	else {
		return -1;
	}
}

// �ش� ���ڵ带 ����Ʈ���� ���� ����
template<typename T>
int SingleLinkedList<T>::Replace(T item) {
	T iTemp = item;
	bool found = 0;
	if (!Get(iTemp)) { //�ش� �����͸� ã�� ���ϸ� ����.
		return 0;
	}
	else {	//�����͸� ã���� ���� ����
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

	if (found) {	//���濡 �����ϸ� 1��, �����ϸ� 0�� ����.
		return 1;
	}
	else
		return 0;
}

// Primary key�� �������� �����͸� �˻��ϰ� �ش� �����͸� ������
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

// ���ڵ� ������ �ʱ�ȭ
template<typename T>
void SingleLinkedList<T>::ResetList() {
	m_pCurPoint = NULL;
}

// Current Pointer�� ���� node�� ����Ű���� �̵� �� �ش� ���ڵ带 ������
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

// Primary key�� �������� �����͸� �˻��ϰ� �ش� �������� �����͸� ����.
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
