#include <iostream>
#include "linked_list.h"

using namespace std;


struct node * build_linked_list(int elements){
    struct node * list_head = NULL;
    if (elements == 0) return list_head;
    struct node * prev = list_head;
    for (int i =0 ; i< elements; i++){
        struct node * newNode = new node;
        newNode->number = i;
        newNode->next = NULL;
        if (list_head == NULL){
            list_head = newNode;
        }
        else {
            prev->next = newNode;
        }
        prev=newNode;
    }
    cout << list_head->next->number << endl;
    return list_head;
}

void print_linked_list(struct node * list, int elements){
    cout << "Executing print" << endl;
    struct node * cur = list;
    while(cur != NULL){
        cout << cur->number << " ";
        cur = cur->next;
    }
}




int delete_linked_list(struct node * list, int elements){
  int deleted = 0;
  if (elements == 0) return deleted;
  struct node * prev = list;
  struct node * nxt = NULL;
  while (prev != NULL){
      nxt = prev->next;
      delete prev;
      prev = nxt; 
      deleted++;
  }
  return deleted;
}


int sum_values_in_linked_list(struct node * list, int elements){
  int sum = 0;
  struct node * cur = list;
  while (cur != NULL){
    sum += cur->number;
    cur = cur->next;
  }
  return sum;
}


void change_pointers(struct node * head, int elements){
  struct node * cur = head;
  struct node * last;
  int position = 0;
  while(position < elements){
    last = cur;
    cur = cur->next;
    position++;
  }
  cout << "last element: " << last->number << endl;
  
  //now you have the last element
  position = 0;
  cur = head;
  while(position < elements){
    //create a temporary node that stores the next node
    struct node * temp = cur->next;
    
    cur->next = last;
    cout << "current node: " << cur->number << " pointing to last node: " << cur->next->number  << endl;
    cur = temp;
    position++;

  }

  
}
