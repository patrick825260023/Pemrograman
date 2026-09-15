#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int skor = 0;
    int salah = 0;
    int max_angka, poin_soal;
    
    // Biar angkanya bener-bener acak tiap kali dijalankan
    srand(time(NULL));
    
    printf("===========================================\n");
    printf("         GAME MATEMATIKA SEDERHANA         \n");
    printf("===========================================\n");
    printf("Aturan main:\n");
    printf("- Total ada 30 soal.\n");
    printf("- Kalau salah 3 kali, game langsung game over.\n");
    printf("- Soal 1-10  : Angka max 10, poin +5\n");
    printf("- Soal 11-20 : Angka max 30, poin +10\n");
    printf("- Soal 21-30 : Angka max 60, poin +15\n");
    printf("===========================================\n\n");
    
    for (int i = 1; i <= 30; i++) {
        // Atur level & batas angka berdasarkan nomor soal
        int level;
        if (i <= 10) {
            level = 1;
            max_angka = 10;
            poin_soal = 5;
        } else if (i <= 20) {
            level = 2;
            max_angka = 30;
            poin_soal = 10;
        } else {
            level = 3;
            max_angka = 60;
            poin_soal = 15;
        }
        
        // Random operator: 0 buat +, 1 buat -, 2 buat *, 3 buat /
        int pilih_op = rand() % 4;
        int a, b, kunci_jawaban;
        char simbol_op;
        
        if (pilih_op == 0) {
            simbol_op = '+';
            a = (rand() % max_angka) + 1;
            b = (rand() % max_angka) + 1;
            kunci_jawaban = a + b;
        } else if (pilih_op == 1) {
            simbol_op = '-';
            a = (rand() % max_angka) + 1;
            b = (rand() % max_angka) + 1;
            // Dibalik biar ga ada minus-minusan di layar
            if (a < b) {
                int temp = a;
                a = b;
                b = temp;
            }
            kunci_jawaban = a - b;
        } else if (pilih_op == 2) {
            simbol_op = '*';
            // Kali dibatesin dikit biar angkanya gak kepanjangan
            int batas_kali = (max_angka > 15) ? 15 : max_angka;
            a = (rand() % batas_kali) + 1;
            b = (rand() % batas_kali) + 1;
            kunci_jawaban = a * b;
        } else {
            simbol_op = '/';
            // Biar hasilnya bulat dan ga pusing mikirin koma
            b = (rand() % 9) + 1;
            int pengali = (rand() % (max_angka / b > 0 ? max_angka / b : 5)) + 1;
            a = b * pengali;
            kunci_jawaban = a / b;
        }
        
        // Lempar soal ke user
        int jawab_user;
        printf("Soal %d [Level %d] : Berapa %d %c %d ?\n", i, level, a, simbol_op, b);
        printf("Jawaban kamu      : ");
        scanf("%d", &jawab_user);
        
        // Cek bener atau salah
        if (jawab_user == kunci_jawaban) {
            skor += poin_soal;
            printf("Mantap, bener! (+%d poin) | Total Skor: %d\n\n", poin_soal, skor);
        } else {
            salah++;
            printf("Waduh, salah! Jawaban yang bener tuh %d.\n", kunci_jawaban);
            printf("Sisa kesempatan salah: %d/3\n\n", 3 - salah);
            
            // Kalau salah udah 3 kali, stop bro
            if (salah >= 3) {
                printf("===========================================\n");
                printf("GAME OVER! Kesempatan kamu udah habis (3x salah).\n");
                break;
            }
        }
    }
    
    // Rekap akhir game
    printf("===========================================\n");
    printf("               HASIL AKHIR                 \n");
    printf("===========================================\n");
    printf("Total Skor Kamu : %d\n", skor);
    if (salah < 3) {
        printf("Status          : KEREN, Lolos sampai habis!\n");
    } else {
        printf("Status          : Kurang beruntung, coba lagi ya.\n");
    }
    printf("===========================================\n");
    
    return 0;
}