/*
 * Created by 2019/4/17
 * Author: big shot
 * Email: 17629272227@163.com
 */

#include <string>
#include <cstdio>

/*
 * 请你来实现一个 atoi 函数，使其能将字符串转换成整数。
 */
class Solution {
public:
    int myAtoi(std::string str) {
        int len = str.size();
        int64_t ret = 0;
        int flag = 1;
        bool z = false;
        bool f = false;
        bool num = false;
        bool tmp = false;
        for (int i = 0; i < len; ++i) {
            if (str[i] == '+') {
                if (f || num || z)
                    break;
                z = true;
            } else if (str[i] == '-') {
                if (z || num || f)
                    break;
                f = true;
                flag = -1;
            } else if (str[i] >= '0' && str[i] <= '9' && !tmp) {
                num = true;
                ret = int64_t((str[i] - '0' + ret) * 10);
            } else if (num || z || f) {
                break;
            } else if((str[i] <= 'z' && str[i] >= 'a') || str[i] <= 'Z' && str[i] >= 'A' || str[0] == '.'){
                tmp = true;
            }
            if (ret / 10 > INT32_MAX || ret / 10 < INT32_MIN) {
                break;
            }
        }

        ret = ret * flag;
        return ret = ret / 10 > INT32_MAX ? INT32_MAX : ret / 10 < INT32_MIN ? INT32_MIN : ret / 10;
    }

};

void test_myAtoi() {
    Solution s;
    std::string str1 = " b11228552307";
    std::string str2 = "--1";
    std::string str3 = "words and 987";
    std::string str4 = "-91283472332";
    std::string str5 = "4193 with words";
    std::string str6 = "-20000000000000000000";
    std::string str7 = "3.14159";
    printf("%d\n", s.myAtoi(str1));
    printf("%d\n", s.myAtoi(str2));
    printf("%d\n", s.myAtoi(str3));
    printf("%d\n", s.myAtoi(str4));
    printf("%d\n", s.myAtoi(str5));
    printf("%d\n", s.myAtoi(str6));
    printf("%d\n", s.myAtoi(str7));
}

int main() {
    test_myAtoi();
    return 0;
}