#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    vector<int> arr = {2, 3, 6, 7, 8, 8, 11, 11, 12};
    int target = 8;

    // Returns iterators pointing to the found elements (or arr.end() if not found)
    auto lb_it = lower_bound(arr.begin(), arr.end(), target);
    auto ub_it = upper_bound(arr.begin(), arr.end(), target);

    // Convert iterators to indices
    int lb_index = lb_it - arr.begin();
    int ub_index = ub_it - arr.begin();

    cout << "STL Lower Bound index: " << lb_index << "\n"; // Output: 4
    cout << "STL Upper Bound index: " << ub_index << "\n"; // Output: 6

    // Tip: Count occurrences of target in O(log n) time
    int count = ub_index - lb_index;
    cout << "Count of " << target << ": " << count << "\n"; // Output: 2

    return 0;
}
