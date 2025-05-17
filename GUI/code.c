#include "code.h"
#include "code_utils.h"

// Add this function prototype after the includes at the top of the file, before any function definitions
CNode *copyNode(CNode *src);

// Functions that are unique to code.c and not in code_utils.c

TList *getSynWords(FILE *f){
    f = fopen("dictinoary.txt","r");
    if (!f) {
        perror("Failed to open file");
        return NULL;
    }
    TList *list = (TList *)malloc(sizeof(TList));
    list->head = NULL;
    char buffer[170];
    char word[50];
    char syn[50];
    while(fgets(buffer, sizeof(buffer), f)!=NULL){
        if (sscanf(buffer, "%49[^=] = %49[^#]", word, syn) == 2) {
            addNodeAtEnd(list,word,syn);
        }
    }
    fclose(f);
    return list;
}

TList *getAntoWords(FILE *f){
    f = fopen("dictinoary.txt","r");
    if (!f) {
        perror("Failed to open file");
        return NULL;
    }
    TList *list = (TList *)malloc(sizeof(TList));
    list->head = NULL;
    char buffer[175];
    char word[50];
    char antonym[50];
    while(fgets(buffer,sizeof(buffer),f)){
        if(sscanf(buffer, " %49[^=]=%*[^#]#%49[^\n]",word,antonym) == 2){
            addNodeAtEnd(list,word,antonym);
        }
    }
    fclose(f);
    return list;
}

void getInfWord(TList *syn, TList *ant, char *word){
    Node *current = syn->head;
    printCentered(word,28);
    bool found = false;
    while(current){
        if(strcmp(current->word,word) == 0){
            found = true;
            printf("Char Count = %d\nVowels Count = %d\nSynonym = %s\n",current->charCount,current->vowelCount,current->relatedWord);
            break;
        }
        current = current->next;
    }
    if(current == NULL){
        printf("Word not found in sysnonyms dictionary!\n");
    }
    current = ant->head;
    while(current){
        if(strcmp(current->word,word) == 0){
            if(found)printf("Antonym = %s\n",current->relatedWord);
            else printf("Antonym = %s\nChar Count = %d\nVowels Count = %d\n",current->relatedWord,current->charCount,current->vowelCount);
            break;
        }
        current = current->next;
    }
    if(current == NULL){
        printf("Word Not found in antonyms dictionary! \n");
    }
    printf("----------------------------\n");
}

void getInfWord2(TList *syn, TList *ant, char *inf){
    bool found = false;
    Node *current = syn->head;
    printCentered(inf,28);
    while(current){
        
        if(strcmp(current->relatedWord,inf) == 0){
            printf("Is a synonym for : %s\nChars Count = %d\nVowels Count = %d\n",current->word,current->charCount,current->vowelCount);
            found = true;
            break;
        }
        current = current->next;
    }
    if(!found){
        current = ant->head;
        while(current){
            if(strcmp(current->relatedWord,inf) == 0){
                printf("Is an antonym for : %s\nChars Count = %d\nVowels Count = %d\n",current->word,current->charCount,current->vowelCount);
                found = true;
                break;
            }
            current = current->next;
        }
        if(!found){
            printf("Word Not found neither in synonym nor antonym list.\n");
        }
    }
    printf("----------------------------\n");
}

TList *sortWord(TList *syn){
    if(syn->head == NULL || (syn->head)->next == NULL) return syn;
    Node *current = syn->head;
    while(current->next){
        Node *temp = current;
        Node *minnode = current;
        while(temp){
            if(strcmp(temp->word,minnode->word) <0){
                minnode = temp;
            }
            temp = temp->next;
        }
        if(minnode != current) swapData(minnode,current);
        current = current->next;
    }
    return syn;
}

TList *sortWord2(TList *syn){
    if(syn->head == NULL || (syn->head)->next == NULL) return syn;
    Node *current = syn->head;
    while(current->next){
        Node *temp = current;
        Node *minnode = current;
        while(temp){
            if(temp->charCount < minnode->charCount){
                minnode = temp;
            }
            temp = temp->next;
        }
        if(minnode != current) swapData(minnode,current);
        current = current->next;
    }
    return syn;
}

TList *sortWord3(TList *syn){
    if(syn->head == NULL || (syn->head)->next == NULL) return syn;
    Node *current = syn->head;
    while(current->next){
        Node *temp = current;
        Node *maxnode = current;
        while(temp){
            if(temp->vowelCount > maxnode->vowelCount){
                maxnode = temp;
            }
            temp = temp->next;
        }
        if(maxnode != current) swapData(maxnode,current);
        current = current->next;
    }
    return syn;
}

