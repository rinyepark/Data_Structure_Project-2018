#ifndef BINARYSEARCHTREE_H_
#define BINARYSEARCHTREE_H_

#include "Iterator.h"
#include <iostream>
using namespace std;

template<typename T>
class Iterator;

/**
*	node type struct.
*/
template <typename T>
class BinaryTreeNode {
public:
	~BinaryTreeNode() {}

	T data;						///< NodeType�� ����
	BinaryTreeNode<T>* left;	///< ���� ��带 ����ų ������
	BinaryTreeNode<T>* right;	///< ������ ��带 ����ų ������
};


/**
*	binary search AVL Tree.
*/
template <typename T>
class BinarySearchTree {
	friend class Iterator<T>;
public:

	/**
	*	defalut constructor.
	*/
	BinarySearchTree();

	/**
	*	copy constructor.
	*/
	BinarySearchTree(const BinarySearchTree<T> *&anList);

	/**
	*	destructor.
	*/
	~BinarySearchTree();

	/**
	*	@brief	����Ʈ�� ����ִ��� Ȯ����.
	*	@pre	none.
	*	@post	none.
	*	@return	����Ʈ�� ��������� true, ������� ������ false�� ������.
	*/
	bool IsEmpty() const;


	/**
	*	@brief	����Ʈ�� �� ������ Ȯ����.
	*	@pre	none.
	*	@post	none.
	*	@return	����Ʈ�� �� �̻� ��Ҹ� �߰��� �� ������ true, �߰��� �� ������ false�� ������.
	*/
	bool IsFull() const;


	/**
	*	@brief	BST�� ����� ���ڵ� ��� ����.
	*	@pre	none.
	*	@post	BST�� root�� ����Ǿ��� �ִ� ��� ��尡 ������.
	*/
	void MakeEmpty();

	/**
	*	@brief	BST�� ����� ���ڵ��� �� ���.
	*	@pre	����.
	*	@post	����.
	*	@return ���ڵ��� �� ��ȯ.
	*/
	int GetLength() const;

	/**
	*	@brief	primary key�� �������� ������ BST�� ���ο� ���ڵ� �߰�
	*	@pre	����.
	*	@post	���ο� ��尡 BST�� �߰���.
	*	@param	item	�߰��Ϸ��� ������.
	*	@return �߰��Ǿ����� 1��, ���������� 0�� ����.
	*/
	int Add(T item);

	/**
	*	@brief	primary key(num)�� �������� ���ڵ带 BST���� �����Ѵ�.
	*	@pre	�ش� ����Ʈ �� primary key�� ���� ���ڵ� �ݵ�� ����.
	*	@post	num�� ������ ���� item�� �̿��� ����Ʈ���� ������ �����ϸ� ����.
	*	@param	item	�����ϰ��� �ϴ� num���� ���� ������.
	*   @return ���� �����ϸ� 1, �ƴϸ� 0�� ������.
	*/
	int Delete(T item);

	/**
	*	@brief	primary key(num)�� �������� BST���� �׸��� �Ϻ� ������ �����Ѵ�.
	*	@pre	�ش� ����Ʈ �� primary key�� ���� ���ڵ� �ݵ�� ����.
	*	@post	num�� ������ ���� item�� �̿��� ����Ʈ���� �ش� �׸��� ������ �����Ѵ�.
	*	@param	item	�����ϰ��� �ϴ� ������
	*   @return ���� �����ϸ� 1, �ƴϸ� 0�� ������.
	*/
	int Replace(T item);


	/**
	*	@brief	Primary key�� �������� �����͸� �˻��ϰ� �ش� �������� �����͸� ������.
	*	@pre	item�� primary key���� ������ �־�� ��.
	*	@post	����Ʈ���� item��  primary key���� ��ġ�ϴ� ���� ã��, ��ġ�ϴ� node ���� ����Ű�� �����͸� �����Ѵ�.
	*	@param	item	 primary key���� ä���� �ִ� ������
	*	@return	ã���� �ش� node�� �����͸�, ã�� ���ϸ� NULL�� �����Ѵ�.
	*/
	T* GetPoint(T item);

