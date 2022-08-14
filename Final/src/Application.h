#ifndef _APPLICATION_H
#define _APPLICATION_H

#include "Queue.h"
#include "InfMusic.h"
#include "DoublyLinkedList.h"


#include <Windows.h>
#include <mmsystem.h>
#include <conio.h>
#include <iostream>
#include <string>
#include <fstream>
#include <atlstr.h>

#pragma comment(lib, "winmm.lib")
using namespace std;


#define FILENAMESIZE 1024

/**
*	application class for item management simply.
*/
class Application
{
public:
	/**
	*	default constructor.
	*/
	Application();

	/**
	*	destructor.
	*/
	~Application();

	/**
	*	@brief	Program driver.
	*	@pre	program is started.
	*	@post	program is finished.
	*/
	void Run();

	/**
	*	@brief	genre�� �ش� genre number�� ã�� �����Ѵ�.
	*	@pre	genre is set.
	*	@post	genre�� ��ġ�ϴ� �ش� genre number�� ã�� �����Ѵ�.
	*	@param	genre	genre number�� ã������ genre��
	*	@return	�ش� �帣�� �´� genre number�� �����ϰ�, ��ġ�ϴ� �帣���� ���� ��, 11�� ����(��Ÿ�帣)�Ѵ�.
	*/
	int SetGenreId(const string& genre);

	/**
	*	@brief	item�� id ����
	*	@pre	id���� ������ ������ item�� ������ ä���� �־�� ��.
	*	@post	item�� id���� ä����
	*	@param	item	id�� �����ϰ��� �ϴ� ������.
	*/
	void SetMusicId(MusicType& item);

	/**
	*	@brief	inCommand�� int����, int�̸� �ش� ��ɹ�ȣ�� �����ϴ��� �Ǻ��Ͽ� ����ڷκ��� �ùٸ� ���� �Է¹���.
	*	@pre	none.
	*	@post	inCommand�� �ùٸ� �Է°��� ���޵�.
	*	@param	inCommand	����ڷκ��� �Է¹޾� ���޵Ǵ� ��.
	*	@param	a			�ּҸ�ɹ�ȣ.
	*	@param	b			�ִ��ɹ�ȣ.
	*/
	void CheckNum(int& inCommand, const int&a, const int&b);

	/**
	*	@brief	Display command on screen and get a input from keyboard.
	*	@pre	none.
	*	@post	none.
	*	@return	user's command.
	*/
	int MainGetCommand();

	/**
	*	@brief	��ü, �帣, ��Ƽ��Ʈ, �ٹ� �� ī�װ��� ������ ������ �˻�.
	*	@pre	none.
	*	@post	none.
	*/
	void SearchMusic();

	/**
	*	@brief	���� ����(�߰�, ����, ����, �����б�, ��������)�� ���� �Լ�.
	*	@pre	none.
	*	@post	none.
	*/
	void ManageMusic();

	/**
	*	@brief	��� ��� ����(�ֱ��߰�, �ֱ����, �ִ����, ����� ���)�� ���� �Լ�.
	*	@pre	none.
	*	@post	none.
	*/
	void ManagePlayList();
	
	/**
	*	@brief	�����Ͽ� ���� ������ ���� ��ɾ ����.
	*	@pre	none.
	*	@post	none.
	*	@param	content		������ ��ü.
	*	@return	������ ��ɿ� ���� command���� ��ȯ.
	*/
	int DetailPlayListGetCommand(const string&content);


	/**
	*	@brief	���� ī�װ��� ���� �˻��� ���� ��ɾ ����.
	*	@pre	none.
	*	@post	none.
	*	@param	content		�˻��� ī�װ�.
	*	@return	������ ��ɿ� ���� command���� ��ȯ.
	*/
	int DetailSerachGetCommand(const string&content);

	/**
	*	@brief	�ش� content �������� ���� ����Ʈ ���� Ȥ�� ���� ��� ��ɾ� ����.
	*	@pre	none.
	*	@post	none.
	*	@param	content		�˻��� ī�װ�.
	*	@return	������ ��ɿ� ���� command���� ��ȯ.
	*/
	int DetailManageSerachGetCommand(const string&content);

