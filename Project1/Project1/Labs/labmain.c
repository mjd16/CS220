//
// Created by C22Maxwell.DiLalla on 1/14/2020.
//

#include <stdio.h>
#include "bstAsLinkedDS.h"

int main() {
    BSTnode* nodel = NULL;
    nodel = insertBST(nodel, 15);
    nodel = insertBST(nodel, 10);
    nodel = insertBST(nodel, 22);
    nodel = insertBST(nodel, 7);
    nodel = insertBST(nodel, 12);
    nodel = insertBST(nodel, 17);
    nodel = insertBST(nodel, 24);

    printInorderBST(nodel);
    printf("\n");
    printPostorderBST(nodel);
    printf("\n");
    printPreorderBST(nodel);
    printf("\n");
          
    return 1;
}