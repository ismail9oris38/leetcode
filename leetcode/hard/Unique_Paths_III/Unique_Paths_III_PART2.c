#include<stdio.h>
#include<stdlib.h>

// Benzersiz yolların sayısını hesaplayan fonksiyon
int uniquePathsIII(int** grid, int gridSize, int* gridColSize);
// DFS (Derinlik Öncelikli Arama) fonksiyonu
void dfs(int** grid, int x, int y, int emptyCount, int* pathCount, int gridSize, int gridColSize);

int main(void) {
    int i, j;
    int rows = 4, cols = 4;

    // 2D array için dinamik bellek tahsisi
    int **Grid = (int **)malloc(rows * sizeof(int *));
    for (i = 0; i < rows; i++) {
        Grid[i] = (int *)malloc(cols * sizeof(int));
    }

    // Engel haritasını tanımlıyoruz (0: Yol açık, 1: Engel var, 2: Bitiş noktası, 1: Başlangıç noktası)
    int data[4][4] = {
        {1, 0, 0, 0},
        {0, 0, 0, 0},
        {0, 0, -1, 0},
        {0, 0, 0, 2}
    };

    // Sabit diziden dinamik diziye kopyalama işlemi
    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            Grid[i][j] = data[i][j];
        }
    }

    // Fonksiyonu çağır ve sonucu ekrana yazdır
    printf("Benzersiz yolların sayısı: %d\n", uniquePathsIII(Grid, rows, &cols));

    // Dinamik bellek tahsisini serbest bırak
    for (i = 0; i < rows; i++) {
        free(Grid[i]);
    }
    free(Grid);

    return 0;
}

// Ana fonksiyon: Başlangıç noktasını bulup DFS çağırır
int uniquePathsIII(int** grid, int gridSize, int* gridColSize) {
    int startX, startY, emptyCount = 0, pathCount = 0;

    // Başlangıç noktasını ve toplam geçilebilir hücreleri say
    for (int i = 0; i < gridSize; i++) {
        for (int j = 0; j < *gridColSize; j++) {
            if (grid[i][j] == 1) { // Başlangıç noktası
                startX = i;
                startY = j;
            } else if (grid[i][j] == 0) { // Geçilebilir hücre
                emptyCount++;
            }
        }
    }

    // DFS çağır: emptyCount + 1 çünkü başlangıç noktası da geçilecek
    dfs(grid, startX, startY, emptyCount + 1, &pathCount, gridSize, *gridColSize);
    return pathCount;
}

// DFS (Derinlik Öncelikli Arama) fonksiyonu
void dfs(int** grid, int x, int y, int emptyCount, int* pathCount, int gridSize, int gridColSize) {
    // Harita dışına çıkma veya engelli alana girme durumunda çıkış
    if (x < 0 || y < 0 || x >= gridSize || y >= gridColSize || grid[x][y] == -1) {
        return;
    }

    // Hedefe ulaşıldığında tüm boş hücrelerin geçildiğinden emin ol
    if (grid[x][y] == 2) {
        if (emptyCount == 0)  (*pathCount)++; // Eğer tüm hücreler geçildiyse sayacı artır
        return;
    }

    // Hücreyi ziyaret edildi olarak işaretle
    grid[x][y] = -1;
    
    // DFS ile dört yönde ilerleme (geri dönüşlerde hücreler eski haline döndürülüyor)
    dfs(grid, x + 1, y, emptyCount - 1, pathCount, gridSize, gridColSize); // Aşağı
    dfs(grid, x - 1, y, emptyCount - 1, pathCount, gridSize, gridColSize); // Yukarı
    dfs(grid, x, y + 1, emptyCount - 1, pathCount, gridSize, gridColSize); // Sağa
    dfs(grid, x, y - 1, emptyCount - 1, pathCount, gridSize, gridColSize); // Sola

    // Geri dönüşte hücreyi tekrar ziyaret edilebilir hale getir
    grid[x][y] = 0;
}