#include <stdio.h>
#include <stdlib.h>
#include "my_string.h"
#include <string.h>

struct string{
	int size;
	int capacity;
	char* data;
};

typedef struct string My_string;


MY_STRING my_string_init_default(void){
	My_string* pMy_string = NULL;
	pMy_string = (My_string*)malloc(sizeof(My_string));
	if (pMy_string != NULL){
		pMy_string->size = 0;
		pMy_string->capacity = 7;
		pMy_string->data = malloc(sizeof(char)*pMy_string->capacity);
		if(pMy_string->data == NULL){
			free(pMy_string);
			return NULL;
		}
		return pMy_string;
	}
	return NULL;
}

void my_string_destroy(Item_ptr pItem){
	My_string* pMy_string = (My_string*)*pItem;
	free(pMy_string->data); 
	free(pMy_string);
	*pItem = NULL;
}	

MY_STRING my_string_init_c_string(const char* c_string){
	
	My_string* pMy_string = NULL;
	pMy_string = (My_string*)malloc(sizeof(My_string));
	
	if(pMy_string != NULL){
		pMy_string->size = strlen(c_string);
		pMy_string->capacity = 1+ strlen(c_string);
		pMy_string->data = malloc(sizeof(char)*pMy_string->capacity);
		if(pMy_string->data == NULL){
			free(pMy_string);
			return NULL;
		}
		for(int i = 0; i < pMy_string->size; i++){
			pMy_string->data[i] = c_string[i];
		}
	}
	return pMy_string;
 }

int my_string_get_capacity(MY_STRING hMy_string){
	My_string* phMy_string = hMy_string;
	if(phMy_string != NULL){
		return phMy_string->capacity;
	}
	else{
		return 1;
	}
}

int my_string_get_size(MY_STRING hMy_string){
	My_string* phMy_string = hMy_string;
	if(phMy_string != NULL){
		return phMy_string->size;
	}
	else{
		return 1;
	}

}

int my_string_compare(MY_STRING hLeft_string, MY_STRING hRight_string){

		My_string* phLeft_string = hLeft_string;
		My_string* phRight_string = hRight_string;
	
		int left_size = my_string_get_size(phLeft_string);
		int right_size = my_string_get_size(phRight_string);
		int small_size = 0;

		if(left_size < right_size){
			small_size = left_size;
		}
		else{
			small_size = right_size;
		}


 		for(int i = 0; (i < small_size); i++){
			
			if((phLeft_string->data[i] > phRight_string->data[i])){		
				return 1;
			} 
			else if(phLeft_string->data[i] < phRight_string->data[i]){
				return -1;
			}
		
		}
		if (left_size == right_size){
			return 0;
		}
		else if(right_size == small_size){
			return 1;
		}
		else{
			return -1;
		}
	
	}
	
Status my_string_extraction(MY_STRING hMy_string, FILE* fp){
	My_string* phMy_string = hMy_string;
	int c;
	c = fgetc(fp);
	while(c != EOF &&  (c == ' ' || c == '\n' || c == '\t')){
		c = fgetc(fp);
	}
	phMy_string->size = 0;	
	while(c != EOF && c != ' ' && c != '\n' && c != '\t'){
		if(phMy_string->size >= phMy_string->capacity){
			char* temp = (char*)malloc(sizeof(char) * phMy_string->capacity * 2);
			if(temp == NULL){
				return FAILURE;
			}
			for(int i = 0; i < phMy_string->size; i++){
				temp[i] = phMy_string->data[i];
			}
			free(phMy_string->data);
			phMy_string->data = temp;
			phMy_string->capacity *= 2;
		}
		phMy_string->data[phMy_string->size++] = c;
		c = fgetc(fp);
	}
	if(phMy_string->size == 0){
		return FAILURE;
	}
	if(c != EOF){
		ungetc(c, fp);
	}
	return SUCCESS;
}

Status my_string_insertion(MY_STRING hMy_string, FILE* fp){
	My_string* pMy_string = (My_string*)hMy_string;
	if(pMy_string->size == 0){
		return FAILURE;
	}
	for(int i = 0; i < pMy_string->size; i++){
		fputc(pMy_string->data[i], fp);
	}
	return SUCCESS;
	
}

Status my_string_push_back(MY_STRING hMy_string, char item){
	My_string* pMy_string = (My_string*)hMy_string;
	if(pMy_string->size + 1 >= pMy_string->capacity){
		char* temp = (char*)malloc(sizeof(char) * pMy_string->capacity * 2);
		if(temp == NULL){
			return FAILURE;
		}
		for(int i = 0; i < pMy_string->size; i++){
			temp[i] = pMy_string->data[i];
		}
		free(pMy_string->data);
		pMy_string->data = temp;
		pMy_string->capacity *= 2;
	}
	pMy_string->data[pMy_string->size++] = item;
	return SUCCESS;
}

