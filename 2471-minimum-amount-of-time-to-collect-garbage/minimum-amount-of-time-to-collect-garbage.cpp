class Solution
{
    public:

        int garbageCollection(vector<string> &garbage, vector<int> &travel)
        {

           	// picktimes
            int pickTimeForP = 0;
            int pickTimeForM = 0;
            int pickTimeForG = 0;

           	// lastStops
            int lastStopForP = 0;
            int lastStopForM = 0;
            int lastStopForG = 0;

           	// timeForDistanceCovering 
            int timeForTruckP = 0;
            int timeForTruckM = 0;
            int timeForTruckG = 0;

            for (int i = 0; i < garbage.size(); i++)
            {

                string garbageInHouse = garbage[i];

                for (auto garbageType: garbageInHouse)
                {
                    if (garbageType == 'M')
                    {
                        pickTimeForM++;
                        lastStopForM = i;
                    }
                    else if (garbageType == 'G')
                    {
                        pickTimeForG++;
                        lastStopForG = i;
                    }
                    else
                    {
                        pickTimeForP++;
                        lastStopForP = i;
                    }
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

            return timeForTruckG + timeForTruckM + timeForTruckP + pickTimeForG + pickTimeForM + pickTimeForP;
        }
};