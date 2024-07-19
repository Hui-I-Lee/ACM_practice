#include <iostream>

using namespace std;

// Definition for singly-linked list node
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

ListNode* swapPairs(ListNode* head) {
    // Edge case: empty list or single node
    if (!head || !head->next) {
        return head;
    }
    
    // Dummy node to handle edge case for head
    ListNode* dummy = new ListNode(0);
    dummy->next = head;
    
    ListNode* prev = dummy;
    ListNode* curr = head;
    ListNode* next = head->next;
    
    while (curr && next) {
        // Swap nodes
        prev->next = next;
        curr->next = next->next;
        next->next = curr;
        
        // Move pointers to the next pair
        prev = curr;
        curr = curr->next;
        if (curr) {
            next = curr->next;
        }
    }
    
    // Return the new head (dummy->next handles the edge case)
    return dummy->next;
}

// Utility function to print the linked list
void printList(ListNode* head) {
    ListNode* curr = head;
    while (curr) {
        cout << curr->val << " ";
        curr = curr->next;
    }
    cout << endl;
}

int main() {
    // Test case 1: [1, 2, 3, 4]
    ListNode* head1 = new ListNode(1);
    head1->next = new ListNode(2);
    head1->next->next = new ListNode(3);
    head1->next->next->next = new ListNode(4);
    
    cout << "Original list 1: ";
    printList(head1);
    
    ListNode* swapped1 = swapPairs(head1);
    
    cout << "Swapped list 1: ";
    printList(swapped1);
    cout << endl;

    // Test case 2: []
    ListNode* head2 = nullptr;
    
    cout << "Original list 2: ";
    printList(head2);
    
    ListNode* swapped2 = swapPairs(head2);
    
    cout << "Swapped list 2: ";
    printList(swapped2);
    cout << endl;

    // Test case 3: [1]
    ListNode* head3 = new ListNode(1);
    
    cout << "Original list 3: ";
    printList(head3);
    
    ListNode* swapped3 = swapPairs(head3);
    
    cout << "Swapped list 3: ";
    printList(swapped3);
    cout << endl;

    return 0;
}
