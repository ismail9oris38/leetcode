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
        {0, 1, 0, 1},
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
    int i, j, line = 1, tmp = 1, result = 0, tmp2 = 0;
    int **lines; // Yolları takip eden diziyi oluştur

    // İlk adımı başlatmak için 1 satırlık bellek ayır
    lines = (int**)malloc(sizeof(int*) * line);
    for (i = 0; i < line; i++) {
        lines[i] = (int*)malloc(sizeof(int) * 2);
    }

    // Başlangıç noktasını (0,0) olarak ayarla
    lines[0][0] = 0;
    lines[0][1] = 0;

    // Eğer başlangıç noktası engelli ise, 0 dönüş yap (hiçbir yol yok)
    if (obstacleGrid[0][0] == 1) {
        return 0;
    }

    // Tüm yolları keşfetmek için döngü başlat
    while (tmp) {
        tmp = 0; // Hareket olup olmadığını kontrol etmek için flag

        for (i = 0; i < line; i++) {
            tmp2 = 0; // Yana hareket ettik mi kontrolü

            // Sağ tarafa hareket kontrolü
            if (lines[i][1] + 1 < *obstacleGridColSize && obstacleGrid[lines[i][0]][lines[i][1] + 1] == 0) {
                lines[i][1] += 1; // Yana git
                tmp = 1; // Hareket yapıldı
                tmp2 = 1;
            }

            // Aşağı hareket kontrolü (eğer sağa gidildiyse yeni satır ekleyerek kontrol)
            if (lines[i][0] + 1 < obstacleGridSize && obstacleGrid[lines[i][0] + 1][lines[i][1] - tmp2] == 0) {
                if (tmp2) {
                    // Yeni yol keşfedildi, yeni satır ekleyerek yolu genişlet
                    line++;
                    int **temp = (int**)realloc(lines, sizeof(int*) * line);
                    if (temp != NULL) {
                        lines = temp;
                    } else {
                        printf("Hafıza atama hatası.\n");
                        return -1;
                    }
                    
                    // Yeni yolu kaydet
                    lines[line - 1] = (int*)malloc(sizeof(int) * 2);
                    if (lines[line - 1] == NULL) {
                        printf("Hafıza atama hatası.\n");
                        return -1;
                    }
                    lines[line - 1][0] = lines[i][0] + 1;
                    lines[line - 1][1] = lines[i][1] - 1;
                } else {
                    lines[i][0] += 1; // Direkt aşağı in
                    tmp = 1;
                }
            }
        }

        // Eğer hareket edilemiyorsa, yolları kontrol et ve hedefe ulaşıldı mı bak
        if (!tmp) {
            for (i = 0; i < line; i++) {
                if (lines[i][0] == obstacleGridSize - 1 && lines[i][1] == *obstacleGridColSize - 1) {
                    result++; // Hedefe ulaşıldı, sonucu arttır
                }
            }
        }
    }

    // Belleği serbest bırak
    for (i = 0; i < line; i++) {
        free(lines[i]);
    }
    free(lines);

    return result;
}
