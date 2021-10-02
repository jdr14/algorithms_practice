/*
 * Given an array of integers "nums" which is sorted in ascending order,
 * and an integer "target", write a function to search "target" in "nums".  If
 * "target" exists, then return its index.  Otherwise, return "-1".  
 *
 * You must write an algorithm with O(log n) runtime complexity
 */

#include <vector>

using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int size = nums.size();
        int lower = 0;
        int upper = size - 1;
        int mid = size / 2;  
        if (target < nums[lower] || target > nums[upper]) {  // Range check
            return -1;
        }
        
        if (target == nums[lower]) {
            return lower;
        }
        if (target == nums[upper]) {
            return upper;
        }        
        
        while (lower <= upper) {
            if (target < nums[mid]) {  // target in lower half
                upper = mid - 1;
                if (target == nums[upper]) {
                    return upper;
                }
            }
            if (target > nums[mid]) {  // target in upper half
                lower = mid + 1;
                if (target == nums[lower]) {
                    return lower;
                }
            }

            if (target == nums[mid]) { // target found!
                return mid;
            }

            mid = (upper + lower) / 2;
            
            // if (target == nums[mid]) { // target found!
            //     return mid;
            // }
        }
        
        return -1;  // Case: target not found
    }
};