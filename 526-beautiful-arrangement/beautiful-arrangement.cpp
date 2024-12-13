class Solution
{
    public:
        void countArrangementHelperRe(vector<int> &nums, int start, int &ans)
        {
           	// base case
            if (start == nums.size())
            {
                bool valid = true;
                for (int i = 0; i < nums.size(); i++)
                {
                    if (!(nums[i] % (i + 1) == 0 || (i + 1) % nums[i] == 0))
                    {
                        valid = false;
                        break;
                    }
                    // cout << nums[i] << " ";
                }
                if (valid)
                {
                    ans++;
                }
                // cout << endl;
                return;
            }

            for (int i = start; i < nums.size(); i++)
            {   if(!(nums[i] % (start+1) == 0 || (start+1)%nums[i]== 0 )) continue;
                swap(nums[i], nums[start]);
               	//  cout << i<<endl;
                countArrangementHelperRe(nums, start + 1, ans);
                swap(nums[i], nums[start]);
            }
        }

    int countArrangement(int n)
    {
        vector<int> nums;
        for (int i = 1; i <= n; i++)
        {
            nums.push_back(i);
        }
        int ans = 0;
        countArrangementHelperRe(nums, 0, ans);
        return ans;
    }
};