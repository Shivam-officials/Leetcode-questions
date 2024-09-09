class Solution {
public:
    int singleNumber(vector<int>& nums) {
        unordered_map<int,int> hash;

        for(int i = 0; i < nums.size(); i++){
            ++hash[ nums[i] ];
        }
        int ans ;
        for(auto pair:hash){
            if(pair.second == 1){
                ans = pair.first;
            }
        }
        return ans;
    }
};