/*
 * Created by 2019/4/12
 * Author: big shot
 * Email: 17629272227@163.com
 */
#include <cstdio>

/*
 * 大家都知道斐波那契数列，现在要求输入一个整数n，请你输出斐波那契数列的第n项（从0开始，第0项为0）。
 */
class Solution {
public:
    /*
     * 递归求解
     */
//    int Fibonacci(int n) {
//        if (n<2) {
//            return n;
//        }
//        return Fibonacci(n - 1) + Fibonacci(n - 2);
//    }
    /*
     * 循环求解
     */
    int Fibonacci(int n) {
        if (n < 2) {
            return n;
        }
        int a = 0;
        int b = 1;
        int sum = 0;
        for (int i = 2; i <= n; ++i) {
            sum = a + b;
            a = b;
            b = sum;
        }
        return sum;
    }

};


int main() {
    Solution s;
    printf("Fibonacci = %d\n", s.Fibonacci(6));
    return 0;
}