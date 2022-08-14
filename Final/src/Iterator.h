#ifndef ITERATOR_H_
#define ITERATOR_H_

#include <iostream>
using namespace std;

template <typename T>
class BinaryTreeNode;
template <typename T>
class BinarySearchTree;

/**
*	Iterator class.
*/
template <typename T>
class Iterator {
	friend class BinarySearchTree<T>;
public:
	/**
	*	default constructor
	*/
	Iterator(BinaryTreeNode<T>* in_pCurPoint, const BinarySearchTree<T>& list);

	/**
	*	default constructor
	*/
	Iterator(const BinarySearchTree<T>& list);


	/**
	*	@brief	list�� ���� ���Ұ� NULL�� �ƴ��� �˻�.
	*	@pre	Iterator�� �����ؾ���.
	*	@post	����
	*	@return	���� ���Ұ� NULL�� �ƴϸ� true��, NULL�̸� false�� ������.
	*/
	bool IsNotNull();


	/**
	*	@brief	���� data�� ����.
	*	@pre	Iterator�� �����ؾ���.
	*	@post	����.
	*	@return	���� m_pCurPointer�� ����Ű�� data�� ����.
	*/
	T GetCurrentdata();

	/**
	*	@brief	���� ��带 �������� ������ �����Ͱ� ����Ű�� iterator�� ������ ��ȯ
	*	@pre	�̸� ��带 ����Ű�� Iterator�� �����ؾ���.
	*	@post	����.
	*	@return	m_pCurPointer�� ���� ����� ������ �����͸� ����Ű�� iterator ��ȯ
	*/
	Iterator<T> MoveLeft();

	/**
	*	@brief	���� ��带 �������� �������� �����Ͱ� ����Ű�� iterator�� ������ ��ȯ
	*	@pre	�̸� ��带 ����Ű�� Iterator�� �����ؾ���.
	*	@post	����.
	*	@return	m_pCurPointer�� ���� ����� �������� �����͸� ����Ű�� iterator ��ȯ
	*/
	Iterator<T> MoveRight();

private:
	BinaryTreeNode<T> *m_pCurPointer;	///< ��带 ����ų ������
	const BinarySearchTree<T> &m_list;	///< ����� ����Ʈ�� ���� ����
};

#endif // !DOUBLYITERATOR_H_


// default constructor.
template <typename T>
Iterator<T>::Iterator(const BinarySearchTree<T> &list) :
	m_list(list), m_pCurPointer(list.root) {}

// default constructor.
template <typename T>
Iterator<T>::Iterator(BinaryTreeNode<T>* in_pCurPoint, const BinarySearchTree<T>& list) :
	m_list(list), m_pCurPointer(in_pCurPoint) {}

//���� m_pCurPointer�� Null�� �ƴ��� �Ǵ�.
template <typename T>
bool Iterator<T>::IsNotNull() {
	if (m_pCurPointer == NULL)
		return false;
	else
		return true;
}

//���� node�� ����.
template <typename T>
T Iterator<T>::GetCurrentdata() {
	return m_pCurPointer->data;
}

//���� ��忡�� ������ �����͸� ���� iterator�� ������ ����.
template <typename T>
Iterator<T> Iterator<T>::MoveLeft() {
	Iterator<T> iter(m_pCurPointer->left, m_list);
	return iter;

}

//���� ��忡�� �������� �����͸� ���� iterator�� ������ ����.
template <typename T>
Iterator<T> Iterator<T>::MoveRight() {
	Iterator<T> iter(m_pCurPointer->right, m_list);
	return iter;
}