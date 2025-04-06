## Problem Tanımı
`row x col` boyutunda bir grid verildiğinde:
- `grid[i][j] = 1` araziyi (land),
- `grid[i][j] = 0` suyu (water) temsil eder.

Grid hücreleri yatay/dikey olarak (çapraz değil) bağlantılıdır. Grid tamamen suyla çevrilidir ve **tam olarak bir ada** (birbirine bağlı arazi hücreleri) içerir. Adanın içinde "göl" yoktur (yani ada içindeki su, dışarıdaki suyla bağlantılı değildir). Her hücre kenar uzunluğu 1 olan bir karedir. Grid dikdörtgenseldir ve boyutları 100'ü geçmez. Adanın çevresini (perimeter) hesaplayın.

## Örnekler

### Örnek 1:
**Girdi:**
```python
grid = [
  [0,1,0,0],
  [1,1,1,0],
  [0,1,0,0],
  [1,1,0,0]
]
```
**Çıktı:** `16`  
**Açıklama:**  
Çevre, yukarıdaki görseldeki 16 sarı çizgi ile gösterilmiştir.

### Örnek 2:
**Girdi:** `grid = [[1]]`  
**Çıktı:** `4`  
**Açıklama:**  
Tek bir hücreden oluşan adanın çevresi 4'tür (her kenar 1 birim).

### Örnek 3:
**Girdi:** `grid = [[1,0]]`  
**Çıktı:** `4`  
**Açıklama:**  
Tek bir arazi hücresinin çevresi yine 4'tür.

## Kısıtlamalar
- `row == grid.length`
- `col == grid[i].length`
- `1 <= row, col <= 100`
- `grid[i][j]` ya `0` ya da `1`'dir.
- Gridde **tam olarak bir ada** bulunur.
