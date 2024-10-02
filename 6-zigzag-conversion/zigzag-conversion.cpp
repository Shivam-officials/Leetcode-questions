class Solution
{
    public:
        string convert(string s, int numRows)
        {
            if (numRows == 1) return s;
            
            vector<string> zigzag( numRows);

            string ans = "";

            int i = 0;
            bool direction = 1;
            int row = 0;
            while (true)
            {
                if (direction)
                {
                    while (i < s.size() && row < numRows)
                    {
                        zigzag[row++].push_back(s[i++]);
                       	// cout << "the i is the " << i << endl;
                    }
                    direction = !direction;
                    row -= 2;
                }
                else
                {
                    while (i < s.size() && row >= 0)
                    {
                        zigzag[row--].push_back(s[i++]);
                    }
                    row = 1;
                    direction = !direction;
                }

                if (i >= s.size())
                {
                    break;
                }
            }

           	// cout << zigzag[0] << zigzag[1] << zigzag[2] << zigzag[3];
            for (auto str: zigzag)
            {
                ans += str;
            }
            return ans;
        }
};