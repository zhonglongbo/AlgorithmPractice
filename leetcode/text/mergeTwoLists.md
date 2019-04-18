## 题目描述
将两个有序链表合并为一个新的有序链表并返回。新链表是通过拼接给定的两个链表的所有节点组成的。 

>示例：

输入：1->2->4, 1->3->4  
输出：1->1->2->3->4->4  
## 解题思路
1. 链表是有序的，所以按照顺序合并即可
2. 值小的连接在合并后链表的末尾

时间复杂度为O(N)，空间复杂度为O(1)或者O(N)

## 代码展示
```cpp
class Solution {
public:
    /*
     * 方法1，不额外开辟空间
     */
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
        if (!l1 && !l2) {
            return NULL;
        }
        ListNode *head = new ListNode(0);
        ListNode *tail = head;
        while (l1 && l2) {
            tail->next = l1->val < l2->val ? l1 : l2;
            l1->val < l2->val ? l1 = l1->next : l2 = l2->next;
            tail = tail->next;
        }
        tail->next = l1 ? l1 : l2;
        return head->next;
    }
    /*
     * 方法2，空间复杂度为O(N)
     */
    ListNode *mergeTwoLists2(ListNode *l1, ListNode *l2) {
        if (!l1 && !l2) {
            return NULL;
        }
        ListNode *head = new ListNode(0);
        ListNode *tail = head;
        while (l1 && l2) {
            if (l1->val < l2->val) {
                tail->next = new ListNode(l1->val);
                l1 = l1->next;
            } else {
                tail->next = new ListNode(l2->val);
                l2 = l2->next;
            }
            tail = tail->next;
        }
        tail->next = l1 ? l1 : l2;
        return head->next;
    }
};
```