#include <stdio.h> 
#include "unit_test.h"
#include <string.h>

Status test_init_default_returns_nonNULL(char* buffer, int length){
	
	MY_STRING hString = NULL;
	hString = my_string_init_default();

	if(hString == NULL){
		my_string_destroy(&hString);
		strncpy(buffer,"test_init_default_returns_nonNULL\n"
				"my_string_init_default returns NULL",length);
		return FAILURE;
	}
	
	else{
		my_string_destroy(&hString);
		strncpy(buffer, "\ttest_init_default_returns_nonNULL\n", length);
		return SUCCESS;
	}
}

Status test_get_size_on_init_default_returns_0(char* buffer, int length){
	
	MY_STRING hString = NULL;
	Status status;

	hString = my_string_init_default();

	if(my_string_get_size(hString) != 0){
		status = FAILURE;
		printf("expected a size of 0 but got %d\n", my_string_get_size(hString));
		strncpy(buffer, "test_get_size_on_init_default_returns_0\n"
				"Did not receive 0 from get_size after init_default\n", length);
	}
	else{
		status = SUCCESS;
		strncpy(buffer, "test_get_size_on_init_default_returns_0\n"
				,length);
	}

	my_string_destroy(&hString);
	return status;
}

Status test_mbedard_get_capacity_on_init_default_returns_7(char* buffer, int length){

	MY_STRING hString = NULL;
	hString = my_string_init_default();
	Status status;

	if(my_string_get_capacity(hString) != 7){
		status = FAILURE;
		printf("expected a capacity of 7 but got %d\n", my_string_get_capacity(hString));
		strncpy(buffer, "test_mbedard_get_capacity_on_init_default_returns_7\n"
				"Did not receive 7 from get_capacity after init_default\n", length);
	}
	else{
		status = SUCCESS;
		strncpy(buffer, "test_mbedard_get_capacity_on_init_default_returns_7\n"
				,length);
	}
	my_string_destroy(&hString);
	return status;
}


Status test_mbedard_my_string_destroy_sets_handle_to_NULL(char* buffer, int length){

	MY_STRING hString = NULL;
	hString = my_string_init_default();
	Status status;
	my_string_destroy(&hString);
	
	if(hString != NULL){
		status = FAILURE;
		printf("hString is not null");
		strncpy(buffer, "test_mbedard_my_string_destroy_sets_handle_to_NULL\n"
				"hString is not set to NULL\n", length);
	}
	else{
		status = SUCCESS;
		strncpy(buffer, "test_mbedard_my_string_destroy_sets_handle_to_NULL\n"
				,length);
	}
	return status;
}



Status test_mbedard_my_string_extraction_changes_capacity(char* buffer, int length){
	MY_STRING hString = NULL;
	hString = my_string_init_default();
	Status status;
	FILE* fp;
	fp = fopen("simple.txt", "r");
	my_string_extraction(hString, fp);
	fclose(fp);
	if(my_string_get_capacity(hString) == 7){
		status = FAILURE;
		printf("expected capacity > 7 %d\n", my_string_get_capacity(hString));
		strncpy(buffer, "test_mbedard_my_string_extraction_changes_capacity\n"
				"my_string_extraction did not change capacity when needed\n", length);
	}
	else{
		status = SUCCESS;
		strncpy(buffer, "test_mbedard_my_string_extraction_changes_capacity\n"
				,length);
	}
	my_string_destroy(&hString);
	return status;
}
	
Status test_mbedard_init_c_string_sets_capacity_plus_one(char* buffer, int length){
	MY_STRING hString = NULL;
	hString = my_string_init_c_string("Hello");
	Status status;

	if(my_string_get_capacity(hString) != 6){
		status = FAILURE;
		printf("expected a capacity of 6 but got %d\n", my_string_get_capacity(hString));
		strncpy(buffer, "test_mbedard_init_c_string_sets_capacity_plus_one\n"
				"Did not receive 6 from get_capacity after init c string with Hello\n", length);
	}
	else{
		status = SUCCESS;
		strncpy(buffer, "test_mbedard_init_c_string_sets_capacity_plus_one\n"
				,length);
	}
	my_string_destroy(&hString);
	return status;
}

Status test_mbedard_get_size_returns_size(char* buffer, int length){
	MY_STRING hString = NULL;
	hString = my_string_init_c_string("Hello");
	Status status;

	if(my_string_get_size(hString) != 5){
		status = FAILURE;
		printf("expected a size of 5 but got %d\n", my_string_get_size(hString));
		strncpy(buffer, "test_mbedard_get_size_returns_size\n"
				"Did not receive 5 from get_size after init c string with Hello\n", length);
	}
	else{
		status = SUCCESS;
		strncpy(buffer, "test_mbedard_get_size_returns_size\n"
				,length);
	}
	my_string_destroy(&hString);
	return status;
}

