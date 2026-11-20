#include <stdio.h>
#include <stdbool.h>

void escape(char s[],char t[]) { //visable escape sequences
    int tIndex = 0;
    int sIndex = 0;
    bool flag = true;
    while (flag) {
        switch (s[sIndex]) {
            case '\n' : 
                t[tIndex++] = '\\';
                t[tIndex++] = 'n';
                break;
            case '\t' :
                t[tIndex++] = '\\';
                t[tIndex++] = 't';
                break;   
            case '\0' :
                t[tIndex++] = s[sIndex];
                flag = false;
                break;
            default:  
                t[tIndex++] = s[sIndex];
                break;
        }
        sIndex++;
    }
}

void escapeInverse(char s[],char t[]) { //invisable escape sequences
    int tIndex = 0;
    int sIndex = 0;
    bool flag = true;
    while (flag) {
        switch (s[sIndex]) {
            case '\\' : 
                switch (s[sIndex+1]) {
                    case 't' :
                        t[tIndex++] = '\t';
                        sIndex += 2;
                        break;
                    case 'n' :
                        t[tIndex++] = '\n';
                        sIndex += 2;
                        break;
                    default:
                        t[tIndex++] = s[sIndex++];
                        break;
                }
                break;
            case '\0' :
                t[tIndex] = '\0';
                flag = false;
                break;
            default:
                t[tIndex++] = s[sIndex++];
                break;
            }
    }
}

int main() {
    char original[] = "hello\nworld\t";
    char escaped[100];
    char unescaped[100];
    escape(original,escaped);
    printf("%s\n",escaped);
    escapeInverse(escaped,unescaped);
    printf("%s",unescaped);
    return 0;
}