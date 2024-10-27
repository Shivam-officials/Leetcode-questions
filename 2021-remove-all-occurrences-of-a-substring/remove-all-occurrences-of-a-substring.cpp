class Solution
{
    public:
        void removeOccurrencesRe(string &str, string &part)
        {
           	// base case
            if (str.find(part) == string::npos) return;

           	// 1 case hum krenge 
            int index = str.find(part);
            str.erase(index, part.length());

            removeOccurrencesRe(str, part);
        }
    string removeOccurrences(string str, string part) {
        removeOccurrencesRe(str,part);
        return str;
    }
};