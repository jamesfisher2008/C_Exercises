#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>

void squeeze(char s1[], char s2[]){
    int i, j;
    for (i = j = 0; s1[i] != '\0'; i++) {
        bool flag = true;
        int k = 0;
        while (flag == true && (s2[k] != '\0')) {
            if (s1[i] == s2[k]) {
                flag = false;
            }
            k++;
        }
        if (flag == true) { //if not in s2
            s1[j++] = s1[i];
        }
    }
    s1[j] = '\0';
}

int any(char s1[], char s2[]){
    int i;
    for (i = 0; s1[i] != '\0'; i++) {
        bool flag = true;
        int k = 0;
        while (flag == true && (s2[k] != '\0')) {
            if (s1[i] == s2[k]) {
                flag = false;
                return i;
            }
            k++;
        }
    }
    return -1;
}

int main() {
    char str[] = "hello i love you";
    squeeze(str,"l");
    printf("%s\n",str);
    printf("%d\n",any(str,"iu"));
    return 0;
}