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
        int prev = 0;
        int next = 0;
        for (int i = 0; i < numRows; ++i) {
            int j = i;
            if (j != 0 && j != numRows - 1) {
                prev = j;
                ret.push_back(s[j]);
                while (true) {
                    next = 2 * (numRows - i) - 2 + prev;
                    if (next > len)
                        break;
                    ret.push_back(s[next]);
                    prev = flag + prev;
                    if (prev > len)
                        break;
                    ret.push_back(s[prev]);
                }
            } else {
                while (j < len) {
                    ret.push_back(s[j]);
                    j = j + 2 * numRows - 2;
                }
            }
        }
        return ret;
    }
};

void test_Convert() {
    Solution s;
    std::string str = "LE";
    std::string ret = s.convert(str, 1);
    std::cout << ret << std::endl;
}

int main() {
    test_Convert();
    return 0;
}