/*
 * Created by 2019/4/14
 * Author: big shot
 * Email: 17629272227@163.com
 */


/*
 * 给定一个字符串 s，找到 s 中最长的回文子串。你可以假设 s 的最大长度为 1000。
 */

#include <string>
#include <iostream>
#include <cstdio>


class Solution {
public:
    /*
     * 找出最大回文串
     */
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

int main() {
    test_longestPalindrome();
    return 0;
}