#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "osint.h"

/* -- Helper: tampilkan info detail node aktif -- */
static void showDetail(void) {
    LeafNode *lf   = (LeafNode *)current;
    int       isLf = (current->fs == NULL && lf->desc[0] != '\0');

    if (!isLf) return;

    printf("\n  Deskripsi : %s\n", lf->desc);
    printf("  URL       : %s\n",  lf->url);
    printf("  Tags      : ");
    for (int i = 0; i < lf->tagCount; i++) {
        printf("[%s]", lf->tags[i]);
        if (i < lf->tagCount - 1) printf(" ");
    }
    printf("\n");
}

/* -- Menu navigasi -- */
static void menuNavigasi(void) {
    int pilih;
    printf("\n  1. Masuk ke node anak\n");
    printf("  2. Kembali ke parent\n");
    printf("  0. Batal\n");
    printf("Pilih: ");
    scanf("%d", &pilih);
    getchar();

    switch (pilih) {
        case 1: navigateIn();   break;
        case 2: navigateBack(); break;
        default: break;
    }
}

/* -- Menu delete dengan konfirmasi -- */
static void menuDelete(void) {
    if (current == root) {
        printf("  Tidak bisa menghapus root.\n");
        return;
    }

    printf("\n  Hapus '%s' beserta semua isinya? (y/n): ", current->info);
    char konfirm;
    scanf(" %c", &konfirm);
    getchar();

    if (konfirm != 'y' && konfirm != 'Y') {
        printf("  Dibatalkan.\n");
        return;
    }

    Node *parent = current->parent;

    /* putus koneksi dari parent */
    if (parent->fs == current) {
        parent->fs = current->nb;
    } else {
        Node *sib = parent->fs;
        while (sib != NULL && sib->nb != current)
            sib = sib->nb;
        if (sib != NULL)
            sib->nb = current->nb;
    }

    /* simpan nb sebelum dihapus, lalu delete rekursif */
    current->nb = NULL;
    deleteNode(current);
    current = parent;

    printf("  Node berhasil dihapus.\n");
}

/* -- Menu search -- */
static void menuSearch(void) {
    char keyword[MAX_INFO];
    printf("\nCari keyword: ");
    fgets(keyword, MAX_INFO, stdin);
    keyword[strcspn(keyword, "\n")] = '\0';

    printf("\nHasil pencarian '%s':\n", keyword);
    searchNode(root, keyword);
}

/* ----------------------------------------
   Main
   ---------------------------------------- */

int main(void) {
    initData();

    int pilih;

    do {
        readCurrent();
        showDetail();

        printf("\n-- Menu --------------------------\n");
        printf("  1. Navigasi\n");
        printf("  2. Tambah node\n");
        printf("  3. Edit node\n");
        printf("  4. Hapus node\n");
        printf("  5. Tampilkan seluruh tree\n");
        printf("  6. Cari node\n");
        printf("  0. Keluar\n");
        printf("----------------------------------\n");
        printf("Pilih: ");
        scanf("%d", &pilih);
        getchar();

        switch (pilih) {
            case 1: menuNavigasi();              break;
            case 2: addNode();                   break;
            case 3: updateNode();                break;
            case 4: menuDelete();                break;
            case 5: displayTree(root, 0);        break;
            case 6: menuSearch();                break;
            case 0: printf("  Sampai jumpa!\n"); break;
            default: printf("  Pilihan tidak valid.\n");
        }

    } while (pilih != 0);

    return 0;
}