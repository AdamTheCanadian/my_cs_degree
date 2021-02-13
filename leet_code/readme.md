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

## Add two numbers (linked list)
```cpp
// Our list we will be adding elements to
ListNode* ret_list = nullptr;
// Our current pointer into the new list
ListNode* curr_node = ret_list;

// If our sum is >= 10 we need to carry over a one to the next sum
int carry_one = 0;

// Go through the list and start adding up the values.
while (l1 != nullptr || l2 != nullptr) {
    // Since the lists could be different sizes we need to check
    // that they arent null, but if we set their values to 0 we
    // can keep the logic the same (dont need end logic for checking 
    // unequal list lengths)
    int l1_val = 0;
    int l2_val = 0;
    if (l1 != nullptr) {
        l1_val = l1->val;
        l1 = l1->next;
    }
    if (l2 != nullptr) {
        l2_val = l2->val;
        l2 = l2->next;
    }
    int sum = l1_val + l2_val + carry_one;
    // We used our carry_one so set it to 0
    carry_one = 0;
    if (sum >= 10) {
        sum -= 10;
        // We now have a leftover carry
        carry_one = 1;
    }
    // Our very first element, so initialize our list
    if (ret_list == nullptr) {
        ret_list = new ListNode(sum);
        curr_node = ret_list;
    }
    else {
        // Create a new element
        curr_node->next = new ListNode(sum);
        curr_node = curr_node->next;
    }
}

// We are done iterating and still left with a carry over so need to add 
// the 1 as the last element.
if (carry_one > 0) {
    curr_node->next = new ListNode(carry_one);
}
return ret_list;
```

## Longest substring
- Find the longest substring in a string without any repeating characters
  - "abcabc"
    - Longest is 3, "abc"
  - "abad"
    - Longest is 3, "bad"
- We know if the string is not empty the longest is at least 1 (the first character in the string)
- First naive attempt 
  - Should be ~O(n^2)
  - **Ran in ~8-12ms**
  
```cpp
// Handle the empty string case
if (s.empty()) {
    return 0;
}
// We can assume the first character is valid, so its the start
// of the current longest substring, hence we know the max is at
// least 1
int max_cnt = 1;
int curr_cnt = 1;
int sub_str_start = 0;
// Given the character at s[i], start at the beginning of the string
// and iterate until we either:
// 1) see the same character
// 2) we reach i
for (int i = 1; i < s.size(); i++) {
    for (int j = sub_str_start; j < i; j++) {
        // Have not seen s[i]
        if (s[i] != s[j]) {
            curr_cnt += 1;
        }
        else {
            sub_str_start = j + 1;
        }
    }
    if (curr_cnt > max_cnt) {
        max_cnt = curr_cnt;
    }
    curr_cnt = 1;
}
return max_cnt;
```

- Second attempt, using a map/hash to keep a record of what elements we have seen before
- This one ran ~16-20ms so slower than the other attempt
- We are storing the index of the character plus 1:
  - This stored index represents the start of the window given our current character.
  - For example: 
  - s = "abcabc"
  - We would store in the map [a, 1] NOT [a, 0]
  - Because when we get to the second instance of a (at actual index 3), we want the longest substring that includes the second instance of a (so we want the string 'bca', not 'abca').
int max_cnt = 0;
std::map<char, int> seen_chars;

// Two pointers, start and current end of our longest current substr
int i = 0;
for (int j = 0; j < s.size(); j++) {
    
    // Have we seen this character?
    if (seen_chars.count(s[j]) > 0) {
        i = max(seen_chars[s[j]], i);
    }
    
    max_cnt = max(max_cnt, j - i + 1);
    seen_chars[s[j]] = j + 1;
    
}
return max_cnt;