	/**
	*	@brief	Primary key�� �������� �����͸� �˻��ϰ� �ش� �������� ������ �ٽ� item�� ��ȯ.
	*	@pre	item�� primary key���� ������ �־�� ��.
	*	@post	����Ʈ���� item��  primary key���� ��ġ�ϴ� ���� ã��, ��ġ�ϴ� data�� item�� ���� ��, found���� ������ ã�Ҵ��� ���� ����.
	*	@param	item	 primary key���� ä���� �ִ� ������, ���� ���� ��ȯ�� ���.
	*	@param	found	 item�� ã�Ҵ��� ���� ����.
	*/
	void Retrieve(T &item, bool &found) const;

	/**
	*	@brief	Primary key�� �������� �����͸� �˻�.
	*	@pre	item�� primary key���� ������ �־�� ��.
	*	@post	����Ʈ���� item��  primary key���� ��ġ�ϴ� ���� ã��, found���� ������ ã�Ҵ��� ���� ����.
	*	@param	item	 primary key���� ä���� �ִ� ������
	*	@param	found	 item�� ã�Ҵ��� ���� ����.
	*/
	void Isthere(T item, bool &found) const;


	/**
	*	@brief	BST����Ʈ �� ����� ������ InOrder ������� ���.
	*	@pre	root�� ����� ��� ����.
	*	@post	����.
	*   @param	out		cout�� ���� ����.
	*/
	void PrintTree(ostream &out) const;


	/**
	*	@brief	operator = overloading
	*	@pre	none.
	*	@post	����Ʈ�� anList�� ����Ʈ�� �����ϰ� �������ش�.
	*	@param	anList		������ ������ ���
	*	@return anList�� ������ ������ this*�� ����.
	*/
	const BinarySearchTree<T>& operator=(const BinarySearchTree<T> *&anList);


private:
	BinaryTreeNode<T>* root;	///< ��带 ����ų ������.
};

//operator = overoading
template<typename T>
const BinarySearchTree<T>& BinarySearchTree<T>::operator=(const BinarySearchTree<T> *&anList) {
	if (this != &anList) {	// this�� anList�� �ƴ� ���
		MakeEmpty();	// this�� �� list�� ����
		this->root = anList; //reference ����
	}
	return *this;	//this��ȯ
}

// default constructor.
template <typename T>
BinarySearchTree<T>::BinarySearchTree() {
	root = NULL;
}

// copy constructor.
template<typename T>
BinarySearchTree<T>::BinarySearchTree(const BinarySearchTree<T> *&anList) {
	this->m_nLength = anList.m_nLength;
	this = anList;
}

//destructor
template <typename T>
BinarySearchTree<T>::~BinarySearchTree() {
	MakeEmpty();	//�����Լ� ���
}

//BST�� ����ִ��� Ȯ��
template <typename T>
bool BinarySearchTree<T>::IsEmpty() const {
	if (root == NULL)	// ��Ʈ�� NULL�̸� ����������� true ����.
		return true;
	else
		return false;	// �׷��� ������ false ����.
}

//BST�� ������ á���� Ȯ��.
template <typename T>
bool BinarySearchTree<T>::IsFull() const {
	try {	//���ο� ��带 �����Ҵ� �� ���ܰ� �߻��� ��� true��, �����Ҵ� �Ǹ� false ����.
		BinaryTreeNode<T> *temp = new BinaryTreeNode<T>;
		delete temp;
		return false;	//���� �߻� ���� ���
	}
	catch (bad_alloc exception) {	//���� �߻� ���.
		return true;
	}
}

//BST�� ����� ���ڵ� ��� ����.
template <typename T>
void BinarySearchTree<T>::MakeEmpty() {
	MakeEmptyTree(root);	// �����Լ� �̿�.
	root = NULL;
}

//BST�� �����ϴ� ��� ����.
template <typename T>
int BinarySearchTree<T>::GetLength() const {
	return CountNodes(root);	//�����Լ� �̿�.
}

//BST �� ���ο� ��� �߰�
template <typename T>
int BinarySearchTree<T>::Add(T item) {	//�� �߰��Ǹ� 1��, �ƴϸ� 0�� ����.
	if (Insert(root, item))	//�����Լ� �̿�.
		return 1;
	else
		return 0;
}

//BST �� Ư�� ��� ����.
template <typename T>
int BinarySearchTree<T>::Delete(T item) {	//�� ���ŵǸ� 1��, �ƴϸ� 0�� ����.
	if (DeleteItem(root, item))	//�����Լ� �̿�.
		return 1;
	else
		return 0;
}

