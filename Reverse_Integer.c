#include <stdio.h>
#include <limits.h>  // INT_MAX ve INT_MIN için


int reverse(int x) {
    int reverse = 0;
    
    while (x != 0) {
        int kalan = x % 10;

        // Taşmayı kontrol etme
        if (reverse > INT_MAX / 10 || (reverse == INT_MAX / 10 && kalan > 7)) {
            return 0;  // Pozitif sınırı aşma kontrolü
        }
        if (reverse < INT_MIN / 10 || (reverse == INT_MIN / 10 && kalan < -8)) {
            return 0;  // Negatif sınırı aşma kontrolü
        }

        reverse = reverse * 10 + kalan;
        x /= 10;
    }

    return reverse;
}

int main() {
    printf("%d\n", reverse(123));       // 321
    printf("%d\n", reverse(-123));      // -321
    printf("%d\n", reverse(1534236469)); // 0 (Çünkü taşma oluyor)
    printf("%d\n", reverse(-2147483412)); // -2143847412 (Geçerli bir sayı)
    return 0;
}