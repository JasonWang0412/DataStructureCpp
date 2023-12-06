#include <iostream>
#include "TypeDefine.h"
#include "LinkedList.h"

#include "Stack.h"

namespace DataStructure
{
	Stack::Stack() = default;

	Stack::~Stack() = default;

	void Stack::Display()
	{
		m_DataList.Display();
	}

	bool Stack::Push( DataType data )
	{
		return m_DataList.Insert( data );
	}

	bool Stack::Pop( DataType &data )
	{
		if( !m_DataList.GetElement( m_DataList.GetLength() - 1, data ) ) {
			return false;
		}
		return m_DataList.Remove();
	}

	bool Stack::Peek( DataType &data )
	{
		return m_DataList.GetElement( m_DataList.GetLength() - 1, data );
	}

	void Stack::Clear()
	{
		return m_DataList.Clear();
	}

	int Stack::GetLength()
	{
		return m_DataList.GetLength();
	}
}
