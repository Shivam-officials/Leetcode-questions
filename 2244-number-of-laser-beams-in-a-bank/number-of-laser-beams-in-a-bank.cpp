class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        
       int totalBeams = 0;

       int numberOfSecurityDevicesInLastRow = 0;

       for (int rowIndex = 0; rowIndex< bank.size(); rowIndex++) {

        string currentRow = bank[rowIndex];
        
        int currentSecurityDeviceNumbers = 0;
        for (auto cell : currentRow) {
            if (cell == '1') {
                currentSecurityDeviceNumbers++;
            }
        }

        if (currentSecurityDeviceNumbers>0 ) {
           if (rowIndex>0) {
           totalBeams += currentSecurityDeviceNumbers*numberOfSecurityDevicesInLastRow;
           }
           numberOfSecurityDevicesInLastRow = currentSecurityDeviceNumbers;
        }
       }
 return totalBeams;
    }
};