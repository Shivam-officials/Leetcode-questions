class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
                unordered_map<int,int> hash;

        for(int i = 0; i < nums.size(); i++){
            ++hash[ nums[i] ];
        }
        vector<int> ans ;
        for(auto pair:hash){
            if(pair.second == 1){
                ans.push_back( pair.first);
            }
        }
        return ans;
    }
};