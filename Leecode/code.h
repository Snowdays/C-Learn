#include <iostream>
#include <string>
#include <sstream>
#include <unordered_map>
#include <stdio.h>
#include <vector>
using namespace std;

//ListNode线性链表定义
struct ListNode{
	int val;
	ListNode *next;
	ListNode() : val(0),next(NULL){}
	ListNode(int x) : val(x), next(NULL){}
	ListNode(int x, ListNode *next) : val(x), next(next){}
}; 

class Solution{
    private:
    void backtrack(vector<int> &state, int target, vector<int> &choices, int start, vector<vector<int>> &res);
    void backtrack_2(vector<int> &choices, int start, vector<vector<int>> &res);
    void backtrack_3(vector<int> &choices, int start, vector<vector<int>> &res);

    public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2);
    string expand(string &str, int l, int r);
    string longestPalindrome(string s);
    int lengthOfLongestSubstring(const std::string &s);
    vector<vector<int>> threeSum(vector<int>& nums);
    int threeSumClosest(vector<int>& nums, int target);
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n);
    int removeElement(vector<int>& nums, int val);
    bool isValid(string s);
    vector<vector<int>> interval_merge(vector<vector<int>>& intervals);
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2);
    ListNode* removeNthFromEnd(ListNode* head, int n);
    ListNode* removeNthFromEnd2(ListNode* head, int n);//第二种
    int removeDuplicates(vector<int>& nums);
    int removeDuplicates_2(vector<int>& nums);//第二种
    string convert(string s, int numRows);
    bool canJump(vector<int>& nums);
    int maxProfit(vector<int>& prices);
    int climbStairs(int n);
    int reverse_(int x);
    int myAtoi(string s);
    bool isMatch(string s, string p);
    int maxArea(vector<int>& height);
    string intToRoman(int num);
    int romanToInt(string s);
    string longestCommonPrefix(vector<string>& strs);
    vector<string> letterCombinations(string digits);
    void backtracking(const string& digits, int index);
    vector<vector<int>> fourSum(vector<int>& nums, long long target);
    vector<string> generateParenthesis(int n);
    ListNode *swapPairs(ListNode *head);
    int strStr(string haystack, string needle);
    int divide(int dividend, int divisor);
    void nextPermutation(vector<int>& nums);
    //二分查找
    int search_two(vector<int> &nums, int target);
    vector<int> searchRange(vector<int>& nums, int target);
    vector<int> searchRange_2(vector<int>& nums, int target);
    int searchInsert(vector<int>& nums, int target);
    bool isValidSudoku(vector<vector<char>>& board);
    string countAndSay(int n);
    vector<vector<int>> combinationSum(vector<int>& candidates, int target);
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target);
    string multiply(string num1, string num2);
    int jump(vector<int>& nums);
    vector<vector<int>> permute(vector<int>& nums);
    vector<vector<int>> permuteUnique(vector<int>& nums);
    void rotate(vector<vector<int>>& matrix);
    vector<vector<string>> groupAnagrams(vector<string>& strs);
    double myPow(double x, int n);
    int maxSubArray(vector<int>& nums);
    vector<int> spiralOrder(vector<vector<int>>& matrix);
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval);
    int lengthOfLastWord(string s);
    vector<vector<int>> generateMatrix(int n);
    ListNode* rotateRight(ListNode* head, int k);
    int uniquePaths(int m, int n);
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid);
    int minPathSum(vector<vector<int>>& grid);
    vector<int> plusOne(vector<int>& digits);
    string addBinary(string a, string b);
    int mySqrt(int x);
    string simplifyPath(string path);
    int minDistance(string word1, string word2);
    void setZeroes(vector<vector<int>>& matrix);
    bool searchMatrix(vector<vector<int>>& matrix, int target);
    void sortColors(vector<int>& nums);
    vector<vector<int>> combine(int n, int k);
    vector<vector<int>> subsets(vector<int>& nums);
    vector<vector<int>> subsetsWithDup(vector<int>& nums);
    bool exist(vector<vector<char>>& board, string word);
    int removeDuplicates_3(vector<int>& nums);
    bool search(vector<int>& nums, int target);
    ListNode* deleteDuplicates(ListNode* head);
    ListNode* deleteDuplicates_simple(ListNode* head);
    ListNode* partition(ListNode* head, int x);
    vector<string> str_grayCode(int n);
    vector<int> grayCode(int n);
    int numDecodings(string s);
};