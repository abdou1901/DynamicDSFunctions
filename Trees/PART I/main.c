#include <stdio.h>
#include "trees.h"

int main() {
    node *root = NULL;

    root = insertNode(root, 1, "System boot", "2025-04-01 08:00", 3);
    root = insertNode(root, 2, "User login", "2025-04-01 08:05", 2);
    root = insertNode(root, 3, "Disk error", "2025-04-01 08:10", 5);
    root = insertNode(root, 4, "Update completed", "2025-04-01 08:20", 1);

    printf("In-order Traversal:\n");
    inOrderTraversal(root);

    printf("\nSearching for log at '2025-04-01 08:10':\n");
    node *found = searchNode(root, "2025-04-01 08:10");
    if (found) printNode(found);

    printf("\nDeleting log at '2025-04-01 08:10'\n");
    root = deleteLog(root, "2025-04-01 08:10");

    printf("\nIn-order Traversal After Deletion:\n");
    inOrderTraversal(root);

    freeTree(root);
    return 0;
}
