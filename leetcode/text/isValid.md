## 题目描述
给定一个只包括 '('，')'，'{'，'}'，'['，']' 的字符串，判断字符串是否有效。

有效字符串需满足：  
1. 左括号必须用相同类型的右括号闭合。  
2. 左括号必须以正确的顺序闭合。
注意空字符串可被认为是有效字符串。
## 解题思路
1. 利用栈的特性，先入后出，遍历原来的字符串
2. 把左括号的字符入栈
3. 遇到右括号，则判断栈顶元素是否与当前括号匹配
4. 匹配则出栈，不匹配说明则返回
5. 遍历完成观看栈是否为空，为空则匹配完毕
``
## 代码展示

```cpp
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

```