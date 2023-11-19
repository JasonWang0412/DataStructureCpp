#include "List.h";
#include <iostream>

using namespace std;

List::List()
{
	m_pDataArray = new DataType[ INITIALSIZE ];
	m_nCurrentSize = INITIALSIZE;
	m_nLength = 0;
}

void List::Display()
{
	for( int i = 0; i < m_nLength; i++ ) {
		cout << m_pDataArray[ i ] << endl;
	}
}

bool List::Insert( int nIndex, DataType data )
{
	// index protection
	if( nIndex < 0 || nIndex > m_nLength ) {
		return false;
	}

	// allocate new memory when space overload
	if( m_nLength >= m_nCurrentSize ) {
		DataType *pTemp = m_pDataArray;
		m_pDataArray = new DataType[ m_nCurrentSize *= 2 ];
		for( int i = 0; i < m_nLength; i++ ) {
			m_pDataArray[ i ] = pTemp[ i ];
		}
		delete pTemp;
	}

	// move data after index backward
	for( int i = m_nLength - 1; i >= nIndex; i-- ) {
		m_pDataArray[ i + 1 ] = m_pDataArray[ i ];
	}

	// insert data
	m_pDataArray[ nIndex ] = data;

	// expand length
	m_nLength++;
	return true;
}

bool List::Insert( DataType data )
{
	return Insert( m_nLength, data );
}

bool List::Remove( int nIndex )
{
	// index protection
	if( nIndex < 0 || nIndex >= m_nLength ) {
		return false;
	}

	// move data after index forward
	for( int i = nIndex; i < m_nLength - 1; i++ ) {
		m_pDataArray[ i ] = m_pDataArray[ i + 1 ];
	}

	// shorter length
	m_nLength--;

	return true;
}

bool List::Remove()
{
	return Remove( m_nLength - 1 );
}

bool List::GetElement( int nIndex, DataType &data )
{
	// index protection
	if( nIndex < 0 || nIndex >= m_nLength ) {
		return false;
	}

	data = m_pDataArray[ nIndex ];
	return true;
}

bool List::FindElement( DataType target, int &nResultIndex )
{
	for( int i = 0; i < m_nLength; i++ ) {
		if( m_pDataArray[ i ] == target ) {
			nResultIndex = i;
			return true;
		}
	}
	return false;
}

void List::Clear()
{
	m_nLength = 0;
}

int List::GetLength()
{
	return m_nLength;
}