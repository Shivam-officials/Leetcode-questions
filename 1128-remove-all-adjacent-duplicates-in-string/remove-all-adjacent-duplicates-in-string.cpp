class Solution {
public:
    string removeDuplicates(string s) {
    
      
    string str = "";

    for (auto c : s) {
        if(str.empty())
        {
            str.push_back(c);
        }else if(c== str.back())
        {
            str.pop_back(); 
        }else 
        {
          str.push_back(c);
        }
        
    }
    return str;
    

    }
};