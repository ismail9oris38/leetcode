# Container With Most Water – Problem Tanımı

Bu problemde, bir dizi yükseklik değeri (`height` array) verilmektedir. Bu yükseklikler, x ekseni boyunca dikey çizgiler oluşturmaktadır.  
Her çizginin `(i, 0)` ve `(i, height[i])` noktalarında başladığı varsayılır.

## **Amaç**
İki çizgi seçerek, bunların x ekseniyle oluşturduğu bir su kabının **en fazla su tutmasını** sağlamaktır.  
Tutulan su miktarı şu şekilde hesaplanır:

- **Genişlik:** Seçilen iki çizginin x koordinatları arasındaki mesafe `(right - left)`
- **Yükseklik:** İki çizginin daha kısa olanının yüksekliği `min(height[left], height[right])`
- **Alan (Su Miktarı):**  

Verilen dizi içindeki **herhangi iki çizgiyi seçerek** oluşturulabilecek **maksimum su miktarını** döndürmeliyiz.

---

## **Örnekler**
```txt
Input: height = [1,8,6,2,5,4,8,3,7]
Output: 49
Açıklama:
En iyi seçim, 8. indeksdeki (yükseklik 7) ve 1. indeksdeki (yükseklik 8) çizgilerdir.
Aralarındaki mesafe 7 birimdir ve daha kısa olan çizginin yüksekliği 7 olduğundan,
maksimum su alanı:7 × 7 = 49

Input: height = [1,1]
Output: 1
Açıklama:
İki çizgi arasındaki mesafe 1 birimdir ve yükseklikleri 1 olduğundan,
maksimum alan:1 × 1 = 1

**## **Kısıtlamalar****
	•	n (height dizisinin uzunluğu) en az 2 ve en fazla 100.000 olabilir.
	•	Yükseklik değerleri 0 ile 10⁴ arasında olabilir.

**## **Çözüm Yöntemi****

Bu problem için brute force (O(n²)) yaklaşımı zaman aşımı hatası verir.
Bunun yerine, çift yönlü iki pointer (Two Pointer Approach – O(n)) kullanarak verimli bir çözüm geliştirilmelidir.
