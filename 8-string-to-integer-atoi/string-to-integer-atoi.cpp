class Solution
{
    public:

        int myAtoi(string s)
        { 
            int i = 0;
           // ignoring white space
           while(s[i]==' '){
            i++;
           }

            // sign cheking
            int sign = 1;
           if(s[i]=='-' || s[i]=='+'){
            sign = s[i]=='-' ? -1 : 1;
            i++;
           }

           // making the number
           int num = 0;
           while(i<s.length() && isdigit(s[i])){
            int digit = s[i]-'0';
            // cheking overflow
            if(num > (INT_MAX - digit)/10){
                return sign == -1 ? INT_MIN : INT_MAX;
            }
            num = (num * 10) + digit;
            i++;
           }

            return sign * num;

        

        }
};