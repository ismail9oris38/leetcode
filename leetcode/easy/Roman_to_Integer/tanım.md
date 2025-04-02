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

Roma rakamları genellikle soldan sağa doğru büyükten küçüğe yazılır. Ancak, dört rakamı `IIII` şeklinde yazılmaz. Bunun yerine `IV` (5 - 1) şeklinde yazılır. Aynı kural dokuz için de geçerlidir (`IX`). Toplamda altı çıkarmalı durum vardır:

1. `I`, `V` (5) ve `X` (10) önüne gelerek 4 (`IV`) ve 9 (`IX`) oluşturur.
2. `X`, `L` (50) ve `C` (100) önüne gelerek 40 (`XL`) ve 90 (`XC`) oluşturur.
3. `C`, `D` (500) ve `M` (1000) önüne gelerek 400 (`CD`) ve 900 (`CM`) oluşturur.

Bir Roma rakamını (`s`) alıp karşılık gelen tam sayıya dönüştüren bir fonksiyon yazın.

## Örnekler

### Örnek 1:
**Girdi:** `s = "III"`  
**Çıktı:** `3`  
**Açıklama:** `III = 1 + 1 + 1 = 3`

### Örnek 2:
**Girdi:** `s = "LVIII"`  
**Çıktı:** `58`  
**Açıklama:**  
`L = 50`, `V = 5`, `III = 3` → `50 + 5 + 3 = 58`

### Örnek 3:
**Girdi:** `s = "MCMXCIV"`  
**Çıktı:** `1994`  
**Açıklama:**  
`M = 1000`, `CM = 900`, `XC = 90`, `IV = 4` → `1000 + 900 + 90 + 4 = 1994`

## Kısıtlamalar
- `1 <= s.length <= 15`
- `s` yalnızca `('I', 'V', 'X', 'L', 'C', 'D', 'M')` karakterlerini içerir.
- `s`, `[1, 3999]` aralığında geçerli bir Roma rakamıdır.
