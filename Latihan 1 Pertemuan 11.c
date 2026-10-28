//Latihan 1 Patrick Kennedy
#include <stdio.h>
#include <string.h>

struct Menu {
    int  id;
    char nama[50];
    char jenis[10];
    int  harga;
    int  stok;
};

struct Pegawai {
    int  id;
    char nama[50];
    char jabatan[30];
    int  gaji;
};

int main(void) {
    struct Menu m;
    struct Pegawai p;

    m.id = 1;
    strcpy(m.nama, "Nasi Goreng");
    strcpy(m.jenis, "Makanan");
    m.harga = 25000;
    m.stok = 20;

    p.id = 1;
    strcpy(p.nama, "Budi Santoso");
    strcpy(p.jabatan, "Koki");
    p.gaji = 4500000;

    printf("=== Data Menu ===\n");
    printf("ID    : %d\n", m.id);
    printf("Nama  : %s\n", m.nama);
    printf("Jenis : %s\n", m.jenis);
    printf("Harga : Rp%d\n", m.harga);
    printf("Stok  : %d\n", m.stok);

    printf("\n=== Data Pegawai ===\n");
    printf("ID      : %d\n", p.id);
    printf("Nama    : %s\n", p.nama);
    printf("Jabatan : %s\n", p.jabatan);
    printf("Gaji    : Rp%d\n", p.gaji);

    getchar();
    return 0;
}