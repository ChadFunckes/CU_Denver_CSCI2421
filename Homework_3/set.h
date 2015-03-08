// Chad S Funckes
// CSCI 2421
// Feb 16 2015
// CLASS PROVIDED: set (Modification of the bag class, HW3)
//
// TYPEDEF and MEMBER CONSTANTS for the bag class:
//   typedef ____ value_type
//     set::value_type is the data type of the items in the set. It may be any of
//     the C++ built-in types (int, char, etc.), or a class with a default
//     constructor, an assignment operator, and operators to
//     test for equality (x == y) and non-equality (x != y).
//
//   typedef ____ size_type
//     set::size_type is the data type of any variable that keeps track of how many items
//     are in a set.
//
//   static const size_type CAPACITY = _____
//     set::CAPACITY is the maximum number of items that a bag can hold.
//
// CONSTRUCTOR for the bag class:
//   set( )
//     Postcondition: The set has been initialized as an empty set.
//
// MODIFICATION MEMBER FUNCTIONS for the set class:
//   size_type erase(const value_type& target);
//     Postcondition: All copies of target have been removed from the set.
//     The return value is the number of copies removed (which could be zero).
//
//   void erase_one(const value_type& target)
//     Postcondition: If target was in the set, then one copy has been removed;
//     otherwise the set is unchanged. A true return value indicates that one
//     copy was removed; false indicates that nothing was removed.
//
//   void insert(const value_type& entry)
//     Precondition:  size( ) < CAPACITY.
//     Postcondition: A new copy of entry has been added to the bag.
//
//   void operator +=(const set& addend)
//     Precondition:  size( ) + addend.size( ) <= CAPACITY.
//     Postcondition: Each item in addend has been added to this set.
//
//	 void clear_dups()
//		Postcondition: All of the duplicate items in the set are removed.
//
// CONSTANT MEMBER FUNCTIONS for the set class:
//   size_type size( ) const
//     Postcondition: The return value is the total number of items in the set.
//
//   size_type count(const value_type& target) const
//     Postcondition: The return value is number of times target is in the set.
//
//	 value_type display(const value_type& item) const)
//	   Postcondition: The return value is the value in the set at that position.
//
// NONMEMBER FUNCTIONS for the bag class:
//   set operator +(const set& b1, const set& b2)
//     Precondition:  set1.size( ) + set2.size( ) <= set::CAPACITY.
//     Postcondition: The bag returned is the union of set1 and set2.
//
//	set operator -(const set& b1, const set& b2)
//	  Postcondition: All of the items in set 2 are removed from set 1.
//
// VALUE SEMANTICS for the bag class:
//    Assignments and the copy constructor may be used with set objects.

#ifndef CHAD_FUNCKES_SET_H
#define CHAD_FUNCKES_SET_H
#include <cstdlib>  // Provides size_t

namespace Chad_Funckes_HW3
{
    class set
    { 
    public:
        // TYPEDEFS and MEMBER CONSTANTS
	// * For VC++ 6.0 we are using size_t instead of std::size_t. And we
	// * have defined CAPACITY using an enum instead of a static member
	// * constant. See www.cs.colorado.edu/~main/vc6.html for details.
        typedef int value_type;
        typedef size_t size_type;
		enum { CAPACITY = 30 }; 
        
		// CONSTRUCTOR
        set( ) { used = 0; } 
        
		// MODIFICATION MEMBER FUNCTIONS
        size_type erase(const value_type& target);
        bool erase_one(const value_type& target);
        void insert(const value_type& entry);
        void operator +=(const set& addend);
		void clear_dups ();
        
		// CONSTANT MEMBER FUNCTIONS
        size_type size( ) const { return used; }
        size_type count(const value_type& target) const;
		value_type display(const value_type& item) const;

    private:
        value_type data[CAPACITY];  // The array to store items
        size_type used;             // How much of array is used
    };

    // NONMEMBER FUNCTIONS for the bag class
    set operator +(const set& b1, const set& b2);
	set operator -(const set& b1, const set& b2);
}
#endif

