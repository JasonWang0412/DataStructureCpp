#include <iostream>
#include "TypeDefine.h"

#include "LinkedList.h";

namespace DataStructure
{
	LinkedList::LinkedList()
		: m_pHeadNode( new ListNode() ), m_nLength( 0 )
	{
		if( !m_pHeadNode ) {
			// Handle memory allocation failure
			std::cerr << "Memory allocation failure for head node in LinkedList constructor.\n";
			// You might want to throw an exception, log an error, or take appropriate action.
			// For simplicity, in this example, we terminate the program.
			exit( EXIT_FAILURE );
		}

		m_pHeadNode->NodeData = 0;
		m_pHeadNode->pNextNode = nullptr;
	}

	LinkedList::~LinkedList()
	{
		Clear(); // Release all allocated memory
		delete m_pHeadNode; // Release the head node
	}

	void LinkedList::Display()
	{
		if( m_nLength == 0 ) {
			std::cout << "The list is empty.\n";
			return;
		}

		ListNode *pCurrentNode = m_pHeadNode->pNextNode;
		for( int i = 0; i < m_nLength && pCurrentNode; i++ ) {
			std::cout << pCurrentNode->NodeData;
			if( i == m_nLength - 1 ) {
				std::cout << "\n";
			}
			else {
				std::cout << ", ";
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
		if( !pNewNode ) {
			// Handle memory allocation failure
			return false;
		}
		pNewNode->NodeData = data;

		// insert data
		ListNode *pPreNode = FindListNode( nIndex - 1 );
		if( !pPreNode ) {
			// Handle memory error
			return false;
		}
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
		if( !pPreNode ) {
			// Handle memory error
			return false;
		}
		ListNode *pRemoveNode = pPreNode->pNextNode;
		if( !pRemoveNode ) {
			// Handle memory error
			return false;
		}
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

		ListNode *pNode = FindListNode( nIndex );
		if( !pNode ) {
			// Handle memory error
			return false;
		}
		data = pNode->NodeData;
		return true;
	}

	bool LinkedList::FindElement( DataType target, int &nResultIndex )
	{
		ListNode *pCurrentNode = m_pHeadNode;
		for( int i = 0; i < m_nLength && pCurrentNode; i++ ) {
			if( pCurrentNode->NodeData == target ) {
				nResultIndex = i;
				return true;
			}
			pCurrentNode = pCurrentNode->pNextNode;
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
		m_pHeadNode->pNextNode = nullptr;
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
			if( !pCurrentNode ) {
				// Handle memory error
				return nullptr;
			}
			pCurrentNode = pCurrentNode->pNextNode;
		}
		return pCurrentNode;
	}
}
