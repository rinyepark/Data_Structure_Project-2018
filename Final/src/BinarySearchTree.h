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

	T data;						///< NodeType의 정보
	BinaryTreeNode<T>* left;	///< 왼쪽 노드를 가리킬 포인터
	BinaryTreeNode<T>* right;	///< 오른쪽 노드를 가리킬 포인터
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
	*	@brief	리스트가 비어있는지 확인함.
	*	@pre	none.
	*	@post	none.
	*	@return	리스트가 비어있으면 true, 비어있지 않으면 false를 리턴함.
	*/
	bool IsEmpty() const;


	/**
	*	@brief	리스트가 꽉 차는지 확인함.
	*	@pre	none.
	*	@post	none.
	*	@return	리스트에 더 이상 요소를 추가할 수 없으면 true, 추가할 수 있으면 false를 리턴함.
	*/
	bool IsFull() const;


	/**
	*	@brief	BST에 연결된 레코드 모두 삭제.
	*	@pre	none.
	*	@post	BST의 root에 연결되어져 있는 모든 노드가 삭제됨.
	*/
	void MakeEmpty();

	/**
	*	@brief	BST에 연결된 레코드의 수 계산.
	*	@pre	없음.
	*	@post	없음.
	*	@return 레코드의 수 반환.
	*/
	int GetLength() const;

	/**
	*	@brief	primary key를 기준으로 정렬해 BST에 새로운 레코드 추가
	*	@pre	없음.
	*	@post	새로운 노드가 BST에 추가됨.
	*	@param	item	추가하려는 데이터.
	*	@return 추가되었으면 1을, 실패했으면 0을 리턴.
	*/
	int Add(T item);

	/**
	*	@brief	primary key(num)를 기준으로 레코드를 BST에서 제거한다.
	*	@pre	해당 리스트 내 primary key를 가진 레코드 반드시 존재.
	*	@post	num의 정보만 가진 item을 이용해 리스트에서 정렬을 유지하며 제거.
	*	@param	item	제거하고자 하는 num값만 가진 데이터.
	*   @return 제거 성공하면 1, 아니면 0을 리턴함.
	*/
	int Delete(T item);

	/**
	*	@brief	primary key(num)를 기준으로 BST에서 항목의 일부 정보를 변경한다.
	*	@pre	해당 리스트 내 primary key를 가진 레코드 반드시 존재.
	*	@post	num의 정보만 가진 item을 이용해 리스트에서 해당 항목의 정보를 변경한다.
	*	@param	item	변경하고자 하는 데이터
	*   @return 변경 성공하면 1, 아니면 0을 리턴함.
	*/
	int Replace(T item);


	/**
	*	@brief	Primary key를 기준으로 데이터를 검색하고 해당 데이터의 포인터를 가져옴.
	*	@pre	item이 primary key값을 가지고 있어야 함.
	*	@post	리스트에서 item의  primary key값과 일치하는 값을 찾고, 일치하는 node 값을 가리키는 포인터를 리턴한다.
	*	@param	item	 primary key값만 채워져 있는 데이터
	*	@return	찾으면 해당 node의 포인터를, 찾지 못하면 NULL을 리턴한다.
	*/
	T* GetPoint(T item);

	/**
	*	@brief	Primary key를 기준으로 데이터를 검색하고 해당 데이터의 정보를 다시 item에 반환.
	*	@pre	item이 primary key값을 가지고 있어야 함.
	*	@post	리스트에서 item의  primary key값과 일치하는 값을 찾고, 일치하는 data를 item의 전달 후, found값을 변경해 찾았는지 여부 전달.
	*	@param	item	 primary key값만 채워져 있는 데이터, 이후 내용 반환에 사용.
	*	@param	found	 item을 찾았는지 여부 전달.
	*/
	void Retrieve(T &item, bool &found) const;

	/**
	*	@brief	Primary key를 기준으로 데이터를 검색.
	*	@pre	item이 primary key값을 가지고 있어야 함.
	*	@post	리스트에서 item의  primary key값과 일치하는 값을 찾고, found값을 변경해 찾았는지 여부 전달.
	*	@param	item	 primary key값만 채워져 있는 데이터
	*	@param	found	 item을 찾았는지 여부 전달.
	*/
	void Isthere(T item, bool &found) const;


	/**
	*	@brief	BST리스트 내 노드의 정보를 InOrder 방식으로 출력.
	*	@pre	root에 연결된 노드 존재.
	*	@post	없음.
	*   @param	out		cout할 형식 전달.
	*/
	void PrintTree(ostream &out) const;


	/**
	*	@brief	operator = overloading
	*	@pre	none.
	*	@post	리스트를 anList의 리스트와 동일하게 정의해준다.
	*	@param	anList		정보를 가져올 대상
	*	@return anList의 정보를 정의한 this*를 리턴.
	*/
	const BinarySearchTree<T>& operator=(const BinarySearchTree<T> *&anList);


