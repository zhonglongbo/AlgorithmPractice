## 题目描述
一只青蛙一次可以跳上1级台阶，也可以跳上2级。求该青蛙跳上一个n级的台阶总共有多少种跳法（先后次序不同算不同的结果）。

## 解题思路
- 设青蛙跳到第n级台阶，有f(n)种方法
- 最后一次有两种情况，
- 从第(n-1)级跳到第n级，有f(n-1)中方法
- 从(n-2)级跳到第n级，有f(n-2)中方法
- 则f(n) = f(n-1)+f(n-2)
- n=1时 f(1) = 1 ,n=2时 f(2) = 2


## 代码展示
```cpp
class Solution {
public:
    int jumpFloor1(int n) {
        if (n <= 2) {
            return n;
        }
        int a = 1;
        int b = 2;
        int sum = 0;
        for (int i = 3; i <= n; ++i) {
            sum = a + b;
            a = b;
            b = sum;
        }
        return sum;
    }
    int jumpFloor2(int n) {
        if(n<=2){
            return n;
        }
        return jumpFloor2(n-2)+jumpFloor2(n-1);
    }
};


int main(){
    Solution s;
    printf("%d\n",s.jumpFloor1(39));
    printf("%d\n",s.jumpFloor2(39));
    return 0;
}
```