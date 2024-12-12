class Solution
{
    public:
        void combinationSumHelper(vector<int> &candidated, int target, int start,
            vector<int> &currentVector,
            vector<vector < int>> &ansSet)
        {
           	// base case
            if (target == 0)
            {
                if (target == 0)
                {
                    ansSet.push_back(currentVector);
                    return;
                }
            }

            if (start >= candidated.size())
                return;

            for (int i = start; i < candidated.size(); i++)
            {
                if (candidated[i] <= target)
                {
                    if(i>start && candidated[i]==candidated[i-1]) continue;
                    currentVector.push_back(candidated[i]);
                    combinationSumHelper(candidated, target - candidated[i], i + 1,
                        currentVector, ansSet);
                    currentVector.pop_back();
                }
            }
        }
    vector<vector < int>> combinationSum2(vector<int> &candidates, int target)
    {
        vector<vector < int>> ansSet;
        vector<int> currentVector;
        sort(candidates.begin(), candidates.end());
        combinationSumHelper(candidates, target, 0, currentVector, ansSet);
        vector<vector < int>> ans;
        for (auto vectors: ansSet)
        {
            ans.push_back(vectors);
        }
        return ans;
    }
};