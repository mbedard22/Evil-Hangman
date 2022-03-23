#include <stdio.h>
#include <string.h>
#include "unit_test.h"

Status test_init_default_returns_nonNULL(char* buffer, int length)
{
  MY_STRING hString = NULL;
  hString = my_string_init_default();
  if(hString == NULL)
  {
    my_string_destroy(&hString);
    strncpy(buffer, "test_init_default_returns_nonNULL\n"
	    "my_string_init_default returns NULL", length);
    return FAILURE;
  }
  else
  {
    my_string_destroy(&hString);
    strncpy(buffer, "\ttest_init_default_returns_nonNULL\n", length);
    return SUCCESS;
  }
}

Status test_get_size_on_init_default_returns_0(char* buffer, int length)
{
  MY_STRING hString = NULL;
  Status status;
  hString = my_string_init_default();
  if(my_string_get_size(hString) != 0)
  {
    status = FAILURE;
    printf("Expected a size of 0 but got %d\n", my_string_get_size(hString));
    strncpy(buffer, "test_get_size_on_init_default_returns_0\n"
	    "Did not receive 0 from get_size after init_default\n", length);
  }
  else
  {
    status = SUCCESS;
    strncpy(buffer, "test_get_size_on_init_default_returns_0\n"
	    , length);
  }
  my_string_destroy(&hString);
  return status;
}

Status test_akumar1_get_capacity_on_init_default_returns_7(char* buffer, int length)
{
  MY_STRING hString = NULL;
  Status status;
  hString = my_string_init_default();
  int capacity = my_string_get_capacity(hString);
  
  if(capacity != 7)
  {
    status = FAILURE;
    printf("Expected a capacity of 7 but got %d\n", capacity);
    strncpy(buffer, "test_akumar1_get_capacity_on_init_default_returns_7\n"
	    "Did not receive 7 from get_capacity after init_default\n", length);
  }
  else
  {
    status = SUCCESS;
    strncpy(buffer, "test_akumar1_get_capacity_on_init_default_returns_7\n", length);
  }
  my_string_destroy(&hString);
  return status;
}

Status test_akumar1_destroy_is_NULL(char* buffer, int length)
{
  MY_STRING hString = NULL;
  Status status;

  hString = my_string_init_default();

  my_string_destroy(&hString);

  if (hString != NULL)
  {
    status = FAILURE;
    strncpy(buffer, "test_akumar1_destroy_is_NULL\n"
	    "destroy did not make the handle NULL\n", length);
  }
  else
  {
    status = SUCCESS;
    strncpy(buffer, "test_akumar1_destroy_is_NULL\n", length);
  }
  return status;
}

Status test_akumar1_init_c_string_returns_nonNULL(char* buffer, int length)
{
  MY_STRING hString = NULL;
  Status status;

  hString = my_string_init_c_string("Avinash");
	
  if(hString == NULL)
  {
    status = FAILURE;
    strncpy(buffer, "test_akumar1_init_c_string_returns_nonNULL\n"
	    "my_string_init_c_string returns NULL", length);
  }
  else
  {
    status = SUCCESS;
    strncpy(buffer, "test_akumar1_init_c_string_returns_nonNULL\n",  length);
  }
  my_string_destroy(&hString);
  return status;
}

Status test_akumar1_get_size_on_init_c_string_returns_7(char* buffer, int length)
{
  MY_STRING hString = NULL;
  Status status;
  
  hString = my_string_init_c_string("Avinash");
  int size = my_string_get_size(hString);
  
  if(size != 7)
  {
    status = FAILURE;
    printf("Expected a size of 7, but got %d\n", size);
    strncpy(buffer, "test_akumar1_get_size_on_init_c_string_returns_7\n"
	    "Did not return 7 from get_size after init_c_string\n", length);
  }
  else
  {
    status = SUCCESS;
    strncpy(buffer, "test_akumar1_get_size_on_init_c_string_returns_7\n",  length);
  }
  my_string_destroy(&hString);
  return status;
}

Status test_akumar1_get_capacity_on_init_c_string_returns_8(char* buffer, int length)
{
  MY_STRING hString = NULL;
  Status status;

  hString = my_string_init_c_string("Avinash");
  int capacity = my_string_get_capacity(hString);

  if(capacity != 8)
  {
    status = FAILURE;
    printf("Expected a capacity of 8, but got %d\n", capacity);
    strncpy(buffer, "test_akumar1_get_capacity_on_init_c_string_returns_7\n"
            "Did not return 8 from get_capacity after init_c_string\n", length);
  }
  else
  {
    status = SUCCESS;
    strncpy(buffer, "test_akumar1_get_size_on_init_c_string_returns_7\n",  length);
  }
  my_string_destroy(&hString);
  return status;
}

