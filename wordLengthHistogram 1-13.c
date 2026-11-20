#include <stdio.h>
#define IN   1
#define OUT  0

int main(){
    int state = OUT;
    int c;
    int counter = 0;
    int array[45];

    for (int i = 0;i<45;i++) {
        array[i] = 0;
    }

    while((c = getchar()) != EOF) {
        if ((c == ' ' || c == '\n' || c == '\t') && state == IN) {
            state = OUT;
            array[counter-1]++;
            counter = 0;
        } else if (c != ' ' && c!= '\n' && c!= '\t') { 
            state = IN;
            counter++;
        }
    }
    if (state == IN) {
        array[counter-2]++;
        counter = 0;
    }
    
    for (int outer = 0;outer<45;outer++) {
        printf("%d: ",outer+1);
        for (int inner = 0;inner<array[outer];inner++) {
            putchar('-');
        }
        putchar('\n');
    }
    return 0;
}