#include <stdio.h>

int main() {
    int jam_kerja;
    float upah_per_jam, upah_harian, total_upah = 0;

    printf("Masukkan upah per jam: ");
    scanf("%f", &upah_per_jam);

    for (int i = 1; i <= 6; i++) {
        printf("Masukkan jam kerja hari ke-%d: ", i);
        scanf("%d", &jam_kerja);

        if (jam_kerja <= 8) {
            upah_harian = jam_kerja * upah_per_jam;
        } else {
            // Jam di atas 8 jam dihitung lembur (1.5x)
            upah_harian = (8 * upah_per_jam) + ((jam_kerja - 8) * (upah_per_jam * 1.5));
        }

        total_upah += upah_harian;
    }

    printf("\nTotal upah pegawai selama 1 minggu adalah: %.2f\n", total_upah);

    return 0;
}