//
// Created by Zhonging Chen on 2019/1/2.
//

#include "CourseSchedule.h"
#include <iostream>
#include <vector>
#include <stack>

class Solution {
public:
    std::vector<int> findOrder(int numCourses, std::vector<std::pair<int, int>>& prerequisites) {
        // using dfa
        std::stack<int> q;
        bool graph[numCourses][numCourses];
        for (int i = 0; i< numCourses; ++i){
            for(int j = 0; j<numCourses; ++j){
                if(std::find(prerequisites.begin(), prerequisites.end(); std::make_pair()))
            }

        }

    }
};
