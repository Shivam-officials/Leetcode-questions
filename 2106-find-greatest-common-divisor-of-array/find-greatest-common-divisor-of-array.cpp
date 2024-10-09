class Solution {
public:
    int findGCD(vector<int>& nums) {
     auto ait = min_element(nums.begin(),nums.end());
     auto bit = max_element(nums.begin(),nums.end());
     int a = *ait;
     int b = *bit;
     cout<<a<<" "<<b;
    
        if(a == 0)return b;
        if(b==0)return a;
     while(a>0 && b >0){
        if(a>b){
            a = a-b;
        }else {
            b = b-a;
        }
     }
     return a==0 ? b:a;
    }
};