private:
	BinaryTreeNode<T>* root;	///< 노드를 가리킬 포인터.
};

//operator = overoading
template<typename T>
const BinarySearchTree<T>& BinarySearchTree<T>::operator=(const BinarySearchTree<T> *&anList) {
	if (this != &anList) {	// this가 anList가 아닌 경우
		MakeEmpty();	// this를 빈 list로 만듦
		this->root = anList; //reference 전달
	}
	return *this;	//this반환
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
	MakeEmpty();	//전역함수 사용
}

//BST가 비어있는지 확인
template <typename T>
bool BinarySearchTree<T>::IsEmpty() const {
	if (root == NULL)	// 루트가 NULL이면 비어있음으로 true 리턴.
		return true;
	else
		return false;	// 그렇지 않으면 false 리턴.
}

//BST가 완전히 찼는지 확인.
template <typename T>
bool BinarySearchTree<T>::IsFull() const {
	try {	//새로운 노드를 동적할당 해 예외가 발생할 경우 true를, 동적할당 되면 false 리턴.
		BinaryTreeNode<T> *temp = new BinaryTreeNode<T>;
		delete temp;
		return false;	//예외 발생 안한 경우
	}
	catch (bad_alloc exception) {	//예외 발생 경우.
		return true;
	}
}

//BST에 연결된 레코드 모두 삭제.
template <typename T>
void BinarySearchTree<T>::MakeEmpty() {
	MakeEmptyTree(root);	// 전역함수 이용.
	root = NULL;
}

//BST내 존재하는 노드 개수.
template <typename T>
int BinarySearchTree<T>::GetLength() const {
	return CountNodes(root);	//전역함수 이용.
}

//BST 내 새로운 노드 추가
template <typename T>
int BinarySearchTree<T>::Add(T item) {	//잘 추가되면 1을, 아니면 0을 리턴.
	if (Insert(root, item))	//전역함수 이용.
		return 1;
	else
		return 0;
}

//BST 내 특정 노드 제거.
template <typename T>
int BinarySearchTree<T>::Delete(T item) {	//잘 제거되면 1을, 아니면 0을 리턴.
	if (DeleteItem(root, item))	//전역함수 이용.
		return 1;
	else
		return 0;
}

//BST 내 특정 노드 일부 내용 변경.
template<typename T>
int BinarySearchTree<T>::Replace(T item) {	//잘 변경되면 1을, 아니면 0을 리턴.
	if (ReplaceItem(root, item))	//전역함수 이용.
		return 1;
	else
		return 0;
}

//Primary key를 기준으로 데이터를 검색하고 해당 데이터의 포인터를 가져옴.
template<typename T>
T* BinarySearchTree<T>::GetPoint(T item) {
	return GetPointItem(root, item);	//전역함수 이용.
}

//Primary key를 기준으로 데이터를 검색하고 해당 데이터의 정보를 다시 item에 반환.
template <typename T>
void BinarySearchTree<T>::Retrieve(T &item, bool &found) const {
	RetrieveItem(root, item, found);	//전역함수 이용.
}

