class Solution
{
    public:
        int compress(vector<char> &chars)
        {
            int adjacentCount = 1;
           
            vector<char> ans;
            for (int i = 0; i < chars.size() - 1; i++)
            {
                if (chars[i] == chars[i + 1])
                {
                    adjacentCount++;

                    continue;
                }

                string currentGp = "";
                if (adjacentCount == 1)
                {
                    currentGp.push_back(chars[i]);
                }
                else if (adjacentCount > 1)
                {
                    currentGp.push_back(chars[i]);
                    currentGp.append(to_string(adjacentCount));
                }

                for (auto ch: currentGp)
                {
                    ans.push_back(ch);
                }
                adjacentCount = i != chars.size() - 1 ? 1 : adjacentCount;
            }

            ans.push_back(chars[chars.size() - 1]);
            string adjacentCountString = to_string(adjacentCount);
            int j = 0;
            while (adjacentCount>1 &&j < adjacentCountString.length())
            {
                ans.push_back(adjacentCountString[j++]);
            }

           	// cout<<"ans is" <<endl;
            for (auto ch: ans)
            {
                cout << ch;
            }
           	// cout << "ans finished"<<endl;
            chars.swap(ans);
            return chars.size();
        }
};