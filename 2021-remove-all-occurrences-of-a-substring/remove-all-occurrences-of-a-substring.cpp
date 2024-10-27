class Solution
{
    public:
        void removeOccurrencesRe(string &str, string &part)
        {
            int index = str.find(part);

           	// base case
            if (index == string::npos) return;

            // 1 case hamra
            str.erase(index, part.length());

            //baki recursion ka
            removeOccurrencesRe(str, part);
        }
    string removeOccurrences(string str, string part)
    {
        removeOccurrencesRe(str, part);
        return str;
    }
};