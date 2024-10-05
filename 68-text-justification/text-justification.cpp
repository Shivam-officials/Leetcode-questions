class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
         vector<string> currentLine;
  int totalNosOfChars = 0, totalNoOfSpaces = 0;

  vector<string> ans;
  if(words.size()==1){
    int spacesToAdd = maxWidth-words[0].size();
    while(spacesToAdd--) words[0] += " ";
    return words;
  }
  //  for (int i = 0; i<words.size();) {
  int i = 0;
  while (i < words.size()) {
    // add the strings into current untill it can have maximum of words with one
    // space minimum them
    while (i<words.size() && totalNoOfSpaces + totalNosOfChars + words[i].length() <= maxWidth) {
      currentLine.push_back(words[i]);
      totalNosOfChars += words[i].length();
      totalNoOfSpaces = currentLine.size();
      i++;
    }

    // calulating the spaces to insert
    int spacesToAddLeft = maxWidth - totalNosOfChars;

    if (i<words.size() && currentLine.size() > 1) {
      int evenlySpacesToAdd = spacesToAddLeft / (currentLine.size() - 1);
      int oddSpacesToAdd = spacesToAddLeft % (currentLine.size() - 1);

      // inserting spaces evenly
      for (int j = 0; j < currentLine.size() - 1; j++) {
        string &currentWord = currentLine[j];
        for (int j = 0; j < evenlySpacesToAdd; j++) {
          currentWord += " ";
        }
      }

      // add odd spaces
      int oddSpacesIndex = 0;
      while (oddSpacesToAdd--) {
        currentLine[oddSpacesIndex++] += " ";
      }
    } else if(currentLine.size() == 1)     // when the current line has only one word in the line
    {
      // add spaces to the right
      int leftSpaccesToAdd = maxWidth - totalNosOfChars, indexForSpace = 0;
      while (leftSpaccesToAdd--) {
        currentLine[indexForSpace] += " ";
      }
    } else 
    {
        int totalNoOFcharsInLastLine = 0;
        for (int j = 0; j<currentLine.size()-1; j++) {
            currentLine[j] += " ";
            totalNoOFcharsInLastLine += currentLine[j].length();
        }
        totalNoOFcharsInLastLine+= currentLine.back().length();

        int spacesLeftToAdd = maxWidth - totalNoOFcharsInLastLine;
        while(spacesLeftToAdd--)
        {
            currentLine.back() += " ";
        }

    }

    // putting the currenline strings into ans
    string ansString = "";
    for (auto entry : currentLine) {
      ansString += entry;
    }
    ans.push_back(ansString);

    // clearing the data for next round
    currentLine.clear();
    totalNoOfSpaces = 0;
    totalNosOfChars = 0;
    // cout << "i is at"<<i<<endl;
    // cout << ans.back()<<endl;
    // break;
  }
  //    for (auto word : ans) {
  //    cout << word<<endl;
  //    }
  return ans;
    }
};