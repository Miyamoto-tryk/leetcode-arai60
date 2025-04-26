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
  ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) { return recursiveAddTwoNumbers(l1, l2, 0); }
  ListNode* recursiveAddTwoNumbers(ListNode* l1, ListNode* l2, int carry) {
    if (l1 == nullptr && l2 == nullptr && carry == 0) return nullptr;
    int num1 = l1 ? l1->val : 0;
    int num2 = l2 ? l2->val : 0;
    int sum = num1 + num2 + carry;
    carry = sum / 10;
    l1 = l1 ? l1->next : nullptr;
    l2 = l2 ? l2->next : nullptr;
    return new ListNode(sum % 10, recursiveAddTwoNumbers(l1, l2, carry));
  }
};