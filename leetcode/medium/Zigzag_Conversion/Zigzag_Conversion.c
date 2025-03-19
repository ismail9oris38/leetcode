#include <stdio.h>
#include <stdlib.h>

char* convert(char* string, int numRows);

int main(void) {
    int numRows;
    char *string = "PAYPALISHIRING";

    numRows = 4;

    printf("\noutput: %s", convert(string, numRows));

   
    char *result = convert(string, numRows);
    free(result); // Bellekten ayrılan alanı serbest bırak

    return 0;
}

char* convert(char* string, int numRows) {
    
    char *result;
    int i, j, k, uzunluk = 0, alt, üst;

    // Eğer numRows 1 ise, zaten dönüşüm gereksiz, direkt string'i döndür.
    if (numRows == 1) return string;
    
    // String uzunluğunu hesapla
    while (*(string + uzunluk) != '\0') uzunluk++;

    // Bellekte yer ayır (ekstra karakter için +1 ekleyerek)
    result = (char*)malloc(sizeof(char) * (uzunluk + 1));
    
    // Sonlandırıcı karakteri ekle (HATA: *(result + uzunluk + 1) yerine *(result + uzunluk) olmalı)
    *(result + uzunluk) = '\0';

    // Eğer string uzunluğu satır sayısından küçükse, dönüşüme gerek yok, string'i döndür.
    if (uzunluk < numRows) return string;

    k = 0;

    // Zigzag desenini belirleyen aralıkları ayarla
    alt = 2 * numRows - 2;
    üst = 0; 
    
    // Satırları tek tek işle
    for (i = 0; i < numRows; i++) {
        j = i;  // Başlangıç indexini satır numarasına göre ayarla

        *(result + k++) = *(string + j);  // İlk karakteri ekle

        while (j < uzunluk) {
            j += alt;  // Alt aralığı uygula
            if (alt != 0 && j < uzunluk) {
                *(result + k++) = *(string + j);  // Karakteri ekle
            }

            j += üst;  // Üst aralığı uygula
            if (üst != 0 && j < uzunluk) {
                *(result + k++) = *(string + j);  // Karakteri ekle
            }
        } 

        // Sonraki satır için aralıkları güncelle
        alt -= 2;
        üst += 2;  
    }

    return result;  // Zigzag formatında oluşturulan string'i döndür
}
