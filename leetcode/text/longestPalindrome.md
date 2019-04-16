## 题目描述
给定一个字符串 s，找到 s 中最长的回文子串。你可以假设 s 的最大长度为 1000。

>示例 1：  
输入: "babad"  
输出: "bab"  
注意: "aba" 也是一个有效答案。  
示例 2：  
输入: "cbbd"  
输出: "bb"  

## 解题思路
1. 遍历字符串
2. 遍历时，以当前字符为中心查找最大回文串
3. 保存最大回文串的长度为max  
此方法的时间复杂度为O(N^2)，空间复杂度为O(1)

## 代码展示
```cpp
class Solution {
public:
    int longestPalindromePart(std::string s, int i, int j) {
        for (; i >= 0, j < s.size(); --i, ++j) {
            if (s[i] != s[j])
                break;
        }
        ++i, --j;
        return j - i + 1;
    }

    std::string longestPalindrome(std::string s) {
        int len = s.size();
        if (len < 2) {
            return s;
        }
        int pos = 0;
        int max = 0;
        for (int i = 0; i < len; ++i) {
            int ret1 = longestPalindromePart(s, i, i);
            int ret2 = longestPalindromePart(s, i, i + 1);
            int num = ret1 > ret2 ? ret1 : ret2;
            if (num >= max) {
                max = num;
                pos = i - (max - 1) / 2;
            }
        }
        return s.substr(pos, max);
    }
};
/*
 * 测试用例
 */
void test_longestPalindrome() {
    Solution s;
    std::string str ="babad";
    std::cout << s.longestPalindrome(str) << std::endl;
}
```