void deleteWord(FILE *f, TList *syn, TList *ant, char *word){
    //delete from the File(the file will be overwritten)
    f = fopen("dictinoary.txt", "r");
    if(f == NULL){
        printf("Error opening file 'dictinoary.txt'!\n");
        return;
    }
    FILE *tempFile = fopen("tempFile.txt", "w");
    if(tempFile == NULL){
        printf("Error creating temporary file!\n");
        fclose(f);
        return;
    }
    char buffer[175];
    char wordFromFile[50];
    while(fgets(buffer,sizeof(buffer),f)){
        if(sscanf(buffer,"%49[^=]",wordFromFile) == 1){
            if(strcmp(word,wordFromFile) != 0){
                fputs(buffer, tempFile);
            }
        }else fputs(buffer,tempFile);
    }
    fclose(f);
    fclose(tempFile);
    remove("dictinoary.txt");
    rename("tempFile.txt","dictinoary.txt");
    //delte from sysnonyms List
    Node *current = syn->head;
    while(syn->head && strcmp(syn->head->word,word) == 0){
        syn->head = syn->head->next;
    }
    while(current && current->next){
        if(strcmp(current->next->word,word) == 0){
            Node *temp = current->next;
            current->next = current->next->next;
            free(temp);
        }else current = current->next;
    }

    //Delete form Antonum List
    current = ant->head;
    while(ant->head && strcmp(ant->head->word,word) == 0){
        ant->head = ant->head->next;
    }
    while(current && current->next){
        if(strcmp(current->next->word,word) == 0){
            Node *temp = current->next;
            current->next = current->next->next;
            free(temp);
        }else current = current->next;
    }
    
}

void updateWord(FILE *f , TList *syn, TList *ant, char *word, char *syne, char *anton){
    //update in the file
    f = fopen("dictinoary.txt","r");
    if(f == NULL){
        printf("Error opening the file 'dictinoary.txt'!\n");
        return;
    }
    FILE *tempFile = fopen("tempFile.txt","w");
    if(tempFile == NULL){
        printf("Error creating temprary file !\n");
        fclose(f);
        return;
    }
    char buffer[175];
    char newLine[175];
    while(fgets(buffer,sizeof(buffer),f)){
        if(sscanf(buffer,"%49[^=]",newLine) == 1){
            if(strcmp(newLine,word) == 0){
                strcat(newLine, "=");
                strcat(newLine, syne);
                strcat(newLine, "#");
                strcat(newLine, anton);
                strcat(newLine, "\n");
                fputs(newLine,tempFile);
            }else fputs(buffer,tempFile);
        }else fputs(buffer,tempFile);
    }
    fclose(f);
    fclose(tempFile);
    remove("dictinoary.txt");
    rename("tempFile.txt","dictinoary.txt");
    //update in the lists
    Node *current = syn->head;
    while(current){
        if(strcmp(current->word,word) == 0){
            strcpy(current->relatedWord,syne);
        }
        current = current->next;
    }

    current = ant->head;
    while(current){
        if(strcmp(current->word,word) == 0){
            strcpy(current->relatedWord,anton);
        }
        current = current->next;
    }
}

// the rate will be counted base on prefix match
TList *similarWord(TList *syn, char *word, int rate){
    TList *newlist = (TList *)malloc(sizeof(TList));
    newlist->head = NULL;
    Node *current = syn->head;
    while(current){
        if(matchRate(current->word,word) >= rate){
            addNodeAtEnd(newlist,current->word,current->relatedWord);
        }
        current = current->next;
    }
    return newlist;
}

TList *countWord(TList *syn, char *prt){
    TList *newlist = (TList *) malloc(sizeof(TList));
    newlist->head = NULL;
    Node *current = syn->head;
    while(current){
        if(strstr(current->word,prt)){
            addNodeAtEnd(newlist,current->word,current->relatedWord);
        }
        current = current->next;
    }
    return newlist;
}

TList *palindromWord(TList *syn){
    TList *newlist = (TList *)malloc(sizeof(TList));
    newlist->head = NULL;
    Node *current = syn->head;
    while(current){
        if(isPalindrome(current->word,0,current->charCount -1)){
            Node *newnode = (Node *)malloc(sizeof(Node));
            newnode->charCount = current->charCount;
            newnode->vowelCount = current->vowelCount;
            strcpy(newnode->word,current->word);
            strcpy(newnode->relatedWord,current->relatedWord);
            newnode->next = NULL;
            if(newlist->head ==NULL) newlist->head = newnode;
            else{
                Node *temp2 = newlist->head;
                if(strcmp(temp2->word, newnode->word) > 0){
                    newnode->next = newlist->head;
                    newlist->head= newnode;
                    continue;
                }
                while(temp2->next && strcmp(temp2->next->word, newnode->word) < 0) temp2 = temp2->next;
                Node *temp = temp2->next;
                temp2->next = newnode;
                newnode->next = temp;
            } 
        }
        current = current->next;
    }
    return newlist;
}

