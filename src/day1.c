#include <stdio.h>
#include <errno.h>
extern int errno;
int main() {
    FILE *f;

    // cols are for elf no and calories she has
    // rows are for current elf, top 1, 2 and 3
    int elf[4][2] = {1, 0, 0, 0, 0, 0, 0, 0};

    int cal, i, j, k;
    char calories[20];

    f = fopen("input/day1.txt", "r");
    if (f == NULL) {
        perror("Cannot open ./input/day1.txt");
        return errno;
    }
    while ( ! feof(f) ) {
        fgets(calories, 20, f);
        if (calories[0] != '\n') {
            sscanf(calories, "%d", &cal);
            elf[0][1] += cal;
        } else {
            for (i = 1; i <= 3; i++)
                if (elf[0][1] > elf[i][1]) {
                    for (j = 3; j > i; j--)
                            for (k = 0; k <= 1; k++)
                                    elf[j][k] = elf[j-1][k];
                    elf[i][0] = elf[0][0];
                    elf[i][1] = elf[0][1];
                    break;
                }
            elf[0][0]++;
            elf[0][1] = 0;
        }
    }
    fclose(f);
    printf("Elf with most calories: %d\n", elf[1][0]);
    printf("Total amount of calories with that elf: %d\n\n", elf[1][1]);
    printf("Elf with second top calories: %d\n", elf[2][0]);
    printf("Total amount of calories with that elf: %d\n\n", elf[2][1]);
    printf("Elf with third top calories: %d\n", elf[3][0]);
    printf("Total amount of calories with that elf: %d\n\n", elf[3][1]);
    printf("Total amount of calories available with top 3: %d\n", elf[1][1] + elf[2][1] + elf[3][1]);
    return 0;
}
