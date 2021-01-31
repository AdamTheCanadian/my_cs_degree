# Linked List

## Linked List Cycle
- Find if a node in a link list cycles to a previous node in the list
- Need to keep a record of whether or not a node has been visited before.
  - Cant use an array since the nodes are not layed out in order (how do we know we came back to node 2 for example)
  - So used a map with the node address (pointer) as the key
  - If a node is in the map, it has been visited
```cpp
std::map<ListNode*, bool> visited;
if (!head) {
    return false;
}
visited.insert({head, true});
ListNode* n = head->next;
while (n != NULL) {
    // Seen this node before
    if (visited.count(n) > 0) {
        return true;
    }
    visited.insert({n, true});
    n = n->next;
}
return false;
```
- Solution below apparently is called Floyds Cycle Finding
```cpp
if (!head) {
    return false;
}
auto n1 = head;
auto n2 = head->next;
while (n1 != n2) {
    if (!n2 || !n2->next) {
        return false;
    }
    n1 = n1->next;
    n2 = n2->next->next;
}
return true;
```