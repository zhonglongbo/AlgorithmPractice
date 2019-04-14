/*
 * Created by 2019/4/14
 * Author: big shot
 * Email: 17629272227@163.com
 */

#include <cmath>
#include <cstdio>

/*
 * 一只青蛙一次可以跳上1级台阶，也可以跳上2级……它也可以跳上n级。求该青蛙跳上一个n级的台阶总共有多少种跳法。
 */

class Solution {
public:
    int jumpFloorII(int number) {
        return pow(2,number-1);
    }
};

/*
 * 测试用例
 */
void test_jumpFloorII(){
    Solution s;
    printf("%d\n",s.jumpFloorII(1));
    printf("%d\n",s.jumpFloorII(2));
    printf("%d\n",s.jumpFloorII(3));
    printf("%d\n",s.jumpFloorII(4));
    printf("%d\n",s.jumpFloorII(5));
    printf("%d\n",s.jumpFloorII(9));
    printf("%d\n",s.jumpFloorII(11));
}

