#include <stdio.h>
#include <stdlib.h>

void koboImaginaryChess(int i, int j, int size, int *chessBoard) {
    // Array 2D untuk menyimpan papan catur
    int board[size][size];

    // Inisialisasi semua elemen papan catur dengan nilai 0
    for (int row = 0; row < size; row++) {
        for (int col = 0; col < size; col++) {
            board[row][col] = 0;
        }
    }

    // Menentukan posisi yang dapat dicapai oleh bidak kuda
    int moves[8][2] = {{-2, -1}, {-2, 1}, {-1, -2}, {-1, 2},
                       {1, -2}, {1, 2}, {2, -1}, {2, 1}};

    // Mengupdate posisi bidak kuda dan menandai posisi yang dapat dicapai
    for (int m = 0; m < 8; m++) {
        int new_i = i + moves[m][0];
        int new_j = j + moves[m][1];
        
        // Memeriksa apakah posisi baru valid
        if (new_i >= 0 && new_i < size && new_j >= 0 && new_j < size) {
            board[new_i][new_j] = 1;
        }
    }

    // Menampilkan papan catur setelah update
    for (int row = 0; row < size; row++) {
        for (int col = 0; col < size; col++) {
            printf("%d ", board[row][col]);
        }
        printf("\n");
    }
}

int main() {
    int i, j;
    printf("Masukkan nilai i dan j dipisahkan spasi: ");
    scanf("%d %d", &i, &j);

    // Ukuran papan catur
    int size = 8;

    // Memanggil fungsi koboImaginaryChess
    koboImaginaryChess(i, j, size, NULL);

    return 0;
}