#pragma once

namespace DataStructure
{
	class Stack
	{
	public:
		Stack();
		~Stack();
		void Display();
		bool Push( DataType data );
		bool Pop( DataType &data );
		bool Peek( DataType &data );
		void Clear();
		int GetLength();

	private:
		LinkedList m_DataList;
	};
}
