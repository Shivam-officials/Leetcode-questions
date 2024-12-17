class Solution
{
    public:

        bool canDistributeHelper_Sir(vector<int> &quantity, vector< int > &occurances, int start)
        {
           	//base case 
            if (start == quantity.size())
            {
                return true;
            }

            int currentQuantity = quantity[start];

            // for (auto &occur: occurances)
            for(int i = 0; i < occurances.size(); i++)
            {

                if (currentQuantity <= occurances[i])
                {
                    occurances[i] = occurances[i] - currentQuantity;
                   	//  visited[start] = true;
                    if (canDistributeHelper_Sir( quantity, occurances, start + 1))
                    {
                        return true;
                    }
                   	// visited[start] = false;
                    occurances[i] = occurances[i] + currentQuantity;
                }
            }
            return false;
        }

    bool canDistribute(vector<int> &nums, vector<int> &quantity)
    {
        bool ans = false;
        unordered_map<int, int> occurances;
        vector<int> count;
        for (auto &elm: nums)
        {
            occurances[elm]++;
        }
        for (auto &pair: occurances)
        {
            count.push_back(pair.second);
           	//    cout << pair.first<<" "<<pair.second <<endl;
        }

        sort(quantity.rbegin(), quantity.rend());

        return canDistributeHelper_Sir(quantity, count, 0);
    }
};