#include <stdio.h>
#include <stdlib.h>

int maxArea(int* height, int heightSize);

int main ( void) {
    int *height, heightSize;
    int i, alan;

    printf("dizi boyutu: ");
    scanf("%d",&heightSize);

    height = (int*)malloc(sizeof(int) * heightSize);

    printf("dizi elemanları: ");
    for ( i = 0; i < heightSize; i++) {
        scanf("%d", height + i);
    }

    alan = maxArea(height,heightSize);

    printf("%d",alan);

    free(height);

    return 0;
}

int maxArea(int* height, int heightSize) {
    int ilk = 0, son = heightSize - 1; 
    int tmp, result = 0;

    while ( ilk < son) {
        //eğer ilk eleman son elemandan küçükse ilk elemanı bir arttırıyoruz ve alan hesaplıyoruz
        if ( height[ilk] < height[son]) {
            tmp = height[ilk] * (son - ilk);
            ilk++;
        }
        //eğer son eleman ilk elemandan küçükse son elemanı bir azaltıyoruz ve alan hesaplıyoruz
        else {
            tmp = height[son] * (son - ilk);
            son--;
        }
        //eğer hesaplanan alan daha önceki hesaplanan alandan büyükse result değişkenine atıyoruz
        if ( result < tmp) {
            result = tmp;
        }
        

    }
    return result;
}
