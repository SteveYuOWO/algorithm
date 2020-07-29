#include <iostream>
using namespace std;
// Definition for singly-linked list.
// 两数相加，我们定义一个带头结点的链表
// 之后用cur指向头结点
// 每次用t保存两个链表之和，
// 当前链表节点值为t % 10, 之后t / 10为进位
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        auto dummy = new ListNode(-1), cur = dummy;
        int t = 0;
        while(l1 || l2 || t) {
            if(l1) t += l1->val, l1 = l1->next;
            if(l2) t += l2->val, l2 = l2->next;
            cur = cur->next = new ListNode(t % 10);
            t /= 10;
        }
        return dummy->next;
    }
};