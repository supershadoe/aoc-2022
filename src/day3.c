#include <stdio.h>
#include <errno.h>
#include <string.h>

extern int errno;

int main() {
    FILE *f;
    char items[60], *sec_half, first_half[30], *match;
    int sum = 0;
    f = fopen("input/day3.txt", "r");
    if (f == NULL) {
        perror("Cannot open input/day3.txt");
        return errno;
    }

    while ( fgets(items, 60, f) ) {
        strncpy(first_half, items, strlen(items)/2);
        sec_half = &items[strlen(items)/2];
        match = strpbrk(first_half, sec_half);
        if (match != NULL)
            if (*match >= 'A' && *match <= 'Z')
                sum += *match - 38;
            else if (*match >= 'a' && *match <= 'z')
                sum += *match - 96;
            else
                printf("Invalid input.\n"); // never executed
    }
    fclose(f);
    printf("The sum of the priorities of the item types is %d.\n", sum);

    return 0;
}
