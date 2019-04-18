/*
 * Created by 2019/4/18
 * Author: big shot
 * Email: 17629272227@163.com
 */

#include <string>
#include <stack>
#include <cstdio>

/*
 * 给定一个只包括 '('，')'，'{'，'}'，'['，']' 的字符串，判断字符串是否有效。
 */

class Solution {
public:
    bool isValid(std::string s) {
        int size = s.size();
        if (size == 0) {
            return true;
        }
        if (size == 1)
            return false;
        std::stack<char> stack;
        for (int i = 0; i < size; ++i) {
            if (stack.empty()||s[i]=='('||s[i]=='{'||s[i]=='[') {
                stack.push(s[i]);
                continue;
            }
            char top = stack.top();
            if ((top == '(' && s[i] == ')') ||
                (top == '{' && s[i] == '}') ||
                (top == '[' && s[i] == ']')) {
                stack.pop();
            } else {
                return false;
            }
        }
        if (stack.empty()) {
            return true;
        }
        return false;
    }
};

void test_isValid() {
    Solution s;
    printf("%d\n", s.isValid("()")); //1
    printf("%d\n", s.isValid("()[]{}"));//1
    printf("%d\n", s.isValid("({)"));//0
    printf("%d\n", s.isValid(")(()"));//0
    printf("%d\n", s.isValid("{{}()}"));//1
    printf("%d\n", s.isValid(""));//1
    printf("%d\n", s.isValid("([)]"));//0
}


int main() {
    test_isValid();
    return 0;
}