	/**
	*	@brief	������ �߰� �Ǵ� ��������� ���� ��ɾ ����.
	*	@pre	none.
	*	@post	none.
	*	@return	������ ��ɿ� ���� command���� ��ȯ.
	*/
	int DetailSearchMusicListGetCommand();

	/**
	*	@brief	DetailSearchMusicListGetCommand�κ��� ��ɰ��� �޾ƿ� �ش� ��ɰ��� ���� ���� ����.
	*	@pre	none.
	*	@post	none.
	*	@param	m_list	�˻�, Ȥ�� ����� ������ ��ü�� �Ǵ� ����Ʈ.
	*/
	void DetailManageSearchMusicList(BinarySearchTree<SimpleMusicType>& m_list);

	/**
	*	@brief	���� ���ǰ˻�(��ü, �帣, ��Ƽ��Ʈ, �ٹ�)�� ���� ���� ��ɾ� �Է¹޾� ��ȯ.
	*	@pre	none.
	*	@post	none.
	*	@return	������ ��ɿ� ���� command���� ��ȯ.
	*/
	int SearchGetCommand();

	/**
	*	@brief	m_list�� ���� command�� ���� ��������� �ش� ����Ʈ�� ���� ������ ���.(Inorder����)
	*	@pre	none.
	*	@post	ȭ�鿡 ���ϴ� ������ ��µ�.
	*	@param	m_list	�˻��ϰ��� �ϴ� ����Ʈ
	*	@param	b_iter	InfMusic�� name������ �������� ���� Iterator.
	*	@param	command	1�̸� m_list�� ���� ������ ã�� ���, 2�̸� m_list�� ������ ���� ������ ���, ������ ���ڴ� InfMusic�� name���� ���
	*/
	void DisplayAllnestedBST(BinarySearchTree<InfMusic>& m_list, Iterator<InfMusic> b_iter, const int& command);

	/**
	*	@brief	m_list�� ���� command�� ���� ��������� �ش� ����Ʈ�� ���� ������ ���.(��������)
	*	@pre	none.
	*	@post	ȭ�鿡 ���ϴ� ������ ��µ�.
	*	@param	m_list	�˻��ϰ��� �ϴ� ����Ʈ
	*	@param	b_iter	InfMusic�� name������ �������� ���� Iterator.
	*	@param	command	1�̸� m_list�� ���� ������ ã�� ���, 2�̸� m_list�� ������ ���� ������ ���, ������ ���ڴ� InfMusic�� name���� ���
	*/
	void DisplayAllnestedOrderBST(BinarySearchTree<InfMusic>& m_list, Iterator<InfMusic> b_iter, const int& command);

	/**
	*	@brief	list(BST-InfMusic)�� �׸��� ���� �����Ͽ� �߰���Ű�� ���� �����ϴ� �Լ�.
	*	@pre	none.
	*	@post	���� ������ �� ������ �߰���.
	*	@param	str		����Ʈ�� ī�װ�
	*	@param	list	�˻��ϰ��� �ϴ� ����Ʈ.
	*	@param	input	�߰��Ϸ��� InfMusic�� name���� Need�� ���� ����ڷκ��� �ش� �Լ������� �Է¹ްų�, �Ķ���ͷ� ���޹��� �� �ٷ� ��� ����.
	*	@param	Need	true�̸� ����ڿ��� ���� input���� �ش� �Լ� ������ �Է¹ް�, Need�� �ƴϸ� �ٷ� input�� �Լ��� ���.
	*/
	void AddMyMusicbyBSTInf(const string& str, BinarySearchTree<InfMusic>& list, string& input, const bool& Need);

	/**
	*	@brief	list(BST-InfMusic)�� �׸���  ���� �����Ͽ� �߰���Ű�� ���� �����ϴ� �Լ�.
	*	@pre	none.
	*	@post	���� ������ �� ������ �߰���.
	*	@param	str		����Ʈ�� ī�װ�
	*	@param	list	�˻��ϰ��� �ϴ� ����Ʈ.
	*	@param	input	�߰��Ϸ��� InfMusic�� name���� Need�� ���� ����ڷκ��� �ش� �Լ������� �Է¹ްų�, �Ķ���ͷ� ���޹��� �� �ٷ� ��� ����.
	*	@param	Need	true�̸� ����ڿ��� ���� input���� �ش� �Լ� ������ �Է¹ް�, Need�� �ƴϸ� �ٷ� input�� �Լ��� ���.
	*/
	void AddNowPlayListbyBSTInf(const string& str, BinarySearchTree<InfMusic>& list, string& input, const bool& Need);


