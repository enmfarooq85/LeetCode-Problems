// 303. Range Sum Query - Immutable

// Problem statement:

/*
Given an integer array nums, handle multiple queries of the following type:

Calculate the sum of the elements of nums between indices left and right inclusive where left <= right.
Implement the NumArray class:

NumArray(int[] nums) Initializes the object with the integer array nums.
int sumRange(int left, int right) Returns the sum of the elements of nums between indices left and right inclusive (i.e. nums[left] + nums[left + 1] + ... + nums[right]).
*/

// Understand the problem first:

// hme aik array of nums dia hua hy hum ne us per segment tree ke kuch basic operations lgane hy like update, build and range sum.

// Approach and Solution:

// Isko brute force se bi hal kr skte asani se. Lekin ye asal me segment tree ka aik buht hi acha question hy. Iske liye bs apko segment tree ke basic operations ka pta hona chahie. 

// class NumArray {
// public:
//     vector<int> arr;

//     NumArray(vector<int>& nums) { arr = nums; }

//     int sumRange(int left, int right) {
//         int sum = 0;

//         for (int i = left; i <= right; i++) {
//             sum += arr[i];
//         };

//         return sum;
//     }
// };

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */

// class NumArray {
// public:
//     vector<int> arr;
//     vector<int> segmentTree;
//     int n;

//     NumArray(vector<int>& nums) {
//         arr = nums;
//         n = arr.size();

//         segmentTree.resize(4 * n);

//         if (n > 0) {
//             buildSegmentTree(0, 0, n - 1);
//         }
//     }

//     void buildSegmentTree(int i, int left, int right) {
//         if (left == right) {
//             segmentTree[i] = arr[left];
//             return;
//         }

//         int mid = left + (right - left) / 2;

//         buildSegmentTree(2 * i + 1, left, mid);
//         buildSegmentTree(2 * i + 2, mid + 1, right);

//         segmentTree[i] =
//             segmentTree[2 * i + 1] + segmentTree[2 * i + 2];
//     }

//     int query(int i, int left, int right, int start, int end) {
//         // No overlap
//         if (right < start || left > end) {
//             return 0;
//         }

//         // Complete overlap
//         if (start <= left && right <= end) {
//             return segmentTree[i];
//         }

//         // Partial overlap
//         int mid = left + (right - left) / 2;

//         int leftSum = query(2 * i + 1, left, mid, start, end);
//         int rightSum = query(2 * i + 2, mid + 1, right, start, end);

//         return leftSum + rightSum;
//     }

//     int sumRange(int left, int right) {
//         return query(0, 0, n - 1, left, right);
//     }
// };
