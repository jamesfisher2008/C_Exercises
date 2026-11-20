#include <stdio.h>
#define MAXLINE 1024

int getLine(char s[],int lim) {
    int c, i;
    for (i=0; i < lim-1 && (c=getchar())!=EOF && c!='\n'; ++i) {
        s[i] = c;
    }
    if (c == '\n') {
        s[i] = c;
        ++i;
    }
    s[i] = '\0';
    return i;
}


void reverses(char line[],char reversedLine[],int length) {
    int q = length - 2;
    for(int i = 0; i < length; i++) {
        reversedLine[q] = line[i];
        q--;
    }
    reversedLine[length - 1] = '\0';
}

int main() {
    char line[MAXLINE];
    char reversedLine[MAXLINE];
    int length;
    do {
        length = getLine(line,MAXLINE);
        reverses(line,reversedLine,length);
        printf("%s\n",reversedLine);
    } while (length > 1);
    return 0;
}