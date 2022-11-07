#ifndef HANGMAN_H
#define HANGMAN_H

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "tree.h"
#include "generic_vector.h"
#include "my_string.h"
#include "status.h"

Status play_hangman(G_VECTOR my_string_vector, int length, int num_guesses, int display_running_total);

int get_word_length();

int get_choice_running_total();

int get_num_guesses();

int get_choice_continue();

char get_guess(MY_STRING guessed_letters);
#endif
