#include<stdio.h>

void sample() {
    printf("\n%d", sample);
}

int main() {
    printf("%d", main);
    printf("\n%d", sizeof(main));
    sample();
}