	/**
	*	@brief	m_list(BST-SimpleMT)�� �̿��� iterator�� ������ DisplayAllInfobySimple �Լ��� �����ϱ� ���� �Լ�.
	*	@pre	none.
	*	@post	none.
	*	@param	m_list	Iterator�� �˻��ϱ� ���� ����Ʈ.
	*/
	void DisplayAllInfobySimpleFirst(BinarySearchTree<SimpleMusicType>& m_list);

	/**
	*	@brief	iter�� �̿��� InOreder����� �̿��� ��������� �ռ� m_list���� �׸��� ���� ������ �˻��� ȭ�鿡 ���.
	*	@pre	none.
	*	@post	���� ���� ��� ȭ�鿡 ��µ�.
	*	@param	iter	�˻� �� ����ϰ��� �ϴ� �Լ��� ����Ű�� iterator.
	*/
	void DisplayAllInfobySimple(Iterator<SimpleMusicType> iter);

	/**
	*	@brief	�ѱ�, ����, ���� �� ��Ÿ�� ���е� 0~12�� �ε����� inTitle�� ù��° ������ ���� �ش��ϴ� �ε��� �� ��ȯ.
	*	@pre	none.
	*	@post	none.
	*	@param	inTitle		MusicList������ �� ��° �ε����� �������� �˾ƺ��� ���� ����.
	*	@return	�ش� inTitle�� �´� MusicList �� �ε��� ��ȯ.
	*/
	int GetMusicListIdx(string& inTitle);

	/**
	*	@brief	���ƿ� ��� ��, ���ƿ並 �����Ϸ��� ����� ID���� �Է¹޾� �ش� ����� ���ƿ� ���� �� �ش� ����Ʈ���� ������.
	*	@pre	none.
	*	@post	���õ� ����� ���ƿ� ���� ����Ǹ�, ���ƿ� ��Ͽ��� ������.
	*/
	void SelectMusicUnHeart();


	/**
	*	@brief	���� ���ǰ���(�����߰�, �ڵ��߰�, ����, ����, ���������)�� ���� ��ɾ �����, ����ڷκ��� �Է¹޾� ��ȯ�ϴ� �Լ�.
	*	@pre	none.
	*	@post	none.
	*	@return	����ڷκ��� �Է¹��� ��ɾ� ��ȯ.
	*/
	int ManageGetCommand();

	/**
	*	@brief	���� ������ ����(���� ���, �ֱ��߰�,�ֱ����, �ִ����, ���ƿ�)�� ���� ��ɾ �����, ����ڷκ��� �Է¹޾� ��ȯ�ϴ� �Լ�.
	*	@pre	none.
	*	@post	none.
	*	@return	����ڷκ��� �Է¹��� ��ɾ� ��ȯ.
	*/
	int PlaylistGetCommnad();


	/**
	*	@brief	���� ����� �ʿ��� ��ɾ� ��� �� �ش� ���� ��� ��, ��ɰ��� ����ڷκ��� �Է¹޾� ��ȯ�ϴ� �Լ�.
	*	@pre	none.
	*	@post	none.
	*	@param	inHeart		�ش� ������ ���ƿ� ���� ����
	*	@param	filename	�ش� ������ �����̸�
	*	@return	����ڷκ��� �Է¹��� ��ɾ� ��ȯ.
	*/
	int PlayGetCommand(const bool& inHeart, const char *filename);

	/**
	*	@brief	������� ���� �÷��̾� ��������� �м��� ȭ�鿡 ���.
	*	@pre	none.
	*	@post	��������� ȭ�鿡 ��µ�.
	*/
	void MyMusic();

