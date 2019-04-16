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
#include <vector>
#include <algorithm>

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

    std::string InitStr(std::string s) {
        std::string ret;
        int len = s.size();
        ret.push_back('*');
        for (int i = 0; i < len; ++i) {
            ret.push_back('*');
            ret.push_back(s[i]);
        }
        ret.push_back('*');
        return ret;
    }
    /*
     * Manacher算法
     */
    std::string Manacher(std::string s) {
        std::string str = InitStr(s);
        int len = str.size();
        int center = 0;
        int radius = 0;
        int resLen = 0;
        int resCenter = 0;
        std::vector<int> v;
        v.resize(len, 0);
        for (int i = 1; i < len; ++i) {
            v[i] = radius > i ? std::min(v[2 * center - i], radius - i) : 1;
            while (str[i + v[i]] == str[i - v[i]]) ++v[i];
            if (radius < i + v[i]) {
                radius = i + v[i];
                center = i;
            }
            if (resLen < v[i]) {
                resLen = v[i];
                resCenter = i;
            }
        }
        return s.substr((resCenter - resLen) / 2, resLen - 1);
    }

    std::string longestPalindrome(std::string s) {
        return Manacher(s);
    }

//    std::string longestPalindrome(std::string s) {
//        int len = s.size();
//        if (len < 2) {
//            return s;
//        }
//        int pos = 0;
//        int max = 0;
//        for (int i = 0; i < len; ++i) {
//            int ret1 = longestPalindromePart(s, i, i);
//            int ret2 = longestPalindromePart(s, i, i + 1);
//            int num = ret1 > ret2 ? ret1 : ret2;
//            if (num >= max) {
//                max = num;
//                pos = i - (max - 1) / 2;
//            }
//        }
//        return s.substr(pos, max);
//    }
};

/*
 * 测试用例
 */
void test_longestPalindrome() {
    Solution s;
    std::string str = "babad";
    std::cout << s.longestPalindrome(str) << std::endl;
}

void test_Manacher() {
    Solution s;
    std::string str = "babad";
    std::string ret = s.Manacher(str);
    std::cout << ret << std::endl;
}

int main() {
//    test_longestPalindrome();
    test_Manacher();
    return 0;
}