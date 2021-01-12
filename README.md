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

7. reverse integer
   Int の扱える値は -2^31 -- 2^31 -1
   n bit の場合 -2^(n-1) -- 2^(n-1) - 1
