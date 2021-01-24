# Notes to array problems on leet code

## Merging two sorted arrays
- Given two sorted arrays (arr1, arr2) of length n and m, merge them so they are in order.
- Assume arr1 has size (n + m), so it has memory allocated to fit both arrays
  - Example:
  - arr1 = [1, 2, 3, 0, 0, 0]
  - arr2 = [4, 5, 6]
  - n == 3
  - m == 3
  - out = [1, 2, 3, 4, 5, 6]

** Solution **
- Create an index for for the end of the array
- Work backwards adding elements in reverse order
- No new space is allocated, traverse each array once
  - O(n + m)

## Erasing duplicates
- We can start at index 1 since the first element will always be valid
- If we iterate through the array, comparing the current element to the last element written, if its the same, keep going. If its different write this new value