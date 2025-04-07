# Sıralı İki Bağlı Listeyi Birleştirme

# Problem Tanımı

İki tane sıralı tek bağlı liste (linked list) verilmektedir: `liste1` ve `liste2`.  
Bu iki listeyi sıralı bir şekilde birleştiren bir fonksiyon yazmalısınız.

Yeni oluşturulacak liste, verilen iki listedeki düğümlerin birleştirilmesiyle (splice) oluşmalı ve **artarak sıralı** olmalıdır.

Fonksiyon, **birleştirilmiş yeni listenin başını (head)** döndürmelidir.

---

## Örnekler

### Örnek 1

**Girdi:**  
`liste1 = [1, 3, 5]`  
`liste2 = [2, 4, 6]`  

**Çıktı:**  
`[1, 2, 3, 4, 5, 6]`

**Görsel Anlatım:**
liste1: 1 → 3 → 5
liste2: 2 → 4 → 6

Birleştirilmiş Liste:
1 → 2 → 3 → 4 → 5 → 6

---

### Örnek 2

**Girdi:**  
`liste1 = []`  
`liste2 = []`  

**Çıktı:**  
`[]`

---

### Örnek 3

**Girdi:**  
`liste1 = []`  
`liste2 = [0, 1]`  

**Çıktı:**  
`[0, 1]`

---

## Kısıtlamalar

- Her iki listedeki düğüm sayısı `0` ile `50` arasındadır.
- Düğümlerin değeri `-100` ile `100` arasındadır.
- Her iki liste **artan sıralıdır** (non-decreasing).

---

## İpucu

Bu problem, bağlı listelerde gezinmeyi, karşılaştırmalar yapmayı ve yeni düğümler oluşturarak listeyi inşa etmeyi öğrenmek için çok faydalıdır.  
Kodlama sırasında **geçici bir başlangıç (dummy)** düğümü kullanmak işinizi kolaylaştırabilir.
