#include <stdio.h>
#include <stdlib.h>
#include<string.h>

typedef struct PString {
        char *chars;
        int (*length)();
} PString;

int length(PString *self) {
    return strlen(self->chars);
}

PString *initializeString(int n) {
    PString *str = malloc(sizeof(PString));

    str->chars = malloc(sizeof(char) * n);
    str->length = length;

    // str[0] = '\0'; //add a null terminator in case the string is used before any other initialization.

    return str;
}

int main() {
    PString *p = initializeString(30);
    strcpy(p->chars, "aaaaaaaaaaaaaa");
    printf("\n%d", p->length(p));
    
    return 0;
}