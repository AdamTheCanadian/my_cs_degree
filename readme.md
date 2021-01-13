# My CS Degree

My 2021 goal of learning as much of the CS fundamentals as possible. Not having a formal CS degree but having >5 years experience wanted to test my knowledge, fill in any gaps, and learn something new along the way.

## Algorithms

- Linear time:
  - Maximum number of guesses == number of elements in the list
  - O(n)
- Log (logarimthic time)
  - Binary search for example. Splitting the search space in half every iteration.
  - An array of size 128 has max 7 iterations. Double the size of the array, increase the max iterations by 1 
    - Assuming log(n). log2(128) == 7, log2(256) == 8.
  - O(log n) for example

- Big O
  - It is not time, but the number of operations/steps (ignoring constants, conditionals).
  - Worst case scenario. Not the average time
    - Linear search of O(n) cant be slower than the n
  - O(n)
    - Linear time
  - O(log n)
    - log time
  - O(n * log n)
    - Quick sort for example
  - O(n^2)
    - Selection sort
  - O(n!)
    - Traveling salesman problem

### Recursion

- Recursive functions contain two parts:
  - Recursive case:
    - Part where the function calls itself
  - Base case:
    - Part where the function returns, conditions checks, etc.

## Data Structures

### Hash Table

- Load factor:
  - Number of elements in the hash table divided by the number of available slots
    - 1 element in a table that can hold 3 elements has a load of 1/3
  - If the load factor goes up the chance of collisions goes up
    - Slower -> bad
  - If load approaches 0.7 good idea to resize