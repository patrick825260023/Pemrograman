NOMOR 1

#include <stdio.h>

int main() {
    int n, i, angka;

    printf("Masukkan n: ");
    scanf("%d", &n);

    angka = n;
    for (i = 1; i <= n; i++) {
        printf("%d", angka);
        if (i < n) printf(" + ");
        angka += n;   
    }
    printf("\n");

    return 0;
}

Nomor 2

#include <stdio.h>

int main() {
    const int PIN_BENAR = 123456;
    int pin, percobaan = 0;
    int berhasil = 0;

    while (percobaan < 3) {
        printf("Masukkan PIN: ");
        scanf("%d", &pin);

        if (pin == PIN_BENAR) {
            berhasil = 1;
            break;
        }

        percobaan++;
        if (percobaan < 3) {
            printf("PIN salah! Sisa kesempatan: %d\n", 3 - percobaan);
        }
    }

    if (berhasil) {
        printf("PIN benar. Selamat datang!\n");
    } else {
        printf("Kartu Anda Diblokir\n");
    }

    return 0;
}

NOMOR 3

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int rahasia, tebakan;

    srand(time(NULL));
    rahasia = rand() % 20 + 1;   

    printf("=== Permainan Tebak Angka (1-20) ===\n");
    printf("Masukkan 99 untuk menyerah.\n");

    while (1) {
        printf("Tebakan Anda: ");
        scanf("%d", &tebakan);

        if (tebakan == 99) {
            printf("Permainan disudahi. Angkanya adalah %d\n", rahasia);
            break;
        } else if (tebakan == rahasia) {
            printf("Cocok! Anda berhasil menebak.\n");
            break;
        } else if (tebakan < rahasia) {
            printf("Lebih tinggi\n");
        } else {
            printf("Lebih rendah\n");
        }
    }

    return 0;
}

NOMOR 4

#include <stdio.h>

int main() {
    int n, i, j;
    char c1, c2;

    printf("Masukkan n: ");
    scanf("%d", &n);
    printf("Karakter baris ganjil (c1): ");
    scanf(" %c", &c1);
    printf("Karakter baris genap (c2): ");
    scanf(" %c", &c2);

    for (i = 1; i <= n; i++) {
        for (j = 1; j <= n; j++) {
            if (i % 2 == 1)
                printf("%c", c1);
            else
                printf("%c", c2);

            if (j < n) printf(" ");
        }
        printf("\n");
    }

    return 0;
}

nomor 5

#include <stdio.h>

#define MAKS_PRODUK 3
#define MAKS_TOTAL  50000

int main() {
    const char *nama[5] = {"Roti", "Susu", "Kopi", "Jus", "Cokelat"};
    int harga[5] = {15000, 16000, 16000, 15000, 19000};

    int dipilih[MAKS_PRODUK];
    int jumlah = 0, total = 0;
    int pilihan, i;

    printf("VENDING MACHINE\n");
    for (i = 0; i < 5; i++) {
        printf("%d. %-8s Rp%d\n", i + 1, nama[i], harga[i]);
    }
    printf("6. Selesai\n");
    printf("(Maks. %d produk atau Rp%d)\n\n", MAKS_PRODUK, MAKS_TOTAL);

    while (jumlah < MAKS_PRODUK && total < MAKS_TOTAL) {
        printf("Pilih (1-6) [dipilih: %d, total: Rp%d]: ", jumlah, total);
        scanf("%d", &pilihan);

        if (pilihan == 6) {
            break;
        }

        if (pilihan < 1 || pilihan > 5) {
            printf("Pilihan tidak valid!\n");
            continue;
        }

        if (total + harga[pilihan - 1] > MAKS_TOTAL) {
            printf("Melebihi Rp%d, pilih produk lain atau tekan 6.\n", MAKS_TOTAL);
            continue;
        }

        dipilih[jumlah] = pilihan - 1;
        jumlah++;
        total += harga[pilihan - 1];
        printf("%s ditambahkan.\n", nama[pilihan - 1]);
    }

    printf("\n=== PRODUK YANG DIPILIH ===\n");
    if (jumlah == 0) {
        printf("Tidak ada produk dipilih.\n");
    } else {
        for (i = 0; i < jumlah; i++) {
            printf("%d. %-8s Rp%d\n", i + 1, nama[dipilih[i]], harga[dipilih[i]]);
        }
    }
    printf("Total tagihan: Rp%d\n", total);

    return 0;
}