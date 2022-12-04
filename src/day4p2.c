#include <stdio.h>
#include <errno.h>
#include <string.h>

extern int errno;

int main() {
    FILE *f;
    int l1, u1, l2, u2, counter = 0;
    f = fopen("input/day4.txt", "r");
    if (f == NULL) {
        perror("Cannot open input/day4.txt");
        return errno;
    }

    while ( fscanf(f, "%d-%d,%d-%d", &l1, &u1, &l2, &u2) != -1 ) {
        if ((l2 >= l1 && l2 <= u1) || (l1 >= l2 && l1 <= u2))
            counter++;
    }

    printf("Number of assignment pairs with any overlap at all is %d.\n", counter);
}
