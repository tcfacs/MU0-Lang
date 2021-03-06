
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

#include "listmap.h"

/*
 * A couple of functions to implement linked lists,
 * and string maps.
 *
 * String map is implemented trough binary tree
 *
 * Both lists and maps should be initiated as 0
 */


/* Expamle code:
 *
 * List myList = 0;
 * 
 * list_push(&myList, "abc");
 * 
 * if(list_len(&myList)){
 * 	puts("yay, list is not empty");
 * }
 *
 * char* myString = list_get(&myList, 0);
 */


// Push object to list
void list_push(List* list, void *obj){
	
	while (*list != 0) {
		list = &(list[0]->next);
	}

	*list = malloc(sizeof(struct List));
	list[0]->obj = obj;
	list[0]->next = 0;
}

// Get list length
int list_len(List* list) {
	
	int length = 0;

	while (*list != 0) {
		list = &(list[0]->next);
		length++;
	}

	return length;
}

// Get item i of list, returns 0 on failure
void* list_get(List* list, int i) {

	while (i > 0) {
		if (*list == 0) {
			return 0;
		}

		list = &(list[0]->next);
		i--;
	}

	return list[0]->obj;
}

// Set value in map
void map_set(Map* map, char *str, void *obj) {
	
	while (*map != 0) {
		int res = strcmp(str, map[0]->str);

		if (res == 0) {
			break;
		} else if (res > 0) {
			map = &(map[0]->high);
		} else {
			map = &(map[0]->low);
		}
	}

	if (*map != 0) {
		free(*map);
	}

	*map = malloc(sizeof(struct Map));

	map[0]->str = str;
	map[0]->obj = obj;
	map[0]->high = 0;
	map[0]->low = 0;
}

// Get value in map
void *map_get(Map* map, char* str) {
	
	while (*map != 0) {
		int res = strcmp(str, map[0]->str);

		if (res == 0) {
			return map[0]->obj;
		} else if(res > 0) {
			map = &(map[0]->high);
		} else {
			map = &(map[0]->low); 
		}
	}

	return 0;
}