//Primary key를 기준으로 데이터를 검색하고 검색 여부 전달.
template <typename T>
void BinarySearchTree<T>::Isthere(T item, bool &found) const {
	IsthereItem(root, item, found);
}

//BST리스트 내 노드의 정보를 InOrder 방식으로 출력.
template <typename T>
void BinarySearchTree<T>::PrintTree(ostream &out) const {
	if (!IsEmpty()) {
		PrintInOrder(root, out);	//전역함수 이용.
		cout << endl;
	}
}

#endif // !BINARYSEARCHTREE_H_

//Binary Search Tree 초기화
template <typename T>
void MakeEmptyTree(BinaryTreeNode<T>*&root) {
	if (root != NULL) {	//재귀함수 방식으로, tree의 맨 아래서부터 연결된 노드를 삭제해 나가는 방식.
		MakeEmptyTree(root->left);
		MakeEmptyTree(root->right);
		delete root;
	}
}

//BST 노드 개수
template <typename T>
int CountNodes(BinaryTreeNode<T> *root) {
	if (root == NULL)	//재귀 함수 방식으로, root가 null이 아니면 왼쪽, 오른쪽의 노드 개수와 자기자신을 더해나가는 방식으로 개수 계산.
		return 0;
	else
		return CountNodes(root->left) + CountNodes(root->right) + 1;
}


//노드의 높이 계산
template<typename T>
int GetHeight(BinaryTreeNode<T> *root) {
	if (root == NULL)
		return -1;	//비어있는 경우 높이는 -1
	else {
		int leftH = GetHeight(root->left);	//왼쪽 노드의 높이
		int rightH = GetHeight(root->right); //오른쪽 노드의 높이
		int MaxH = leftH > rightH ? leftH : rightH;	// 둘 중 더 큰 값 선택
		return MaxH + 1;	//큰 값에 1을 더해 높이 반환
	}
}

//Balance Factor 계산
template <typename T>
int GetBalanceFactor(BinaryTreeNode<T>* item) {
	int LeftHeight = GetHeight(item->left);	// 왼쪽 노드의 높이
	int RightHeight = GetHeight(item->right);//오른쪽 노드의 높이

	return LeftHeight - RightHeight;	//왼쪽 노드의 높이에서 오른쪽 노드의 높이 차이를 Balance Factor로 반환
}


//BST 새로운 노드 추가
template <typename T>
bool Insert(BinaryTreeNode<T>*& root, T item) {
	//추가할 노드 생성
	bool temp;
	if (root == NULL) {//빈 루트이면
		BinaryTreeNode<T> *add_node;
		add_node = new BinaryTreeNode<T>;
		add_node->left = NULL;
		add_node->right = NULL;
		add_node->data = item;
		root = add_node;
		return true;
	}
	else if (root->data < item) {	//item이 data보다 큰 경우
		temp = Insert(root->right, item);	//root의 오른쪽으로 이동 후 다시 추가.
		SetBalance(root);	//Balance 맞추기
		return temp;
	}
	else if (root->data > item) {	//item이 data보다 작은 경우
		temp = Insert(root->left, item);	//root의 왼쪽으로 이동 후 다시 추가.
		SetBalance(root);	//Balance 맞추기
		return temp;
	}
	else {
		return false;	//그 이외의 경우 false 리턴.
	}
}

//밸런스 팩터를 이용해 트리의 밸런스 맞춤.
template <typename T>
void SetBalance(BinaryTreeNode<T>*& root) {
	int BF = GetBalanceFactor(root);

	if (BF > 1) { //root 기준 왼쪽 서브트리로 삽입된 경우
		if (GetBalanceFactor(root->left) > 0) {// 그 중 왼쪽 노드의 균형이 깨진 경우
			LLRotation(root);	//LL Rotation
		}
		else { // 그 중 오른쪽 노드의 균형이 깨진 경우
			LRRotation(root);	//LR Rotation
		}
	}
	else if (BF < -1) { //root 기준 오른쪽 서브트리로 삽입된 경우
		if (GetBalanceFactor(root->right) > 0) { // 그 중 왼쪽 노드의 균형이 깨진 경우
			RLRotation(root); //RL Rotation
		}
		else {//그 중 오른쪽 노드의 균형이 깨진 경우
			RRRotation(root); //RR Roataion
		}
	}
}

