class Solution
{
    public:
        string largestNumber(vector<int> &nums)
        {
            vector<string> numString;

            for (auto elm: nums)
            {
                numString.push_back(to_string(elm));
            }
           	// cout <<  largestNumber(nums);

            sort(numString.begin(), numString.end(), [](string a, string b)->bool
            {
               	// return a>b;
                string t1 = a + b;
                string t2 = b + a;
                return t1 > t2;
	});
            if(numString[0]=="0") return "0";

            string str ="";
            for(auto elm:numString){
                str += elm;
            }
            return str;
        }
};