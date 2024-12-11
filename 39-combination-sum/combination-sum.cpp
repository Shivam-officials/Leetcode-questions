class Solution
{
    public:

        void combinationSumHelper(vector<int> &candidated, int target, int start, vector<int> &currentVector, vector< vector< int>> &ans)
        {
           	// base case
            if (target == 0)
            {
                ans.push_back(currentVector);
            }
            if (start >= candidated.size()) return;

            for (int i = start; i < candidated.size(); i++)
            {
                if (candidated[i] <= target)
                {
                    currentVector.push_back(candidated[i]);
                    combinationSumHelper(candidated, target - candidated[i], i, currentVector, ans);
                    currentVector.pop_back();
                }
            }
        }

    vector<vector < int>> combinationSum(vector<int> &candidates, int target)
    {
        vector<vector < int>> ans;
        vector<int> currentVector;
        combinationSumHelper(candidates, target, 0, currentVector, ans);
        return ans;
    }
};