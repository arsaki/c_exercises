/*
 * singly_linked_list.c
 * Copying singly linked list with random pointer pole
 *
 */

#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>

#define CHAIN_SIZE 512

struct element{
	uint32_t number;
	char  data[8];
	struct element * next;
	struct element * random;
};

int main (void){
	struct element * pointer, * pointer_prev, * pointer_first, * pointer_tmp;
		
	/* making 1st element */	
		pointer_first =(struct element *) malloc(sizeof (struct element));
		pointer_first->number = 0;
		strcpy(pointer_first->data,"even\n");
		pointer_prev = pointer_first;
	/* making 1...n-1 elements */
	for (uint32_t i = 1; i < CHAIN_SIZE; i++){
		pointer = (struct element *)malloc(sizeof (struct element));
		pointer->number = i;
		if (i % 1)  
			strcpy(pointer_first->data,"odd\n");
		else	
			strcpy(pointer_first->data,"odd\n");
		pointer_prev->next = pointer;		
		pointer_prev = pointer;
	}
	/* finishing last element */
		pointer->next = pointer_first;

	/* randoming */
	pointer = pointer_first;
	pointer_tmp = pointer_first;
	for (uint32_t i = 0; i < CHAIN_SIZE; i++){
		uint32_t random_value = random() % CHAIN_SIZE;
		for (uint32_t c = 0; c < random_value; c++)
			pointer_tmp = pointer_tmp->next;
		pointer->random = pointer_tmp;
		pointer = pointer->next; 
	}	
	
	/* printing sequence with random field */
	pointer = pointer_first;
	printf("Printing elements sequence\n");
	for (uint32_t i = 0; i < CHAIN_SIZE; i++){
		printf("Element num. %d, randomly points to %d \n", pointer->number, (pointer->random)->number);
		pointer = pointer->next; 
	}	
	printf("End of printing\n");

	/* freeing memory */
	pointer = pointer_first;
	for (uint32_t i = 0; i < CHAIN_SIZE; i++){	
		pointer_tmp = pointer->next;
		free(pointer);
		pointer = pointer_tmp;
	}	
return 0;

}

