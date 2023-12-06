#include <iostream>
#include "TypeDefine.h"
#include "LinkedList.h"

#include "Queue.h""

namespace DataStructure
{
	Queue::Queue() = default;

	Queue::~Queue() = default;

	void Queue::Display()
	{
		if( m_DataList.GetLength() == 0 ) {
			std::cout << "queue empty" << std::endl;
			return;
		}
		m_DataList.Display();
	}

	bool Queue::EnQueue( DataType data )
	{
		return m_DataList.Insert( data );
	}

	bool Queue::DeQueue( DataType &data )
	{
		if( !m_DataList.GetElement( 0, data ) ) {
			return false;
		}
		return m_DataList.Remove( 0 );
	}

	bool Queue::Peek( DataType &data )
	{
		return m_DataList.GetElement( 0, data );
	}

	void Queue::Clear()
	{
		m_DataList.Clear();
	}

	int Queue::GetLength()
	{
		return m_DataList.GetLength();
	}
}

