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

    void mergeWithSorting(std::vector<int> &nums, int start, int end)
    {
        int mid = (start + end) / 2;

       	// Using std::vector for temporary arrays (recommended)
        std::vector<int> leftSide
        {
            nums.begin() + start, nums.begin() + mid + 1
        };	// includes element at mid
        std::vector<int> rightSide
        {
            nums.begin() + mid + 1, nums.begin() + end + 1
        };	// includes element at end

       	// Alternative using dynamic arrays (not recommended due to manual memory management)
        /*
        int leftSize = mid - start + 1;
        int rightSize = end - mid;
        int* leftSide = new int[leftSize];
        int* rightSide = new int[rightSize];

       	// Copy elements into leftSide and rightSide
        std::copy(nums.begin() + start, nums.begin() + mid + 1, leftSide);
        std::copy(nums.begin() + mid + 1, nums.begin() + end + 1, rightSide);
        */

        int li = 0, ri = 0, index = start;

       	// Merging process
        while (li < leftSide.size() && ri < rightSide.size())
        {
            if (leftSide[li] < rightSide[ri])
            {
                nums[index++] = leftSide[li++];
            }
            else
            {
                nums[index++] = rightSide[ri++];
            }
        }

       	// Copy any remaining elements from leftSide
        while (li < leftSide.size())
        {
            nums[index++] = leftSide[li++];
        }

       	// Copy any remaining elements from rightSide
        while (ri < rightSide.size())
        {
            nums[index++] = rightSide[ri++];
        }

       	// If using dynamic arrays, free the memory after merging
        /*
        delete[] leftSide;
        delete[] rightSide;
        */
    }

    void mergeSort(vector<int> &nums, int start, int end)
    {
        if (start >= end) return;	// Base case: Single element is already sorted

        int mid = (start + end) / 2;

       	// Recursively sort left and right halves
        mergeSort(nums, start, mid);
        mergeSort(nums, mid + 1, end);

       	// Merge the sorted halves in place
        mergeWithSorting(nums, start,  end);
    }

    vector<int> sortArray(vector<int> &nums)
    {
        mergeSort(nums, 0, nums.size() - 1);
        return nums;
    }
};