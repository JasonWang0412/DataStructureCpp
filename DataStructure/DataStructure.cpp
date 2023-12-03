// DataStructure.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "LinkedList.h";

using namespace std;
using namespace DataStructure;

int main()
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
	cout << pl.GetLength() << endl; // 0

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
	cout << data1 << endl; // 4
	cout << data2 << endl; // -999

	int index1 = -999; int index2 = -999;
	pl.FindElement( 4, index1 );
	pl.FindElement( 7, index1 );
	cout << index1 << endl; // 4
	cout << index2 << endl; // -999

	cout << pl.GetLength() << endl; // 7
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
