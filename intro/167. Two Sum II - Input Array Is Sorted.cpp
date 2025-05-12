// https://leetcode.com/problems/two-sum-ii-input-array-is-sorted/description/

class Solution {
    public:
        vector<int> twoSum(vector<int>& numbers, int target) {
            // 一左一右两个指针相向而行
            int left = 0;
            int right = numbers.size() - 1;
            while (left < right) {
                if (numbers[left] + numbers[right] > target) {
                    -- right;   // 让sum变小
                }
                else if (numbers[left] + numbers[right] < target) {
                    ++ left;    // 让sum变大
                }
                else {
                    return vector<int> {left + 1, right + 1};
                }
            }
            return vector<int> {-1, -1};
        }
    };