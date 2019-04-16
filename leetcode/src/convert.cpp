/*
 * Created by 2019/4/16
 * Author: big shot
 * Email: 17629272227@163.com
 */

#include <string>
#include <iostream>

class Solution {
public:
    std::string convert(std::string s, int numRows) {
        int len = s.size();
        if (len < 2 || numRows < 2)
            return s;
        std::string ret;
        int flag = 2 * numRows - 2;
        for (int i = 0; i < numRows; ++i) {
            for (int j = 0; j + i < len;) {
                ret.push_back(s[j + i]);
                if (i != 0 && i != numRows - 1 && j + flag - i < len) {
                    ret.push_back(s[j + flag - i]);
                }
                j = j + flag;
            }
        }
        return ret;
    }

};

void test_Convert() {
    Solution s;
    std::string str = "LEETCODEISHIRING";
    std::string ret = s.convert(str, 3);
    std::cout << ret << std::endl;
}

int main() {
    test_Convert();
    return 0;
}