	/**
	*	@brief	BST-SimpleMT ���� ����Ʈ ��� �� ���� ���� ��Ҹ� ����.
	*	@pre	none.
	*	@post	none.
	*	@param	iter		�ش� ����Ʈ�� ����Ű�� iterator
	*	@param	i_temp		���� ���� ����� ����
	*	@param	temp		���� ���� ����� �̸�
	*/
	void Favorite(Iterator<InfMusic> iter, int& i_temp, string& temp);

	/**
	*	@brief	artist�� ����ٷ� ������ arr �迭�� ����
	*	@pre	none.
	*	@post	arr�迭 �� ��Ұ� �߰���
	*	@param	arr		���е� ��Ƽ��Ʈ�� �����ϱ� ���� �迭.
	*	@param	artist	����ٷ� �����ϱ� ���� ��Ƽ��Ʈ ����.
	*/
	void SplitArtist(string arr[], string& artist);


	/**
	*	@brief	���� ������ ����ǰ� ������ ���� ȭ�鿡�� ���� ���� ����ϴ� �Լ�.
	*	@pre	������ ����ǰ� �־����.
	*	@post	none.
	*	@param	IsPlaying	������ ���� ����ǰ� �ִ��� �����ϴ� ����.	
	*/
	void PlayingMusic(bool& IsPlaying);

	/**
	*	@brief	PlayGetCommand�κ��� ���� �޾� ����������� �ش� ����� �����ϴ� �Լ�.
	*	@pre	���� ������ ����.
	*	@post	none.
	*	@param	command		�ش� ��ɾ�� iterator�� �ٽ� �ʱ�ȭ ���� �ʵ��� ����//���� ���� �ʿ�
	*/
	void ManagePlayingMusic(const int& command);

	/**
	*	@brief	DetailPlayListGetCommand�κ��� ���� �޾� Queue�� �̿��� �ش� ����� �����ϴ� �Լ�.
	*	@pre	none.
	*	@post	none.
	*	@param	Queue	�ش� ����Ʈ �� ��Ҹ� �̿�.
	*	@param	str		ī�װ��� ��Ÿ���� ����.
	*/
	void ManageQueueList(Queue<SimpleMusicType>& Queue, string& str);

	/**
	*	@brief	�ִ������Ͽ� ���� ��ɾ ����ϰ� �Է¹��� ��, �ش� ����� �����ϴ� �Լ��� �ִ��������� ������.
	*	@pre	none.
	*	@post	none.
	*/
	void ManageMostPlayList();

	/**
	*	@brief	���������Ͽ� ���� ��ɾ ����ϰ� �Է¹��� ��, �ش� ����� �����ϴ� �Լ��� ������������ ������.
	*	@pre	none.
	*	@post	none.
	*/
	void ManageNowPlayList();

	
	/**
	*	@brief	SelectMyMuiscList�κ��� ������ �Է¹��� ��, 0�� �ƴ� ���� SelectMyPlayList�� �����ϴ� �Լ�.
	*	@pre	none.
	*	@post	none.
	*/
	void ManageMyPlayList();

	/**
	*	@brief	command�� �̿��� �ش� ������ �� �����Ͽ� �����Ͽ� �ش� �����Ͽ� ���� ������ ����.
	*	@pre	none.
	*	@post	none.
	*	@param	command	���� ������ �� �����ϰ��� �ϴ� ������ ������.
	*/
	void SelectMyPlayList(int& command);

	/**
	*	@brief	command���� �ش��ϴ� ���� �����Ͽ� ���� Iterator�� ������ AddAllNowPlayList�Լ��� ȣ��.
	*	@pre	none.
	*	@post	none.
	*	@param	command	���� ������ �� �����ϰ��� �ϴ� ������ ������.
	*/
	void AddNowPlayListManage(int& command);

	/**
	*	@brief	���� ������ ����Ʈ�� �̸��� ����ڿ��� ����Ͽ� ������ ��, �� �� �����ϰ��� �ϴ� ����Ʈ�� ��ȣ�� �Է¹���.
	*	@pre	none.
	*	@post	none.
	*	@return ���� ������ �� �����ϰ��� �ϴ� �������� ��ȣ ��ȯ.
	*/
	int SelectMyMuiscList();


