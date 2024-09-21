class Solution {
public:
    string removeDuplicates(string s) {
    
        int i = 1;
        while (i<s.length()) {
            // cout << s<<endl;
            if(i>= 1 && s.at(i) == s.at(i-1)  )
            {
                s.erase(i-1,2);
                // cout << "erasing the "<<str.at(i)<<"and"<<str.at(i-1)<<endl;
                // i = i>1?i-1:1;
                i--;
            }else 
            {
                i++;
            }
        }
        return s;
    }
};