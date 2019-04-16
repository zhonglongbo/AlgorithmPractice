## 题目描述
将一个给定字符串根据给定的行数，以从上往下、从左到右进行 Z 字形排列。

比如输入字符串为 "LEETCODEISHIRING" 行数为 3 时，排列如下：
>L   C   I   R  
E T O E S I I G  
E   D   H   N  

之后，你的输出需要从左往右逐行读取，产生出一个新的字符串，比如："LCIRETOESIIGEDHN"。
  
请你实现这个将字符串进行指定行数变换的函数：
>string convert(string s, int numRows); 
 
示例 1:

>输入: s = "LEETCODEISHIRING", numRows = 3
输出: "LCIRETOESIIGEDHN"

示例 2:
>输入: s = "LEETCODEISHIRING", numRows = 4
输出: "LDREOEIIECIHNTSG"
解释:

>L     D     R  
E   O E   I I  
E C   I H   N  
T     S     G  

## 解题思路
拿到这道题我第一想到的是一行一行的输出即可  
所以你需要注意一行输出的规律即可  

时间复杂度O(N)，空间复杂度O(N)
## 代码展示
```cpp
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
```