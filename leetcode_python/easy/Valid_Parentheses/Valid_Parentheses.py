class Solution:
    def isValid(self, s: str) -> bool:
        stack = []
        # Parantezlerin eşleşmesini kontrol etmek için bir harita oluşturuyoruz
        mapping = {')': '(', '}': '{', ']': '['}
        
        for char in s:
            # Eğer karakter bir kapanan parantezse
            if char in mapping:
                # Stack boşsa veya stack'teki en üst karakter eşleşmiyorsa geçersiz
                top_element = stack.pop() if stack else '#'
                if mapping[char] != top_element:
                    return False
            else:
                # Açık parantezleri stack'e ekliyoruz
                stack.append(char)
        
        # Son olarak, stack'in boş olması gerekir
        return not stack
    
# Test
result = Solution()
s = "()[]{}"
print(result.isValid(s))  # Çıktı: True
s = "(]"
print(result.isValid(s))  # Çıktı: False
s = "([)]"  
print(result.isValid(s))  # Çıktı: False
