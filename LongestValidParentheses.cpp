//
// Created by Zhonging Chen on 2019/1/2.
//
#include <math.h>
#include "LongestValidParentheses.h"
#include <iostream>
#include <cstring>
#include <stack>
#include <vector>

class Solution {
private:

public:
    int longestValidParentheses(std::string s) {
        int length = int(s.size());
        std::stack<char> st;
        std::vector<int> first;
        std::vector<int> recent;
        int stack_maxheight = 0;

        first.push_back(0);
        recent.push_back(0);

        for(int i=0; i<s.size(); ++i){
            if (s[i] == '('){
                st.push('(');
                if (stack_maxheight < st.size()) {
                    stack_maxheight = stack_maxheight + 1;
                    first.push_back(i+1);
                }

            }else if(st.top() == '('){
                st.pop();
            }else{
                st.push(')');
                if (stack_maxheight < st.size()) {
                    stack_maxheight = stack_maxheight + 1;
                    first.push_back(i+1);
                }
            }
            recent[st.size()] = i+1;
        }

        int res = 0;
        for (int i=0; i< first.size(); ++i){
            std::cout<< first[i] << std::endl;
            std::cout<< recent[i] << std::endl;
            if (res < recent[i] - first[i]){
                res = recent[i] - first[i];
            }
        }
        return res;

        /** if (length<2){
            return 0;
        }
        int mid = 0;
        bool leftp = (s[length/2-1] == '(');
        bool rightp = (s[length/2] == ')');
        if (leftp && rightp){
            mid = 2;
            int lpivot = length/2 - 3;
            while ((lpivot >= 0) || (s[lpivot] == '(' && s[lpivot + 1] == ')')){
                mid = mid + 2;
                lpivot = lpivot - 2;
            }
            lpivot = length/2 + 1;
            while ((lpivot <= length-2) || (s[lpivot] == '(' && s[lpivot + 1] == ')')){
                mid = mid + 2;
                lpivot = lpivot + 2;
            }
        }
        int left = this->longestValidParentheses(s.substr(0, length/2));
        int right = this->longestValidParentheses(s.substr(length/2, s.size() - length/2));
        if (left > mid){
            if (right > left)
                return right;
            else
                return left;
        }else{
            if (right > mid)
                return right;
            else
                return mid;
        }**/
    }
};
