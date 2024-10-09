class Solution {
public:

 
    int countPrimes(int n) {
        if(n<=1) return 0;
        int ans = 0;
        vector<bool> prime(n,true);

     prime[0]=prime[1]=false;

     for (int i = 2; i < n; i++) {
        if(prime[i]) {
            ans++;
        
        int j = i*2;
        while(j<n)
        {
            prime[j]= false;
            j += i;
        }
        
     }
     }

    // int ans =0;
    //  for(int i = 0; i < n; i++)
    //  {
    //     if(prime[i]==true)
    //     {
    //         ans++;
    //     }
        
    //  }

     return ans;
    }
};