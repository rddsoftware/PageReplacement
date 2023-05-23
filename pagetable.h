/**
 * Assignment 5: Page replacement algorithms
 * @file pagetable.h
 * @author Rusty Dillard
 * @brief This class represents a traditional pagetable data structure.
 * @version 0.1
 */

#pragma once

// Remember to add comments to your code
#include <vector>
using namespace std;

// A page table entry
/**
 * @brief A page table entry. This class is used to represent a page table entry.
 * @details Each page has one entry in the page table. It contains the following fields:
 * - frame number
 * - valid bit
 */
class PageEntry
{
	public:
		// Member variables
		int frame_num;
		bool valid = false;
		bool dirty = false;
};


/**
 * @brief A page table is like an array of page entries.
 * 			The size of the page table should equal to the number of pages in logical memory
 * 			(i.e. the number of pages in the process).
 * @details The page table is a vector of PageEntry objects.
 * 			The index of the vector is the page number.
 * 			The page table is initialized with all invalid entries.
 * 			The page table is responsible for allocating and deallocating frames.
 * 			The page table is also responsible for updating the valid bit and frame number
 * 			when a page is loaded into a frame.
 * 			The page table is also responsible for updating the dirty bit when a page is written.
 * 			The page table is also responsible for updating the frame number when a page is evicted.
 * 			The page table is also responsible for updating the valid bit when a page is evicted.
 */
class PageTable
{
	private:
		//  The page table data structure itself
		vector<PageEntry> pages;

	public:
		// Constructor
		PageTable(int num_pages, int num_frames);

		// Destructor
		~PageTable();

		/**
		 * @brief Access a page in the page table.
		 * @param i
		 * @return
		 * @details This function returns a reference to a page entry in the page table.
		 * 		   	It is used to access a page entry in the page table.
		 * 		   	It is also used to update a page entry in the page table.
		 * 		   	For example, to set the valid bit of page 5 to true, you can do:
		 * 		   	page_table[5].valid = true;
		 */
		PageEntry& operator [] (int i) {
			return pages[i];
		}
};
