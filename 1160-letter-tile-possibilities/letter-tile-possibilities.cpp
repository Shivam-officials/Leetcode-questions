class Solution
{
    public:
        /**method 1
                void subSequence(string &tiles, set<string> &ansSet, string outputStr, int index)
                {
                   	//base case
                    if (index == tiles.length())
                    {
                        ansSet.insert(outputStr);
                        return;
                    }

                   	//include
                    subSequence(tiles, ansSet, outputStr + tiles[index], index + 1);
                    subSequence(tiles, ansSet, outputStr, index + 1);
                }

            void permutations(string &tiles, set<string> &ans, int index)
            {
               	// base case
                if (index == tiles.length())
                {
                    ans.insert(tiles);
                    return;
                }

                unordered_map<char, bool> map;
               	// recursion process
                for (int i = index; i < tiles.length(); i++)
                {

                    if (map.find(tiles[i]) != map.end()) continue;
                    map[tiles[i]] = true;
                    swap(tiles[i], tiles[index]);
                    permutations(tiles, ans, index + 1);
                    swap(tiles[i], tiles[index]);
                }
            }

        */

        void allPossibleArrangement(unordered_map<char, int> &count, int &result)
        {
           	//base case
           	// cout << result<<endl;
            for (auto &pair: count)
            {
                if (pair.second > 0)
                {
                    result++;
                    pair.second--;
                    allPossibleArrangement(count, result);
                    pair.second++;
                }
            }
            return;
        }

    int numTilePossibilities(string tiles)
    {
        /**method 1
        set<string> ans;
        subSequence(tiles, ans, "", 0);
        set<string> realAns;
        for (auto elm: ans)
        {
            permutations(elm, realAns, 0);
           	// cout<<elm<<endl;
        }
         return realAns.size() - 1;
         */

        unordered_map<char, int> count;
        for (auto elm: tiles)
        {
            count[elm]++;
        }

        int result = 0;
        allPossibleArrangement(count, result);
        return result;
    }
};