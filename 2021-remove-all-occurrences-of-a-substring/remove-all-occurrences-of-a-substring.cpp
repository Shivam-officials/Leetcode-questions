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
            // string st_left = str.substr(0, index);
            // string st_right = str.substr(index + part.length());
            // str = st_left + st_right;

           	//baki recursion ka
            removeOccurrencesRe(str, part);
        }
    string removeOccurrences(string str, string part)
    {
        while(str.find(part)!=string::npos){
            str.erase(str.find(part),part.length());
        }
        return str;
    }
};