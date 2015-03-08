//Chad S Funckes
// csci 2421
// Set implementation (modification of bag class, HW3)
//
// FILE: set.cpp
// Modification of bag class in Chapter 3 of Data Structures and Other Objects (Second Edition)
// ________________________________________________________________________
//
// This file has been modified to work with Microsoft Visual C++ 6.0,
// as described in www.cs.colorado.edu/~main/vc6.html
// ________________________________________________________________________
//
// CLASS IMPLEMENTED: set (see set.h for documentation)
// INVARIANT for the set class:
//   1. The number of items in a set is in the member variable used;
//   2. For an empty bag, we do not care what is stored in any of data; for a
//      non-empty bag the items in the bag are stored in data[0] through
//      data[used-1], and we don't care what's in the rest of data.

#include <algorithm> // Provides copy function
#include <cassert>   // Provides assert function
#include "set.h"
using namespace std;

namespace Chad_Funckes_HW3
{
	// (Omitted for VC++ 6.0) const bag::size_type bag::CAPACITY;

	set::size_type set::erase(const value_type& target)
	{
		size_type index = 0;
		size_type many_removed = 0;

		while (index < used)
		{
			if (data[index] == target)
			{
				--used;
				data[index] = data[used];
				++many_removed;
			}
			else
				++index;
		}

		return many_removed;
	}

	bool set::erase_one(const value_type& target)
	{
		size_type index; // The location of target in the data array    

		// First, set index to the location of target in the data array,
		// which could be as small as 0 or as large as used-1. If target is not
		// in the array, then index will be set equal to used.
		index = 0;
		while ((index < used) && (data[index] != target))
			++index;

		if (index == used)
			return false; // target isn?t in the bag, so no work to do.

		// When execution reaches here, target is in the bag at data[index].
		// So, reduce used by 1 and copy the last item onto data[index].
		--used;
		data[index] = data[used];
		return true;
	}

	void set::insert(const value_type& entry)
		// Library facilities used: cassert
	{
		assert(size() < CAPACITY);

		data[used] = entry;
		++used;
	}

	void set::clear_dups(){  /// Takes duplicated out of the array
		for (unsigned out_loop = 0; out_loop < used; out_loop++){ // outside loop is the item being compared
			for (unsigned in_loop = out_loop + 1; in_loop < used; in_loop++){ // inside loop is what the outside is being compared to
				if (data[out_loop] == data[in_loop]){ // if the comparison is the same
					data[in_loop] = data[used - 1];   // take the number from the back of the array and replace the duplicate
					--used;							 // then pull back used to be the new end of the array.
				} 
			} 
		} 
	}

	void set::operator +=(const set& addend)
		// Library facilities used: algorithm, cassert
	{
		assert(size() + addend.size() <= CAPACITY);

		copy(addend.data, addend.data + addend.used, data + used);
		used += addend.used;
	}

	set::size_type set::count(const value_type& target) const
	{
		size_type answer;
		size_type i;

		answer = 0;
		for (i = 0; i < used; ++i)
			if (target == data[i])
				++answer;
		return answer;
	}

	set operator +(const set& b1, const set& b2)
		// Library facilities used: cassert
	{
		set answer;

		assert(b1.size() + b2.size() <= set::CAPACITY);

		answer += b1;
		answer += b2;
		answer.clear_dups();
		return answer;
	}

	set operator -(const set& b1, const set& b2){
		set answer = b1;

		for (int i = 0; i < b2.size(); i++) // for loop iterates as long as there is numbers to remove
			while (answer.erase_one(b2.display(i)) == true){} // erase one unil there is no more left 
		return answer;										 // (I tried just using erase from the bag class but it didn't always work)
	}

	set::value_type set::display(const value_type& item) const{
		int x;
		x = data[item];
		return x;
	}
}