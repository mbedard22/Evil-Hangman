#ifndef UNIT_TEST_H
#define UNIT_TEST_H
#include "my_string.h"

Status test_init_default_returns_nonNULL(char* buffer, int length);
Status test_get_size_on_init_default_returns_0(char* buffer, int length);

Status test_akumar1_get_capacity_on_init_default_returns_7(char* buffer, int length);

Status test_akumar1_destroy_is_NULL(char* buffer, int length);

Status test_akumar1_init_c_string_returns_nonNULL(char* buffer, int length);
Status test_akumar1_get_size_on_init_c_string_returns_7(char* buffer, int length);
Status test_akumar1_get_capacity_on_init_c_string_returns_8(char* buffer, int length);

Status test_akumar1_compare_same_strings_return_0(char* buffer, int length);
Status test_akumar1_compare_app_is_less_than_apple(char* buffer, int length);
Status test_akumar1_compare_apple_is_greater_than_app(char* buffer, int length);

Status test_akumar1_extraction_updates_capacity(char* buffer, int length);

Status test_akumar1_insertion_prints_string(char* buffer, int length);

Status test_akumar1_push_back_updates_size(char* buffer, int length);
Status test_akumar1_push_back_updates_capaciy(char* buffer, int length);

Status test_akumar1_pop_back_updates_size(char* buffer, int length);
Status test_akumar1_pop_back_does_not_update_capacity(char* buffer, int length);
Status test_akumar1_pop_back_fails_on_empty_string(char* buffer, int length);

Status test_akumar1_at_returns_NULL(char* buffer, int length);

Status test_akumar1_c_str_is_NULL_terminated(char* buffer, int length);
Status test_akumar1_c_str_returns_nonNULL(char* buffer, int length);

Status test_akumar1_concat_combines_strings(char* buffer, int length);
Status test_akumar1_get_size_on_concat_returns_9(char* buffer, int length);
Status test_akumar1_get_capacity_on_concat_returns_10(char* buffer, int length);

Status test_akumar1_empty_returns_true(char* buffer, int length);
Status test_akumar1_empty_returns_false(char* buffer, int length);

#endif
