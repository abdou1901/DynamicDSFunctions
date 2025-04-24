#include "code.h"
//some useful functions -----------------------------------------------------
void printCentered(char *str, int width){
    int len = strlen(str);
    if (len > width - 2) len = width - 2;
    int padding = (width - 2 - len) / 2;
    int extra = (width - 2 - len) % 2;
    printf("+");
    for (int i = 0; i < width - 2; i++) printf("-");
    printf("+\n");
    printf("|%*s%s%*s|\n", padding, "", str, padding + extra, "");
    printf("+");
    for (int i = 0; i < width - 2; i++) printf("-");
    printf("+\n");
}
bool includes(char *str, char c, int size){
    for (int i = 0; i < size; i++) {
        if (str[i] == c) return true;
    }
    return false;
}
int countVowels(char *str){
    int count = 0;
    int i = 0;
    char vowels[5] = {'a','e','u','i','o'};
    while(str[i] != '\0'){
        if(includes(vowels,str[i],5)) count ++;
        i++;
    }
    return count;
}
node *createNode(char *word , char *relatedWord){
    node *newnode = (node *)malloc(sizeof(node));
    newnode->next = NULL;
    newnode->charCount = strlen(word);
    newnode->vowelCount = countVowels(word);
    strcpy(newnode->relatedWord,relatedWord);
    strcpy(newnode->word,word);
    return newnode;
}
void addNodeAtEnd(TList *list,char *word ,char *relatedWord){
    node *newnode = createNode(word,relatedWord);
    newnode->next = NULL;
    if(list->head == NULL){
        list->head = newnode;
        return;
    }
    node *current = list->head;
    while(current->next) current = current->next;
    current->next = newnode;
}
void SwapData(node *node1 ,node *node2){
    node temp;
    temp.charCount = node1->charCount;
    temp.vowelCount = node1->vowelCount;
    strcpy(temp.word, node1->word);
    strcpy(temp.relatedWord, node1->relatedWord);

    node1->charCount = node2->charCount;
    node1->vowelCount = node2->vowelCount;
    strcpy(node1->word, node2->word);
    strcpy(node1->relatedWord, node2->relatedWord);

    node2->charCount = temp.charCount;
    node2->vowelCount = temp.vowelCount;
    strcpy(node2->word, temp.word);
    strcpy(node2->relatedWord, temp.relatedWord);
}
void printWords(TList *list,int option){
    node *current = list->head;
    if(current == NULL){
        printf("Empty List !\n");
        return;
    }
    int i = 1;
    while(current){
        printf("%d) %s %s %s (Length = %d, Vowels Count %d)\n",i,current->word,option == 0? "=":"#",current->relatedWord,current->charCount,current->vowelCount);
        i++;
        current = current->next;
    }
}
int matchRate(char *word1, char *word2) { 
    int len1 = strlen(word1);
    int len2 = strlen(word2);
    int common = 0;
    for (int i = 0; i < len2; i++){
        if (word1[i] == word2[i]) common++;
        else break;
    }
    if (common == len2) return 100;
    return (common * 100) / len2;
}
bool isPalindrome(char *s,int l,int r){ return (l >= r)?1:(s[l]==s[r] && isPalindrome(s,l+1,r-1)); }
void printWords2(TList2 *list){ // prints words of the biderctional linked list from the merge function
    dnode *current = list->head;
    if(current == NULL){
        printf("Empty List !\n");
        return;
    }
    int i = 1;
    while(current){
        printf("%d) %s = %s # %s(Length = %d, Vowels Count %d)\n",i,current->word,current->synonym,current->antonym,current->charCount,current->vowelCount);
        i++;
        current = current->next;
    }
}
void printWords3(TList3 *list) { // print words of the circular linked list from the merge2 function
    if (list->head == NULL) {
        printf("Empty List!\n");
        return;
    } 
    cnode *current = list->head;
    int i = 1;
    do{
        printf("%d) %s = %s # %s (Length = %d, Vowels Count %d)\n",i, current->word, current->synonym, current->antonym,current->charCount, current->vowelCount);
        current = current->next;
        i++;
    } while (current != list->head);
}
int is_vowel(char c){
    c = tolower(c);
    return(c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' || c == 'y');
}
int count_syllables(const char *word){
    int count = 0;
    int prev_char_was_vowel = 0;
    int length = strlen(word);
    for (int i = 0; i < length; i++){
        char c = tolower(word[i]);

        if (is_vowel(c)){
            if(!prev_char_was_vowel){
                count++;
                prev_char_was_vowel = 1;
            }
        }else{
            prev_char_was_vowel = 0;
        }
    }
    if(tolower(word[length - 1]) == 'e' && count > 1) count--;
    if(count == 0)count = 1;
    return count;
}
TQueue *createQueue(){
    TQueue *queue = (TQueue *)malloc(sizeof(TQueue));
    queue->head = queue->tail = NULL;
    return queue;
}
TStack *createStack(){
    TStack *stack = (TStack *)malloc(sizeof(TStack));
    stack->head = NULL;
    return stack;
}
void printQueueWords(TQueue *queue){
    QNode *current = queue->head;
    while(current){
        printf("%s\n",current->word);
        current = current->next;
    }
}
enum VowelType getVowelType(const char *word) {
    const char *diphthongs[] = {"ai", "au", "ei", "oi", "ou", "ow", "oy"};
    for(int i = 0; i < sizeof(diphthongs)/sizeof(diphthongs[0]); i++)if (strstr(word, diphthongs[i])) return DIPHTHONG;
    int len = strlen(word);
    if(len >= 2 && word[len-1]== 'e') return LONG;
    return SHORT;
}
void printStack(TStack *stk){
    cnode *current = stk->head;
    int i =1;
    while(current){
        printf("%d) %s = %s # %s(Length = %d, Vowels Count %d)\n",i++,current->word,current->synonym,current->antonym,current->charCount,current->vowelCount);
        current = current->next;
    }
}
bool isStackEmpty(TStack *stk){
    return stk->head == NULL;
}
void pushToStack(TStack *stk , cnode *nod){
    if(stk->head == NULL) {stk->head = nod, stk->head->next = NULL;return;}
    nod->next = stk->head;
    stk->head = nod;
}
cnode *peakStack(TStack *stk){
    return stk->head;
}
cnode *popFromStack(TStack *stk){
    if(stk->head == NULL) return NULL;
    cnode *temp = stk->head;
    stk->head = stk->head->next;
    temp->next = NULL;
    return temp;
}
cnode *searchNodeInStack(TStack *stk,char *word){
    if(stk->head == NULL) return NULL;
    if(strcmp(stk->head->word,word) == 0) return stk->head;
    cnode *temp = popFromStack(stk);
    cnode *result =  searchNodeInStack(stk,word);
    pushToStack(stk,temp);
    return result;
}
void insertSorted(TStack *stk , cnode *newnode){ // used to insert a node in the stack wiht maintaining order
    if(isStackEmpty(stk) || strcmp(newnode->word,peakStack(stk)->word) <0){
        pushToStack(stk,newnode);
        return;
    }
    cnode *temp = popFromStack(stk);
    insertSorted(stk,newnode);
    pushToStack(stk,temp);
}
void enqueue(TQueue *queue,char *word){
    QNode *newnode = (QNode *)malloc(sizeof(QNode));
    strcpy(newnode->word,word);
    newnode->next = NULL;
    if(queue->head == NULL){
        queue->head = queue->tail = newnode;
        return;
    }
    queue->tail->next = newnode;
    queue->tail = newnode;
}
void insertsortedtoqueue(TQueue *queue,TStack *stk){// used to convert sorted stack to a sorted queue
    if(isStackEmpty(stk)) return;
    cnode *temp = popFromStack(stk);
    enqueue(queue,temp->word);
    insertsortedtoqueue(queue,stk);
    pushToStack(stk,temp);
}
void insertSortedToList(TList2 *list,TStack *stk){//used to convert sorted stack to a sorted linked list
    if(isStackEmpty(stk)) return;
    cnode *temp = popFromStack(stk);
    insertSortedToList(list,stk);
    dnode *newnode = (dnode *)malloc(sizeof(dnode));
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
cnode *copyNode(cnode *src){
    cnode *newNode = (cnode *)malloc(sizeof(cnode));
    newNode->charCount =src->charCount;
    newNode->vowelCount = src->vowelCount;
    strcpy(newNode->word,src->word);
    strcpy(newNode->antonym,src->antonym);
    strcpy(newNode->synonym,src->synonym);
    return newNode;
}
//---------------------------------------------------------------------------

TList *getSynWords(FILE *f){
    f = fopen("words.txt","r");
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
    f = fopen("words.txt","r");
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
    node *current = syn->head;
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
    node *current = syn->head;
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
    node *current = syn->head;
    while(current->next){
        node *temp = current;
        node *minnode = current;
        while(temp){
            if(strcmp(temp->word,minnode->word) <0){
                minnode = temp;
            }
            temp = temp->next;
        }
        if(minnode != current) SwapData(minnode,current);
        current = current->next;
    }
    return syn;
}
TList *sortWord2(TList *syn){
    if(syn->head == NULL || (syn->head)->next == NULL) return syn;
    node *current = syn->head;
    while(current->next){
        node *temp = current;
        node *minnode = current;
        while(temp){
            if(temp->charCount < minnode->charCount){
                minnode = temp;
            }
            temp = temp->next;
        }
        if(minnode != current) SwapData(minnode,current);
        current = current->next;
    }
    return syn;
}
TList *sortWord3(TList *syn){
    if(syn->head == NULL || (syn->head)->next == NULL) return syn;
    node *current = syn->head;
    while(current->next){
        node *temp = current;
        node *maxnode = current;
        while(temp){
            if(temp->vowelCount > maxnode->vowelCount){
                maxnode = temp;
            }
            temp = temp->next;
        }
        if(maxnode != current) SwapData(maxnode,current);
        current = current->next;
    }
    return syn;
}


void deleteWord(FILE *f, TList *syn, TList *ant, char *word){
    //delete from the File(the file will be overwritten)
    f = fopen("words.txt", "r");
    if(f == NULL){
        printf("Error opening file 'words.txt'!\n");
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
    remove("words.txt");
    rename("tempFile.txt","words.txt");
    //delte from sysnonyms List
    node *current = syn->head;
    while(syn->head && strcmp(syn->head->word,word) == 0){
        syn->head = syn->head->next;
    }
    while(current && current->next){
        if(strcmp(current->next->word,word) == 0){
            node *temp = current->next;
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
            node *temp = current->next;
            current->next = current->next->next;
            free(temp);
        }else current = current->next;
    }
    
}
void updateWord(FILE *f , TList *syn, TList *ant, char *word, char *syne, char *anton){
    //update in the file
    f = fopen("words.txt","r");
    if(f == NULL){
        printf("Error opening the file 'words.txt'!\n");
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
    remove("words.txt");
    rename("tempFile.txt","words.txt");
    //update in the lists
    node *current = syn->head;
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
TList *similarWord(TList *syn, char *word,int  rate){// rate should be a value from 0-100 (as a percentage)
    TList *newlist = (TList *)malloc(sizeof(TList));
    newlist->head = NULL;
    node *current = syn->head;
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
    node *current = syn->head;
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
    node *current = syn->head;
    while(current){
        if(isPalindrome(current->word,0,current->charCount -1)){
            node *newnode = (node *)malloc(sizeof(node));
            newnode->charCount = current->charCount,
            newnode->vowelCount = current->vowelCount;
            strcpy(newnode->word,current->word);
            strcpy(newnode->relatedWord,current->relatedWord);
            newnode->next = NULL;
            if(newlist->head ==NULL) newlist->head = newnode;
            else{
                node *temp2 = newlist->head;
                if(strcmp(temp2->word, newnode->word) > 0){
                    newnode->next = newlist->head;
                    newlist->head= newnode;
                    continue;
                }
                while(temp2->next && strcmp(temp2->next->word, newnode->word) < 0) temp2 = temp2->next;
                node *temp = temp2->next;
                temp2->next = newnode;
                newnode->next = temp;
            } 
        }
        current = current->next;
    }
    return newlist;
}

TList2 *merge(TList *syn, TList *ant){ // it assumes that they're in the right order , and contain same words
    TList2 *newlist = (TList2 *)malloc(sizeof(TList2));
    newlist->head = newlist->tail =  NULL;
    node *current = syn->head;
    node *current2 = ant->head;
    while(current && current2){
        dnode *newnode = (dnode *)malloc(sizeof(dnode));
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
            dnode *temp = newlist->head;
            while(temp->next) temp = temp->next;
            temp->next = newnode;
            newnode->prev = temp;
            newlist->tail  = newnode;
        }
        
        current2 = current2->next;
        current  = current->next;
    }
    return newlist;
}
TList3 *merge2(TList *syn, TList *ant){
    TList3 *newlist = (TList3 *)malloc(sizeof(TList3));
    newlist->head = newlist->tail = NULL;
    node *current = syn->head;
    node *current2 = ant->head;
    while(current && current2){
        cnode *newnode= (cnode *)malloc(sizeof(cnode));
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
    f = fopen("words.txt","a");
    if(!f){
        printf("Cannot open the file 'words.txt'\n");
        return;
    }
    fprintf(f,"%s=%s#%s\n",word,syne,anton);
    fclose(f);
}

int compareNodes(const void *a, const void *b){ // used for the quick sort;
    node *nodeA =*(node **)a;
    node *nodeB = *(node **)b;
    int countA =count_syllables(nodeA->word);
    int countB = count_syllables(nodeB->word);
    if(countA != countB) {
        return countA - countB;
    }
    return strcmp(nodeA->word,nodeB->word);
}
TQueue *syllable(TList *syn){
    //coutn the number of words in syn list
    int length  =0;
    node *tempLength= syn->head;
    while(tempLength){length++;tempLength = tempLength->next;}
    
    // array of Node poniters
    node **arr = (node **)malloc(length*sizeof(node *));
    tempLength = syn->head;
    for(int i = 0 ; i < length ;i++){
        arr[i] = tempLength;
        tempLength = tempLength->next;
    }

    //sort the array based on syllbales count (we will use quick sort(from stdlib library))
    qsort(arr,length,sizeof(node *),compareNodes);

    //create the queue and add entries
    TQueue *queue = createQueue();
    for(int i = 0 ; i < length ;i++){
        enqueue(queue,arr[i]->word);
    }
    free(arr);
    return queue;
}
TQueue **prounounciation(TList *syn){
    TQueue **queues = (TQueue **)malloc(3*sizeof(TQueue *));
    queues[SHORT] = createQueue();
    queues[LONG] = createQueue();
    queues[DIPHTHONG] = createQueue();
    node *current = syn->head;
    while(current){
        enqueue(queues[getVowelType(current->word)],current->word);
        current = current->next;
    }
    return queues;
}
TQueue *toQueue(TList2 *merged){
    TQueue *q = createQueue();
    if(merged->head == NULL) return q;
    dnode *current = merged->head;
    while(current){
        enqueue(q,current->word);
        current = current->next;
    }
    return q;
}



// Part Two : ----------------------------------------------------------------------------------------

TStack *toStack(TList2 *merged){
    TStack *stk = (TStack *)malloc(sizeof(TStack));
    stk->head = NULL;
    if(merged->head == NULL) return stk;
    dnode *current = merged->head;
    while(current){
        cnode *newnode = (cnode *)malloc(sizeof(cnode));
        newnode->charCount = current->charCount;
        newnode->vowelCount = current->vowelCount;
        strcpy(newnode->word,current->word);
        strcpy(newnode->antonym,current->antonym);
        strcpy(newnode->synonym,current->synonym);
        newnode->next = NULL;
        pushToStack(stk,newnode);
        current = current->next;
    }
    return stk;
}  
TStack *getInfWordStack(TStack *stk, char *word){
    cnode *nod = searchNodeInStack(stk,word);
    if(nod) printf("%s = %s # %s(Length = %d, Vowels Count %d)\n",nod->word,nod->synonym,nod->antonym,nod->charCount,nod->vowelCount);
    return stk;
}
TStack *sortWordStack(TStack *stk){
    if(!isStackEmpty(stk)){
        cnode *temp  = popFromStack(stk);
        sortWordStack(stk);
        insertSorted(stk,temp);
    }
    return stk;
}
TStack *deleteWordStack(TStack *stk, char *word){
    if(isStackEmpty(stk)) return stk;
    if(strcmp(word,peakStack(stk)->word) == 0){
        cnode *temp = popFromStack(stk);
        free(temp);
        temp = NULL;
        // return stk; // if we want to delete only first occurence
    }
    cnode *temp2 = popFromStack(stk);
    deleteWordStack(stk,word);
    pushToStack(stk,temp2);
    return stk;
}
TStack *updateWordStack(TStack *stk, char *word, char *syne, char *anton){
    if(isStackEmpty(stk)) return stk;
    if(strcmp(peakStack(stk)->word,word) == 0){
        cnode *temp = peakStack(stk);
        strcpy(temp->antonym , anton);
        strcpy(temp->synonym,syne);
        // return stk; // if we want to delete only first occurence
    }
    cnode *temp = popFromStack(stk);
    updateWordStack(stk,word,syne,anton);
    pushToStack(stk,temp);
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
    cnode *newnode = (cnode *)malloc(sizeof(cnode));
    strcpy(newnode->word,word);
    strcpy(newnode->antonym,anton);
    strcpy(newnode->synonym,syne);
    newnode->charCount = strlen(word);
    newnode->vowelCount = countVowels(word);
    insertSorted(stk,newnode);
    return stk;
}
bool isSimpleStackEmpty(Tstack2 *stk){
    return stk->head == NULL;
}
void push(Tstack2 *stk,char c){
    Tnode *newnode = (Tnode *)malloc(sizeof(Tnode));
    newnode->c = c;
    newnode->next = stk->head;
    stk->head = newnode;
}
char pop(Tstack2 *stk){
    char c = -1;
    if(!isSimpleStackEmpty(stk)){
        Tnode *temp = stk->head;
        stk->head = stk->head->next;
        c= temp->c;
        free(temp);
    }
    return c;
}
int lengthStack(TStack *stk){
    if (isStackEmpty(stk)) return 0;
    cnode *temp = popFromStack(stk);
    int count = 1+ lengthStack(stk);
    pushToStack(stk,temp);
    return count;
}
int compareNodes2(const void *a, const void *b){ // used for the quick sort;
    cnode *nodeA =*(cnode **)a;
    cnode *nodeB = *(cnode **)b;
    int countA =count_syllables(nodeA->word);
    int countB = count_syllables(nodeB->word);
    if(countA != countB) {
        return countA - countB;
    }
    return strcmp(nodeA->word,nodeB->word);
}
void addNodesToArray(cnode **arr,int index,TStack *stk){
    if(isStackEmpty(stk)) return ;
    cnode *temp = popFromStack(stk);
    arr[index] = temp;
    addNodesToArray(arr,index+1,stk);
    pushToStack(stk,temp);
}
TStack *syllableStack(TStack *stk){
    //count the length
    int length = lengthStack(stk);

    //put the nodes's pointerts into an array
    cnode **arr = (cnode **)malloc(length*sizeof(cnode *));
    addNodesToArray(arr,0,stk);

    //sort the array using quick sort (from stdlib library)
    qsort(arr,length,sizeof(cnode *),compareNodes2);

    //Create the stak and add the nodes
    TStack *newStack = (TStack *)malloc(sizeof(TStack));
    newStack->head = NULL;
    for(int i= 0 ; i < length ; i++){
        pushToStack(newStack,arr[i]);
    }
    return newStack;

}
void InserToPronounciationStacks(TStack *stk, TStack **stacks){
    if(isStackEmpty(stk)) return;
    cnode *temp1 = popFromStack(stk);
    cnode *temp = copyNode(temp1);
    pushToStack(stacks[getVowelType(temp->word)],temp);
    InserToPronounciationStacks(stk,stacks);
    pushToStack(stk,temp1); 
}
TStack **prounounciationStack(TStack *stk){
    TStack **stacks = (TStack **)malloc(3*sizeof(TStack *));
    stacks[SHORT] = createStack();
    stacks[LONG] = createStack();
    stacks[DIPHTHONG] = createStack();
    InserToPronounciationStacks(stk,stacks);
    return stacks;
    
}
void smallestword(TStack *stk,cnode **minnode){
    if(isStackEmpty(stk)) return;
    cnode *temp = popFromStack(stk);
    if(*minnode == NULL || temp->charCount < (*minnode)->charCount) *minnode = temp;
    smallestword(stk,minnode);
    pushToStack(stk,temp);
}
char *getSmallest(TStack *stk) {
    if (isStackEmpty(stk)) {
        return NULL;
    }
    cnode *minnode = NULL;
    smallestword(stk, &minnode);

    return minnode ? minnode->word : NULL;
}
void insertWordInverse(char *word,int index,Tstack2 *stk){
    if(index == strlen(word)) return;
    push(stk,word[index]);
    insertWordInverse(word,index+1,stk);
}
bool isPalyndromeStack(char *word){
    Tstack2 *stk = (Tstack2 *)malloc(sizeof(Tstack2));
    stk->head = NULL;
    insertWordInverse(word,0,stk);
    int i = 0;
    while(!isSimpleStackEmpty(stk)){
        if(pop(stk) != word[i]){while (!isSimpleStackEmpty(stk)){pop(stk);}free(stk); return false;}
        i++;
    }
    free(stk);
    return true;
}
TStack *StackRev(TStack *stk){
    if(isStackEmpty(stk)) return stk;
    cnode *temp = popFromStack(stk);
    stk = StackRev(stk);
    pushToStack(stk,temp);
    return stk;
}
//--------------------------------------------------------------------------------------
