//
// Created by Zhonging Chen on 2018/12/31.
//
#include <iostream>
#include <vector>
#include <queue>

struct ListNode{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL){}
};

class Solution{
public:
    ListNode* mergeKLists(std::vector<ListNode*> &lists){
        // using divide & conquer
        // running time: O(klogn)
        std::priority_queue<std::pair<int, ListNode*>, std::vector<std::pair<int, ListNode*>> , std::greater<std::pair<int, ListNode*>> > pq;
        ListNode *res = new ListNode(-1);
        ListNode *head = res;
        for (std::vector<ListNode*>::iterator iter = lists.begin(); iter != lists.end(); iter++){
            if (*iter) {
                pq.push(std::make_pair((*iter)->val, *iter));
            }
        }
        while (!pq.empty()){
            ListNode* t =  pq.top().second;
            int v = pq.top().first;
            pq.pop();
            if (t){
                pq.push(std::make_pair(t->val, t->next));
            }
            res->next = new ListNode(v);
            res = res->next;
        }
        return head;
    }

};


