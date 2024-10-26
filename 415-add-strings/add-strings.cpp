class Solution {
public:

    void addStringRecursion(string &str1,string &str2,int carry,int index, string &ans){
    int l1 = str1.size()-1;
    int l2 = str2.size()-1;
    // base case
    if (l1-index <0 && l2-index < 0 && carry<=0 ) {
    return;
    }

    // 1 case
    
    int temp1 = l1-index >= 0 ? str1[l1-index]-'0':0 ;
    int temp2 = l2-index >= 0 ? str2[l2-index]-'0' :0;
    int digit = temp1 + temp2 + carry;
    carry = digit/10;
    // ans = ans*10 + (digit%10);
    ans.push_back (digit%10 + '0');
    // cout << ans<<endl;
    addStringRecursion(str1, str2,carry, index+1, ans);
}
    string addStrings(string num1, string num2) {
    string ans = "";
    addStringRecursion(num1,num2,0,0,ans);
    reverse(ans.begin(),ans.end());
    return ans;
    }
};