	/**
	*	@brief	MusicList���� QueueList�� ��ҿ� ���� �ڼ��� ������ �˻��� ��� ������ ȭ�鿡 ������ִ� �Լ�..
	*	@pre	none.
	*	@post	none.
	*	@param	Queue	�ڼ��� ������ ����ϰ� �ϴ� QueueList.
	*/
	void DisplayQueue(Queue<SimpleMusicType>& Queue);

	/**
	*	@brief	���� ����ǰ� �ִ� �� ���ǿ� ���� ������ ���.
	*	@pre	none.
	*	@post	none.
	*	@param	item	���� ����ǰ� �ִ� ����.
	*/
	void DisplayPlayingMusic(MusicType& item);

	/**
	*	@brief	temp�� ���̵� �̿��� MusicList�� �ش� �ε����� ���� ��, �ش� BST���� m_temp�� ���� �ڼ��� ������ ������.
	*	@pre	none.
	*	@post	m_temp�� ���� �ڼ��� ���� �߰���.
	*	@param	temp	ID�� ���� ����.
	*	@param	m_temp	temp�� ID�� �̿��� MusicList���� �ش� ID�� �ڼ��� ������ ���� ����.
	*	@param	found	m_temp�� ã���� ��� true, �ƴϸ� false���� ����.
	*/
	void PlayingMusicGetMT(SimpleMusicType& temp, MusicType& m_temp, bool& found);

	/**
	*	@brief	iter�� ����Ű�� ����Ʈ �� ��� ����� count���� +1�� ��, �ش� ��� ��Ҹ� PreOrder�� ������� t_NowPlayList�� ����.
	*	@pre	none.
	*	@post	iter�� ����Ű�� ����� count�� ���� �� t_NowPlayList�� ��� �߰���.
	*	@param	iter	����ϸ鼭 �ӽ� �����Ͽ� ��� ���� ����Ʈ�� ����Ű�� iterator.
	*	@param	IsPlay	UpdateInfor�Լ��� ���� �Ķ����.
	*/
	void AddTempNPL(Iterator<SimpleMusicType> iter, const bool& IsPlay);

	/**
	*	@brief	���ƿ� �� ��Ͽ� ���� ��ɾ ����ϰ� �Է¹��� ��, �ش� ����� �����ϴ� �Լ��� ���ƿ� �� ����� ������.
	*	@pre	none.
	*	@post	none.
	*/
	void ManageHeartList();

	/**
	*	@brief	���� ������ �� command������ �ش��ϴ� ������ �� ��� ��Ҹ� ���� �����Ͽ� �߰�(�ߺ��˻� ��)
	*	@pre	none.
	*	@post	���� �����Ͽ� ��� �߰���.
	*	@param	command		���� ������ �� �� ����Ʈ�� ����.
	*/
	void AddNowPlayList(int& command);

	/**
	*	@brief	Queue-SimpleMusicType�� ���� Queue�� ��� ��Ҹ� command���� ���� �ٸ� Ư�� ��Ͽ� �߰���.
	*	@pre	none.
	*	@post	Ư�� ����Ʈ �� ��� �߰�.
	*	@param	Queue		�ش� ����Ʈ �� ��Ұ� �ٸ� ����Ʈ�� �߰���.
	*	@param	command		1�̸� ���������Ͽ�, ������ ���ڴ� ���� ������ �� �߰��ϰ��� �ϴ� ������ �޾ƿ� �ش� ����Ʈ�� ����.
	*/
	void AddNowPlayListbyQue(Queue<SimpleMusicType>& Queue, const int& command);

	/**
	*	@brief	���ƿ� �� ����� ��� ��Ҹ� ���� �����Ͽ� ������.
	*	@pre	none.
	*	@post	���� �����Ͽ� ��� �߰���.
	*/
	void AddNowPlayListbyHeart();

	/**
	*	@brief	BST-SimpleMusicType�� list�� ��� ��Ҹ� �� ������ �� Ư�� ����Ʈ�� �߰�.
	*	@pre	none.
	*	@post	none.
	*	@param	list	Ư�� ����Ʈ�� �߰��ϰ��� �ϴ� ��Ҹ� ���� ����Ʈ.
	*/
	void AddMyPlayListbyBSTSim(BinarySearchTree<SimpleMusicType>& list);

