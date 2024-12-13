class Solution {
public:

    void permutations(vector<int> & nums ,int start,vector<vector<int>>&ans){
        //base case 
        if(start == nums.size()){
            ans.push_back(nums);
            return;
        }
            unordered_map<int,bool>visited;
        for(int i = start; i < nums.size();i++){
            // if(i>start && (( nums[i]==nums[start]) || (nums[i]==nums[i-1]) )) continue;
           
            if(visited.find(nums[i])!=visited.end())continue;

            visited[ nums[i] ] = true;
            swap(nums[i],nums[start]);
            
            permutations(nums,start+1,ans);
            swap(nums[i],nums[start]); 
           
        }
    }

    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>>ans;
        sort(nums.begin(),nums.end());
        permutations(nums,0,ans);
        return ans;
    }
};