TList2 *merge(TList *syn, TList *ant){
    TList2 *newlist = (TList2 *)malloc(sizeof(TList2));
    newlist->head = newlist->tail = NULL;
    Node *current = syn->head;
    Node *current2 = ant->head;
    while(current && current2){
        DNode *newnode = (DNode *)malloc(sizeof(DNode));
        newnode->charCount = current2->charCount;
        newnode->vowelCount = current2->vowelCount;
        strcpy(newnode->word,current2->word);
        strcpy(newnode->synonym,current->relatedWord);
        strcpy(newnode->antonym,current2->relatedWord);
        newnode->next = NULL;
        newnode->prev = NULL;
        if(newlist->head == NULL){
            newlist->head = newlist->tail = newnode;
        }else{
            DNode *temp = newlist->head;
            while(temp->next) temp = temp->next;
            temp->next = newnode;
            newnode->prev = temp;
            newlist->tail = newnode;
        }
        
        current2 = current2->next;
        current = current->next;
    }
    return newlist;
}

TList3 *merge2(TList *syn, TList *ant){
    TList3 *newlist = (TList3 *)malloc(sizeof(TList3));
    newlist->head = newlist->tail = NULL;
    Node *current = syn->head;
    Node *current2 = ant->head;
    while(current && current2){
        CNode *newnode = (CNode *)malloc(sizeof(CNode));
        newnode->charCount = current2->charCount;
        newnode->vowelCount = current2->vowelCount;
        strcpy(newnode->antonym,current2->relatedWord);
        strcpy(newnode->word,current2->word);
        strcpy(newnode->synonym,current->relatedWord);
        newnode->next = NULL;
        if(newlist->head == NULL) newlist->head = newlist->tail= newnode;
        else {
            newlist->tail->next = newnode;
            newnode->next = newlist->head;
            newlist->tail = newnode;
        }
        current2 = current2->next;
        current = current->next;
    }
    return newlist;
}

void addWord(FILE *f,TList *syn, TList *ant, char *word, char *syne, char *anton){
    addNodeAtEnd(syn,word,syne);
    addNodeAtEnd(ant,word,anton);

    //add it to the text file
    f = fopen("dictinoary.txt","a");
    if(!f){
        printf("Cannot open the file 'dictinoary.txt'\n");
        return;
    }
    fprintf(f,"%s=%s#%s\n",word,syne,anton);
    fclose(f);
}

int compareNodes(const void *a, const void *b){
    Node *nodeA = *(Node **)a;
    Node *nodeB = *(Node **)b;
    int countA =count_syllables(nodeA->word);
    int countB = count_syllables(nodeB->word);
    if(countA != countB) {
        return countA - countB;
    }
    return strcmp(nodeA->word,nodeB->word);
}

TQueue **prounounciation(TList *syn){
    TQueue **queues = (TQueue **)malloc(3*sizeof(TQueue *));
    queues[VOWEL_SHORT] = createQueue();
    queues[VOWEL_LONG] = createQueue();
    queues[VOWEL_DIPHTHONG] = createQueue();
    Node *current = syn->head;
    while(current){
        enqueue(queues[getVowelType(current->word)], current->word);
        current = current->next;
    }
    return queues;
}

TQueue *syllable(TList *syn){
    //coutn the number of words in syn list
    int length = 0;
    Node *tempLength = syn->head;
    while(tempLength){length++; tempLength = tempLength->next;}
    
    // array of Node poniters
    Node **arr = (Node **)malloc(length*sizeof(Node *));
    tempLength = syn->head;
    for(int i = 0; i < length; i++){
        arr[i] = tempLength;
        tempLength = tempLength->next;
    }

    //sort the array based on syllbales count (we will use quick sort(from stdlib library))
    qsort(arr, length, sizeof(Node *), compareNodes);

    //create the queue and add entries
    TQueue *queue = createQueue();
    for(int i = 0; i < length; i++){
        enqueue(queue, arr[i]->word);
    }
    free(arr);
    return queue;
}