Status test_mbedard_get_capacity_returns_capacity(char* buffer, int length){
	MY_STRING hString = NULL;
	hString = my_string_init_c_string("Hello");
	Status status;

	if(my_string_get_capacity(hString) != 6){
		status = FAILURE;
		printf("expected a capacity of 6 but got %d\n", my_string_get_capacity(hString));
		strncpy(buffer, "test_mbedard_get_capacity_returns_capacity\n"
				"Did not receive 6 from get_capacity after init c string with Hello\n", length);
	}
	else{
		status = SUCCESS;
		strncpy(buffer, "test_mbedard_get_capacity_returns_capacity\n"
				,length);
	}
	my_string_destroy(&hString);
	return status;
}


Status test_mbedard_string_compare_returns_prefix_smaller(char* buffer, int length){

	MY_STRING hString = my_string_init_c_string("Hello");
	MY_STRING hString2 = my_string_init_c_string("Hel");
	Status status;

	if(my_string_compare(hString,hString2) <= 0){
		status = FAILURE;
		printf("expected return greater than 0 got %d\n", my_string_compare(hString, hString2));
		strncpy(buffer, "test_mbedard_string_compare_returns_prefix_smaller\n"
				"Right string is a prefix to left and should return > 0\n", length);
	}
	else{
		status = SUCCESS;
		strncpy(buffer, "test_mbedard_string_compare_returns_prefix_smaller\n"
				,length);
	}
	my_string_destroy(&hString);
	my_string_destroy(&hString2);
	return status;
}


Status test_mbedard_string_compare_returns_0_if_same(char* buffer, int length){
	MY_STRING hString = my_string_init_c_string("Hello");
	MY_STRING hString2 = my_string_init_c_string("Hello");
	Status status;

	if(my_string_compare(hString,hString2) != 0){
		status = FAILURE;
		printf("expected 0 got  %d\n", my_string_compare(hString, hString2));
		strncpy(buffer, "test_mbedard_string_compare_returns_0_if_same\n"
				"The two strings are the same so string compare should return 0\n", length);
	}
	else{
		status = SUCCESS;
		strncpy(buffer, "test_mbedard_string_compare_returns_0_if_same\n"
				,length);
	}
	my_string_destroy(&hString);
	my_string_destroy(&hString2);
	return status;
}

Status test_mbedard_string_insertion_writes_string(char* buffer, int length){
	MY_STRING hString = my_string_init_c_string("Hello");
	Status status;
	FILE* fp = fopen("test.txt", "w");
	my_string_insertion(hString, fp);
	fclose(fp);
	MY_STRING hString2 = my_string_init_default();
	FILE* fp2 = fopen("test.txt", "r");
	my_string_extraction(hString2, fp2);
	
	if(my_string_compare(hString, hString2)!= 0){
		status = FAILURE;
		printf("expected return to be 0 got %d\n", my_string_compare(hString, hString2));
		strncpy(buffer, "test_mbedard_string_insertion_writes_string\n"
				"Strings should be the same, after string is written to file\n", length);
	}
	else{
		status = SUCCESS;
		strncpy(buffer, "test_mbedard_string_insertion_writes_string\n"
				,length);
	}
	fclose(fp2);
	my_string_destroy(&hString);
	my_string_destroy(&hString2);
	return status;
}
Status test_mbedard_push_back_adds_char(char* buffer, int length){
	MY_STRING hString = my_string_init_c_string("Hello");
	Status status;
	my_string_push_back(hString, 'o');

	if(my_string_at(hString, 5) == NULL) {
		status = FAILURE;
		printf("Should not return null if char was added properly\n");
		strncpy(buffer, "test_mbedard_push_back_adds_char\n"
				"Size should be 6 if char was added properly\n", length);
	}
	else{
		status = SUCCESS;
		strncpy(buffer, "test_mbedard_push_back_adds_char\n"
				,length);
	}
	my_string_destroy(&hString);
	return status;
}

