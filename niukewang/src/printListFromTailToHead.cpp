/*
 * Created by 2019/4/10
 * Author: zhonglongbo
 * Email: 17629272227@163.com
 */
#include <vector>
#include <iostream>


typedef struct ListNode {
    int val;
    struct ListNode *next;

    ListNode(int x) :
            val(x), next(NULL) {
    }
} ListNode;

void printListNode(ListNode *l) {
    while (l) {
        printf("%d->", l->val);
        l = l->next;
    }
    printf("NULL\n");
}
/*
 * 输入一个链表，按链表值从尾到头的顺序返回一个ArrayList。
 */

/*
 * 方法一
 * 先逆序链表，在打印
 */
/*
std::vector<int> printListFromTailToHead(ListNode *head) {
    std::vector<int> ret;
    if (!head){
        return ret;
    }
    if (!head->next){
        ret.push_back(head->val);
        return ret;
    }
    ListNode* first = head;
    ListNode* next = head->next;
    first->next = NULL;
    while(next){
        ListNode* tmp = next->next;
        next->next= first;
        first = next;
        next = tmp;
    }
    printListNode(first);
    while(first){
        ret.push_back(first->val);
        first = first->next;
    }
    return ret;
}
 */

/*
 * 方法2 递归法
 * 递归返回时进行数据打印
 */
//std::vector<int> ret;
//std::vector<int> printListFromTailToHead(ListNode *head) {
//    if(!head){
//        return ret;
//    }
//    printListFromTailToHead(head->next);
//    ret.push_back(head->val);
//    return ret;
//}

//std::vector<int> printListFromTailToHead(ListNode *head,std::vector<int>& ret) {
//    if(!head){
//        return ret;
//    }
//    printListFromTailToHead(head->next,ret);
//    ret.push_back(head->val);
//    return ret;
//}

/*
 * 方法3
 * 先插入到数组，在逆序数组
 */
std::vector<int> printListFromTailToHead(ListNode *head) {
    std::vector<int> ret;
    if (!head) {
        return ret;
    }
    while (head) {
        ret.push_back(head->val);
        head = head->next;
    }
    std::reverse(ret.begin(),ret.end());
    return ret;
}

/*
 * 测试用例
 */
void testprintListFromTailToHead() {
    ListNode *head1 = new ListNode(0);
    ListNode *l1 = new ListNode(0);
    ListNode *l2 = new ListNode(0);
    (head1)->val = 9;
    l1->val = 8;
    l2->val = 3;
    head1->next = l1;
    l1->next = l2;
    l2->next = NULL;
    std::vector<int> ret;
    auto vec = printListFromTailToHead(head1);
    for (int i = 0; i < vec.size(); ++i) {
        printf("%d,", vec[i]);
    }
    printf("\n");
}


int main() {
    testprintListFromTailToHead();
    return 0;
}