TQueue *toQueue(TList2 *merged){
    TQueue *q = createQueue();
    if(merged->head == NULL) return q;
    DNode *current = merged->head;
    while(current){
        enqueue(q, current->word);
        current = current->next;
    }
    return q;
}

void insertsortedtoqueue(TQueue *queue,TStack *stk){// used to convert sorted stack to a sorted queue
    if(isStackEmpty(stk)) return;
    CNode *temp = popFromStack(stk);
    enqueue(queue,temp->word);
    insertsortedtoqueue(queue,stk);
    pushToStack(stk,temp);
}

void insertSortedToList(TList2 *list,TStack *stk){//used to convert sorted stack to a sorted linked list
    if(isStackEmpty(stk)) return;
    CNode *temp = popFromStack(stk);
    insertSortedToList(list,stk);
    DNode *newnode = (DNode *)malloc(sizeof(DNode));
    newnode->next = list->head;
    newnode->prev = NULL;
    newnode->charCount = temp->charCount;
    newnode->vowelCount = temp->vowelCount;
    strcpy(newnode->word,temp->word);
    strcpy(newnode->antonym,temp->antonym);
    strcpy(newnode->synonym,temp->synonym);
    if(list->head== NULL) list->head = list->tail = newnode;
    else list->head = newnode;
    pushToStack(stk,temp);
}
//---------------------------------------------------------------------------

//----------------------------------------------------------------------------------------

TStack *toStack(TList2 *merged){
    TStack *stk = (TStack *)malloc(sizeof(TStack));
    stk->head = NULL;
    if(merged->head == NULL) return stk;
    DNode *current = merged->head;
    while(current){
        CNode *newnode = (CNode *)malloc(sizeof(CNode));
        newnode->charCount = current->charCount;
        newnode->vowelCount = current->vowelCount;
        strcpy(newnode->word, current->word);
        strcpy(newnode->antonym, current->antonym);
        strcpy(newnode->synonym, current->synonym);
        newnode->next = NULL;
        pushToStack(stk, newnode);
        current = current->next;
    }
    return stk;
}  

TStack *getInfWordStack(TStack *stk, char *word){
    CNode *nod = searchNodeInStack(stk, word);
    if(nod) printf("%s = %s # %s(Length = %d, Vowels Count %d)\n", nod->word, nod->synonym, nod->antonym, nod->charCount, nod->vowelCount);
    return stk;
}

TStack *sortWordStack(TStack *stk){
    if(!isStackEmpty(stk)){
        CNode *temp = popFromStack(stk);
        sortWordStack(stk);
        insertSorted(stk, temp);
    }
    return stk;
}

TStack *deleteWordStack(TStack *stk, char *word){
    if(isStackEmpty(stk)) return stk;
    if(strcmp(word, peakStack(stk)->word) == 0){
        CNode *temp = popFromStack(stk);
        free(temp);
        temp = NULL;
        // return stk; // if we want to delete only first occurence
    }
    CNode *temp2 = popFromStack(stk);
    deleteWordStack(stk, word);
    pushToStack(stk, temp2);
    return stk;
}

TStack *updateWordStack(TStack *stk, char *word, char *syne, char *anton){
    if(isStackEmpty(stk)) return stk;
    if(strcmp(peakStack(stk)->word, word) == 0){
        CNode *temp = peakStack(stk);
        strcpy(temp->antonym, anton);
        strcpy(temp->synonym, syne);
        // return stk; // if we want to delete only first occurence
    }
    CNode *temp = popFromStack(stk);
    updateWordStack(stk, word, syne, anton);
    pushToStack(stk, temp);
    return stk;
}

TQueue *stackToQueue(TStack *stk){
    sortWordStack(stk);
    TQueue *queue =createQueue();
    insertsortedtoqueue(queue,stk);
    return queue;
}

TList2 *StacktoList(TStack *stk){
    TList2 * list = (TList2 *)malloc(sizeof(TList2));
    list->head = list->tail = NULL;
    sortWordStack(stk);
    insertSortedToList(list,stk);
    return list;
}

TStack *addWordStack(TStack *stk, char *word, char *syne, char *anton){
    CNode *newnode = (CNode *)malloc(sizeof(CNode));
    strcpy(newnode->word, word);
    strcpy(newnode->antonym, anton);
    strcpy(newnode->synonym, syne);
    newnode->charCount = strlen(word);
    newnode->vowelCount = countVowels(word);
    insertSorted(stk, newnode);
    return stk;
}

// Remove the isSimpleStackEmpty, push, and pop functions from code.c
// Replace these functions with calls to the ones in code_utils.c

