from typing import List  # List tipini kullanabilmek için typing modülünü içe aktarıyoruz

class Solution:
    # islandPerimeter fonksiyonu, grid (2D liste) alır ve adanın çevresini döndürür
    def islandPerimeter(self, grid: List[List[int]]) -> int:
        perimeter = 0  # Çevreyi tutacak değişken, başlangıçta 0
        rows = len(grid)  # Grid'in satır sayısını alıyoruz
        column = len(grid[0])  # Grid'in sütun sayısını alıyoruz (ilk satır üzerinden)
        
        # Grid üzerinde her hücreyi (i, j) olarak dolaşmak için iki iç içe döngü kullanıyoruz
        for i in range(rows):
            for j in range(column):
                
                # Eğer hücre kara (1) ise işlem yapıyoruz
                if grid[i][j] == 1:
                    edge = 4  # Başlangıçta her kara hücresinin 4 kenarı vardır
                    
                    # Eğer sağında bir kara hücresi varsa, bir kenar kaybolur
                    if j + 1 < column and grid[i][j + 1] == 1:
                        edge -= 1  # Sağdaki kenar kaybolur
                    
                    # Eğer solunda bir kara hücresi varsa, bir kenar kaybolur
                    if j - 1 >= 0 and grid[i][j - 1] == 1:
                        edge -= 1  # Soldaki kenar kaybolur
                    
                    # Eğer altında bir kara hücresi varsa, bir kenar kaybolur
                    if i + 1 < rows and grid[i + 1][j] == 1:
                        edge -= 1  # Alt kenar kaybolur
                    
                    # Eğer üstünde bir kara hücresi varsa, bir kenar kaybolur
                    if i - 1 >= 0 and grid[i - 1][j] == 1:
                        edge -= 1  # Üst kenar kaybolur
                        
                    # Toplanan kenarları çevreye ekliyoruz
                    perimeter += edge
        
        return perimeter  # Sonuç olarak çevreyi döndürüyoruz

# Çözümü test etmek için bir örnek grid oluşturuyoruz
result = Solution()
grid = [[0,1,0,0],  # İlk satır
        [1,1,1,0],  # İkinci satır
        [0,1,0,0],  # Üçüncü satır
        [1,1,0,0]]  # Dördüncü satır

# Fonksiyonu çağırarak sonucu yazdırıyoruz
print(result.islandPerimeter(grid))  # Çıktı: 12