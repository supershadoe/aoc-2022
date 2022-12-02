#include <stdio.h>
#include <errno.h>
#include <string.h>

extern int errno;

int main() {
    FILE *f;
    char choices[4];
    int sum = 0;
    f = fopen("input/day2.txt", "r");
    if (f == NULL) {
        perror("Cannot open input/day2.txt");
        return errno;
    }

    // lol hard coded solution
    while ( ! feof(f) ) {
        fgets(choices, 4, f);
        if( ! strcmp(choices, "A X")) sum += 4;
        else if ( ! strcmp(choices, "A Y")) sum += 8;
        else if ( ! strcmp(choices, "A Z")) sum += 3;
        else if ( ! strcmp(choices, "B X")) sum += 1;
        else if ( ! strcmp(choices, "B Y")) sum += 5;
        else if ( ! strcmp(choices, "B Z")) sum += 9;
        else if ( ! strcmp(choices, "C X")) sum += 7;
        else if ( ! strcmp(choices, "C Y")) sum += 2;
        else if ( ! strcmp(choices, "C Z")) sum += 6;
    }
    fclose(f);
    printf("The total score that can be obtained from this strategy guide is %d.\n", sum);
    return 0;
}
