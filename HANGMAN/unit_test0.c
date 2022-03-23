#include <stdio.h>
#include "unit_test.h"
int main(int argc, char* argv[])
{
  Status (*tests[])(char*, int) =
    {
      test_init_default_returns_nonNULL,
      test_get_size_on_init_default_returns_0,

      test_akumar1_get_capacity_on_init_default_returns_7,

      test_akumar1_destroy_is_NULL,

      test_akumar1_init_c_string_returns_nonNULL,
      test_akumar1_get_size_on_init_c_string_returns_7,
      test_akumar1_get_capacity_on_init_c_string_returns_8,

      test_akumar1_compare_same_strings_return_0,
      test_akumar1_compare_app_is_less_than_apple,
      test_akumar1_compare_apple_is_greater_than_app,

      test_akumar1_extraction_updates_capacity,

      test_akumar1_insertion_prints_string,

      test_akumar1_push_back_updates_size,
      test_akumar1_push_back_updates_capaciy,

      test_akumar1_pop_back_updates_size,
      test_akumar1_pop_back_does_not_update_capacity,
      test_akumar1_pop_back_fails_on_empty_string,
      
      test_akumar1_at_returns_NULL,

      test_akumar1_c_str_is_NULL_terminated,
      test_akumar1_c_str_returns_nonNULL,

      test_akumar1_concat_combines_strings,
      test_akumar1_get_size_on_concat_returns_9,
      test_akumar1_get_capacity_on_concat_returns_10,

      test_akumar1_empty_returns_true,
      test_akumar1_empty_returns_false
    };
  int number_of_functions = sizeof(tests) / sizeof(tests[0]);
  int i;
  char buffer[500];
  int success_count = 0;
  int failure_count = 0;
  for(i=0; i<number_of_functions; i++)
  {
    if(tests[i](buffer, 500) == FAILURE)
    {
      printf("FAILED: Test %d failed miserably\n", i);
      printf("\t%s\n", buffer);
      failure_count++;
    }
    else
    {
      // printf("PASS: Test %d passed\n", i);
      // printf("\t%s\n", buffer);
      success_count++;
    }
  }
  printf("Total number of tests: %d\n", number_of_functions);
  printf("%d/%d Pass, %d/%d Failure\n", success_count, number_of_functions, failure_count, number_of_functions);
  return 0;
}
