#include<stdio.h>
#include<stdlib.h>

int uniquePathsIII(int** grid, int gridSize, int* gridColSize);


int main() {
    int i, j;
    int rows = 4, cols = 4;

    // 2D array için dinamik bellek tahsisi
    int **Grid = (int **)malloc(rows * sizeof(int *));
    for (i = 0; i < rows; i++) {
        Grid[i] = (int *)malloc(cols * sizeof(int));
    }

    // Engel haritasını tanımlıyoruz (0: Yol açık, 1: Engel var)
    int data[4][4] = {
        {1, 2, 0, 0},
        {0, 0, 0, 0},
        {0, 0, -1, 0},
        {0, 0, 0, 0}
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

int uniquePathsIII(int** grid, int gridSize, int* gridColSize) {
    int i, j, tmp, tmp_sağ, tmp_yukarı, tmp_aşağı, result = 0, line = 1, total_line = 0, engel = 0;
    int **lines;

    for ( i = 0; i < gridSize; i++) {
        for ( j = 0; j < gridColSize[i]; j++) {
            if ( grid[i][j] == -1) {
                engel++;
            }
        }
    }
    for ( i = 0; i < gridSize; i++) {
        total_line += gridColSize[i];
    }
    total_line -= engel;

    lines = (int**)malloc(sizeof(int*) * line);
    for ( i = 0; i < line; i++) {
        *(lines + i) = (int*)malloc(sizeof(int) * 3);
    }

    tmp = 1;
    i = 0;
    while( i < gridSize && tmp) {
        j = 0;
        while(j < gridColSize[i] && tmp) {
            if( grid[i][j] == 1) {
                tmp = 0;
            }
            j++;
        }
        i++;
    } 

    if( tmp ) {
        return 0;
    }

    lines[0][0] = i - 1;
    lines[0][1] = j - 1;
    lines[0][2] = 1;

    tmp = 1;
    while ( tmp ) {
        tmp = 0;
        for ( i = 0; i < line; i++) {
            if ( lines[i][2] != 0) {

                tmp_aşağı = 0;
                tmp_yukarı = 0;
                tmp_sağ = 0;
                if ( lines[i][0] + 1 < gridSize && (grid[lines[i][0] + 1][lines[i][1]] == 0 || grid[lines[i][0] + 1][lines[i][1]] == 2) ) {
                    lines[i][0]++;
                    lines[i][2]++;
                    tmp = 1;
                    tmp_yukarı = 1;
                }

                if ( lines[i][0] - 1 >= 0 && (grid[lines[i][0] - 1 - tmp_yukarı][lines[i][1]] == 0 || grid[lines[i][0] + 1][lines[i][1]] == 2)) {
                    if ( tmp_yukarı ) {
                        line++;
                        int **temp = (int**)realloc(lines, sizeof(int*) * line);
                        if (temp != NULL) {
                            lines = temp;
                        } else {
                            printf("Hafıza atama hatası.\n");
                            return -1;
                        }
                        lines[line - 1] = (int*)malloc(sizeof(int) * 2);
                        if (lines[line - 1] == NULL) {
                            printf("Hafıza atama hatası.\n");
                            return -1;
                        }
                        lines[line - 1][0] = lines[i][0] - tmp_yukarı - 1;
                        lines[line - 1][1] = lines[i][1];
                        lines[line - 1][2] = lines[i][2];
                    }
                    else {
                        lines[i][0]--;
                        lines[i][2]++;
                        tmp = 1;
                    }
                    tmp_aşağı = 1;
                }

                if ( lines[i][1] + 1 < gridColSize[i] && (grid[lines[i][0] - tmp_yukarı + tmp_aşağı][lines[i][1] + 1] == 0 || grid[lines[i][0] + 1][lines[i][1]] == 2)) {
                    if ( tmp_yukarı || tmp_aşağı ) {
                        line++;
                        int **temp = (int**)realloc(lines, sizeof(int*) * line);
                        if (temp != NULL) {
                            lines = temp;
                        } else {
                            printf("Hafıza atama hatası.\n");
                            return -1;
                        }
                        lines[line - 1] = (int*)malloc(sizeof(int) * 2);
                        if (lines[line - 1] == NULL) {
                            printf("Hafıza atama hatası.\n");
                            return -1;
                        }
                        lines[line - 1][0] = lines[i][0] - tmp_yukarı + tmp_aşağı;
                        lines[line - 1][1] = lines[i][1] + 1;
                        lines[line - 1][2] = lines[i][2];
                    }
                    else {
                        lines[i][1]++;
                        lines[i][2]++;
                        tmp = 1;
                    }
                    tmp_sağ = 1;
                }

                if ( lines[i][1] - 1 >= 0 && (grid[lines[i][0] - tmp_yukarı + tmp_aşağı][lines[i][1] - tmp_sağ - 1] == 0 || grid[lines[i][0] + 1][lines[i][1]] == 2)) {

                    if ( tmp_yukarı || tmp_aşağı || tmp_sağ) {
                        line++;
                        int **temp = (int**)realloc(lines, sizeof(int*) * line);
                        if (temp != NULL) {
                            lines = temp;
                        } else {
                            printf("Hafıza atama hatası.\n");
                            return -1;
                        }
                        lines[line - 1] = (int*)malloc(sizeof(int) * 2);
                        if (lines[line - 1] == NULL) {
                            printf("Hafıza atama hatası.\n");
                            return -1;
                        }
                        lines[line - 1][0] = lines[i][0] - tmp_yukarı + tmp_aşağı;
                        lines[line - 1][1] = lines[i][1] - tmp_sağ - 1;
                        lines[line - 1][2] = lines[i][2];
                    }
                    else {
                        lines[i][1]--;
                        lines[i][2]++;
                        tmp = 1;
                    }
                }
            }
            
            
        }

        for ( i = 0; i < line; i++) {
            if( grid[lines[i][0]][lines[i][1]] == 2) {
                if ( lines[i][2] == total_line ) {
                    result++;
                }
                lines[i][2] = 0;         
            }
            if ( lines[i][2] > total_line) {
                lines[i][2] = 0;
            }
        }
        for( i = 0; i < line ;i++) {
            free(*(lines + i));
        }
        free(lines);
    }
    return result;
}