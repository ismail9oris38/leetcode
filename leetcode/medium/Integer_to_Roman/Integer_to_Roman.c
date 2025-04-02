#include<stdio.h>
#include<stdlib.h>

char* intToRoman(int num); // Roma rakamına dönüştürme fonksiyonu prototipi

int main(void) {
    int num;
    char *result;

    printf("sayıyı giriniz: "); // Kullanıcıdan sayı girişi isteme
    scanf("%d",&num);

    result = intToRoman(num); // Sayıyı Roma rakamına çevirme

    printf("\nsayının roman harfleriyle gösterimi:\n %s", result);

    free(result); // Dinamik olarak ayrılan belleği serbest bırakma

    return 0;
}

char* intToRoman(int num) {
    int i, tmp, harf = 0, diget = 0;
    char *result;
    char harfler[7] = {'I', 'V', 'X', 'L', 'C', 'D', 'M'}; // Roma rakamı sembolleri

    // Roma rakamı için yeterli bellek ayırma (max 20 karakter)
    result = (char*)malloc(sizeof(char) * 20);

    while (num > 0) {
        tmp = num % 10; // Sayının son basamağını al
        
        // 1-3 arası sayılar için (I, II, III gibi)
        if (tmp < 4) {
            for(i = 0; i < tmp; i++) {
                result[harf++] = harfler[diget];
            }
        }
        // 4 için (IV gibi)
        else if (tmp == 4) {
            result[harf++] = harfler[diget + 1];
            result[harf++] = harfler[diget];
        }
        // 5-8 arası sayılar için (V, VI, VII, VIII gibi)
        else if (tmp < 9 && tmp > 4) {
            for(i = 0; i < tmp - 5; i++) {
                result[harf++] = harfler[diget];
            }
            result[harf++] = harfler[diget + 1];
        }
        // 9 için (IX gibi)
        else if (tmp == 9) {
            result[harf++] = harfler[diget + 2];
            result[harf++] = harfler[diget];
        }
        
        diget += 2; // Bir sonraki basamak için sembol indeksini güncelle
        num /= 10; // Bir sonraki basamağa geç
    }
    
    result[harf] = '\0'; // String sonuna null karakter ekle

    // Rakamlar ters sırada eklendiği için stringi ters çevir
    for(i = 0; i < harf/2; i++) {
        tmp = result[i];
        result[i] = result[harf - 1 - i];
        result[harf - 1 - i] = tmp;
    }
    
    return result;
}
