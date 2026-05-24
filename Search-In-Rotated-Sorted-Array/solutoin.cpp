// 81. Search in Rotated Sorted Array II

// Problem statement:

// There is an integer array nums sorted in non-decreasing order (not necessarily with distinct values).Given the array nums after the rotation and an integer target, return true if target is in nums, or false if it is not in nums. You must decrease the overall operation steps as much as possible.

// Understand the problem statement:

// hme aik int of array nums jo ke ascending order me sort hy aur pir usko rotate kr ke hme dia gia hy. aur aik int target dia gia hy hume ye pta lgana hy ke agr wo target us array me hy tu return true otherwise false. hme operation ko minimum se minimum krna hy. So, classical binary search yaha work nahi kre ge.

// Approach and Solution:

// hum log yaha binary search ka use kre ge lekin optimally. ye problem still binary search se hal ho skti hy because kahi na kahi sorted part hy jis me target ho ga agr nahi tu simply return false.

#include "bits/stdc++.h"
using namespace std;

class Solution {
public:
    // nums = [2,5,6,0,0,1,2] ,target = 3
    bool search(vector<int>& nums, int target) {
        // 0
        // 4
        // 6
        // 7
        int left = 0;
        // 6
        // 5
        int right = nums.size() - 1;
        
        // 0 <= 6 <==> true
        // 4 <= 6 <==> true
        // 6 <= 6 <==> true
        // 7 <= 5 <==> false
        while (left <= right) {
            // 0 + (6 - 0) / 2 <==> 3
            // 4 + (6 - 4) / 2 <==> 5
            // 6 + (6 - 6) / 2 <==> 6
            int mid = left + (right - left) / 2;
            // 0 == 0 <==> false
            // 1 == 3 <==> false
            // 2 == 3 <==> false
            if (nums[mid] == target) {
                return true;
            }

            // Handling duplicates
            // 2 == 0 && 0 == 2 <==> false
            // 0 == 1 && 1 == 2 <==> false
            // 6 == 6 && 6 == 6 <==> false
            if (nums[left] == nums[mid] && nums[mid] == nums[right]) {
                // 6 = 7
                left++;
                // 6 = 5
                right--;
            }

            // Left half is sorted
            // 2 <= 0 <==> true
            // 0 <= 1 <==> true
            else if (nums[left] <= nums[mid]) {
                // 2 <= 3 && 3 < 0 <==> false
                // 0 <= 3 && 3 < 1 <==> false
                if (nums[left] <= target && target < nums[mid]) {
                    right = mid - 1;
                } else {
                    // 0 = 3 + 1 <==> 4
                    // 4 = 5 + 1 <==> 6
                    left = mid + 1;
                }
            }

            // Right half is sorted
            else {
                if (nums[mid] < target && target <= nums[right]) {
                    left = mid + 1;
                } else {
                    right = mid - 1;
                }
            }
        }

        // false
        return false;
    }
};

int main (){
    Solution s1;
    vector <int> nums = {2,5,6,0,0,1,2};
    int target = 3;
    bool ans = s1.search(nums, target);
    cout << ((ans == 0) ? !true : !false) << endl;
    return 0;
}