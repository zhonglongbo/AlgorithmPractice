/*
 * Created by 2019/5/9
 * Author: zhonglongbo
 * Email: 17629272227@163.com
 */

#include <vector>
#include <string>
#include <cstdlib>
#include <iostream>


#include<iostream>
#include<vector>

using namespace std;

void productImplement(vector<vector<double>> dimvalue, vector<vector<double>> &res, int layer, vector<double> tmp) {
    if (layer < dimvalue.size() - 1) {
        for (int i = 0; i < dimvalue[layer].size(); i++) {
            vector<double> sb;
            sb.clear();

            for (int i = 0; i < tmp.size(); i++) {
                sb.push_back(tmp[i]);
            }
            sb.push_back(dimvalue[layer][i]);
            productImplement(dimvalue, res, layer + 1, sb);
        }
    } else if (layer == dimvalue.size() - 1) {
        for (int j = 0; j < dimvalue[layer].size(); j++) {
            tmp.push_back(dimvalue[layer][j]);
            res.push_back(tmp);
            tmp.pop_back();
        }
    }
}

