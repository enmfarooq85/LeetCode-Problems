// 3478. Choose K Elements With Maximum Sum

// Problem statement:

/*
You are given two integer arrays, nums1 and nums2, both of length n, along with a positive integer k.

For each index i from 0 to n - 1, perform the following:

Find all indices j where nums1[j] is less than nums1[i].
Choose at most k values of nums2[j] at these indices to maximize the total sum.
Return an array answer of size n, where answer[i] represents the result for the corresponding index i.

*/

// Understand the problem first:

// hme do arrays dia gaye nums1 and nums2 in ki length same hy. hme hr index i ke liye kuch operation krne hy jo ke ino ne mention kiye hoe hy.

// Approach and Solution:

// Sb se pehle jesa bola gia hy wese ka wesa kr do agr wesa kr do ge tu TLE kre ga then pir optimal solution ki trf jaye. Optimal solution ke liye hum log sorting kre ge aur hum log indexes, nums1 aur nums2 store kre ge. Then pir minHeap ka use kr ke k maximium element maintain kre ge.

// #include "bits/stdc++.h"
// using namespace std;

// class Solution
// {
// public:
//     vector<long long> findMaxSum(vector<int> &nums1, vector<int> &nums2,
//                                  int k)
//     {
//         int n1 = nums1.size();
//         int n2 = nums2.size();
//         vector<int> lessIndices;
//         vector<int> lessIndicesElement;
//         vector<long long> ans;

//         for (int i = 0; i < n1; i++)
//         {
//             for (int j = 0; j < n1; j++)
//             {
//                 if (i == j)
//                 {
//                     continue;
//                 }

//                 if (nums1[j] < nums1[i])
//                 {
//                     lessIndices.push_back(j);
//                 }
//             }

//             for (int kk = 0; kk < lessIndices.size(); kk++)
//             {
//                 lessIndicesElement.push_back(nums2[lessIndices[kk]]);
//             }

//             sort(lessIndicesElement.begin(), lessIndicesElement.end());

//             long long maximum = 0;
//             int count = k;
//             while (lessIndicesElement.size() > 0 && count > 0)
//             {
//                 maximum += lessIndicesElement.back();
//                 lessIndicesElement.pop_back();
//                 count--;
//             }

//             ans.push_back(maximum);
//             lessIndices.clear();
//             lessIndicesElement.clear();
//         }

//         return ans;
//     }
// };

// class Solution {
// public:
//     vector<long long> findMaxSum(vector<int>& nums1, vector<int>& nums2,
//                                  int k) {
//         int n1 = nums1.size();
//         int n2 = nums2.size();
//         vector<int> lessIndicesElement;
//         vector<long long> ans;

//         for (int i = 0; i < n1; i++) {
//             for (int j = 0; j < n1; j++) {
//                 if (i == j) {
//                     continue;
//                 }

//                 if (nums1[j] < nums1[i]) {
//                     lessIndicesElement.push_back(nums2[j]);
//                 }
//             }

//             sort(lessIndicesElement.begin(), lessIndicesElement.end());

//             long long maximum = 0;
//             int count = k;
//             while (lessIndicesElement.size() > 0 && count > 0) {
//                 maximum += lessIndicesElement.back();
//                 lessIndicesElement.pop_back();
//                 count--;
//             }

//             ans.push_back(maximum);
//             lessIndicesElement.clear();
//         }

//         return ans;
//     }
// };

// class Solution {
// public:
//     vector<long long> findMaxSum(vector<int>& nums1, vector<int>& nums2,
//                                  int k) {
//         int n1 = nums1.size();
//         vector<long long> ans;

//         for (int i = 0; i < n1; i++) {
//             // using min heap so that we maintain k greater element of j indices
//             priority_queue<int, vector<int>, greater<int>> minHeap;
//             for (int j = 0; j < n1; j++) {
//                 if (nums1[j] < nums1[i]) {
//                     minHeap.push(nums2[j]);
//                     if (minHeap.size() > k) {
//                         minHeap.pop();
//                     }
//                 }
//             }

//             long long sum = 0;
//             while (minHeap.size() > 0) {
//                 sum += minHeap.top();
//                 minHeap.pop();
//             };

//             ans.push_back(sum);
//         }

//         return ans;
//     }
// };

// class Solution {
// public:
//     vector<long long> findMaxSum(vector<int>& nums1, vector<int>& nums2,
//                                  int k) {
//         int n = nums1.size();
//         vector<vector<int>> triplet;

//         for (int i = 0; i < n; i++) {
//             triplet.push_back({nums1[i], nums2[i], i});
//         }

//         sort(triplet.begin(), triplet.end());

//         vector<long long> ans(n, 0);
//         priority_queue<int, vector<int>, greater<int>> minHeap;
//         long long currSum = 0;

//         for (int i = 0; i < n; i++) {
//             int value = triplet[i][0];
//             int index = triplet[i][2];

//             if (i > 0 && value == triplet[i - 1][0])
//                 ans[index] = ans[triplet[i - 1][2]];
//             else
//                 ans[index] = currSum;

//             minHeap.push(triplet[i][1]);
//             currSum += triplet[i][1];

//             // keep only k largest values
//             if (minHeap.size() > k) {
//                 currSum -= minHeap.top();
//                 minHeap.pop();
//             }
//         }

//         return ans;
//     }
// };


// int main()
// {
//     Solution s;
//     vector<int> nums1 = {4, 2, 1, 5, 3};
//     vector<int> nums2 = {10, 20, 30, 40, 50};
//     int k = 2;
//     vector<long long> ans = s.findMaxSum(nums1, nums2, k);

//     for (long long i = 0; i < ans.size(); i++)
//     {
//         cout << ans[i] << endl;
//     }

//     return 0;
// }
