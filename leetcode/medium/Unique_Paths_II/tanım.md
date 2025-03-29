# 63. Benzersiz Yollar II

## Problem Tanımı
Bir robot, m x n boyutlarında bir ızgara üzerinde hareket etmektedir. Başlangıçta robot, sol üst köşede (grid[0][0]) bulunur ve sağ alt köşeye (grid[m - 1][n - 1]) ulaşmaya çalışmaktadır. Robot, her adımda yalnızca sağa veya aşağıya hareket edebilir.

Izgara, engeller ve boş alanlardan oluşmaktadır. Engel olan hücreler `1`, boş alanlar ise `0` ile gösterilmektedir. Robot, engel içeren bir hücreden geçemez.

Robotun sağ alt köşeye ulaşabileceği benzersiz yolların sayısını döndüren bir fonksiyon yazınız.

> **Not:** Sonuç değeri 2 * 10⁹'u aşmayacak şekilde testler oluşturulmuştur.

---

## Örnekler

### Örnek 1
**Giriş:**
```plaintext
obstacleGrid = [[0,0,0],
                [0,1,0],
                [0,0,0]]
```
**Çıkış:**
```plaintext
2
```
**Açıklama:** 3x3'lük ızgarada, ortada bir engel bulunmaktadır. Robotun hedefe ulaşabileceği iki farklı yol vardır:
1. Sağ → Sağ → Aşağı → Aşağı
2. Aşağı → Aşağı → Sağ → Sağ

### Örnek 2
**Giriş:**
```plaintext
obstacleGrid = [[0,1,0,0],
                [0,0,0,1],
                [1,0,0,0],
                [0,0,1,0]]
```
**Çıkış:**
```plaintext
3
```
**Açıklama:** 4x4'lük ızgarada bazı engeller bulunmaktadır. Robotun hedefe ulaşabileceği üç farklı yol vardır.

### Örnek 3
**Giriş:**
```plaintext
obstacleGrid = [[0,0,1,0,0],
                [0,1,0,0,1],
                [0,0,0,1,0],
                [1,0,0,0,0],
                [0,0,1,0,0]]
```
**Çıkış:**
```plaintext
4
```
**Açıklama:** 5x5'lik ızgarada robotun hedefe ulaşabileceği dört farklı yol bulunmaktadır.

---

## Kısıtlar
- `m == obstacleGrid.length`
- `n == obstacleGrid[i].length`
- `1 <= m, n <= 100`
- `obstacleGrid[i][j]` ya `0` ya da `1` değerine sahiptir.

---

## Notlar
- Eğer başlangıç noktası (`grid[0][0]`) veya bitiş noktası (`grid[m-1][n-1]`) bir engel içeriyorsa, robot asla hedefe ulaşamaz ve sonuç `0` olur.
- Dinamik programlama yöntemi ile verimli bir çözüm elde edilebilir.

---

Bu problem, LeetCode'daki "63. Unique Paths II" problemine dayanmaktadır ancak örnekler zorlaştırılmıştır.

