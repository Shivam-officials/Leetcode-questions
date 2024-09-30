class Solution
{
    public:

        int myAtoi(string s)
        {
            int number = 0;
            int sign = 1;
            bool numStarted = false;	// Flag to check when to start processing digits

            for (auto ch: s)
            {
               	// Skip leading spaces
                if (ch == ' ' && !numStarted)
                {
                    continue;
                }

               	// Handle sign if it's the first non-space character
                if (ch == '-' && !numStarted)
                {
                    sign = -1;
                    numStarted = true;	// Mark that we've started processing
                    continue;
                }
                else if (ch == '+' && !numStarted)
                {
                    numStarted = true;
                    continue;
                }

               	// Stop if non-digit characters are found (including alphabets and '.')
                if (ch<'0' || ch > '9')
                {
                    break;
                }

               	// Convert char to digit
                int digit = ch - '0';

               	// Overflow check before processing the next digit
                if (number > (INT_MAX - digit) / 10)
                {
                    return sign == 1 ? INT_MAX : INT_MIN;
                }

               	// Accumulate the digit into the number
                number = number *10 + digit;
                numStarted = true;	// Mark that we've started processing
            }

            return sign * number;
        }
};