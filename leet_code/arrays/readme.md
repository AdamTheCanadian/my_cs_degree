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

## Check If N and Its Double Exist
- Given an array arr, of size n
- Find if there is an element that is double another element
  - element[j] = 2 * element[i]

- Crude implementation, search the array twice
  - O(n^2)
- 2nd implementation:
  - Use a map/dictionary/hash to store previously seen values
  - Search the map if:
    - arr[i] * 2 exists (the double value)
    - arr[i] / 2 exists (the half value), and arr[i] % 2 to avoid fractional division

## Move Zeroes
- Create pointer to maintain the next location to be written to
- If we find a non zero, write it to the next write location, and increment write location
- This will require two-ish passes, once to move all the elements, and then to go from write index to the end setting everything to 0
- 2nd approach
  - If we write the non zero element to the write index
  - Set the index of the non zero element to 0 at the same time
    - ** only if i != write index **

## Sort Array By Parity
- Use two pointers, 
  - one starting at the front moving towards the back 
  - one at the back moving towards the front
- Will keep iterating until the two pointers cross over each other
- If the element at the front pointer is not even (mod 2), swap it with the back pointer and decrement back pointer (cause the element is now correct, its odd, and in the back of the array)
  - This brings potentially an odd number to the front (cause we swapped front and back pointers, back could have been odd).
  - However since we havent changed the front pointer, the next iteration will check this newly swapped value.

## Max Consecutive Ones II
- Double loop
  - O(n^2) 
- Start first loop (i) at first index (0)
  - Start second loop (j) at first index (so 0 in this case)
    - Keep incrementing a count variable until we have encountered two 0's
    - So if arr[j] is not 0 add one to count, UNLESS the number of zeros encountered is 2
      - So need to keep a record of how many zeros we have seen
  - If the current count > max found so far update max
- First loop is now 1, second loop starts at 1, repeat
- Test cases failed on:
  - [0, 0]. Should be an answer of 1
  - Apparently timeout on a long sequence....
    - 244 ms
- Ended up going with the double pointer.
  - Pointers start at same location
  - Move one pointer forward until you hit two zeros in a row
    - Once this happens bring the other pointer up until no more two zeros
  - Keep a record of the max, and then the current sequence is the length/gap of the two pointers (+1)

## Third maximum number
- This one kicked my butt. 
- Ended up using a set, and taking advantage of the fact that the set is ordered/sorted but it seems to be cheating.