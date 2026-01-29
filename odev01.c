#include <stdio.h>

int main() {
    FILE *file = fopen("sayilar.txt", "r");
    FILE *fp = fopen("sayilar2.txt", "w");
    int dizi[100], flag;

    if (file == NULL || fp == NULL) {
        printf("Dosya acma hatasi!\n");
        return 1;
    }

    for (int i = 0; i < 100; i++) {
        if (fscanf(file, "%d", &dizi[i]) != 1) break;
    }

    for (int a = 0; a < 100; a++) {
        flag = 0;
        if (dizi[a] < 2) {
            flag = 1;
        } else {
            for (int j = 2; j <= dizi[a] / 2; j++) {
                if (dizi[a] % j == 0) {
                    flag = 1;
                    break;
                }
            }
        }

        if (flag == 0) {
            fprintf(fp, "ASAL SAYILAR: %d\n", dizi[a]);
        } else {
            fprintf(fp, "ASAL OLMAYAN SAYILAR: %d\n", dizi[a]);
        }
    }

    fclose(file);
    fclose(fp);

    return 0;
}
