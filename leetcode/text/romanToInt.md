## 题目描述
罗马数字包含以下七种字符: I， V， X， L，C，D 和 M。

>字符          数值  
I             1  
V             5  
X             10  
L             50  
C             100  
D             500  
M             1000  
例如， 罗马数字 2 写做 II ，即为两个并列的 1。12 写做 XII ，即为 X + II 。 27 写做  XXVII, 即为 XX + V + II 。

通常情况下，罗马数字中小的数字在大的数字的右边。但也存在特例，例如 4 不写做 IIII，而是 IV。数字 1 在数字 5 的左边，所表示的数等于大数 5 减小数 1 得到的数值 4 。同样地，数字 9 表示为 IX。这个特殊的规则只适用于以下六种情况：  

I 可以放在 V (5) 和 X (10) 的左边，来表示 4 和 9。  
X 可以放在 L (50) 和 C (100) 的左边，来表示 40 和 90。   
C 可以放在 D (500) 和 M (1000) 的左边，来表示 400 和 900。  
给定一个罗马数字，将其转换成整数。输入确保在 1 到 3999 的范围内。  

>示例 1:

输入: "III"  
输出: 3
>示例 2:

输入: "IV"  
输出: 4
>示例 3:

输入: "IX"  
输出: 9
>示例 4:

输入: "LVIII"  
输出: 58  
解释: L = 50, V= 5, III = 3.
>示例 5:

输入: "MCMXCIV"  
输出: 1994  
解释: M = 1000, CM = 900, XC = 90, IV = 4.
## 解题思路
1. 先用一个哈希表映射罗马字母及其对应的值
2. 遍历字符串，比较当前值是否小于下一个存在的值，小于则把当前值置为负的
3. 依次累加即可

## 代码展示
```cpp
class Solution {
public:
    Solution() {
        _mp['I'] = 1;
        _mp['V'] = 5;
        _mp['X'] = 10;
        _mp['L'] = 50;
        _mp['C'] = 100;
        _mp['D'] = 500;
        _mp['M'] = 1000;
    }

    int romanToInt(std::string s) {
        int size = s.size();
        int num = 0;
        if (size < 2) {
            return _mp[s[0]];
        }
        for (int i = 0; i < size; ++i) {
            auto cur = _mp[s[i]];
            auto next = i + 1 < size ? _mp[s[i + 1]] : 0;
            if (cur < next) {
                cur = -cur;
            }
            num += cur;
        }
        return num;
    }

private:
    std::map<char, int> _mp;
};
/*
测试用例
*/
void test_romanToInt() {
    Solution s;
    printf("num=%d\n", s.romanToInt("III"));
    printf("num=%d\n", s.romanToInt("V"));
    printf("num=%d\n", s.romanToInt("IV"));
    printf("num=%d\n", s.romanToInt("IX"));
    printf("num=%d\n", s.romanToInt("MCMXCIV"));
    printf("num=%d\n", s.romanToInt("LVIII"));
}

int main() {
    test_romanToInt();
    return 0;
}
```