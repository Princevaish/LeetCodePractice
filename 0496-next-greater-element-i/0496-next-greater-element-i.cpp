class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> nge;  // Map from number to its next greater element
        stack<int> s;

        // Traverse nums2 in reverse to build the NGE map
        for (int i = nums2.size() - 1; i >= 0; --i) {
            int num = nums2[i];
            
            // Pop smaller elements from the stack
            while (!s.empty() && s.top() <= num) {
                s.pop();
            }

            // If stack is not empty, the top is the next greater element
            nge[num] = s.empty() ? -1 : s.top();

            // Push current element to stack
            s.push(num);
        }

        // Prepare the result for nums1 using the map
        vector<int> result;
        for (int num : nums1) {
            result.push_back(nge[num]);
        }

        return result;
    }
};
