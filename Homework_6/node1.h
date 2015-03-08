// FILE: node1.h
// PROVIDES: A modified class for a node in a circular double linked list, and list manipulation
// functions, all within the namespace funckes_6
// original node class provided by Data structures and other objects by walter savich
//
// TYPEDEF for the node class:
//     Each node of the list contains a piece of data and a pointer to the
//     next node. The type of the data is defined as node::value_type in a
//     typedef statement. The value_type may be any
//     of the built-in C++ classes (int, char, ...) or a class with a copy
//     constructor, an assignment operator, and a test for equality (x == y).
//
// CONSTRUCTOR for the node class:
//   node(
//     const value_type& init_data = value_type(),
//     node* init_link = NULL
//   )
//     Postcondition: The node contains the specified data and link.
//     NOTE: The default value for the init_data is obtained from the default
//     constructor of the value_type. In the ANSI/ISO standard, this notation
//     is also allowed for the built-in types, providing a default value of
//     zero. The init_link has a default value of NULL, and the last_field has a value of null.
//
// NOTE:
//   Some of the functions have a return value which is a pointer to a node.
//   Each of these  functions comes in two versions: a non-const version (where
//   the return value is node*) and a const version (where the return value
//   is const node*). 
// EXAMPLES:
//    const node *c;
//    c->link( ) activates the const version of link
//    list_search(c,... calls the const version of list_search
//    node *p;
//    p->link( ) activates the non-const version of link
//    list_search(p,... calls the non-const version of list_search
//
// MEMBER FUNCTIONS for the node class:
//   void set_data(const value_type& new_data)
//     Postcondition: The node now contains the specified new data.
//   
//   void set_link(node* new_link)
//     Postcondition: The node now contains the specified new link.
//
//	void set_last(node* new_link)
//		Postcondition: The now contains the data about the previous node link.
//
//   value_type data( ) const
//     Postcondition: The return value is the data from this node.
//
//   const node* link( ) const <----- const version
//   node* link( ) <----------------- non-const version
//   See the note (above) about the const version and non-const versions:
//     Postcondition: The return value is the link from this node.
//
// const node* last( ) const <----- const version
// node* last( ) <----------------- non-const version
//   
// FUNCTIONS in the linked list toolkit:
//   size_t list_length(const node* head_ptr)
//     Precondition: head_ptr is the head pointer of a linked list.
//     Postcondition: The value returned is the number of nodes in the linked
//     list.
//
//   void list_insert(node* head_ptr, node* previous_ptr, const node::value_type& entry) 
//     Precondition: Head_ptr is the enty into a circular list, previous_ptr points to a node in a linked list.
//     Postcondition: A new node containing the given entry has been added
//     after the node that previous_ptr points to.
//
//   const node* list_search(const node* head_ptr, const node::value_type& target) 
//   node* list_search(node* head_ptr, const node::value_type& target) 
//   See the note (above) about the const version and non-const versions:
//     Precondition: head_ptr is the head pointer of a linked list.
//     Postcondition: The pointer returned points to the first node containing
//     the specified target in its data member. If there is no such node, the
//     null pointer is returned.
//
//   const node* list_locate(const node* head_ptr, size_t position) 
//   node* list_locate(node* head_ptr, size_t position) 
//   See the note (above) about the const version and non-const versions:
//     Precondition: head_ptr is the head pointer of a linked list, and
//     position > 0.
//     Postcondition: The pointer returned points to the node at the specified
//     position in the list that is a number of positions away from the pointer position
//		input.  If there is more than the number of positions than in the list, it will loop
//      around again to move that many positions.
//
//   void list_remove(node* previous_ptr) 
//     Precondition: previous_ptr points to a node in a linked list.
//     Postcondition: The node after previous_ptr has been removed from the
//     linked list.  *note if there is only one item in the list, the function will return and 
//		do nothing.  Use set_data() etc.. to change if there is only one node.
//
//   void list_clear(node*& head_ptr) 
//     Precondition: head_ptr is the head pointer of a linked list.
//     Postcondition: All nodes of the list have been returned to the heap,
//     and the head_ptr has both next and last links set to itself.
//
//   void list_copy(node* source_ptr, node*& new_list) 
//     Precondition: source_ptr is the head pointer of a linked list.
//					 new_list is the pointer to a list (initialized OR unitialized)
//     Postcondition: A new list that contains the same items as the list pointed to by
//     source_ptr.  **** NOTE **** if new_list is a list that contains data or is already initialized
//					that data will be cleared and the original data deleted and returned to the heap.
//					only a fresh copy of the list will exist at the copy to pointer.  If there were other
//					pointers that pointed to the old data in the copy to list, they are no longer valid.
//
//
// DYNAMIC MEMORY usage by the toolkit: 
//   If there is insufficient dynamic memory, then the following functions throw
//   bad_alloc: the constructor, list_head_insert, list_insert, list_copy,
//   list_piece.

#ifndef FUNCKES_HW6  
#define FUNCKES_HW6
#include <cstdlib> // Provides size_t and NULL
#include <string>

namespace funckes_6
{
	class node
	{
	public:
		// TYPEDEF
		typedef int value_type;

		// CONSTRUCTOR
		node(const value_type& init_data = value_type(), node* init_link = NULL)
		{
			data_field = init_data; link_field = init_link; last_field = NULL;
		}

		// Member functions to set the data and link fields:
		void set_data(const value_type& new_data) { data_field = new_data; }
		void set_link(node* new_link)             { link_field = new_link; }
		void set_last(node* new_link)			  { last_field = new_link; }

		// Constant member function to retrieve the current data:
		value_type data() const { return data_field; }

		// Two slightly different member functions to retreive
		// the current link:
		const node* link() const { return link_field; }
		node* link()             { return link_field; }
		node* last()			 { return last_field; }
		const node* last() const { return last_field; }
		
	private:
		value_type data_field;
		node* link_field;
		node* last_field;
		//node* head_ptr;
	};

	// FUNCTIONS for the linked list toolkit
	std::size_t list_length(const node* head_ptr);  // modified for HW6
	//void list_head_insert(node*& head_ptr, const node::value_type& entry); // ** removed because there is no longer a head
	void list_insert(node* head_ptr, node* previous_ptr, const node::value_type& entry); // modified for HW6
	node* list_search(node* head_ptr, const node::value_type& target); // modified for HW6
	const node* list_search(const node* head_ptr, const node::value_type& target); // modified for HW6
	node* list_locate(node* head_ptr, std::size_t position); // modified for HW6
	const node* list_locate(const node* head_ptr, std::size_t position); // modified for HW6
	//void list_head_remove(node*& head_ptr); // * removed, no longer head position
	void list_remove(node* previous_ptr); // modified for HW6
	void list_clear(node*& head_ptr); // modified for HW6
	void list_copy(node* source_ptr, node*& new_list); // modified for HW6
}

#endif