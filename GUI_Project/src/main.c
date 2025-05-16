// Function category structure
#include <gtk/gtk.h>
#include "lib/trees.h"
#include "include/ds_wrapper.h"
typedef struct {
    char *name;
    char *description;
} FunctionCategory;

// Function definition structure
typedef struct {
    char *name;
    char *signature;
    char *description;
    char *category;
    int num_params;
    char **param_names;
    char **param_types;
    char **param_descriptions;
} FunctionDef;

// Global variables
GtkWidget *window;
GtkWidget *category_combo;
GtkWidget *function_list;
GtkWidget *args_container;
GtkWidget *output_text;
GtkWidget *execute_button;
GtkTextBuffer *output_buffer;
GtkWidget *status_bar;
guint status_context_id;

FunctionDef *functions = NULL;
int num_functions = 0;
FunctionDef *current_function = NULL;
GtkWidget **arg_entries = NULL;
int num_arg_entries = 0;

// Function categories
FunctionCategory categories[] = {
    {"Trees", "Tree Operations"},
    {"Recursion", "Recursive Functions"},
    {"Code", "General Code Functions"}
};
int num_categories = sizeof(categories) / sizeof(categories[0]);

// Forward declarations
void populate_function_list(const char *category);
void on_category_changed(GtkComboBox *widget, gpointer user_data);
void on_function_selected(GtkListBox *box, GtkListBoxRow *row, gpointer user_data);
void create_argument_widgets(FunctionDef *func);
void on_execute_clicked(GtkButton *button, gpointer user_data);
void clear_output();
void append_output(const char *text);
char *execute_command(const char *command);

// Initialize the functions array with all available functions
void init_functions() {
    // Allocate memory for functions
    functions = (FunctionDef *)malloc(100 * sizeof(FunctionDef)); // Assuming max 100 functions
    num_functions = 0;

    // Add functions from Trees PART II
    functions[num_functions++] = (FunctionDef){
        .name = "fillTree",
        .signature = "TTree2 *fillTree(const char *filename)",
        .description = "Fill a tree from a file",
        .category = "Trees",
        .num_params = 1,
        .param_names = (char *[]){"filename"},
        .param_types = (char *[]){"char *"},
        .param_descriptions = (char *[]){"Path to words.txt file"}
    };

    functions[num_functions++] = (FunctionDef){
        .name = "printTreeNodeCharacteristics",
        .signature = "void printTreeNodeCharacteristics(TTree2 *tr, char *word)",
        .description = "Print characteristics of a tree node",
        .category = "Trees",
        .num_params = 2,
        .param_names = (char *[]){"filename", "word"},
        .param_types = (char *[]){"char *", "char *"},
        .param_descriptions = (char *[]){"Path to words.txt file", "Word to look up"}
    };

    functions[num_functions++] = (FunctionDef){
        .name = "TraversalBSTinOrder",
        .signature = "void TraversalBSTinOrder(TTree2 *tr)",
        .description = "Traverse tree in-order",
        .category = "Trees",
        .num_params = 1,
        .param_names = (char *[]){"filename"},
        .param_types = (char *[]){"char *"},
        .param_descriptions = (char *[]){"Path to words.txt file"}
    };

    // Add functions from Recursion PART II
    functions[num_functions++] = (FunctionDef){
        .name = "countWordOccurrence",
        .signature = "int countWordOccurrence(FILE *f, const char *word)",
        .description = "Count occurrences of a word in a file",
        .category = "Recursion",
        .num_params = 2,
        .param_names = (char *[]){"filename", "word"},
        .param_types = (char *[]){"char *", "char *"},
        .param_descriptions = (char *[]){"Path to text file", "Word to count"}
    };

    functions[num_functions++] = (FunctionDef){
        .name = "isPalindromWord",
        .signature = "bool isPalindromWord(char *word)",
        .description = "Check if a word is a palindrome",
        .category = "Recursion",
        .num_params = 1,
        .param_names = (char *[]){"word"},
        .param_types = (char *[]){"char *"},
        .param_descriptions = (char *[]){"Word to check"}
    };

    functions[num_functions++] = (FunctionDef){
        .name = "wordPermutation",
        .signature = "void wordPermutation(char *word)",
        .description = "Generate all permutations of a word",
        .category = "Recursion",
        .num_params = 1,
        .param_names = (char *[]){"word"},
        .param_types = (char *[]){"char *"},
        .param_descriptions = (char *[]){"Word to permute"}
    };

    // Add functions from code.c
    functions[num_functions++] = (FunctionDef){
        .name = "sortWord",
        .signature = "TList *sortWord(TList *syn)",
        .description = "Sort words alphabetically",
        .category = "Code",
        .num_params = 1,
        .param_names = (char *[]){"filename"},
        .param_types = (char *[]){"char *"},
        .param_descriptions = (char *[]){"Path to words.txt file"}
    };

    functions[num_functions++] = (FunctionDef){
        .name = "sortWord2",
        .signature = "TList *sortWord2(TList *syn)",
        .description = "Sort words by character count",
        .category = "Code",
        .num_params = 1,
        .param_names = (char *[]){"filename"},
        .param_types = (char *[]){"char *"},
        .param_descriptions = (char *[]){"Path to words.txt file"}
    };

    functions[num_functions++] = (FunctionDef){
        .name = "sortWord3",
        .signature = "TList *sortWord3(TList *syn)",
        .description = "Sort words by vowel count",
        .category = "Code",
        .num_params = 1,
        .param_names = (char *[]){"filename"},
        .param_types = (char *[]){"char *"},
        .param_descriptions = (char *[]){"Path to words.txt file"}
    };
}