//Outside case로 한 번만 우회전하는 LL Rotaion
template<typename T>
void LLRotation(BinaryTreeNode<T>*& root) {
	BinaryTreeNode<T>* temp;
	temp = root->left;	//root의 왼쪽노드 가리킴
	root->left = temp->right;	//root의 왼쪽을 원래 root의 왼쪽노드의 오른쪽 가리키도록 함
	temp->right = root;	//원래 root의 왼쪽노드의 오른쪽을 root로 설정

	root = temp;	//root를 원래 root의 왼쪽노드로 설정
}

//Inside case로 총 두번, 좌회전과 우회전을 하는 LR Rotaion 
template<typename T>
void LRRotation(BinaryTreeNode<T>*& root) {
	RRRotation(root->left); //root의 왼쪽 노드를 기준으로 RR Rotation(좌회전) 시킴
	LLRotation(root); //root를 LL Rotation(우회전) 시킴
}

//Outside case로 한 번만 좌회전하는 RR Rotaion
template<typename T>
void RRRotation(BinaryTreeNode<T>*& root) {
	BinaryTreeNode<T>*temp;
	temp = root->right; //root의 오른쪽노드 가리킴
	root->right = temp->left;//root의 오른쪽을을 원래 root의 오른쪽노드의 왼쪽을 가리키도록 함
	temp->left = root; //원래 root의 오른쪽노드의 왼쪽을 root로 설정

	root = temp;	//root를 원래 root의 오른쪽노드로 설정
}

//Inside case로 총 두번, 우회전과 좌회전을 하는 RL Rotaion 
template<typename T>
void RLRotation(BinaryTreeNode<T>*& root) {
	LLRotation(root->right);//root의 오른쪽 노드를 기준으로 LL Rotation(우회전) 시킴
	RRRotation(root); //root를 RR Rotation(좌회전) 시킴
}

//root의 가장 오른쪽에 위치한 데이터 찾아 전달.
template <typename T>
void GetPredecessor(BinaryTreeNode<T>* root, T&item) {
	//중간 연결 root를 삭제하는 경우, 삭제 root의 왼편 subtree 중 가장 큰 값(가장 오른쪽에 위치한 값)을 찾아 item에 값을 전달하는 방식
	while (root->right != NULL) {	//맨 오른쪽 노드에 도달할 때까지 이동
		root = root->right;
	}
	item = root->data;	//찾은 값 전달.
}

//BST 노드 삭제
template<typename T>
void DeleteNode(BinaryTreeNode<T>*&root) {
	BinaryTreeNode<T>* del_node;	//삭제하고자 하는 노드 가리킬 포인터.
	del_node = new BinaryTreeNode<T>;	//동적할당
	del_node = root;	//root(삭제하려는 노드 가리킴)와 같은 노드 가리키도록 지정.
	if (root->left == NULL) {	//해당 노드의 왼편이 NULL인 경우
		root = root->right;	// root가 root의 오른쪽 subtree를 가리키도록 변경
		delete del_node;	//해당 노드 삭제
	}
	else if (root->right == NULL) {	//해당 노드의 오른편이 NULL인 경우(왼편의 노드는 반드시 NULL이 아닌 상황)
		root = root->left;	// root가 root의 왼쪽 subtree를 가리키도록 변경
		delete del_node;	//해당 노드 삭제
	}
	else { // 해당 노드의 왼쪽, 오른쪽 모두 NULL이 아닌 경우
		T temp;
		GetPredecessor(root->left, temp);	//root보다 작은 값들 중 가장 큰 값의 정보를 temp로 받아옴.
		root->data = temp;	// 원래 삭제하고자 했던 root의 데이터를 받아온 정보로 변경.
		DeleteItem(root->left, temp);	//temp 값을 가진 노드 삭제.
	}

}

