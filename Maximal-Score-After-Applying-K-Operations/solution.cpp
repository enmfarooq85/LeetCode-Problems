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

// hme aik array of int nums dia hua hy hum logo ne kuch steps perform kr ke maximum score nikalna hy.

// Approach and Solution:

// Acha is me kuch cheeze hy jin se ap log pans skte hy aik ye ke in steps me jo pehla step hy wo agr ap usko dihan se dekhe hr index wo condition satisfy kr raha hy. Tu ye condition lgane ki zaroorat nahi hy. Then pir bs yahi hy ke hum max score chahie tu maximum value ko dond kr add krne ki koshih kr ge. Mene pehle two approached pure brute force se bnai hy but ye TLE de rahi hy. Lekin teesri approach heap se bnai hy.

// class Solution {
// public:
//     long long maxKelements(vector<int>& nums, int k) {
//         int n = nums.size();
//         long long score = 0;

//         while (k > 0) {
//             int maximum = INT_MIN;
//             int index = 0;

//             for (int i = 0; i < n; i++) {
//                 if (nums[i] > maximum) {
//                     maximum = nums[i];
//                     index = i;
//                 }
//             }

//             score += maximum;
//             nums[index] = ceil(nums[index] / 3.0);

//             k--;
//         }

//         return score;
//     }
// };

// class Solution {
// public:
//     long long maxKelements(vector<int>& nums, int k) {
//         int n = nums.size();
//         long long score = 0;

//         while (k > 0) {
//             sort(nums.begin(), nums.end());

//             score += nums.back();
//             nums[n  - 1] = ceil(nums[n  - 1] / 3.0);

//             k--;
//         }

//         return score;
//     }
// };

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
