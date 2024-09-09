class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int,int> hash;
        for(auto v: nums){
            ++hash[v];
        }

        int n = nums.size();
        int ans;
        for(auto pair: hash){
            if(pair.second>n/2){
                ans = pair.first;
            }
        }

        return ans;
    }
};