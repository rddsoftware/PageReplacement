/**
 * Assignment 5: Page replacement algorithms
 * @file pagetable.cpp
 * @author Rusty Dillard
 * @brief This class represents a traditional pagetable data structure.
 * @version 0.1
 */

#include "pagetable.h"

// Constrcutor
PageTable::PageTable(int num_pages, int num_frames)
{
	// Initialize the page table for a given number of pages
	pages = std::vector<PageEntry>(num_pages);
}

// 	Destructor
//	- Nothing to do here
PageTable::~PageTable() { }


