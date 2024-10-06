class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
 vector<string>ans;
  vector<string>currentLine;
  int totalNumberOfCharsInCurrentline = 0;
  for (auto currentWord : words) {

    int currentNeededNumberOfSpaces = currentLine.size();

    if (totalNumberOfCharsInCurrentline + currentNeededNumberOfSpaces + currentWord.length() > maxWidth) {
      
      int totalSpacesLeft = maxWidth-totalNumberOfCharsInCurrentline;
      int evenSpaces = totalSpacesLeft/max(1,(int)currentLine.size()-1);
      int oddSpaces = totalSpacesLeft%max(1,(int)currentLine.size()-1);

      // adding the spaces for justification

      for (int i = 0; i< currentLine.size()-1; i++) {

      string &currentLineWords = currentLine[i];

       for (int j = 0; j<evenSpaces; j++) {
        currentLineWords+= " ";
       }
       
       if(oddSpaces>0)
       {
        currentLineWords+=" ";
        oddSpaces--;
       }
       
      }

      // when only element is there in currentline
      if(currentLine.size()==1)
      {
        while (totalSpacesLeft--) {
         currentLine[0] += " ";
        }
      }
       
       // after making the string justified in the vector store it in the string and push to ans
       string justifiedString = accumulate(currentLine.begin(),currentLine.end(),string());
       ans.push_back(justifiedString);

      // reset the values for next line
      currentLine.clear();
      totalNumberOfCharsInCurrentline = 0;

    }
   
      // push the current word into current line and increase it totalChars 
      currentLine.push_back(currentWord);
      totalNumberOfCharsInCurrentline += currentWord.length();  
    
    
  }

  // handling last line bcz that line will never be crossing the maxwidth thats why its a last line and we have to make it left justified
    string leftJustifiedString = "";
    for (auto word : currentLine) {
      leftJustifiedString += word + " ";
    }

    // last word does not need extraspace
    leftJustifiedString.pop_back();

    int spacesToAddForLeftJustification = maxWidth - leftJustifiedString.size();
    while (spacesToAddForLeftJustification--) {
      leftJustifiedString += " ";
    }

    ans.push_back(leftJustifiedString);

    return ans;
    }
};