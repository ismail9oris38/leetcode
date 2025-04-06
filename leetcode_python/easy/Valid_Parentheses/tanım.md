# Geçerli Parantezler

## Problem Tanımı

Bir string içerisinde sadece şu karakterler bulunmaktadır: `'('`, `')'`, `'{'`, `'}'`, `'['`, `']'`.  
Bu stringin geçerli (valid) olup olmadığını kontrol eden bir program yazmalısınız.

## Geçerli olma koşulları:

- Açılan her parantez kapatılmalıdır.
- Parantezler doğru sırayla kapatılmalıdır.
- Aynı türde parantezler birbiriyle eşleşmelidir.

## Örnekler

### Örnek 1

**Girdi:**  
`"{[()]}"`  

**Çıktı:**  
`true`  

**Açıklama:**  
Tüm parantezler doğru sırayla ve eşleşerek kapanmış.

---

### Örnek 2

**Girdi:**  
`"{[(])}"`  

**Çıktı:**  
`false`  

**Açıklama:**  
Açılan parantezler doğru sırayla kapanmamış.

---

### Örnek 3

**Girdi:**  
`"(()[]{})"`  

**Çıktı:**  
`true`  

---

### Örnek 4

**Girdi:**  
`"[({)]"`  

**Çıktı:**  
`false`

## Kısıtlamalar

- `1 <= s.length <= 10^4`
- Girdi sadece şu karakterlerden oluşacaktır: `'('`, `')'`, `'{'`, `'}'`, `'['`, `']'`.

## Not

Bu problem, yığın (stack) veri yapısını anlamak ve uygulamak için güzel bir alıştırmadır.
