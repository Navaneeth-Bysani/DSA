// A void pointer is a pointer that has no associated data type with it. 
// A void pointer can hold address of any type and can be typcasted to any type.

//These can be used to create generic functions or data types. Used in qsort() operation
#include<stdio.h>

int main() {
    int a = 10;
    char b = 'c';

    void *p = &a;
    p = &b;
    printf("%c", *(char*) p);
    // printf("%c", *p);
    // The above statement causes an error, Void pointer doesn't allow deserialisation but can be achieved through tupe casting
}