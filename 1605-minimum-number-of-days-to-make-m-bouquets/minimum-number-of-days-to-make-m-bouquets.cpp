class Solution
{
    public:
        bool isPossibleSolution(vector<int>&bloomDay,int m ,int k, int mid){
            int flowerCount  = 0;
            int bq = 0;

            if((long long)m*k>bloomDay.size()){
                return false;
            }

            for(int i = 0; i< bloomDay.size();i++){
                int day = bloomDay[i];

                if(day <= mid){
                    flowerCount++;

                    if(flowerCount>=k){
                        bq++;
                        flowerCount=0;
                    }
                }else{
                    flowerCount = 0;
                }

                if(bq>=m){
                    return true;
                }
            }
            return false;
        }

        int minDays(vector<int> &bloomDay, int m, int k)
        {
            int start = *min_element(bloomDay.begin(), bloomDay.end());
            int end = *max_element(bloomDay.begin(), bloomDay.end());
            int mid;
            int ans = -1;
            while (start <= end)
            {
                mid = (start + end) >> 1;
                if (isPossibleSolution(bloomDay, m, k, mid))
                {
                    end = mid - 1;
                    ans = mid;
                }
                else
                {
                    start = mid + 1;
                }
            }
            return ans;
        }
};