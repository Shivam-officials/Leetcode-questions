class Solution {
public:

 bool isPossible(vector<int> &arr, int mid , int k){
        int pos = arr[0];
        int cows = 1;
        for (int i = 1; i < arr.size();i++){
            if(arr[i]-pos>=mid){
                cows++;
                pos = arr[i];
            }
        }
        return cows>=k;
    }

    int solve(int n, int k, vector<int> &stalls) {
    
        // Write your code here
        
        sort(stalls.begin(),stalls.end());
        int start = 1;
        int end = stalls[stalls.size()-1] - stalls[0];
        int mid ;
        int ans;
        while(start<=end){
            mid = start + end >> 1 ;
            
            if(isPossible(stalls,mid,k)){
                ans = mid ;
                start = mid+1;
            }else{
                end = mid -1;
            }
        }
        
        return ans;
    }
    int maxDistance(vector<int>& position, int m) {
       return solve(position.size(),m,position);
    }
};