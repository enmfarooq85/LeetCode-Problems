// 137. Single Number II

// Problem statement:

// Given an integer array nums where every element appears three times except for one, which appears exactly once. Find the single element and return it. You must implement a solution with a linear runtime complexity and use only constant extra space.

// Understand the problem first:

// Hme aik array of integers dia gya hy aur is me hr number three times ho ga siwae aik number ko hme us aik number ko find krna hy aur return krna hy yaad rahe ke hme contant space use krni hy.

// Approach and Solution:

// Sb se pehle mind me approach ati hy wo ye hy ke hum log frequency calculate kr le aur dekh le kis ki frequency 1 hy. Doosri approach hy hy ke hum log sorting kr ke pir tripplets pe jump krte hoe uska left aur right se compare krte hoe dekh le agr pura array traverse kr ke pir bi nahi mil raha then pir last wala hi apka unique hy. Teesri approach hy ke hum log Bit Manipulation se answer nikale iske liye apko left shift ka concept aur konse bit ka wo bit zero hy ya one hy wo ana chahiye yes it's tough but computer science student will enjoy it.

// class Solution {
// public:
//     int singleNumber(vector<int>& nums) {
//         unordered_map<int, int> mp;

//         for (int& num :nums){
//             mp[num]++;
//         }
        
//         int ans = -1;
//         for (const auto& [key, val]:mp){
//             if (val <3){
//                 ans  = key;
//                 break;
//             }
//         }
        
//         return ans;
//     }
// };

// class Solution {
// public:
//     int singleNumber(vector<int>& nums) {
//         sort(begin(nums), end(nums));
//         int n = nums.size();

//         if (n == 1) {
//             return nums[0];
//         }

//         int ans = 0;
//         for (int i = 1; i < n - 1; i += 3) {
//             if (nums[i] != nums[i - 1]) {
//                return nums[i - 1];
//             } else if (nums[i] != nums[i + 1]) {
//                return nums[i + 1];
//             }
//         }

//          return nums[n - 1];
//     }
// };

// class Solution {
// public:
//     int singleNumber(vector<int>& nums) {
//         int result = 0;

//         for (int i = 0; i <= 31; i++) {
//             int temp = (1 << i);

//             int countOfOnes = 0;
//             for (int& num : nums) {
//                 if ((num & temp) != 0) {
//                     countOfOnes++;
//                 }
//             }

//             if (countOfOnes % 3 == 1) {
//                 result = (result | temp);
//             }
//         }

//         return result;
//     }
// };
