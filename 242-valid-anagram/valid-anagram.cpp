class Solution {
public:

    
    bool isAnagram(string s , string t) {
    

int freqTable[256] = {0};


for (auto ch : s) {
    freqTable[ch]++;
}

for (auto ch : t) {
    // if(freqTable[ch]==0)
    // {
    //     return false;
    // }
    
    freqTable[ch]--;
}

for (auto elm : freqTable) {
    if (elm !=0) {
     return false;
    }
}

 return true;   


    }
};