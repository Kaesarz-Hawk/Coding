int solve(vector<int>& nums, int x) {
    auto elements = lower_bound(nums.begin(), nums.end(), x);
    int count = distance(nums.begin(), elements);
    return count;
  
}