Status test_akumar1_compare_same_strings_return_0(char* buffer, int length)
{
  MY_STRING hString1 = NULL;
  MY_STRING hString2 = NULL;
  Status status;

  hString1 = my_string_init_c_string("Avinash");
  hString2 = my_string_init_c_string("Avinash");

  int compare_test = my_string_compare(hString1, hString2);

  if (compare_test != 0)
  {
    status = FAILURE;
    printf("Expected comparison to return 0, got %d instead", compare_test);
    strncpy(buffer, "test_akumar1_compare_same_strings_returns_0\n"
	    "Did not return 0 from compare when comparing the same string\n", length);
  }
  else
  {
    status = SUCCESS;
    strncpy(buffer, "test_akumar1_compare_same_strings_returns_0\n", length);
  }

  my_string_destroy(&hString1);
  my_string_destroy(&hString2);
  return status;
}

Status test_akumar1_compare_app_is_less_than_apple(char* buffer, int length)
{
  MY_STRING hString1 = NULL;
  MY_STRING hString2 = NULL;
  Status status;

  hString1 = my_string_init_c_string("app");
  hString2 = my_string_init_c_string("apple");

  int compare_test = my_string_compare(hString1, hString2);

  if (compare_test >= 0)
  {
    status = FAILURE;
    printf("Expected comparison to return a negative value, got %d instead", compare_test);
    strncpy(buffer, "test_akumar1_compare_app_is_less_than_apple\n"
            "Did not return a negative value from compare when comparing prefix to entire word\n", length);
  }
  else
  {
    status = SUCCESS;
    strncpy(buffer, "test_akumar1_compare_app_is_less_than_apple\n", length);
  }

  my_string_destroy(&hString1);
  my_string_destroy(&hString2);
  return status;
}

Status test_akumar1_compare_apple_is_greater_than_app(char* buffer, int length)
{
  MY_STRING hString1 = NULL;
  MY_STRING hString2 = NULL;
  Status status;

  hString1 = my_string_init_c_string("app");
  hString2 = my_string_init_c_string("apple");

  int compare_test = my_string_compare(hString2, hString1);

  if (compare_test <= 0)
  {
    status = FAILURE;
    printf("Expected comparison to return a positive value, got %d instead", compare_test);
    strncpy(buffer, "test_akumar1_compare_apple_is_greater_than_app\n"
            "Did not return a positive value from compare when comparing entire word to prefix\n", length);
  }
  else
  {
    status = SUCCESS;
    strncpy(buffer, "test_akumar1_compare_apple_is_greater_than_app\n", length);
  }

  my_string_destroy(&hString1);
  my_string_destroy(&hString2);
  return status;
}

Status test_akumar1_extraction_updates_capacity(char* buffer, int length)
{
  MY_STRING hMy_string = NULL;
  FILE* fp;
  Status status;

  hMy_string = my_string_init_default();
  fp = fopen("dictionary.txt", "r");

  while (my_string_get_size(hMy_string) != 5)
  {
    my_string_extraction(hMy_string, fp);
  }
  
  int capacity = my_string_get_capacity(hMy_string);
  
  if(capacity < 5)
  {
    status = FAILURE;
    printf("Expected a capacity larger than or equal to the size, but got %d\n", capacity);
    strncpy(buffer, "test_akumar1_extraction_updates_capacity\n"
            "Did not return update capacity after extracting with my_string_extraction\n", length);
  }
  else
  {
    status = SUCCESS;
    strncpy(buffer, "test_akumar1_extraction_updates_capacity\n",  length);
  }
  
  my_string_destroy(&hMy_string);

  fclose(fp);
  fp = NULL;

  return status;
}

Status test_akumar1_insertion_prints_string(char* buffer, int length)
{
  MY_STRING hString = NULL;
  Status status;

  hString = my_string_init_c_string("Hello");

  if(!my_string_insertion(hString, stdout))
  {
    status = FAILURE;
    printf("Insertion did not print string\n");
    strncpy(buffer, "test_akumar1_insertion_prints_string\n"
	    "Insertion did not return SUCCESS when trying to print string\n", length);
  }
  else
  {
    status = SUCCESS;
    strncpy(buffer, "test_akumar1_insertion_prints_string\n",  length);
  }
  my_string_destroy(&hString);
  return status;
}

