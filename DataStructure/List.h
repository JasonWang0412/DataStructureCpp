#pragma once

typedef int DataType;

class List
{
public:
	List();
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
	const int INITIALSIZE = 4;
	int m_nCurrentSize;
	int m_nLength;
	DataType *m_pDataArray;
};
