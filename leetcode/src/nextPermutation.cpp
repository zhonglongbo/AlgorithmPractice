
/*
 * Created by 2019/5/10
 * Author: zhonglongbo
 * Email: 17629272227@163.com
 */
#include <vector>
#include <algorithm>


class Solution {
public:
    static bool cmp(int i, int j) {
        return i < j;
    }

    void nextPermutation(std::vector<int> &nums) {
        if (nums.size() < 2) {
            return;
        }
        int first = 0;
        int last = 0;
        int len = nums.size();
        for (int i = len - 1; i >= 0; --i) {
            if (i - 1 >= 0 && nums[i] > nums[i - 1]) {
                first = i - 1;
                break;
            }
        }
        for (int j = len - 1; j >= 0; --j) {
            if (nums[first] < nums[j]) {
                last = j;
                break;
            }
        }
        if (!last) {
            std::sort(nums.begin() + first, nums.end(), cmp);
        } else {
            std::swap(nums[first], nums[last]);
            sort(nums.begin() + first + 1, nums.end());
        }
    }
};