Status test_akumar1_push_back_updates_size(char* buffer, int length)
{
  MY_STRING hString = NULL;
  Status status;

  hString = my_string_init_c_string("Hello");
  my_string_push_back(hString, 'w');

  int size = my_string_get_size(hString);
	
  if(size != 6)
  {
    status = FAILURE;
    printf("Expected a size of 6, but got %d\n", size);
    strncpy(buffer, "test_akumar1_push_back_updates_size\n"
	    "Did not update size to 6 from get_size after push\n", length);
  }
  else
  {
    status = SUCCESS;
    strncpy(buffer, "test_akumar1_push_back_updates_size\n",  length);
  }
  my_string_destroy(&hString);
  return status;
}

Status test_akumar1_push_back_updates_capaciy(char* buffer, int length)
{
  MY_STRING hString = NULL;
  Status status;

  hString = my_string_init_c_string("Hello");
  my_string_push_back(hString, 'w');

  int capacity = my_string_get_capacity(hString);

  if(capacity < 6)
  {
    status = FAILURE;
    printf("Expected a capacity greater than or equal to 6, but got %d\n", capacity);
    strncpy(buffer, "test_akumar1_push_back_updates_capcity\n"
            "Did not update capcity to 6 from get_size after push\n", length);
  }
  else
  {
    status = SUCCESS;
    strncpy(buffer, "test_akumar1_push_back_updates_capacity\n",  length);
  }
  my_string_destroy(&hString);
  return status;
}

Status test_akumar1_pop_back_updates_size(char* buffer, int length)
{
  MY_STRING hString = NULL;
  Status status;

  hString = my_string_init_c_string("Hello");
  my_string_pop_back(hString);

  int size = my_string_get_size(hString);

  if(size != 4)
  {
    status = FAILURE;
    printf("Expected a size of 4, but got %d\n", size);
    strncpy(buffer, "test_akumar1_pop_back_updates_size\n"
            "Did not update size to 4 from get_size after pop back\n", length);
  }
  else
  {
    status = SUCCESS;
    strncpy(buffer, "test_akumar1_pop_back_updates_size\n",  length);
  }
  my_string_destroy(&hString);
  return status;
}

Status test_akumar1_pop_back_does_not_update_capacity(char* buffer, int length)
{
  MY_STRING hString = NULL;
  Status status;

  hString = my_string_init_c_string("Hello");
  int capacity1 = my_string_get_capacity(hString);
  
  my_string_pop_back(hString);

  int capacity2 = my_string_get_capacity(hString);

  if(capacity1 != capacity2)
  {
    status = FAILURE;
    printf("Expected the capacity to remain the same, instead it increased by %d\n", capacity2 - capacity1);
    strncpy(buffer, "test_akumar1_pop_back_does_not_update_capacity\n"
            "Updated capacity after pop back\n", length);
  }
  else
  {
    status = SUCCESS;
    strncpy(buffer, "test_akumar1_pop_back_does_not_update_capacity\n",  length);
  }
  my_string_destroy(&hString);
  return status;
}

Status test_akumar1_pop_back_fails_on_empty_string(char* buffer, int length)
{
  MY_STRING hString = NULL;
  Status status;
	
  hString = my_string_init_default();
		
  if(my_string_pop_back(hString))
  {
    status = FAILURE;
    printf("Pop back did not return FAILURE\n");
    strncpy(buffer, "test_akumar1_pop_back_fails_on_empty_string\n"
	    "pop_back did not return FAILURE when given an empty string\n", length);
  }
  else
  {
    status = SUCCESS;
    strncpy(buffer, "test_akumar1_pop_back_fails_on_empty_string\n",  length);
  }
  my_string_destroy(&hString);
  return status;
}

Status test_akumar1_at_returns_NULL(char* buffer, int length)
{
  MY_STRING hString = NULL;
  Status status;
  
  hString = my_string_init_c_string("hello");
  if (my_string_at(hString, 10) != NULL)
  {
    status = FAILURE;
    strncpy(buffer, "test_akumar1_at_returns_NULL\n"
	    "Did not return NULL when index was out of bounds\n", length);
  }
  else
  {
    status = SUCCESS;
    strncpy(buffer, "test_akumar1_at_returns_NULL\n", length);
  }
  my_string_destroy(&hString);
  return status;
}

Status test_akumar1_c_str_is_NULL_terminated(char* buffer, int length)
{
  MY_STRING hString = NULL;
  Status status;

  hString = my_string_init_c_string("hello");

  char c = my_string_c_str(hString)[5];

  if (c != '\0')
  {
    status = FAILURE;
    printf("Expected a NULL terminator, got '%c' instead\n", c);
    strncpy(buffer, "test_akumar1_c_str_is_NULL_terminated\n"
	    "Did not return a null terminator from my_string_c_str\n", length);
  }
  else
  {
    status = SUCCESS;
    strncpy(buffer, "test_akumar1_c_str_is_NULL_terminated\n", length);
  }
  my_string_destroy(&hString);
  return status;
}