// UI event handlers
void on_category_changed(GtkComboBox *widget, gpointer user_data) {
    GtkTreeIter iter;
    if (gtk_combo_box_get_active_iter(widget, &iter)) {
        GtkTreeModel *model = gtk_combo_box_get_model(widget);
        gchar *category;
        gtk_tree_model_get(model, &iter, 0, &category, -1);
        
        populate_function_list(category);
        
        g_free(category);
    }
}

void on_function_selected(GtkListBox *box, GtkListBoxRow *row, gpointer user_data) {
    if (row == NULL) return;
    
    int index = gtk_list_box_row_get_index(row);
    
    // Find the selected function
    const char *category = gtk_combo_box_text_get_active_text(GTK_COMBO_BOX_TEXT(category_combo));
    int count = 0;
    
    for (int i = 0; i < num_functions; i++) {
        if (strcmp(functions[i].category, category) == 0) {
            if (count == index) {
                current_function = &functions[i];
                break;
            }
            count++;
        }
    }
    
    if (current_function == NULL) return;
    
    // Update status bar
    gtk_statusbar_push(GTK_STATUSBAR(status_bar), status_context_id, 
                       current_function->description);
    
    // Create argument widgets
    create_argument_widgets(current_function);
    
    // Enable execute button
    gtk_widget_set_sensitive(execute_button, TRUE);
}

// Function to capture output from functions by redirecting to a file
char* capture_to_file(void (*func)()) {
    char tempFileName[L_tmpnam];
    char* buffer = NULL;
    FILE* tempFile;
    long fileSize;
    size_t bytesRead;
    FILE* savedStdout;
    
    // Generate a temporary file name
    tmpnam(tempFileName);
    
    // Save the current stdout
    savedStdout = stdout;
    
    // Open a temporary file for writing
    tempFile = fopen(tempFileName, "w");
    if (tempFile == NULL) {
        return strdup("Error: Could not capture output");
    }
    
    // Redirect stdout to our temporary file
    stdout = tempFile;
    
    // Call the function that will now print to our file
    func();
    
    // Flush the buffer to ensure all output is written
    fflush(stdout);
    
    // Restore original stdout
    stdout = savedStdout;
    
    // Close the temporary file
    fclose(tempFile);
    
    // Open the file for reading
    tempFile = fopen(tempFileName, "r");
    if (tempFile == NULL) {
        remove(tempFileName);
        return strdup("Error: Could not read captured output");
    }
    
    // Get the file size
    fseek(tempFile, 0, SEEK_END);
    fileSize = ftell(tempFile);
    rewind(tempFile);
    
    // Allocate memory for the buffer
    buffer = (char*)malloc(fileSize + 1);
    if (buffer == NULL) {
        fclose(tempFile);
        remove(tempFileName);
        return strdup("Error: Memory allocation failed");
    }
    
    // Read the file content into the buffer
    bytesRead = fread(buffer, 1, fileSize, tempFile);
    buffer[bytesRead] = '\0';
    
    // Close and delete the temporary file
    fclose(tempFile);
    remove(tempFileName);
    
    return buffer;
}

