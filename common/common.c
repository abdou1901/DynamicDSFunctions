#include "common.h"

// Common utility functions implementation
void printCentered(char *str, int width) {
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

bool includes(char *str, char c, int size) {
    for (int i = 0; i < size; i++) {
        if (str[i] == c) return true;
    }
    return false;
}

int countVowels(char *str) {
    int count = 0;
    int i = 0;
    char vowels[5] = {'a','e','u','i','o'};
    while(str[i] != '\0') {
        if(includes(vowels, str[i], 5)) count++;
        i++;
    }
    return count;
}

int is_vowel(char c) {
    c = tolower(c);
    return(c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' || c == 'y');
}

int count_syllables(const char *word) {
    int count = 0;
    int prev_char_was_vowel = 0;
    int length = strlen(word);
    for (int i = 0; i < length; i++) {
        char c = tolower(word[i]);

        if (is_vowel(c)) {
            if(!prev_char_was_vowel) {
                count++;
                prev_char_was_vowel = 1;
            }
        } else {
            prev_char_was_vowel = 0;
        }
    }
    if(tolower(word[length - 1]) == 'e' && count > 1) count--;
    if(count == 0) count = 1;
    return count;
}

bool isPalindrome(char *s, int l, int r) { 
    return (l >= r) ? 1 : (s[l] == s[r] && isPalindrome(s, l+1, r-1)); 
}

int matchRate(char *word1, char *word2) { 
    int len1 = strlen(word1);
    int len2 = strlen(word2);
    int common = 0;
    for (int i = 0; i < len2; i++) {
        if (word1[i] == word2[i]) common++;
        else break;
    }
    if (common == len2) return 100;
    return (common * 100) / len2;
}

enum VowelType getVowelType(const char *word) {
    const char *diphthongs[] = {"ai", "au", "ei", "oi", "ou", "ow", "oy"};
    for(int i = 0; i < sizeof(diphthongs)/sizeof(diphthongs[0]); i++)
        if (strstr(word, diphthongs[i])) return DIPHTHONG;
    int len = strlen(word);
    if(len >= 2 && word[len-1] == 'e') return LONG;
    return SHORT;
}