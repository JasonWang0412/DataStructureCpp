// DataStructure.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "List.h";

using namespace std;

int main()
{
	List *pl = new List();
	pl->Insert( 666 );
	pl->Insert( 888 );
	pl->Insert( 1, 777 );
	pl->Display();
	DataType data;
	pl->GetElement( 1, data );
	cout << data << endl;
	int index;
	pl->FindElement( 777, index );
	cout << index << endl;
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
