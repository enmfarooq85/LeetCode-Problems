// 2366. Minimum Replacements to Sort the Array

// Problem statement:

// You are given a 0-indexed integer array nums. In one operation you can replace any element of the array with any two elements that sum to it. Return the minimum number of operations to make an array that is sorted in non-decreasing order.

// Understand the problem first:

// Hme aik zero indexed based integer dia gia hy nums ke name se. Hum aik operation me kisi bi element ko two numbers se replace kr skte hy. aur hme ye replacing isliye krni hy ta ke hum log array ko non-decreasing bna ske. aur hme ye cheez minimum operations me krni hy.

// Approach and Solution:

// Simple approach ye hy ke hum log number ko tbhi replace krne ki koshih kre ge jb wo problem kre ga. Aur usko optimally break kre ta ke operations minimum lge. Means greedy approach lgae ge.

// class Solution {
// public:
//     long long minimumReplacement(vector<int>& nums) {
//         int n = nums.size();

//         long long opts = 0;

//         for (int i = n - 2; i >= 0; i--) {
//             // already maintained version
//             if (nums[i] <= nums[i + 1]) {
//                 continue;
//             }

//             int parts = nums[i] / nums[i + 1];

//             if (nums[i] % nums[i + 1] != 0) {
//                 parts += 1;
//             }

//             opts += parts - 1;
//             nums[i] = nums[i] / parts;
//         };

//         return opts;
//     };
// };
