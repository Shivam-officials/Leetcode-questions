class Solution
{
    public:
        int majorityElement(vector<int> &nums)
        {
            vector<int>v{nums};
            int vote = 0;
            int majority = v[0];	// safe to make the first element the majority alothougu it will be	//automatically set in the first iteration bcz of zero votes

            for (auto item: v)
            {
                if (vote == 0)
                {
                    vote++;
                    majority = item;
                }
                else if (majority == item)
                {
                    vote++;
                }
                else
                {
                    vote--;
                }
            }

            return majority;
        }
};