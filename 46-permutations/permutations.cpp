class Solution
{
    public:
        void printAllPermutationsForVector(vector<int> &input, int i, vector<vector< int>> &ans)
        {
           	//base case
            if (i == input.size())
            {
                ans.push_back(input);
                return;
            }

            for (int j = i; j < input.size(); j++)
            {
                swap(input[i], input[j]);
                printAllPermutationsForVector(input, i + 1, ans);
                swap(input[i], input[j]);
            }
        }
    vector<vector < int>> permute(vector<int> &nums)
    {
        vector<vector < int>> ans;
        printAllPermutationsForVector(nums, 0, ans);
        return ans;
    }
};