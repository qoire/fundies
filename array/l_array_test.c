#include "../testing/minunit.h"
#include "l_array.h"

MU_TEST(test_array_init) {
  // do nothing for now
  arr *arr_ptr = l_arr_init(1, 16);
  printf("arr_ptr\nblk_size=%d\nsize=%d\nalloc=%d",
    arr_ptr->blk_s,
    arr_ptr->s,
    arr_ptr->alloc);
}

MU_TEST_SUITE(test_suite) {
  MU_RUN_TEST(test_array_init);
}

int main(int argc, char *argv[]) {
  MU_RUN_SUITE(test_suite);
  MU_REPORT();
  return 0;
}
