#include <string>
#include <cstdio>
#include <cmath>

/*
 * Created by 2019/4/17
 * Author: big shot
 * Email: 17629272227@163.com
 */

class Solution {
public:
    /*
     * 此种方法很直接，但是一定要注意溢出
     */
    int reverse(int x) {
        int64_t ret = 0;
        while (x / 10) {
            ret = (x % 10 + ret) * 10;
            x /= 10;
            if (ret < INT32_MIN || ret > INT32_MAX)
                return 0;
        }
        return ret + x;
    }
};
/*
 * 测试
 */
void test_reverse() {
    Solution s;
    printf("%d\n", s.reverse(1534236469));
}

int main() {
    test_reverse();
    return 0;
}