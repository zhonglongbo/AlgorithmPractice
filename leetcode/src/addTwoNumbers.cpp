/*
 * Created by 2019/4/9
 * Author: big shot
 * Email: 17629272227@163.com
 */

#include <iostream>
#include <vector>


typedef struct ListNode {
    int val;
    ListNode *next;

    ListNode(int x) : val(x), next(NULL) {}
} ListNode;

/*
 * 给出两个 非空 的链表用来表示两个非负的整数。其中，它们各自的位数是按照 逆序 的方式存储的，
 * 并且它们的每个节点只能存储 一位 数字。
 * 如果，我们将这两个数相加起来，则会返回一个新的链表来表示它们的和。
 * 您可以假设除了数字 0 之外，这两个数都不会以 0 开头。
 * 示例：
输入：(2 -> 4 -> 3) + (5 -> 6 -> 4)
输出：7 -> 0 -> 8
原因：342 + 465 = 807
 */

/*
 * 打印链表,调试使用
 */
void printListNode(ListNode *l) {
    while (l) {
        printf("%d->", l->val);
        l = l->next;
    }
    printf("NULL\n");
}

ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
    ListNode *head = l1;
    int flag = 0;
    ListNode *prev = head;
    while (l1 && l2) {
        int sum = l1->val + l2->val + flag;
        sum > 9 ? (l1->val = sum - 10, flag = 1) : (l1->val = sum, flag = 0);
        prev = l1;
        l1 = l1->next;
        l2 = l2->next;
    }
    ListNode *tail = l1 ? l1 : l2;
    while (tail) {
        prev->next = tail;
        int sum = tail->val + flag;
        sum > 9 ? (tail->val = sum - 10, flag = 1) : (tail->val = sum, flag = 0);
        tail = tail->next;
        prev = prev->next;
    }
    if (flag) {
        prev->next = new ListNode(flag);
    }
    return head;
}

void testaddTwoNumbers() {
    ListNode *head1 = (ListNode *) malloc(sizeof(ListNode));
    ListNode *l1 = (ListNode *) malloc(sizeof(ListNode));
    ListNode *l2 = (ListNode *) malloc(sizeof(ListNode));
    (head1)->val = 9;
    l1->val = 8;
    l2->val = 3;
    head1->next = l1;
    l1->next = NULL;
    l2->next = NULL;
    ListNode *head2 = (ListNode *) malloc(sizeof(ListNode));
    ListNode *l3 = (ListNode *) malloc(sizeof(ListNode));
    ListNode *l4 = (ListNode *) malloc(sizeof(ListNode));
    (head2)->val = 1;
    l3->val = 6;
    l4->val = 4;
    head2->next = NULL;
    l3->next = l4;
    l4->next = NULL;
    //addTwoNumbers(head1,head2);
    printListNode(addTwoNumbers(head1, head2));
}

int main() {
    //testReverseListNode();
    testaddTwoNumbers();
    return 1;
}