void on_execute_clicked(GtkButton *button, gpointer user_data) {
    if (current_function == NULL) return;
    
    // Get arguments from entry widgets
    char *args[10]; // Assuming max 10 arguments
    for (int i = 0; i < current_function->num_params; i++) {
        args[i] = strdup(gtk_entry_get_text(GTK_ENTRY(arg_entries[i])));
    }
    
    // Clear output
    clear_output();
    
    // Execute the function based on its name
    if (strcmp(current_function->name, "fillTree") == 0) {
        TTree2 *tree = fillTree(args[0]);
        if (tree) {
            append_output("Tree filled successfully.\n");
        } else {
            append_output("Failed to fill tree.\n");
        }
    }
    else if (strcmp(current_function->name, "printTreeNodeCharacteristics") == 0) {
        TTree2 *tree = fillTree(args[0]);
        if (tree) {
            // Create a capture function
            void print_func() {
                printTreeNodeCharacteristics(tree, args[1]);
            }
            
            // Capture output
            char* output = capture_to_file(print_func);
            if (output) {
                append_output(output);
                free(output);
            }
        } else {
            append_output("Failed to fill tree.\n");
        }
    }
    else if (strcmp(current_function->name, "TraversalBSTinOrder") == 0) {
        TTree2 *tree = fillTree(args[0]);
        if (tree) {
            append_output("In-order traversal:\n");
            
            // Create a capture function
            void traverse_func() {
                TraversalBSTinOrder(tree);
            }
            
            // Capture output
            char* output = capture_to_file(traverse_func);
            if (output) {
                append_output(output);
                free(output);
            }
        } else {
            append_output("Failed to fill tree.\n");
        }
    }
    else if (strcmp(current_function->name, "countWordOccurrence") == 0) {
        FILE *f = fopen(args[0], "r");
        if (f) {
            int count = countWordOccurrence(f, args[1]);
            char result[100];
            sprintf(result, "Word '%s' occurs %d times in the file.\n", args[1], count);
            append_output(result);
            fclose(f);
        } else {
            append_output("Failed to open file.\n");
        }
    }
    else if (strcmp(current_function->name, "isPalindromWord") == 0) {
        bool is_palindrome = isPalindromWord(args[0]);
        if (is_palindrome) {
            append_output("The word is a palindrome.\n");
        } else {
            append_output("The word is not a palindrome.\n");
        }
    }
    else if (strcmp(current_function->name, "wordPermutation") == 0) {
        // Create a capture function
        void perm_func() {
            wordPermutation(args[0]);
        }
        
        // Capture output
        char* output = capture_to_file(perm_func);
        if (output) {
            append_output("Permutations:\n");
            append_output(output);
            free(output);
        }
    }
    else if (strcmp(current_function->name, "sortWord") == 0 || 
             strcmp(current_function->name, "sortWord2") == 0 || 
             strcmp(current_function->name, "sortWord3") == 0) {
        FILE *f = fopen(args[0], "r");
        if (f) {
            TList *list = getSynWords(f);
            fclose(f);
            
            if (list) {
                if (strcmp(current_function->name, "sortWord") == 0) {
                    list = sortWord(list);
                    append_output("Words sorted alphabetically:\n");
                } 
                else if (strcmp(current_function->name, "sortWord2") == 0) {
                    list = sortWord2(list);
                    append_output("Words sorted by character count:\n");
                }
                else if (strcmp(current_function->name, "sortWord3") == 0) {
                    list = sortWord3(list);
                    append_output("Words sorted by vowel count:\n");
                }
                
                // Define a wrapper function
                void print_func() {
                    printWords(list, 0);
                }
                
                // Capture output
                char* output = capture_to_file(print_func);
                if (output) {
                    append_output(output);
                    free(output);
                }
            } else {
                append_output("Failed to process words.\n");
            }
        } else {
            append_output("Failed to open file.\n");
        }
    }
    
    // Free allocated memory for arguments
    for (int i = 0; i < current_function->num_params; i++) {
        free(args[i]);
    }
}

// Output functions
void clear_output() {
    GtkTextIter start, end;
    gtk_text_buffer_get_bounds(output_buffer, &start, &end);
    gtk_text_buffer_delete(output_buffer, &start, &end);
}

void append_output(const char *text) {
    GtkTextIter end;
    gtk_text_buffer_get_end_iter(output_buffer, &end);
    gtk_text_buffer_insert(output_buffer, &end, text, -1);
}

