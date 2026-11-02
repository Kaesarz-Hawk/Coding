class Solution
{
public:
    string longestPalindrome(string s)
    {
        string t = s;
        for (int i = 0; i < s.size(); i++){
       
       //use two pointers to find the longest palindrome
            int left = i, right = i;
            while (left >= 0 && right < s.size() && s[left] == s[right]) {
                left--;
                right++;
            }
            if (right - left - 1 > t.size()) {
                t = s.substr(left + 1, right - left - 1);
            }
            left = i, right = i + 1;
            while (left >= 0 && right < s.size() && s[left] == s[right]) {
                left--;
                right++;
            }
            if (right - left - 1 > t.size()) {
                t = s.substr(left + 1, right - left - 1);
            }

        
        }
        return s;
    }
};