from typing import Optional

# Bağlı listenin (linked list) düğüm (node) sınıfı
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val    # Düğümün değeri
        self.next = next  # Sonraki düğüme bağlantı

# Çözüm sınıfı
class Solution:
    def mergeTwoLists(self, list1: Optional[ListNode], list2: Optional[ListNode]) -> Optional[ListNode]:
        head = ListNode()   # Sahte bir başlangıç düğümü
        tail = head         # tail, yeni birleşmiş listenin sonunu takip eder

        # Her iki liste de boş değilse devam et
        while list1 and list2:
            if list1.val < list2.val:
                tail.next = list1      # list1'in düğümünü tail'e bağla
                list1 = list1.next     # list1'de ilerle
            else:
                tail.next = list2      # list2'nin düğümünü tail'e bağla
                list2 = list2.next     # list2'de ilerle
            tail = tail.next           # tail'i bir sonraki düğüme kaydır

        # Kalan düğümleri doğrudan bağla
        if list1:
            tail.next = list1
        else:
            tail.next = list2

        return head.next  # Gerçek başlangıç düğümünü döndür (head sahteydi)
