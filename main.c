
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_PERALATAN 5
#define MAX_TRANSAKSI 10

char namaAlat[MAX_PERALATAN][40] = {
    "Tenda Kapasitas 4 Orang",
    "Sleeping Bag",
    "Kompor Portable",
    "Matras Camping",
    "Lampu Camping"
};

int harga[MAX_PERALATAN] = {
    50000, 15000, 20000, 10000, 12000
};

char nama[MAX_TRANSAKSI][100];
int noAlat[MAX_TRANSAKSI];
int jumlah[MAX_TRANSAKSI];
int hari[MAX_TRANSAKSI];
long long total[MAX_TRANSAKSI];
int banyakTransaksi = 0;

int bacaAngka(char pesan[], int min, int max) {
    char baris[100], sisa;
    int angka;

    while (1) {
        printf("%s", pesan);

        if (fgets(baris, sizeof(baris), stdin) != NULL &&
            sscanf(baris, " %d %c", &angka, &sisa) == 1 &&
            angka >= min && angka <= max) {
            return angka;
        }

        printf("Input tidak valid. Coba lagi.\n");
    }
}

void daftarAlat(void) {
    int i;

    printf("\n========== DAFTAR PERALATAN ==========\n");

    for (i = 0; i < MAX_PERALATAN; i++) {
        printf("%d. %-28s Rp%d/hari\n",
               i + 1, namaAlat[i], harga[i]);
    }
}

int hitungDiskon(int lama) {
    if (lama >= 5)
        return 15;
    else if (lama >= 3)
        return 10;
    else
        return 0;
}

int sewaAlat(void) {
    char namaPenyewa[100];
    char baris[100];
    char pilihan;
    int alat, unit, lama, diskon;
    long long subtotal, potongan, bayar;

    if (banyakTransaksi >= MAX_TRANSAKSI) {
        printf("Kapasitas transaksi sudah penuh!\n");
        return 1;
    }

    printf("Nama penyewa: ");

    if (fgets(namaPenyewa, sizeof(namaPenyewa), stdin) == NULL)
        return 1;

    namaPenyewa[strcspn(namaPenyewa, "\n")] = '\0';

    if (namaPenyewa[0] == '\0') {
        printf("Nama tidak boleh kosong.\n");
        return 1;
    }

    daftarAlat();

    alat = bacaAngka("Pilih alat (1-5): ", 1, 5);
    unit = bacaAngka("Jumlah unit: ", 1, 1000000);
    lama = bacaAngka("Lama sewa (hari): ", 1, 1000000);

    subtotal = (long long)harga[alat - 1] * unit * lama;
    diskon = hitungDiskon(lama);
    potongan = subtotal * diskon / 100;
    bayar = subtotal - potongan;

    printf("\n========== STRUK PENYEWAAN ==========\n");
    printf("Nama penyewa  : %s\n", namaPenyewa);
    printf("Peralatan     : %s\n", namaAlat[alat - 1]);
    printf("Harga per hari: Rp%d\n", harga[alat - 1]);
    printf("Jumlah unit   : %d\n", unit);
    printf("Lama sewa     : %d hari\n", lama);
    printf("Subtotal      : Rp%lld\n", subtotal);
    printf("Diskon        : %d%% (Rp%lld)\n",
           diskon, potongan);
    printf("TOTAL BAYAR   : Rp%lld\n", bayar);
    printf("=====================================\n");

    strcpy(nama[banyakTransaksi], namaPenyewa);
    noAlat[banyakTransaksi] = alat - 1;
    jumlah[banyakTransaksi] = unit;
    hari[banyakTransaksi] = lama;
    total[banyakTransaksi] = bayar;
    banyakTransaksi++;

    while (1) {
        printf("Kembali ke menu utama? (Y/T): ");

        if (fgets(baris, sizeof(baris), stdin) == NULL)
            return 0;

        pilihan = (char)toupper((unsigned char)baris[0]);

        if (pilihan == 'Y')
            return 1;

        if (pilihan == 'T') {
            printf("Terima kasih telah menggunakan Adventure Camp!\n");
            return 0;
        }

        printf("Masukkan Y atau T.\n");
    }
}

void riwayatTransaksi(void) {
    int i;
    long long pendapatan = 0;

    if (banyakTransaksi == 0) {
        printf("Belum ada transaksi penyewaan.\n");
        return;
    }

    printf("\n========== RIWAYAT TRANSAKSI ==========\n");

    for (i = 0; i < banyakTransaksi; i++) {
        printf("%d. %s | %s | %d unit | %d hari | Rp%lld\n",
               i + 1,
               nama[i],
               namaAlat[noAlat[i]],
               jumlah[i],
               hari[i],
               total[i]);

        pendapatan += total[i];
    }

    printf("---------------------------------------\n");
    printf("Jumlah transaksi : %d\n", banyakTransaksi);
    printf("Total pendapatan : Rp%lld\n", pendapatan);
}

int main(void) {
    int menu;
    int aktif = 1;

    while (aktif) {
        printf("\n====================================\n");
        printf("          ADVENTURE CAMP\n");
        printf("     SISTEM PENYEWAAN PERALATAN\n");
        printf("====================================\n");
        printf("1. Lihat Daftar Peralatan\n");
        printf("2. Sewa Peralatan\n");
        printf("3. Lihat Riwayat Transaksi\n");
        printf("4. Keluar\n");
        printf("====================================\n");

        menu = bacaAngka("Pilih menu (1-4): ", 1, 4);

        switch (menu) {
            case 1:
                daftarAlat();
                break;

            case 2:
                aktif = sewaAlat();
                break;

            case 3:
                riwayatTransaksi();
                break;

            case 4:
                aktif = 0;
                printf("Terima kasih telah menggunakan Adventure Camp!\n");
                break;
        }
    }

    return 0;
}
