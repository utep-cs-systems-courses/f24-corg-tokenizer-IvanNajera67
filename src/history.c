#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tokenizer.h"
#include "history.h"

//Initialize a linked list
List* init_history(){
  List *history_list = (List*)malloc(sizeof(List));
  history_list->root = NULL;
  return history_list;
}

void add_history(List *list, char *str){
  Item *node = (Item*)malloc(sizeof(Item));
  node->str = copy_str(str,strlen(str));
  node->next = NULL;

  if (list->root == NULL) {
      list->root = node;
      node->id = 1;
    }
  else{
      Item *temp = list->root;
      int i = temp->id;

      while(temp->next != NULL){
	  temp = temp->next;
	  i = temp->id;
	}
      temp->next = node;
      node->id = i + 1;
    }
}
char *get_history(List *list, int id){
  Item *temp = list->root;
  while(temp != NULL){
      if(temp->id == id){
	  return temp->str;
	}
      temp = temp->next;
    }
  return NULL;
}

void print_history(List *list){
  Item *temp = list->root;
  if(temp == NULL){
      printf("ERROR: empty\n ");
    }
  while(temp != NULL){
      printf("[%d] %s\n", temp->id, temp->str);
      temp = temp->next;
    }
}
 
void free_history(List *list){
  Item *head = list->root;
  Item *temp;
  while(head != NULL){
      temp = head;
      head = head->next;;
      free(temp->str);
      free(temp);
    }
}
