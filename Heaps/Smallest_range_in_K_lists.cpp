#include<bits/stdc++.h>
// #include<vector>
// #include<queue>
using namespace std;

class node{
    public:
        int data ;
        int row;
        int col;

    //constructor
    node(int data , int row   , int  col){
        this->data = data;
        this->row = row;
        this->col = col;
    }
};

class compare {
public:
    bool operator()(node* a, node* b) {
        return a->data > b->data;
    }
};
class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        int mini = INT_MAX, maxi = INT_MIN;
        priority_queue<node*, vector<node*>, compare> minHeap;

        // Step 1: Initialize the heap with the first element from each list
        for (int i = 0; i < nums.size(); i++) {
            int element = nums[i][0];
            mini = min(mini, element);
            maxi = max(maxi, element);
            minHeap.push(new node(element, i, 0));
        }

        int start = mini, end = maxi;

        while (!minHeap.empty()) {
            node* temp = minHeap.top();
            minHeap.pop();
            mini = temp->data;

            // Update the range if it's smaller
            if (maxi - mini < end - start || (maxi - mini == end - start && mini < start)) {
                start = mini;
                end = maxi;
            }

            // If more elements exist in the current row, push the next one
            if (temp->col + 1 < nums[temp->row].size()) {
                int nextVal = nums[temp->row][temp->col + 1];
                maxi = max(maxi, nextVal);
                minHeap.push(new node(nextVal, temp->row, temp->col + 1));
            } else {
                // One of the lists is exhausted, can't find a valid range beyond this
                break;
            }
        }

        return {start, end};
    }
};

int main(){
    return 0;
}