class Solution {
public:

    
    bool isAnagram(string s , string t) {
    

vector<int> freq(256,0);


for (auto ch : s) {
    freq[ch]++;
}

for (auto ch : t) {
    // if(freq[ch]==0)
    // {
    //     return false;
    // }
    
    freq[ch]--;
}

for (auto elm : freq) {
    if (elm !=0) {
     return false;
    }
}

 return true;   


    }
};