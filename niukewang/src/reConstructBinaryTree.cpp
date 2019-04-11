/*
 * Created by 2019/4/11
 * Author: big shot
 * Email: 17629272227@163.com
 */
#include <vector>
#include <iostream>
#include <stack>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

void printTreeNode(TreeNode *root) {
    if (!root) {
        return;
    }
    printf("%d,", root->val);
    printTreeNode(root->left);
    printTreeNode(root->right);
    return;
}

/*
 * 输入某二叉树的前序遍历和中序遍历的结果，请重建出该二叉树。
 * 假设输入的前序遍历和中序遍历的结果中都不含重复的数字。
 * 例如输入前序遍历序列{1,2,4,7,3,5,6,8}和中序遍历序列{4,7,2,1,5,3,8,6}，则重建二叉树并返回。
 */

std::vector<int> handerArray(std::vector<int> pre, int start, int end) {
    std::vector<int> tmp;
    for (int i = start; i < end; ++i) {
        tmp.push_back(pre[i]);
    }
    return tmp;
}

TreeNode *reConstructBinaryTreePart(std::vector<int> pre, int prestart, int preend,
                                    std::vector<int> in, int instart, int inend) {
    if (prestart >= preend || instart >= inend) {
        return NULL;
    }
    auto root = new TreeNode(pre[prestart]);
    int i;
    for (i = instart; i < inend; ++i) {
        if (pre[prestart] == in[i]) {
            root->left = reConstructBinaryTreePart
                    (pre, prestart + 1, prestart + i - instart + 1, in, instart, i);
            root->right = reConstructBinaryTreePart
                    (pre, prestart + i - instart + 1, preend, in, i + 1, inend);
        }
    }
    return root;
}

TreeNode *reConstructBinaryTree(std::vector<int> pre, std::vector<int> vin) {
    return reConstructBinaryTreePart(pre, 0, pre.size(), vin, 0, vin.size());
}


void test_reConstructBinaryTree() {
    std::vector<int> pre = {1, 2, 4, 7, 3, 5, 6, 8};
    std::vector<int> vin = {4, 7, 2, 1, 5, 3, 8, 6};
    TreeNode *ret = reConstructBinaryTree(pre, vin);
    printTreeNode(ret);
}

int main() {
    test_reConstructBinaryTree();
    return 0;
}