//BST �� Ư�� ��� �Ϻ� ���� ����.
template<typename T>
int BinarySearchTree<T>::Replace(T item) {	//�� ����Ǹ� 1��, �ƴϸ� 0�� ����.
	if (ReplaceItem(root, item))	//�����Լ� �̿�.
		return 1;
	else
		return 0;
}

//Primary key�� �������� �����͸� �˻��ϰ� �ش� �������� �����͸� ������.
template<typename T>
T* BinarySearchTree<T>::GetPoint(T item) {
	return GetPointItem(root, item);	//�����Լ� �̿�.
}

//Primary key�� �������� �����͸� �˻��ϰ� �ش� �������� ������ �ٽ� item�� ��ȯ.
template <typename T>
void BinarySearchTree<T>::Retrieve(T &item, bool &found) const {
	RetrieveItem(root, item, found);	//�����Լ� �̿�.
}

//Primary key�� �������� �����͸� �˻��ϰ� �˻� ���� ����.
template <typename T>
void BinarySearchTree<T>::Isthere(T item, bool &found) const {
	IsthereItem(root, item, found);
}

//BST����Ʈ �� ����� ������ InOrder ������� ���.
template <typename T>
void BinarySearchTree<T>::PrintTree(ostream &out) const {
	if (!IsEmpty()) {
		PrintInOrder(root, out);	//�����Լ� �̿�.
		cout << endl;
	}
}

#endif // !BINARYSEARCHTREE_H_

//Binary Search Tree �ʱ�ȭ
template <typename T>
void MakeEmptyTree(BinaryTreeNode<T>*&root) {
	if (root != NULL) {	//����Լ� �������, tree�� �� �Ʒ������� ����� ��带 ������ ������ ���.
		MakeEmptyTree(root->left);
		MakeEmptyTree(root->right);
		delete root;
	}
}

//BST ��� ����
template <typename T>
int CountNodes(BinaryTreeNode<T> *root) {
	if (root == NULL)	//��� �Լ� �������, root�� null�� �ƴϸ� ����, �������� ��� ������ �ڱ��ڽ��� ���س����� ������� ���� ���.
		return 0;
	else
		return CountNodes(root->left) + CountNodes(root->right) + 1;
}


//����� ���� ���
template<typename T>
int GetHeight(BinaryTreeNode<T> *root) {
	if (root == NULL)
		return -1;	//����ִ� ��� ���̴� -1
	else {
		int leftH = GetHeight(root->left);	//���� ����� ����
		int rightH = GetHeight(root->right); //������ ����� ����
		int MaxH = leftH > rightH ? leftH : rightH;	// �� �� �� ū �� ����
		return MaxH + 1;	//ū ���� 1�� ���� ���� ��ȯ
	}
}

//Balance Factor ���
template <typename T>
int GetBalanceFactor(BinaryTreeNode<T>* item) {
	int LeftHeight = GetHeight(item->left);	// ���� ����� ����
	int RightHeight = GetHeight(item->right);//������ ����� ����

	return LeftHeight - RightHeight;	//���� ����� ���̿��� ������ ����� ���� ���̸� Balance Factor�� ��ȯ
}


//BST ���ο� ��� �߰�
template <typename T>
bool Insert(BinaryTreeNode<T>*& root, T item) {
	//�߰��� ��� ����
	bool temp;
	if (root == NULL) {//�� ��Ʈ�̸�
		BinaryTreeNode<T> *add_node;
		add_node = new BinaryTreeNode<T>;
		add_node->left = NULL;
		add_node->right = NULL;
		add_node->data = item;
		root = add_node;
		return true;
	}
	else if (root->data < item) {	//item�� data���� ū ���
		temp = Insert(root->right, item);	//root�� ���������� �̵� �� �ٽ� �߰�.
		SetBalance(root);	//Balance ���߱�
		return temp;
	}
	else if (root->data > item) {	//item�� data���� ���� ���
		temp = Insert(root->left, item);	//root�� �������� �̵� �� �ٽ� �߰�.
		SetBalance(root);	//Balance ���߱�
		return temp;
	}
	else {
		return false;	//�� �̿��� ��� false ����.
	}
}

