#include <stdio.h>

int main(){
    int characters[26];
    int c;

    for (int i = 0; i < 26; i++){
        characters[i] = 0;
    }

    while ((c = getchar()) != EOF) {
        if ('a' <= c && c <= 'z') {
            characters[c - 'a']++;
        } else if ('A' <= c && c <= 'Z') {
            characters[c - 'A']++;
        }
    }
    for (int outer = 0; outer < 26; outer++) {
        printf("%c: ",outer+'A');
        for (int inner = 0; inner < characters[outer]; inner++) {
            putchar('-');
        }
        putchar('\n');
    }
    return 0;
}