// 2940. Find Building Where Alice and Bob Can Meet

// Problem statement:

/*
You are given a 0-indexed array heights of positive integers, where heights[i] represents the height of the ith building. If a person is in building i, they can move to any other building j if and only if i < j and heights[i] < heights[j]. You are also given another array queries where queries[i] = [ai, bi]. On the ith query, Alice is in building ai while Bob is in building bi. Return an array ans where ans[i] is the index of the leftmost building where Alice and Bob can meet on the ith query. If Alice and Bob cannot move to a common building on query i, set ans[i] to -1.
*/

// Understand the problem first:

// hme aik zero index base heights array dia gia hy aur kuch queries di gayi hu aur hr query me pehla index alice ko and dosra bob ko represent kr raha hy hmare goal ye hy ke hum no dono ko aik building pe ponchana hy lekin jaha aik bnda kada waha se age hi ja skta hy peche nahi aur ye ke uski building ki height less than honi chahie jaha pe wo dono jaye ge. Query me pehla aur dosra element index ko represent kr raha hy heights me. Agr koi aesi common building nahi milti tu ap log -1 return kre ge. Problem mushkil hy tu ap logo ko isko solve krne ke liye segment tree ke concept ane chahie.

// Approach and Solution:

//  Straight forward approach ye hy ke ap log isko pehle brute force se hl krne ki koshih kre aur then pir segment tree ke concept ate hy tu simple ho jaye gi.

// class Solution {
// public:
//     int findIndex(int aliceIndex, int bobIndex, vector<int>& heights) {
//         if (aliceIndex == bobIndex) {
//             return aliceIndex;
//         }

//         for (int height = min(aliceIndex, bobIndex); height < heights.size();
//              height++) {

//             bool aliceCanReach =
//                 aliceIndex == height ||
//                 (aliceIndex < height && heights[aliceIndex] < heights[height]);

//             bool bobCanReach =
//                 bobIndex == height ||
//                 (bobIndex < height && heights[bobIndex] < heights[height]);

//             if (aliceCanReach && bobCanReach) {
//                 return height;
//             }
//         }

//         return -1;
//     }

//     vector<int> leftmostBuildingQueries(vector<int>& heights,
//                                         vector<vector<int>>& queries) {

//         vector<int> ans;
//         for (int query = 0; query < queries.size(); query++) {
//             ans.push_back(
//                 findIndex(queries[query][0], queries[query][1], heights));
//         }

//         return ans;
//     }
// };

// class Solution {
// public:
//     int findIndex(int aliceIndex, int bobIndex, vector<int>& heights) {
//         if (aliceIndex == bobIndex) {
//             return aliceIndex;
//         }

//         for (int height = aliceIndex + 1; height < heights.size(); height++) {
//             if (aliceIndex < height && heights[aliceIndex] < heights[height]) {
//                 if (bobIndex <= height &&
//                     heights[bobIndex] <= heights[height]) {
//                     return height;
//                 }
//             } else if (bobIndex < height &&
//                        heights[bobIndex] < heights[height]) {
//                 if (aliceIndex <= height &&
//                     heights[aliceIndex] <= heights[height]) {
//                     return height;
//                 }
//             }
//         }

//         return -1;
//     }

//     vector<int> leftmostBuildingQueries(vector<int>& heights,
//                                         vector<vector<int>>& queries) {
//         vector<int> ans;

//         for (int query = 0; query < queries.size(); query++) {
//             ans.push_back(
//                 findIndex(queries[query][0], queries[query][1], heights));
//         }

//         return ans;
//     }
// };

// class Solution {
// public:
//     int findIndex(int aliceIndex, int bobIndex, vector<int>& heights) {
//         // Same building
//         if (aliceIndex == bobIndex) {
//             return aliceIndex;
//         }

//         // Bob can reach Alice
//         if (aliceIndex < bobIndex && heights[aliceIndex] <= heights[bobIndex]) {
//             return bobIndex;
//         }

//         // Alice can reach Bob
//         if (bobIndex < aliceIndex && heights[bobIndex] <= heights[aliceIndex]) {
//             return aliceIndex;
//         }

