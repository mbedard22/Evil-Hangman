#include <stdio.h>
#include "unit_test.h"

int main(int argc, char* argv[]){

  Status (*tests[])(char*, int) =
    {
	    test_init_default_returns_nonNULL,
 	    test_get_size_on_init_default_returns_0,
	    test_mbedard_get_capacity_on_init_default_returns_7,
	    test_mbedard_my_string_destroy_sets_handle_to_NULL,
    	    test_mbedard_my_string_extraction_changes_capacity,
	    test_mbedard_init_c_string_sets_capacity_plus_one,
	    test_mbedard_get_size_returns_size,
            test_mbedard_get_capacity_returns_capacity,
	    test_mbedard_string_compare_returns_prefix_smaller,
	    test_mbedard_string_compare_returns_0_if_same,
	    test_mbedard_string_insertion_writes_string,
	    test_mbedard_push_back_adds_char,
	    test_mbedard_push_back_resize_successful,
	    test_mbedard_pop_back_removes_char,
	    test_mbedard_pop_back_does_not_resize,
	    test_mbedard_pop_back_returns_failure_if_string_is_empty,
	    test_mbedard_my_string_at_returns_address,
	    test_mbedard_my_string_at_returns_null_if_out_of_bounds,
	    test_mbedard_my_string_c_str_returns_address_first_element,
	    test_mbedard_my_string_c_str_returns_valid_c_string,
	    test_mbedard_my_string_concat_doesnt_change_hAppend,
	    test_mbedard_my_string_concat_resize_succesful,
	    test_mbedard_my_string_concat_works_correctly,
	    test_mbedard_my_string_c_str_does_not_count_null_in_size,
	    test_mbedard_my_string_empty_returns_correctly
    };

  int number_of_functions = sizeof(tests)/sizeof(tests[0]);
  int i;
  char buffer[500];
  int success_count=0;
  int failure_count=0;

  for(i=0; i<number_of_functions; i++){
    if(tests[i](buffer, 500) == FAILURE){
	printf("FAILED: Test %d failed miserably\n", i);
	printf("\t%s\n", buffer);
	failure_count++;
    }
    else {
      printf("PASS: Test %d passed\n", i);
      printf("\t%s\n", buffer);
      success_count++;
    }

  }

  printf("Total number of tests: %d\n", number_of_functions);
  printf("%d/%d Pass, %d/%d Failure\n", success_count, number_of_functions, failure_count, number_of_functions);
  return 0;
}
