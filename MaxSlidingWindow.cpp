//
// Created by Zhonging Chen on 2019/1/15.
//

#include "MaxSlidingWindow.h"
class Solution {
public:
    std::vector<int> maxSlidingWindow(std::vector<int>& nums, int k) {
        std::deque<int> buffer;
        std::vector<int> res;
        for (auto i = 0; i < nums.size(); ++i){
            while(!buffer.empty() && nums[i] >= nums[buffer.back()])
                buffer.pop_back();
            buffer.push_back(i);
            if(i>=k-1)
                res.push_back(nums[buffer.front()]);
            if(buffer.front() <= i-k+1)
                buffer.pop_front();
        }
        return res;
    }
};