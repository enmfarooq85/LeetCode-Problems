// 2997. Minimum Number of Operations to Make Array XOR Equal to K

// Probleme statement:

/*You are given a 0-indexed integer array nums and a positive integer k.

You can apply the following operation on the array any number of times:

Choose any element of the array and flip a bit in its binary representation. Flipping a bit means changing a 0 to 1 or vice versa.
Return the minimum number of operations required to make the bitwise XOR of all elements of the final array equal to k.

Note that you can flip leading zero bits in the binary representation of elements. For example, for the number (101)2 you can flip the fourth bit and obtain (1101)2.
*/

// Understand the problem first:

// hme aik integers of array dia gia hy hum logo ne uske kisi numbers pe option kr ke un tmama numbers ko k ke equal krna hy. Hum kisi number ke kisi bi bits ko flip kr skte hy from 0 to 1 and vice versa.

// Approach & Solution:

// Simply tmam ko XOR nikal lo aur then pir usko k sath xor kr ke number of set bits count kr lo wo ap ke operations ho ge un tmama to k ke equal krne ke.

// class Solution {
// public:
//     int countOfOnes(int n) {
//         int count = 0;
//         while (n != 0) {
//             if (n % 2 == 1) {
//                 count++;
//             }

//             n /= 2;
//         }

//         return count;
//     }

//     int minOperations(vector<int>& nums, int k) {
//         int n = nums.size();
//         int numsXor = 0;

//         for (int num = 0; num < n; num++) {
//             numsXor ^= nums[num];
//         }

//         int diffs = numsXor ^ k;

//         int requiredOpts = countOfOnes(diffs);

//         return requiredOpts;
//     }
// };
