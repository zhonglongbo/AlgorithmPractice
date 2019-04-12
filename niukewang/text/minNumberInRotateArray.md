
## 题目描述
把一个数组最开始的若干个元素搬到数组的末尾，我们称之为数组的旋转。 输入一个非减排序的数组的一个旋转，输出旋转数组的最小元素。 例如数组{3,4,5,1,2}为{1,2,3,4,5}的一个旋转，该数组的最小值为1。 NOTE：给出的所有元素都大于0，若数组大小为0，请返回0。

## 解题思路
> 我理解的这道题就是找出数组最小值
- 可以先排序，排序完直接返回第一个元素，时间复杂度O(NlogN),空间复杂度O(1)
- 直接遍历查找最小元素，时间复杂度O(N)，空间复杂度O(1)

## 代码展示
>方法1
```cpp
class Solution {
public:
    int minNumberInRotateArray(std::vector<int> rotateArray) {
        int len = rotateArray.size();
        if(!len){
            return 0;
        }
        int min = rotateArray[0];
        for (int i = 0; i < len; ++i) {
            if(min>rotateArray[i]){
                min = rotateArray[i];
            }
        }
        //std::sort(rotateArray.begin(),rotateArray.end());
        return min;
    }
};

```
>方法2
```cpp
class Solution {
public:
    int minNumberInRotateArray(std::vector<int> rotateArray) {
        int len = rotateArray.size();
        if(!len){
            return 0;
        }
        
        std::sort(rotateArray.begin(),rotateArray.end());
        return rotateArray[0];
    }
};

```