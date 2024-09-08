class Solution
{
    public:
        int singleNonDuplicate(vector<int> &v)
        {
            
            int start = 0;
            int end = v.size() - 1;
            int mid;

            if(v.size() == 1){
                return v[0];
            }

            while (start <= end)
            {
                mid = start + (end - start) / 2;
                int firstIndex;

               	// its not in the pair 
                if ((mid > 0) && (v[mid] != v[mid - 1]) && (mid < v.size() - 1) &&
                    (v[mid] != v[mid + 1]))
                {
                    return v[mid];
                }

               	// edge cases to avoid out of bound error if its on 0th index 
                if (mid == 0 && v[mid] != v[mid + 1])
                {
                    return v[0];
                }

               	// edge case to avoid out of bound error if its on last index 
                if (mid == v.size() - 1 && v[mid] != v[mid - 1])
                {
                    return v[v.size() - 1];
                }

               	// finding the first index of pair
                if (v[mid] == v[mid + 1])
                {
                    firstIndex = mid;
                }
                else
                {
                    firstIndex = mid - 1;
                }

               	/// shift start / end accordign to condition
                if (firstIndex & 1)
                {
                   	// end = mid-1;
                    end = firstIndex - 1;
                }
                else
                {
                   	// start = mid+1;
                    start = firstIndex + 2;
                }
            }

            return -1;
        }
};