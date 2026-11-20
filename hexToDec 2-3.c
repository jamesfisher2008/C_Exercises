#include <stdio.h>
#include <string.h>
#include <math.h>

int htoi(char s[]) {
    int length = strlen(s);
    unsigned int value = 0;
    int position = 0;
    for (int i = length - 1; i >= 0; i--) {
        if (s[i] >= '0' && s[i] <= '9')  {
            value = value + pow(16,position)*(s[i] - '0');
        } else if (s[i] >= 'a' && s[i] <= 'f') {
            value = value + pow(16,position)*(s[i] - 'a' + 10);
        } else if (s[i] >= 'A' && s[i] <= 'F') {
            value = value + pow(16,position)*(s[i] - 'A' + 10);
        } else {
            return value;
        }
        position++;
    }
    return value;
}

int main() {
    char string[] = "0X7EA";
    printf("%d",htoi(string));
    return 0;
}