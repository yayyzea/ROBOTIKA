#include <stdio.h>

int main() {

    char nama[] = "Zahra Azkiya Rahmani",
         nim[] = "251524124",
         jurusan[] = "Teknik Komputer dan Informatika",
         prodi[] = "Teknik Informatika",
         asal_sekolah[] = "SMAN 10 Bandung",
         hobi[] = "Game, Gambar, Baca",
         desc[] = "Karena sejalan dengan jurusan, ingin lomba, ngoding, dan implementasi ke robot.";

    printf(
        " Nama          : %s\n"
		" NIM           : %s\n"
        " Jurusan       : %s\n"
        " Prodi         : %s\n"
        " Asal Sekolah  : %s\n"
        " Hobi          : %s\n"
        " Deskripsi     : %s\n",

        nama,
        nim,
        jurusan,
        prodi,
        asal_sekolah,
        hobi,
        desc
    );

    return 0;
}