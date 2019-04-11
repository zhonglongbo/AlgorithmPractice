/*
 * Created by 2019/4/11
 * Author: big shot
 * Email: 17629272227@163.com
 */
#include <stack>

/*
 * 用两个栈来实现一个队列，完成队列的Push和Pop操作。 队列中的元素为int类型。
 */
class Solution {
public:
    void push(int node) {
        ClearStack(stack1, stack2);
        stack1.push(node);
        ClearStack(stack2, stack1);
    }

    void ClearStack(std::stack<int> &dst, std::stack<int> &src) {
        while (!src.empty()) {
            dst.push(src.top());
            src.pop();
        }
    }

    int pop() {
        int top = stack2.top();
        stack2.pop();
        return top;
    }

private:
    std::stack<int> stack1; //队尾
    std::stack<int> stack2; //队头
};

int main() {
    Solution s;
    s.push(12);
    s.push(13);
    s.push(14);
    s.push(15);
    s.push(16);
    printf("%d,", s.pop());
    printf("%d,", s.pop());
    printf("%d,", s.pop());
    printf("%d,", s.pop());
    return 0;
}