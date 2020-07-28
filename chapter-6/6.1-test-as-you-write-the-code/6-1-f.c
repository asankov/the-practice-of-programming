#include <stdio.h>

void character(char c);

int main() {
    character('A');
    character('Z');
    character('L');
    character('M');

    character('a');
    character('z');
    character('l');
    character('m');
}

void character(char c)
{
    printf("%c - ", c);
    if (c >= 'A' && c <= 'Z') {
        if (c <= 'L')
            printf("first half of alphabet\n");
        else
            printf("second half of alphabet\n");
    }
}