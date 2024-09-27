class Solution
{
    public:
        string longestCommonPrefix(vector<string> &strs) {
    if (strs.empty()) return "";  // Handle empty input
    
    string lastCommon = strs[0];  // Start with the first string as the common prefix
    
    for (const auto& str : strs) {
        string currentCommon = "";
        int shortLength = min(str.length(), lastCommon.length());
        int i = 0;
        
        // Compare characters until they mismatch or reach the end of the shorter string
        while (i < shortLength && str[i] == lastCommon[i]) {
            currentCommon.push_back(str[i]);
            i++;
        }
        
        // Update the last common prefix
        lastCommon = currentCommon;
        
        // If no common prefix remains, break early
        if (lastCommon.empty()) break;
    }
    
    return lastCommon;
}

};