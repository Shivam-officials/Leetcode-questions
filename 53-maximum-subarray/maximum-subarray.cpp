class Solution {
public:
    int maximumSubArraySumDnC(vector<int>&nums, int start ,int end){
    // base case
    if(start>=end) return nums[start];
    int mid= ( start + end )/2 ;
    int maxLeftSum = maximumSubArraySumDnC(nums, start, mid);
    int maxRightSum = maximumSubArraySumDnC(nums, mid+1, end);

    int maxLeftBorderSum = INT_MIN, maxRightBorderSum = INT_MIN;
    int leftBorderSum = 0, rightBorderSum = 0;

    for (int i = mid; i >= start; i--) {
        leftBorderSum += nums[i];
        // if(leftBorderSum>maxLeftBorderSum){ maxLeftBorderSum = leftBorderSum;};
        maxLeftBorderSum = max(maxLeftBorderSum,leftBorderSum);
    }

    for (int i = mid+1; i <= end; i++) {
        rightBorderSum += nums[i];
        // if(rightBorderSum>maxRightBorderSum){ maxRightBorderSum = rightBorderSum; };
        maxRightBorderSum = max(maxRightBorderSum,rightBorderSum);
    }

    int crossBorderSum = maxLeftBorderSum + maxRightBorderSum;
    // cout << maxLeftSum<<" "<< maxLeftBorderSum<<" "<<maxRightBorderSum <<" "<<maxRightSum <<endl;
    return max(maxLeftSum,max(maxRightSum,crossBorderSum));

}

int maxSubArray(vector<int>& nums) {
      return maximumSubArraySumDnC(nums,0,nums.size()-1) ;
}
};