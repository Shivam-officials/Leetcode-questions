class Solution
{
    public:
        int timeTakenForCurrentGarbageType(vector<string> &garbage, vector<int> &travel, char currentGarbageType)
        {
            int timeTakenForGarbageCollection = 0;

            int distanceCovered = 0;
            int distanceCoveredForCurrentGarbageType = 0;

            for (int i = 0; i < garbage.size(); i++)
            {

                string houseGarbage = garbage[i];

                int currentHouseGarbageCollectionTime = 0;

               	// total distance covered till now 
                if (i > 0)
                {
                    distanceCovered += travel[i - 1];
                }

               	// time taken for collecting garbage from house
                for (auto garbageType: houseGarbage)
                {
                    if (garbageType == currentGarbageType)
                    {
                        currentHouseGarbageCollectionTime++;
                    }
                }

                if (currentHouseGarbageCollectionTime > 0)
                {
                    timeTakenForGarbageCollection += currentHouseGarbageCollectionTime;
                    distanceCoveredForCurrentGarbageType = distanceCovered;
                }
            }
            return distanceCoveredForCurrentGarbageType + timeTakenForGarbageCollection;
        }

    int garbageCollection(vector<string> &garbage, vector<int> &travel)
    {

        string garbageType = "MPG";

        int ans = 0;
        for (auto currentGarbageType: garbageType)
        {
            ans += timeTakenForCurrentGarbageType(garbage, travel, currentGarbageType);
        }
        return ans;
    }
};