// UI creation functions
void populate_function_list(const char *category) {
    // Clear the current list
    GList *children, *iter;
    children = gtk_container_get_children(GTK_CONTAINER(function_list));
    for (iter = children; iter != NULL; iter = g_list_next(iter))
        gtk_widget_destroy(GTK_WIDGET(iter->data));
    g_list_free(children);
    
    // Add functions for the selected category
    for (int i = 0; i < num_functions; i++) {
        if (strcmp(functions[i].category, category) == 0) {
            GtkWidget *row = gtk_list_box_row_new();
            GtkWidget *label = gtk_label_new(functions[i].name);
            gtk_container_add(GTK_CONTAINER(row), label);
            gtk_widget_set_halign(label, GTK_ALIGN_START);
            gtk_widget_set_margin_start(label, 5);
            gtk_widget_set_margin_end(label, 5);
            gtk_widget_set_margin_top(label, 5);
            gtk_widget_set_margin_bottom(label, 5);
            gtk_widget_show_all(row);
            gtk_container_add(GTK_CONTAINER(function_list), row);
        }
    }
}

void create_argument_widgets(FunctionDef *func) {
    // Clear existing widgets
    GList *children, *iter;
    children = gtk_container_get_children(GTK_CONTAINER(args_container));
    for (iter = children; iter != NULL; iter = g_list_next(iter))
        gtk_widget_destroy(GTK_WIDGET(iter->data));
    g_list_free(children);
    
    // Free previous arg_entries
    if (arg_entries) {
        free(arg_entries);
        arg_entries = NULL;
    }
    
    num_arg_entries = func->num_params;
    arg_entries = (GtkWidget **)malloc(num_arg_entries * sizeof(GtkWidget *));
    
    // Create a label and entry for each parameter
    for (int i = 0; i < func->num_params; i++) {
        GtkWidget *hbox = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 5);
        
        GtkWidget *label = gtk_label_new(func->param_names[i]);
        gtk_widget_set_halign(label, GTK_ALIGN_START);
        gtk_widget_set_size_request(label, 100, -1);
        
        GtkWidget *entry = gtk_entry_new();
        gtk_widget_set_tooltip_text(entry, func->param_descriptions[i]);
        
        gtk_box_pack_start(GTK_BOX(hbox), label, FALSE, FALSE, 0);
        gtk_box_pack_start(GTK_BOX(hbox), entry, TRUE, TRUE, 0);
        
        gtk_box_pack_start(GTK_BOX(args_container), hbox, FALSE, FALSE, 5);
        
        arg_entries[i] = entry;
    }
    
    gtk_widget_show_all(args_container);
}

