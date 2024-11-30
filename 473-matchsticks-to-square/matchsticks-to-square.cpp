class Solution
{
    public:
        bool checkPossible(vector<int> &matchSticks, int index, int &L, int &U, int &R, int &D, int &sum4th)
        {
           	//base case
            if (L > sum4th || U > sum4th || R > sum4th || D > sum4th)
            {
                return false;
            }
            if (index == matchSticks.size())
            {
                if (L == U && L == R && L == D)
                {
                    return true;
                }
                return false;
            }

            int currentElement = matchSticks[index];

            L += currentElement;
            bool option1 = checkPossible(matchSticks, index + 1, L, U, R, D, sum4th);
            L -= currentElement;
            if (option1) return true;

            U += currentElement;
            bool option2 = checkPossible(matchSticks, index + 1, L, U, R, D, sum4th);
            U -= currentElement;
            if (option2) return true;

            R += currentElement;
            bool option3 = checkPossible(matchSticks, index + 1, L, U, R, D, sum4th);
            R -= currentElement;
            if (option3) return true;

            D += currentElement;
            bool option4 = checkPossible(matchSticks, index + 1, L, U, R, D, sum4th);
            D -= currentElement;
            if (option4) return true;

            return false;
        }

    bool makesquare(vector<int> &matchSticks)
    {
        int L = 0, U = 0, R = 0, D = 0;
        int sum = accumulate(matchSticks.begin(), matchSticks.end(), 0);

        int sum4th = sum / 4;
        if (sum % 4 != 0)
        {
            return false;
        }

        sort(matchSticks.rbegin(), matchSticks.rend());	// sort in reverse order means decreasing order

        return checkPossible(matchSticks, 0, L, U, R, D, sum4th);
    }
};