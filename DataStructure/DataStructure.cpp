// DataStructure.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "TypeDefine.h"
#include "LinkedList.h";
#include "Stack.h"

using namespace DataStructure;

void LinkedListTest();
void StackTest();

int main()
{
	StackTest();
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

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