//BST 내 특정 데이터 가진 노드 삭제
template<typename T>
bool DeleteItem(BinaryTreeNode<T>*&root, T item) {
	if (root->data < item) {	// item값이 data보다 큰 경우
		return DeleteItem(root->right, item);	//root의 오른쪽 subtree에서 해당 item 다시 찾음.
	}
	else if (root->data > item) {	//item값이 data보다 작은 경우
		return DeleteItem(root->left, item);	//root의 왼쪽 subtree에서 해당 item 다시 찾음.
	}
	else {	//찾은 경우
		DeleteNode(root);	//해당 root가 가리키는 노드 삭제
		return true;	//삭제 후 1 리턴.
	}
}

//BST내 특정 노드에 일부 내용 변경
template<typename T>
bool ReplaceItem(BinaryTreeNode<T>*&root, T item) {
	if (root->data < item) {	// item값이 data보다 큰 경우
		return ReplaceItem(root->right, item);	//root의 오른쪽 subtree에서 해당 item 다시 찾음.
	}
	else if (root->data > item) {	//item값이 data보다 작은 경우
		return ReplaceItem(root->left, item);	//root의 왼쪽 subtree에서 해당 item 다시 찾음.
	}
	else {	//찾은 경우
		root->data = item;	//해당 root가 가리키는 노드의 data를 item으로 변경.
		return true;	//변경 후 1 리턴.
	}
}

//BST내 특정 노드의 data의 포인터 반환.
template<typename T>
T* GetPointItem(BinaryTreeNode<T>*root, T item) {
	if (root == NULL) {	//root가 NULL인 경우
		return NULL;	//NULL 리턴.
	}
	else if (root->data < item) {		// item값이 data보다 큰 경우
		return GetPointItem(root->right, item);	//root의 오른쪽 subtree에서 해당 item 다시 찾음.
	}
	else if (root->data > item) {	//item값이 data보다 작은 경우
		return GetPointItem(root->left, item);	//root의 왼쪽 subtree에서 해당 item 다시 찾음.
	}
	else {	//찾은 경우
		return &(root->data);	//해당 root가 가리키는 노드의 data의 주소값 리턴.
	}
}

//BST 특정 노드의 data 검색
template <typename T>
void RetrieveItem(BinaryTreeNode<T>* root, T &item, bool &found) {
	if (root == NULL) {	//root가 NULL인 경우
		found = false;	//찾지 못했음으로 false값으로 변경.
	}
	else if (root->data < item) {		// item값이 data보다 큰 경우
		RetrieveItem(root->right, item, found);	//root의 오른쪽 subtree에서 해당 item 다시 찾음.
	}
	else if (root->data > item) {	//item값이 data보다 작은 경우
		RetrieveItem(root->left, item, found);	//root의 왼쪽 subtree에서 해당 item 다시 찾음.
	}
	else { //찾은 경우
		item = root->data;	//item에 해당 노드의 data 값 전달.
		found = true;	//찾았기 때문에 true값으로 변경.
	}
}

//BST 특정 노드의 data 검색
template <typename T>
void IsthereItem(BinaryTreeNode<T>* root, T item, bool &found) {
	if (root == NULL) {	//root가 NULL인 경우
		found = false;	//찾지 못했음으로 false값으로 변경.
	}
	else if (root->data < item) {		// item값이 data보다 큰 경우
		IsthereItem(root->right, item, found);	//root의 오른쪽 subtree에서 해당 item 다시 찾음.
	}
	else if (root->data > item) {	//item값이 data보다 작은 경우
		IsthereItem(root->left, item, found);	//root의 왼쪽 subtree에서 해당 item 다시 찾음.
	}
	else { //찾은 경우
		found = true;	//찾았기 때문에 true값으로 변경.
	}
}

//BST 출력(InOrder방식)
template<typename T>
void PrintInOrder(BinaryTreeNode<T>*root, ostream& out) {
	//InOrder 방식의 출력.
	if (root != NULL) {
		PrintInOrder(root->left, out);
		out << root->data;
		PrintInOrder(root->right, out);
	}
}