//         // Neither can directly reach each other.
//         // Search from the rightmost starting position.
//         int start = max(aliceIndex, bobIndex) + 1;

//         int requiredHeight = max(heights[aliceIndex], heights[bobIndex]);

//         for (int i = start; i < heights.size(); i++) {
//             if (heights[i] >= requiredHeight) {
//                 return i;
//             }
//         }

//         return -1;
//     }

//     vector<int> leftmostBuildingQueries(vector<int>& heights,
//                                         vector<vector<int>>& queries) {
//         vector<int> ans;

//         for (int query = 0; query < queries.size(); query++) {
//             ans.push_back(
//                 findIndex(queries[query][0], queries[query][1], heights));
//         }

//         return ans;
//     }
// };

// class Solution {
// public:
//     void buildMaxElementIndexSTree(vector<int>& sTree, vector<int> &heights, int i, int start,
//                     int end) {
//         if (start == end) {
//             sTree[i] = start;
//             return;
//         }

//         int mid = start + (end - start) / 2;
//         buildMaxElementIndexSTree(sTree, heights, 2 * i + 1, start, mid);
//         buildMaxElementIndexSTree(sTree, heights, 2 * i + 2, mid + 1, end);

//         int leftIndex = sTree[2 * i + 1];
//         int rightIndex = sTree[2 * i + 2];

//         sTree[i] = (heights[leftIndex] >= heights[rightIndex]) ? leftIndex: rightIndex;
//     };

//     int findMaxElementIndexFromSTree(vector<int>& sTree, vector<int>& heights,
//                                      int i, int start, int end, int queryStart,
//                                      int queryEnd) {
//         if (queryStart > end || queryEnd < start) {
//             return -1;
//         }

//         if (start >= queryStart && end <= queryEnd) {
//             return sTree[i];
//         }

//         int mid = start + (end - start) / 2;

//         int leftIndex = findMaxElementIndexFromSTree(
//             sTree, heights, 2 * i + 1, start, mid, queryStart, queryEnd);
//         int rightIndex = findMaxElementIndexFromSTree(
//             sTree, heights, 2 * i + 2, mid + 1, end, queryStart, queryEnd);

//         if (leftIndex == -1)
//             return rightIndex;
//         if (rightIndex == -1)
//             return leftIndex;

//         return (heights[leftIndex] >= heights[rightIndex]) ? leftIndex
//                                                            : rightIndex;
//     };

//     vector<int> leftmostBuildingQueries(vector<int>& heights,
//                                         vector<vector<int>>& queries) {
//         int n = heights.size();
//         vector<int> sTree(4 * n, 0);
//         buildMaxElementIndexSTree(sTree, heights, 0, 0, n - 1);
//         vector<int> ans;

//         for (int query = 0; query < queries.size(); query++) {
//             int minIndex = min(queries[query][0], queries[query][1]);
//             int maxIndex = max(queries[query][0], queries[query][1]);

//             if (minIndex == maxIndex) {
//                 ans.push_back(maxIndex);
//             } else if (heights[maxIndex] > heights[minIndex]) {
//                 ans.push_back(maxIndex);
//             } else {
//                 int start = maxIndex + 1;
//                 int end = n - 1;
//                 int bestIndex = INT_MAX;

//                 while (start <= end) {
//                     int mid = start + (end - start) / 2;
//                     int maxElementIndex = findMaxElementIndexFromSTree(
//                         sTree, heights, 0, 0, n - 1, start, mid);

//                     if (heights[maxElementIndex] >
//                         max(heights[minIndex], heights[maxIndex])) {
//                         bestIndex = min(bestIndex, maxElementIndex);
//                         end = mid - 1;
//                     } else {
//                         start = mid + 1;
//                     }
//                 }

//                 if (bestIndex == INT_MAX) {
//                     ans.push_back(-1);
//                 } else {
//                     ans.push_back(bestIndex);
//                 }
//             }
//         }

//         return ans;
//     }
// };