Status test_mbedard_push_back_resize_successful(char* buffer, int length){
	MY_STRING hString = my_string_init_c_string("Hello");
	Status status;
	my_string_push_back(hString, 'o');

	if(my_string_get_capacity(hString) == 6){
		status = FAILURE;
		printf("Capacity did not change\n");
		strncpy(buffer, "test_mbedard_push_back_resize_successful\n"
				"Capacity should increase because new size would equal capacity\n", length);
	}
	else{
		status = SUCCESS;
		strncpy(buffer, "test_mbedard_push_back_resize_successful\n"
				,length);
	}
	my_string_destroy(&hString);
	return status;
}

Status test_mbedard_pop_back_removes_char(char* buffer, int length){
	MY_STRING hString = my_string_init_c_string("Hello");
	Status status;
	my_string_pop_back(hString);

	if(my_string_get_size(hString) != 4) {
		status = FAILURE;
		printf("Pop back unsuccesful\n");
		strncpy(buffer, "test_mbedard_pop_back_removes_char\n"
				"Size should be 4 after pop back\n", length);
	}
	else{
		status = SUCCESS;
		strncpy(buffer, "test_mbedard_pop_back_removes_char\n"
				,length);
	}
	my_string_destroy(&hString);
	return status;
}



Status test_mbedard_pop_back_does_not_resize(char* buffer, int length){
	MY_STRING hString = my_string_init_c_string("Hello");
	Status status;
	my_string_pop_back(hString);

	if(my_string_get_capacity(hString) < 6) {
		status = FAILURE;
		printf("Pop back made capacity smaller\n");
		strncpy(buffer, "test_mbedard_pop_back_does_not_resize\n"
				"Capacity should be atleast 6 after init c string Hello\n", length);
	}
	else{
		status = SUCCESS;
		strncpy(buffer, "test_mbedard_pop_back_does_not_resize\n"
				,length);
	}
	my_string_destroy(&hString);
	return status;

} 

Status test_mbedard_pop_back_returns_failure_if_string_is_empty(char* buffer, int length){
	MY_STRING hString = my_string_init_default();
	Status status;
	
	if(my_string_pop_back(hString) != FAILURE) {
		status = FAILURE;
		printf("pop back did not return failure\n");
		strncpy(buffer, "test_mbedard_pop_back_returns_failure_if_string_is_empty\n"
				"Pop back should return failure if passed empty string\n", length);
	}
	else{
		status = SUCCESS;
		strncpy(buffer, "test_mbedard_pop_back_returns_failure_if_string_is_empty\n"
				,length);
	}
	my_string_destroy(&hString);
	return status;


}

Status test_mbedard_my_string_at_returns_address(char* buffer, int length){
	MY_STRING hString = my_string_init_c_string("Hello");
	Status status;

	if(*my_string_at(hString, 3) != 'l') {
		status = FAILURE;
		printf("my_string_at does not return address\n");
		strncpy(buffer, "test_mbedard_my_string_at_returns_adress\n"
				"Should be able to dereference return\n", length);
	}
	else{
		status = SUCCESS;
		strncpy(buffer, "test_mbedard_my_string_at_returns_address\n"
				,length);
	}
	my_string_destroy(&hString);
	return status;


}


Status test_mbedard_my_string_at_returns_null_if_out_of_bounds(char* buffer, int length){
	MY_STRING hString = my_string_init_c_string("Hello");
	Status status;

	if(my_string_at(hString, 5) != NULL) {
		status = FAILURE;
		printf("my_string_at does not return NULL when out of bounds acces\n");
		strncpy(buffer, "test_mbedard_my_string_at_returns_null_if_out_of_bounds\n"
				"Return value should be NULL if trying to access element 5 of Hello\n", length);
	}
	else{
		status = SUCCESS;
		strncpy(buffer, "test_mbedard_my_string_at_returns_null_if_out_of_bounds\n"
				,length);
	}
	my_string_destroy(&hString);
	return status;
}


Status test_mbedard_my_string_c_str_returns_address_first_element(char* buffer, int length){
	MY_STRING hString = my_string_init_c_string("Hello");
	Status status;

	if(*my_string_c_str(hString) != 'H') {
		status = FAILURE;
		printf("my_string_c_str does not return address to first element\n");
		strncpy(buffer, "test_mbedard_my_string_c_str_returns_address_first_element\n"
				"Unable to dereference return and get char H\n", length);
	}
	else{
		status = SUCCESS;
		strncpy(buffer, "test_mbedard_my_string_c_str_returns_address_first_element\n"
				,length);
	}
	my_string_destroy(&hString);
	return status;

}

