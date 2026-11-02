class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int> merged;
        for (int i = 0; i < nums1.size(); i++) {
            merged.push_back(nums1[i]);
        }
        for (int i = 0; i < nums2.size(); i++) {
            merged.push_back(nums2[i]);
        }
        sort(merged.begin(), merged.end());

        int n = merged.size();
        if (n % 2 != 0) {
            return merged[n / 2];
        } else {
            return (merged[n / 2 - 1] + merged[n / 2]) / 2.0;
        }
    }
};