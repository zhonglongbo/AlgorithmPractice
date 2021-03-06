## 题目描述
给出一个 32 位的有符号整数，你需要将这个整数中每位上的数字进行反转。

示例 1:
>输入: 123  
输出: 321

 示例 2:
>输入: -123  
输出: -321

示例 3:
>输入: 120  
输出: 21  

注意: 假设我们的环境只能存储得下 32 位的有符号整数，则其数值范围为 [−231,  231 − 1]。请根据这个假设，如果反转后整数溢出那么就返回 0。

## 解题思路
1. x%10取下最后一位
2. ret = (ret+x%10)*10 ,判断ret是否溢出
3. x/=10

最重要的是防止溢出
## 代码展示
```cpp
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

```