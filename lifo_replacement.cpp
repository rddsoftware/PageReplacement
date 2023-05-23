/**
 * Assignment 5: Page replacement algorithms
 * @file lifo_replacement.cpp
 * @author Rusty Dillard
 * @brief A class implementing the LIFO page replacement algorithms
 * @version 0.1
 */

#include "lifo_replacement.h"

// Constructor
LIFOReplacement::LIFOReplacement(int num_pages, int num_frames) : Replacement(num_pages, num_frames)
{
    // initialize the last page to 0
    last_page = 0;
}

// Destructor
// - Nothing to do here
LIFOReplacement::~LIFOReplacement() { }

// Access an invalid page, but free frames are available
void LIFOReplacement::load_page(int page_num)
{
    // Update your data structure LRU replacement and pagetable
    // set the new page to the next available frame
    page_table[page_num].frame_num = frame_index++;
    // set the new page to valid
    page_table[page_num].valid = true;
    // set the last in page to the new page
    last_page = page_num;
    // decrement the amount of available free frames
    num_frames--;
}

// Access an invalid page and no free frames are available
int LIFOReplacement::replace_page(int page_num) {
    page_table[last_page].valid = false; // set the old page to invalid
    // set the new page to the frame that the last in frame had
    page_table[page_num].frame_num = page_table[last_page].frame_num;
    // set new page to valid
    page_table[page_num].valid = true;
    // set last in page to the new page
    last_page = page_num;

    return 0;
}