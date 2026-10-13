#include <stdio.h>
#include <string.h>

struct Ladang {
    char jenis[30];
    float nilai_tanggungan;
    float luas;
    float biaya;
};

void hitung_asuransi(struct Ladang *l) {
    float standar = 0.035 * l->nilai_tanggungan * l->luas;
    
    if (strcmp(l->jenis, "kedelai") == 0 || strcmp(l->jenis, "kentang") == 0 || 
        strcmp(l->jenis, "bawang merah") == 0 || strcmp(l->jenis, "cabai") == 0) {
        l->biaya = 2.0 * standar;
    } else if (strcmp(l->jenis, "padi") == 0 || strcmp(l->jenis, "singkong") == 0 || 
               strcmp(l->jenis, "jagung") == 0) {
        l->biaya = 1.5 * standar;
    } else {
        l->biaya = standar;
    }
}

void cetak_slip(char *nama, struct Ladang ladang[], int jumlah) {
    float total = 0;
    printf("          SLIP PEMBAYARAN ASURANSI      \n");
    printf("Nama Petani : %s\n", nama);
    for(int i = 0; i < jumlah; i++) {
        printf("Jenis Ladang %d : %s\n", i + 1, ladang[i].jenis);
        printf("Luas          : %.2f hektar\n", ladang[i].luas);
        printf("Biaya Asuransi: Rp %.2f\n", ladang[i].biaya);
        total += ladang[i].biaya;
    }
    printf("TOTAL ASURANSI YANG DIBAYAR: Rp %.2f\n", total);
}

int main() {
    char nama_petani[50];
    int jumlah_ladang;
    struct Ladang daftar_ladang[3];

    printf("Masukkan nama petani: ");
    scanf(" %[^\n]", nama_petani);

    printf("Masukkan jumlah jenis ladang (maksimal 3): ");
    scanf("%d", &jumlah_ladang);

    if (jumlah_ladang > 3) {
        jumlah_ladang = 3;
    }

    for(int i = 0; i < jumlah_ladang; i++) {
        printf("\nData ladang ke-%d:\n", i + 1);
        printf("Jenis ladang (padi/jagung/singkong/kedelai/kentang/bawang merah/cabai): ");
        scanf(" %[^\n]", daftar_ladang[i].jenis);
        
        printf("Nilai tanggungan per hektar (Rp): ");
        scanf("%f", &daftar_ladang[i].nilai_tanggungan);
        
        printf("Luas tanah (hektar): ");
        scanf("%f", &daftar_ladang[i].luas);

        hitung_asuransi(&daftar_ladang[i]);
    }

    cetak_slip(nama_petani, daftar_ladang, jumlah_ladang);

    return 0;
}