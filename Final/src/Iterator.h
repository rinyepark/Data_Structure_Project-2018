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
	*	@brief	list의 현재 원소가 NULL이 아닌지 검사.
	*	@pre	Iterator가 존재해야함.
	*	@post	없다
	*	@return	현재 원소가 NULL이 아니면 true를, NULL이면 false를 리턴함.
	*/
	bool IsNotNull();


	/**
	*	@brief	현재 data를 리턴.
	*	@pre	Iterator가 존재해야함.
	*	@post	없다.
	*	@return	현재 m_pCurPointer가 가리키는 data를 리턴.
	*/
	T GetCurrentdata();

	/**
	*	@brief	현재 노드를 기준으로 왼쪽의 포인터가 가리키는 iterator를 생성해 반환
	*	@pre	미리 노드를 가리키는 Iterator가 존재해야함.
	*	@post	없다.
	*	@return	m_pCurPointer가 현재 노드의 왼쪽의 포인터를 가리키는 iterator 반환
	*/
	Iterator<T> MoveLeft();

	/**
	*	@brief	현재 노드를 기준으로 오른쪽의 포인터가 가리키는 iterator를 생성해 반환
	*	@pre	미리 노드를 가리키는 Iterator가 존재해야함.
	*	@post	없다.
	*	@return	m_pCurPointer가 현재 노드의 오른쪽의 포인터를 가리키는 iterator 반환
	*/
	Iterator<T> MoveRight();

private:
	BinaryTreeNode<T> *m_pCurPointer;	///< 노드를 가리킬 포인터
	const BinarySearchTree<T> &m_list;	///< 사용할 리스트의 참조 변수
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

//현재 m_pCurPointer가 Null이 아닌지 판단.
template <typename T>
bool Iterator<T>::IsNotNull() {
	if (m_pCurPointer == NULL)
		return false;
	else
		return true;
}

//현재 node를 리턴.
template <typename T>
T Iterator<T>::GetCurrentdata() {
	return m_pCurPointer->data;
}

//현재 노드에서 왼쪽의 포인터를 가진 iterator를 생성해 리턴.
template <typename T>
Iterator<T> Iterator<T>::MoveLeft() {
	Iterator<T> iter(m_pCurPointer->left, m_list);
	return iter;

}

//현재 노드에서 오른쪽의 포인터를 가진 iterator를 생성해 리턴.
template <typename T>
Iterator<T> Iterator<T>::MoveRight() {
	Iterator<T> iter(m_pCurPointer->right, m_list);
	return iter;
}