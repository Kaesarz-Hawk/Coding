int hasPairWithDifference(vector<int> &A, int N, int B)
{
    sort(A.begin(), A.end());
    int left = 0, right = 1;
    while (left < N && right < N)
    {
        int diff = A[right] - A[left];
        if (diff == B && left != right)
        {
            return 1; // Pair found
        }
        else if (diff < B)
        {
            right++;
        }
        else
        {
            left++;
        }
    }
    return 0; // No pair found
}