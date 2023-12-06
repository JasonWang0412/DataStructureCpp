#pragma once

namespace DataStructure
{
	typedef int DataType;
	class LinkedList;

	class Queue
	{
	public:
		Queue();
		~Queue();
		void Display();
		bool EnQueue( DataType data );
		bool DeQueue();
		bool Peek( DataType &data );
		void Clear();
		int GetLength();

	private:
		LinkedList *m_DataList;
	};
}
