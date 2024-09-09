class Solution
{
    public:
        vector<int> rowAndMaximumOnes(vector<vector < int>> &mat)
        {
            unordered_map<int, int> hash;
            for (int i = 0; i < mat.size(); i++)
            {
                hash[i];
                for (int j = 0; j < mat[0].size(); j++)
                {
                    if (mat[i][j] == 1)
                    {
                        ++hash[i];
                    }
                }
            }

            vector<int> ans
            {
                0,
                hash[0]
            };
            for (int i = 1; i < mat.size(); i++)
            {
                if (ans[1] < hash[i])
                {
                    ans[0] = i;
                    ans[1] = hash[i];
                }
                else if (ans[1] == hash[i])
                {
                    ans[0] == i;
                }
            }

            return ans;
        }
};