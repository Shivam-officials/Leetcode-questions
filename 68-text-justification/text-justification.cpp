class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
  vector<string> ans, currentLine;
  int totalNumberOfCharsInCurrentline = 0;

  // Loop through each word in the input list
  for (auto currentWord : words) {
    int currentNeededNumberOfSpaces = currentLine.size();

    // Check if adding the current word would exceed the max width
    if (totalNumberOfCharsInCurrentline + currentNeededNumberOfSpaces + currentWord.length() > maxWidth) {
      int totalSpacesLeft = maxWidth - totalNumberOfCharsInCurrentline;
      int evenSpaces = totalSpacesLeft / max(1, (int)currentLine.size() - 1);
      int oddSpaces = totalSpacesLeft % max(1, (int)currentLine.size() - 1);

      // Distribute spaces between words for justification
      for (int i = 0; i < currentLine.size() - 1; i++) {
        string &currentLineWords = currentLine[i];
        currentLineWords += string(evenSpaces, ' ');  // Add even spaces

        // Add extra space if needed
        if (oddSpaces > 0) {
          currentLineWords += " ";
          oddSpaces--;
        }
      }

      // Handle single-word lines by adding all remaining spaces
      if (currentLine.size() == 1) {
        currentLine[0] += string(totalSpacesLeft, ' ');
      }

      // Combine the justified line and store it in the result
      ans.push_back(accumulate(currentLine.begin(), currentLine.end(), string()));

      // Reset for next line
      currentLine.clear();
      totalNumberOfCharsInCurrentline = 0;
    }

    // Add current word to the line and update char count
    currentLine.push_back(currentWord);
    totalNumberOfCharsInCurrentline += currentWord.length();
  }

 // Handle the last line (left-justified)
  for(auto &lastLineWord:currentLine) lastLineWord += " ";
  string leftJustifiedString = accumulate(currentLine.begin(), currentLine.end(), string());
  leftJustifiedString.pop_back(); // Remove the  space from the last word which added above in for range loop


  // Add remaining spaces to the end of the last line
  leftJustifiedString += string(maxWidth - leftJustifiedString.size(), ' ');
  ans.push_back(leftJustifiedString);

  return ans;
    }
};