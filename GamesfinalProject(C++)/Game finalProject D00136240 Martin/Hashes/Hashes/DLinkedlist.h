#ifndef DLINKEDLIST_H
#define DLINKEDLIST_H

template<class Datatype>class DLinkedNode;
template<class Datatype>class DLinkedList;

template<class Datatype>
class DLinkedNode{
public:
	Datatype m_data;
	DLinkedNode<Datatype>* m_prev;
	DLinkedNode<Datatype>* m_next;


	/*
	Name: The Deafult Constructor
	Description: empty Constructor
	Arguments: none
	Returns: none
`*/
	DLinkedNode(){
		m_next = 0;
		m_data = Player();
		m_prev = 0;
	}

	/*
	Name: The insertAfter method
	Description: inserts a node after a given node
	Arguments: none
	Returns: none
*/
void InsertAfter( Datatype p_data)
{
// create the new node.
	DLinkedNode<Datatype>* newnode = new DLinkedNode<Datatype>;
	newnode->m_data = p_data;
// make the new node point to the next node.
	newnode->m_next = m_next;
	newnode->m_prev = this;
// make the previous node point to the new node
	if(m_next != 0){
		m_next->m_prev = newnode;
	}

	m_next = newnode;

}

/*
	Name: The insert before method
	Description: inserts a node infront of another node
	Arguments: none
	Returns: none
*/
void InsertBefore(Datatype p_data){

	DLinkedNode<Datatype>* newnode = new DLinkedNode<Datatype>;
	newnode->m_data = p_data;

	newnode->m_next = this->m_next;
	newnode->m_prev = this;

	if(m_prev != 0){
		m_prev->m_next = newnode;
	}

	m_prev = newnode;

}

/*
	Name: the dropNode method
	Description: sets the next and previous fields to 0 effectively severing the node from the linked list
	Arguments: none
	Returns: none
*/
void dropNode(){

	if(m_prev != 0){
		m_prev->m_next = m_next;
	}

	if(m_next != 0){
		m_next ->m_prev = m_prev;
	}

}


	



};

template<class Datatype>
class DLinkedList{
public:
	DLinkedNode<Datatype>* m_head;
	DLinkedNode<Datatype>* m_tail;
	int m_count;

	/*
	Name: The Deafult Constructor
	Description: empty Constructor
	Arguments: none
	Returns: none
*/
	DLinkedList(){
		m_head= 0;
		m_tail= 0;
		m_count= 0;
	}



	
	/*
	Name: The Destructor
	Description: destructs the list
	Arguments: none
	Returns: none
*/
	~DLinkedList(){
		// temporary node pointers.
		DLinkedNode<Datatype>* itr= m_head;
		DLinkedNode<Datatype>* next;
		while( itr!= 0 ){
			// save the pointer to the next node.
			next = itr->m_next;
			// delete the current node.
			delete itr;
			// make the next node the current node.
			itr= next;
		}
	}

	
	/*
	Name: append
	Description: appends the node on to the end of the list
	Arguments: data field
	Returns: none
*/
	void Append( Datatype p_data){
		if( m_head== 0 ){
			// create a new head node.
			m_head= m_tail= new DLinkedNode<Datatype>;
			m_head->m_data= p_data;
		}
		else{
			// insert a new node after the tail and reset the tail.
			m_tail->InsertAfter( p_data);
			m_tail= m_tail->m_next;
		}
		m_count++;
	}


	
	/*
	Name: prepend
	Description: it prepends the node taking it from the list
	Arguments: data field
	Returns: none
*/
	void Prepend( Datatype p_data){
		// create the new node.
		DLinkedNode<Datatype>* newnode= new DLinkedNode<Datatype>;
		newnode->m_data= p_data;
		newnode->m_next= m_head;
		// set the head node and the tail node if needed.
		m_head= newnode;
		if( m_tail== 0 )
			m_tail= m_head;
		m_count++;

	}

	
	/*
	Name: remove head
	Description: removes the first node from the linked list
	Arguments: none
	Returns: none
*/
	void RemoveHead(){
		DLinkedNode<Datatype>* node = 0;
		if( m_head!= 0 ){
			// make node point to the next node.
			node = m_head->m_next;
			// then delete the head and make the pointer
			// point to node.
			delete m_head;
			m_head= node;
			// if the head is null, then you’ve just deleted the only node
			// in the list. set the tail to 0.
			if( m_head== 0 ){

				m_tail= 0;
			}
			m_count --;
		}
	}

	/*
	Name: remove tail
	Description: removes the last node from the linked list
	Arguments: none
	Returns: none
*/
	void RemoveTail(){
		DLinkedNode<Datatype>* node = m_head;
		// if the list isn’t empty, then remove a node.
		if( m_head!= 0 ){
			// if the head is equal to the tail, then
			// the list has 1 node, and you are removing it.
			if( m_head== m_tail){
				// delete the node and set both pointers
				// to 0.
				delete m_head;
				m_head= m_tail= 0;
			}
			else{
				// skip ahead until you find the node
				// right before the tail node
				while( node->m_next!= m_tail)
					node = node->m_next;
				// make the tail point to the node before the
				// current tail and delete the old tail.
				m_tail= node;
				delete node->m_next;
				node->m_next= 0;
			}
			m_count--;
		}
	}

	

};

template<class Datatype>
class DListIterator{

public:
	DLinkedNode<Datatype>* m_node;
	DLinkedList<Datatype>* m_list;

	/*
	Name: IterConstructor
	Description: basic constructor for the iterator
	Arguments: none
	Returns: none
*/
	DListIterator( DLinkedList<Datatype>* p_list= 0 , DLinkedNode<Datatype>* p_node= 0 ){
		m_list= p_list;
		m_node= p_node;
		
	}

	/*
	Name: start
	Description: points the iterator to the start node
	Arguments: none
	Returns: none
*/
	void Start(){
		if( m_list!= 0 )
			m_node= m_list->m_head;
	}

	/*
	Name: fourth
	Description: points the iterator to the next node
	Arguments: none
	Returns: none
*/
	void Forth(){
		if( m_node!= 0 )
	m_node= m_node->m_next;
	}

	/*
	Name: item
	Description: points the iterator to the current node
	Arguments: none
	Returns: none
*/
	Datatype& Item(){
		return m_node->m_data;
	}
	/*
	Name: vaild
	Description:checks if the iterator is a valid node
	Arguments: none
	Returns: none
*/
	bool Valid(){
		return (m_node!= 0);
	}

	/*
	Name: getIter
	Description: calls the iter into function
	Arguments: none
	Returns: none
*/
	DListIterator<Datatype> GetIterator(DLinkedList<Datatype>* l_list){
		return DListIterator<Datatype>( l_list, l_list->m_head);
	}

};
#endif;