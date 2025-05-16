#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>
#include "Recursion_2.h"
#include "../🔹PART I/Recursion_1.h" 

FILE *openFile(const char *filename, const char *mode) {
    FILE *f = fopen(filename, mode);
    if (f == NULL) {
        printf("Error opening file: %s\n", filename);
        exit(1);
    }
    return f;
}

char *readLine(FILE *file) {
    static char line[256];
    if (fgets(line, sizeof(line), file) != NULL) {
        return line;
    }
    return NULL;
}

void parseLineS(char *line, char *word, char *syn) {
    sscanf(line, "%[^=]=%s", word, syn);
}

void parseLineA(char *line, char *word, char *ant) {
    sscanf(line, "%[^#]#%s", word, ant);
}

int countWordOccurrence(FILE *f, const char *word) {
    char line[512]; 
    int count = 0;
    
    if (fgets(line, sizeof(line), f) == NULL)  return 0;  

    char *pos = line;
    
    while ((pos = strstr(pos, word)) != NULL) {
        count++;
        pos += strlen(word);  
    }
    
    return count + countWordOccurrence(f, word);
}

FILE *removeWordOccurence(FILE *f, char *word){
    char line1[512];
    FILE *temp=fopen("temp.txt","a");
    if (!temp)
    {
        perror("File name not found");
        return NULL;
    }
    
    if (fgets(line1, sizeof(line1), f) == NULL)  return NULL;  

    char *pos=line1;
    
    while ((pos =strstr(pos,word))!=NULL)
    {
        memmove(pos,pos+strlen(word),strlen(pos+strlen(word))+1);
    }
    fputs(line1,temp);
    removeWordOccurence(f,word);
    fclose(f);
    return temp;
} 

FILE *replaceWordOccurence(FILE *f, char *word, char *rep){
    char line1[512];
    FILE *temp=fopen("temp.txt","a");
    if (!temp)
    {
        perror("File name not found");
        return NULL;
    }
    
    if (fgets(line1, sizeof(line1), f) == NULL)  return NULL;  

    char *pos=line1;
    if (strlen(word)>=strlen(rep))
    {
        while ((pos=strstr(pos,word))!=NULL)
        {
            memcpy(pos, rep, strlen(rep));
            memmove(pos + strlen(rep), pos + strlen(word), strlen(pos + strlen(word)) + 1);
            
        } 
        fputs(line1,temp);
        replaceWordOccurence(f,word,rep);
        fclose(f);
        return temp;
    }
    int found=0;
    char line[512];
    while ((pos=strstr(pos,word))!=NULL)
    {
        strncpy(line,line1,pos-line1);
        strcpy(line+(pos-line1),rep);
        strcpy(line+(pos-line1)+strlen(rep),pos+strlen(word));
        pos+=strlen(word);
        found=1;
        strcpy(line1,line);
    } 
    if (found) {
        fputs(line,temp);
    }else fputs(line1,temp);
    replaceWordOccurence(f,word,rep);
    fclose(f);
    return temp;
}

void permute(char *word, int index) {
    int len = strlen(word);
    if (index == len) {
        printf("%s\t", word);
        return;
    }
    loop(index,len,index,word);
}

void loop(int i, int end, int index, char *word){
    if (i >= end) return;
    
    char temp = word[index];
    word[index] = word[i];
    word[i] = temp;
          
    permute(word, index + 1);
          
    temp = word[index];
    word[index] = word[i];
    word[i] = temp;
    loop(i+1,end,index,word);
}

void wordPermutation(char *word) {
    permute(word,0);
}

void generateSubsequences(char *word, int index, char *currentSubseq, int subseqIndex) {
    int len = strlen(word);
    
    if (index == len) {
        currentSubseq[subseqIndex] = '\0';  
        printf("%s\t", currentSubseq);
        return;
    }
    
    currentSubseq[subseqIndex] = word[index];
    generateSubsequences(word, index + 1, currentSubseq, subseqIndex + 1);
    
    generateSubsequences(word, index + 1, currentSubseq, subseqIndex);
}

void subseqWord(char *word) {
    int len = strlen(word);
    char currentSubseq[len + 1]; 
    generateSubsequences(word, 0, currentSubseq, 0);
}

int max(int a, int b){
    if (a > b) return a;
    return b;
}

int longestSubseqWord(char *word1, char *word2){
    if (word1[0] == '\0' || word2[0] == '\0') return 0;
    
    if (word1[0] == word2[0]) {
        return 1 + longestSubseqWord(word1+1, word2+1);
    } else {
        return max(longestSubseqWord(word1, word2+1), longestSubseqWord(word1+1, word2));
    }
}

int distinctSubseqWord(char *word) {
    if (*word == '\0') return 1;

    int count = 2 * distinctSubseqWord(word + 1);
    
    char *next = word + 1;
    while (*next != '\0') {
        if (*next == *word) {
            count -= distinctSubseqWord(next + 1);
            break;
        }
        next++;
    }

    return count;
}

bool isPalindromWord(char *word){
    int len = strlen(word);
    if (len == 1) return true;
    char temp[len-1];
    temp[len-1] = '\0';
    if (word[0] == word[len-1]) {
        strcpy(temp, word+1);
        temp[len-2] = '\0';
        return isPalindromWord(temp);
    }
    return false;
}

#define MAX_LINE_LENGTH 512

typedef struct {
    char **lines;
    int top;
    int capacity;
} Stack;

Stack *createStack(int capacity) {
    Stack *stack = (Stack *)malloc(sizeof(Stack));
    stack->capacity = capacity;
    stack->top = -1;
    stack->lines = (char **)malloc(capacity * sizeof(char *));
    return stack;
}

void push(Stack *stack, const char *line) {
    if (stack->top < stack->capacity - 1) {
        stack->top++;
        stack->lines[stack->top] = strdup(line);
    }
}

char *pop(Stack *stack) {
    if (stack->top == -1) {
        return NULL;
    }
    char *line = stack->lines[stack->top];
    stack->top--;
    return line;
}

void reverseFile(const char *inputFilename, const char *outputFilename) {
    FILE *inputFile = fopen(inputFilename, "r");
    if (!inputFile) {
        perror("Unable to open the input file");
        return;
    }

    FILE *outputFile = fopen(outputFilename, "w");
    if (!outputFile) {
        perror("Unable to open the output file");
        fclose(inputFile);
        return;
    }

    char line[MAX_LINE_LENGTH];
    int lineCount = 0;
    
    while (fgets(line, sizeof(line), inputFile) != NULL) {
        lineCount++;
    }
    Stack *stack = createStack(lineCount);
    rewind(inputFile);

    while (fgets(line, sizeof(line), inputFile) != NULL) {
         push(stack, line);
    }

    char *lineToWrite;
    while ((lineToWrite = pop(stack)) != NULL) {
        fputs(lineToWrite, outputFile);
        free(lineToWrite);
    }

    fclose(inputFile);
    fclose(outputFile);
    free(stack->lines);
    free(stack);
}

void replaceFile(const char *original, const char *temp) {
    remove(original);        
    rename(temp, original);  
}