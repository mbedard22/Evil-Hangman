#include <stdio.h>
#include <stdlib.h>
#include "generic_vector.h"
#include "my_string.h"
#include "tree.h"
#include "generic.h"
#include "hangman.h"
int main(int argc, char* argv[]){

	G_VECTOR array[30];
	FILE* fp = fopen("dictionary.txt", "r");


	for(int i = 0; i < 30; i++){
		array[i] = g_vector_init_default(my_string_assignment, my_string_destroy);
	}
	
	MY_STRING word1 = my_string_init_default();

	while(my_string_extraction(word1, fp)){
		g_vector_push_back(array[my_string_get_size(word1)], word1);
	}
		
//	printf("size of first word in vector: %d\n", my_string_get_size(g_vector_at(array[5], 0)));
//	my_string_insertion(g_vector_at(array[5], 0), stdout);
//	printf("\n");

	my_string_destroy(&word1);
	fclose(fp);
	
	Status status;

	do{
		int word_length = get_word_length();
		int num_guesses = get_num_guesses();
		int display_running_total = get_choice_running_total();
	       	if(num_guesses > 0){
			status = play_hangman(array[word_length], word_length, num_guesses, display_running_total);
		}
		if(status == FAILURE){
			printf("play_hangman returned FAILURE\n");
			exit(1);
		}
	}while(get_choice_continue());

		

	for(int j = 0; j < 30; j++){
		g_vector_destroy(&array[j]);
	}

	

	return 0;
}


	

