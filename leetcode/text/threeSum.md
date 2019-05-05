### 题目描述
给定一个包含 n 个整数的数组 nums，判断 nums 中是否存在三个元素 a，b，c ，使得 a + b + c = 0 ？找出所有满足条件且不重复的三元组。


### 解题思路
1. 把三数之和转换为求两个数之和 
2. 再把两数之和转化为查找一个数

### 代码展示

```cpp
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
            /*
            去重
            */
            if (i - 1 >= 0 && nums[i] == nums[i - 1]) {
                continue;
            }
            int num = 0 - nums[i];
            for (int j = i + 1; j < len; ++j) {
                /*
                去重
                */
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

```