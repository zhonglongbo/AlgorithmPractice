/*
 * Created by 2019/4/14
 * Author: big shot
 * Email: 17629272227@163.com
 * leetcode 周赛 132场
 */

#include <vector>
#include<iostream>

/*
 爱丽丝和鲍勃一起玩游戏，他们轮流行动。爱丽丝先手开局。
最初，黑板上有一个数字 N 。在每个玩家的回合，玩家需要执行以下操作：
选出任一 x，满足 0 < x < N 且 N % x == 0 。
用 N - x 替换黑板上的数字 N 。
如果玩家无法执行这些操作，就会输掉游戏。
只有在爱丽丝在游戏中取得胜利时才返回 True，否则返回 false。假设两个玩家都以最佳状态参与游戏。
 */

class Solution {
public:
    bool divisorGamePart(int N){
        for (int i = 1; i < N; ++i) {
            if(N%i==0){
                return false;
            }
        }
        return true;
    }
    bool divisorGame(int N) {
        for (int i = 1; i < N; ++i) {
            if(N%i==0){
                if (!divisorGame(N-i)){
                    return true;
                }
            }
        }
        return false;
    }
};

void test_divisorGame(){
    Solution s;
    std::cout<<s.divisorGame(2)<<std::endl;
    std::cout<<s.divisorGame(3)<<std::endl;
    std::cout<<s.divisorGame(4)<<std::endl;
}
