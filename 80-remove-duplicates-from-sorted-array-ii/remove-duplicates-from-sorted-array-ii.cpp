class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
     unordered_map<int,int>mp;
     int index = 0;
     for(auto ch:nums){
        if(mp.find(ch)==mp.end()){
            nums[index++] = ch;
            mp[ch]++;
        }else{
            if(mp[ch]==1){
                mp[ch]++;
                nums[index++]=ch;
            }
        }
     }
     return index;
    }
};