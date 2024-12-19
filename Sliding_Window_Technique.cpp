/*
Why should I use this Technique?
REASON: The sliding window technique effectively reduces time complexity from O(n^2) to O(n), making it suitable for large datasets.

There are two types of Sliding Window Techniques:
01. Fixed_Size Window
02. Variable_Size Window

*/


// Fixed_Size Window:
// Finding the maximum sum of a subarray of size 'k'.


int maxSumSubarray(vector<int>& nums, int k) {
    int n = nums.size();
    if (n < k) return 0; 

    int sum = 0;
    for (int i = 0; i < k; i++) {
        sum += nums[i];
    }

    int maxSum = sum;
    for (int i = k; i < n; i++) {
        sum += nums[i] - nums[i - k]; // Slide the window
        maxSum = max(maxSum, sum);
    }

    return maxSum;
}



// Variable-Size Window: 
// Longest Substring with at Most 'k' Distinct Characters

int longestSubstringKDistinct(string s, int k) {
    int n = s.length();
    if (n == 0 || k == 0) return 0;

    unordered_map<char, int> charCount;
    int left = 0, right = 0, maxLen = 0;

    while (right < n) {
        charCount[s[right]]++;

        while (charCount.size() > k) {
            charCount[s[left]]--;
            if (charCount[s[left]] == 0) {
                charCount.erase(s[left]);
            }
            left++;
        }

        maxLen = max(maxLen, right - left + 1);
        right++;
    }

    return maxLen;
}
