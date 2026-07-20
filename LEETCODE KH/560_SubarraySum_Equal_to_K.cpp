class Solution {
public:
    int subarraySum(const vector<int>& nums, int k) {
        map<long long, int> cntpre;
        cntpre[0] = 1;
        long long pre = 0 , ans = 0;
        for ( int x : nums) {
            pre += x;
            ans += cntpre[pre - k];
            cntpre[pre]++;
        }

        return ans;
        
    }
};