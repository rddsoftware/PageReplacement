/**
 * Assignment 5: Page replacement algorithms
 * @file replacement.cpp
 * @author Rusty Dillard
 * @brief A base class for different page replacement algorithms.
 * @version 0.1
 */
#include <iostream>
#include "replacement.h"

using namespace std;

// Constructor
Replacement::Replacement(int num_pages, int num_frames) : page_table(num_pages, num_frames)
{
    // Construct the page table with a given number of pages
    page_table = PageTable(num_pages, num_frames);
    // Initialize the member variables
    this->frame_index = 0;
    this->frame_capacity = num_frames;
    this->num_pages = num_pages;
    this->num_frames = num_frames;
}

//  Destructor
//  - Nothing to do here
Replacement::~Replacement() { }

// Simulate a single page access 
// @return true if it's a page fault
bool Replacement::access_page(int page_num, bool is_write)
{
    PageEntry page; // page being accessed
    num_page_references++; // increment # of references

    // If the page number is valid, it calls the touch_page function.
    if(page_num < num_pages)
    {
        page = getPageEntry(page_num);
    }

    // If the page number is invalid, it calls the touch_page function.
    else
    {
        // Wont ever get here just had this for assurance
        cerr << "Invalid page number\n";
        return false;
    }

    // If the page is valid, it calls the touch_page function. 
    if(page.valid)
    {
        touch_page(page_num);
    }

    // If the page is not valid but free frames are available, it calls the load_page function.
    else if(num_frames > 0)
    {
        load_page(page_num);
        num_page_faults++;
        return true;
    }

    // If the page is not valid and there is no free frame, it calls the replace_page function.
    else
    {
        replace_page(page_num);
        num_page_faults++;
        num_page_replacements++;
        return true;
    }
    return false;
}

// Print out statistics of simulation
void Replacement::print_statistics() const {
        // print out the number of references, number of page faults and number of page replacements
		cout << "Number of references: \t\t"  << num_page_references << endl;
		cout << "Number of page faults: \t\t" << num_page_faults << endl;
		cout << "Number of page replacements: \t"  << num_page_replacements << endl;
}