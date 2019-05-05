/*
 * Created by 2019/4/18
 * Author: zhonglongbo
 * Email: 17629272227@163.com
 */

#include <vector>
#include <cstdio>

class Solution {
public:
    int maxArea(std::vector<int> &height) {
        int len = height.size();
        if (len == 0) {
            return 0;
        }
        int max_height = height[0];
        int pos = 0;
        int max_area = 0;
        for (int i = 0; i < len; ++i) {
            int area = height[i] > max_height ? max_height * (i - pos) : height[i] * (i - pos);
            if (max_height < height[i]) {
                max_height = height[i];
                pos = i;
            }
            max_area = area > max_area ? area : max_area;
        }
        return max_area;
    }
};


void test_maxArea(){
    Solution solution;
    std::vector<int> v = {2,5,4,8,3,7};
    printf("%d\n",solution.maxArea(v));
}

int main() {
    test_maxArea();
    return 0;
}
