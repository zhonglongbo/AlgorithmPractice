/*
 * Created by 2019/5/5
 * Author: zhonglongbo
 * Email: 17629272227@163.com
 */

#include <vector>
#include <algorithm>

class Solution {
public:
    int binSearch(std::vector<int> &nums, int start, int end, int target) {
        while (start <= end) {
            int mid = (end - start) / 2 + start;
            if (nums[mid] == target) {
                return mid;
            } else if (nums[mid] < target) {
                start = mid + 1;
            } else if (nums[mid] > target) {
                end = mid - 1;
            }
        }
        return -1;
    }

    std::vector<std::vector<int>> threeSum(std::vector<int> &nums) {
        int len = nums.size();
        std::vector<std::vector<int> > ret;
        if (len < 3) {
            return ret;
        }
        std::sort(nums.begin(), nums.end());
        for (int i = 0; i < len; ++i) {
            if (i - 1 >= 0 && nums[i] == nums[i - 1]) {
                continue;
            }
            int num = 0 - nums[i];
            for (int j = i + 1; j < len; ++j) {
                if (j - 1 >= i + 1 && nums[j] == nums[j - 1]) {
                    continue;
                }
                int target = num - nums[j];
                int pos = binSearch(nums, j + 1, len - 1, target);
                if (pos >= 0) {
                    std::vector<int> tmp;
                    tmp.push_back(nums[i]);
                    tmp.push_back(nums[j]);
                    tmp.push_back(nums[pos]);
                    ret.push_back(tmp);
                }
            }
        }
        return ret;
    }
};


int main() {
    std::vector<int> nums = {0, 0, 0, 0};
    Solution s;
    std::vector<std::vector<int>> ret = s.threeSum(nums);
    return 0;
}