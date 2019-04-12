

## 题目描述
>给定一个字符串，请你找出其中不含有重复字符的 最长子串 的长度。
示例 1:
输入: "abcabcbb"
输出: 3
解释: 因为无重复字符的最长子串是 "abc"，所以其长度为 3。


## 解题思想
> 本题主要利用滑动窗口思想

## 代码展示
```cpp
class Solution {
public:
    int Find(std::string &s, int start, int end, char target) {
        int len = end - start;
        if (len == 0) {
            return start;
        }
        for (int i = start; i < end; ++i) {
            if (s[i] == target) {
                return i + 1;
            }
        }
        return -1;
    }

    int lengthOfLongestSubstring(std::string s) {
        int len = s.size();
        int max = 0;
        int startpos = 0;
        int endpos = 0;
        for (int i = 0; i < len; ++i) {
            int pos = Find(s, startpos, i, s[i]);
            endpos = i;
            if (pos != -1) {
                startpos = pos;
            }
            if (endpos - startpos + 1 > max) {
                max = endpos - startpos + 1;
            }
        }
        return max;
    }
};

/*
 * 测试用例
 */
void test_lengthOfLongestSubstring() {
    Solution s;
    std::string str;
    str = "";
    printf("%d\n", s.lengthOfLongestSubstring(str));
    str = " ";
    printf("%d\n", s.lengthOfLongestSubstring(str));
    str = "abcabcbb";
    printf("%d\n", s.lengthOfLongestSubstring(str));
    str = "ccc";
    printf("%d\n", s.lengthOfLongestSubstring(str));
    str = "abwwabc";
    printf("%d\n", s.lengthOfLongestSubstring(str));
    str = "pwwkew";
    printf("%d\n", s.lengthOfLongestSubstring(str));
}

int main() {
    test_lengthOfLongestSubstring();
    return 0;
}
```