Status test_mbedard_my_string_c_str_returns_valid_c_string(char* buffer, int length){
	MY_STRING hString = my_string_init_c_string("Hello");
	Status status;

	if(my_string_c_str(hString)[5] != '\0') {
		status = FAILURE;
		printf("my_string_c_str is not a valid c str\n");
		strncpy(buffer, "test_mbedard_my_string_c_str_returns_valid_c_string\n"
				"No null terminator at proper index\n", length);
	}
	else{
		status = SUCCESS;
		strncpy(buffer, "test_mbedard_my_string_c_str_returns_valid_c_string\n"
				,length);
	}
	my_string_destroy(&hString);
	return status;


}


Status test_mbedard_my_string_concat_doesnt_change_hAppend(char* buffer, int length){
	MY_STRING hString = my_string_init_c_string("Hello");
	MY_STRING hString2 = my_string_init_c_string(" world!");

	Status status;

	my_string_concat(hString, hString2);

	if(my_string_c_str(hString2)[0] != ' ' || my_string_c_str(hString2)[6] != '!'){
		status = FAILURE;
		printf("append string changed\n");
		strncpy(buffer, "test_mbedard_my_string_concat_doesnt_change_hAppend\n"
				"The string appended on was changed after calling my_string_concat\n", length);
	}
	else{
		status = SUCCESS;
		strncpy(buffer, "test_mbedard_my_string_concat_doesnt_change_append\n"
				,length);
	}

	my_string_destroy(&hString);
	my_string_destroy(&hString2);
	return status;

}

Status test_mbedard_my_string_concat_resize_succesful(char* buffer, int length){
	MY_STRING hString = my_string_init_c_string("Hello");
	MY_STRING hString2 = my_string_init_c_string(" world!");
	
	int original_capacity = my_string_get_capacity(hString);

	Status status;

	my_string_concat(hString, hString2);

	if(my_string_get_capacity(hString) == original_capacity){
		status = FAILURE;
		printf("Resize failed\n");
		strncpy(buffer, "test_mbedard_my_string_concat_resize_succesful\n"
				"The string object capacity did not resize as needed to concatenate\n", length);
	}
	else{
		status = SUCCESS;
		strncpy(buffer, "test_mbedard_my_string_concat_resize_successful\n"
				,length);
	}

	my_string_destroy(&hString);
	my_string_destroy(&hString2);
	return status;


}

Status test_mbedard_my_string_concat_works_correctly(char* buffer, int length){
	MY_STRING hString = my_string_init_c_string("Hello");
	MY_STRING hString2 = my_string_init_c_string(" world!");
	MY_STRING hString3 = my_string_init_c_string("Hello world!");
	Status status;
	my_string_concat(hString, hString2);

	if(my_string_compare(hString, hString3) != 0){
		status = FAILURE;
		printf("concat unsuccesful\n");
		strncpy(buffer, "test_mbedard_my_string_concat_works_correctly\n"
				"my_string_concat did not correctly concatenate\n", length);
	}
	else{
		status = SUCCESS;
		strncpy(buffer, "test_mbedard_my_string_concat_works_correctly\n"
				,length);
	}

	my_string_destroy(&hString);
	my_string_destroy(&hString2);
	my_string_destroy(&hString3);
	return status;

}

Status test_mbedard_my_string_c_str_does_not_count_null_in_size(char* buffer, int length){
	MY_STRING hString = my_string_init_c_string("Hello");
	Status status;

	if(my_string_get_size(hString) == 6) {
		status = FAILURE;
		printf("size of string was %d expected 5\n", my_string_get_size(hString));
		strncpy(buffer, "test_mbedard_my_string_c_str_does_not_count_null_in_size\n"
				"Likely null terminator was added to string in object and counted in size\n", length);
	}
	else{
		status = SUCCESS;
		strncpy(buffer, "test_mbedard_my_string_c_str_does_not_count_null_in_size\n"
				,length);
	}
	my_string_destroy(&hString);
	return status;

}

Status test_mbedard_my_string_empty_returns_correctly(char* buffer, int length){
	MY_STRING hString = my_string_init_c_string("Hello");
	MY_STRING emptyString = my_string_init_default();
	Status status;

	if(my_string_empty(hString) != 0 && my_string_empty(emptyString) != 1){
		status = FAILURE;
		printf("string_empty returned incorrectly");
		strncpy(buffer, "test_mbedard_my_string_empty_returns_correctly\n"
				"Did not return 1 for empty string and 0 otherwise\n", length);
	}
	else{
		status = SUCCESS;
		strncpy(buffer, "test_mbedard_my_string_empty_returns_correctly\n"
				,length);
	}
	my_string_destroy(&hString);
	my_string_destroy(&emptyString);
	return status;


}