//�뷱�� ���͸� �̿��� Ʈ���� �뷱�� ����.
template <typename T>
void SetBalance(BinaryTreeNode<T>*& root) {
	int BF = GetBalanceFactor(root);

	if (BF > 1) { //root ���� ���� ����Ʈ���� ���Ե� ���
		if (GetBalanceFactor(root->left) > 0) {// �� �� ���� ����� ������ ���� ���
			LLRotation(root);	//LL Rotation
		}
		else { // �� �� ������ ����� ������ ���� ���
			LRRotation(root);	//LR Rotation
		}
	}
	else if (BF < -1) { //root ���� ������ ����Ʈ���� ���Ե� ���
		if (GetBalanceFactor(root->right) > 0) { // �� �� ���� ����� ������ ���� ���
			RLRotation(root); //RL Rotation
		}
		else {//�� �� ������ ����� ������ ���� ���
			RRRotation(root); //RR Roataion
		}
	}
}

//Outside case�� �� ���� ��ȸ���ϴ� LL Rotaion
template<typename T>
void LLRotation(BinaryTreeNode<T>*& root) {
	BinaryTreeNode<T>* temp;
	temp = root->left;	//root�� ���ʳ�� ����Ŵ
	root->left = temp->right;	//root�� ������ ���� root�� ���ʳ���� ������ ����Ű���� ��
	temp->right = root;	//���� root�� ���ʳ���� �������� root�� ����

	root = temp;	//root�� ���� root�� ���ʳ��� ����
}

//Inside case�� �� �ι�, ��ȸ���� ��ȸ���� �ϴ� LR Rotaion 
template<typename T>
void LRRotation(BinaryTreeNode<T>*& root) {
	RRRotation(root->left); //root�� ���� ��带 �������� RR Rotation(��ȸ��) ��Ŵ
	LLRotation(root); //root�� LL Rotation(��ȸ��) ��Ŵ
}

//Outside case�� �� ���� ��ȸ���ϴ� RR Rotaion
template<typename T>
void RRRotation(BinaryTreeNode<T>*& root) {
	BinaryTreeNode<T>*temp;
	temp = root->right; //root�� �����ʳ�� ����Ŵ
	root->right = temp->left;//root�� ���������� ���� root�� �����ʳ���� ������ ����Ű���� ��
	temp->left = root; //���� root�� �����ʳ���� ������ root�� ����

	root = temp;	//root�� ���� root�� �����ʳ��� ����
}

//Inside case�� �� �ι�, ��ȸ���� ��ȸ���� �ϴ� RL Rotaion 
template<typename T>
void RLRotation(BinaryTreeNode<T>*& root) {
	LLRotation(root->right);//root�� ������ ��带 �������� LL Rotation(��ȸ��) ��Ŵ
	RRRotation(root); //root�� RR Rotation(��ȸ��) ��Ŵ
}

//root�� ���� �����ʿ� ��ġ�� ������ ã�� ����.
template <typename T>
void GetPredecessor(BinaryTreeNode<T>* root, T&item) {
	//�߰� ���� root�� �����ϴ� ���, ���� root�� ���� subtree �� ���� ū ��(���� �����ʿ� ��ġ�� ��)�� ã�� item�� ���� �����ϴ� ���
	while (root->right != NULL) {	//�� ������ ��忡 ������ ������ �̵�
		root = root->right;
	}
	item = root->data;	//ã�� �� ����.
}

//BST ��� ����
template<typename T>
void DeleteNode(BinaryTreeNode<T>*&root) {
	BinaryTreeNode<T>* del_node;	//�����ϰ��� �ϴ� ��� ����ų ������.
	del_node = new BinaryTreeNode<T>;	//�����Ҵ�
	del_node = root;	//root(�����Ϸ��� ��� ����Ŵ)�� ���� ��� ����Ű���� ����.
	if (root->left == NULL) {	//�ش� ����� ������ NULL�� ���
		root = root->right;	// root�� root�� ������ subtree�� ����Ű���� ����
		delete del_node;	//�ش� ��� ����
	}
	else if (root->right == NULL) {	//�ش� ����� �������� NULL�� ���(������ ���� �ݵ�� NULL�� �ƴ� ��Ȳ)
		root = root->left;	// root�� root�� ���� subtree�� ����Ű���� ����
		delete del_node;	//�ش� ��� ����
	}
	else { // �ش� ����� ����, ������ ��� NULL�� �ƴ� ���
		T temp;
		GetPredecessor(root->left, temp);	//root���� ���� ���� �� ���� ū ���� ������ temp�� �޾ƿ�.
		root->data = temp;	// ���� �����ϰ��� �ߴ� root�� �����͸� �޾ƿ� ������ ����.
		DeleteItem(root->left, temp);	//temp ���� ���� ��� ����.
	}

}

