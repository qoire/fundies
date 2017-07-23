#include "../testing/minunit.h"
#include "l_array.h"

MU_TEST(test_array_init) {
  // do nothing for now
  arr *arr_ptr = l_arr_init(1, 16);
  printf("test_array_init:\n");
  printf("arr_ptr\nblk_size=%d\nsize=%d\nalloc=%d\n",
    arr_ptr->blk_s,
    arr_ptr->s,
    arr_ptr->alloc);

  l_arr_free(arr_ptr);
}

MU_TEST(test_array_push) {
  arr *arr_ptr = l_arr_init(1, 1);

  printf("test_array_push:\n");
  printf("arr_ptr\nblk_size=%d\nsize=%d\nalloc=%d\n",
    arr_ptr->blk_s,
    arr_ptr->s,
    arr_ptr->alloc);

  l_arr_push(arr_ptr, 1337);
  int resp = l_arr_get(arr_ptr, 0);
  printf("l_arr_get(0)=%d\n", resp);
  
  l_arr_free(arr_ptr);
}

MU_TEST_SUITE(test_suite) {
  MU_RUN_TEST(test_array_init);
  MU_RUN_TEST(test_array_push);
}

int main(int argc, char *argv[]) {
  MU_RUN_SUITE(test_suite);
  MU_REPORT();
  return 0;
}