static void activate(GtkApplication *app, gpointer user_data) {
    // Initialize function data
    init_functions();
    
    // Create the main window
    window = gtk_application_window_new(app);
    gtk_window_set_title(GTK_WINDOW(window), "Data Structures Functions GUI");
    gtk_window_set_default_size(GTK_WINDOW(window), 800, 600);
    gtk_container_set_border_width(GTK_CONTAINER(window), 10);
    
    // Main layout
    GtkWidget *main_box = gtk_box_new(GTK_ORIENTATION_VERTICAL, 10);
    
    // Top part: category selector and function list
    GtkWidget *top_box = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 10);
    
    // Category combo box
    GtkWidget *category_frame = gtk_frame_new("Category");
    GtkWidget *category_box = gtk_box_new(GTK_ORIENTATION_VERTICAL, 5);
    gtk_container_set_border_width(GTK_CONTAINER(category_box), 5);
    
    category_combo = gtk_combo_box_text_new();
    for (int i = 0; i < num_categories; i++) {
        gtk_combo_box_text_append_text(GTK_COMBO_BOX_TEXT(category_combo), categories[i].name);
    }
    g_signal_connect(category_combo, "changed", G_CALLBACK(on_category_changed), NULL);
    
    gtk_box_pack_start(GTK_BOX(category_box), category_combo, FALSE, FALSE, 0);
    gtk_container_add(GTK_CONTAINER(category_frame), category_box);
    
    // Function list
    GtkWidget *function_frame = gtk_frame_new("Functions");
    GtkWidget *function_scrolled = gtk_scrolled_window_new(NULL, NULL);
    gtk_scrolled_window_set_policy(GTK_SCROLLED_WINDOW(function_scrolled), 
                                  GTK_POLICY_NEVER, GTK_POLICY_AUTOMATIC);
    
    function_list = gtk_list_box_new();
    g_signal_connect(function_list, "row-selected", G_CALLBACK(on_function_selected), NULL);
    
    gtk_container_add(GTK_CONTAINER(function_scrolled), function_list);
    gtk_container_add(GTK_CONTAINER(function_frame), function_scrolled);
    
    // Add to top box
    gtk_box_pack_start(GTK_BOX(top_box), category_frame, FALSE, FALSE, 0);
    gtk_box_pack_start(GTK_BOX(top_box), function_frame, TRUE, TRUE, 0);
    
    // Middle part: arguments and execute button
    GtkWidget *middle_box = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 10);
    
    // Arguments container
    GtkWidget *args_frame = gtk_frame_new("Arguments");
    GtkWidget *args_scroll = gtk_scrolled_window_new(NULL, NULL);
    gtk_scrolled_window_set_policy(GTK_SCROLLED_WINDOW(args_scroll), 
                                  GTK_POLICY_NEVER, GTK_POLICY_AUTOMATIC);
    
    args_container = gtk_box_new(GTK_ORIENTATION_VERTICAL, 5);
    gtk_container_set_border_width(GTK_CONTAINER(args_container), 5);
    
    gtk_container_add(GTK_CONTAINER(args_scroll), args_container);
    gtk_container_add(GTK_CONTAINER(args_frame), args_scroll);
    
    // Execute button
    GtkWidget *button_box = gtk_box_new(GTK_ORIENTATION_VERTICAL, 5);
    gtk_widget_set_valign(button_box, GTK_ALIGN_CENTER);
    
    execute_button = gtk_button_new_with_label("Execute");
    gtk_widget_set_sensitive(execute_button, FALSE);
    g_signal_connect(execute_button, "clicked", G_CALLBACK(on_execute_clicked), NULL);
    
    gtk_box_pack_start(GTK_BOX(button_box), execute_button, FALSE, FALSE, 0);
    
    // Add to middle box
    gtk_box_pack_start(GTK_BOX(middle_box), args_frame, TRUE, TRUE, 0);
    gtk_box_pack_start(GTK_BOX(middle_box), button_box, FALSE, FALSE, 0);
    
    // Bottom part: output text area
    GtkWidget *output_frame = gtk_frame_new("Output");
    GtkWidget *output_scroll = gtk_scrolled_window_new(NULL, NULL);
    gtk_scrolled_window_set_policy(GTK_SCROLLED_WINDOW(output_scroll), 
                                  GTK_POLICY_AUTOMATIC, GTK_POLICY_AUTOMATIC);
    
    output_text = gtk_text_view_new();
    gtk_text_view_set_editable(GTK_TEXT_VIEW(output_text), FALSE);
    gtk_text_view_set_wrap_mode(GTK_TEXT_VIEW(output_text), GTK_WRAP_WORD_CHAR);
    output_buffer = gtk_text_view_get_buffer(GTK_TEXT_VIEW(output_text));
    
    gtk_container_add(GTK_CONTAINER(output_scroll), output_text);
    gtk_container_add(GTK_CONTAINER(output_frame), output_scroll);
    
    // Status bar
    status_bar = gtk_statusbar_new();
    status_context_id = gtk_statusbar_get_context_id(GTK_STATUSBAR(status_bar), "Function Info");
    
    // Add all components to main box
    gtk_box_pack_start(GTK_BOX(main_box), top_box, FALSE, FALSE, 0);
    gtk_box_pack_start(GTK_BOX(main_box), middle_box, FALSE, FALSE, 0);
    gtk_box_pack_start(GTK_BOX(main_box), output_frame, TRUE, TRUE, 0);
    gtk_box_pack_start(GTK_BOX(main_box), status_bar, FALSE, FALSE, 0);
    
    // Final setup
    gtk_container_add(GTK_CONTAINER(window), main_box);
    gtk_combo_box_set_active(GTK_COMBO_BOX(category_combo), 0);
    
    gtk_widget_show_all(window);
}

int main(int argc, char **argv) {
    GtkApplication *app;
    int status;
    
    #if GLIB_CHECK_VERSION(2, 74, 0)
        app = gtk_application_new("org.gtk.dsfunction", G_APPLICATION_DEFAULT_FLAGS);
    #else
        app = gtk_application_new("org.gtk.dsfunction", G_APPLICATION_FLAGS_NONE);
    #endif
    
    g_signal_connect(app, "activate", G_CALLBACK(activate), NULL);
    status = g_application_run(G_APPLICATION(app), argc, argv);
    g_object_unref(app);
    
    return status;
}