/***************************************************************************
*
*  	Filename: circbuf.c
*	Description: Hwk 3 Problem 5
*                    Circular buffer data structure that operates on
*                    8 bit unsigned items
*                    
*       Author: Kathy Grimes 
*               
*       
****************************************************************************/


#include "circbuf.h"

// Buffer full with a return of 1 if full
uint8_t buffer_full(CircBuf *cb) {
  if (cb->num_items == cb->size) {
    return 1;
  }
  return 0;
}


// Buffer empty with a return of 1 if empty
uint8_t buffer_empty(CircBuf *cb){
  if (cb->num_items == 0) {
    return 1;
  }
  return 0;
}
   

// Add item to buffer
// Should error (return 1) on overfill and should wrap around
uint8_t buffer_add(CircBuf *cb, void *item){
  if (buffer_state(cb)==FULL_BUF) {
    //circular buffer is full so ERROR
    return 1;
  } //if the newest element is at the end of the buffer (buffer + size), wrap
  else if (cb->tail == cb->buffer + cb->size) {
    cb->tail = cb->buffer;
  } else {
    cb->tail = cb->tail + 1;
  }
  *(cb->tail) = item;
  cb->num_items = cb->num_items + 1;
  return 0;
}


// Remove item from buffer
// Should error on empty
uint8_t buffer_remove(CircBuf *cb){
  if (buffer_state(cb)==EMPTY_BUF) {
    //circular buffer is empty so ERROR
    return 1;
  } //if the oldest element is at the beginning of the buffer (buffer), wrap
  else if (cb->head == cb->buffer) {
    cb->head = cb->buffer + size;
  } else {
    cb->head = cb->head - 1;
  }
  //assign the deleted
  *(cb->head) = '\0';
  cb->num_items = cb->num_items - 1;
  return 0;
}



circbuf_state buffer_state(CircBuf *cb){

  if (buffer_full(cb)) {
    return FULL_BUF;
  } else if (buffer_empty(cb)) {
    return EMPTY_BUF;
  } else {
    return PARTFULL_BUF;
  }
}