// Remove these functions:

// In the lengthStack function:
int lengthStack(TStack *stk){
    if (isStackEmpty(stk)) return 0;
    CNode *temp = popFromStack(stk);
    int count = 1 + lengthStack(stk);
    pushToStack(stk, temp);
    return count;
}

// In the compareNodes2 function:
int compareNodes2(const void *a, const void *b){
    CNode *nodeA = *(CNode **)a;
    CNode *nodeB = *(CNode **)b;
    int countA = count_syllables(nodeA->word);
    int countB = count_syllables(nodeB->word);
    if(countA != countB) {
        return countA - countB;
    }
    return strcmp(nodeA->word, nodeB->word);
}

// Fix the addNodesToArray function:
void addNodesToArray(CNode **arr, int index, TStack *stk){
    if(isStackEmpty(stk)) return;
    CNode *temp = popFromStack(stk);
    arr[index] = temp;
    addNodesToArray(arr, index+1, stk);
    pushToStack(stk, temp);
}

// In the syllableStack function:
TStack *syllableStack(TStack *stk){
    //count the length
    int length = lengthStack(stk);

    //put the nodes's pointerts into an array
    CNode **arr = (CNode **)malloc(length*sizeof(CNode *));
    addNodesToArray(arr, 0, stk);

    //sort the array using quick sort (from stdlib library)
    qsort(arr, length, sizeof(CNode *), compareNodes2);

    //Create the stak and add the nodes
    TStack *newStack = (TStack *)malloc(sizeof(TStack));
    newStack->head = NULL;
    for(int i = 0; i < length; i++){
        pushToStack(newStack, arr[i]);
    }
    return newStack;
}

// In the InserToPronounciationStacks function:
void InserToPronounciationStacks(TStack *stk, TStack **stacks){
    if(isStackEmpty(stk)) return;
    CNode *temp1 = popFromStack(stk);
    CNode *temp = copyNode(temp1);
    pushToStack(stacks[getVowelType(temp->word)], temp);
    InserToPronounciationStacks(stk, stacks);
    pushToStack(stk, temp1); 
}

// Fix the prounounciationStack function
TStack **prounounciationStack(TStack *stk){
    TStack **stacks = (TStack **)malloc(3*sizeof(TStack *));
    stacks[VOWEL_SHORT] = createStack();
    stacks[VOWEL_LONG] = createStack();
    stacks[VOWEL_DIPHTHONG] = createStack();
    InserToPronounciationStacks(stk, stacks);
    return stacks;
}

// Fix the smallestword function:
void smallestword(TStack *stk, CNode **minnode){
    if(isStackEmpty(stk)) return;
    CNode *temp = popFromStack(stk);
    if(*minnode == NULL || temp->charCount < (*minnode)->charCount) *minnode = temp;
    smallestword(stk, minnode);
    pushToStack(stk, temp);
}

// In the getSmallest function:
char *getSmallest(TStack *stk) {
    if (isStackEmpty(stk)) {
        return NULL;
    }
    CNode *minnode = NULL;
    smallestword(stk, &minnode);

    return minnode ? minnode->word : NULL;
}

// Fix the insertWordInverse function:
void insertWordInverse(char *word, int index, TStack2 *stk){
    if(index == strlen(word)) return;
    push(stk, word[index]);
    insertWordInverse(word, index+1, stk);
}

// In the isPalyndromeStack function:
bool isPalyndromeStack(char *word){
    TStack2 *stk = (TStack2 *)malloc(sizeof(TStack2));
    stk->head = NULL;
    insertWordInverse(word, 0, stk);
    int i = 0;
    while(!isSimpleStackEmpty(stk)){
        if(pop(stk) != word[i]){
            while (!isSimpleStackEmpty(stk)){
                pop(stk);
            }
            free(stk);
            return false;
        }
        i++;
    }
    free(stk);
    return true;
}

// In the StackRev function:
TStack *StackRev(TStack *stk){
    if(isStackEmpty(stk)) return stk;
    CNode *temp = popFromStack(stk);
    stk = StackRev(stk);
    pushToStack(stk, temp);
    return stk;
}

// Add the missing copyNode function:
CNode *copyNode(CNode *src){
    CNode *newNode = (CNode *)malloc(sizeof(CNode));
    newNode->charCount = src->charCount;
    newNode->vowelCount = src->vowelCount;
    strcpy(newNode->word, src->word);
    strcpy(newNode->antonym, src->antonym);
    strcpy(newNode->synonym, src->synonym);
    newNode->next = NULL;
    return newNode;
}
