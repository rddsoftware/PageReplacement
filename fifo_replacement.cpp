/**
 * Assignment 5: Page replacement algorithms
 * @file fifo_replacement.cpp
 * @author Rusty Dillard
 * @brief A class implementing the FIFO page replacement algorithms
 * @version 0.1
 */

#include "fifo_replacement.h"
#include <iostream>

// Add your implementation here
FIFOReplacement::FIFOReplacement(int num_pages, int num_frames) : Replacement(num_pages, num_frames)
{
    // additional implementation code
    frame_page_index = std::vector<int>(num_frames);
    fifo_frame = 0;
}

// Add your implementations for desctructor, load_page, replace_page here
FIFOReplacement::~FIFOReplacement() {}

// Access an invalid page, but free frames are available
void FIFOReplacement::load_page(int page_num)
{
    // Update your data structure LRU replacement and pagetable
    // add new page to the frame to page table
    frame_page_index[frame_index] = page_num;
    // set the new page to the next available frame
    page_table[page_num].frame_num = frame_index++;
    // set the new page to valid
    page_table[page_num].valid = true;
    // reduce the number of available free frames
    num_frames--;
}

// Access an invalid page and no free frames are available
int FIFOReplacement::replace_page(int page_num)
{
    // Update your data structure LRU replacement and pagetable
    // set the old page to invalid
    page_table[frame_page_index[fifo_frame]].valid = false;
    // add the new frame to the frame to page table
    frame_page_index[fifo_frame] = page_num;
    // set the new page to the next frame to be replaced
    page_table[page_num].frame_num = fifo_frame++; 
    // set the new page to valid
    page_table[page_num].valid = true;

    // If the fifo frame index reaches the end, set it back to the beginning
    if (fifo_frame == frame_capacity)
    {
        fifo_frame = 0;
    }
    return 0;
}