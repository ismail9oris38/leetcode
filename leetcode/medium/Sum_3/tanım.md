## Problem Tanımı
Bir tam sayı dizisi (`nums`) verildiğinde, `i ≠ j`, `i ≠ k` ve `j ≠ k` olacak şekilde ve `nums[i] + nums[j] + nums[k] = 0` koşulunu sağlayan tüm benzersiz üçlüleri (`triplets`) bulunuz. Çözüm kümesi tekrar eden üçlüler içermemelidir.

## Örnekler

### Örnek 1:
**Girdi:** `nums = [-1,0,1,2,-1,-4]`  
**Çıktı:** `[[-1,-1,2],[-1,0,1]]`  
**Açıklama:**  
- `(-1) + 0 + 1 = 0`  
- `(-1) + (-1) + 2 = 0`  
Diğer kombinasyonlar ya aynı üçlüyü verir ya da toplamı 0 yapmaz.

### Örnek 2:
**Girdi:** `nums = [0,1,1]`  
**Çıktı:** `[]`  
**Açıklama:**  
Toplamı 0 yapan bir üçlü yoktur.

### Örnek 3:
**Girdi:** `nums = [0,0,0]`  
**Çıktı:** `[[0,0,0]]`  
**Açıklama:**  
Tek üçlünün toplamı 0'dır.

## Kısıtlamalar
- `3 <= nums.length <= 3000`  
- `-10⁵ <= nums[i] <= 10⁵`  
