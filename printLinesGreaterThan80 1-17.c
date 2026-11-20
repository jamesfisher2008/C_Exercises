#include <stdio.h>
#define MAXLINE 1024 /* maximum input line length */
#define LIMIT 80
int getline(char line[], int maxline);
void copy(char to[], char from[]);

 /* print the longest input line */
int main() {
    int len; /* current line length */
    char line[MAXLINE]; /* current input line */

    while ((len = getline(line, MAXLINE)) > 0) {
        if (len > LIMIT) {
            printf("%d: %s",len,line);
            }
        }
    return 0;
}

/* getline: read a line into s, return length */
int getline(char s[],int lim){
    int c, i;
    i = 0;
    while((c=getchar())!=EOF && c!='\n') {
        if (i < MAXLINE) {
            s[i] = c;
        }
        i++;
    }
    s[i] = '\0';
    return i;
}