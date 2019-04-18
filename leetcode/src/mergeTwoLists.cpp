/*
 * Created by 2019/4/18
 * Author: zhonglongbo
 * Email: 17629272227@163.com
 */


#include <cstdio>

struct ListNode {
    int val;
    ListNode *next;

    ListNode(int x) : val(x), next(NULL) {}
};

/*
 *
 */
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

void printList(ListNode *head) {
    while (head) {
        printf("%d->", head->val);
        head = head->next;
    }
    printf("NULL");
}

void test_mergeTwoLists() {
    Solution s;
    ListNode *l1 = new ListNode(1);
    ListNode *ln1 = new ListNode(2);
    ListNode *ln2 = new ListNode(3);
    ListNode *ln3 = new ListNode(4);
    l1->next = ln1;
    ln1->next = ln2;
    ln2->next = ln3;
    ListNode *l2 = new ListNode(2);
    ListNode *lm1 = new ListNode(5);
    ListNode *lm2 = new ListNode(6);
    ListNode *lm3 = new ListNode(8);
    ListNode *lm4 = new ListNode(9);
    ListNode *lm5 = new ListNode(10);
    ListNode *lm6 = new ListNode(11);
    l2->next = lm1;
    lm1->next = lm2;
    lm2->next = lm3;
    lm3->next = lm4;
    lm4->next = lm5;
    lm5->next = lm6;
    ListNode *ret = s.mergeTwoLists(l1, l2);
    printList(ret);
}

int main() {
    test_mergeTwoLists();
    return 0;
}