#include <stdio.h>

char nama[5][20];
int stok[5] = {0, 0, 0, 0, 0};

void isiNama()
{
    int i;
    for (i = 0; i < 5; i++)
    {
        printf("Nama barang rak %d: ", i + 1);
        scanf("%s", nama[i]);
    }
}

void lihatStok()
{
    int i;
    for (i = 0; i < 5; i++)
    {
        printf("Rak %d | %-15s | %d\n", i + 1, nama[i], stok[i]);
    }
}

void ubahStok()
{
    int rak, jumlah;

    lihatStok();
    printf("Pilih rak (1-5): ");
    scanf("%d", &rak);
    if (rak < 1 || rak > 5)
    {
        printf("Rak tidak ada\n");
        return;
    }

    printf("Jumlah (isi minus untuk mengurangi): ");
    scanf("%d", &jumlah);

    if (stok[rak - 1] + jumlah < 0)
    {
        printf("Gagal, stok tidak boleh negatif\n");
    }
    else
    {
        stok[rak - 1] = stok[rak - 1] + jumlah;
        printf("Stok sekarang: %d\n", stok[rak - 1]);
    }
}

void histogram()
{
    int i, j;
    for (i = 0; i < 5; i++)
    {
        printf("%-15s | ", nama[i]);
        for (j = 0; j < stok[i]; j++)
        {
            printf(".");
        }
        printf(" %d\n", stok[i]);
    }
}

int main()
{
    int pilihan;

    isiNama();

    do
    {
        printf("\n1. Lihat stok\n2. Ubah stok\n3. Histogram\n0. Keluar\nPilihan: ");
        scanf("%d", &pilihan);

        if (pilihan == 1)
            lihatStok();
        else if (pilihan == 2)
            ubahStok();
        else if (pilihan == 3)
            histogram();
    } while (pilihan != 0);

    return 0;
}