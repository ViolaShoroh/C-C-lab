#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct TOVAR {
    char NAZV[50];
    int STOIM;
    int KOL;
};

int main() {
    struct TOVAR SHOP[5];
    int i, sum, k = 0;
    char input_buffer[100];

    system("chcp 1251");
    system("cls");

    for (i = 0; i < 5; i++) {
        printf("Введите название %d товара: ", i + 1);
        fgets(SHOP[i].NAZV, 50, stdin);
        SHOP[i].NAZV[strcspn(SHOP[i].NAZV, "\n")] = '\0'; 

        printf("Введите стоимость %d товара: ", i + 1);
        fgets(input_buffer, 100, stdin);
        SHOP[i].STOIM = atoi(input_buffer);

        printf("Введите количество %d товара: ", i + 1);
        fgets(input_buffer, 100, stdin);
        SHOP[i].KOL = atoi(input_buffer);
    }

    printf("Введите сумму, чтобы найти товары большей стоимости: ");
    fgets(input_buffer, 100, stdin);
    sum = atoi(input_buffer);

    printf("\nТовары дороже %d рублей:\n", sum);
    for (i = 0; i < 5; i++) {
        if (SHOP[i].STOIM > sum) {
            k = 1;
            printf("  %s: %d рублей, %d шт.\n", SHOP[i].NAZV, SHOP[i].STOIM, SHOP[i].KOL);
        }
    }

    if (k == 0) {
        printf("Нет товаров дороже %d рублей.\n", sum);
    }

    getchar();
    return 0;
}