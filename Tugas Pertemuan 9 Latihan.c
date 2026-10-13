//Patrick Kennedy 825260023
//Latihan 1
#include <stdio.h>

float tambah(float a, float b) ;
float kurang(float a, float b) ;
float kali(float a, float b) ;
float bagi(float a, float b) ;

int main() {
    float a, b, hasil;
    char op;
    char lagi;

    do {
        printf("Masukkan bilangan pertama : ");
        scanf("%f", &a);
        printf("Masukkan bilangan kedua   : ");
        scanf("%f", &b);

        printf("Pilih operasi (+  -  x  /) : ");
        scanf(" %c", &op);

        if (op == '+') {
            hasil = tambah(a, b);
            printf("Hasil: %.2f + %.2f = %.2f\n", a, b, hasil);
        } else if (op == '-') {
            hasil = kurang(a, b);
            printf("Hasil: %.2f - %.2f = %.2f\n", a, b, hasil);
        } else if (op == 'x' || op == 'X' || op == '*') {
            hasil = kali(a, b);
            printf("Hasil: %.2f x %.2f = %.2f\n", a, b, hasil);
        } else if (op == '/') {
            if (b == 0) {
                printf("Error: tidak bisa dibagi dengan 0\n");
            } else {
                hasil = bagi(a, b);
                printf("Hasil: %.2f / %.2f = %.2f\n", a, b, hasil);
            }
        } else {
            printf("Operasi tidak dikenal\n");
        }

        printf("\nHitung lagi? (y/n) : ");
        scanf(" %c", &lagi);
        printf("\n");

    } while (lagi == 'y' || lagi == 'Y');

    printf("Program selesai.\n");
    return 0;
}
float tambah(float a, float b) {
    return a + b;
}

float kurang(float a, float b) {
    return a - b;
}

float kali(float a, float b) {
    return a * b;
}

float bagi(float a, float b) {
    return a / b;
}



//Latihan 2
#include <stdio.h>

float bilangan_pertama = 0;
float bilangan_kedua = 0;

void input_pertama() {
    printf("Masukkan bilangan pertama: ");
    scanf("%f", &bilangan_pertama);
}

void input_kedua() {
    printf("Masukkan bilangan kedua: ");
    scanf("%f", &bilangan_kedua);
}

void tambah() {
    float hasil = bilangan_pertama + bilangan_kedua;
    printf("Hasil: %.2f + %.2f = %.2f\n", bilangan_pertama, bilangan_kedua, hasil);
}

void kurang() {
    float hasil = bilangan_pertama - bilangan_kedua;
    printf("Hasil: %.2f - %.2f = %.2f\n", bilangan_pertama, bilangan_kedua, hasil);
}

void kali() {
    float hasil = bilangan_pertama * bilangan_kedua;
    printf("Hasil: %.2f * %.2f = %.2f\n", bilangan_pertama, bilangan_kedua, hasil);
}

void bagi() {
    if (bilangan_kedua == 0) {
        printf("Error: Pembagian dengan nol tidak diperbolehkan.\n");
    } else {
        float hasil = bilangan_pertama / bilangan_kedua;
        printf("Hasil: %.2f / %.2f = %.2f\n", bilangan_pertama, bilangan_kedua, hasil);
    }
}

int main() {
    char pilihan;
    char lanjut;

    while (1) {
        printf("\n Kalkulator Sederhana \n");
        input_pertama();
        input_kedua();

        printf("Pilih operasi (+, -, x, /): ");
        scanf(" %c", &pilihan);

        if (pilihan == '+') {
            tambah();
        } else if (pilihan == '-') {
            kurang();
        } else if (pilihan == 'x' || pilihan == 'X') {
            kali();
        } else if (pilihan == '/') {
            bagi();
        } else {
            printf("Pilihan tidak valid.\n");
        }

        printf("Ingin menghitung lagi? (y/t): ");
        scanf(" %c", &lanjut);

        if (lanjut == 't' || lanjut == 'T') {
            printf("Program selesai.\n");
            break;
        }
    }

    return 0;
}