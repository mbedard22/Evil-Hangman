#ifndef UNIT_TEST_H
#define UNIT_TEST_H
#include "my_string.h"

Status test_init_default_returns_nonNULL(char* buffer, int length);

Status test_get_size_on_init_default_returns_0(char* buffer, int length);

Status test_mbedard_get_capacity_on_init_default_returns_7(char* buffer, int length);

Status test_mbedard_my_string_destroy_sets_handle_to_NULL(char* buffer, int length);

Status test_mbedard_my_string_extraction_changes_capacity(char* buffer, int length);

Status test_mbedard_init_c_string_sets_capacity_plus_one(char* buffer, int length);

Status test_mbedard_get_size_returns_size(char* buffer, int length);

Status test_mbedard_get_capacity_returns_capacity(char* buffer, int length);

Status test_mbedard_string_compare_returns_prefix_smaller(char* buffer, int length);

Status test_mbedard_string_compare_returns_0_if_same(char* buffer, int length);

Status test_mbedard_string_insertion_writes_string(char* buffer, int length);

Status test_mbedard_push_back_adds_char(char* buffer, int length);

Status test_mbedard_push_back_resize_successful(char* buffer, int length);

Status test_mbedard_pop_back_removes_char(char* buffer, int length);

Status test_mbedard_pop_back_does_not_resize(char* buffer, int length);

Status test_mbedard_pop_back_returns_failure_if_string_is_empty(char* buffer, int length);

Status test_mbedard_my_string_at_returns_address(char* buffer, int length);

Status test_mbedard_my_string_at_returns_null_if_out_of_bounds(char* buffer, int length);

Status test_mbedard_my_string_c_str_returns_address_first_element(char* buffer, int length);

Status test_mbedard_my_string_c_str_returns_valid_c_string(char* buffer, int length);

Status test_mbedard_my_string_concat_doesnt_change_hAppend(char* buffer, int length);

Status test_mbedard_my_string_concat_resize_succesful(char* buffer, int length);

Status test_mbedard_my_string_concat_works_correctly(char* buffer, int length);

Status test_mbedard_my_string_c_str_does_not_count_null_in_size(char* buffer, int length);

Status test_mbedard_my_string_empty_returns_correctly(char* buffer, int length);

#endif
