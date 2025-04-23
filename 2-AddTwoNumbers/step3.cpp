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
    int carry = 0;
    ListNode dummyHead = ListNode();
    ListNode* previous = &dummyHead;
    while (l1 != nullptr || l2 != nullptr || carry != 0) {
      int num1 = l1 ? l1->val : 0;
      int num2 = l2 ? l2->val : 0;
      int sum = num1 + num2 + carry;
      carry = sum / 10;
      previous->next = new ListNode(sum % 10);

      previous = previous->next;
      l1 = l1 ? l1->next : nullptr;
      l2 = l2 ? l2->next : nullptr;
    }
    return dummyHead.next;
  }
};