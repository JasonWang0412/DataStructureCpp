// DataStructure.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "TypeDefine.h"
#include "LinkedList.h";
#include "Stack.h"
#include "Queue.h"
#include "BinaryTree.h"

using namespace DataStructure;

void LinkedListTest();
void StackTest();
void QueueTest();

int main()
{
	BinaryTree T;
	T.CreateByPreOrderAndInOrder( "ABDGHCEIF", "GDHBAEICF" );
	T.DFSTraverse(TraverseType::PreOrder);
	std::cout << "\n";
	T.DFSTraverse( TraverseType::InOrder );
}

void LinkedListTest()
{
	LinkedList pl;

	pl.Insert( 1 );
	pl.Insert( 3 );
	pl.Insert( 4 );
	pl.Insert( 1, 2 );
	pl.Insert( 4, 5 ); // OK
	pl.Insert( 6, -1 ); // NG, length is 5
	pl.Insert( 0, 0 ); // OK
	pl.Insert( -1, -1 ); //NG
	pl.Display(); // 0, 1, 2, 3, 4, 5

	pl.Remove();
	pl.Remove( 1 );
	pl.Remove( 0 ); // OK
	pl.Remove( -1 ); // NG
	pl.Remove( 2 ); // OK
	pl.Remove( 2 ); // NG, length is 2
	pl.Display(); // 2, 3

	pl.Clear();
	pl.Display(); // nothing
	std::cout << pl.GetLength() << std::endl; // 0

	pl.Insert( 0 );
	pl.Insert( 1 );
	pl.Insert( 2 );
	pl.Insert( 3 );
	pl.Insert( 4 );
	pl.Insert( 5 );
	pl.Insert( 6 );
	DataType data1 = -999;
	DataType data2 = -999;
	pl.GetElement( 4, data1 );
	pl.GetElement( 7, data2 );
	std::cout << data1 << std::endl; // 4
	std::cout << data2 << std::endl; // -999

	int index1 = -999; int index2 = -999;
	pl.FindElement( 4, index1 );
	pl.FindElement( 7, index1 );
	std::cout << index1 << std::endl; // 4
	std::cout << index2 << std::endl; // -999

	std::cout << pl.GetLength() << std::endl; // 7
}

void StackTest()
{
	Stack st;
	st.Push( 0 );
	st.Push( 1 );
	st.Push( 2 );
	st.Push( 3 );
	st.Push( 4 );
	st.Display(); // 0, 1, 2, 3, 4

	DataType data;
	st.Peek( data );
	std::cout << data << std::endl; // 4

	st.Pop( data );
	std::cout << data << std::endl; // 4

	st.Pop( data );
	std::cout << data << std::endl; // 3

	std::cout << st.GetLength() << std::endl; // 3

	st.Clear();
	st.Display(); // empty

	data = -888;
	st.Peek( data );
	std::cout << data << std::endl; // -888

	data = -999;
	st.Pop( data );
	std::cout << data << std::endl; // -999
}

void QueueTest()
{
	Queue q;
	q.EnQueue( 0 );
	q.EnQueue( 1 );
	q.EnQueue( 2 );
	q.EnQueue( 3 );
	q.EnQueue( 4 );
	q.Display(); // 0, 1, 2, 3, 4

	DataType data;
	q.Peek( data );
	std::cout << data << std::endl; // 0

	q.DeQueue( data );
	std::cout << data << std::endl; // 0

	q.DeQueue( data );
	std::cout << data << std::endl; // 1

	std::cout << q.GetLength() << std::endl; // 3

	q.Clear();
	q.Display(); // empty

	data = -888;
	q.Peek( data );
	std::cout << data << std::endl; // -888

	data = -999;
	q.DeQueue( data );
	std::cout << data << std::endl; // -999
}