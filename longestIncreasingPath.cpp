//
// Created by Zhonging Chen on 2019/1/5.
//

#include "longestIncreasingPath.h"
#include <vector>
#include <iostream>

class Solution {
public:
    std::vector<std::vector<int>> record;
    std::vector<std::vector<int>> m;
    int search(int i, int j){
        std::cout<< std::to_string(i) +" " + std::to_string(j) << std::endl;
        int cur = m[i][j];
        if (record[i][j] == 0){
            int up  = i==0 ? 0 : (m[i-1][j] > cur ? search(i-1,j) : 0 );
            int down = i==m.size()-1 ? 0 : (m[i+1][j] > cur ? search(i+1,j) : 0 ) ;
            int left = j==0 ? 0 : (m[i][j-1] > cur ? search(i,j-1) : 0 );
            int right = j==m[0].size()-1 ? 0 : (m[i][j+1] > cur ? search(i,j+1) : 0 );
            record[i][j] = 1 + std::max(std::max(up, down), std::max(left,right));
        }
        return record[i][j];
    }
    int longestIncreasingPath(std::vector<std::vector<int>>& matrix) {
        this->m = matrix;
        if (matrix.empty())
            return 0;

        int max = 0;
        record.resize(m.size());
        for (int i=0; i<matrix.size(); ++i){
            record[i].resize(matrix[0].size());
        }

        for (int i=0; i<matrix.size(); ++i){
            for(int j=0; j<matrix[0].size(); ++j){
                record[i][j] = 0;
            }
        }

        for (int i=0; i<matrix.size(); ++i){
            for(int j=0; j<matrix[0].size(); ++j){
                if (max < search(i,j))
                    max = search(i,j);
            }
        }

        return max;

    }
};
