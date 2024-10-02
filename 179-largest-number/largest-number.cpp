class Solution
{
    public:
        string largestNumber(vector<int> &nums)
        {
           	// Convert integers to strings
            vector<string> numString;

           	// Reserve space to avoid multiple reallocations for efficiency
            numString.reserve(nums.size());

           	// Convert each integer in the input vector 'nums' to a string and store it in 'numString'
            for (int num: nums)
            {
                numString.push_back(to_string(num));
            }

           	// Sort the strings using a custom comparator that compares concatenated results
           	// For example, for "9" and "34", compare "934" vs "349" and sort accordingly
            sort(numString.begin(), numString.end(), [](const string &a, const string &b)
            {
                return a + b > b + a;
	});

           	// If the largest number after sorting is "0", that means all numbers were zero
           	// Hence, return "0" to handle the edge case of all zeros
            if (numString[0] == "0")
                return "0";

           	// Use the 'accumulate' function to concatenate all sorted strings into one large string
           	// Start with an empty string as the initial value
            return accumulate(numString.begin(), numString.end(), string());
        }
};