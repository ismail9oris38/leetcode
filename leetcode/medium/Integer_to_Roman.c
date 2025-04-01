#include <stdio.h>
#include <stdlib.h>

// Sayıyı Roma rakamlarına çeviren fonksiyon
char* intToRoman(int num);

int main(void) {
    int num;
    char *result;

    // Kullanıcıdan sayı girişi al
    printf("Sayıyı giriniz: ");
    scanf("%d", &num);

    // Sayıyı Roma rakamlarına çevir
    result = intToRoman(num);

    // Sonucu ekrana yazdır
    printf("\nSayının Roma rakamlarıyla gösterimi:\n %s\n", result);

    // Belleği serbest bırak
    free(result);

    return 0;
}

char* intToRoman(int num) {
    int i, tmp, harf = 0, basamak = 0;
    
    // Çıktıyı saklamak için yeterli bellek ayır
    char *result = (char*)malloc(sizeof(char) * 20);
    if (!result) {
        printf("Bellek tahsisi başarısız!\n");
        exit(1);
    }

    // Roma rakamları için karakter dizileri
    char birler[] = {'I', 'X', 'C', 'M'}; // 1, 10, 100, 1000
    char besler[] = {'V', 'L', 'D'};      // 5, 50, 500

    // Sayıyı basamak basamak işle
    while (num > 0) {
        tmp = num % 10; // Son basamağı al

        if (tmp < 4) {
            // 1, 2, 3 için (I, II, III gibi)
            for (i = 0; i < tmp; i++) {
                result[harf++] = birler[basamak];
            }
        } else if (tmp == 4) {
            // 4 için (IV, XL, CD gibi)
            result[harf++] = besler[basamak];
            result[harf++] = birler[basamak];
        } else if (tmp < 9) {
            // 5, 6, 7, 8 için (V, VI, VII, VIII gibi)
            for (i = 0; i < tmp - 5; i++) {
                result[harf++] = birler[basamak];
            }
            result[harf++] = besler[basamak];
        } else { // tmp == 9
            // 9 için (IX, XC, CM gibi)
            result[harf++] = birler[basamak + 1];
            result[harf++] = birler[basamak];
        }

        basamak++;  // Basamak seviyesini artır
        num /= 10;  // Bir sonraki basamağa geç
    }

    // String'in sonuna null karakter ekleyerek güvenli hale getir
    result[harf] = '\0';

    // Roma rakamlarını ters çevir (doğru sırayla yazdırmak için)
    for (i = 0; i < harf / 2; i++) {
        tmp = result[i];
        result[i] = result[harf - 1 - i];
        result[harf - 1 - i] = tmp;
    }

    return result; // Çevrilen sonucu döndür
}