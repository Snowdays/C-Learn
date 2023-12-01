#include <iostream>
#include <string>
#include <sstream>
#include <unordered_map>
#include "code.h"
#include <stdio.h>
#include <vector>
using namespace std;

int main(){
    Solution solution;

    // Solution so;
    // string a;
    // a = 'babad';
    // cout<<so.longestPalindrome(a)<<endl;

    // string b;
    // b = 'abcabcbb';
    // cout<<so.lengthOfLongestSubstring(b);

    // vector<int> nums1 = { 2,3, 5 };
	// vector<int> nums2 = { 1,4,7, 9 };
	// Solution solution;
	// double ret = solution.findMedianSortedArrays(nums1, nums2);
    // cout<<ret;

    // vector<int> nums1 = {1,2,3,0,0,0};
    // vector<int> nums2 = {2,5,6};
    // solution.merge(nums1, 3, nums2, 3);
    // for(int i=0; i < nums1.size(); ++i){
    //     cout<<nums1[i]<<' ';
    // }

    // vector<int> nums1 = {3,2,2,3};
    // int ret;
    // ret = solution.removeElement(nums1, 3);
    // cout<<ret;
    // for(int i=0; i < nums1.size(); ++i){
    //      cout<<nums1[i]<<' ';
    // }
    
    // string s ='()[]{}';
    // bool isva;
    // isva = solution.isValid(s);
    // cout<<boolalpha<<isva;

    // vector<vector<int>> a;
    // vector<vector<int>> b;
    // a = {{1,3},{2,6},{8,10},{15,18}};
    // b = solution.interval_merge(a);
    // for(int i=0; i < b.size(); ++i){
    //      for(int j=0;j<b[0].size();++j)
    //      cout<<b[i][j]<<' ';
    // }

    // //创建新链表L，头节点赋值固定（0）
    // ListNode *L = new ListNode();
    // ListNode *l1 = new ListNode(1);
    // ListNode *l2 = new ListNode(2);
    // ListNode *l3 = new ListNode(4);
    // L->next = l1;
    // l1->next = l2;
    // l2->next = l3;
    // //创建新链表p，顶替之前赋值的新链表L的头节点（0）
    // //完成新建链表操作
    // ListNode *list2 = L->next;
    // // while(list2!=NULL){
    // //     cout<<list2->val<<endl;
    // //     list2 = list2->next;
    // // }
    // ListNode *Q = new ListNode();
    // ListNode *q1 = new ListNode(1);
    // ListNode *q2 = new ListNode(3);
    // ListNode *q3 = new ListNode(4);
    // Q->next = q1;
    // q1->next = q2;
    // q2->next = q3;
    // ListNode *list1 = Q->next;
    // // while(list1!=NULL){
    // //     cout<<list1->val<<endl;
    // //     list1 = list1->next;
    // // }
    // ListNode *list = new ListNode();
    // list = solution.mergeTwoLists(list2, list1);
    // while(list!=NULL){
	// 	cout<<list->val<<' ';
	// 	list = list->next;
	// }

        //创建新链表L，头节点赋值固定（0）
    // ListNode *L = new ListNode();
    // ListNode *l1 = new ListNode(1);
    // ListNode *l2 = new ListNode(2);
    // ListNode *l3 = new ListNode(3);
    // ListNode *l4 = new ListNode(4);
    // ListNode *l5 = new ListNode(5);
    // L->next = l1;
    // l1->next = l2;
    // l2->next = l3;
    // l3->next = l4;
    // l4->next = l5;
    // //创建新链表p，顶替之前赋值的新链表L的头节点（0）
    // //完成新建链表操作
    // ListNode *list2 = L->next;
    // while(list2!=NULL){
    //     cout<<list2->val<<endl;
    //     list2 = list2->next;
    // }
    // ListNode *list = new ListNode();
    // list = solution.removeNthFromEnd(list2, 2);
    // while(list!=NULL){
	// 	cout<<list->val<<' ';
	// 	list = list->next;
	// }

    // vector<int> a;
    // a = {0,0,1,1,1,2,2,3,3,4};
    // int b = solution.removeDuplicates(a);
    // cout<<b;

    // string s ='PAYPALISHIRING';
    // string str;
    // str = solution.convert(s, 3);
    // cout<<str;

    // vector<int> a;
    // a = {2,3,1,1,4};
    // bool bo = solution.canJump(a);

    // vector<int> a;
    // a = {7,1,5,3,6,4};
    // int bo = solution.maxProfit(a);
    // cout<<bo;

    // int a = 2;
    // int b = solution.climbStairs(a);
    // cout<<b;

    // int x = -123;
    // int b = solution.reverse_(x);
    // cout<<b<<endl;

    // string s ='42HEllo';
    // int str;
    // str = solution.myAtoi(s);
    // cout<<str;

    // string s ='aa';
    // string p ='a*';
    // bool str;
    // str = solution.isMatch(s, p);
    // cout<<str;

    // vector<int> a;
    // a = {1,8,6,2,5,4,8,3,7};
    // int bo = solution.maxArea(a);
    // cout<<bo;

    // int num = 1994;
    // string res = solution.intToRoman(num);
    // cout<<res;

    // string num = {'MCMXCIV'};
    // int res = solution.romanToInt(num);
    // cout<<res;

    // vector<string> strs;
    // strs = {'flower','flow','flight'};
    // auto res = solution.longestCommonPrefix(strs);
    // cout<<res;

    // vector<int> a;
    // a = {1,1,1,1};
    // int result = solution.threeSumClosest(a, 0);
    // cout<<result;

    // vector<int> s;
    // s = {1,0,-1,0,-2,2};
    // vector<vector<int>> str;
    // str = solution.fourSum(s, 0);
    // for(int i=0;i<str.size();i++){
    //     for(int j=0;j<str[0].size();j++){
    //         cout<<str[i][j]<<' ';
    //     }
    //     cout<<endl;
    // }

    // vector<string> str = solution.generateParenthesis(3);
    // for(int i = 0;i<str.size();i++){
    //     cout<<str[i]<<endl;
    // }

    // vector<int> a = {2,3,1};
    // solution.nextPermutation(a);
    // for(int i = 0;i<a.size();i++){
    //     cout<<a[i]<<' ';
    // }

    // vector<int> a = {5,7,7,8,8,10};
    // vector<int> b = solution.searchRange_2(a, 8);
    // for(int i = 0;i<b.size();i++){
    //     cout<<b[i]<<' ';
    // }

    // vector<int> a = {1,3,5,6};
    // int b = solution.searchInsert(a, 6);
    // cout<<b;

    // vector<vector<char>> charVector;
    // charVector = {
    //     {'8','3','.','.','7','.','.','.','.'}
    //    ,{'6','.','.','1','9','5','.','.','.'}
    //    ,{'.','9','8','.','.','.','.','6','.'}
    //    ,{'8','.','.','.','6','.','.','.','3'}
    //    ,{'4','.','.','8','.','3','.','.','1'}
    //    ,{'7','.','.','.','2','.','.','.','6'}
    //    ,{'.','6','.','.','.','.','2','8','.'}
    //    ,{'.','.','.','4','1','9','.','.','5'}
    //    ,{'.','.','.','.','8','.','.','7','9'}
    // };
    // bool b0 = solution.isValidSudoku(charVector);
    // cout<<b0;

    // int a = 4;
    // string str = solution.countAndSay(a);
    // cout<<str;
    // vector<int> a = {10,1,2,7,6,1,5};
    // vector<vector<int>> b = solution.combinationSum2(a, 8);
    // for(int i=0;i<b.size();i++){
    // for(int j=0;j<b[0].size();j++){
    //     cout<<b[i][j]<<' ';
    // }
    // cout<<endl;
    // }

    // string num1 = "123";
    // string num2 = "456";
    // string result = solution.multiply(num1, num2);
    // cout<<result;

    // vector<int> nums = {1, 1, 2};
    // vector<vector<int>> b  = solution.permuteUnique(nums);
    // for(int i=0;i<b.size();i++){
    // for(int j=0;j<b[0].size();j++){
    //     cout<<b[i][j]<<' ';
    // }
    // cout<<endl;
    // }

    // vector<vector<int>> intervals = {{1,3},{6,9}};
    // vector<int> newIntervals = {2,5};
    // vector<vector<int>> res;
    // res = solution.insert(intervals, newIntervals);
    // for(int i = 0;i < res.size();i++){
    //     for(int j = 0;j < res[i].size();j++){
    //         cout<<res[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }

    // string s = "Hello World";
    // int a = solution.lengthOfLastWord(s);
    // cout<<a;

    // int n = 3;
    // vector<vector<int>> res = solution.generateMatrix(n);
    // for(int i = 0;i < res.size();i++){
    //     for(int j = 0;j < res[i].size();j++){
    //         cout<<res[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }

    // // 创建新链表L，头节点赋值固定（0）
    // ListNode *L = new ListNode();
    // ListNode *l1 = new ListNode(1);
    // ListNode *l2 = new ListNode(2);
    // ListNode *l3 = new ListNode(3);
    // ListNode *l4 = new ListNode(4);
    // ListNode *l5 = new ListNode(5);
    // L->next = l1;
    // l1->next = l2;
    // l2->next = l3;
    // l3->next = l4;
    // l4->next = l5;
    // //创建新链表p，顶替之前赋值的新链表L的头节点（0）
    // //完成新建链表操作
    // ListNode* list2 = L->next;
    // while(list2!=NULL){
    //     cout<<list2->val<<" ";
    //     list2 = list2->next;
    // }
    // ListNode *list = new ListNode();
    // list = solution.rotateRight(list2, 2);
    // while(list!=NULL){
	// 	cout<<list->val<<' ';
	// 	list = list->next;
	// }

    // vector<vector<int>> grid = {{1,3,1},{1,5,1},{4,2,1}};
    // int res = solution.minPathSum(grid);
    // cout<<res;

    // vector<int> digits;
    // vector<int> res = solution.plusOne(digits);
    // for(int i=0;i<digits.size();i++)
    // {
    //     cout<<digits[i]<<" ";
    // }
    // string a = "1010";
    // string b = "1011";
    // string res = solution.addBinary(a, b);
    // cout<<res;

    // string word1 = "horse";
    // string word2 = "ros";
    // int res= solution.minDistance(word1, word2);
    // cout<<res;

    // vector<vector<int>> matrix = {{0,1,2,0},{3,4,5,2},{1,3,1,5}};
    // solution.setZeroes(matrix);
    // for(int i = 0;i < matrix.size();i++){
    //     for(int j = 0;j < matrix[i].size();j++){
    //         cout<<matrix[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }


    // int n = 4,k = 2;
    // vector<vector<int>> res = solution.combine(n, k);
    // for(int i = 0;i < res.size();i++){
    //     for(int j = 0;j < res[i].size();j++){
    //         cout<<res[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }
    // vector<int> nums = {2,5,6,0,0,1,2};
    // bool b  = solution.search(nums, 3);
    // cout<<b;

    // // 创建新链表L，头节点赋值固定（0）
    // ListNode *L = new ListNode();
    // ListNode *l1 = new ListNode(1);
    // ListNode *l2 = new ListNode(4);
    // ListNode *l3 = new ListNode(3);
    // ListNode *l4 = new ListNode(2);
    // ListNode *l5 = new ListNode(5);
    // ListNode *l6 = new ListNode(2);
    // L->next = l1;
    // l1->next = l2;
    // l2->next = l3;
    // l3->next = l4;
    // l4->next = l5;
    // l5->next = l6;
    // //创建新链表p，顶替之前赋值的新链表L的头节点（0）
    // //完成新建链表操作
    // ListNode* list2 = L->next;
    // while(list2!=NULL){
    //     cout<<list2->val<<" ";
    //     list2 = list2->next;
    // }
    // ListNode *list = new ListNode();
    // list = solution.partition(list2, 3);
    // while(list!=NULL){
	// 	cout<<list->val<<' ';
	// 	list = list->next;
	// }

    // vector<int> res = solution.grayCode(2);
    // for(const int& code : res)
    // {
    //     cout<<code<<" ";
    // }

    // vector<int> nums = {1, 2, 2};
    // vector<vector<int>> res = solution.subsetsWithDup(nums);
    // for(int i = 0;i < res.size();i++){
    //     for(int j = 0;j < res[i].size();j++){
    //         cout<<res[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }
    string s = "226";
    int a = solution.numDecodings(s);
    cout<<a;

    return 0;
}