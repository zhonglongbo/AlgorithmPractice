#include <vector>
#include <string>
#include <iostream>

/*
 * Created by 2019/5/10
 * Author: zhonglongbo
 * Email: 17629272227@163.com
 */

template<typename T>
void Premutation(T &nums, int first, int last, std::vector<T> &ret) {
    if (first == last) {
        ret.push_back(nums);
        return;
    }
    for (int i = first; i < last; ++i) {
        if (i != first && nums[i] == nums[first]) {
            continue;
        }
        std::swap(nums[first], nums[i]);
        Premutation(nums, first + 1, last, ret);
        std::swap(nums[first], nums[i]);
    }
}


int main() {
    std::string str = "abcd";
    std::vector<std::string> ret;
    Premutation(str, 0, str.size(), ret);
    for (int i = 0; i < ret.size(); ++i) {
        std::cout<<ret[i]<<std::endl;
    }
    return 0;
}
