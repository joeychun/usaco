#include <stdio.h>
#include <stdlib.h>

// I. Declare structure node
typedef struct node {
  int val;
  struct node *link;
}NODE;

// II. Declare pointers head and tail that will indicate the first/last NODES
NODE *head;
NODE *tail;
int size = 0;

//char *color = "[1;32m";
char *color = "[1m";


// III. Declare functions that will be used

  /* Inserts NODE with value of "val" in position "pos" */
void insert(int val, int pos, int print);

  /* Erases NODE in position "pos", freeing it */
void erase(int pos, int print);

  /* Search for NODE with position "pos", returns its value */
int search_by_pos(int pos, int print);

  /* Search for NODE with value "val", returns its position */
int search_by_val(int val, int print);

  /* Print the whole Linked List */
void print(void);

  /* Get the number of elements of Linked List */
int get_size(void);



int main() {
  // TODO: But first, build the funcitons
  // Boolean that determines if the process of the function gets printed
  int print_process = 1;

  for (int i=0; i<7; ++i) printf("\n");

  insert(1,0, print_process);
  print();
  erase(0,print_process);
  print();
  insert(1,0, print_process);
  print();
  insert(2,0, print_process);
  print();
  erase(0,print_process);
  print();
  insert(2,0, print_process);
  print();
  erase(1,print_process);
  print();
  insert(1,1, print_process);
  print();
  insert(100,4, print_process);
  print();
  insert(3,2, print_process);
  print();
  insert(10,1, print_process);
  print();
  search_by_pos(0,print_process);
  search_by_pos(1,print_process);
  search_by_pos(2,print_process);
  search_by_pos(3,print_process);
  search_by_pos(4,print_process);

  search_by_val(1,print_process);
  search_by_val(2,print_process);
  search_by_val(3,print_process);
  search_by_val(10,print_process);
  print();

  erase(2, print_process);
  print();
  insert(1,2, print_process);
  print();
  erase(4, print_process);
  print();
  erase(3, print_process);
  print();

  printf("\n");
  return 0;
}

// TODO: Actually make the functions work
void insert(int val, int pos, int print) {
  /* Inserts NODE with value of "val" in position "pos" */

  if (print) {
    printf("Insert(val=%d, pos=%d)\n\n", val, pos);
  }

  // EXEPTION: check if "pos" is a valid position
  if (pos > size) {
    if (print) {
      printf("\tThe position %d is not valid. ", pos);
      if (size == 0) {
        printf("The only option available is 0.\n");
        printf("-----------------------------------\n");
      } else {
        printf("The options you have are 0 ~ %d\n", size);
        printf("-----------------------------------\n");
      }
    }
    return;
  }

  NODE *new_node = (NODE*)malloc(sizeof(NODE));
  new_node->val = val;
  new_node->link = NULL;
  if (size == 0 && pos == 0) {
    // First node; head = tail = new_node
    if (print) printf("\tFirst node; head = tail = new_node\n");
    head = new_node;
    tail = new_node;
  } else if (pos == 0) {
    // New head has arrived
    if (print) printf("\tpos = 0, new_node is the new head\n");
    new_node->link = head;
    head = new_node;
  } else if (pos == size) {
    // New tail has arrived
    if (print) printf("\tpos = %d(last), new_node is the new tail\n", size);
    tail->link = new_node;
    tail = new_node;
  } else {
    // Putting new_node in between two nodes [pos-1] and [pos]
    if (print) printf("\tNormal case: putting new_node in between nodes in positions %d and %d\n", pos-1, pos);
    NODE *cur = head;
    for (int i=0; i<pos-1; ++i) {
      if (cur == NULL) {
        if (print) printf("\t\tNULL Error: NODE *cur turns out to be NULL. Exiting insert()\n");
        return;
      }
      cur = cur->link;
    } // cur is now node in position "pos-1"

    new_node->link = cur->link;
    cur->link = new_node;

  }

  if (print) printf("\nInsert successfully done!\n");
  if (print) printf("-----------------------------------\n");
  // Increase size
  size++;
  return;
}

