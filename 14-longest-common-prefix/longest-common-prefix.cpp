class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string lastCommon = strs[0];
        for(auto str:strs){
            string currentCommon = "";
            int shortLength = str.length()>=lastCommon.length() ? str.length():lastCommon.length();
            int i = 0;
            while(str[i]==lastCommon[i] && i < shortLength){
                currentCommon.push_back(str[i++]);
            }
            lastCommon = currentCommon;
        }
        cout<<lastCommon<<endl;
        return lastCommon;
    }
};