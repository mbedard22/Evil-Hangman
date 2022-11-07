#include <stdio.h>
#include <stdlib.h>
#include "hangman.h"
#include <ctype.h>

Status play_hangman(G_VECTOR my_string_vector, int length, int num_guesses, int display_running_total){

	MY_STRING masterKey = my_string_init_default();
	MY_STRING guessedLetters = my_string_init_default();
	char guess;
	int win = 0;


	for(int i = 0; i < length; i++){
		my_string_push_back(masterKey, '-');
	}

	G_VECTOR master_word_list = g_vector_init_default(my_string_assignment, my_string_destroy);
	for(int i = 0; i < g_vector_get_size(my_string_vector); i++){
		g_vector_push_back(master_word_list, g_vector_at(my_string_vector, i));

	}

	printf("Current key: ");
	my_string_insertion(masterKey, stdout);	

	for(int guesses_remaining = num_guesses; guesses_remaining > 0; guesses_remaining--){
	
		printf("\nYou have %d guesses remaining.\n", guesses_remaining);
		
		guess = get_guess(guessedLetters);
		
		Tree* tree = tree_init_default();
		
		MY_STRING key = my_string_init_default();
	
		for(int i = 0; i < g_vector_get_size(master_word_list); i++){
	
			get_word_key_value(masterKey, key, g_vector_at(master_word_list, i), guess);
			tree_insert(tree, key, g_vector_at(master_word_list, i));
		}

		if(display_running_total){
	
			traversal_in_order(tree->root);
		}
	
		Node* temp = traverse_find_largest(tree->root);
			
		g_vector_destroy(&master_word_list);
		master_word_list = g_vector_init_default(my_string_assignment, my_string_destroy);

		for(int i = 0; i < g_vector_get_size(temp->hVector); i++){
		
			g_vector_push_back(master_word_list, g_vector_at(temp->hVector, i));
		}

		MY_STRING temp_string = my_string_init_default();
		my_string_assignment(&temp_string, masterKey);
		my_string_assignment(&masterKey, temp->hKey);
		
		if(my_string_compare(masterKey, temp_string) != 0){
		
			guesses_remaining++;
		}

		my_string_destroy(&temp_string);
		
		printf("Current Key: ");
		my_string_insertion(masterKey, stdout);	
		printf("\n");		
		
		for(int i = 0; i < my_string_get_size(masterKey); i++){
		
			if(*my_string_at(masterKey, i) == '-'){
		
				win = 0;
				break;
			}
		
			else{
		
				win = 1;
			}
		}

	

		my_string_destroy(&key);
		tree_destroy(&tree);
		
		if(win){
		
			printf("Congratulations! You've won!\n");	
			break;
		}
	}
	
	if(win == 0){	
	
		printf("Sorry, you have lost.\n");
	}

	srand(time(0));

	printf("The word was ");
	my_string_insertion(g_vector_at(master_word_list, rand() % (g_vector_get_size(master_word_list)+1 )), stdout);
	printf("\n");
	
	my_string_destroy(&guessedLetters);
	my_string_destroy(&masterKey);
	g_vector_destroy(&master_word_list);

	return SUCCESS;
}

int get_word_length(){

	int word_length = 0;

	while(word_length < 2 && word_length != 26 && word_length != 27){
	
		printf("Please enter your desired word length: ");
		scanf("%d", &word_length);
		clear_keyboard_buffer();
	}
	return word_length;
}

int get_choice_running_total(){
	
	char yesno;

	printf("Would you like to see a running total of the words remaining in the word list? y/n: ");
	scanf("%c", &yesno);
	clear_keyboard_buffer();
	
	if(yesno == 'y'){
	
		return 1;
	}
	else{
	
		return 0;
	}
}

int get_num_guesses(){

	int num_guesses = 0;

	while(num_guesses < 1){
	
		printf("Please enter your desired number of guesses: ");
		scanf("%d", &num_guesses);
		clear_keyboard_buffer();
	}
	
	return num_guesses;
}
	
int get_choice_continue(){
	
	char yesno;
	
	printf("Would you like to play again? y/n: ");
	scanf("%c", &yesno);
	clear_keyboard_buffer();
	
	if(yesno == 'y'){
	
		return 1;
	}
	else{
	
		return 0;
	}
}

char get_guess(MY_STRING guessed_letters){
	
	char guess;
	int isGuessed = 1;
	
	while(isGuessed){
	
		printf("Please enter a letter: ");
		scanf("%c", &guess);
		clear_keyboard_buffer();
		
		while(!isalpha(guess)){
	
			printf("Please enter a LETTER: ");
			scanf("%c", &guess);
			clear_keyboard_buffer();
		}
		
		isGuessed = 0; 
		
		for(int i = 0; i < my_string_get_size(guessed_letters); i++){
	
			if(guess == *my_string_at(guessed_letters, i)){
	
				isGuessed = 1;
				break;
			}
		}
		
		if(isGuessed){
	
			printf("That letter has already been guessed.\n");
		}
	}
	

	my_string_push_back(guessed_letters, guess);
	
	return guess;
}
	


