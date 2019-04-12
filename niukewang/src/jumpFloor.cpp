#include <cstdio>

/*
 * Created by 2019/4/12
 * Author: big shot
 * Email: 17629272227@163.com
 */


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