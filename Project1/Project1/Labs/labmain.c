//
// Created by C22Maxwell.DiLalla on 1/14/2020.
//

#include <stdio.h>
#include "listAsLinkedList (1).h"

int main() {
    LinkedList* list = createLinkedList();
    appendElementLinkedList(list, 1);
    appendElementLinkedList(list, 2);
    appendElementLinkedList(list, 3);
    appendElementLinkedList(list, 4);
    appendElementLinkedList(list, 6);

    int len = lengthOfLinkedList(list);
    printf("%d\n is the length\n", len);
    printLinkedList(list);

    printf("\nInserting element 4 at position 4\n");
    insertElementLinkedList(list, 4, 5);
    printLinkedList(list);
    printf("\nDeleting element 1st\n");
    deleteElementLinkedList(list, 0);
    printLinkedList(list);


    return 1;
}