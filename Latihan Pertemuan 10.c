#include <stdio.h>

int main() {
    int angka[10];
    int n = sizeof(angka) / sizeof(angka[0]);

    for (int i = 0; i < n; i++) {
        printf("Masukkan bilangan ke-%d: ", i + 1);
        scanf("%d", &angka[i]);
    }

    printf("\nBilangan ganjil: ");
    for (int i = 0; i < n; i++) {
        if (angka[i] % 2 != 0)
            printf("%d ", angka[i]);
    }

    printf("\nBilangan genap : ");
    for (int i = 0; i < n; i++) {
        if (angka[i] % 2 == 0)
            printf("%d ", angka[i]);
    }

    printf("\n");
    return 0;
}


#include <stdio.h>
void print(float total, float terdingin, float terpanas )
{printf("\nRata-rata : %.2f\n", total / n);
    printf("Terdingin : %.2f\n", terdingin);
    printf("Terpanas  : %.2f\n", terpanas)

}
int main() {
    float suhu[7];
    int n = sizeof(suhu) / sizeof(suhu[0]);

    for (int i = 0; i < n; i++) {
        printf("Masukkan suhu hari ke-%d: ", i + 1);
        scanf("%f", &suhu[i]);
    }

    float total = 0;
    float terdingin = suhu[0];
    float terpanas = suhu[0];

    for (int i = 0; i < n; i++) {
        total += suhu[i];
        if (suhu[i] < terdingin) terdingin = suhu[i];
        if (suhu[i] > terpanas) terpanas = suhu[i];
    }


    print(total, terdingin, terpanas);
    return 0;
}