//
// Created by Zhonging Chen on 2019/1/2.
//

#include "TrapRainWater.h"
#include <vector>

class Solution {
public:
    int trap(std::vector<int>& height) {
        if (height.size() < 2)
            return 0;

        int max = 0;
        int maxid = 0;
        int res = 0;
        std::vector<int> nheight(height);
        for (int i = 0; i<height.size(); ++i){
            if (height[i]>max) {
                max = height[i];
                maxid = i;
            }
        }

        for (int i = 1; i< maxid; ++i){
            if (nheight[i] < nheight[i-1]){
                res = res + (nheight[i-1] - nheight[i]);
                nheight[i] = nheight[i-1];
            }
        }

        for (int i = height.size() -2; i > maxid; --i){
            if (nheight[i-1] < nheight[i]){
                res = res + (nheight[i] - nheight[i-1]);
                nheight[i-1] = nheight[i];
            }
        }

        return res;

    }
};