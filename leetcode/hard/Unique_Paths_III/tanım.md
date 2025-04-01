## Problem Tanımı
Bir `m x n` boyutunda 2D grid verilmiştir. Grid hücreleri şu değerlere sahip olabilir:

- `1`: Başlangıç noktası. **Tam olarak bir tane** başlangıç noktası vardır.
- `2`: Bitiş noktası. **Tam olarak bir tane** bitiş noktası vardır.
- `0`: Boş hücreler. Üzerinden yürünebilir.
- `-1`: Engeller. Üzerinden yürünemez.

Görev, başlangıç noktasından bitiş noktasına giden ve **tüm boş hücrelerden tam olarak bir kez geçen** 4 yönlü (sağ, sol, yukarı, aşağı) yolların sayısını bulmaktır.

## Örnekler

### Örnek 1:
**Girdi:**
```
grid = [
  [1, 0, 0, 0],
  [0, 0, 0, 0],
  [0, 0, 2, -1]
]
```
**Çıktı:** `2`  
**Açıklama:**  
İki geçerli yol vardır:
1. `(0,0) → (0,1) → (0,2) → (0,3) → (1,3) → (1,2) → (1,1) → (1,0) → (2,0) → (2,1) → (2,2)`
2. `(0,0) → (1,0) → (2,0) → (2,1) → (1,1) → (0,1) → (0,2) → (0,3) → (1,3) → (1,2) → (2,2)`

### Örnek 2:
**Girdi:**
```
grid = [
  [1, 0, 0, 0],
  [0, 0, 0, 0],
  [0, 0, 0, 2]
]
```
**Çıktı:** `4`  
**Açıklama:**  
Dört geçerli yol vardır (örnekte detaylı yol verilmiştir).

### Örnek 3:
**Girdi:**
```
grid = [
  [0, 1],
  [2, 0]
]
```
**Çıktı:** `0`  
**Açıklama:**  
Tüm boş hücrelerden geçen bir yol yoktur.

## Kısıtlamalar
- `m == grid.length`
- `n == grid[i].length`
- `1 <= m, n <= 20`
- `1 <= m * n <= 20`
- `-1 <= grid[i][j] <= 2`
- **Tam olarak bir başlangıç hücresi (`1`) ve bir bitiş hücresi (`2`) vardır.**
