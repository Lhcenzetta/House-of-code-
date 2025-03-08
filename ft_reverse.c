#include <stdio.h>

// this function has alerady solved
int my_strlen(const char *str) {
    int count = 0;
    while (str[count] != '\0') {
        count++;
    }
    return count;
}

// this is function principal
void reverse_string(char *str) {
    int i;
    int j;
    char swap;

    i = 0;
    j = my_strlen(str) - 1; // call the function my_strlen
    while (i < j) {  // Stop when i >= j to avoid extra swaps
        swap = str[j];
        str[j] = str[i];  
        str[i] = swap;     
        i++;
        j--;
    }
}

// this section for testing fell free to do it .
int main(void) {
    char test1[] = " edoc fo esuoH oT emocleW ";
    char test2[] = " uoy pleh lliw ti ;3 melborp ni noitcnuf siht esU ";
    char test3[] = " Hello World ";
    char test4[] = " G ";

    printf("Before: %s\n", test1);
    reverse_string(test1);
    printf("After: %s\n\n", test1);

    printf("Before: %s\n", test2);
    reverse_string(test2);
    printf("After: %s\n\n", test2);

    printf("Before: %s\n", test3);
    reverse_string(test3);
    printf("After: %s\n\n", test3);

    printf("Before: %s\n", test4);
    reverse_string(test4);
    printf("After: %s\n\n", test4);

    return 0;
}
