#include <windows.h>
#include <windowsx.h>
#include <commctrl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "functions_wrapper.h"

//* This isn't my own work i used youtube and AI its really obvious
//* Window handles
HWND hWnd;
HWND hCategoryCombo;
HWND hFunctionCombo;
HWND hArgsContainer;
HWND hRunButton;
HWND hResultText;
HWND hStatusBar;

//* Global tree pointer for storing the loaded tree
TTree2 *global_tree = NULL;

//* Global pointers for lists, stacks, and queues
TList *global_syn_list = NULL;
TList *global_ant_list = NULL;
TStack *global_stack = NULL;
TQueue *global_queue = NULL;

//* Function categories
typedef enum {
    CATEGORY_TREES,
    CATEGORY_CODE,
    CATEGORY_RECURSION,
    NUM_CATEGORIES
} FunctionCategory;

const char* category_names[NUM_CATEGORIES] = {
    "Trees",
    "Linked lists && Stacks && Queues",
    "Recursion"
};

//* Function information structure
typedef struct {
    const char *name;
    const char *description;
    int category;
    int num_args;
    const char **arg_names;
    const char **arg_types;
} FunctionInfo;

//* Function information array
FunctionInfo functions[] = {
    {"fillTree", "Load a dictionary from a file", CATEGORY_TREES, 1, 
     (const char*[]){"Filename"}, 
     (const char*[]){"string"}},
    
    {"printTreeNodeCharacteristics", "Print information about a word", CATEGORY_TREES, 2, 
     (const char*[]){"Tree", "Word"}, 
     (const char*[]){"tree", "string"}},
    
    {"TraversalBSTinOrder", "Print tree in-order traversal", CATEGORY_TREES, 1, 
     (const char*[]){"Tree"}, 
     (const char*[]){"tree"}},
    
    {"TraversalBSTpreOrder", "Print tree pre-order traversal", CATEGORY_TREES, 1, 
     (const char*[]){"Tree"}, 
     (const char*[]){"tree"}},
    
    {"TraversalBSTpostOrder", "Print tree post-order traversal", CATEGORY_TREES, 1, 
     (const char*[]){"Tree"}, 
     (const char*[]){"tree"}},
    
    {"deleteWordBST", "Delete a word from the tree", CATEGORY_TREES, 2, 
     (const char*[]){"Tree", "Word"}, 
     (const char*[]){"tree", "string"}},
    
    {"UpdateWordBST", "Update a word in the tree", CATEGORY_TREES, 4, 
     (const char*[]){"Tree", "Word", "Synonym", "Antonym"}, 
     (const char*[]){"tree", "string", "string", "string"}},
    
    {"deleteSyn", "Delete a synonym for a word", CATEGORY_TREES, 3, 
     (const char*[]){"Tree", "Word", "Synonym"}, 
     (const char*[]){"tree", "string", "string"}},
    
    {"deleteAnt", "Delete an antonym for a word", CATEGORY_TREES, 3, 
     (const char*[]){"Tree", "Word", "Antonym"}, 
     (const char*[]){"tree", "string", "string"}},
    
    {"HighSizeBST", "Show height and size of the tree", CATEGORY_TREES, 1, 
     (const char*[]){"Tree"}, 
     (const char*[]){"tree"}},
    
    {"LowestCommonAncestor", "Find lowest common ancestor of two words", CATEGORY_TREES, 3, 
     (const char*[]){"Tree", "Word1", "Word2"}, 
     (const char*[]){"tree", "string", "string"}},
    
    {"CountNodesRanges", "Count nodes with word length in range", CATEGORY_TREES, 3, 
     (const char*[]){"Tree", "Min Length", "Max Length"}, 
     (const char*[]){"tree", "int", "int"}},
    
    {"inOrderSuccesor", "Find in-order successor of a word", CATEGORY_TREES, 2, 
     (const char*[]){"Tree", "Word"}, 
     (const char*[]){"tree", "string"}},
    
    {"BSTMirror", "Create a mirror image of the tree", CATEGORY_TREES, 1, 
     (const char*[]){"Tree"}, 
     (const char*[]){"tree"}},
    
    {"isBalencedBST", "Check if the tree is balanced", CATEGORY_TREES, 1, 
     (const char*[]){"Tree"}, 
     (const char*[]){"tree"}},

    // Linked Lists functions
    {"getSynWords", "Get synonyms from file", CATEGORY_CODE, 1, 
     (const char*[]){"Filename"}, 
     (const char*[]){"string"}},
    
    {"getAntoWords", "Get antonyms from file", CATEGORY_CODE, 1, 
     (const char*[]){"Filename"}, 
     (const char*[]){"string"}},
    
    {"getInfWord", "Get information about a word", CATEGORY_CODE, 1, 
     (const char*[]){"Word"}, 
     (const char*[]){"string"}},
    
    {"sortWord", "Sort words alphabetically", CATEGORY_CODE, 0, 
     (const char*[]){""}, 
     (const char*[]){""}},
    
    {"sortWord2", "Sort words by character count", CATEGORY_CODE, 0, 
     (const char*[]){""}, 
     (const char*[]){""}},
    
    {"sortWord3", "Sort words by vowel count", CATEGORY_CODE, 0, 
     (const char*[]){""}, 
     (const char*[]){""}},
    
    {"deleteWord", "Delete a word", CATEGORY_CODE, 1, 
     (const char*[]){"Word"}, 
     (const char*[]){"string"}},
    
    {"updateWord", "Update a word", CATEGORY_CODE, 3, 
     (const char*[]){"Word", "Synonym", "Antonym"}, 
     (const char*[]){"string", "string", "string"}},
    
    {"similarWord", "Find similar words", CATEGORY_CODE, 2, 
     (const char*[]){"Word", "Match Rate"}, 
     (const char*[]){"string", "int"}},
    
    {"countWord", "Count words containing substring", CATEGORY_CODE, 1, 
     (const char*[]){"Substring"}, 
     (const char*[]){"string"}},
    
    {"palindromWord", "Find palindrome words", CATEGORY_CODE, 0, 
     (const char*[]){""}, 
     (const char*[]){""}},
    
    // Stack functions
    {"toStack", "Convert list to stack", CATEGORY_CODE, 0, 
     (const char*[]){""}, 
     (const char*[]){""}},
    
    {"getInfWordStack", "Get word info from stack", CATEGORY_CODE, 1, 
     (const char*[]){"Word"}, 
     (const char*[]){"string"}},
    
    {"sortWordStack", "Sort stack", CATEGORY_CODE, 0, 
     (const char*[]){""}, 
     (const char*[]){""}},
    
    {"deleteWordStack", "Delete word from stack", CATEGORY_CODE, 1, 
     (const char*[]){"Word"}, 
     (const char*[]){"string"}},
    
    {"updateWordStack", "Update word in stack", CATEGORY_CODE, 3, 
     (const char*[]){"Word", "Synonym", "Antonym"}, 
     (const char*[]){"string", "string", "string"}},
    
    {"addWordStack", "Add word to stack", CATEGORY_CODE, 3, 
     (const char*[]){"Word", "Synonym", "Antonym"}, 
     (const char*[]){"string", "string", "string"}},
    
    // Queue functions
    {"syllable", "Group words by syllable count", CATEGORY_CODE, 0, 
     (const char*[]){""}, 
     (const char*[]){""}},
    
    {"prounounciation", "Group words by pronunciation", CATEGORY_CODE, 0, 
     (const char*[]){""}, 
     (const char*[]){""}},
    
    {"stackToQueue", "Convert stack to queue", CATEGORY_CODE, 0, 
     (const char*[]){""}, 
     (const char*[]){""}},
    
    {"wordPermutation", "Generate all permutations of a word", CATEGORY_RECURSION, 1, 
     (const char*[]){"Word"}, 
     (const char*[]){"string"}},
    
    {"subseqWord", "Generate all subsequences of a word", CATEGORY_RECURSION, 1, 
     (const char*[]){"Word"}, 
     (const char*[]){"string"}},
    
    {"longestSubseqWord", "Find longest common subsequence of two words", CATEGORY_RECURSION, 2, 
     (const char*[]){"Word1", "Word2"}, 
     (const char*[]){"string", "string"}},
    
    {"distinctSubseqWord", "Count distinct subsequences of a word", CATEGORY_RECURSION, 1, 
     (const char*[]){"Word"}, 
     (const char*[]){"string"}},
    
    {"isPalindromWord", "Check if a word is a palindrome", CATEGORY_RECURSION, 1, 
     (const char*[]){"Word"}, 
     (const char*[]){"string"}}
};

