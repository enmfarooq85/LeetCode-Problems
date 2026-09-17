// 307. Range Sum Query - Mutable

// Problem statement:

/*
Given an integer array nums, handle multiple queries of the following types:

Update the value of an element in nums.
Calculate the sum of the elements of nums between indices left and right inclusive where left <= right.
Implement the NumArray class:

NumArray(int[] nums) Initializes the object with the integer array nums.
void update(int index, int val) Updates the value of nums[index] to be val.
int sumRange(int left, int right) Returns the sum of the elements of nums between indices left and right inclusive (i.e. nums[left] + nums[left + 1] + ... + nums[right]).
*/

// Understand the problem first:

// hme aik array of nums dia gia hy hme multiple queries handle krni hy. like updating, range sum.

// Approach and Solution:

// Isko ap log brute force se badi asani se hal kre ge just ye ke object oriented programming ka pta ho thoda sa like kese cheeze ko initialize krna hy. Baqi ye question segment tree ka hy aur segment tree ke basic operation use ho rahe hy. like updating, query, and building segment tree.

// class NumArray {
// public:
//     vector<int> num;
//     int n;
//     NumArray(vector<int>& nums) {
//         num = nums;
//         n   = nums.size();
//     }
    
//     void update(int index, int val) {
//         num[index] = val;
//     }
    
//     int sumRange(int left, int right) {
//         int sum = 0;
        
//         for(int i = left; i <= right; i++) {
//             sum += num[i];
//         }

//         return sum;
//     }
// };
/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */


// class NumArray {
// public:
//     vector<int> segmentTree;
//     int n;

//     NumArray(vector<int>& nums) {
//         n = nums.size();
//         segmentTree.resize(4 * n);
        
//         if (n > 0) {
//             buildSegmentTree(0, 0, n - 1, nums);
//         }
//     }

//     void buildSegmentTree(int i, int l, int r, vector<int>& nums) {
//         if (l == r) {
//             segmentTree[i] = nums[l];
//             return;
//         }

//         int mid = l + (r - l) / 2;
//         buildSegmentTree(2 * i + 1, l, mid, nums);
//         buildSegmentTree(2 * i + 2, mid + 1, r, nums);

//         segmentTree[i] = segmentTree[2 * i + 1] + segmentTree[2 * i + 2];
//     }

//     void updateSegTree(int index, int val, int i, int l, int r) {
//         if (l == r) {
//             segmentTree[i] = val;
//             return;
//         }

//         int mid = l + (r - l) / 2;
//         if (index <= mid) {
//             updateSegTree(index, val, 2 * i + 1, l, mid);
//         } else {
//             updateSegTree(index, val, 2 * i + 2, mid + 1, r);
//         }

//         segmentTree[i] = segmentTree[2 * i + 1] + segmentTree[2 * i + 2];
//     }

//     int querySegmentTree(int start, int end, int i, int l, int r) {
//         if (l > end || r < start) {
//             return 0;
//         }

//         if (l >= start && r <= end) {
//             return segmentTree[i];
//         }

//         int mid = l + (r - l) / 2;
//         return querySegmentTree(start, end, 2 * i + 1, l, mid) +
//                querySegmentTree(start, end, 2 * i + 2, mid + 1, r);
//     }

//     void update(int index, int val) { updateSegTree(index, val, 0, 0, n - 1); }

//     int sumRange(int left, int right) {
//         return querySegmentTree(left, right, 0, 0, n - 1);
//     }
// };

// /**
//  * Your NumArray object will be instantiated and called as such:
//  * NumArray* obj = new NumArray(nums);
//  * obj->update(index,val);
//  * int param_2 = obj->sumRange(left,right);
//  */