	/**
	*	@brief	BST-SimpleMusicType�� list�� ��� ��Ҹ� �� ������ �� Ư�� ����Ʈ�� �߰�.
	*	@pre	none.
	*	@post	none.
	*	@param	iter	����Ʈ�� ��ҿ� �����ϴ� iterator.
	*	@param	list	Ư�� ����Ʈ�� �߰��ϰ��� �ϴ� ��Ҹ� ���� ����Ʈ.
	*	@param	com		Ư�� ����Ʈ�� ����.
	*/
	void AddMyPlayListbyBST(Iterator<SimpleMusicType> iter, InfMusic*& list, int com);


	/**
	*	@brief	���� ������ �� Ư�� ����� ����Ű�� iter�� �̿��� ���� �����Ͽ� �߰�.
	*	@pre	���� ������ ����.
	*	@post	���� �����Ͽ� �߰�
	*	@param	iter	����Ʈ�� ��ҿ� �����ϴ� iterator.
	*/
	void AddAllNowPlayList(Iterator<SimpleMusicType> iter);


	/**
	*	@brief	s_temp�� id�� ������  MusicType�� ����� �ڼ��� ������ ������ ��, ���� command�� �°� ����Ʈ �߰�,���� �� ���� ������ ��
	*	@pre	none.
	*	@post	����Ʈ Ȥ�� ���� ��� �Ϻ� ���� ����.
	*	@param	s_item		Id�� ���� ����.
	*	@param	command		0~4�� ���� ������ �ش� �ε��� �� �߰� Ȥ�� ����, 5�̸� ���ƿ� ���� ���� �߰�, ����, �� ���� ���ڴ� ���Ƚ�� ���� �� ���� ����Ʈ �� �߰�
	*	@param	IsUnset		true�� ����, false�� �߰�. ���Ƚ�� ������ �ش� ������ ������ ���� ����.
	*/
	void UpdateInfor(SimpleMusicType& s_item, const int& command, const int& IsUnset);

	/**
	*	@brief	����ڷκ��� ���� ���̵� �Է¹޾� m_List �� �ش� ���̵� ���� ��Ҹ� ����.
	*	@pre	m_List����
	*	@post	m_List������ Ư�� ��� ����
	*	@param	m_List		�ش� ����Ʈ���� �Է¹��� ���̵� ���� ��� ����.
	*/
	void SelectMusicListSimpleDelete(BinarySearchTree<SimpleMusicType>& m_List);

	/**
	*	@brief	����ڷκ��� �߰��ϰ��� �ϴ� ������ �Է¹޾� AddMusic�Լ��� true���� �Բ� ������ ����Ʈ�� ���ο� ���ڵ� �߰�.
	*	@pre	����Ʈ ����.
	*	@post	���ο� ���ڵ尡 ����Ʈ�� �߰���.
	*	@return	�� �߰��Ǹ� 1��, �ƴϸ� 0�� ������.
	*/
	int AddMusicFromUser();

	/**
	*	@brief	����Ʈ�� ���ο� ���ڵ� �߰�.
	*	@pre	����Ʈ ����.
	*	@post	IsUser�� true�� �ߺ� �˻縦 �ϸ�, ���ο� ���ڵ尡 ����Ʈ�� �߰���.
	*	@param	userAdd	�߰��Ϸ��� ������
	*	@param	IsUser	User�Է����� �����͸� �����Ѱ��� �ƴ��� ����Ű�� ��.
	*	@return	�� �߰��Ǹ� 1��, �ƴϸ� 0�� ������.
	*/
	int AddMusic(MusicType userAdd, const bool &IsUser);


	/**
	*	@brief	����Ʈ���� ���� ���ڵ� ����.
	*	@pre	����Ʈ ����.
	*	@post	����Ʈ�� �����ϴ� ���� ���ڵ尡 ����Ʈ���� ������.
	*	@param	userDel	�����Ϸ��� ������
	*	@param	IsUser	User�Է����� �����͸� �����Ѱ��� �ƴ��� ����Ű�� ��.
	*	@return	�� �����Ǹ� 1��, �ƴϸ� 0�� ������.
	*/
	int DeleteMusic(MusicType userDel, const bool &IsUser);


