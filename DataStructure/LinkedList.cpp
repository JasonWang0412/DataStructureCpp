#include "LinkedList.h";
#include <iostream>

using namespace std;

namespace DataStructure
{
	LinkedList::LinkedList()
	{
		m_pHeadNode = new ListNode();
		m_pHeadNode->NodeData = 0;
		m_pHeadNode->pNextNode = nullptr;
		m_nLength = 0;
	}

	void LinkedList::Display()
	{
		ListNode *pCurrentNode = m_pHeadNode->pNextNode;
		for( int i = 0; i < m_nLength; i++ ) {
			cout << pCurrentNode->NodeData;
			if( i == m_nLength - 1 ) {
				cout << "\n";
			}
			else {
				cout << ", ";
			}
			pCurrentNode = pCurrentNode->pNextNode;
		}
	}

	bool LinkedList::Insert( int nIndex, DataType data )
	{
		// index protection
		if( nIndex < 0 || nIndex > m_nLength ) {
			return false;
		}

		// create data node
		ListNode *pNewNode = new ListNode();
		pNewNode->NodeData = data;

		// insert data
		ListNode *pPreNode = FindListNode( nIndex - 1 );
		pNewNode->pNextNode = pPreNode->pNextNode;
		pPreNode->pNextNode = pNewNode;

		// expand length
		m_nLength++;
		return true;
	}

	bool LinkedList::Insert( DataType data )
	{
		return Insert( m_nLength, data );
	}

	bool LinkedList::Remove( int nIndex )
	{
		// index protection
		if( nIndex < 0 || nIndex >= m_nLength ) {
			return false;
		}

		// cut the node
		ListNode *pPreNode = FindListNode( nIndex - 1 );
		ListNode *pRemoveNode = pPreNode->pNextNode;
		pPreNode->pNextNode = pRemoveNode->pNextNode;

		// delete node data
		delete pRemoveNode;

		// shorter length
		m_nLength--;

		return true;
	}

	bool LinkedList::Remove()
	{
		return Remove( m_nLength - 1 );
	}

	bool LinkedList::GetElement( int nIndex, DataType &data )
	{
		// index protection
		if( nIndex < 0 || nIndex >= m_nLength ) {
			return false;
		}

		data = FindListNode( nIndex )->NodeData;
		return true;
	}

	bool LinkedList::FindElement( DataType target, int &nResultIndex )
	{
		ListNode *pCurrentNode = m_pHeadNode;
		for( int i = 0; i < m_nLength; i++ ) {
			pCurrentNode = pCurrentNode->pNextNode;
			if( pCurrentNode->NodeData == target ) {
				nResultIndex = i;
				return true;
			}
		}
		return false;
	}

	void LinkedList::Clear()
	{
		ListNode *pCurrentNode = m_pHeadNode->pNextNode;
		while( pCurrentNode ) {
			ListNode *pTemp = pCurrentNode;
			pCurrentNode = pCurrentNode->pNextNode;
			delete pTemp;
		}
		m_nLength = 0;
	}

	int LinkedList::GetLength()
	{
		return m_nLength;
	}

	ListNode *LinkedList::FindListNode( int nIndex )
	{
		// index protection, -1 is HeadNode
		if( nIndex < -1 || nIndex >= m_nLength ) {
			return nullptr;
		}

		ListNode *pCurrentNode = m_pHeadNode;
		for( int i = -1; i < nIndex; i++ ) {
			pCurrentNode = pCurrentNode->pNextNode;
		}
		return pCurrentNode;
	}
}
