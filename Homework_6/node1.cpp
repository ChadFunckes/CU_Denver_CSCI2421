// FILE: node1.cpp
// IMPLEMENTS: The functions of the node class and the
// linked list toolkit (see node1.h for documentation).
// INVARIANT for the node class:
// The data of a node is stored in data_field, and the link in link_field, the previous node link is stored in the Last_field

#include "node1.h"
#include <cassert>    // Provides assert
#include <cstdlib>    // Provides NULL and size_t
using namespace std;

namespace funckes_6
{
	size_t list_length(const node* head_ptr)
		// Library facilities used: cstdlib
	{
		const node *cursor;
		size_t answer;

		answer = 0;
		for (cursor = head_ptr; cursor != head_ptr->last(); cursor = cursor->link())
			++answer;
		++answer;
		return answer;
	}
	/* removed, not needed, there is no head in a circular list
	void list_head_insert(node*& head_ptr, const node::value_type& entry)
	{
		head_ptr = new node(entry, head_ptr);
	}
	*/
	void list_insert(node* head_ptr, node* previous_ptr, const node::value_type& entry)
	{
		node *insert_ptr; // make new node pointer

		insert_ptr = new node(entry, previous_ptr->link()); // create new node with data entry and set the locations pointer to the new node.
		previous_ptr->set_link(insert_ptr);					// sets prev pointers link to the new node
		insert_ptr->set_last(previous_ptr);					// sets the new nodes prev pointer to the location
		insert_ptr->set_link(head_ptr);					    // sets the new nodes next link pointer to the head of the list
		head_ptr->set_last(insert_ptr);						// sets the head pointers last link to the newly created node
	}
	node* list_search(node* head_ptr, const node::value_type& target)
		// Library facilities used: cstdlib
	{
		node *cursor;

		for (cursor = head_ptr; cursor != head_ptr->last(); cursor = cursor->link())
			if (target == cursor->data())
				return cursor;
		return NULL;
	}
	const node* list_search(const node* head_ptr, const node::value_type& target)
		// Library facilities used: cstdlib
	{
		const node *cursor;

		for (cursor = head_ptr; cursor != head_ptr->last(); cursor = cursor->link())
			if (target == cursor->data())
				return cursor;
		return NULL;
	}
	node* list_locate(node* head_ptr, size_t position)
		// Library facilities used: cassert, cstdlib
	{
		node *cursor;
		size_t i;

		assert(0 < position);
		cursor = head_ptr;
		for (i = 1; (i < position); i++)
			cursor = cursor->link();
		return cursor;
	}
	const node* list_locate(const node* head_ptr, size_t position)
		// Library facilities used: cassert, cstdlib
	{
		const node *cursor;
		size_t i;

		assert(0 < position);
		cursor = head_ptr;
		for (i = 1; (i < position); i++)
			cursor = cursor->link();
		return cursor;
	}
	/* removed list_head_remove because there is no longer a head position
	void list_head_remove(node*& head_ptr)
	{
		node *remove_ptr;

		remove_ptr = head_ptr;
		head_ptr = head_ptr->link();
		delete remove_ptr;
	}
	*/
	void list_remove(node* previous_ptr)
	{
		node *remove_ptr;					// create pointer to remove and
		remove_ptr = previous_ptr->link();  // set it to the prev pointers next link
		
		if (remove_ptr == previous_ptr){   // if stement keeps the reomve function from deleting itself
			return;
		}

		node* new_next;						// create pointer to state what the next pointer will be after deletion
		new_next = remove_ptr->link();		// set new next pointer to the pointer to be deleteds link pointer
		new_next->set_last(previous_ptr);	// set that pointers backwards pointer to the pointer before the one to be deleted

		previous_ptr->set_link(remove_ptr->link()); // set the previous pointers next pointer to the link after the pointer to be deleted
		delete remove_ptr;					// give the remove pointer back to the heap.
	}
	void list_clear(node*& head_ptr)
		// Library facilities used: cstdlib
	{
		node* remove_ptr;
		while (head_ptr->link() != head_ptr){
			remove_ptr = head_ptr->link();
			list_remove(head_ptr);
		}
	}
	void list_copy(node* source_ptr, node*& new_list)
		// Library facilities used: cstdlib
	{

		// Handle the case of the empty list.
		if (source_ptr == NULL)
			return;

		if (new_list->link() != NULL){
			list_clear(new_list);
			delete new_list;
		}

		new_list = new node(source_ptr->data());
		node* indx = source_ptr->link();
		node* pos = new_list;

		for (indx; indx != source_ptr; indx = indx->link()){
			list_insert(new_list, pos, indx->data());
			pos = pos->link();
		}
		
	}
}