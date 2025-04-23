//  Definition for singly-linked list.
struct ListNode {
  int val;
  ListNode* next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution {
 public:
  ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    ListNode* dummyHead = new ListNode();
    recursiveAddTwoNumbers(l1, l2, 0, dummyHead);
    ListNode* ans = dummyHead->next;
    delete dummyHead;
    return ans;
  }
  void recursiveAddTwoNumbers(ListNode* l1, ListNode* l2, int carry, ListNode* current) {
    if (l1 == nullptr && l2 == nullptr && carry == 0) return;
    int num1 = l1 ? l1->val : 0;
    int num2 = l2 ? l2->val : 0;
    int sum = num1 + num2 + carry;
    carry = sum / 10;
    l1 = l1 ? l1->next : nullptr;
    l2 = l2 ? l2->next : nullptr;
    current->next = new ListNode(sum % 10);
    current = current->next;
    return recursiveAddTwoNumbers(l1, l2, carry, current);
  }
};