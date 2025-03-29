#include <stdio.h>
#include <stdlib.h>

int uniquePathsWithObstacles(int** obstacleGrid, int obstacleGridSize, int* obstacleGridColSize);

int main() {
    int i, j;
    int rows = 4, cols = 4;

    // Bellek tahsisi (3 satır için pointer dizisi oluştur)
    int **obstacleGrid = (int **)malloc(rows * sizeof(int *));
    
    // Her satır için bellek tahsisi yap
    for (i = 0; i < rows; i++) {
        obstacleGrid[i] = (int *)malloc(cols * sizeof(int));
    }

    // Değerleri manuel atayalım
    int data[4][4] = {
        {0, 0, 0,1},
        {0, 1, 0,0},
        {0, 1, 0,1},
        {0, 0, 0,0}
        
    };

    // Dinamik diziye kopyalama
    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            obstacleGrid[i][j] = data[i][j];
        }
    }
    int uniquePathsWithObstacles(int** obstacleGrid, int obstacleGridSize, int* obstacleGridColSize);
    printf("%d\n", uniquePathsWithObstacles(obstacleGrid, rows, &cols));
    // Belleği serbest bırak
    for (i = 0; i < rows; i++) {
        free(obstacleGrid[i]);
    }
    free(obstacleGrid);

    return 0;
}

int uniquePathsWithObstacles(int** obstacleGrid, int obstacleGridSize, int* obstacleGridColSize) {
    int i, j, line = 1, tmp = 1, result = 0, tmp2 = 0;
    int **lines;

    lines = (int**)malloc(sizeof(int*) * line);
    for ( i = 0; i < line; i++) {
        *(lines + i) = (int*)malloc(sizeof(int) * 2);
    }
    lines[0][0]=0;
    lines[0][1]=0;
    if (obstacleGrid[0][0] == 1) {
        return 0;
    }
    while ( tmp ) {
        tmp = 0;
        for(i = 0; i < line; i++) {
           
            tmp2 = 0;
            if ( lines[i][1] + 1 < *obstacleGridColSize && obstacleGrid[lines[i][0]][lines[i][1] + 1] == 0) {      
                lines[i][1] += 1;
                tmp = 1;
                tmp2 = 1;
            }

            if ( lines[i][0] + 1 < obstacleGridSize && obstacleGrid[lines[i][0] + 1][lines[i][1] - tmp2] == 0) {
                if ( tmp2 ) {
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
                    lines[line - 1][0] = lines[i][0] + 1;
                    lines[line - 1][1] = lines[i][1] - 1;
                }
                else {
                    lines[i][0] += 1;
                    tmp = 1;
                }
            }   
        }
        if(!tmp) {
            for(i = 0; i < line; i++)
            if ( lines[i][0] == obstacleGridSize - 1 && lines[i][1] == *obstacleGridColSize - 1) {
                result++; 
            }
        }
    }
    for( i = 0; i < line ;i++) {
        free(*(lines + i));
    }
    free(lines);
    
    return result;
}
