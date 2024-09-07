class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int un  = nums[0] ;
        // sort(nums.begin(),nums.end());
        int nextIndex = 1;
        for(int i = 1; i < nums.size(); i++){
            if(un != nums[i]){
                un = nums[i];
               nums[nextIndex++] = nums[i];
            }
        }
        return nextIndex;
    } 
};