#include <string>
#include <cstdio>

/*
 * Created by 2019/4/17
 * Author: big shot
 * Email: 17629272227@163.com
 */

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

void test_isPalindrome() {
    Solution s;
    printf("%d\n", s.isPalindrome2(121));
    printf("%d\n", s.isPalindrome2(-121));
    printf("%d\n", s.isPalindrome2(10000100001));
}

int main() {
    test_isPalindrome();
    return 0;
}