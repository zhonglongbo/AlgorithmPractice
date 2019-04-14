
## 题目描述
一只青蛙一次可以跳上1级台阶，也可以跳上2级……它也可以跳上n级。求该青蛙跳上一个n级的台阶总共有多少种跳法。

## 解题思路
设f(n)为跳到第n级台阶的方法数  
则有  
当n=1 -> f(1) = 1  2^0  
  n=2 -> f(2) = 2  2^1  
  n=3 -> f(3) = 4  2^2  
  n=4 -> f(4) = 8  2^3  
 由此可以推出  
 当n=n时 f(n) = 2^(n-1)

## 代码展示
```cpp
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

```