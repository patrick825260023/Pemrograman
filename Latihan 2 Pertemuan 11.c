// Latihan 2 Patrick Kennedy
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define JML_MAKANAN 5
#define JML_MINUMAN 3
#define JML_MENU    (JML_MAKANAN + JML_MINUMAN)
#define JML_PEGAWAI 2

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

struct Menu    daftarMenu[JML_MENU];
struct Pegawai daftarPegawai[JML_PEGAWAI];

void bacaString(const char *prompt, char *hasil, int ukuran) {
    printf("%s", prompt);
    if (fgets(hasil, ukuran, stdin) != NULL) {
        hasil[strcspn(hasil, "\n")] = '\0';
    }
}

int bacaInt(const char *prompt) {
    char buf[32];
    printf("%s", prompt);
    if (fgets(buf, sizeof(buf), stdin) == NULL) return 0;
    return atoi(buf);
}

void isiMenu(int i, int id, const char *nama, const char *jenis, int harga, int stok) {
    daftarMenu[i].id = id;
    strcpy(daftarMenu[i].nama, nama);
    strcpy(daftarMenu[i].jenis, jenis);
    daftarMenu[i].harga = harga;
    daftarMenu[i].stok = stok;
}

void isiPegawai(int i, int id, const char *nama, const char *jabatan, int gaji) {
    daftarPegawai[i].id = id;
    strcpy(daftarPegawai[i].nama, nama);
    strcpy(daftarPegawai[i].jabatan, jabatan);
    daftarPegawai[i].gaji = gaji;
}

void inisialisasiData(void) {
    isiMenu(0, 1, "Nasi Goreng", "Makanan", 25000, 20);
    isiMenu(1, 2, "Mie Goreng",  "Makanan", 23000, 15);
    isiMenu(2, 3, "Ayam Bakar",  "Makanan", 30000, 10);
    isiMenu(3, 4, "Sate Ayam",   "Makanan", 28000, 12);
    isiMenu(4, 5, "Soto Ayam",   "Makanan", 22000, 18);

    isiMenu(5, 6, "Es Teh",      "Minuman", 5000,  50);
    isiMenu(6, 7, "Es Jeruk",    "Minuman", 8000,  40);
    isiMenu(7, 8, "Kopi Hitam",  "Minuman", 10000, 30);

    isiPegawai(0, 1, "Budi Santoso", "Koki",  4500000);
    isiPegawai(1, 2, "Siti Aminah",  "Kasir", 4000000);
}

void tampilMenu(void) {
    int i;
    printf("\n================= DAFTAR MENU =================\n");
    printf("%-4s %-15s %-10s %-10s %-5s\n", "ID", "Nama", "Jenis", "Harga", "Stok");
    printf("-----------------------------------------------\n");
    for (i = 0; i < JML_MENU; i++) {
        printf("%-4d %-15s %-10s Rp%-8d %-5d\n",
               daftarMenu[i].id, daftarMenu[i].nama, daftarMenu[i].jenis,
               daftarMenu[i].harga, daftarMenu[i].stok);
    }
    printf("===============================================\n");
}

void tampilPegawai(void) {
    int i;
    printf("\n================ DAFTAR PEGAWAI ================\n");
    printf("%-4s %-18s %-10s %-12s\n", "ID", "Nama", "Jabatan", "Gaji");
    printf("------------------------------------------------\n");
    for (i = 0; i < JML_PEGAWAI; i++) {
        printf("%-4d %-18s %-10s Rp%-10d\n",
               daftarPegawai[i].id, daftarPegawai[i].nama,
               daftarPegawai[i].jabatan, daftarPegawai[i].gaji);
    }
    printf("================================================\n");
}

void ubahMenu(void) {
    int id, i, idx = -1;
    char buf[50];

    tampilMenu();
    id = bacaInt("Masukkan ID menu yang akan diubah: ");

    for (i = 0; i < JML_MENU; i++) {
        if (daftarMenu[i].id == id) { idx = i; break; }
    }
    if (idx == -1) {
        printf("Menu dengan ID %d tidak ditemukan.\n", id);
        return;
    }

    printf("\nMengubah menu: %s (kosongkan / isi 0 untuk tidak mengubah)\n",
           daftarMenu[idx].nama);

    bacaString("Nama baru  : ", buf, sizeof(buf));
    if (strlen(buf) > 0) strcpy(daftarMenu[idx].nama, buf);

    i = bacaInt("Harga baru : ");
    if (i > 0) daftarMenu[idx].harga = i;

    i = bacaInt("Stok baru  : ");
    if (i > 0) daftarMenu[idx].stok = i;

    printf("Data menu berhasil diubah.\n");
}

void ubahPegawai(void) {
    int id, i, idx = -1;
    char buf[50];

    tampilPegawai();
    id = bacaInt("Masukkan ID pegawai yang akan diubah: ");

    for (i = 0; i < JML_PEGAWAI; i++) {
        if (daftarPegawai[i].id == id) { idx = i; break; }
    }
    if (idx == -1) {
        printf("Pegawai dengan ID %d tidak ditemukan.\n", id);
        return;
    }

    printf("\nMengubah pegawai: %s (kosongkan / isi 0 untuk tidak mengubah)\n",
           daftarPegawai[idx].nama);

    bacaString("Nama baru    : ", buf, sizeof(buf));
    if (strlen(buf) > 0) strcpy(daftarPegawai[idx].nama, buf);

    bacaString("Jabatan baru : ", buf, sizeof(buf));
    if (strlen(buf) > 0) strncpy(daftarPegawai[idx].jabatan, buf,
                                 sizeof(daftarPegawai[idx].jabatan) - 1);

    i = bacaInt("Gaji baru    : ");
    if (i > 0) daftarPegawai[idx].gaji = i;

    printf("Data pegawai berhasil diubah.\n");
}

int main(void) {
    int pilihan;

    inisialisasiData();

    do {
        printf("\n=========== APLIKASI RESTORAN ===========\n");
        printf("1. Tampilkan data menu\n");
        printf("2. Ubah data menu\n");
        printf("3. Tampilkan data pegawai\n");
        printf("4. Ubah data pegawai\n");
        printf("0. Keluar\n");
        printf("=========================================\n");
        pilihan = bacaInt("Pilih menu: ");

        switch (pilihan) {
            case 1: tampilMenu();    break;
            case 2: ubahMenu();      break;
            case 3: tampilPegawai(); break;
            case 4: ubahPegawai();   break;
            case 0: printf("Terima kasih. Program selesai.\n"); break;
            default: printf("Pilihan tidak valid!\n");
        }
    } while (pilihan != 0);

    return 0;
}