//* Number of functions
const int num_functions = sizeof(functions) / sizeof(functions[0]);

//* Array to store input widgets
HWND input_widgets[10];  // Assuming max 10 arguments per function
int current_function_index = -1;

//* Redirect stdout to a string buffer
#define BUFFER_SIZE 65536
char result_buffer[BUFFER_SIZE];
size_t buffer_pos = 0;

//* Custom stdout function
int custom_printf(const char *format, ...) {
    va_list args;
    va_start(args, format);
    
    char temp_buffer[1024];
    int result = vsprintf(temp_buffer, format, args);
    
    //* Append to our buffer
    size_t len = strlen(temp_buffer);
    if (buffer_pos + len < BUFFER_SIZE - 1) {
        strcpy(result_buffer + buffer_pos, temp_buffer);
        buffer_pos += len;
    }
    
    va_end(args);
    return result;
}

//* Function to clear the arguments container
void ClearArgsContainer() {
    //* Destroy all child windows
    HWND child = GetWindow(hArgsContainer, GW_CHILD);
    while (child) {
        HWND next = GetWindow(child, GW_HWNDNEXT);
        DestroyWindow(child);
        child = next;
    }
}

//* Function to update the arguments container based on the selected function
void UpdateArgsContainer(int function_index) {
    ClearArgsContainer();
    
    if (function_index < 0 || function_index >= num_functions) {
        return;
    }
    
    current_function_index = function_index;
    FunctionInfo *func = &functions[function_index];
    
    //* Create labels and input fields for each argument
    for (int i = 0; i < func->num_args; i++) {
        //* Create label for argument
        CreateWindow(
            "STATIC", func->arg_names[i],
            WS_CHILD | WS_VISIBLE | SS_LEFT,
            10, 10 + i * 30, 100, 20,
            hArgsContainer, NULL, GetModuleHandle(NULL), NULL);
        
        //* Create input widget based on argument type
        if (strcmp(func->arg_types[i], "tree") == 0) {
            //* For tree arguments, create a label showing if tree  "tree") == 0) {
            //* For tree arguments, create a label showing if tree is loaded
            HWND tree_label = CreateWindow(
                "STATIC", global_tree ? "Tree loaded" : "No tree loaded",
                WS_CHILD | WS_VISIBLE | SS_LEFT,
                120, 10 + i * 30, 200, 20,
                hArgsContainer, NULL, GetModuleHandle(NULL), NULL);
            input_widgets[i] = tree_label;
        } else {
            //* For other arguments, create an edit control
            HWND edit = CreateWindow(
                "EDIT", "",
                WS_CHILD | WS_VISIBLE | WS_BORDER | ES_AUTOHSCROLL,
                120, 10 + i * 30, 200, 20,
                hArgsContainer, NULL, GetModuleHandle(NULL), NULL);
            input_widgets[i] = edit;
        }
    }
}

//* Function to update the function combo box based on the selected category
void UpdateFunctionCombo(int category_index) {
    //* Clear the combo box
    SendMessage(hFunctionCombo, CB_RESETCONTENT, 0, 0);
    
    //* Add functions for the selected category
    for (int i = 0; i < num_functions; i++) {
        if (functions[i].category == category_index) {
            SendMessage(hFunctionCombo, CB_ADDSTRING, 0, (LPARAM)functions[i].name);
        }
    }
    
    //* Select the first item
    SendMessage(hFunctionCombo, CB_SETCURSEL, 0, 0);
    
    //* Update the arguments container
    int function_index = -1;
    for (int i = 0; i < num_functions; i++) {
        if (functions[i].category == category_index) {
            function_index = i;
            break;
        }
    }
    
    if (function_index >= 0) {
        UpdateArgsContainer(function_index);
    }
}

//* Function to get the selected function index
int GetSelectedFunctionIndex() {
    int category_index = SendMessage(hCategoryCombo, CB_GETCURSEL, 0, 0);
    int function_index = SendMessage(hFunctionCombo, CB_GETCURSEL, 0, 0);
    
    if (category_index < 0 || function_index < 0) {
        return -1;
    }
    
    //* Find the actual function index
    int count = 0;
    for (int i = 0; i < num_functions; i++) {
        if (functions[i].category == category_index) {
            if (count == function_index) {
                return i;
            }
            count++;
        }
    }
    
    return -1;
}

