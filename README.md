# Adventure Camp – Sistem Penyewaan Peralatan Camping
## Identitas
- Nama: M. Raihan Setyawan
- NIM: C 2583207048
- Proyek: Adventure Camp
## Deskripsi
Adventure Camp adalah program penyewaan peralatan camping berbasis terminal yang dibuat menggunakan bahasa pemrograman C. Program ini membantu pengguna melihat daftar peralatan, melakukan transaksi penyewaan, menghitung biaya sewa dan diskon secara otomatis, menampilkan struk pembayaran, serta melihat riwayat transaksi dan total pendapatan.
## Fitur Program
- Melihat daftar peralatan camping beserta harga sewanya.
- Melakukan transaksi penyewaan berdasarkan nama penyewa, jenis peralatan, jumlah unit, dan lama sewa.
- Menghitung subtotal, diskon, dan total pembayaran secara otomatis.
- Menampilkan struk penyewaan.
- Menyimpan dan menampilkan riwayat transaksi.
- Menghitung jumlah transaksi dan total pendapatan.
- Kembali ke menu utama atau keluar dari program.
## Daftar Peralatan
- Tenda Kapasitas 4 Orang — Rp50.000/hari
- Sleeping Bag — Rp15.000/hari
- Kompor Portable — Rp20.000/hari
- Matras Camping — Rp10.000/hari
- Lampu Camping — Rp12.000/hari
## Perhitungan Biaya
Diskon ditentukan berdasarkan lama penyewaan:
- 1–2 hari: 0%
- 3–4 hari: 10%
- 5 hari atau lebih: 15%
## Rumus:
- Subtotal = Harga per Hari × Jumlah Unit × Lama Sewa
- Diskon = Persentase Diskon × Subtotal
- Total Bayar = Subtotal − Diskon
## Contoh Transaksi dari Hasil Pengujian
- Nama penyewa: raihan
- Peralatan: Kompor Portable
- Harga per hari: Rp20.000
- Jumlah unit: 7
- Lama sewa: 8 hari
- Subtotal: Rp1.120.000
- Diskon: Rp168.000 (15%)
- Total bayar: Rp952.000
## Batas Penyimpanan
Program dapat menyimpan maksimal 10 transaksi selama program berjalan. Data transaksi digunakan untuk menampilkan riwayat penyewaan, jumlah transaksi, dan total pendapatan. Data akan hilang ketika program ditutup.
## Screenshot Program
1. Tampilan Menu Utama dan Daftar Peralatan
<img width="753" height="482" alt="raihan1" src="https://github.com/user-attachments/assets/b7b46e33-87ac-44a8-84a1-48bd9a75e3ad" />


2. Tampilan Struk Penyewaan
<img width="960" height="507" alt="raihan2" src="https://github.com/user-attachments/assets/b187d160-7cf6-4b71-b509-d9872dff4128" />

3. Tampilan Riwayat Transaksi
   <img width="960" height="507" alt="raihan3" src="https://github.com/user-attachments/assets/c579d097-ca8f-4264-9995-4555dee1eb2b" />
