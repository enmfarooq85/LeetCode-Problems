// 1508. Range Sum of Sorted Subarray Sums

// Understand the problem satatement:

// hme aik array of int nums dia gai hy jo ke positive integers pe mushtamil hy. Hme is array ke tmama subarrays ka sum nikalna hy aur usko sorted order me hona chahie. aur jo new subarrays sum bne ge wo n * (n + 1) / 2 times ho ge. Hme is sorted array ko one indexes man ke chlna hy aur left index se right index tk ka sum nikal ke return krna hy. Ans buht bada ho jaye ge jo ke int ki limit se up ho jaye ga isliye sum calculate krte waqt mod lo.

// Understand the problem first:

// Hme nums ke subarrays ke sum nikalne hy aur then sort kr ke sum nikalna hy. Isko krne ke different tareeqe hy. See approach and solution section.

// Approach and Solution:

// simply agr hume subarray nikalne ate hy tu hum log sum bi nikal skte hy aur then usko sort kr lo. aur then pe loop lga ke nika lo sum. Isko min heap se ya maxHeap se bina sorting ke nikal skte hy asani se.

// Brute force approaches:

// #include <iostream>
// #include <algorithm>
// #include <vector>
// using namespace std;

// T.C => O(n^2 * logn)
// S.C => O(n)

// class Solution
// {
// public:
//     int rangeSum(vector<int> &nums, int n, int left, int right)
//     {
//         vector<int> prefixSums(n, 0);
//         vector<vector<int>> subarraySums;
//         vector<int> allSums;

//         for (int start = 0; start < n; start++)
//         {
//             for (int end = start; end < n; end++)
//             {
//                 if (start == end)
//                 {
//                     prefixSums[end] = nums[end];
//                 }
//                 else
//                 {
//                     prefixSums[end] = prefixSums[end - 1] + nums[end];
//                 }
//             }

//             subarraySums.push_back(prefixSums);
//             prefixSums.assign(n, 0);
//         }

//         for (int row = 0; row < n; row++)
//         {
//             for (int col = 0; col < n; col++)
//             {
//                 if (subarraySums[row][col] != 0)
//                 {
//                     allSums.push_back(subarraySums[row][col]);
//                 }
//             }
//         }

//         sort(allSums.begin(), allSums.end());

//         int rangeSum = 0;

//         for (int index = left - 1; index < right; index++)
//         {
//             rangeSum = (rangeSum + allSums[index]) % 1000000007;
//         }

//         return rangeSum;
//     }
// };

// class Solution {
// public:
//     int rangeSum(vector<int>& nums, int n, int left, int right) {
//         vector<int> allSums;

//         for (int start = 0; start < n; start++) {
//             // For every starting index, keep a currentSum.
//             int currentSum = 0;

//             for (int end = start; end < n; end++) {
//                 currentSum += nums[end];
//                 allSums.push_back(currentSum);
//             }
//         }

//         sort(allSums.begin(), allSums.end());

//         int rangeSum = 0;

//         for (int i = left - 1; i < right; i++) {
//             rangeSum = (rangeSum + allSums[i]) % 1000000007;
//         }

//         return rangeSum;
//     }
// };

// int main()
// {

//     Solution s1;

//     vector<int> nums = {1, 2, 3, 4};
//     int n = 4;
//     int left = 1;
//     int right = 5;

//     cout << s1.rangeSum(nums, n, left, right) << endl;
//     return 0;
// }

// Using Min Heap:

// T.C => O(n^2 * log(n))
// S.C => O(n)

// class Solution {
// public:
//     typedef pair<int, int> P;
//     const int MOD = 1000000007;

//     int rangeSum(vector<int>& nums, int n, int left, int right) {
//         priority_queue<P, vector<P>, greater<P>> minHeap;

//         // every single element subarray
//         for (int start = 0; start < n; start++) {
//             minHeap.push({nums[start], start});
//         }

//         int result = 0;
//         // generate subarray sums in sorted order
//         for (int count = 1; count <= right; count++) {
//             P smallest = minHeap.top();
//             minHeap.pop();

//             int currentSum = smallest.first;
//             int endIndex = smallest.second;

//             if (count >= left  && count <= right) {
//                 result = (result + currentSum) % MOD;
//             }

//             int nextIndex = endIndex + 1;
//             if (nextIndex < n) {
//                 int nextSum = currentSum + nums[nextIndex];
//                 minHeap.push({nextSum, nextIndex});
//             }
//         }

//         return result;
//     }
// };
