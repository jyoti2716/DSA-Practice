#include<iostream>
#include<vector>
#include<unordered_map>
#include<algorithm>
using namespace std;

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> freq;

        // Step 1: Build frequency map
        for (int i = 0; i < nums.size(); i++) {
            freq[nums[i]]++;
        }

        // Step 2: Move map to a vector of pairs
        vector<pair<int, int>> freqVec;
        for (auto it : freq) {
            freqVec.push_back({it.first, it.second});  // {element, frequency}
        }

        // Step 3: Sort the vector by frequency in descending order
        sort(freqVec.begin(), freqVec.end(), [](pair<int, int>& a, pair<int, int>& b) {
            return a.second > b.second;
        });

        // Step 4: Extract top k elements
        vector<int> ans;
        for (int i = 0; i < k; i++) {
            ans.push_back(freqVec[i].first);
        }

        return ans;
    }
};

int main(){
    return 0;
}

