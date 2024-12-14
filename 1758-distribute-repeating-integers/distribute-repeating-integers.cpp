class Solution {
public:

bool canDistributeHelper_Sir(vector<int>&nums, vector<int>&quantity, vector<int> occurances, int start){
    //base case 
    if(start == quantity.size()){
        return true;
    }

    int currentQuantity = quantity[start];

    for (auto &occur : occurances) {
        if (currentQuantity<=occur) {
         occur = occur-currentQuantity;
        //  visited[start] = true;
         if(canDistributeHelper_Sir(nums, quantity,  occurances, start+1)){
            return true;
         }
        // visited[start] = false;
        occur = occur+currentQuantity;
        }
    }
    return false;
}


bool canDistribute(vector<int>& nums, vector<int>& quantity) {
  bool ans = false;
  unordered_map<int, int>occurances;
  vector<int>count;
  for (auto elm : nums) {
   occurances[elm]++;
  }
  for (auto pair : occurances) {
    count.push_back(pair.second);
   cout << pair.first<<" "<<pair.second <<endl;
  }
  


   sort(quantity.rbegin(),quantity.rend());
  
//   return canDistributeHelper_ME(nums,quantity,occurances,0);      
  return canDistributeHelper_Sir(nums,quantity,count,0);      
}
};