void erase(int pos, int print) {
  /* Erases NODE in position "pos", freeing it */

  if (print) {
    printf("Erase(pos=%d)\n\n", pos);
  }

  if (pos >= size) {
    if (print) {
      printf("\tThe position %d is not valid. ", pos);
      if (size == 0) {
        printf("The Linked List is empty!\n");
        printf("-----------------------------------\n");
      } else if (size == 1) {
        printf("The only option available is 0.\n");
        printf("-----------------------------------\n");
      } else {
        printf("The options you have are 0 ~ %d\n", size-1);
        printf("-----------------------------------\n");
      }
    }
    return;
  }

  if (size == 1 && pos == 0) {
    if (print) printf("\tOnly one node; node erased; head = tail = NULL\n");
    free(head);
    head = NULL;
    tail = NULL;
  } else if (size == 2) {
    if (pos == 0) {
      if (print) printf("\tsize = 2 & pos = 0, head erased and address redirected to tail\n");
      head->link = NULL;
      free(head);
      head = tail;
    } else if (pos == 1) {
      if (print) printf("\tsize = 2 & pos = 1, tail erased and address redirected to head\n");
      head->link = NULL;
      free(tail);
      tail = head;
    } else {
      // THIS SHOULD NOT BE CALLED BECAUSE POS>=SIZE IS CHECKED
      // IF THIS GETS CALLED, THERE IS A PROBLEM
      if (print) printf("\tError: size is two, yet a bigger pos is given.");
    }
  } else if (pos == 0) {
    if (print) printf("\tpos = 0, head erased and address redirected to head->link");
    NODE *tmp = head;
    free(head);
    head = tmp->link;
  } else {
    if (print) {
      printf("\tNormal case: erasing node in position %d\n", pos);
      printf("\t  and connecting the node in position %d and the node in the position %d\n", pos-1,pos+1);
      if (pos == size-1) printf("\t  (in this case, node in position %d is NULL)\n", pos+1);
    }

    NODE *cur = head;
    for (int i=0; i<pos-1; ++i) {
      if (cur == NULL) {
        if (print) printf("\t\tNULL Error: NODE *cur turns out to be NULL. Exiting erase()\n");
        return;
      }
      cur = cur->link;
    }

    // Cur is now node in position "pos-1"
    // Need to erase position "pos" node
    // Need to connect position "pos-1" and "pos+1"
    NODE *tmp = cur->link;
    cur->link = tmp->link;
    free(tmp);
  }

  if (print) printf("\nErase successfully done!\n");
  if (print) printf("-----------------------------------\n");
  // Increase size
  size--;
  return;
}

int search_by_pos(int pos, int print) {
  /* Search for NODE with position "pos", returns its value */

  if (print) {
    printf("SearchByPosition(pos=%d)\n\n", pos);
  }

  if (pos >= size) {
    if (print) {
      printf("\tThe position %d is not valid. ", pos);
      if (size == 0) {
        printf("The only position that exists list is 0.\n");
        printf("-----------------------------------\n");
      } else {
        printf("The positions that exist in the list are 0 ~ %d\n", size-1);
        printf("-----------------------------------\n");
      }
    }
    return -1;
  }

  NODE *cur = head;
  for (int i=0; i<pos; ++i) {
    cur = cur->link;
  }

  if (print) {
    printf("\tThe node in position %d: ", pos);
    printf("\033%s",color);
    printf("%d\n", cur->val);
    printf("\033[0m");
    printf("-----------------------------------\n");
  }

  return cur->val;
}

int search_by_val(int val, int print) {
  /* Search for NODE with value "val", returns its position */

  if (print) {
    printf("SearchByValue(val=%d)\n\n", val);
  }

  NODE *cur;
  int pos_counter = 0;
  for (cur = head; cur != NULL; cur = cur->link) {
    if (cur->val == val) {
      if (print) {
        printf("\tThe node in ");
        printf("\033%s",color);
        printf("position %d", pos_counter);
        printf("\033[0m");
        printf(": %d\n", cur->val);
        printf("-----------------------------------\n");
      }
      return pos_counter;
    }
    pos_counter++;
  }

  if (print) printf("\tThere is no node with value %d\n", val);
  if (print) printf("-----------------------------------\n");
  return -1;
}

void print(void) {
  /* Print the whole Linked List */
  printf("Print()\n\n");

  // Iterate through whole list until NULL
  NODE *cur;
  int counter = 0;
  for (cur = head; cur != NULL; cur = cur->link) {
    printf("\tNode in position %d: %d\n", counter, cur->val);
    counter++;
  }

  printf("\nLinked List: ");
  for (cur = head; cur != NULL; cur = cur->link) {
    printf("%d ", cur->val);
  }
  printf("\nEnd of Linked List\n");
  printf("-----------------------------------\n");
}

int get_size(void) {
  NODE *cur;
  int counter = 0;
  for (cur = head; cur != NULL; cur = cur->link) {
    counter++;
  }
  return counter;
}
