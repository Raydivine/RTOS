#include "LinkedList.h"
#include "LinkedListRemove.h"
#include "LinkedListERR.h"
#include <string.h>
#include <malloc.h>
#include <stdio.h>
#include "Task.h"

void removeDataFromList(LinkedList **list, void  *removeData){
  LinkedList *current = *list;
    
  if(current != NULL){
    if(current->data == removeData){
      removeHead(&current);
      *list = current;
      return;  
    }
    while(current->next != NULL){ 
      if(current->next->data == removeData){
        removeHead( &(current->next) );
        return;
      }
      current = current->next;    
    }
  }
}

void removeHead(LinkedList **list){
  LinkedList *current = *list, *tail;
  
  if(current == NULL)
    return;
  
  tail = current->next;
  *list = tail;
 // free(current);
}

LinkedList *returnHead(LinkedList **list){
  LinkedList *current = *list, *tail;
  
  if(current == NULL)
    return NULL;
  
  tail = current->next;
  *list = tail;
  
  current->next = NULL;
  return current;
}
