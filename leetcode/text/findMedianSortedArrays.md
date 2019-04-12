
## 题目描述
给定两个大小为 m 和 n 的有序数组 nums1 和 nums2。
请你找出这两个有序数组的中位数，并且要求算法的时间复杂度为 O(log(m + n))。
你可以假设 nums1 和 nums2 不会同时为空。

>示例 1:

nums1 = [1, 3]
nums2 = [2]

则中位数是 2.0
>示例 2:

nums1 = [1, 2]
nums2 = [3, 4]

则中位数是 (2 + 3)/2 = 2.5

## 解题思路
> 中位数的定理

中位数，又称中点数，中值。中位数是按顺序排列的一组数据中居于中间位置的数，即在这组数据中，有一半的数据比他大，有一半的数据比他小，这里用  来表示中位数。（注意：中位数和众数不同，众数指最多的数，众数有时不止一个，而中位数只能有一个。
> 合并两个有序数组，在进行求中位数
## 代码展示
```cpp
/*
 * 合并两个有序数组，在进行求中位数
 */
    double findMedianSortedArrays(std::vector<int> &nums1, std::vector<int> &nums2) {
        int len1 = nums1.size();
        int len2 = nums2.size();
        int len = len1 + len2;
        if (!len) {
            return 0;
        }
        std::vector<int> tmp;
        int i, j;
        for (i = 0, j = 0; i < len1 || j < len2;) {
            if (i < len1 && j < len2) {
                if (nums1[i] < nums2[j]) {
                    tmp.push_back(nums1[i]);
                    ++i;
                } else {
                    tmp.push_back(nums2[j]);
                    ++j;
                }
            } else if (i < len1) {
                tmp.push_back(nums1[i]);
                ++i;
            } else {
                tmp.push_back(nums2[j]);
                ++j;
            }
        }
        return findMedianSortedArraysPart(tmp, len);
    }


};

/*
 * 测试用例
 */
void test_findMedianSortedArrays() {
    Solution s;
    std::vector<int> nums1 = {1, 3};
    std::vector<int> nums2 = {2};
    double ret = s.findMedianSortedArrays(nums1, nums2);
    printf("mid=%f\n", ret);
}

int main() {
    test_findMedianSortedArrays();
    return 0;
}
```

