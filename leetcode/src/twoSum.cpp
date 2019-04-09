/*
 * Created by 2019/4/9
 * Author: big shot
 * Email: 17629272227@163.com
 */

#include <map>
#include <iostream>
#include <stdio.h>
#include <vector>

/*
 * 给定一个整数数组 nums 和一个目标值 target，请你在该数组中找出和为目标值的那 两个 整数，
 * 并返回他们的数组下标。你可以假设每种输入只会对应一个答案。但是，你不能重复利用这个数组中同样的元素。
 * 给定 nums = [2, 7, 11, 15], target = 9
 * 因为 nums[0] + nums[1] = 2 + 7 = 9
 * 所以返回 [0, 1]
 */

int Find(std::vector<int> &nums, int first, int end, int target) {
    for (int i = first; i < end; ++i) {
        if (nums[i] == target)
            return i;
    }
    return -1;
}

/*
 * 暴力法
 * 直接在数组的剩下元素中查找target-nums[i]，是否存在
 * 时间复杂度为O(N)，空间复杂度为O(1)
 */
//std::vector<int> twoSum(std::vector<int> &nums, int target) {
//    std::vector<int> ret;
//    for (int i = 0, size = nums.size(); i < size; ++i) {
//        int pos = Find(nums, i + 1, size, target - nums[i]);
//        if (pos != -1) {
//            ret.push_back(i);
//            ret.push_back(pos);
//        }
//    }
//    return ret;
//}

/*
 * 用哈希表的方式查找
 * 时间复杂度为O(1) 空间复杂度为O(N)
 * 用空间换时间的方式
 */
std::vector<int> twoSum(std::vector<int> &nums, int target) {
    std::multimap<int, int> mp;
    std::vector<int> answer;
    int len = nums.size();
    for (int i = 0; i < len; ++i) {
        mp.insert(std::pair<int,int>(nums[i],i));
        auto ret = mp.find(target - nums[i]);
        if (ret != mp.end() && ret->second != -1 && ret->second != i) {
            answer.push_back(ret->second);
            answer.push_back(i);
            mp.find(nums[i])->second = -1;
        }
    }
    return answer;
}

/*
 * 用两边哈希，效果与上面一样
 */
//std::vector<int> twoSum(std::vector<int> &nums, int target) {
//    std::multimap<int, int> mp;
//    std::vector<int> answer;
//
//    int len = nums.size();
//    for (int i = 0; i < len; ++i) {
//        mp.insert(std::pair<int, int>(nums[i], i));
//    }
//    for (int j = 0; j < len; ++j) {
//        auto ret = mp.find(target - nums[j]);
//        if (ret != mp.end() && ret->second != -1 && ret->second != j) {
//            answer.push_back(j);
//            answer.push_back(ret->second);
//            mp.find(nums[j])->second = -1;
//        }
//    }
//    return answer;
//}


/*
 * 测试用例
 */
void test_twoSum() {
    std::vector<int> array = {2,7,11,15};
    int target = 9;
    std::vector<int> ret;
    ret = twoSum(array, target);
    for (int i = 0; i < ret.size(); ++i) {
        std::cout << ret[i];
    }
    std::cout << std::endl;
}


int main() {
    test_twoSum();
    return 0;
}

