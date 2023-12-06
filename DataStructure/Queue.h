#pragma once

namespace DataStructure
{
	class Queue
	{
	public:
		Queue();
		~Queue();
		void Display();
		bool EnQueue( DataType data );
		bool DeQueue( DataType &data );
		bool Peek( DataType &data );
		void Clear();
		int GetLength();

	private:
		LinkedList m_DataList;
	};
}