	/**
	*	@brief	����ڿ��� ������ ������ �Է¹޾� DeleteMusic�Լ��� �Ѱ��ִ� ������ �Ѵ�.
	*	@pre	����Ʈ �� ���� ���� ����.
	*	@post	����ڰ� �Է��� num�� ������ �ִ� ������ ��� ����Ʈ���� �����.
	*	@return	�� ���ŵǸ� 1��, �ƴϸ� 0�� ������.
	*/
	void DeleteMusicFromUser();

	/**
	*	@brief	����ڿ��� num�� �Է¹޾� Replace�Լ��� �Ѱ��ִ� ������ �Ѵ�.
	*	@pre	����Ʈ �� ���� ���� ����.
	*	@post	����ڰ� �Է��� num�� ������ �ִ� ������ ��� ����Ʈ���� ������.
	*	@return	�� ����Ǹ� 1��, �ƴϸ� 0�� ������.
	*/
	int ReplaceMusic();


	/**
	*	@brief	��ü�� ���� ��, ã���� �ϴ� Title�� �Է¹޴´�.
	*	@pre	����.
	*	@post	find �Լ��� �̿��� �Է¹��� Title�� ��ġ�ϴ� ���� ������ �����ϴ��� ã�� ����Ѵ�.(��, �˻�� ��� ���Եȴٸ� ����Ѵ�.)
	*	@return ��ġ�ϴ� �׸��� ã�� ��� 1�� �����ϰ�, �׷��� ������ 0�� �����Ѵ�.
	*/
	int SearchByName(MusicType & item);

	/**
	*	@brief	��ü�� ���� ��, ã���� �ϴ� Artist�� �Է¹޴´�.
	*	@pre	����.
	*	@post	find �Լ��� �̿��� �Է¹��� Artist�� ��ġ�ϴ� ���� ������ �����ϴ��� ã�� ����Ѵ�.(��, �˻�� ������ ���Եȴٸ� ����Ѵ�.)
	*	@return ��ġ�ϴ� �׸��� ã�� ��� 1�� �����ϰ�, �׷��� ������ 0�� �����Ѵ�.
	*/
	int SearchByArtist();



	/**
	*	@brief	str�� inString ī�װ����� list�� �̿��� ����� ó����.
	*	@pre	����.
	*	@post	����.
	*	@param	list		�ش� list�� Ư�� �Լ��� ���� ���޹��� ��ɰ��� ����ǵ��� ��.
	*	@param	str			ū ī�װ�
	*	@param	inString	���� ī�װ�
	*	@return ��ġ�ϴ� �׸��� ã�� ��� 1�� �����ϰ�, �׷��� ������ 0�� �����Ѵ�.
	*/
	int SearchByBSTInfDetail(BinarySearchTree<InfMusic>& list, const string& str, string& inString);

	/**
	*	@brief	��Ƽ��Ʈ �� �����ϴ� ����� ���� ���.
	*	@pre	����.
	*	@post	����.
	*   @param  inArtist	��Ƽ��Ʈ ����.
	*	@return ������� ������ ��ȯ.
	*/
	int CountUnderVarArtist(string& inArtist);

	/**
	*	@brief	��ü�� ���� ��, ã���� �ϴ� Album�� �Է¹޴´�.
	*	@pre	����.
	*	@post	����.
	*/
	int SearchByAlbum();

	/**
	*	@brief	��ü�� ���� ��, ã���� �ϴ� Genre�� �Է¹޴´�.
	*	@pre	����.
	*	@post	����.
	*/
	int SearchByGenre();

	/**
	*	@brief	Display all records in the musiclist on screen.
	*	@pre	none.
	*	@post	none.
	*/
	void DisplayAllMusic();

	/**
	*	@brief	Open a file by file descriptor as an input file.
	*	@pre	a file for reading is exist.
	*	@post	open the file for reading.
	*	@param	fileName	a filename to open for reading.
	*	@return	return 1 if this function works well, otherwise 0.
	*/
	int OpenInFile(char *fileName);

