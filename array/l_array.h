#ifndef __L_ARRAY_H__
#define __L_ARRAY_H__

#include <stdlib.h>
#include <assert.h>

// define array type
typedef int arr_type;

typedef struct l_arr {
  size_t blk_s; // block size of the array
  size_t s; // size of the array
  size_t alloc; // allocated size of the array
  arr_type *b; // beginning of the logical array
  arr_type *e;
} arr;

// allocates a new array structure onto the heap
arr * l_arr_init(int init_s, int blk_s) {
  assert(init_s >= 0);
  assert(blk_s > 0); // block size cant be 0!

  arr *arr_m_ptr = (arr *) malloc(3 * sizeof(size_t) + 2 * sizeof(arr_type));
  arr_m_ptr->blk_s = blk_s;
  arr_m_ptr->s = 0;
  arr_m_ptr->alloc = blk_s * ((init_s / blk_s) + 1);
  arr_m_ptr->b = (arr_type *) malloc(arr_m_ptr->alloc * sizeof(arr_type));
  arr_m_ptr->e = arr_m_ptr->b;

  return arr_m_ptr;
}

arr * push(arr *arr_ptr, arr_type t) {
  arr_ptr->e = arr_ptr->e + 1;
  *arr_ptr->e = t;
}

#endif
