class Solution
{
    public:

        int garbageCollection(vector<string> &garbage, vector<int> &travel)
        {

           	//last spot
            int lastStopForP = 0;
            int lastStopForM = 0;
            int lastStopForG = 0;

           	// timeForDistanceCovering 
            int timeForTruckP = 0;
            int timeForTruckM = 0;
            int timeForTruckG = 0;

            int timeTakenForPickup = 0;
            for (int i = 0; i < garbage.size(); i++)
            {
                string currentHouseGarbage = garbage[i];
                timeTakenForPickup += currentHouseGarbage.length();

                if (currentHouseGarbage.find('P') != string::npos)
                {
                    lastStopForP = i;
                }
                if (currentHouseGarbage.find('M') != string::npos)
                {
                    lastStopForM = i;
                }
                if (currentHouseGarbage.find('G') != string::npos)
                {
                    lastStopForG = i;
                }
            }

           	// calculating the time cost for every truck

           	// truck p
            for (int i = 0; i < lastStopForP; i++)
            {
                timeForTruckP += travel[i];
            }

           	// truck p
            for (int i = 0; i < lastStopForM; i++)
            {
                timeForTruckM += travel[i];
            }

           	// truck p
            for (int i = 0; i < lastStopForG; i++)
            {
                timeForTruckG += travel[i];
            }

            return timeTakenForPickup + timeForTruckM + timeForTruckG + timeForTruckP;
        }
};