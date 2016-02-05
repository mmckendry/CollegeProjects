#include <iostream>
#include <windows.h>

#include "DLinkedList.h"
using namespace std;

int main(){

	
	DLinkedNode<int>* newNode = new DLinkedNode<int>;
	newNode ->m_data = 100;
	newNode ->m_next = new DLinkedNode<int>;
	newNode = newNode->m_next;
	newNode->m_data = 46;
	newNode ->m_next = new DLinkedNode<int>;
	newNode ->m_next ->m_data = 89;
	
	
	DLinkedNode<int>* listNode = new DLinkedNode<int>;
	listNode ->m_data = 75;
	listNode->InsertAfter(82);
	listNode->InsertBefore(788);


	cout << "N0de: "<< newNode->m_next->m_data <<  endl;
	cout << "List N0de: " << listNode->m_data << " Break " << listNode->m_next->m_data << endl;
	getchar();
	
	listNode->dropNode();
	
	cout << "List N0de: " << listNode->m_data << " Break " << listNode->m_next->m_data << endl;
	getchar();
	
	
	cout << "N0de: "<< newNode->m_next->m_data <<  endl;
	cout << "List N0de: " << listNode->m_data << endl;
	getchar();




	DLinkedList<int>* dualList = new DLinkedList<int>; 

	dualList->Append(10);
	dualList->Append(20);
	dualList->Append(30);
	cout<< "the list contains: "<< endl;
// create a new iteratorand make it point to the
 //beginning of the list.
DListIterator<int> itr = itr.GetIterator(dualList);
// loop through the list while the iteratoris valid.
for( itr.Start(); itr.Valid(); itr.Forth() )
{
cout << itr.Item() << ", ";
}
// reset the iteratorto the beginning again.
itr.Start();
cout << " " <<endl;

cout << "Ahhhhh! I created a new line" << endl;

dualList->RemoveTail();
dualList->RemoveHead();

dualList->Prepend(42);

for(itr.Start(); itr.Valid(); itr.Forth()){
	cout << itr.Item() << ", ";
}

itr.Start();

	getchar();


	cout << "new test" << endl;
	
	
	DLinkedList<int>* testList = new DLinkedList<int>;
	DListIterator<int> iter = iter.GetIterator(testList);

	testList->Append(46);
	testList->Append(22);
	testList->Append(995);
	testList->Prepend(88);
	testList->Prepend(44);



	for(iter.Start();iter.Valid();iter.Forth()){
		
		cout << iter.Item() << " , ";
	}
	iter.Start();
	getchar();
} 
