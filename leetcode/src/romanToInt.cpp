/*
 * Created by 2019/4/18
 * Author: big shot
 * Email: 17629272227@163.com
 */

#include <string>
#include <map>
#include <cstdio>
#include <vector>

/*
字符          数值
I             1
V             5
X             10
L             50
C             100
D             500
M             1000
 */

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