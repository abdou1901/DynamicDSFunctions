#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include"PART I/Recursion_1.h"
#include "PART II/Recursion_2.h"

int main() {
    //! PART ONE TESTS
    
    //*reverse Linked List
    Node *head = NULL, *tail = NULL;
    Node *n1 = (Node*)malloc(sizeof(Node));
    Node *n2 = (Node*)malloc(sizeof(Node));
    n1->id = 10; strcpy(n1->message, "First");
    n2->id = 20; strcpy(n2->message, "Second");
    n1->next = n2; n2->prev = n1;
    head = n1; tail = n2;

   printf("Original List:\n");
    printf("ID: %d, Message: %s\n", head->id, head->message);
    printf("ID: %d, Message: %s\n", head->next->id, head->next->message);

    reverseListRecursive(&head, &tail, head);

    printf("\nReversed List:\n");
    printf("ID: %d, Message: %s\n", head->id, head->message);
    printf("ID: %d, Message: %s\n", head->next->id, head->next->message);
/*
    //*math functions
    printf("\nFactorial of 5: %d\n", factorial(5));
    printf("Fibonacci of 6: %d\n", fibonacci(6));

    //*findMaxIDRecursive
    printf("\nMax ID in list: %d\n", findMaxIDRecursive(head, head, 0));

    //*binary Search on an array
    Node logs[3] = {
        {5, "", "", "Log5", NULL, NULL},
        {10, "", "", "Log10", NULL, NULL},
        {20, "", "", "Log20", NULL, NULL}
    };
    printf("\nBinary Search for ID 10: Index = %d\n", binarySearchLogs(logs, 0, 2, 10));
*/
    //*infixToPostfixRecursive
    char infix[] = "A+B*C";
    char postfix[100];
    int postIndex = 0;
    infixToPostfixRecursive(infix, 0, postfix, &postIndex);
    postfix[postIndex] = '\0';
    printf("\nPostfix Expression: %s\n", postfix);
/*
    //! PART TWO TESTS
    FILE *f = fopen("test.txt", "w+");
    if (f) {
        fputs("hello world hello everyone", f);
        fclose(f);

        //*count Occurrence
        f = fopen("test.txt", "r+");
        printf("\nWord Occurrence of 'hello': %d\n", countWordOccurrence(f, "hello"));
        fclose(f);

        //*remove Occurrence
        f = fopen("test.txt", "r+");
        f = removeWordOccurence(f, "hello");
        fclose(f);

        //*replace Occurrence
        f = fopen("test.txt", "r+");
        f = replaceWordOccurence(f, "world", "earth");
        fclose(f);
    } else {
        printf("\nFailed to open test.txt\n");
    }
    
    FILE *file = fopen("temp.txt", "r");
    if (file) {
        printf("\nContents of file after modification:\n");

        char ch;
        while ((ch = fgetc(file)) != EOF) {
            putchar(ch);
        }

        fclose(file);
    } else {
        printf("\nFailed to reopen file.\n");
    }

    char word[] = "abc";
    //*permutations
    printf("\nPermutations of 'abc':\n");
    wordPermutation(word);

    //*subsequences
    printf("\nSubsequences of 'abc':\n");
    subseqWord(word);

    char word1[] = "abcde";
    char word2[] = "ace";
    //*longestSubseqWord
    printf("\nLongest Common Subsequence between 'abcde' and 'ace': %d\n", 
           longestSubseqWord(word1, word2));

    //*distinctSubseqWord
    printf("\nDistinct Subsequences of 'abc': %d\n", distinctSubseqWord(word));

    //*palindrome check
    char palWord[] = "racecar";
    printf("\nIs 'racecar' a palindrome? %s\n", 
           isPalindromWord(palWord) ? "Yes" : "No");

    free(n1);
    free(n2);
*/
    return 0;
}