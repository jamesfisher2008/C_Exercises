#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>

unsigned short int setbits(unsigned short int x, int p, int n, unsigned short int y) { //zero-based indexing 0,1,2,3... MSB
    //create maskX
    unsigned short int maskXRight = ~0;
    maskXRight = maskXRight >> (p+n);
    unsigned short int maskXLeft = ~0;
    maskXLeft = maskXLeft << (16-p);
    unsigned short int maskX = maskXLeft | maskXRight;
    //apply maskX
    unsigned short int tempX = x & maskX;
    //create maskY via shifting
    unsigned short int maskY = ~0;
    maskY = maskY >> (16-n);
    //apply maskY
    unsigned short int tempY = y & maskY;
    //shift y into position
    tempY = tempY << 16-(p+n);
    // compare
    x = tempX | tempY;
    return x;
}

unsigned short int invert(unsigned short int x, int p, int n) { //zero-based indexing 0,1,2,3... MSB
    unsigned short int doInvertMask;
    unsigned short int dontInvertMask;
    unsigned short int maskRight = ~0;
    unsigned short int maskLeft = ~0;

    maskRight = maskRight >> (p+n);
    maskLeft = maskLeft << (16-p);
    dontInvertMask = maskLeft | maskRight;
    doInvertMask = ~dontInvertMask;

    unsigned short int doInvert;
    unsigned short int dontInvert;

    doInvert = x & doInvertMask;
    dontInvert = x & dontInvertMask;

    unsigned short int inverted;
    inverted = ~doInvert & doInvertMask;

    x = dontInvert | inverted;
    return x;
}

unsigned short int rightrot(unsigned short int x, int n) {//zero-based indexing 0,1,2,3... MSB
    unsigned short int fallen = x << (16-n);
    x = x >> n;
    x = x | fallen;
    return x;
}

int main() {
    unsigned short int x = setbits(9,0,1,255);
    printf("%d",x);
    return 0;
}