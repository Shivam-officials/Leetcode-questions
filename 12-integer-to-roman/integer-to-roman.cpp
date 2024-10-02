class Solution
{
    public:
        string intToRoman(int num)
        {
        	// Define pairs of integer values and their corresponding Roman numeral representations
            vector<pair<int, string>> values = {
		{
                    1000,
                    "M" },
                {
                    900,
                    "CM" },
                {
                    500,
                    "D" },
                {
                    400,
                    "CD" },
                {
                    100,
                    "C" },
                {
                    90,
                    "XC" },
                {
                    50,
                    "L" },
                {
                    40,
                    "XL" },
                {
                    10,
                    "X" },
                {
                    9,
                    "IX" },
                {
                    5,
                    "V" },
                {
                    4,
                    "IV" },
                {
                    1,
                    "I" }
            };

            string result;

           	// Loop through the values array and construct the Roman numeral string
            for (const auto &romanMap: values)
            {
                while (num >= romanMap.first)
                {
                    result += romanMap.second;	// Append the Roman numeral to the result
                    num -= romanMap.first;	// Subtract the value from num
                }
            }

            return result;	// Return the constructed Roman numeral string
        }
};