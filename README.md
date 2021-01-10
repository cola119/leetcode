1. two some
   HashMap によるループの削減
   computation O(n^2), memory O(1)
   ↓
   computation O(n), memory O(n)

2. add two numbers
   LinkList の操作
   1. current.next = new LinkList
   2. current = current.next
   3. current.val = 10