Status my_string_pop_back(MY_STRING hMy_string){
	My_string* pMy_string = (My_string*)hMy_string;
	if(pMy_string->size == 0){
		return FAILURE;
	}
	pMy_string->size -= 1;
	return SUCCESS;
}

char* my_string_at(MY_STRING hMy_string, int index){
	My_string* pMy_string = (My_string*)hMy_string;
	if(pMy_string == NULL){
		printf("my_string_at given null string\n");
		exit(1);
	}
	if(index >= pMy_string->size){
		return NULL;
	}
	else{
		return &pMy_string->data[index];
	}
}

char* my_string_c_str(MY_STRING hMy_string){
	My_string* pMy_string = (My_string*)hMy_string;
	if(pMy_string->size >= pMy_string->capacity){
		char* temp = (char*)malloc(sizeof(char) * pMy_string->capacity +1);
		if(temp == NULL){
			return FAILURE;
		}
		for(int i = 0; i < pMy_string->size; i++){
			temp[i] = pMy_string->data[i];
		}
		free(pMy_string->data);
		pMy_string->data = temp;
		pMy_string->capacity += 1;
	}
	pMy_string->data[pMy_string->size] = '\0';
	return &pMy_string->data[0];
}

Status my_string_concat(MY_STRING hResult, MY_STRING hAppend){
	My_string* pResult = (My_string*)hResult;
	My_string* pAppend = (My_string*)hAppend;
	int newSize = pResult->size + pAppend->size;

	if(pResult->capacity <= newSize){
		char* temp = (char*)malloc(sizeof(char) * (newSize) + 1);
		if(temp == NULL){
			return FAILURE;
		}
		for(int i = 0; i < pResult->size; i++){
			temp[i] = pResult->data[i];
		}		
		int j = 0;
		for(int i = pResult->size; j < pAppend->size; i++, j++){
			temp[i] = pAppend->data[j];
		}
		free(pResult->data);
		pResult->size = newSize;
		pResult->data = temp;
		pResult->capacity = newSize + 1;
	}
	else{
		int j = 0;
		for(int i = pResult->size; j < pAppend->size; i++, j++){
			pResult->data[i] = pAppend->data[j];
		}
		pResult->size = newSize;

	}
	return SUCCESS;
}

_Bool my_string_empty(MY_STRING hMy_string){
	My_string* pMy_string = (My_string*)hMy_string;
	if(pMy_string->size == 0){
		return 1;
	}
	else{
		return 0;
	}
}

Status my_string_assignment(Item_ptr pLeft, ITEM Right){

	My_string* pMy_string_right = (My_string*)Right;
	
	if(*pLeft == NULL){
		
		My_string* pMy_string = NULL;
		pMy_string = (My_string*)malloc(sizeof(My_string));
		if(pMy_string == NULL){
			return FAILURE;
		}
		pMy_string->size = pMy_string_right->size;
		pMy_string->capacity = pMy_string_right->capacity;
		pMy_string->data = malloc(sizeof(char)*pMy_string_right->capacity);
		if(pMy_string->data == NULL){
			free(pMy_string);
			return FAILURE;
		}
		*pLeft = pMy_string; 
	
	}
	My_string* pMy_string_left = (My_string*) *pLeft;
	
	if(pMy_string_left->capacity < pMy_string_right->size){	
     		char* temp = (char*)malloc(sizeof(char) * pMy_string_right->capacity);
		if(temp == NULL){
			return FAILURE;
		}
		free (pMy_string_left->data);
		pMy_string_left->data = temp;
		pMy_string_left->capacity = pMy_string_right->capacity;
	}


	pMy_string_left->size = pMy_string_right->size;
	
	for(int i = 0; i < pMy_string_right->size; i++){
		pMy_string_left->data[i] = pMy_string_right->data[i];
	}

	return SUCCESS;
}

Status get_word_key_value(MY_STRING current_word_family, MY_STRING new_key, MY_STRING word, char guess){
	
//	printf("getwordkeyvalue\n");
	if(64 < guess && guess < 91){
	       guess += 32;
	}	       
	my_string_assignment(&new_key, current_word_family);

	for(int i = 0; i < my_string_get_size(word); i++){
//		printf("get key value loop\n");
//		printf("word size: %d\n", my_string_get_size(word));
	
		if(guess == *my_string_at(word, i)){
			*my_string_at(new_key, i) = guess;
		}
		
	}
	return SUCCESS;
	
}
void clear_keyboard_buffer(void){
    char c;
    scanf("%c", &c);
    while(c != '\n' && c != '\0'){
        scanf("%c", &c);
    }
}