//BST �� Ư�� ������ ���� ��� ����
template<typename T>
bool DeleteItem(BinaryTreeNode<T>*&root, T item) {
	if (root->data < item) {	// item���� data���� ū ���
		return DeleteItem(root->right, item);	//root�� ������ subtree���� �ش� item �ٽ� ã��.
	}
	else if (root->data > item) {	//item���� data���� ���� ���
		return DeleteItem(root->left, item);	//root�� ���� subtree���� �ش� item �ٽ� ã��.
	}
	else {	//ã�� ���
		DeleteNode(root);	//�ش� root�� ����Ű�� ��� ����
		return true;	//���� �� 1 ����.
	}
}

//BST�� Ư�� ��忡 �Ϻ� ���� ����
template<typename T>
bool ReplaceItem(BinaryTreeNode<T>*&root, T item) {
	if (root->data < item) {	// item���� data���� ū ���
		return ReplaceItem(root->right, item);	//root�� ������ subtree���� �ش� item �ٽ� ã��.
	}
	else if (root->data > item) {	//item���� data���� ���� ���
		return ReplaceItem(root->left, item);	//root�� ���� subtree���� �ش� item �ٽ� ã��.
	}
	else {	//ã�� ���
		root->data = item;	//�ش� root�� ����Ű�� ����� data�� item���� ����.
		return true;	//���� �� 1 ����.
	}
}

//BST�� Ư�� ����� data�� ������ ��ȯ.
template<typename T>
T* GetPointItem(BinaryTreeNode<T>*root, T item) {
	if (root == NULL) {	//root�� NULL�� ���
		return NULL;	//NULL ����.
	}
	else if (root->data < item) {		// item���� data���� ū ���
		return GetPointItem(root->right, item);	//root�� ������ subtree���� �ش� item �ٽ� ã��.
	}
	else if (root->data > item) {	//item���� data���� ���� ���
		return GetPointItem(root->left, item);	//root�� ���� subtree���� �ش� item �ٽ� ã��.
	}
	else {	//ã�� ���
		return &(root->data);	//�ش� root�� ����Ű�� ����� data�� �ּҰ� ����.
	}
}

//BST Ư�� ����� data �˻�
template <typename T>
void RetrieveItem(BinaryTreeNode<T>* root, T &item, bool &found) {
	if (root == NULL) {	//root�� NULL�� ���
		found = false;	//ã�� ���������� false������ ����.
	}
	else if (root->data < item) {		// item���� data���� ū ���
		RetrieveItem(root->right, item, found);	//root�� ������ subtree���� �ش� item �ٽ� ã��.
	}
	else if (root->data > item) {	//item���� data���� ���� ���
		RetrieveItem(root->left, item, found);	//root�� ���� subtree���� �ش� item �ٽ� ã��.
	}
	else { //ã�� ���
		item = root->data;	//item�� �ش� ����� data �� ����.
		found = true;	//ã�ұ� ������ true������ ����.
	}
}

//BST Ư�� ����� data �˻�
template <typename T>
void IsthereItem(BinaryTreeNode<T>* root, T item, bool &found) {
	if (root == NULL) {	//root�� NULL�� ���
		found = false;	//ã�� ���������� false������ ����.
	}
	else if (root->data < item) {		// item���� data���� ū ���
		IsthereItem(root->right, item, found);	//root�� ������ subtree���� �ش� item �ٽ� ã��.
	}
	else if (root->data > item) {	//item���� data���� ���� ���
		IsthereItem(root->left, item, found);	//root�� ���� subtree���� �ش� item �ٽ� ã��.
	}
	else { //ã�� ���
		found = true;	//ã�ұ� ������ true������ ����.
	}
}

//BST ���(InOrder���)
template<typename T>
void PrintInOrder(BinaryTreeNode<T>*root, ostream& out) {
	//InOrder ����� ���.
	if (root != NULL) {
		PrintInOrder(root->left, out);
		out << root->data;
		PrintInOrder(root->right, out);
	}
}
