// 2530. Maximal Score After Applying K Operations

// Problem statement:

/*
You are given a 0-indexed integer array nums and an integer k. You have a starting score of 0.

In one operation:

choose an index i such that 0 <= i < nums.length,
increase your score by nums[i], and
replace nums[i] with ceil(nums[i] / 3).
Return the maximum possible score you can attain after applying exactly k operations.

The ceiling function ceil(val) is the least integer greater than or equal to val.
*/

// Understand the problem first:

// hme aik array of int nums dia hua hy hum logo ne kuch steps perform kr ke maximum score nikalna hy. It is not too straight forward for now. I am totally cooked at this moment.

// Approach and Solution:

// Ye cheeze subh discuss kre ge.

// class Solution {
// public:
//     long long maxKelements(vector<int>& nums, int k) {
//         int n = nums.size();
//         long long score = 0;

//         priority_queue<int> maxHeap;

//         for (int i = 0; i < n; i++) {
//             maxHeap.push(nums[i]);
//         }

//         while (k > 0) {
//             int maxTopMost = maxHeap.top();
//             maxHeap.pop();

//             score += maxTopMost;
//             maxTopMost = ceil(maxTopMost / 3.0);
//             maxHeap.push(maxTopMost);
//             k--;
//         }

//         return score;
//     }
// };
