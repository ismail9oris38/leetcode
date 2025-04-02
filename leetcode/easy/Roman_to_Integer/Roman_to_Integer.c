#include<stdio.h>
#include<stdlib.h>

int romanToInt(char* s); // Roma rakamını tamsayıya çeviren fonksiyon prototipi

int main(void) {
    char *s;
    int result;

    // Roma rakamı için bellek ayırma (max 20 karakter)
    s = (char*)malloc(sizeof(char) * 20);

    printf("roma rakamlarını giriniz: "); // Kullanıcıdan Roma rakamı girişi isteme
    scanf("%s", s);

    result = romanToInt(s); // Roma rakamını tamsayıya çevirme

    printf("\nroma harflerinin sayı karşılığı: \n %d", result);

    free(s); // Ayrılan belleği serbest bırakma

    return 0;
}

int romanToInt(char* s) {
    int i = 0, j, result = 0;
    // Roma rakamları ve karşılık gelen değerler
    char harfler[7] = {'I', 'V', 'X', 'L', 'C', 'D', 'M'};
    int sayılar[7] = {1, 5, 10, 50, 100, 500, 1000};

    while (s[i] != '\0') { // String sonuna kadar döngü
        j = 6; // En büyük roma rakamından başla (M)
        
        // Mevcut karakteri harfler dizisinde bul
        while (s[i] != harfler[j]) j--;

        // Eğer çift indeksli bir rakamsa (I, X, C) ve en büyük değilse
        if (j % 2 == 0 && j != 6) {
            // Çıkarma durumlarını kontrol et (IV, IX gibi)
            if (s[i + 1] == harfler[j + 1]) { // V veya L veya D
                result += sayılar[j + 1] - sayılar[j];
                i += 2; // 2 karakter atla
            }
            else if (s[i + 1] == harfler[j + 2]) { // X veya C veya M
                result += sayılar[j + 2] - sayılar[j];
                i += 2; // 2 karakter atla
            }
            else {
                result += sayılar[j]; // Normal toplama
                i++; // 1 karakter atla
            }
        }
        else {
            result += sayılar[j]; // Normal toplama (V, L, D, M)
            i++; // 1 karakter atla
        }
    }
    return result;
}
