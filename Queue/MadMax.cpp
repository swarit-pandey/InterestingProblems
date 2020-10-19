// https://binarysearch.com/problems/Mad-Max
// Above given is the link to the problem which is tagged under Deque in binarysearch.com

/*
Given a list of integers nums and an integer k, return the maximum values of each subarray of length k.

For example, given nums = [10, 5, 2, 7, 8, 7] and k = 3, return [10, 7, 8, 8] since:

10 = max(10, 5, 2)
7 = max(5, 2, 7)
8 = max(2, 7, 8)
8 = max(7, 8, 7)
*/

class Solution {
    public:
    vector<int> solve(vector<int>& nums, int k) {
        vector<int> res;
        deque<int> dq;
        
        for(int i = 0; i < nums.size(); ++i) {
            while(not dq.empty() and nums[dq.back()] <= nums[i]) {
                dq.pop_back();
            }    
            dq.push_back(i);
            if(not dq.empty() and i - dq.front() >= k) {
                dq.pop_front();
            }
            if(i >= k - 1) {
                res.push_back(nums[dq.front()]);
            }
        }
        return res;
    }
};

/*
This problem is pretty interesting as the algorithm used is a almost perfect case scenario for using deque Data Structure.
There are certain condition on when we need to pop or push the elements from the deque and that is pretty much self explainatory.
Here is visual kinda tutorial for the problem: https://www.geeksforgeeks.org/sliding-window-maximum-maximum-of-all-subarrays-of-size-k/
*/
