## 题目描述
编写一个函数来查找字符串数组中的最长公共前缀。

如果不存在公共前缀，返回空字符串 ""。

>示例 1:

输入: ["flower","flow","flight"]  
输出: "fl"  
>示例 2:

输入: ["dog","racecar","car"]  
输出: ""  
解释: 输入不存在公共前缀。
## 解题思路
逐一匹配，返回公共前缀
## 代码展示
```cpp
class Solution {
public:

    std::string longestCommonPrefixPart(const std::string &s1, const std::string &s2) {
        int start = 0;
        int end = 0;
        for (int i = 0, j = 0; i < s1.size() && j < s2.size(); ++i, ++j) {
            if (s1[i] == s2[i]) {
                end++;
            } else {
                break;
            }
        }
        return s1.substr(0, end);
    }

    std::string longestCommonPrefix(std::vector<std::string> &strs) {
        int size = strs.size();
        if (size == 0) {
            return "";
        }
        for (int i = 1; i < size; ++i) {
            strs[0] = longestCommonPrefixPart(strs[0], strs[i]);
        }
        return strs[0];
    }
};


void test_longestCommonPrefix() {
    Solution s;

    std::vector<std::string> s1 = {"flower", "flow", "flight"};
    std::vector<std::string> s2 = {"dog", "racecar", "car"};
    std::vector<std::string> s3 = {};
    printf("longestCommonPrefix:%s\n", s.longestCommonPrefix(s1).c_str());
    printf("longestCommonPrefix:%s\n", s.longestCommonPrefix(s2).c_str());
    printf("longestCommonPrefix:%s\n", s.longestCommonPrefix(s3).c_str());
}

int main() {
    test_longestCommonPrefix();
    return 0;
}
```