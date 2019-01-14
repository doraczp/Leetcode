//
// Created by Zhonging Chen on 2019/1/14.
//

#include "KthSmallestInMatrix.h"
class Solution {
private:
    struct compare
    {
        bool operator()(const std::pair<int,std::pair<int, int> >& a, const std::pair<int, std::pair<int, int> >& b)
        {
                return a.first>b.first;
        }
    };
public:
    int kthSmallest(std::vector<std::vector<int>>& matrix, int k) {
            std::priority_queue<std::pair<int, std::pair<int, int>>, std::vector<std::pair<int, std::pair<int, int>>>, compare> h;
            int x = matrix.size();
            int n = x; int m = k;
            int res = 0;
            for(int i=0;i<x;i++)
                    h.push(make_pair(matrix[i][0],std::make_pair(i,0)));
            while (m--) {
                    int i = h.top().second.first;
                    int j = h.top().second.second;
                    int e = h.top().first;
                    res = e;
                    h.pop();
                    if (j!=n-1){
                            h.push(std::make_pair(matrix[i][j+1], std::make_pair(i, j+1)));
                    }

            }
            return res;
    }

};
