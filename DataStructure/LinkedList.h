#pragma once

namespace DataStructure
{
	struct ListNode
	{
		DataType NodeData;
		ListNode *pNextNode;
	};

	class LinkedList
	{
	public:
		LinkedList();
		~LinkedList();
		void Display();
		bool Insert( int nIndex, DataType data );
		bool Insert( DataType data );
		bool Remove( int nIndex );
		bool Remove();
		bool GetElement( int nIndex, DataType &data );
		bool FindElement( DataType target, int &nResultIndex );
		void Clear();
		int GetLength();

	private:
		ListNode *FindListNode( int nIndex );
		int m_nLength;
		ListNode *m_pHeadNode;
	};
}
