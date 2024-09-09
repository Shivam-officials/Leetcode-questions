class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
         unordered_map<int,int> hash;
        for(auto v: nums){
            ++hash[v];
        }

        int n = nums.size();
        vector<int> ans;
        for(auto pair: hash){
            if(pair.second>n/3){
                ans.push_back(pair.first);
            }
        }

        return ans;
    }
};