//* Function to execute the selected function
void ExecuteFunction() {
    int function_index = GetSelectedFunctionIndex();
    if (function_index < 0) {
        MessageBox(hWnd, "No function selected", "Error", MB_OK | MB_ICONERROR);
        return;
    }
    
    FunctionInfo *func = &functions[function_index];
    
    //* Clear the result buffer
    memset(result_buffer, 0, BUFFER_SIZE);
    buffer_pos = 0;
    
    //* Execute the function based on its name
    if (strcmp(func->name, "fillTree") == 0) {
        char filename[256];
        GetWindowText(input_widgets[0], filename, sizeof(filename));
        
        custom_printf("Loading tree from file: %s\n", filename);
        
        global_tree = fw_fillTree(filename);
        
        if (global_tree) {
            custom_printf("Tree loaded successfully.\n");
        } else {
            custom_printf("Failed to load tree.\n");
        }
    }
    else if (strcmp(func->name, "printTreeNodeCharacteristics") == 0) {
        if (!global_tree) {
            custom_printf("Error: No tree loaded.\n");
            goto update_result;
        }
        
        char word[256];
        GetWindowText(input_widgets[1], word, sizeof(word));
        
        custom_printf("Printing characteristics for word: %s\n", word);
        
        //* Create a temporary file for capturing stdout
        char tempFilename[MAX_PATH];
        GetTempPath(MAX_PATH, tempFilename);
        strcat(tempFilename, "tree_output.txt");
        
        //* Redirect stdout to the temp file
        FILE *temp_file = freopen(tempFilename, "w", stdout);
        if (!temp_file) {
            custom_printf("Error redirecting output.\n");
            goto update_result;
        }
        
        fw_printTreeNodeCharacteristics(global_tree, word);
        
        //* Close and reopen stdout
        fclose(stdout);
        FILE *console = freopen("CON", "w", stdout);
        if (!console) {
            custom_printf("Error restoring output.\n");
        }
        
        //* Read from the temp file
        FILE *read_temp = fopen(tempFilename, "r");
        if (read_temp) {
            char line[1024];
            while (fgets(line, sizeof(line), read_temp)) {
                custom_printf("%s", line);
            }
            fclose(read_temp);
        }
        
        //* Delete the temp file
        remove(tempFilename);
    }
    else if (strcmp(func->name, "TraversalBSTinOrder") == 0) {
        if (!global_tree) {
            custom_printf("Error: No tree loaded.\n");
            goto update_result;
        }
        
        custom_printf("In-order traversal of the tree:\n");
        
        //* Create a temporary file for capturing stdout
        char tempFilename[MAX_PATH];
        GetTempPath(MAX_PATH, tempFilename);
        strcat(tempFilename, "tree_output.txt");
        
        //* Redirect stdout to the temp file
        FILE *temp_file = freopen(tempFilename, "w", stdout);
        if (!temp_file) {
            custom_printf("Error redirecting output.\n");
            goto update_result;
        }
        
        fw_TraversalBSTinOrder(global_tree);
        
        //* Close and reopen stdout
        fclose(stdout);
        FILE *console = freopen("CON", "w", stdout);
        if (!console) {
            custom_printf("Error restoring output.\n");
        }
        
        //* Read from the temp file
        FILE *read_temp = fopen(tempFilename, "r");
        if (read_temp) {
            char line[1024];
            while (fgets(line, sizeof(line), read_temp)) {
                custom_printf("%s", line);
            }
            fclose(read_temp);
        }
        
        //* Delete the temp file
        remove(tempFilename);
    }
    else if (strcmp(func->name, "TraversalBSTpreOrder") == 0) {
        if (!global_tree) {
            custom_printf("Error: No tree loaded.\n");
            goto update_result;
        }
        
        custom_printf("Pre-order traversal of the tree:\n");
        
        //* Create a temporary file for capturing stdout
        char tempFilename[MAX_PATH];
        GetTempPath(MAX_PATH, tempFilename);
        strcat(tempFilename, "tree_output.txt");
        
        //* Redirect stdout to the temp file
        FILE *temp_file = freopen(tempFilename, "w", stdout);
        if (!temp_file) {
            custom_printf("Error redirecting output.\n");
            goto update_result;
        }
        
        fw_TraversalBSTpreOrder(global_tree);
        
        //* Close and reopen stdout
        fclose(stdout);
        FILE *console = freopen("CON", "w", stdout);
        if (!console) {
            custom_printf("Error restoring output.\n");
        }
        
        //* Read from the temp file
        FILE *read_temp = fopen(tempFilename, "r");
        if (read_temp) {
            char line[1024];
            while (fgets(line, sizeof(line), read_temp)) {
                custom_printf("%s", line);
            }
            fclose(read_temp);
        }
        
        //* Delete the temp file
        remove(tempFilename);
    }
    else if (strcmp(func->name, "TraversalBSTpostOrder") == 0) {
        if (!global_tree) {
            custom_printf("Error: No tree loaded.\n");
            goto update_result;
        }
        
        custom_printf("Post-order traversal of the tree:\n");
        
        //* Create a temporary file for capturing stdout
        char tempFilename[MAX_PATH];
        GetTempPath(MAX_PATH, tempFilename);
        strcat(tempFilename, "tree_output.txt");
        
        //* Redirect stdout to the temp file
        FILE *temp_file = freopen(tempFilename, "w", stdout);
        if (!temp_file) {
            custom_printf("Error redirecting output.\n");
            goto update_result;
        }
        
        fw_TraversalBSTpostOrder(global_tree);
        
        //* Close and reopen stdout
        fclose(stdout);
        FILE *console = freopen("CON", "w", stdout);
        if (!console) {
            custom_printf("Error restoring output.\n");
        }
        
        //* Read from the temp file
        FILE *read_temp = fopen(tempFilename, "r");
        if (read_temp) {
            char line[1024];
            while (fgets(line, sizeof(line), read_temp)) {
                custom_printf("%s", line);
            }
            fclose(read_temp);
        }
        
        //* Delete the temp file
        remove(tempFilename);
    }
    else if (strcmp(func->name, "deleteWordBST") == 0) {
        if (!global_tree) {
            custom_printf("Error: No tree loaded.\n");
            goto update_result;
        }
        
        char word[256];
        GetWindowText(input_widgets[1], word, sizeof(word));
        
        custom_printf("Deleting word: %s\n", word);
        
        global_tree = fw_deleteWordBST(global_tree, word);
        
        custom_printf("Word deleted.\n");
    }
    else if (strcmp(func->name, "UpdateWordBST") == 0) {
        if (!global_tree) {
            custom_printf("Error: No tree loaded.\n");
            goto update_result;
        }
        
        char word[256], synonym[256], antonym[256];
        GetWindowText(input_widgets[1], word, sizeof(word));
        GetWindowText(input_widgets[2], synonym, sizeof(synonym));
        GetWindowText(input_widgets[3], antonym, sizeof(antonym));
        
        custom_printf("Updating word: %s\n", word);
        
        global_tree = fw_UpdateWordBST(global_tree, word, synonym, antonym);
        
        custom_printf("Word updated.\n");
    }
    else if (strcmp(func->name, "deleteSyn") == 0) {
        if (!global_tree) {
            custom_printf("Error: No tree loaded.\n");
            goto update_result;
        }
        
        char word[256], synonym[256];
        GetWindowText(input_widgets[1], word, sizeof(word));
        GetWindowText(input_widgets[2], synonym, sizeof(synonym));
        
        custom_printf("Deleting synonym '%s' for word '%s'\n", synonym, word);
        
        global_tree = fw_deleteSyn(global_tree, word, synonym);
        
        custom_printf("Synonym deleted.\n");
    }
    else if (strcmp(func->name, "deleteAnt") == 0) {
        if (!global_tree) {
            custom_printf("Error: No tree loaded.\n");
            goto update_result;
        }
        
        char word[256], antonym[256];
        GetWindowText(input_widgets[1], word, sizeof(word));
        GetWindowText(input_widgets[2], antonym, sizeof(antonym));
        
        custom_printf("Deleting antonym '%s' for word '%s'\n", antonym, word);
        
        global_tree = fw_deleteAnt(global_tree, word, antonym);
        
        custom_printf("Antonym deleted.\n");
    }
    else if (strcmp(func->name, "HighSizeBST") == 0) {
        if (!global_tree) {
            custom_printf("Error: No tree loaded.\n");
            goto update_result;
        }
        
        custom_printf("Tree height and size:\n");
        
        //* Create a temporary file for capturing stdout
        char tempFilename[MAX_PATH];
        GetTempPath(MAX_PATH, tempFilename);
        strcat(tempFilename, "tree_output.txt");
        
        //* Redirect stdout to the temp file
        FILE *temp_file = freopen(tempFilename, "w", stdout);
        if (!temp_file) {
            custom_printf("Error redirecting output.\n");
            goto update_result;
        }
        
        fw_HighSizeBST(global_tree);
        
        //* Close and reopen stdout
        fclose(stdout);
        FILE *console = freopen("CON", "w", stdout);
        if (!console) {
            custom_printf("Error restoring output.\n");
        }
        
        //* Read from the temp file
        FILE *read_temp = fopen(tempFilename, "r");
        if (read_temp) {
            char line[1024];
            while (fgets(line, sizeof(line), read_temp)) {
                custom_printf("%s", line);
            }
            fclose(read_temp);
        }
        
        //* Delete the temp file
        remove(tempFilename);
    }
    else if (strcmp(func->name, "LowestCommonAncestor") == 0) {
        if (!global_tree) {
            custom_printf("Error: No tree loaded.\n");
            goto update_result;
        }
        
        char word1[256], word2[256];
        GetWindowText(input_widgets[1], word1, sizeof(word1));
        GetWindowText(input_widgets[2], word2, sizeof(word2));
        
        custom_printf("Finding lowest common ancestor for words '%s' and '%s'\n", word1, word2);
        
        TTree2 *lca = fw_LowestCommonAncestor(global_tree, word1, word2);
        
        if (lca) {
            custom_printf("Lowest common ancestor: %s\n", lca->word);
        } else {
            custom_printf("No common ancestor found.\n");
        }
    }
    else if (strcmp(func->name, "CountNodesRanges") == 0) {
        if (!global_tree) {
            custom_printf("Error: No tree loaded.\n");
            goto update_result;
        }
        
        char min_str[256], max_str[256];
        GetWindowText(input_widgets[1], min_str, sizeof(min_str));
        GetWindowText(input_widgets[2], max_str, sizeof(max_str));
        
        int min_len = atoi(min_str);
        int max_len = atoi(max_str);
        
        custom_printf("Counting nodes with word length between %d and %d\n", min_len, max_len);
        
        int count = fw_CountNodesRanges(global_tree, min_len, max_len);
        
        custom_printf("Count: %d\n", count);
    }
    else if (strcmp(func->name, "inOrderSuccesor") == 0) {
        if (!global_tree) {
            custom_printf("Error: No tree loaded.\n");
            goto update_result;
        }
        
        char word[256];
        GetWindowText(input_widgets[1], word, sizeof(word));
        
        custom_printf("Finding in-order successor for word '%s'\n", word);
        
        TTree2 *successor = fw_inOrderSuccesor(global_tree, word);
        
        if (successor) {
            custom_printf("In-order successor: %s\n", successor->word);
        } else {
            custom_printf("No in-order successor found.\n");
        }
    }
    else if (strcmp(func->name, "BSTMirror") == 0) {
        if (!global_tree) {
            custom_printf("Error: No tree loaded.\n");
            goto update_result;
        }
        
        custom_printf("Creating mirror image of the tree\n");
        
        global_tree = fw_BSTMirror(global_tree);
        
        custom_printf("Tree mirrored.\n");
    }
    else if (strcmp(func->name, "isBalencedBST") == 0) {
        if (!global_tree) {
            custom_printf("Error: No tree loaded.\n");
            goto update_result;
        }
        
        custom_printf("Checking if the tree is balanced\n");
        
        int balanced = fw_isBalencedBST(global_tree);
        
        if (balanced) {
            custom_printf("The tree is balanced.\n");
        } else {
            custom_printf("The tree is not balanced.\n");
        }
    }
    else if (strcmp(func->name, "wordPermutation") == 0) {
        char word[256];
        GetWindowText(input_widgets[0], word, sizeof(word));
        
        custom_printf("Generating permutations for word '%s'\n", word);
        
        //* Create a copy of the word since wordPermutation modifies it
        char *word_copy = strdup(word);
        
        //* Create a temporary file for capturing stdout
        char tempFilename[MAX_PATH];
        GetTempPath(MAX_PATH, tempFilename);
        strcat(tempFilename, "tree_output.txt");
        
        //* Redirect stdout to the temp file
        FILE *temp_file = freopen(tempFilename, "w", stdout);
        if (!temp_file) {
            custom_printf("Error redirecting output.\n");
            free(word_copy);
            goto update_result;
        }
        
        fw_wordPermutation(word_copy);
        
        //* Close and reopen stdout
        fclose(stdout);
        FILE *console = freopen("CON", "w", stdout);
        if (!console) {
            custom_printf("Error restoring output.\n");
        }
        
        //* Read from the temp file
        FILE *read_temp = fopen(tempFilename, "r");
        if (read_temp) {
            char line[1024];
            while (fgets(line, sizeof(line), read_temp)) {
                custom_printf("%s", line);
            }
            fclose(read_temp);
        }
        
        //* Delete the temp file
        remove(tempFilename);
        free(word_copy);
    }
    else if (strcmp(func->name, "subseqWord") == 0) {
        char word[256];
        GetWindowText(input_widgets[0], word, sizeof(word));
        
        custom_printf("Generating subsequences for word '%s'\n", word);
        
        //* Create a temporary file for capturing stdout
        char tempFilename[MAX_PATH];
        GetTempPath(MAX_PATH, tempFilename);
        strcat(tempFilename, "tree_output.txt");
        
        //* Redirect stdout to the temp file
        FILE *temp_file = freopen(tempFilename, "w", stdout);
        if (!temp_file) {
            custom_printf("Error redirecting output.\n");
            goto update_result;
        }
        
        fw_subseqWord(word);
        
        //* Close and reopen stdout
        fclose(stdout);
        FILE *console = freopen("CON", "w", stdout);
        if (!console) {
            custom_printf("Error restoring output.\n");
        }
        
        //* Read from the temp file
        FILE *read_temp = fopen(tempFilename, "r");
        if (read_temp) {
            char line[1024];
            while (fgets(line, sizeof(line), read_temp)) {
                custom_printf("%s", line);
            }
            fclose(read_temp);
        }
        
        //* Delete the temp file
        remove(tempFilename);
    }
    else if (strcmp(func->name, "longestSubseqWord") == 0) {
        char word1[256], word2[256];
        GetWindowText(input_widgets[0], word1, sizeof(word1));
        GetWindowText(input_widgets[1], word2, sizeof(word2));
        
        custom_printf("Finding longest common subsequence for words '%s' and '%s'\n", word1, word2);
        
        int length = fw_longestSubseqWord(word1, word2);
        
        custom_printf("Length of longest common subsequence: %d\n", length);
    }
    else if (strcmp(func->name, "distinctSubseqWord") == 0) {
        char word[256];
        GetWindowText(input_widgets[0], word, sizeof(word));
        
        custom_printf("Counting distinct subsequences for word '%s'\n", word);
        
        int count = fw_distinctSubseqWord(word);
        
        custom_printf("Number of distinct subsequences: %d\n", count);
    }
    else if (strcmp(func->name, "isPalindromWord") == 0) {
        char word[256];
        GetWindowText(input_widgets[0], word, sizeof(word));
        
        custom_printf("Checking if word '%s' is a palindrome\n", word);
        
        int is_palindrome = fw_isPalindromWord(word);
        
        if (is_palindrome) {
            custom_printf("The word is a palindrome.\n");
        } else {
            custom_printf("The word is not a palindrome.\n");
        }
    }
    else if (strcmp(func->name, "getSynWords") == 0) {
        char filename[256];
        GetWindowText(input_widgets[0], filename, sizeof(filename));
        
        custom_printf("Getting synonyms from file: %s\n", filename);
        
        global_syn_list = fw_getSynWords(filename);
        
        if (global_syn_list) {
            custom_printf("Synonyms list created successfully.\n");
            
            //* Create a temporary file for capturing stdout
            char tempFilename[MAX_PATH];
            GetTempPath(MAX_PATH, tempFilename);
            strcat(tempFilename, "list_output.txt");
            
            //* Redirect stdout to the temp file
            FILE *temp_file = freopen(tempFilename, "w", stdout);
            if (!temp_file) {
                custom_printf("Error redirecting output.\n");
                goto update_result;
            }
            
            fw_printWords(global_syn_list, 0);
            
            //* Close and reopen stdout
            fclose(stdout);
            FILE *console = freopen("CON", "w", stdout);
            if (!console) {
                custom_printf("Error restoring output.\n");
            }
            
            //* Read from the temp file
            FILE *read_temp = fopen(tempFilename, "r");
            if (read_temp) {
                char line[1024];
                while (fgets(line, sizeof(line), read_temp)) {
                    custom_printf("%s", line);
                }
                fclose(read_temp);
            }
            
            //* Delete the temp file
            remove(tempFilename);
        } else {
            custom_printf("Failed to create synonyms list.\n");
        }
    }
    else if (strcmp(func->name, "getAntoWords") == 0) {
        char filename[256];
        GetWindowText(input_widgets[0], filename, sizeof(filename));
        
        custom_printf("Getting antonyms from file: %s\n", filename);
        
        global_ant_list = fw_getAntoWords(filename);
        
        if (global_ant_list) {
            custom_printf("Antonyms list created successfully.\n");
            
            //* Create a temporary file for capturing stdout
            char tempFilename[MAX_PATH];
            GetTempPath(MAX_PATH, tempFilename);
            strcat(tempFilename, "list_output.txt");
            
            //* Redirect stdout to the temp file
            FILE *temp_file = freopen(tempFilename, "w", stdout);
            if (!temp_file) {
                custom_printf("Error redirecting output.\n");
                goto update_result;
            }
            
            fw_printWords(global_ant_list, 1);
            
            //* Close and reopen stdout
            fclose(stdout);
            FILE *console = freopen("CON", "w", stdout);
            if (!console) {
                custom_printf("Error restoring output.\n");
            }
            
            //* Read from the temp file
            FILE *read_temp = fopen(tempFilename, "r");
            if (read_temp) {
                char line[1024];
                while (fgets(line, sizeof(line), read_temp)) {
                    custom_printf("%s", line);
                }
                fclose(read_temp);
            }
            
            //* Delete the temp file
            remove(tempFilename);
        } else {
            custom_printf("Failed to create antonyms list.\n");
        }
    }
    else if (strcmp(func->name, "getInfWord") == 0) {
        if (!global_syn_list || !global_ant_list) {
            custom_printf("Error: Synonym and antonym lists must be loaded first.\n");
            goto update_result;
        }
        
        char word[256];
        GetWindowText(input_widgets[0], word, sizeof(word));
        
        custom_printf("Getting information for word: %s\n", word);
        
        //* Create a temporary file for capturing stdout
        char tempFilename[MAX_PATH];
        GetTempPath(MAX_PATH, tempFilename);
        strcat(tempFilename, "word_info.txt");
        
        //* Redirect stdout to the temp file
        FILE *temp_file = freopen(tempFilename, "w", stdout);
        if (!temp_file) {
            custom_printf("Error redirecting output.\n");
            goto update_result;
        }
        
        fw_getInfWord(global_syn_list, global_ant_list, word);
        
        //* Close and reopen stdout
        fclose(stdout);
        FILE *console = freopen("CON", "w", stdout);
        if (!console) {
            custom_printf("Error restoring output.\n");
        }
        
        //* Read from the temp file
        FILE *read_temp = fopen(tempFilename, "r");
        if (read_temp) {
            char line[1024];
            while (fgets(line, sizeof(line), read_temp)) {
                custom_printf("%s", line);
            }
            fclose(read_temp);
        }
        
        //* Delete the temp file
        remove(tempFilename);
    }
    else if (strcmp(func->name, "sortWord") == 0) {
        if (!global_syn_list) {
            custom_printf("Error: Synonym list must be loaded first.\n");
            goto update_result;
        }
        
        custom_printf("Sorting words alphabetically.\n");
        
        global_syn_list = fw_sortWord(global_syn_list);
        
        //* Create a temporary file for capturing stdout
        char tempFilename[MAX_PATH];
        GetTempPath(MAX_PATH, tempFilename);
        strcat(tempFilename, "sorted_list.txt");
        
        //* Redirect stdout to the temp file
        FILE *temp_file = freopen(tempFilename, "w", stdout);
        if (!temp_file) {
            custom_printf("Error redirecting output.\n");
            goto update_result;
        }
        
        fw_printWords(global_syn_list, 0);
        
        //* Close and reopen stdout
        fclose(stdout);
        FILE *console = freopen("CON", "w", stdout);
        if (!console) {
            custom_printf("Error restoring output.\n");
        }
        
        //* Read from the temp file
        FILE *read_temp = fopen(tempFilename, "r");
        if (read_temp) {
            char line[1024];
            while (fgets(line, sizeof(line), read_temp)) {
                custom_printf("%s", line);
            }
            fclose(read_temp);
        }
        
        //* Delete the temp file
        remove(tempFilename);
    }
    else if (strcmp(func->name, "sortWord2") == 0) {
        if (!global_syn_list) {
            custom_printf("Error: Synonym list must be loaded first.\n");
            goto update_result;
        }
        
        custom_printf("Sorting words by character count.\n");
        
        global_syn_list = fw_sortWord2(global_syn_list);
        
        //* Create a temporary file for capturing stdout
        char tempFilename[MAX_PATH];
        GetTempPath(MAX_PATH, tempFilename);
        strcat(tempFilename, "sorted_list.txt");
        
        //* Redirect stdout to the temp file
        FILE *temp_file = freopen(tempFilename, "w", stdout);
        if (!temp_file) {
            custom_printf("Error redirecting output.\n");
            goto update_result;
        }
        
        fw_printWords(global_syn_list, 0);
        
        //* Close and reopen stdout
        fclose(stdout);
        FILE *console = freopen("CON", "w", stdout);
        if (!console) {
            custom_printf("Error restoring output.\n");
        }
        
        //* Read from the temp file
        FILE *read_temp = fopen(tempFilename, "r");
        if (read_temp) {
            char line[1024];
            while (fgets(line, sizeof(line), read_temp)) {
                custom_printf("%s", line);
            }
            fclose(read_temp);
        }
        
        //* Delete the temp file
        remove(tempFilename);
    }
    else if (strcmp(func->name, "sortWord3") == 0) {
        if (!global_syn_list) {
            custom_printf("Error: Synonym list must be loaded first.\n");
            goto update_result;
        }
        
        custom_printf("Sorting words by vowel count.\n");
        
        global_syn_list = fw_sortWord3(global_syn_list);
        
        //* Create a temporary file for capturing stdout
        char tempFilename[MAX_PATH];
        GetTempPath(MAX_PATH, tempFilename);
        strcat(tempFilename, "sorted_list.txt");
        
        //* Redirect stdout to the temp file
        FILE *temp_file = freopen(tempFilename, "w", stdout);
        if (!temp_file) {
            custom_printf("Error redirecting output.\n");
            goto update_result;
        }
        
        fw_printWords(global_syn_list, 0);
        
        //* Close and reopen stdout
        fclose(stdout);
        FILE *console = freopen("CON", "w", stdout);
        if (!console) {
            custom_printf("Error restoring output.\n");
        }
        
        //* Read from the temp file
        FILE *read_temp = fopen(tempFilename, "r");
        if (read_temp) {
            char line[1024];
            while (fgets(line, sizeof(line), read_temp)) {
                custom_printf("%s", line);
            }
            fclose(read_temp);
        }
        
        //* Delete the temp file
        remove(tempFilename);
    }
    else if (strcmp(func->name, "deleteWord") == 0) {
        if (!global_syn_list || !global_ant_list) {
            custom_printf("Error: Synonym and antonym lists must be loaded first.\n");
            goto update_result;
        }
        
        char word[256];
        GetWindowText(input_widgets[0], word, sizeof(word));
        
        custom_printf("Deleting word: %s\n", word);
        
        fw_deleteWord("dictinoary.txt", global_syn_list, global_ant_list, word);
        
        custom_printf("Word deleted successfully.\n");
    }
    else if (strcmp(func->name, "updateWord") == 0) {
        if (!global_syn_list || !global_ant_list) {
            custom_printf("Error: Synonym and antonym lists must be loaded first.\n");
            goto update_result;
        }
        
        char word[256], synonym[256], antonym[256];
        GetWindowText(input_widgets[0], word, sizeof(word));
        GetWindowText(input_widgets[1], synonym, sizeof(synonym));
        GetWindowText(input_widgets[2], antonym, sizeof(antonym));
        
        custom_printf("Updating word: %s with synonym: %s and antonym: %s\n", word, synonym, antonym);
        
        fw_updateWord("dictinoary.txt", global_syn_list, global_ant_list, word, synonym, antonym);
        
        custom_printf("Word updated successfully.\n");
    }
    else if (strcmp(func->name, "similarWord") == 0) {
        if (!global_syn_list) {
            custom_printf("Error: Synonym list must be loaded first.\n");
            goto update_result;
        }
        
        char word[256], rate_str[256];
        GetWindowText(input_widgets[0], word, sizeof(word));
        GetWindowText(input_widgets[1], rate_str, sizeof(rate_str));
        
        int rate = atoi(rate_str);
        
        custom_printf("Finding words similar to '%s' with match rate %d%%\n", word, rate);
        
        TList *similar_list = fw_similarWord(global_syn_list, word, rate);
        
        if (similar_list) {
            //* Create a temporary file for capturing stdout
            char tempFilename[MAX_PATH];
            GetTempPath(MAX_PATH, tempFilename);
            strcat(tempFilename, "similar_words.txt");
            
            //* Redirect stdout to the temp file
            FILE *temp_file = freopen(tempFilename, "w", stdout);
            if (!temp_file) {
                custom_printf("Error redirecting output.\n");
                goto update_result;
            }
            
            fw_printWords(similar_list, 0);
            
            //* Close and reopen stdout
            fclose(stdout);
            FILE *console = freopen("CON", "w", stdout);
            if (!console) {
                custom_printf("Error restoring output.\n");
            }
            
            //* Read from the temp file
            FILE *read_temp = fopen(tempFilename, "r");
            if (read_temp) {
                char line[1024];
                while (fgets(line, sizeof(line), read_temp)) {
                    custom_printf("%s", line);
                }
                fclose(read_temp);
            }
            
            //* Delete the temp file
            remove(tempFilename);
        } else {
            custom_printf("No similar words found.\n");
        }
    }
    else if (strcmp(func->name, "countWord") == 0) {
        if (!global_syn_list) {
            custom_printf("Error: Synonym list must be loaded first.\n");
            goto update_result;
        }
        
        char substring[256];
        GetWindowText(input_widgets[0], substring, sizeof(substring));
        
        custom_printf("Finding words containing substring: %s\n", substring);
        
        TList *count_list = fw_countWord(global_syn_list, substring);
        
        if (count_list) {
            //* Create a temporary file for capturing stdout
            char tempFilename[MAX_PATH];
            GetTempPath(MAX_PATH, tempFilename);
            strcat(tempFilename, "count_words.txt");
            
            //* Redirect stdout to the temp file
            FILE *temp_file = freopen(tempFilename, "w", stdout);
            if (!temp_file) {
                custom_printf("Error redirecting output.\n");
                goto update_result;
            }
            
            fw_printWords(count_list, 0);
            
            //* Close and reopen stdout
            fclose(stdout);
            FILE *console = freopen("CON", "w", stdout);
            if (!console) {
                custom_printf("Error restoring output.\n");
            }
            
            //* Read from the temp file
            FILE *read_temp = fopen(tempFilename, "r");
            if (read_temp) {
                char line[1024];
                while (fgets(line, sizeof(line), read_temp)) {
                    custom_printf("%s", line);
                }
                fclose(read_temp);
            }
            
            //* Delete the temp file
            remove(tempFilename);
        } else {
            custom_printf("No matching words found.\n");
        }
    }
    else if (strcmp(func->name, "palindromWord") == 0) {
        if (!global_syn_list) {
            custom_printf("Error: Synonym list must be loaded first.\n");
            goto update_result;
        }
        
        custom_printf("Finding palindrome words.\n");
        
        TList *palindromes = fw_palindromWord(global_syn_list);
        
        if (palindromes) {
            //* Create a temporary file for capturing stdout
            char tempFilename[MAX_PATH];
            GetTempPath(MAX_PATH, tempFilename);
            strcat(tempFilename, "palindromes.txt");
            
            //* Redirect stdout to the temp file
            FILE *temp_file = freopen(tempFilename, "w", stdout);
            if (!temp_file) {
                custom_printf("Error redirecting output.\n");
                goto update_result;
            }
            
            fw_printWords(palindromes, 0);
            
            //* Close and reopen stdout
            fclose(stdout);
            FILE *console = freopen("CON", "w", stdout);
            if (!console) {
                custom_printf("Error restoring output.\n");
            }
            
            //* Read from the temp file
            FILE *read_temp = fopen(tempFilename, "r");
            if (read_temp) {
                char line[1024];
                while (fgets(line, sizeof(line), read_temp)) {
                    custom_printf("%s", line);
                }
                fclose(read_temp);
            }
            
            //* Delete the temp file
            remove(tempFilename);
        } else {
            custom_printf("No palindrome words found.\n");
        }
    }
    else if (strcmp(func->name, "syllable") == 0) {
        if (!global_syn_list) {
            custom_printf("Error: Synonym list must be loaded first.\n");
            goto update_result;
        }
        
        custom_printf("Grouping words by syllable count.\n");
        
        global_queue = fw_syllable(global_syn_list);
        
        if (global_queue) {
            //* Create a temporary file for capturing stdout
            char tempFilename[MAX_PATH];
            GetTempPath(MAX_PATH, tempFilename);
            strcat(tempFilename, "syllables.txt");
            
              tempFilename;
            strcat(tempFilename, "syllables.txt");
            
            //* Redirect stdout to the temp file
            FILE *temp_file = freopen(tempFilename, "w", stdout);
            if (!temp_file) {
                custom_printf("Error redirecting output.\n");
                goto update_result;
            }
            
            fw_printQueueWords(global_queue);
            
            //* Close and reopen stdout
            fclose(stdout);
            FILE *console = freopen("CON", "w", stdout);
            if (!console) {
                custom_printf("Error restoring output.\n");
            }
            
            //* Read from the temp file
            FILE *read_temp = fopen(tempFilename, "r");
            if (read_temp) {
                char line[1024];
                while (fgets(line, sizeof(line), read_temp)) {
                    custom_printf("%s", line);
                }
                fclose(read_temp);
            }
            
            //* Delete the temp file
            remove(tempFilename);
        } else {
            custom_printf("No words grouped by syllable count.\n");
        }
    }
    else if (strcmp(func->name, "prounounciation") == 0) {
        if (!global_syn_list) {
            custom_printf("Error: Synonym list must be loaded first.\n");
            goto update_result;
        }
        
        custom_printf("Grouping words by pronunciation.\n");
        
        TQueue **queues = fw_prounounciation(global_syn_list);
        
        if (queues) {
            //* Create a temporary file for capturing stdout
            char tempFilename[MAX_PATH];
            GetTempPath(MAX_PATH, tempFilename);
            strcat(tempFilename, "pronunciation.txt");
            
            //* Redirect stdout to the temp file
            FILE *temp_file = freopen(tempFilename, "w", stdout);
            if (!temp_file) {
                custom_printf("Error redirecting output.\n");
                goto update_result;
            }
            
            custom_printf("Words with short vowels:\n");
            fw_printQueueWords(queues[0]);
            custom_printf("Words with long vowels:\n");
            fw_printQueueWords(queues[1]);
            custom_printf("Words with diphthongs:\n");
            fw_printQueueWords(queues[2]);
            
            //* Close and reopen stdout
            fclose(stdout);
            FILE *console = freopen("CON", "w", stdout);
            if (!console) {
                custom_printf("Error restoring output.\n");
            }
            
            //* Read from the temp file
            FILE *read_temp = fopen(tempFilename, "r");
            if (read_temp) {
                char line[1024];
                while (fgets(line, sizeof(line), read_temp)) {
                    custom_printf("%s", line);
                }
                fclose(read_temp);
            }
            
            //* Delete the temp file
            remove(tempFilename);
        } else {
            custom_printf("No words grouped by pronunciation.\n");
        }
    }
    else if (strcmp(func->name, "stackToQueue") == 0) {
        if (!global_stack) {
            custom_printf("Error: Stack must be loaded first.\n");
            goto update_result;
        }
        
        custom_printf("Converting stack to queue.\n");
        
        global_queue = fw_stackToQueue(global_stack);
        
        if (global_queue) {
            //* Create a temporary file for capturing stdout
            char tempFilename[MAX_PATH];
            GetTempPath(MAX_PATH, tempFilename);
            strcat(tempFilename, "queue.txt");
            
            //* Redirect stdout to the temp file
            FILE *temp_file = freopen(tempFilename, "w", stdout);
            if (!temp_file) {
                custom_printf("Error redirecting output.\n");
                goto update_result;
            }
            
            fw_printQueueWords(global_queue);
            
            //* Close and reopen stdout
            fclose(stdout);
            FILE *console = freopen("CON", "w", stdout);
            if (!console) {
                custom_printf("Error restoring output.\n");
            }
            
            //* Read from the temp file
            FILE *read_temp = fopen(tempFilename, "r");
            if (read_temp) {
                char line[1024];
                while (fgets(line, sizeof(line), read_temp)) {
                    custom_printf("%s", line);
                }
                fclose(read_temp);
            }
            
            //* Delete the temp file
            remove(tempFilename);
        } else {
            custom_printf("Failed to convert stack to queue.\n");
        }
    }
    else if (strcmp(func->name, "toStack") == 0) {
        if (!global_syn_list) {
            custom_printf("Error: Synonym list must be loaded first.\n");
            goto update_result;
        }
        
        custom_printf("Converting list to stack.\n");
        
        global_stack = fw_toStack(global_syn_list);
        
        if (global_stack) {
            custom_printf("Stack created successfully.\n");
            
            //* Create a temporary file for capturing stdout
            char tempFilename[MAX_PATH];
            GetTempPath(MAX_PATH, tempFilename);
            strcat(tempFilename, "stack_output.txt");
            
            //* Redirect stdout to the temp file
            FILE *temp_file = freopen(tempFilename, "w", stdout);
            if (!temp_file) {
                custom_printf("Error redirecting output.\n");
                goto update_result;
            }
            
            fw_printStackWords(global_stack);
            
            //* Close and reopen stdout
            fclose(stdout);
            FILE *console = freopen("CON", "w", stdout);
            if (!console) {
                custom_printf("Error restoring output.\n");
            }
            
            //* Read from the temp file
            FILE *read_temp = fopen(tempFilename, "r");
            if (read_temp) {
                char line[1024];
                while (fgets(line, sizeof(line), read_temp)) {
                    custom_printf("%s", line);
                }
                fclose(read_temp);
            }
            
            //* Delete the temp file
            remove(tempFilename);
        } else {
            custom_printf("Failed to create stack.\n");
        }
    }
    else if (strcmp(func->name, "getInfWordStack") == 0) {
        if (!global_stack) {
            custom_printf("Error: Stack must be loaded first.\n");
            goto update_result;
        }
        
        char word[256];
        GetWindowText(input_widgets[0], word, sizeof(word));
        
        custom_printf("Getting information for word: %s\n", word);
        
        //* Create a temporary file for capturing stdout
        char tempFilename[MAX_PATH];
        GetTempPath(MAX_PATH, tempFilename);
        strcat(tempFilename, "word_info.txt");
        
        //* Redirect stdout to the temp file
        FILE *temp_file = freopen(tempFilename, "w", stdout);
        if (!temp_file) {
            custom_printf("Error redirecting output.\n");
            goto update_result;
        }
        
        fw_getInfWordStack(global_stack, word);
        
        //* Close and reopen stdout
        fclose(stdout);
        FILE *console = freopen("CON", "w", stdout);
        if (!console) {
            custom_printf("Error restoring output.\n");
        }
        
        //* Read from the temp file
        FILE *read_temp = fopen(tempFilename, "r");
        if (read_temp) {
            char line[1024];
            while (fgets(line, sizeof(line), read_temp)) {
                custom_printf("%s", line);
            }
            fclose(read_temp);
        }
        
        //* Delete the temp file
        remove(tempFilename);
    }
    else if (strcmp(func->name, "sortWordStack") == 0) {
        if (!global_stack) {
            custom_printf("Error: Stack must be loaded first.\n");
            goto update_result;
        }
        
        custom_printf("Sorting stack.\n");
        
        global_stack = fw_sortWordStack(global_stack);
        
        //* Create a temporary file for capturing stdout
        char tempFilename[MAX_PATH];
        GetTempPath(MAX_PATH, tempFilename);
        strcat(tempFilename, "sorted_stack.txt");
        
        //* Redirect stdout to the temp file
        FILE *temp_file = freopen(tempFilename, "w", stdout);
        if (!temp_file) {
            custom_printf("Error redirecting output.\n");
            goto update_result;
        }
        
        fw_printStackWords(global_stack);
        
        //* Close and reopen stdout
        fclose(stdout);
        FILE *console = freopen("CON", "w", stdout);
        if (!console) {
            custom_printf("Error restoring output.\n");
        }
        
        //* Read from the temp file
        FILE *read_temp = fopen(tempFilename, "r");
        if (read_temp) {
            char line[1024];
            while (fgets(line, sizeof(line), read_temp)) {
                custom_printf("%s", line);
            }
            fclose(read_temp);
        }
        
        //* Delete the temp file
        remove(tempFilename);
    }
    else if (strcmp(func->name, "deleteWordStack") == 0) {
        if (!global_stack) {
            custom_printf("Error: Stack must be loaded first.\n");
            goto update_result;
        }
        
        char word[256];
        GetWindowText(input_widgets[0], word, sizeof(word));
        
        custom_printf("Deleting word from stack: %s\n", word);
        
        global_stack = fw_deleteWordStack(global_stack, word);
        
        custom_printf("Word deleted successfully.\n");
    }
    else if (strcmp(func->name, "updateWordStack") == 0) {
        if (!global_stack) {
            custom_printf("Error: Stack must be loaded first.\n");
            goto update_result;
        }
        
        char word[256], synonym[256], antonym[256];
        GetWindowText(input_widgets[0], word, sizeof(word));
        GetWindowText(input_widgets[1], synonym, sizeof(synonym));
        GetWindowText(input_widgets[2], antonym, sizeof(antonym));
        
        custom_printf("Updating word in stack: %s with synonym: %s and antonym: %s\n", word, synonym, antonym);
        
        global_stack = fw_updateWordStack(global_stack, word, synonym, antonym);
        
        custom_printf("Word updated successfully.\n");
    }
    else if (strcmp(func->name, "addWordStack") == 0) {
        if (!global_stack) {
            custom_printf("Error: Stack must be loaded first.\n");
            goto update_result;
        }
        
        char word[256], synonym[256], antonym[256];
        GetWindowText(input_widgets[0], word, sizeof(word));
        GetWindowText(input_widgets[1], synonym, sizeof(synonym));
        GetWindowText(input_widgets[2], antonym, sizeof(antonym));
        
        custom_printf("Adding word to stack: %s with synonym: %s and antonym: %s\n", word, synonym, antonym);
        
        global_stack = fw_addWordStack(global_stack, word, synonym, antonym);
        
        custom_printf("Word added successfully.\n");
    }
    else {
        custom_printf("Function not implemented: %s\n", func->name);
    }

update_result:
    //* Update the result text
    SetWindowText(hResultText, result_buffer);
}

