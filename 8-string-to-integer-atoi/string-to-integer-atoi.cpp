class Solution
{
    public:

        int myAtoi(string s)
        {
            int num = 0, i = 0, sign = 1;	// Initialize variables: number, index, and sign (default +1 for positive)

           	// Skip leading whitespace
            while (s[i] == ' ')
            {
                i++;
            }

           	// Check for sign characters '+' or '-'
            if (i < s.size() && (s[i] == '-' || s[i] == '+'))
            {
                sign = (s[i] == '-') ? -1 : 1;
                i++;
            }

           	// Process each digit in the string
            while (i < s.size() && isdigit(s[i]))
            {
                int digit = s[i] - '0';	// Convert char to digit

               	// Overflow check: Ensure that num *10 + digit does not overflow
                if (num > (INT_MAX - digit) / 10)
                {
                    return (sign == 1) ? INT_MAX : INT_MIN;	// Return INT_MAX or INT_MIN depending on the sign
                }

               	// Accumulate the digit into the number
                num = num *10 + digit;
                i++;
            }

           	// Return the final number multiplied by its sign
            return num * sign;
        }
};