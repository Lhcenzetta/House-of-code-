#include <stdio.h>

// Function to calcul lenght of string
int my_strlen(const char *str) {
    int count = 0;
    while (str[count] != '\0') {
        count++;
    }
    return count;
}

// Function to reverse a string in place
void reverse_string(char *str) {
    int i = 0;
    int j = my_strlen(str) - 1;
    char temp;

    while (i < j) {
        temp = str[i];
        str[i] = str[j];
        str[j] = temp;
        i++;
        j--;
    }
}

// Function to reverse the order of words in a string
void reverse_words(char *str) {
    int len;
    int begin,end;

    // this section for Reverse the entire string
    reverse_string(str);

    // Step 2: Reverse each word individually
    len = my_strlen(str);
    begin = 0, end = 0;
    while (end < len) {
        // Find the beginning of a word
        while (str[end] == ' ' && end < len) {
            end++;
        }
        begin = end;  // Mark the begin of the word

        // Find the end of the word
        while (str[end] != ' ' && str[end] != '\0') {
            end++;
        }

        // Reverse the word
        int word_end = end - 1;
        while (begin < word_end) {
            char temp = str[begin];
            str[begin] = str[word_end];
            str[word_end] = temp;
            begin++;
            word_end--;
        }
    }
}

// please fell free to test the code
int main(void) {
    char test1[] = "Welcome To House of Code";
    char test2[] = "IAE CLUB is awesome";
    char test3[] = "  Reverse this sentence  ";
    char test4[] = "SingleWord";

    printf("Before: \"%s\"\n", test1);
    reverse_words(test1);
    printf("After: \"%s\"\n\n", test1);

    printf("Before: \"%s\"\n", test2);
    reverse_words(test2);
    printf("After: \"%s\"\n\n", test2);

    printf("Before: \"%s\"\n", test3);
    reverse_words(test3);
    printf("After: \"%s\"\n\n", test3);

    printf("Before: \"%s\"\n", test4);
    reverse_words(test4);
    printf("After: \"%s\"\n\n", test4);

    return 0;
}


