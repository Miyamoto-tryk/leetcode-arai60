
//  Definition for singly-linked list.
struct ListNode {
  int val;
  ListNode* next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode* next) : val(x), next(next) {}
};
// 　再帰
static int carry = 0;
class Solution {
 public:
  ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    if (!l1 && !l2 && carry == 0) return nullptr;
    int x = l1 ? l1->val : 0;
    int y = l2 ? l2->val : 0;
    int sum = x + y + carry;
    carry = sum / 10;

    l1 = l1 ? l1->next : nullptr;
    l2 = l2 ? l2->next : nullptr;

    return new ListNode(sum % 10, addTwoNumbers(l1, l2));
  }
};
