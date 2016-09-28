/***************************************************************************
*
*  	Filename: circbuf.h
*	Description: Header file for circbuf.c
*                    
*       Author: Kathy Grimes 
*               
*       
****************************************************************************/
#ifndef _CIRCBUF_H
#define _CIRCBUF_H

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>


/* Structures,enums, and defines section
  ***************************************************************************/
//Circular Buffer structure
typedef struct CircBuf {
  void * buffer;    // Beginning of buffer in memory
  void * head;      // Pointer to oldest element
  void * tail;      // Pointer to newest element
  size_t size;      // Size of the buffer
  size_t item_size; // Size of each item (bytes)
  size_t num_items; // Current number of items
} CircBuf_t;

//Enum for current state of circular buffer
typedef enum {
  ERROR,
  PARTFULL_BUF,
  EMPTY_BUF,
  FULL_BUF
} circbuf_state;


/* Function prototype Section
 * Add protoypes for all functions called by this module, with the exception
 * of runtime routines.
 ***************************************************************************/
// Buffer full with a return
uint8_t buffer_full(CircBuf *cb);


// Buffer empty with a return
uint8_t buffer_empty(CircBuf *cb);
   

// Add item to buffer
// Should error on overfill and should wrap around
uint8_t buffer_add(CircBuf *cb, void *item);


// Remove item from buffer
// Should error on empty
uint8_t buffer_remove(CircBuf *cb);


//Current Buffer State
uint8_t buffer_state(CircBuf *cb);

#endif
