#include "trees.h"
#include <string.h>



int main(){
    //* Create synonyms and antonyms lists
    WordNode *synonyms = NULL;
    WordNode *antonyms = NULL;
    insertAtEnd(&synonyms, "joyful");
    insertAtEnd(&antonyms, "sad");

    insertAtEnd(&synonyms, "cheerful");
    insertAtEnd(&antonyms, "gloomy");

    printf("\nSynonyms List:\n");
    printWordNodeList(synonyms);

    printf("\nAntonyms List:\n");
    printWordNodeList(antonyms);

    WordNode *copySyn = copyNodeList(synonyms);
    printf("\nCopied Synonyms List:\n");
    printWordNodeList(copySyn);

    //* Tree creation
    TTree2 *root = NULL;
    root = insertBST2(root, "happy", synonyms, antonyms);
    root = insertBST2(root, "fast", NULL, NULL);
    root = insertBST2(root, "bright", NULL, NULL);
 
    printf("\nIn-Order Traversal:\n");
    TraversalBSTinOrder(root);
 
    printf("\nPre-Order Traversal:\n");
    TraversalBSTpreOrder(root);
 
    printf("\nPost-Order Traversal:\n");
    TraversalBSTpostOrder(root);
 
    printf("\nHeight and Size of BST:\n");
    HighSizeBST(root);
    printf("\nIn-Order Successor of 'fast':\n");
    TTree2 *successor = inOrderSuccesor(root, "fast");
    if (successor) printf("Successor: %s\n", successor->word);

    printf("\nLowest Common Ancestor of 'happy' and 'bright':\n");
    TTree2 *lca = LowestCommonAncestor(root, "happy", "bright");
    if (lca) printf("LCA: %s\n", lca->word);

    printf("\nCount Nodes within word lengths 3-7:\n");
    printf("%d\n", CountNodesRanges(root, 3, 7));

    printf("\nBST Mirror:\n");
    TTree2 *mirror = BSTMirror(root);
    TraversalBSTinOrder(mirror);

    printf("\nIs BST Balanced:\n");
    printf("%s\n", isBalencedBST(root) ? "Yes" : "No");

    printf("\nPrinting Tree Node Characteristics for 'happy':\n");
    printTreeNodeCharacteristics(root, "happy");

    printf("\nUpdating 'happy' with new synonym and antonym:\n");
    root = UpdateWordBST(root, "happy", "elated", "depressed");
    printTreeNodeCharacteristics(root, "happy");

    printf("\nDeleting synonym 'cheerful' from 'happy':\n");
    root = deleteSyn(root, "happy", "cheerful");
    printTreeNodeCharacteristics(root, "happy");

    printf("\nDeleting antonym 'gloomy' from 'happy':\n");
    root = deleteAnt(root, "happy", "gloomy");
    printTreeNodeCharacteristics(root, "happy");

  

    printf("\nDeleting 'fast' from tree:\n");
    root = deleteWordBST(root, "fast");
    TraversalBSTinOrder(root);
    printTreeNodeCharacteristics(root,"fast");
    


   printf("\nLoading BST from dictionary.txt.....\n");
    TTree2 *file = fillTree("dictinoary.txt");
    TraversalBSTinOrder(file);

    printf("\033[0;33mBTS Merge two trees:\033[0m\n");
    TTree2 *mergedTree = BTSMerge(root, file);
    TraversalBSTinOrder(mergedTree);


    return 0;
}
/* printf("\033[0;31mThis is red text!\033[0m\n");
    printf("\033[0;32mThis is green text!\033[0m\n");
    printf("\033[0;33mThis is yellow text!\033[0m\n");
    printf("\033[0;34mThis is blue text!\033[0m\n");
    printf("\033[0;35mThis is magenta text!\033[0m\n");
    printf("\033[0;36mThis is cyan text!\033[0m\n");
    printf("This is normal text.\n");
*/
