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
} arr;

// allocates a new array structure onto the heap
arr * l_arr_init(int init_s, int blk_s) {
  assert(init_s >= 0);
  assert(blk_s > 0); // block size cant be 0!

  arr *arr_m_ptr = (arr *) malloc(3 * sizeof(size_t) + 1 * sizeof(arr_type));
  arr_m_ptr->blk_s = blk_s;
  arr_m_ptr->s = 0;
  arr_m_ptr->alloc = blk_s * ((init_s / blk_s) + 1);
  arr_m_ptr->b = (arr_type *) malloc(arr_m_ptr->alloc * sizeof(arr_type));

  return arr_m_ptr;
}

// resizes based on how many elements are being added
static void l_arr_resize(arr *arr_ptr, int ele) {
  if (arr_ptr->s + ele > arr_ptr->alloc) {
    arr_ptr->alloc = ((arr_ptr->alloc + ele) / arr_ptr->blk_s + 1) * arr_ptr->blk_s;
    arr_ptr->b = realloc(
      arr_ptr->b,
      arr_ptr->alloc
    );
  }
}

arr * l_arr_push(arr *arr_ptr, arr_type t) {
  l_arr_resize(arr_ptr, 1);
  arr_ptr->s = arr_ptr->s + 1;
  *(arr_ptr->b + arr_ptr->s - 1) = t;
  return arr_ptr;
}

arr_type l_arr_get(arr *arr_ptr, int i) {
  assert(i < arr_ptr->s);
  return *(arr_ptr->b + i);
}

void l_arr_free(arr *arr_ptr) {
  free(arr_ptr->b);
  free(arr_ptr);
}

#endif
