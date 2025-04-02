## Problem Tanımı
Bir string dizisi (`strs`) verildiğinde, bu dizideki tüm stringlerin **en uzun ortak önekini** (başlangıç kısmını) bulan bir fonksiyon yazın. Eğer ortak önek yoksa, boş bir string (`""`) döndürün.

## Örnekler

### Örnek 1:
**Girdi:** `strs = ["flower","flow","flight"]`  
**Çıktı:** `"fl"`  
**Açıklama:**  
Tüm stringler "fl" ile başlar:
- "flower" → "fl"
- "flow" → "fl"
- "flight" → "fl"

### Örnek 2:
**Girdi:** `strs = ["dog","racecar","car"]`  
**Çıktı:** `""`  
**Açıklama:**  
Ortak bir önek yoktur.

## Kısıtlamalar
- `1 <= strs.length <= 200`
- `0 <= strs[i].length <= 200`
- `strs[i]` yalnızca küçük İngilizce harflerinden oluşir (boş değilse).
