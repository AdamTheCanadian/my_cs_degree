class MyLinkedList {
public:
    /** Initialize your data structure here. */
    MyLinkedList() : length_(0) {
        
    }
    
    /** Get the value of the index-th node in the linked list. If the index is invalid, return -1. */
    int get(int index) {
        if (index < 0 || index >= length_) {
            return -1;
        }
        auto curr = head_;
        for (int i = 0; i < index + 1; i++) {
            curr = curr->next;
        }
        std::cout << "Index: " << index << std::endl;
        std::cout << "Length: " << length_ << std::endl;
        return curr->val;
    }
    
    /** Add a node of value val before the first element of the linked list. After the insertion, the new node will be the first node of the linked list. */
    void addAtHead(int val) {
        addAtIndex(0, val);
    }
    
    /** Append a node of value val to the last element of the linked list. */
    void addAtTail(int val) {
        addAtIndex(length_, val);
    }
    
    /** Add a node of value val before the index-th node in the linked list. If index equals to the length of linked list, the node will be appended to the end of linked list. If index is greater than the length, the node will not be inserted. */
    void addAtIndex(int index, int val) {
        if (index > length_) {
            return;
        }
        if (index < 0) {
            return;
        }
        auto curr = head_;
        for (int i = 0; i < index; i++) {
            curr = curr->next;
        }
        std::shared_ptr<Node> new_node = std::make_shared<Node>();
        new_node->val = val;
        new_node->next = curr->next;
        curr->next = new_node;
        length_ += 1;
    }
    
    /** Delete the index-th node in the linked list, if the index is valid. */
    void deleteAtIndex(int index) {
        if (index >= length_) {
            return;
        }
        if (index < 0) {
            return;
        }
        auto curr = head_;
        for (int i = 0; i < index; i++) {
            curr = curr->next;
        }
        curr->next = curr->next->next;
        length_ -= 1;
    }
private:
    struct Node {
        int val = 0;
        std::shared_ptr<Node> next = nullptr;
    };
    std::shared_ptr<Node> head_ = std::make_shared<Node>();
    int length_;
};