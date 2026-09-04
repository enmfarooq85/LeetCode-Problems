// 2593. Find Score of an Array After Marking All Elements

// Problem statement:

/*
You are given an array nums consisting of positive integers.

Starting with score = 0, apply the following algorithm:

Choose the smallest integer of the array that is not marked. If there is a tie, choose the one with the smallest index.
Add the value of the chosen integer to score.
Mark the chosen element and its two adjacent elements if they exist.
Repeat until all the array elements are marked.
Return the score you get after applying the above algorithm.
*/

// Understand the problem first:

// hme aik array of nums positive integer dia gia hy jis ko hum ne aik pre definced steps ke zariye solved krna hy. I think step explain krne ki zaroorat nahi.

// Approach and Solution:

// Simply jesa bola gia hy wesa kr do. Lekin yaha pe inititally maybe ap ko aik cheez preshan kre gi ke hum log kese smallest index wala choose kre ge aur two minimum number hoe tu. First ap aik minimum number ko man ke chle aur solve kre. Then is case ko dekhe. Mje 100% confirm ke ap is trah ka code likhe ge ke ye cheeze automatically handle ho jaye gi. Then pir isko brute force O(n^2) se bi solve kr skte hy aur then pir sort kr ke TC ko mazeed km kr skte hy aur then heap se bi efficient kr skte hy but not more. Lekin heap wali approach apko production me help kre gi.

// #include "iostream"
// #include "vector"
// #include "climits"
// using namespace std;

// Brute Force:

// T.C => O(n^2)
// S.C => O(1)

// class Solution {
// public:
//     long long findScore(vector<int>& nums) {
//         long long score = 0;
//         int n = nums.size();

//         int totalMarked = 0;
//         while (totalMarked < n) {
//             int smallestInteger = INT_MAX;
//             int smallestIndex = INT_MAX;

//             for (int i = 0; i < n; i++) {
//                 if (nums[i] != -1 && nums[i] < smallestInteger) {
//                     smallestInteger = nums[i];
//                     smallestIndex = i;
//                 }
//             }

//             score += smallestInteger;
//             nums[smallestIndex] = -1;
//             totalMarked += 1;

//             // Mark right neighbor if it wasn't already marked
//             if (smallestIndex + 1 < n) {
//                 if (nums[smallestIndex + 1] != -1) {
//                     totalMarked += 1;
//                     nums[smallestIndex + 1] = -1;
//                 }
//             }

//             // Mark left neighbor if it wasn't already marked
//             if (smallestIndex - 1 >= 0) {
//                 if (nums[smallestIndex - 1] != -1) {
//                     totalMarked += 1;
//                     nums[smallestIndex - 1] = -1;
//                 }
//             }
//         }

//         return score;
//     }
// };

// Brute Force + Sorting

// T.C => O(n log (n))
// S.C => O(n)

// class Solution {
// public:
//     long long findScore(vector<int>& nums) {
//         int n = nums.size();
//         vector<pair<int, int>> arr;

//         for (int i = 0; i < n; i++) {
//             arr.push_back({nums[i], i});
//         }

//         sort(arr.begin(), arr.end());

//         vector<bool> marked(n, false);

//         long long score = 0;

//         for (auto& [value, index] : arr) {
//             if (marked[index])
//                 continue;

//             score += value;
//             marked[index] = true;

//             if (index - 1 >= 0) {
//                 marked[index - 1] = true;
//             }

//             if (index + 1 < n) {
//                 marked[index + 1] = true;
//             }
//         }

//         return score;
//     }
// };

// O(n log (n))
// S.C => O(n)

// class Solution {
// public:
//     typedef pair<int, int> P;
//     long long findScore(vector<int>& nums) {
//         int n = nums.size();
//         priority_queue<P, vector<P>, greater<P>> minHeap;

//         for (int i = 0; i < n; i++) {
//             minHeap.push({nums[i], i});
//         }

//         vector<bool> marked(n, false);

//         long long score = 0;
//         while (!minHeap.empty()) {

//             auto [value, index] = minHeap.top();
//             minHeap.pop();

//             if (marked[index])
//                 continue;

//             score += value;
//             marked[index] = true;

//             if (index - 1 >= 0) {
//                 marked[index - 1] = true;
//             }

//             if (index + 1 < n) {
//                 marked[index + 1] = true;
//             }
//         }

//         return score;
//     }
// };

// int main()
// {
//     Solution s;
//     vector<int> nums = {2, 1, 3, 4, 5, 2};
//     cout << s.findScore(nums) << endl;

//     return 0;
// }
