## Problem Tanımı
Roma rakamları, aşağıdaki değerlere sahip yedi farklı sembolle temsil edilir:

| Sembol | Değer |
|--------|-------|
| I      | 1     |
| V      | 5     |
| X      | 10    |
| L      | 50    |
| C      | 100   |
| D      | 500   |
| M      | 1000  |

Roma rakamları, ondalık basamak değerlerinin yüksekten düşüğe doğru dönüştürülüp birleştirilmesiyle oluşturulur. Bir tam sayıyı Roma rakamına çevirirken aşağıdaki kurallar geçerlidir:

1. **Normal Dönüşüm:**  
   - Eğer değer 4 veya 9 ile başlamıyorsa, giriş değerinden çıkarılabilecek en büyük sembol seçilir.  
   - Bu sembol sonuca eklenir, değeri çıkarılır ve kalan kısım Roma rakamına çevrilir.  

2. **Çıkarmalı Form (Subtractive Notation):**  
   - Eğer değer 4 veya 9 ile başlıyorsa, bir sembol bir sonraki sembolden çıkarılarak yazılır. Örneğin:  
     - 4 → `IV` (5 - 1)  
     - 9 → `IX` (10 - 1)  
     - 40 → `XL` (50 - 10)  
     - 90 → `XC` (100 - 10)  
     - 400 → `CD` (500 - 100)  
     - 900 → `CM` (1000 - 100)  

3. **Tekrar Kuralı:**  
   - Sadece 10'un kuvvetleri (`I`, `X`, `C`, `M`) art arda **en fazla 3 kez** tekrar edilebilir.  
   - 5 (`V`), 50 (`L`), veya 500 (`D`) sembolleri **birden fazla kez tekrar edilemez**.  
   - 4 kez tekrar gerekiyorsa çıkarmalı form kullanılır (örneğin 4 → `IV`).

## Örnekler

### Örnek 1:
**Girdi:** `num = 3749`  
**Çıktı:** `"MMMDCCXLIX"`  
**Açıklama:**  
- `3000 → MMM`  
- `700 → DCC`  
- `40 → XL`  
- `9 → IX`  

### Örnek 2:
**Girdi:** `num = 58`  
**Çıktı:** `"LVIII"`  
**Açıklama:**  
- `50 → L`  
- `8 → VIII`  

### Örnek 3:
**Girdi:** `num = 1994`  
**Çıktı:** `"MCMXCIV"`  
**Açıklama:**  
- `1000 → M`  
- `900 → CM`  
- `90 → XC`  
- `4 → IV`  

## Kısıtlamalar
- `1 <= num <= 3999`

  
