class Solution {
public:

    
void solve_shivam(vector<string> & ans, int n, int openingParenthesis,int closingParenthesis,string &outputString){
    if(closingParenthesis > openingParenthesis) return;
    if(closingParenthesis > n || openingParenthesis > n) return;
    // cout << "it runned"<<endl;
    if(openingParenthesis ==n && closingParenthesis ==n){
        ans.push_back(outputString);
        return;
    }
    // cout << "it runned2"<<endl;


    // cout << "it runned3"<<endl;
    outputString.push_back('(');
    solve_shivam(ans,n, openingParenthesis+1, closingParenthesis, outputString);
    outputString.pop_back();

    outputString.push_back(')');
    solve_shivam(ans,n, openingParenthesis, closingParenthesis + 1, outputString);
    outputString.pop_back();
    return;
}
    vector<string> generateParenthesis(int n) {
     vector<string>ans ;
     string outputString = "(";
    solve_shivam(ans,n,1,0,outputString);

    return ans;
 
    }
};