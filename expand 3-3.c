#include <stdio.h>

int expand(char s1[],char s2[]) {
    int q = 0;
    int len = 0;
    for (int i = 0; s1[i] != '\0'; i++) {
        len++;
    }

    for (int i = 0; i < len; i++) {
        if (s1[i] == '-' && i != 0 && i < len - 1) {
            char first = s1[i-1];
            char last = s1[i+1];
            for (int i = first + 1; i < last; i++, q++) {
                s2[q] = i;
            }
        } else {
            s2[q++] = s1[i];
        }
    }

    s2[q] = '\0';
    return 0;
}

int main (void) {
    char output[127] = "";
    expand("0-9 hello world!A-Z",output);
    printf("%s",output);
    return 0;
}