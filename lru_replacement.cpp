/**
 * Assignment 5: Page replacement algorithms
 * @file lru_replacement.cpp
 * @author Rusty Dillard
 * @brief A class implementing the LRU page replacement algorithms
 * @version 0.1
 */

#include "lru_replacement.h"

// Constructor
LRUReplacement::LRUReplacement(int num_pages, int num_frames) : Replacement(num_pages, num_frames) { }

// Destructor
// - Nothing to do here
LRUReplacement::~LRUReplacement() {}

// Accesss a page already in physical memory
void LRUReplacement::touch_page(int page_num)
{
    // remove the selected page from the page table
    page_queue.erase(ma[page_num]);
    // push the page to the front of the list
    page_queue.push_front(page_num);
    // save the index of the page in the list to the map
    ma[page_num] = page_queue.begin();
    // set the page to dirty
    page_table[page_num].dirty = true;
}

// Access an invalid page, but free frames are available.
void LRUReplacement::load_page(int page_num)
{
    // push it to the front of the list
    page_queue.push_front(page_num);
    // save the index of the page in the list to the map
    ma[page_num] = page_queue.begin();
    // assign the frame to the page
    page_table[page_num].frame_num = frame_index++;
    // set the page to valid
    page_table[page_num].valid = true;
    // decrement the number of free frames
    num_frames--;
}

// Access an invalid page and no free frames are available
int LRUReplacement::replace_page(int page_num)
{
    // get the lru page
    int last = page_queue.back(); 
    // remove the lru page from the list
    page_queue.pop_back();

    // set the lru page to invalid
    page_table[last].valid = false;
    // set the new page to valid
    page_table[page_num].valid = true; 
    // assign the new page frame to the lru page frame
    page_table[page_num].frame_num = page_table[last].frame_num;
    
    // remove the lru page from the map
    ma.erase(last);
    // put the new page at the front of the list
    page_queue.push_front(page_num);
    // save the page position in the list for quick access later
    ma[page_num] = page_queue.begin();

    return 0;
}