//* Add a file browser dialog
void OpenFileBrowser() {
    OPENFILENAME ofn;
    char szFile[260] = {0};
    
    ZeroMemory(&ofn, sizeof(ofn));
    ofn.lStructSize = sizeof(ofn);
    ofn.hwndOwner = hWnd;
    ofn.lpstrFile = szFile;
    ofn.nMaxFile = sizeof(szFile);
    ofn.lpstrFilter = "Text Files\0*.txt\0All Files\0*.*\0";
    ofn.nFilterIndex = 1;
    ofn.lpstrFileTitle = NULL;
    ofn.nMaxFileTitle = 0;
    ofn.lpstrInitialDir = NULL;
    ofn.Flags = OFN_PATHMUSTEXIST | OFN_FILEMUSTEXIST;
    
    if (GetOpenFileName(&ofn)) {
        //* Get the current function index
        int function_index = GetSelectedFunctionIndex();
        if (function_index >= 0 && functions[function_index].num_args > 0) {
            //* Set the filename in the first input field
            SetWindowText(input_widgets[0], szFile);
        }
    }
}

//* Window procedure
LRESULT CALLBACK WndProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam) {
    switch (msg) {
        case WM_CREATE: {
            //* Initialize common controls
            INITCOMMONCONTROLSEX icex;
            icex.dwSize = sizeof(INITCOMMONCONTROLSEX);
            icex.dwICC = ICC_WIN95_CLASSES;
            InitCommonControlsEx(&icex);
            
            //* Create category combo box
            hCategoryCombo = CreateWindow(
                "COMBOBOX", NULL,
                WS_CHILD | WS_VISIBLE | CBS_DROPDOWNLIST | WS_VSCROLL,
                10, 10, 150, 200,
                hwnd, (HMENU)1, GetModuleHandle(NULL), NULL);
            
            //* Add categories to the combo box
            for (int i = 0; i < NUM_CATEGORIES; i++) {
                SendMessage(hCategoryCombo, CB_ADDSTRING, 0, (LPARAM)category_names[i]);
            }
            
            //* Select the first category
            SendMessage(hCategoryCombo, CB_SETCURSEL, 0, 0);
            
            //* Create function combo box
            hFunctionCombo = CreateWindow(
                "COMBOBOX", NULL,
                WS_CHILD | WS_VISIBLE | CBS_DROPDOWNLIST | WS_VSCROLL,
                170, 10, 300, 200,
                hwnd, (HMENU)2, GetModuleHandle(NULL), NULL);
            
            //* Create arguments container
            hArgsContainer = CreateWindow(
                "STATIC", NULL,
                WS_CHILD | WS_VISIBLE | WS_BORDER,
                10, 50, 460, 200,
                hwnd, NULL, GetModuleHandle(NULL), NULL);
            
            //* Create run button
            hRunButton = CreateWindow(
                "BUTTON", "Run",
                WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,
                10, 260, 100, 30,
                hwnd, (HMENU)3, GetModuleHandle(NULL), NULL);
            
            //* Create browse button
            CreateWindow(
                "BUTTON", "Browse...",
                WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,
                120, 260, 100, 30,
                hwnd, (HMENU)4, GetModuleHandle(NULL), NULL);
            
            //* Create result text
            hResultText = CreateWindow(
                "EDIT", "",
                WS_CHILD | WS_VISIBLE | WS_BORDER | ES_MULTILINE | ES_AUTOVSCROLL | WS_VSCROLL | ES_READONLY,
                10, 300, 760, 250,
                hwnd, NULL, GetModuleHandle(NULL), NULL);
            
            //* Create status bar
            hStatusBar = CreateWindow(
                STATUSCLASSNAME, NULL,
                WS_CHILD | WS_VISIBLE | SBARS_SIZEGRIP,
                0, 0, 0, 0,
                hwnd, (HMENU)5, GetModuleHandle(NULL), NULL);
            
            //* Update the function combo box
            UpdateFunctionCombo(0);
            
            //* Set a default font for all controls
            HFONT hFont = (HFONT)GetStockObject(DEFAULT_GUI_FONT);
            SendMessage(hCategoryCombo, WM_SETFONT, (WPARAM)hFont, TRUE);
            SendMessage(hFunctionCombo, WM_SETFONT, (WPARAM)hFont, TRUE);
            SendMessage(hRunButton, WM_SETFONT, (WPARAM)hFont, TRUE);
            SendMessage(hResultText, WM_SETFONT, (WPARAM)hFont, TRUE);
            
            //* Set status bar text
            SendMessage(hStatusBar, SB_SETTEXT, 0, (LPARAM)"Ready");
            
            break;
        }
        
        case WM_COMMAND: {
            int wmId = LOWORD(wParam);
            int wmEvent = HIWORD(wParam);
            
            //* Parse the menu selections
            switch (wmId) {
                case 1: //* Category combo box
                    if (wmEvent == CBN_SELCHANGE) {
                        int category_index = SendMessage(hCategoryCombo, CB_GETCURSEL, 0, 0);
                        UpdateFunctionCombo(category_index);
                    }
                    break;
                
                case 2: //* Function combo box
                    if (wmEvent == CBN_SELCHANGE) {
                        int function_index = GetSelectedFunctionIndex();
                        if (function_index >= 0) {
                            UpdateArgsContainer(function_index);
                        }
                    }
                    break;
                
                case 3: //* Run button
                    ExecuteFunction();
                    break;
                
                case 4: //* Browse button
                    OpenFileBrowser();
                    break;
                
                default:
                    return DefWindowProc(hwnd, msg, wParam, lParam);
            }
            break;
        }
        
        case WM_SIZE: {
            //* Resize the status bar
            SendMessage(hStatusBar, WM_SIZE, 0, 0);
            
            //* Get the client area size
            RECT rcClient;
            GetClientRect(hwnd, &rcClient);
            
            //* Resize the result text
            SetWindowPos(hResultText, NULL, 10, 300, rcClient.right - 20, rcClient.bottom - 310, SWP_NOZORDER);
            
            break;
        }
        
        case WM_CLOSE:
            DestroyWindow(hwnd);
            break;
        
        case WM_DESTROY:
            PostQuitMessage(0);
            break;
        
        default:
            return DefWindowProc(hwnd, msg, wParam, lParam);
    }
    
    return 0;
}

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow) {
    //* Register the window class
    WNDCLASSEX wc;
    wc.cbSize = sizeof(WNDCLASSEX);
    wc.style = 0;
    wc.lpfnWndProc = WndProc;
    wc.cbClsExtra = 0;
    wc.cbWndExtra = 0;
    wc.hInstance = hInstance;
    wc.hIcon = LoadIcon(NULL, IDI_APPLICATION);
    wc.hCursor = LoadCursor(NULL, IDC_ARROW);
    wc.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
    wc.lpszMenuName = NULL;
    wc.lpszClassName = "TreeGUIClass";
    wc.hIconSm = LoadIcon(NULL, IDI_APPLICATION);
    
    if (!RegisterClassEx(&wc)) {
        MessageBox(NULL, "Window Registration Failed!", "Error", MB_ICONEXCLAMATION | MB_OK);
        return 0;
    }
    
    //* Create the window
    hWnd = CreateWindowEx(
        WS_EX_CLIENTEDGE,
        "TreeGUIClass",
        "Tree Functions GUI",
        WS_OVERLAPPEDWINDOW,
        CW_USEDEFAULT, CW_USEDEFAULT, 800, 600,
        NULL, NULL, hInstance, NULL);
    
    if (hWnd == NULL) {
        MessageBox(NULL, "Window Creation Failed!", "Error", MB_ICONEXCLAMATION | MB_OK);
        return 0;
    }
    
    //* Show the window
    ShowWindow(hWnd, nCmdShow);
    UpdateWindow(hWnd);
    
    //* Message loop
    MSG msg;
    while (GetMessage(&msg, NULL, 0, 0) > 0) {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }
    
    return msg.wParam;
}
