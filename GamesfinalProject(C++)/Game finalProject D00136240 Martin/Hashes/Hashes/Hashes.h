
#ifndef HASHES_H
#define HASHES_H
#include "Array.h"
#include "DLinkedlist.h"


template< class KeyType, class DataType >

class HashEntry{
public:

	KeyType m_key;

	DataType m_data;


};
template< class KeyType, class DataType >

class HashTable{
public:

	typedef HashEntry<KeyType, DataType> Entry;
	int m_size;
	int m_count;
	Array <DLinkedList< Entry >> m_table;
	unsigned long int (*m_hash)(KeyType);

/*
	Name: Constructor
	Description: The default constructer for the hashes set
	Arguments: none
	Returns: none

*/

	HashTable( int p_size, unsigned long int (*p_hash)(KeyType) ): m_table( p_size )
{
// set the size, hash function, and count.
	m_size = p_size;
	m_hash = p_hash;
	m_count = 0;
}

	/*
	Name: Insert method
	Description: This inserts the data into the hash set
	Arguments: key and the data
	Returns: none

*/

	void Insert( KeyType p_key, DataType p_data )
{
Entry entry;
entry.m_data = p_data;
entry.m_key = p_key;
int index = m_hash( p_key ) % m_size;
m_table[index].Append( entry );
m_count++;
}


	/*
	Name: find method
	Description: This finds the data that 
	Arguments: key and the data
	Returns: none

*/

Entry* Find( KeyType p_key )
{
int index = m_hash( p_key ) % m_size;
DListIterator<Entry> itr = m_table[index].GetIterator();
while( itr.Valid() )
{
if( itr.Item().m_key == p_key )
return &(itr.Item());
itr.Forth();
}
return 0;
}

/*
	Name: Remove
	Description: removes the specified value from the hash
	Arguments: key
	Return: none
*/


bool Remove( KeyType p_key ){
	int index = m_hash( p_key ) % m_size;
	DListIterator<Entry> itr = m_table[index].GetIterator();

	while( itr.Valid() ){
		if( itr.Item().m_key == p_key ){
			m_table[index].Remove( itr );
			m_count--;	
				return true;
		}	
			itr.Forth();
		}
		return false;
	}

	unsigned long int Hash( int k )
{
return k;
}


};

/*
class String{
public:
char m_string[64];

	String(){
	strcpy( m_string, "" );
	}

	String( char* p_string ){
		strcpy( m_string, p_string );
	}

	bool operator== ( String& p_right ){
	return !strcmp( m_string, p_right.m_string);
	}
};
*/



#endif;