	/**
	*	@brief	Open a file by file descriptor as an output file.
	*	@pre	list should be initialized.
	*	@post	open the file for writing.
	*	@param	fileName	a filename to open for writing.
	*	@return	return 1 if this function works well, otherwise 0.
	*/
	int OpenOutFile(char *fileName);

	/**
	*	@brief	�̸� �Էµ� ���ϸ��� �̿��� ������ ����.
	*	@pre	none.
	*	@post	none.
	*/
	void AutoReadFile();

	/**
	*	@brief	 ���ϸ��� ����ڷκ��� �Է¹޾� �ҷ���.
	*	@pre	none.
	*	@post	none.
	*/
	void ReadFile();

	/**
	*	@brief	Open a file as a read mode, read all data on the file, and set list by the data.
	*	@pre	The file is not opened.
	*	@post	list holds all records from the file.
	*	@param	filename	�а��� �ϴ� ���ϸ�.
	*	@return	return 1 if this function works well, otherwise 0.
	*/
	int ReadDataFromFile(char *filename);

	/**
	*	@brief	Open a file as a write mode, and write all data into the file,
	*	@pre	The file is not opened.
	*	@post	the list is stored in the output file.
	*	@return	return 1 if this function works well, otherwise 0.
	*/
	int WriteDataToFile();


	/**
	*	@brief	PreOrder ������� BST�� ��� ������ ���Ͽ� �ۼ�.
	*	@pre	����Ʈ �����ϸ�, �ۼ��ϰ��� �ϴ� Ư�� ���� �����־�� ��.
	*	@post	���Ͽ� ����Ʈ �� �������� ���� �ۼ�
	*	@param	iter	Tree ���θ� Ž���� iterator.
	*	@param	count	��� data�� �ۼ��ߴ����� ���� ����.
	*/
	void WritePreOrder(Iterator<MusicType> iter, int& count);


	/**
	*	@brief	iterator�� �̿��� tree �� Ư�� data�� ���� ����� ���� ���.
	*	@pre	����Ʈ ����.
	*	@post	����.
	*	@param	iter	Tree ���θ� Ž���� iterator.
	*	@param	temp	ã�ƾ� �ϴ� ������ ���� MusicType
	*	@param	found	data ã�Ҵ��� �Ǻ� ����
	*	@param	m_list	ã�� ������ ������ SimpleMusicType���� �ٲپ� �ӽ� �����Ͽ� ����
	*/
	void SearchTree(Iterator<MusicType> iter, MusicType& temp, bool& found, BinarySearchTree<SimpleMusicType>& m_list);


	
private:
	ifstream m_InFile;										///< input file descriptor.
	ofstream m_OutFile;										///< output file descriptor.


	SortedList<BinarySearchTree<MusicType>> MusicList;		///< ��� ���� ���� ���� ����Ʈ.
	SortedList<InfMusic> GenreList;							///< �帣���� ������ ����Ʈ

	BinarySearchTree<InfMusic> ArtistList;					///< ��Ƽ��Ʈ���� ������ ����Ʈ
	BinarySearchTree<InfMusic> AlbumList;					///< �ٹ����� ������ ����Ʈ


	Queue<SimpleMusicType> AddRecentlyList;					///<�ֱ��߰����
	Queue<SimpleMusicType> PlayRecentlyList;				///<�ֱ�������

	BinarySearchTree<InfMusic> MostPlayList;				///<�ִ�������

	SortedList<InfMusic> PlayList;							///<������
	BinarySearchTree<SimpleMusicType> HeartList;			///<���ƿ� �� ����Ʈ

	BinarySearchTree<SimpleMusicType> NowPlayList;			///<����������
	DoublyLinkedList<SimpleMusicType> t_NowPlayList;		///<���������� �����

	DoublyIterator<SimpleMusicType> *np_iter;

	MusicType MusicItem;									///< ����� ���� ����


	bool IsPlaying;				///< ��� ������ true�Ǿ ȭ�鿡 � ���� ��е��� �󸶳� �÷��̵ǰ� �մ��� ǥ�õ�, PlayingMusic�� �Ķ����
	bool b;						///< ���� ����� ���� ����
	int count;					///< ��ü ���� ����
	int m_Command;				///< current command number.

};


#endif // !_APPLICATION_H

