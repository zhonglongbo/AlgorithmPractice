/*
 * Created by 2019/4/16
 * Author: big shot
 * Email: 17629272227@163.com
 */

#include <iostream>

/*
 * 输入一个整数，输出该数二进制表示中1的个数。其中负数用补码表示。
 */

class Solution {
public:

/*
 * 方法1
 */
    int NumberOf1(int n) {
        int byte = sizeof(n);
        int bit = byte * 8;
        int count = 0;
        while (bit--) {
            if (n & 1)
                count++;
            n >>= 1;
        }
        return count;
    }

    /*
     * 方法2
     */
    int NumberOf1_method2(int n) {
        if (n == 0)
            return n;
        int count = 1;
        while ((n &= (n - 1)))
            count++;
        return count;
    }
};

/*
 * 测试用例
 */
void test_NumberOf1() {
    Solution s;
    std::cout << s.NumberOf1_method2(15) << std::endl;
}

int main() {
    test_NumberOf1();
    return 0;
}