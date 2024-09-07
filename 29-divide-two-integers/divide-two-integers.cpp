class Solution
{
    public:
        int divide(int dividend, int divisor)
        {
            if (dividend == INT_MIN && divisor == -1)
            {
                return INT_MAX;
            }

            

           	// because we are calulating things after making it positive so its ans will
           	// be INT_MAX + 1 in real bt it will overflow bcz our quetiont is int in
           	// calculation so here we are treating it as edge cases
            if (dividend == INT_MIN && divisor == 1)
            {
                return INT_MIN;
            }

            if(divisor == INT_MIN){
                if(dividend == INT_MIN){
                    return 1;
                }else{
                    return 0;
                }
            }

            if (divisor == 0)
            {
                return INT_MAX;
            }

            int  absDivident = abs(dividend);
            int absDivisor = abs(divisor);

           	// sign
            int sign = (dividend > 0) == (divisor > 0) ? 1 : -1;

            int quetiont = 0;
            while (absDivident > 0 && absDivident >= absDivisor)
            {
                long long tempDivisor = absDivisor;
                int multiplyTimes = 1;
                while (absDivident > (tempDivisor << 1))
                {
                    tempDivisor <<= 1;
                    multiplyTimes <<= 1;
                }
                absDivident -= tempDivisor;
                quetiont += multiplyTimes;
            }

            return quetiont * sign;
        }
};