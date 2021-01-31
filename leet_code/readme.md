# Challenges

Answers to random leet code challenges that were done a) not part of a block, or b) encountered before hitting a block

## Shortest Word Distance

- Find the shortest distance of two words (word1 and word2) in an array of words
- Double loop so O(n^2)
- Since word1 and word2 could appear more than once in words we need to keep a record of the shortest distance found
- Could do a single pass by keeping a record of the indicies found
```cpp
int short_dist = 1e6;
for (int i = 0; i < words.size(); i++) {
    // Dont need to start the 2nd loop unless we are on a valid word
    if (words[i] == word1) {
        for (int j = 0; j < words.size(); j++) {
            // Got a 2nd word test if its the shortest
            if (words[j] == word2) {
                int dist = abs(j - i);
                if (dist < short_dist) {
                    short_dist = dist;
                }
            }
        }
    }
}
return short_dist;
```