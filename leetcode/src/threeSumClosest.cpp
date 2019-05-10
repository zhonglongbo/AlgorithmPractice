/*
 * Created by 2019/5/6
 * Author: zhonglongbo
 * Email: 17629272227@163.com
 */

#include <vector>
#include <algorithm>
#include <cstdio>

class Solution {
public:
    int binSearch(std::vector<int> &nums, int start, int end, int target) {
        int mid = (end - start) / 2 + start;
        int ret = mid;
        int flag = mid;
        while (start <= end) {
            mid = (end - start) / 2 + start;
            if (nums[mid] == target) {
                return target;
            } else if (nums[mid] < target) {
                start = mid + 1;
                if (abs(target - nums[flag]) < abs(target - nums[mid])) {
                    ret = flag;
                }else{
                    ret = mid;
                }
            } else if (nums[mid] > target) {
                end = mid - 1;
                if (abs(target - nums[flag]) < abs(target - nums[mid])) {
                    ret = flag;
                }else{
                    ret = mid;
                }
            }
            flag = mid;
        }
        return nums[ret];
    }

    int threeSumClosest(std::vector<int> &nums, int target) {
        int len = nums.size();
        int ret;
        if (len < 3) {
            for (int i = 0; i < len; ++i) {
                ret += nums[i];
            }
            return ret;
        }
        int sum = INT32_MAX;
        std::sort(nums.begin(), nums.end());
        for (int i = 0; i < len-2; ++i) {
            if (i - 1 >= 0 && nums[i] == nums[i - 1]) {
                continue;
            }
            int num = target - nums[i];
            for (int j = i + 1; j < len - 1; ++j) {
                if (j - 1 >= i + 1 && nums[j] == nums[j - 1]) {
                    continue;
                }
                int tmp = num - nums[j];
                int three = binSearch(nums, j + 1, len - 1, tmp);
                int t = nums[i] + nums[j] + three;
                int m = abs(target - t);
                if (m <= sum) {
                    sum = m;
                    ret = t;
                }
            }
        }
        return ret;
    }
};

int main() {
    std::vector<int> num = {-1, 2, 1, -4, 9};
    Solution s;
    s.threeSumClosest(num, 0);
    printf("hello world\n");
    return 0;
}