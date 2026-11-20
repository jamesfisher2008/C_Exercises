#include <stdio.h>
#define MAXLINE 1024
#define TABWIDTH 3
int detab(char tabbed[],char detabbed[]) {
    int detabbedPointer = 0;
    int tabbedPointer = 0;
    while(tabbed[tabbedPointer] != '\0') {
        if (tabbed[tabbedPointer] == '\t') {
            for(int x = 0;x < TABWIDTH;x++) {
                detabbed[detabbedPointer] = ' ';
                detabbedPointer++;
            }
            tabbedPointer++;
        } else {
            detabbed[detabbedPointer] = tabbed[tabbedPointer];
            detabbedPointer++;
            tabbedPointer++;
        }
    }
    tabbed[tabbedPointer] = '\0';
    return 0;
}

int getLine(char tabbed[]) {
    int i = 0;
    int c = 0;
    while ((c = getchar()) != EOF && i < MAXLINE - 1) {
        tabbed[i] = c;
        i++;
    }
    tabbed[i] = '\0';
    return 0;
}

int main() {
    char tabbed[MAXLINE];
    char detabbed[(MAXLINE - 1) * TABWIDTH + 1];
    int length;
    do {
        length = getLine(tabbed);
        detab(tabbed,detabbed);
        printf("%s",detabbed);
    } while(length > 1);
    return 0;
}