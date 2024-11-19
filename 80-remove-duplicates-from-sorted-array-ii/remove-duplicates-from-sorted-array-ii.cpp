class Solution {
public:
    int solveIt(vector<int> &v,int maximumTime) {
  int next = 1, times = 1;
  int matcher = v[0];

  int k = 1; 
  // chalte jao kuch bhi 2 times se kam mile piche feko aur kuch nya mile to bhi piche fek do aur times ko nya hai to 1 kr do
  while (k < v.size()) {
    if (v[k] == matcher) {
        times++;
      if (times <= maximumTime) {
        v[next++] = v[k];
      }
    } else {
      matcher = v[k];
      v[next++] = v[k];
      times = 1;
    }
    k++;
  }
  // remove rest of them

  return next;
}
    int removeDuplicates(vector<int>& nums) {
    //  unordered_map<int,int>mp;
    //  int index = 0;
    //  for(auto ch:nums){
    //     if(mp.find(ch)==mp.end()){
    //         nums[index++] = ch;
    //         mp[ch]++;
    //     }else{
    //         if(mp[ch]==1){
    //             mp[ch]++;
    //             nums[index++]=ch;
    //         }
    //     }
    //  }
    //  return index;

    return solveIt(nums,2);
    }
};