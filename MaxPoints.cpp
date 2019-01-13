//
// Created by Zhonging Chen on 2019/1/11.
//

#include "MaxPoints.h"
#include <vector>
#include <iostream>
#include <bits/unordered_map.h>
#include <map>
typedef std::pair<int, int> PAIR;

class Solution {
private:
    int gcd(int a, int b){
        if(a*b==0)
            return 1;
        int x = std::max(a,b);
        int y = a+b-x;
        if (x % y == 0)
            return y;
        else
            return gcd(y, x-y);
    }
    struct Point {
             int x;
             int y;
             Point() : x(0), y(0) {}
             Point(int a, int b) : x(a), y(b) {}
    };
    struct Comp { // comparator for key (slope) in map
        bool operator()(const Point& a, const Point& b)
        {
            int64_t diff = (int64_t)a.x*b.y - (int64_t)a.y*b.x; // convert to 64bit int for int overflow
            return (int64_t)a.y*b.y>0? diff > 0 : diff < 0;
        }
    };

public:
    int maxPoints(std::vector<Point>& points) {
        // count the slope between Pi and Pj (j>i)
        if(points.size()==0)
            return 0;
        if(points.size()==1)
            return 1;

        int maxp = 0;
        for(auto i = 0; i < points.size()-1; ++i){
            int maxi = 0;
            int vertical = 0;
            int same = 0;
            std::map<Point, int, Comp> record;
            for(auto j = i+1; j < points.size(); ++j){
                if (points[i].x == points[j].x){
                    if(points[i].y != points[j].y)
                        vertical++;
                    else
                        same++;
                }else{
                    int g = gcd(abs(points[j].y - points[i].y), abs(points[j].x - points[i].x));
                    Point slope =  Point((points[j].y - points[i].y)/g, (points[j].x - points[i].x)/g);
                    if(record.find(slope) != record.end()){
                        ++record[slope];
                    }else{
                        record[slope] = 1;
                    }
                    if(record[slope] > maxi)
                        maxi = record[slope];
                }
                maxi = std::max(vertical, maxi);
            }
            maxp = std::max(maxp, maxi+same);
        }
        return maxp+1;
    }
};