Status test_akumar1_c_str_returns_nonNULL(char* buffer, int length)
{
  MY_STRING hString = NULL;
  Status status;

  hString = my_string_init_c_string("hello");

  if (my_string_c_str(hString) == NULL)
  {
    status = FAILURE;
    strncpy(buffer, "test_akumar1_c_str_returns_nonNULL\n"
            "my_string_c_str returns NULL\n", length);
  }
  else
  {
    status = SUCCESS;
    strncpy(buffer, "test_akumar1_c_str_returns_nonNULL\n", length);
  }
  my_string_destroy(&hString);
  return status;
}

Status test_akumar1_concat_combines_strings(char* buffer, int length)
{
  MY_STRING hString1 = NULL;
  MY_STRING hString2 = NULL;
  MY_STRING hString3 = NULL;
  Status status;

  hString1 = my_string_init_c_string("blue");
  hString2 = my_string_init_c_string("berry");
  hString3 = my_string_init_c_string("blueberry");

  my_string_concat(hString1, hString2);

  int compare_test = my_string_compare(hString1, hString3);

  if (compare_test != 0)
  {
    status = FAILURE;
    strncpy(buffer, "test_akumar1_concat_combines_strings\n"
            "my_string_concat does not combine strings\n", length);
  }
  else
  {
    status = SUCCESS;
    strncpy(buffer, "test_akumar1_concat_combines_strings\n", length);
  }
  my_string_destroy(&hString1);
  my_string_destroy(&hString2);
  my_string_destroy(&hString3);
  return status;    
}

Status test_akumar1_get_size_on_concat_returns_9(char* buffer, int length)
{
  MY_STRING hString1 = NULL;
  MY_STRING hString2 = NULL;
  Status status;

  hString1 = my_string_init_c_string("blue");
  hString2 = my_string_init_c_string("berry");

  my_string_concat(hString1, hString2);
  int size = my_string_get_size(hString1);
  
  if (size != 9)
  {
    status = FAILURE;
    printf("Expected size of 9, got %d instead", size);
    strncpy(buffer, "test_akumar1_get_size_on_concat_returns_9\n"
            "Does not return size of 9 after my_string_concat\n", length);
  }
  else
  {
    status = SUCCESS;
    strncpy(buffer, "test_akumar1_get_size_on_concat_returns_9\n", length);
  }
  my_string_destroy(&hString1);
  my_string_destroy(&hString2);
  return status;
}

Status test_akumar1_get_capacity_on_concat_returns_10(char* buffer, int length)
{
  MY_STRING hString1 = NULL;
  MY_STRING hString2 = NULL;
  Status status;

  hString1 = my_string_init_c_string("blue");
  hString2 = my_string_init_c_string("berry");

  my_string_concat(hString1, hString2);
  int capacity = my_string_get_capacity(hString1);

  if (capacity < 9)
  {
    status = FAILURE;
    printf("Expected capacity greater than or equal to 9, got %d instead", capacity);
    strncpy(buffer, "test_akumar1_get_capacity_on_concat_returns_10\n"
            "Does not return capacity greater than or equal to 9  after my_string_concat\n", length);
  }
  else
  {
    status = SUCCESS;
    strncpy(buffer, "test_akumar1_get_capacity_on_concat_returns_10\n", length);
  }
  my_string_destroy(&hString1);
  my_string_destroy(&hString2);
  return status;
}

Status test_akumar1_empty_returns_true(char* buffer, int length)
{
  MY_STRING hString = NULL;
  Status status;
  
  hString = my_string_init_default();
	
  if(!my_string_empty(hString))
  {
    status = FAILURE;
    strncpy(buffer, "test_akumar1_empty_returns_true\n"
	    "my_string_empty does not returns TRUE", length);
  }
  else
  {
    status = SUCCESS;
    strncpy(buffer, "test_akumar1_empty_returns_true\n", length);
  }
  my_string_destroy(&hString);
  return status;
}

Status test_akumar1_empty_returns_false(char* buffer, int length)
{
  MY_STRING hString = NULL;
  Status status;

  hString = my_string_init_c_string("hello");

  if(my_string_empty(hString))
  {
    status = FAILURE;
    strncpy(buffer, "test_akumar1_empty_returns_false\n"
            "my_string_empty does not returns FALSE", length);
  }
  else
  {
    status = SUCCESS;
    strncpy(buffer, "test_akumar1_empty_returns_false\n", length);
  }
  my_string_destroy(&hString);
  return status;
}
