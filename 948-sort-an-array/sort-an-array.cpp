class Solution
{
    public:

        void merge(vector<int> &nums, int start, int mid, int end)
        {
           	// int i = start, j = mid + 1;
           	// while(i <= mid && j<=end){
           	//     if(nums[i]>nums[j]){
           	//         for(int k = j; k>i; k--){
           	//             swap(nums[k],nums[k-1]);
           	//         }
           	//         j++;
           	//         mid++;
           	//     }

           	//         i++;

           	// }

           	// using shifting instead of swap bcz it less overhead and more fast in performance  .. still not enough
           	// int i = start, j = mid + 1;
           	// while(i<=mid && j<=end){
           	//     if(nums[i]>nums[j]){
           	//         int index = j;
           	//         int temp = nums[j];
           	//         while(index>i){
           	//             nums[index--] = nums[index-1];
           	//         }

           	//         nums[i] = temp;
           	//         j++;
           	//         mid++;
           	//     }
           	//     i++;
           	// }
        }
    void merge2(vector<int> &nums, int start, int mid, int end)
    {
        int sizeOfArray = end - start + 1;
        int gap = sizeOfArray / 2 + sizeOfArray % 2;

        while (gap > 0)
        {
            int i = start;
            int j = i + gap;
            while (j <= end)
            {

                if (nums[j] < nums[i])
                {
                    swap(nums[j], nums[i]);
                }
                j++;
                i++;
            }
            gap = gap > 1 ? (gap / 2 + gap % 2) : 0;
        }
    }

    

    void mergeSort(vector<int> &nums, int start, int end)
    {
        if (start >= end) return;	// Base case: Single element is already sorted

        int mid = (start + end) / 2;

       	// Recursively sort left and right halves
        mergeSort(nums, start, mid);
        mergeSort(nums, mid + 1, end);

       	// Merge the sorted halves in place
        merge2(nums, start, mid, end);
    }

    vector<int> sortArray(vector<int> &nums)
    {
        mergeSort(nums, 0, nums.size() - 1);
        return nums;
    }
};