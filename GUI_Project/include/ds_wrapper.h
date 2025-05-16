#ifndef DS_WRAPPER_H
#define DS_WRAPPER_H

// Function category structure
#include <gtk/gtk.h>  // Main GTK include - contains all GTK widgets
#include "lib/trees.h"
#include "lib/code.h"
#include "lib/recursion_2.h"

typedef struct {
    char *name;
    char *description;
} FunctionCategory;

// Make sure bool is defined if needed
#ifndef __cplusplus
#ifndef bool
#include <stdbool.h>
#endif
#endif

// Forward declarations of all used functions to avoid compilation issues
// Trees functions
TTree2* fillTree(const char* filename);
void printTreeNodeCharacteristics(TTree2* tr, char* word);
void TraversalBSTinOrder(TTree2* tr);

// Recursion functions
int countWordOccurrence(FILE* f, const char* word);
bool isPalindromWord(char* word);
void wordPermutation(char* word);

// Code functions
TList* getSynWords(FILE* f);
TList* sortWord(TList* syn);
TList* sortWord2(TList* syn);
TList* sortWord3(TList* syn);
void printWords(TList* list, int num);

// Rename conflicting enum types to avoid conflicts with GTK
typedef enum VowelType DS_VowelType;
#define SHORT DS_SHORT
#define LONG DS_LONG
#define DIPHTHONG DS_DIPHTHONG
#define UNKNOWN DS_UNKNOWN

#endif // DS_WRAPPER_H