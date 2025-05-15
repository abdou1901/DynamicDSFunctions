#include "LinkedLists.h"

// Node creation and list operations
node *createNode(char *word, char *relatedWord) {
    node *newnode = (node *)malloc(sizeof(node));
    newnode->next = NULL;
    newnode->charCount = strlen(word);
    newnode->vowelCount = countVowels(word);
    strcpy(newnode->relatedWord, relatedWord);
    strcpy(newnode->word, word);
    return newnode;
}

void addNodeAtEnd(TList *list, char *word, char *relatedWord) {
    node *newnode = createNode(word, relatedWord);
    newnode->next = NULL;
    if(list->head == NULL) {
        list->head = newnode;
        return;
    }
    node *current = list->head;
    while(current->next) current = current->next;
    current->next = newnode;
}

void SwapData(node *node1, node *node2) {
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

void printWords(TList *list, int option) {
    node *current = list->head;
    if(current == NULL) {
        printf("Empty List !\n");
        return;
    }
    int i = 1;
    while(current) {
        printf("%d) %s %s %s (Length = %d, Vowels Count %d)\n", 
               i, current->word, option == 0 ? "=" : "#", 
               current->relatedWord, current->charCount, current->vowelCount);
        i++;
        current = current->next;
    }
}

void printWords2(TList2 *list) {
    dnode *current = list->head;
    if(current == NULL) {
        printf("Empty List !\n");
        return;
    }
    int i = 1;
    while(current) {
        printf("%d) %s = %s # %s(Length = %d, Vowels Count %d)\n", 
               i, current->word, current->synonym, 
               current->antonym, current->charCount, current->vowelCount);
        i++;
        current = current->next;
    }
}

void printWords3(TList3 *list) {
    if (list->head == NULL) {
        printf("Empty List!\n");
        return;
    } 
    cnode *current = list->head;
    int i = 1;
    do {
        printf("%d) %s = %s # %s (Length = %d, Vowels Count %d)\n", 
               i, current->word, current->synonym, current->antonym,
               current->charCount, current->vowelCount);
        current = current->next;
        i++;
    } while (current != list->head);
}

// File operations with linked lists
TList *getSynWords(FILE *f) {
    f = fopen("words.txt", "r");
    if (!f) {
        perror("Failed to open file");
        return NULL;
    }
    TList *list = (TList *)malloc(sizeof(TList));
    list->head = NULL;
    char buffer[170];
    char word[50];
    char syn[50];
    while(fgets(buffer, sizeof(buffer), f) != NULL) {
        if (sscanf(buffer, "%49[^=] = %49[^#]", word, syn) == 2) {
            addNodeAtEnd(list, word, syn);
        }
    }
    fclose(f);
    return list;
}

TList *getAntoWords(FILE *f) {
    f = fopen("words.txt", "r");
    if (!f) {
        perror("Failed to open file");
        return NULL;
    }
    TList *list = (TList *)malloc(sizeof(TList));
    list->head = NULL;
    char buffer[175];
    char word[50];
    char antonym[50];
    while(fgets(buffer, sizeof(buffer), f)) {
        if(sscanf(buffer, " %49[^=]=%*[^#]#%49[^\n]", word, antonym) == 2) {
            addNodeAtEnd(list, word, antonym);
        }
    }
    fclose(f);
    return list;
}

void getInfWord(TList *syn, TList *ant, char *word) {
    node *current = syn->head;
    printCentered(word, 28);
    bool found = false;
    while(current) {
        if(strcmp(current->word, word) == 0) {
            found = true;
            printf("Char Count = %d\nVowels Count = %d\nSynonym = %s\n", 
                   current->charCount, current->vowelCount, current->relatedWord);
            break;
        }
        current = current->next;
    }
    if(current == NULL) {
        printf("Word not found in synonyms dictionary!\n");
    }
    
    current = ant->head;
    while(current) {
        if(strcmp(current->word, word) == 0) {
            if(found)
                printf("Antonym = %s\n", current->relatedWord);
            else
                printf("Antonym = %s\nChar Count = %d\nVowels Count = %d\n", 
                       current->relatedWord, current->charCount, current->vowelCount);
            break;
        }
        current = current->next;
    }
    if(current == NULL) {
        printf("Word Not found in antonyms dictionary! \n");
    }
    printf("----------------------------\n");
}

void getInfWord2(TList *syn, TList *ant, char *inf) {
    bool found = false;
    node *current = syn->head;
    printCentered(inf, 28);
    while(current) {
        if(strcmp(current->relatedWord, inf) == 0) {
            printf("Is a synonym for : %s\nChars Count = %d\nVowels Count = %d\n", 
                   current->word, current->charCount, current->vowelCount);
            found = true;
            break;
        }
        current = current->next;
    }
    if(!found) {
        current = ant->head;
        while(current) {
            if(strcmp(current->relatedWord, inf) == 0) {
                printf("Is an antonym for : %s\nChars Count = %d\nVowels Count = %d\n", 
                       current->word, current->charCount, current->vowelCount);
                found = true;
                break;
            }
            current = current->next;
        }
        if(!found) {
            printf("Word Not found neither in synonym nor antonym list.\n");
        }
    }
    printf("----------------------------\n");
}

void deleteWord(FILE *f, TList *syn, TList *ant, char *word) {
    // Delete from the File (the file will be overwritten)
    f = fopen("words.txt", "r");
    if(f == NULL) {
        printf("Error opening file 'words.txt'!\n");
        return;
    }
    FILE *tempFile = fopen("tempFile.txt", "w");
    if(tempFile == NULL) {
        printf("Error creating temporary file!\n");
        fclose(f);
        return;
    }
    char buffer[175];
    char wordFromFile[50];
    while(fgets(buffer, sizeof(buffer), f)) {
        if(sscanf(buffer, "%49[^=]", wordFromFile) == 1) {
            if(strcmp(word, wordFromFile) != 0) {
                fputs(buffer, tempFile);
            }
        } else {
            fputs(buffer, tempFile);
        }
    }
    fclose(f);
    fclose(tempFile);
    remove("words.txt");
    rename("tempFile.txt", "words.txt");
    
    // Delete from synonyms List
    node *current = syn->head;
    while(syn->head && strcmp(syn->head->word, word) == 0) {
        syn->head = syn->head->next;
    }
    while(current && current->next) {
        if(strcmp(current->next->word, word) == 0) {
            node *temp = current->next;
            current->next = current->next->next;
            free(temp);
        } else {
            current = current->next;
        }
    }

    // Delete from Antonym List
    current = ant->head;
    while(ant->head && strcmp(ant->head->word, word) == 0) {
        ant->head = ant->head->next;
    }
    while(current && current->next) {
        if(strcmp(current->next->word, word) == 0) {
            node *temp = current->next;
            current->next = current->next->next;
            free(temp);
        } else {
            current = current->next;
        }
    }
}

void updateWord(FILE *f, TList *syn, TList *ant, char *word, char *syne, char *anton) {
    // Update in the file
    f = fopen("words.txt", "r");
    if(f == NULL) {
        printf("Error opening the file 'words.txt'!\n");
        return;
    }
    FILE *tempFile = fopen("tempFile.txt", "w");
    if(tempFile == NULL) {
        printf("Error creating temporary file!\n");
        fclose(f);
        return;
    }
    char buffer[175];
    char newLine[175];
    while(fgets(buffer, sizeof(buffer), f)) {
        if(sscanf(buffer, "%49[^=]", newLine) == 1) {
            if(strcmp(newLine, word) == 0) {
                strcat(newLine, "=");
                strcat(newLine, syne);
                strcat(newLine, "#");
                strcat(newLine, anton);
                strcat(newLine, "\n");
                fputs(newLine, tempFile);
            } else {
                fputs(buffer, tempFile);
            }
        } else {
            fputs(buffer, tempFile);
        }
    }
    fclose(f);
    fclose(tempFile);
    remove("words.txt");
    rename("tempFile.txt", "words.txt");
    
    // Update in the lists
    node *current = syn->head;
    while(current) {
        if(strcmp(current->word, word) == 0) {
            strcpy(current->relatedWord, syne);
        }
        current = current->next;
    }

    current = ant->head;
    while(current) {
        if(strcmp(current->word, word) == 0) {
            strcpy(current->relatedWord, anton);
        }
        current = current->next;
    }
}

void addWord(FILE *f, TList *syn, TList *ant, char *word, char *syne, char *anton) {
    addNodeAtEnd(syn, word, syne);
    addNodeAtEnd(ant, word, anton);

    // Add it to the text file
    f = fopen("words.txt", "a");
    if(!f) {
        printf("Cannot open the file 'words.txt'\n");
        return;
    }
    fprintf(f, "%s=%s#%s\n", word, syne, anton);
    fclose(f);
}

// Sorting and searching
TList *sortWord(TList *syn) {
    if(syn->head == NULL || (syn->head)->next == NULL) return syn;
    node *current = syn->head;
    while(current->next) {
        node *temp = current;
        node *minnode = current;
        while(temp) {
            if(strcmp(temp->word, minnode->word) < 0) {
                minnode = temp;
            }
            temp = temp->next;
        }
        if(minnode != current) SwapData(minnode, current);
        current = current->next;
    }
    return syn;
}

TList *sortWord2(TList *syn) {
    if(syn->head == NULL || (syn->head)->next == NULL) return syn;
    node *current = syn->head;
    while(current->next) {
        node *temp = current;
        node *minnode = current;
        while(temp) {
            if(temp->charCount < minnode->charCount) {
                minnode = temp;
            }
            temp = temp->next;
        }
        if(minnode != current) SwapData(minnode, current);
        current = current->next;
    }
    return syn;
}

TList *sortWord3(TList *syn) {
    if(syn->head == NULL || (syn->head)->next == NULL) return syn;
    node *current = syn->head;
    while(current->next) {
        node *temp = current;
        node *maxnode = current;
        while(temp) {
            if(temp->vowelCount > maxnode->vowelCount) {
                maxnode = temp;
            }
            temp = temp->next;
        }
        if(maxnode != current) SwapData(maxnode, current);
        current = current->next;
    }
    return syn;
}

TList *similarWord(TList *syn, char *word, int rate) {
    TList *newlist = (TList *)malloc(sizeof(TList));
    newlist->head = NULL;
    node *current = syn->head;
    while(current) {
        if(matchRate(current->word, word) >= rate) {
            addNodeAtEnd(newlist, current->word, current->relatedWord);
        }
        current = current->next;
    }
    return newlist;
}

TList *countWord(TList *syn, char *prt) {
    TList *newlist = (TList *)malloc(sizeof(TList));
    newlist->head = NULL;
    node *current = syn->head;
    while(current) {
        if(strstr(current->word, prt)) {
            addNodeAtEnd(newlist, current->word, current->relatedWord);
        }
        current = current->next;
    }
    return newlist;
}

TList *palindromWord(TList *syn) {
    TList *newlist = (TList *)malloc(sizeof(TList));
    newlist->head = NULL;
    node *current = syn->head;
    while(current) {
        if(isPalindrome(current->word, 0, current->charCount - 1)) {
            node *newnode = (node *)malloc(sizeof(node));
            newnode->charCount = current->charCount;
            newnode->vowelCount = current->vowelCount;
            strcpy(newnode->word, current->word);
            strcpy(newnode->relatedWord, current->relatedWord);
            newnode->next = NULL;
            if(newlist->head == NULL) {
                newlist->head = newnode;
            } else {
                node *temp2 = newlist->head;
                if(strcmp(temp2->word, newnode->word) > 0) {
                    newnode->next = newlist->head;
                    newlist->head = newnode;
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

// Merging functions
TList2 *merge(TList *syn, TList *ant) {
    TList2 *newlist = (TList2 *)malloc(sizeof(TList2));
    newlist->head = newlist->tail = NULL;
    node *current = syn->head;
    node *current2 = ant->head;
    while(current && current2) {
        dnode *newnode = (dnode *)malloc(sizeof(dnode));
        newnode->charCount = current2->charCount;
        newnode->vowelCount = current2->vowelCount;
        strcpy(newnode->word, current2->word);
        strcpy(newnode->synonym, current->relatedWord);
        strcpy(newnode->antonym, current2->relatedWord);
        newnode->next = NULL;
        newnode->prev = NULL;
        if(newlist->head == NULL) {
            newlist->head = newlist->tail = newnode;
        } else {
            dnode *temp = newlist->head;
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

TList3 *merge2(TList *syn, TList *ant) {
    TList3 *newlist = (TList3 *)malloc(sizeof(TList3));
    newlist->head = newlist->tail = NULL;
    node *current = syn->head;
    node *current2 = ant->head;
    while(current && current2) {
        cnode *newnode = (cnode *)malloc(sizeof(cnode));
        newnode->charCount = current2->charCount;
        newnode->vowelCount = current2->vowelCount;
        strcpy(newnode->antonym, current2->relatedWord);
        strcpy(newnode->word, current2->word);
        strcpy(newnode->synonym, current->relatedWord);
        newnode->next = NULL;
        if(newlist->head == NULL) {
            newlist->head = newlist->tail = newnode;
        } else {
            newlist->tail->next = newnode;
            newnode->next = newlist->head;
            newlist->tail = newnode;
        }
        current2 = current2->next;
        current = current->next;
    }
    return newlist;
}