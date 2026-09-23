// 2940. Find Building Where Alice and Bob Can Meet

// Problem statement:

/*
You are given a 0-indexed array heights of positive integers, where heights[i] represents the height of the ith building. If a person is in building i, they can move to any other building j if and only if i < j and heights[i] < heights[j]. You are also given another array queries where queries[i] = [ai, bi]. On the ith query, Alice is in building ai while Bob is in building bi. Return an array ans where ans[i] is the index of the leftmost building where Alice and Bob can meet on the ith query. If Alice and Bob cannot move to a common building on query i, set ans[i] to -1.
*/

// Understand the problem first:

//

// Approach and Solution:

//

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
