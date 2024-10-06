class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int num = nums[0];
        int p = 0;
            
        int count = 0;
        for(int i = 0; i< nums.size();){
            while(i<nums.size() && num == nums[i]){
                count++;
                if(count<=2){
                    nums[p++]=nums[i];
                }
                i++;
            }
            if(i==nums.size())break;
            nums[p++] = nums[i];
            num = nums[i++];
            count = 1;

        }
        return p;
    }
};