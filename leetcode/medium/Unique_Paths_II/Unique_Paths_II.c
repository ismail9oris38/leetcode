#include <stdio.h>
#include <stdlib.h>

// Engellerin olduğu grid üzerinde benzersiz yolları bulan fonksiyonun prototipi
int uniquePathsWithObstacles(int** obstacleGrid, int obstacleGridSize, int* obstacleGridColSize);

int main() {
    int i, j;
    int rows = 4, cols = 4;

    // 2D array için dinamik bellek tahsisi
    int **obstacleGrid = (int **)malloc(rows * sizeof(int *));
    for (i = 0; i < rows; i++) {
        obstacleGrid[i] = (int *)malloc(cols * sizeof(int));
    }

    // Engel haritasını tanımlıyoruz (0: Yol açık, 1: Engel var)
    int data[4][4] = {
        {0, 0, 0, 1},
        {0, 1, 0, 0},
        {0, 0, 0, 1},
        {0, 0, 0, 0}
    };

    // Sabit diziden dinamik diziye kopyalama işlemi
    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            obstacleGrid[i][j] = data[i][j];
        }
    }

    // Fonksiyonu çağır ve sonucu ekrana yazdır
    printf("Benzersiz yolların sayısı: %d\n", uniquePathsWithObstacles(obstacleGrid, rows, &cols));

    // Dinamik bellek tahsisini serbest bırak
    for (i = 0; i < rows; i++) {
        free(obstacleGrid[i]);
    }
    free(obstacleGrid);

    return 0;
}

// Engellerle dolu bir grid içinde benzersiz yolları bulan fonksiyon
int uniquePathsWithObstacles(int** obstacleGrid, int obstacleGridSize, int* obstacleGridColSize) {
    int i, j;
    
    // DP tablosu
    int **dp = (int**)malloc(obstacleGridSize * sizeof(int*));
    for (i = 0; i < obstacleGridSize; i++) {
        dp[i] = (int*)malloc(obstacleGridColSize[i] * sizeof(int));
    }

    // Eğer başlangıç noktası engelse, hiç yol yok
    if (obstacleGrid[0][0] == 1) return 0;
    
    // İlk hücreye 1 koy
    dp[0][0] = 1;

    // İlk satırı doldur
    for (j = 1; j < obstacleGridColSize[0]; j++) {
        if (obstacleGrid[0][j] == 1) dp[0][j] = 0;  // Engel varsa 0
        else dp[0][j] = dp[0][j - 1]; // Soldan gelen yol
    }

    // İlk sütunu doldur
    for (i = 1; i < obstacleGridSize; i++) {
        if (obstacleGrid[i][0] == 1) dp[i][0] = 0;  // Engel varsa 0
        else dp[i][0] = dp[i - 1][0]; // Yukarıdan gelen yol
    }

    // DP tablosunu doldur
    for (i = 1; i < obstacleGridSize; i++) {
        for (j = 1; j < obstacleGridColSize[i]; j++) {
            if (obstacleGrid[i][j] == 1) dp[i][j] = 0;  // Engel varsa 0
            else dp[i][j] = dp[i - 1][j] + dp[i][j - 1]; // Yukarıdan ve soldan gelen yolları topla
        }
    }

    int result = dp[obstacleGridSize - 1][obstacleGridColSize[0] - 1];

    // Belleği temizle
    for (i = 0; i < obstacleGridSize; i++) {
        free(dp[i]);
    }
    free(dp);

    return result;
}