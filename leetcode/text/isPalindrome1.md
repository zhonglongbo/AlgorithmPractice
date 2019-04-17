## 题目描述
判断一个整数是否是回文数。回文数是指正序（从左向右）和倒序（从右向左）读都是一样的整数。

示例 1:

输入: 121  
输出: true  
示例 2:

输入: -121  
输出: false  
解释: 从左向右读, 为 -121 。 从右向左读, 为 121- 。因此它不是一个回文数。  
示例 3:

输入: 10  
输出: false  
解释: 从右向左读, 为 01 。因此它不是一个回文数。  
进阶:

你能不将整数转为字符串来解决这个问题吗？
## 解题思路
我第一眼看到题想到的是转化为字符串在处理，这样时间复杂度为O(N),空间复杂度为O(N)  
之后才想到用一半的数字比较，如果后一半等于前一半的数字大小，则为回文串。要考虑溢出问题

## 代码展示
```cpp
class Solution {
public:
    /*
     * 方法1
     */
    bool isPalindrome1(int x) {
        if (x < 0) {
            return false;
        }
        std::string str;
        while (x / 10) {
            str.push_back(x % 10 + '0');
            x /= 10;
        }
        str.push_back(x + '0');
        int len = str.size();
        for (int i = 0, j = len - 1; i < j; ++i, --j) {
            if (str[i] != str[j])
                return false;
        }
        return true;
    }
    /*
     * 方法2
     */
    bool isPalindrome2(int x) {
        if (x < 0 || x % 10 == 0 && x != 0) {
            return false;
        }
        int num = 0;
        while (x > num) {
            num = (num + x % 10) * 10;
            if (x==num/10) {
                return true;
            }
            x /= 10;
            if (x==num/10) {
                return true;
            }
        }
        return num / 10 == x || num == x;
    }
};

```