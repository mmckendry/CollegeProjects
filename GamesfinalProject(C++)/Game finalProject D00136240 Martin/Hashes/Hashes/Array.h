#ifndef ARRAY_H
#define ARRAY_H

#include <iostream>
#include <stdio.h>

template<class Datatype>
 class Array{
 public:

 //here is my pointer
 Datatype* m_array;
		 //here is the size of my array
 int m_size;
 int numElements;
 
 


 /* Here is my Constructor
	Name:	Array::Array
	Description:	This constructs the array
	Arguments:	-P_size: specifies the size of the array
*/


 Array( int p_size) {
 m_array= new Datatype[p_size];
 m_size= p_size;
 }



 /*Here is my Destructor
	Name: Array:Array
	Description: it deletes the array when its called
	Arguments: no arguments
	*/
 ~Array() {
	 //if the array is not null, delete it
 if( m_array!= 0 )

 delete[] m_array;	//because we used "New" to create the array we must use "delete"

  m_array = 0;	//Clears the pointer
 }


  /*Here is my Access Operator
	Name:	Array::Operator[]
	Descriptions: returns an array value at the index you select
	Arguments:	input p_index // position in the array, output return reference array value corresponding to the index
	*/

 // Datatype& operator[] ( int p_index)
 //{
	//
	// if(m_array[p_index] != 0){
	//	 numElements ++;
	// }
	//return m_array[p_index];
	//
	//
 // }

 Datatype& operator[] ( int p_index)
 {
 return m_array[p_index];
 }



  /*Here is my Conversion Operator
	Name:	Array::converion
	Descriptions: allows you to implicitly convert a class into a different data type.
	Arguments:	it has no arguments
	*/

  operator Datatype* ()
{
return m_array;
}


  // -------------------------------------------------------
//  Name:         Array::Size
//  Description:  gets the size of the array.
//  Arguments:    None.
//  Return Value: the size of the array.
// -------------------------------------------------------
    int Size()
    {
        return m_size;
    }



   /*Here is my Resize method
	Name:	Resize
	Descriptions: its an algorithm to change the size of an array
	Arguments:	input p_size
	*/

  void Resize( int grow_size){
	  Datatype* newarray= new Datatype[grow_size];
	 if( newarray== 0 )
		 return;
 
	 int min;
	// if the old array is smaller then use that size as the min, if not use the new array as the min size

		if( grow_size < m_size)
			 min = grow_size;
 
		else
			min = m_size;
	 int index;

	 //Runs through all the array and makes the new array equal to the old.
		for( index = 0; index < min; index++ )
			newarray[index] = m_array[index];
			m_size= grow_size;

			//if its NOT equal to 0 delete
		if( m_array!= 0 )
			delete[] m_array;
			m_array= newarray;
	 }

// -------------------------------------------------------
//  Name:         Array::Insert
//  Description:  Inserts a cell inbetween two others.
//  Arguments:    - p_item: item to insert
//                - p_index: index to insert at.
// -------------------------------------------------------
    void Insert( Datatype p_item, int p_index )
    {
        int index;
        
        // move everything after p_index up by one cell.
        for( index = m_size - 1; index > p_index; index-- )
            m_array[index] = m_array[index - 1];

        // insert the item.
        m_array[p_index] = p_item;
    }





// -------------------------------------------------------
//  Name:         Array::Remove
//  Description:  Removes a cell
//  Arguments:    - p_index: index to remove.
// -------------------------------------------------------

   void Remove( int p_index )
    {
        int index;

        // move everything after p_index down by one cell.
        for( index = p_index + 1; index < m_size; index++ )
            m_array[index - 1] = m_array[index];
    }


   
   /* Here is my clear method
   Name: clear
   Descriptions: clears the values from the array
   Arguments: none
   */

   void clear(){
	
		 int index = 0;
	   for(int i = 0; i < m_size; i++){

		   m_array[i] = index;
			for(int i = 0; i < m_size; i++){
				m_array[index -1] = m_array[i];
			}
		}
   }


   /* Here is my linear search method
   Name: linear search
   Descriptions: searches the array from end to end to find the correct number
   Arguments: The thing you wish to search for
   */

   void linearSearch(int searNo){
		int index = 0;
		int i = 0;
		//searches through the array and checks the searh number against every element when it gets a hit it prints out the number.
		while(searNo != m_array[i]){
		for( i = 0; i < m_size; i++){
			index++;
			m_array[i];
		

			if(searNo == m_array[i]){
				cout << "here is the number you have searched for: " << searNo << " it was at position: " << index << " of the array." << endl;
				break;
			}
		}
			if(searNo != m_array[i]){
			
				cout << "The number could not be found." <<endl;
				break;
			}
			
		}
   }

    /*Here is my binarySerach method
	Name:	binarySearch
	Descriptions:	its searches the whole array by going to the middle point then checking higher or lower and then opulling ot the appropriate number
	Arguments:	seach number
	*/

   void binarySearch(int searNo, int n){
	 int low = 0, mid, high = n -1;

	 while (low <= high){
					 //find the mid point of the array
					 mid = (low + high) / 2;
					 //check the number against mid
					 if (searNo < m_array[mid])
						 //if the number is below the mid reset high
						 high = mid - 1;
					 else if (searNo > m_array[mid])
						 //if the number is below the mid reset low
						 low = high + 1;
					 else
						 //if the number is found set low to exit the loop(if low > hi it breaks the loop)
						 low = high + 1;
				 }

				 
				 if (searNo == m_array[mid]){
					 cout << "Here is the number you have searched for: " << searNo << endl;
				 }
				 else{
					 cout << "The number could not be found." << endl;
				 }
			 }
  
   /*Here is my push method
	Name:	push
	Descriptions:	its used to insert a number into the correct order in the array into the array.
	Arguments:	input position
	*/

	void push(Datatype p_item, int n ){
		int index = 0;
		int lo = 0, mid, hi = n -1;
		
		// similar to a binary search but when the conditions 
		while(lo <= hi){
			index ++;
			mid = (lo + hi)/2;


			if(p_item > m_array[mid] ){
				hi = mid -1;
			}

			else if(p_item < m_array[mid]){
				lo = mid + 1;
			}

			}
	
		//this means that when the number is between the new hi and low that it places it in the (hopefully) correct area
			 if (p_item < m_array[hi] && p_item > m_array[lo]){
					m_array[index] = p_item;
			 }
	
	}
 // -------------------------------------------------------
//  Name:         Array::Pop
//  Description:  Pops out the last element
//  Arguments:    None.
//  Return Value: none.
// -------------------------------------------------------

	void pop(){
		
		m_array[m_size -1] = m_array[m_size];
	
	}


		
   /*Here is my display method
	Name:	display
	Descriptions: it will display the array when it is called
	Arguments:	none (possibly the array)
	*/
		/*void display(Array<Datatype> myArray){
			
			int index = 0;
			
			for(int i = 0; i< myArray.size; i++){
				index = myArray[i];
				cout << "index: " << index <<endl;
			}

			
		}
	*/




 
// -------------------------------------------------------
//  Name:         Array::WriteFile
//  Description:  Writes an array to disk
//  Arguments:    The Filename
//  Return Value: true on success, false on failure
// -------------------------------------------------------
    bool WriteFile( const char* p_filename )
    {
        FILE* outfile = 0;
        int written = 0;

        // open the file
        outfile = fopen( p_filename, "wb" );

        // return if it couldn't be opened
        if( outfile == 0 )
            return false;

        // write the array and close thef ile
        written = fwrite( m_array, sizeof( Datatype ), m_size, outfile );
        fclose( outfile );

        // if we didn't write the number of items we expected,
        // return failure
        if( written != m_size )
            return false;

        // return success.
        return true;
    }





	// -------------------------------------------------------
//  Name:         Array::ReadFile
//  Description:  reads an array from disk
//  Arguments:    The Filename
//  Return Value: true on success, false on failure
// -------------------------------------------------------
    bool ReadFile( const char* p_filename )
    {
        FILE* infile = 0;
        int read = 0;

        // open the file
        infile = fopen( p_filename, "wb" );

        // return if it couldn't be opened
        if( infile == 0 )
            return false;

        // read the array and close the file
        read = fread( m_array, sizeof( Datatype ), m_size, infile );
        fclose( infile );

        // if we didn't read the number of items we expected,
        // return failure
        if( read != m_size )
            return false;

        // return success
        return true;
    }


    


 };

#endif