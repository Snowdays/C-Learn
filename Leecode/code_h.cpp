#include <iostream>
#include <string>
#include <sstream>
#include <unordered_map>
#include <unordered_set> 
#include"code.h"
#include <stdio.h>
#include <stack>
#include <algorithm>
#include <vector>
#include <set>
#include <limits.h> 
#include <math.h>


using namespace std;

#define max(a,b) (((a) > (b)) ? (a) : (b))
#define min(a,b) (((a) < (b)) ? (a) : (b))

// 中心扩散法,从每一个位置出发，向两边扩散，遇到不是回文的时候结束，即碰到不一样的词就结束循环
string Solution::expand(string &str, int l, int r){
    while(l>=0 && r<=str.size()-1 && str[l]==str[r]) l--, r++;
        return str.substr(l+1, r-l-1);  //退出循环后，字符范围是[l+1, r-1]，所以长度是：(r-1)-(l+1) + 1 = r-l-1
}

string Solution::longestPalindrome(string s){
    string out = s.substr(0, 1); //从string 的start位置开始提取字符串
    for(int i=0; i<s.size(); i++){
        string str1 = expand(s, i, i);  //从中心元素i开始向两边找
        string str2 = expand(s, i, i+1); //从中心元素[i, i+1]开始向两边找
        if(str1.size()>out.size()) out = str1; 
        if(str2.size()>out.size()) out = str2;     
    }
    return out;
}

double Solution::findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2){
	int n = nums1.size();
	int m = nums2.size();

	if (n > m)  //保证数组1一定最短
	{
		return findMedianSortedArrays(nums2, nums1);
	}

	// Ci 为第i个数组的割,比如C1为2时表示第1个数组只有2个元素。LMaxi为第i个数组割后的左元素。RMini为第i个数组割后的右元素。
	int LMax1, LMax2, RMin1, RMin2, c1, c2, lo = 0, hi = 2 * n;  //我们目前是虚拟加了'#'所以数组1是2*n长度

	while (lo <= hi)   //二分
	{
		c1 = (lo + hi) / 2;  //c1是二分的结果
		c2 = m + n - c1;

		LMax1 = (c1 == 0) ? INT_MIN : nums1[(c1 - 1) / 2];
		RMin1 = (c1 == 2 * n) ? INT_MAX : nums1[c1 / 2];
		LMax2 = (c2 == 0) ? INT_MIN : nums2[(c2 - 1) / 2];
		RMin2 = (c2 == 2 * m) ? INT_MAX : nums2[c2 / 2];

		if (LMax1 > RMin2)
			hi = c1 - 1;
		else if (LMax2 > RMin1)
			lo = c1 + 1;
		else
			break;
	}
	return (max(LMax1, LMax2) + min(RMin1, RMin2)) / 2.0;
}

int Solution::lengthOfLongestSubstring(const std::string &s)
{
    //给每一个字符建立一个字典，有重复就加一
    int n = s.length(), ans = 0, left = 0;
    unordered_map<char, int> cnt;
    for (int right = 0; right < n; ++right) {
        char c = s[right];
        ++cnt[c];
        while (cnt[c] > 1) // 不满足要求
            --cnt[s[left++]];
        ans = max(ans, right - left + 1);
        }
    return ans;
}

vector<vector<int>> Solution::threeSum(vector<int>& nums) {
	sort(nums.begin(), nums.end());//数组排序
	vector<vector<int>> ans;
	int n = nums.size();
	for (int i = 0; i < n - 2 && nums[i] <= 0; ++i) { // 遍历数组，固定第一个元素
		if (i && nums[i] == nums[i - 1]) {//避免重复的固定元素
			continue;
		}
		int j = i + 1, k = n - 1;//左指针指向固定元素的下一位，右指针指向数组末尾
		while (j < k) {
			int x = nums[i] + nums[j] + nums[k];
			if (x < 0) {//和小于0，需要增大和，左指针增加
				++j;
			} else if (x > 0) {//和大于0，需要减小和，右指针增加
				--k;
			} else {
				ans.push_back({nums[i], nums[j++], nums[k--]});
				while (j < k && nums[j] == nums[j - 1]) {
					++j;
				}
				while (j < k && nums[k] == nums[k + 1]) {
					--k;
				}
			}
		}
	}
	return ans;
}


vector<vector<int>> Solution::fourSum(vector<int>& nums, long long target) {
    sort(nums.begin(),nums.end());
    vector<vector<int> > res;
    if(nums.size()<4)
    return res;
    int a,b,c,d,_size=nums.size();
    for(a=0;a<=_size-4;a++){
        if(a>0&&nums[a]==nums[a-1]) continue;      //确保nums[a] 改变了
        for(b=a+1;b<=_size-3;b++){
        	if(b>a+1&&nums[b]==nums[b-1])continue;   //确保nums[b] 改变了
        	c=b+1,d=_size-1;
        	while(c<d){
        		if(nums[a]+nums[b]-target<-(nums[c]+nums[d]))//原写法num[a]+num[b]+num[c]+num[d]<target为了防止溢出，见下面的补充修改
        			c++;
        		else if(nums[a]+nums[b]-target>-(nums[c]+nums[d]))//同上
        			d--;
        		else{
        			res.push_back({nums[a],nums[b],nums[c],nums[d]});
        			while(c<d&&nums[c+1]==nums[c])      //确保nums[c] 改变了
        				c++;
        			while(c<d&&nums[d-1]==nums[d])      //确保nums[d] 改变了
        				d--;
        			c++;
        			d--;
				}
			}
		}
	}
	return res;
}


int Solution::threeSumClosest(vector<int>& nums, int target)
{
    sort(nums.begin(), nums.end());
    int result = INT_MAX;
    int n = nums.size();
    for (int i=0;i < n;++i){
        int j = i + 1,k = n - 1;
        while(j < k){
            int x = nums[i] + nums[j] + nums[k];
            if (abs(x - target) < abs(result - target)) result = x;
            if(x < target) ++j;
            else if(x > target) --k;
            else return x; 
        }
    }
    return result;
}


// 从后往前，确定该位置该使用两组中的哪个数字，然后做交换，少的一组数据全部加进去为止；
// 88. 合并两个有序数组
void Solution::merge(vector<int>& nums1, int m, vector<int>& nums2, int n){
	int i=nums1.size()-1;
    m--;
    n--;
    while(n>=0){
        while(m>=0 && nums1[m]>nums2[n]){
            swap(nums1[i--], nums1[m--]);
        }
        swap(nums1[i--],nums2[n--]);
    }
}


int Solution::removeElement(vector<int>& nums, int val) {
    int left=0;
    for(int i=0;i<nums.size();i++){
        if(nums[i] != val){
            nums[left]=nums[i];
            left++;
        }
    }
    return left;
}
//栈进行符号匹配
bool Solution::isValid(string s) {
    unordered_map<char,int> m{{'(',1},{'[',2},{'{',3},
                                {')',4},{']',5},{'}',6}};
    stack<char> st;
    bool istrue=true;
	//使用哈希表来判断是否能够形成括号，从而决定进行入栈操作还是出栈操作
    for(char c:s){
        int flag=m[c];
        if(flag>=1&&flag<=3) st.push(c);
        else if(!st.empty()&&m[st.top()]==flag-3) st.pop();
        else {istrue=false;break;}
    }
    if(!st.empty()) istrue=false;
    return istrue;
}
//区间合并
//使用双指针，左边指针指向当前区间的开始
//使用一个变量来记录连续的范围 t
//右指针开始往后寻找，如果后续的区间的开始值比 t 还小，说明重复了，可以归并到一起
vector<vector<int>> Solution::interval_merge(vector<vector<int>>& intervals) {
    sort(intervals.begin(),intervals.end());
    vector<vector<int>> ans;
    for (int i=0; i < intervals.size();){
        int t = intervals[i][1];
        int j = i + 1;
        while (j < intervals.size() && intervals[j][0] <= t) {
            t = max(t, intervals[j][1]);
            j++;
        }
        ans.push_back({ intervals[i][0], t });
		//在Vector最后添加一个元素
        i = j;
    }
    return ans;
}

//ListNode线性链表定义
// struct ListNode{
// 	int val;
// 	ListNode *next;
// 	ListNode() : val(0),next(NULL){}
// 	ListNode(int x) : val(x), next(NULL){}
// 	ListNode(int x, ListNode *next) : val(x), next(next){}
// }; 

//双指针
ListNode* Solution::mergeTwoLists(ListNode* list1, ListNode* list2) {
	//辅助链表的头节点
    ListNode* dum = new ListNode(0);
	//cur指向头节点dum
    ListNode* cur = dum;
    while (list1 != nullptr && list2 != nullptr) {
        if (list1->val < list2->val) {
            cur->next = list1;
            list1 = list1->next;
        }
        else {
            cur->next = list2;
            list2 = list2->next;
        }
        cur = cur->next;
    }
    cur->next = list1 != nullptr ? list1 : list2;

    return dum->next;
}
//假设链表的长度为n，为了将链表每个节点向右移动 k 个位置，我们只需要将链表的后 k % n个节点移动到链表的最前面，然后将链表的后k % n个节点和前 n - k个节点连接到一块即可。
ListNode* Solution::rotateRight(ListNode* head, int k){
    if(!head || !k) return head;
    int n = 0;//存储链表的长度
    ListNode* tail;
    for(ListNode*p = head;p;p = p->next){//获取长度
        tail = p;
        n++;
    }
    k %= n;
    ListNode* p = head;
    for(int i = 0;i< n-k-1;i++){//找到链表的n-k个节点
        p = p->next;
    }
    tail->next = head;
    head = p->next;
    p->next = nullptr;
    return head;
}

//引入额外空间
//用哈希表记录每个节点的索引；然后通过要删除节点的索引，获取要删除链表的前一个节点
ListNode* Solution::removeNthFromEnd2(ListNode* head, int n){
    ListNode* pre = new ListNode(0, head);   // 伪头节点
    ListNode* node = pre;    // 当前节点，初始化为伪头节点
    int idx = 0;    // 节点编号，初始为0
    unordered_map<int, ListNode*>map;   // 哈希表存储节点编号和节点
    while(node != nullptr){    // 遍历链表，idx最终为节点总个数
        map[idx] = node;
        node = node->next;
        idx++;
    }
    map[idx - n - 1]->next = map[idx - n]->next;  // 根据节点编号获取删除节点的前一个节点和要删除的节点
    return pre->next;    // 返回头节点
}

//不引入额外空间
//快慢指针之间始终间隔n+1个节点
//当快指针为空时【到达链表尾部】，慢指针指向要删除节点的前一个节点。
ListNode* Solution::removeNthFromEnd(ListNode* head, int n){
    ListNode* CHead = new ListNode(0);
    CHead->next = head;
    ListNode* fast = CHead;
    ListNode* slow = CHead;
    int i = 0;
    while(i<n+1){
        fast = fast->next;
        i++;
    }
    while(fast!=NULL){
        fast = fast->next;
        slow = slow->next;
    }
    slow->next = slow->next->next;//删除操作
    return CHead->next;
}

//双指针
int Solution::removeDuplicates(vector<int>& nums) {
    int len = nums.size();
    if(len == 0) return 0;//一个元素都没有的情况，空数组返回0
    int l = 0, r = 0,k = 1;//双指针快慢指针均指向0，元素个数设置为1
    while(l <= r && r < len - 1){
        //快指针找到下一个元素不一样了
        if(nums[r] != nums[r + 1]){
            //快慢指针相等的情况，这时候无需排列，跳过做下次循环即可
            if(l == r){
                l++;
                r++;
                k++;
                continue;
            }
            l++;//慢指针加1，给新元素留位置
            nums[l] = nums[r + 1];//替换元素值
            k++;//不相同的元素加1
        }
        r++;//无论如何，慢指针每次循环后必定加1去找
    }
    return k;
}
//新建数组
int Solution::removeDuplicates_2(vector<int>& nums) {
    vector<int> temp;//创建一个中间数组
    temp.push_back(nums[0]);//现将nums中第一个元素放入数组中
    for(int i=0;i<nums.size()-1;i++){
        if(nums[i+1]!=nums[i]){
            temp.push_back(nums[i+1]);//只要i+1所指的数字和i所指的数字不相同就存入中间数组中
        }
    }
    int k=temp.size();
    for(int i=0;i<temp.size();i++){
        nums[i]=temp[i];//把中间数组的值赋值给nums数组
    }
   return k;
}

ListNode* Solution::deleteDuplicates(ListNode* head){
    if(!head) return head;
    ListNode* dum = new ListNode(0);
    ListNode* cur = dum;
    while(head){
        if(head->next == nullptr || head->val != head->next->val){
            cur->next = head;
            cur = head;
        }
        while (head->next && head->val == head->next->val)
        {
            head = head->next;
        }
        head = head->next;
    }
    cur->next = nullptr;
    return dum->next;
}

ListNode* Solution::deleteDuplicates_simple(ListNode* head){
    if(!head) return head;
    ListNode*cur = head;
    while(cur->next){
        if(cur->val != cur->next->val){
            cur = cur->next;
        }
        else cur->next = cur->next->next;
    }
    return head;
}

ListNode* Solution::partition(ListNode* head, int x){
    if(!head) return head;
    ListNode* sml_dum = new ListNode(0);
    ListNode* cur_sml = sml_dum;
    ListNode* big_dum = new ListNode(0);
    ListNode* cur_big = big_dum;
    while(head){
        if(head->val < x){
            cur_sml->next = head;
            cur_sml = cur_sml->next;
        }
        else {
            cur_big->next = head;
            cur_big = cur_big->next;
        }
        head = head->next;
    }
    cur_sml->next = big_dum->next;//两条链表连接，此处要使用仍指向头节点的big_dum指针
    cur_big->next = nullptr;//最末尾添加nullptr
    return sml_dum->next;
}

//模拟这个行索引的变化，在遍历s中把每个字符填到正确的行res[i]
string Solution::convert(string s, int numRows) {
    if (numRows < 2)
        return s;
    vector<string> rows(numRows);
    int i = 0, flag = -1;
	//用flag控制i的值从而控制字符应存的位置
	//达到临界值时，flag变化，从而操纵i变大或者缩小
    for (char c : s) {
        rows[i].push_back(c);
        if (i == 0 || i == numRows -1)
            flag = - flag;
        i += flag;
    }
    string res;
    for (const string &row : rows)
        res += row;
    return res;
}

//核心思想其实是动态规划
//设置了一个变量记录能到达的最远距离，若当前枚举到的位置下标已经超过最远距离，就说明当前这个位置是无法到达的。
bool Solution::canJump(vector<int>& nums) {
    int k = 0;
    for (int i = 0; i < nums.size(); i++) {
		//i说明你一步一步走，k说明你可以跳，如果你跳的最大距离还没有你一步一步走的快，那说明你跳不出去
        if (i > k) return false;
        k = max(k, i + nums[i]);
    }
    return true;
}
//就一个一个跳，记录能到的距离
int Solution::jump(vector<int>& nums){
    int k = 0;
    int result = 0;
    int end = 0;
    for(int i = 0;i<nums.size() - 1;i++){
        k = max(i + nums[i], k);
        if(i == end) 
        {
            end = k;
            result++;
        }
    }
    return result;
}

int Solution::maxSubArray(vector<int>& nums){ //一段一段计算，每一段的最大结果存储（最佳子结构）
    int len = nums.size();
    vector<int> dp(len); //dp[i] 代表以元素 nums[i] 为结尾的连续子数组最大和
    dp[0] = nums[0]; //即以 nums[0] 结尾的连续子数组最大和为 nums[0];
    int res = dp[0];
    for (int i = 1;i < len;i++){
        if(dp[i-1] > 0){
            dp[i] = dp[i - 1] + nums[i];
        }
        else {  //dp[i-1] <= 0 说明dp[i-1]对dp[i]产生副影响
            dp[i] = nums[i];
        }
        res = max(res, dp[i]);
    }
    return res;
}

vector<vector<int>> Solution::combinationSum(vector<int>& candidates, int target) {
	unordered_map<int, set<vector<int>>>dict;
	for (int i = 1; i <= target; i++)
	    for (int it : candidates) 
		if (i == it) dict[i].insert(vector<int>{it});           //返回该数字的组合
		else if (i > it)
		    for (auto ivec : dict[i - it]) {
			ivec.push_back(it);          //容器最后添加一个元素
			sort(ivec.begin(), ivec.end());
			if(dict[i].count(ivec)==0) //避免重复的组合
		            dict[i].insert(ivec);
		    }
	vector<vector<int>>ans;
	for (auto it : dict[target]) ans.push_back(it);
	return ans;
}
//剪枝
void Solution::backtrack(vector<int> &state, int target, vector<int> &choices, int start, vector<vector<int>> &res){
    // 子集和等于 target 时，记录解
    if (target == 0) {
        res.push_back(state);
        return;
    }
    // 遍历所有选择
    // 剪枝二：从 start 开始遍历，避免生成重复子集
    // 剪枝三：从 start 开始遍历，避免重复选择同一元素
    for (int i = start; i < choices.size(); i++) {
        // 剪枝一：若子集和超过 target ，则直接结束循环
        // 这是因为数组已排序，后边元素更大，子集和一定超过 target
        if (target - choices[i] < 0) {
            break;
        }
        // 剪枝四：如果该元素与左边元素相等，说明该搜索分支重复，直接跳过
        if (i > start && choices[i] == choices[i - 1]) {
            continue;
        }
        // 尝试：做出选择，更新 target, start
        state.push_back(choices[i]);
        // 进行下一轮选择
        backtrack(state, target - choices[i], choices, i + 1, res);
        // 回退：撤销选择，恢复到之前的状态
        state.pop_back();
    }
}
//回溯
vector<vector<int>> Solution::combinationSum2(vector<int>& candidates, int target){
    vector<int> state;              // 状态（子集）
    sort(candidates.begin(), candidates.end()); // 对 candidates 进行排序
    int start = 0;                  // 遍历起始点
    vector<vector<int>> res;        // 结果列表（子集列表）
    backtrack(state, target, candidates, start, res);
    return res;
}
void Solution::backtrack_2(vector<int> &choices, int start, vector<vector<int>> &res){
    if(start == choices.size() - 1){
        res.push_back(choices);
        return;
    }
    for(int i = start;i < choices.size();i++){
        swap(choices[i], choices[start]);// 固定元素位start
        backtrack_2(choices, start + 1, res);
        swap(choices[i], choices[start]);
    }
}

vector<vector<int>> Solution::permute(vector<int>& nums){
    int start = 0;
    vector<vector<int>> res;
    backtrack_2(nums, start, res);
    return res;
}

void Solution::backtrack_3(vector<int> &choices, int start, vector<vector<int>> &res){
    if(start == choices.size() - 1){
        res.push_back(choices);
        return;
    }
    set<int> st;// 初始化一个 Set ，用于排除重复的元素
    for(int i = start;i < choices.size();i++){
        if(st.find(choices[i]) != st.end()){ //在 Set​ 中，代表其是重复元素，因此 “剪枝” 。
            continue;
        }
        st.insert(choices[i]);
        swap(choices[i], choices[start]);// 固定元素位start
        backtrack_3(choices, start + 1, res);
        swap(choices[i], choices[start]);
    }
}

vector<vector<int>> Solution::permuteUnique(vector<int>& nums){
    int start = 0;
    vector<vector<int>> res;
    backtrack_3(nums, start, res);
    return res;
}


vector<vector<int>> Solution::combine(int n, int k){
    vector<int> state;
    vector<vector<int>> res;
    function<void(int)> dfs = [&](int i){
        int d  = k - state.size();
        if(d == 0){
            res.push_back(state);
            return;
        }
        if(i > d) dfs(i-1);
        state.push_back(i);
        dfs(i-1);
        state.pop_back();
    };
    dfs(n);
    return res;
}

vector<vector<int>> Solution::subsets(vector<int>& nums){
    vector<int> state;
    vector<vector<int>> res;
    int n = nums.size();
    function<void(int)> dfs = [&](int i){
        if(i == n){
            res.emplace_back(state);//与push_back作用相同，但运行效率方面更优秀,但是换了之后运行时间反而更小。。。。。。
            return;
        }
        dfs(i+1);//选择i+1
        state.push_back(nums[i]);
        dfs(i+1);//不选i+1
        state.pop_back();
    };
    dfs(0);
    return res;
}
//subsetsWithDup使用set去重复的版本
void back_subsetsWithDup(vector<int>& nums, int startindex){
    vector<vector<int>> res;
    vector<int> path;
    res.push_back(path);
    unordered_set<int> used;
    for(int i = startindex; i < nums.size();i++){
        if(used.find(nums[i]) != used.end()){
            continue;
        }
        used.insert(nums[i]);
        path.push_back(nums[i]);
        back_subsetsWithDup(nums, i + 1);
        path.pop_back();
    }
}
vector<vector<int>> Solution::subsetsWithDup(vector<int>& nums){
    sort(nums.begin(), nums.end());
    vector<int> state;
    vector<vector<int>> res;
    int n = nums.size();
    function<void(int)> dfs = [&](int i){
        res.push_back(state);
        for(int j = i;j < n;j++){
            if(j - 1 >= i && nums[j - 1] == nums[j]) continue;
            state.push_back(nums[j]);
            dfs(j + 1);
            state.pop_back();
        }
    };
    dfs(0);
    return res;
}

//深度优先搜索中插入剪枝
bool dfs(vector<vector<char>>& board, string word, int rows, int cols, int start){
    if(rows >= board.size() || rows < 0 || cols >= board[0].size() || cols < 0 || board[rows][cols] != word[start]) return false;
    if(start == word.size() - 1) return true;
    board[rows][cols] = '\0';//标记当前矩阵元素，防止重复访问
    bool res = dfs(board, word, rows + 1, cols, start + 1) ||
     dfs(board, word, rows, cols + 1, start + 1) ||
      dfs(board, word, rows, cols - 1, start + 1) ||
       dfs(board, word, rows - 1, cols, start + 1);
    board[rows][cols] = word[start];//标记之后还原
    return res;
}

bool Solution::exist(vector<vector<char>>& board, string word){
    int rows = board.size();
    int cols = board[0].size();
    for(int i = 0;i < rows;i++){
        for(int j = 0;j < cols;j++){
            if(dfs(board, word, i, j, 0)) return true;
        }
    }
}

int Solution::maxProfit(vector<int>& prices) {
    int cost = INT_MAX, profit = 0;
    for (int price : prices) {
        cost = min(cost, price);
        profit = max(profit, price - cost);
    }
    return profit;
}

//可转化为 求斐波那契数列的第 n 项，区别仅在于初始值不同
//青蛙跳台阶问题： f(0)=1 , f(1)=1 , f(2)=2 。
// 斐波那契数列问题： f(0)=0 , f(1)=1 , f(2)=1 。
// 第i项只与第i-1项和i-2项有关
int Solution::climbStairs(int n) {
    //动态规划
    //利用辅助变量sum使a,b两数交替上升
    int a = 1, b = 1, sum;
    for(int i = 0; i < n - 1; i++){
        sum = a + b;
        a = b;
        b = sum;
    }
    return b;
}
//另一种递归的方式
int f(int m, int n) {
    if (m == 0 || n == 0) return 1;
    return f(m - 1, n) + f(m, n - 1);   //第一个字母为A时f(m-1,n)；第一个字母为B时f(m,n-1)
}
int climbStairs(int n) {
    int fa = 0;
    if (n == 1) fa = 1;
    else {
        for (int i = 0; i < n / 2; i++) {//i为整个过程中上两阶的个数
            int m = n - 2 * i;//m为整个过程中上一阶的个数
            fa = fa + f(m, i);//排列组合，m个1，i个2
        }
    }
    return fa;
}

//递归思路
string Solution::countAndSay(int n){
    if(n == 1) return "1";
    string previous = countAndSay(n-1), result = "";
    int count = 1;
    for(int i = 0;i<previous.length();i++){
        if(previous[i]==previous[i+1]){
            count++;
        }
        else{
            result += to_string(count) + previous[i];
            count = 1;
        }
    }
    return result;
}

//考虑边界
int Solution::reverse_(int x) {
    int ans = 0;
    while(x != 0){
        int z = x % 10;
        if (INT32_MIN/10 > ans) return 0;
        if (INT32_MAX/10 < ans) return 0;
        ans = ans*10+z;
        x/=10;
    }
    return ans;
}

//遍历不同情况，同时考虑边界
int Solution::myAtoi(string s){
    int i=0,bndry = INT32_MAX/10;
    int length = s.size(),sign = 1;
    int res = 0;
    if (length==0) return 0;
    while(s[i]==' ')
       if(++i == length) return 0;
    if(s[i]=='-') sign = -1;
    if(s[i]=='-'||s[i]=='+') i++;
    for(int j=i;j<length;j++)
    {
        if(s[j]<'0' || s[j]>'9')break;
        if(res > bndry || res == bndry && s[j] > '7')
            return sign == 1 ? INT_MAX : INT_MIN;
        res = res * 10 + (s[j] - '0');
    }
    return res*sign;
}

//正则表达式匹配可转换为动态规划问题
bool Solution::isMatch(string s, string p) {
    int m = s.size() + 1, n = p.size() + 1;
    vector<vector<bool>> dp(m, vector<bool>(n, false));
    dp[0][0] = true;
    //初始化首行
    for(int j = 2; j < n; j += 2)
        dp[0][j] = dp[0][j - 2] && p[j - 1] == '*';
    for(int i = 1; i < m; i++) {
        for(int j = 1; j < n; j++) {
            dp[i][j] = p[j - 1] == '*' ?
                dp[i][j - 2] || dp[i - 1][j] && (s[i - 1] == p[j - 2] || p[j - 2] == '.'):
                dp[i - 1][j - 1] && (p[j - 1] == '.' || s[i - 1] == p[j - 1]);
        }
    }
    return dp[m - 1][n - 1];
}

bool isMatch(string s, string p) {
    int m = s.size() + 1, n = p.size() + 1;
    vector<vector<bool>> dp(m, vector<bool>(n, false));
    dp[0][0] = true;
    // 初始化首行
    for(int j = 2; j < n; j += 2)
        dp[0][j] = dp[0][j - 2] && p[j - 1] == '*';
    // 状态转移
    for(int i = 1; i < m; i++) {
        for(int j = 1; j < n; j++) {
            if (p[j - 1] == '*') {
                if (dp[i][j - 2]) dp[i][j] = true;                              // 1.
                else if (dp[i - 1][j] && s[i - 1] == p[j - 2]) dp[i][j] = true; // 2.
                else if (dp[i - 1][j] && p[j - 2] == '.') dp[i][j] = true;      // 3.
            } else {
                if (dp[i - 1][j - 1] && s[i - 1] == p[j - 1]) dp[i][j] = true;  // 1.
                else if (dp[i - 1][j - 1] && p[j - 1] == '.') dp[i][j] = true;  // 2.
            }
        }
    }
    return dp[m - 1][n - 1];
}
//动态规划
int Solution::minDistance(string word1, string word2){
        vector<vector<int>> dp(word1.size() + 1, vector<int>(word2.size() + 1, 0));
        for (int i = 0; i <= word1.size(); i++) dp[i][0] = i;
        for (int j = 0; j <= word2.size(); j++) dp[0][j] = j;
        for (int i = 1; i <= word1.size(); i++) {
            for (int j = 1; j <= word2.size(); j++) {
                if (word1[i - 1] == word2[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1];
                }
                else {
                    int a = min(dp[i-1][j-1], dp[i-1][j]);
                    dp[i][j] = min(a, dp[i][j - 1]) + 1;
                }
            }
        }
        return dp[word1.size()][word2.size()];
}
//动态规划，前n个数有多少种划分方式
//确定状态方程  f[i] += f[i-1] && f[i] += f[i - 2]
//确定规划路径  int i > 1 && s[i-2] != '0' && ((s[i-2] - '0') * 10 + (s[i-1] - '0') <= 26
int Solution::numDecodings(string s){
    int n = s.size();
    vector<int> f(n+1);
    f[0] = 1;
    for(int i = 1;i <= n;i++){
        if(s[i-1] != '0') f[i] += f[i-1];
        if(i > 1 && s[i-2] != '0' && ((s[i-2] - '0') * 10 + (s[i-1] - '0') <= 26)) f[i] += f[i - 2];
    }
    return f[n];
}


//双指针，相遇时结束，同时记录值的变化
int Solution::maxArea(vector<int>& height) {
    int i = 0, j = height.size() - 1, res = 0;
    while(i < j) {
        res = height[i] < height[j] ? 
            max(res, (j - i) * height[i++]): 
            max(res, (j - i) * height[j--]); 
    }
    return res;
}
//哈希表
string Solution::intToRoman(int num){
    int values[] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
    string reps[] = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
    string res;
    for (int i = 0; i < 13; i ++ )  //这里不使用图里的count了，一遍一遍来就行了
        while(num >= values[i])
        {
            num -= values[i];
            res += reps[i];
        }
    return res;
}

#include <map>

int Solution::romanToInt(string s) {
    int result=0;
    map<char,int> luomab={
        {'I',1},
        {'V',5},
        {'X',10},
        {'L',50},
        {'C',100},
        {'D', 500},
        {'M', 1000}
    };//初始化哈希表
    for(int i=0;i<s.length();i++)
    {
        if(luomab[s[i]] < luomab[s[i+1]])
                result -= luomab[s[i]];
        else
        {
            result += luomab[s[i]];
        }
    }
    return result;
}

string Solution::longestCommonPrefix(vector<string>& strs) {
    if(strs.empty()) return "";
    //问题简化为寻找最大最小串的相同字符个数
    const auto p = minmax_element(strs.begin(), strs.end());
    for (int i =0;i < p.first->size();++i)
        if(p.first->at(i) != p.second->at(i)) return p.first->substr(0, i);
    return *p.first;
}

vector<string> ans;
string s;
string MAPPING[10] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
vector<string> Solution::letterCombinations(string digits){
    int n = digits.length();
    if (n == 0) return {};
    s.clear();
    ans.clear();
    backtracking(digits, 0);
    return ans;

}
void Solution::backtracking(const string& digits, int index) {
    if (index == digits.size()) {
        ans.push_back(s);
        return;
    }
    int digit = digits[index] - '0';        // 将index指向的数字转为int
    string letters = MAPPING[digit];      // 取数字对应的字符集
    for (int i = 0; i < letters.size(); i++) {
        s.push_back(letters[i]);            // 处理
        backtracking(digits, index + 1);    // 递归，注意index+1，一下层要处理下一个数字了
        s.pop_back();                       // 回溯
    }
}

#include <functional>
vector<string> Solution::generateParenthesis(int n){
    int m = n * 2;
    vector<string> ans;
    string path(m, 0);
    function<void(int, int)> dfs = [&](int i, int open) {
        if (i == m) {
            ans.emplace_back(path);
            return;
        }
        if (open < n) { // 可以填左括号
            path[i] = '(';
            dfs(i + 1, open + 1);
        }
        if (i - open < open) { // 可以填右括号
            path[i] = ')';
            dfs(i + 1, open);
        }
    };
    dfs(0, 0);
    return ans;
}

ListNode* Solution::swapPairs(ListNode *head) {
    auto dummy = new ListNode(0, head); // 用哨兵节点简化代码逻辑
    auto node0 = dummy;
    auto node1 = head;
    while (node1 && node1->next) { // 至少有两个节点
        auto node2 = node1->next;
        auto node3 = node2->next;

        node0->next = node2; // 0 -> 2
        node2->next = node1; // 2 -> 1
        node1->next = node3; // 1 -> 3

        node0 = node1; // 下一轮交换，0 是 1
        node1 = node3; // 下一轮交换，1 是 3
    }
    return dummy->next; // 返回新链表的头节点
}

//KMP 经典题目。
//当出现字符串不匹配时，可以记录一部分之前已经匹配的文本内容，利用这些信息避免从头再去做匹配。
//前缀表具有告诉我们当前位置匹配失败，跳到之前已经匹配过的地方的能力。
void getNext(int* next, const string& s) {
    int j = -1;
    next[0] = j;
    for(int i = 1; i < s.size(); i++) { // 注意i从1开始
        while (j >= 0 && s[i] != s[j + 1]) { // 前后缀不相同了
            j = next[j]; // 向前回溯
        }
        if (s[i] == s[j + 1]) { // 找到相同的前后缀
            j++;
        }
        next[i] = j; // 将j（前缀的长度）赋给next[i]
    }
}
int Solution::strStr(string haystack, string needle) {
    if (needle.size() == 0) {
        return 0;
    }
    int next[needle.size()];
    getNext(next, needle);
    int j = -1; // // 因为next数组里记录的起始位置为-1
    for (int i = 0; i < haystack.size(); i++) { // 注意i就从0开始
        while(j >= 0 && haystack[i] != needle[j + 1]) { // 不匹配
            j = next[j]; // j 寻找之前匹配的位置
        }
        if (haystack[i] == needle[j + 1]) { // 匹配，j和i同时向后移动
            j++; // i的增加在for循环里
        }
        if (j == (needle.size() - 1) ) { // 文本串s里出现了模式串t
            return (i - needle.size() + 1);
        }
    }
    return -1;
}

int Solution::divide(int dividend, int divisor) {

    if (dividend == INT_MIN && divisor == -1) return INT_MAX;

    int res = 0;
    // 处理边界，防止转正数溢出
    // 除数绝对值最大，结果必为 0 或 1
    if (divisor == INT_MIN) {
        return dividend == divisor? 1 : 0;
    }

    // 被除数先减去一个除数
    if (dividend == INT_MIN) {
        dividend -= -abs(divisor);
        res += 1;
    }

    int sign = (dividend > 0) ^ (divisor > 0) ? -1 : 1;

    int ua = abs(dividend);
    int ub = abs(divisor);
    for (int i = 31; i >= 0; i--) {
        if ((ua >> i) >= ub) {
            ua = ua - (ub << i);
            // 代码优化：这里控制 ans 大于等于 INT_MAX
            if (res > INT_MAX - (1 << i)) {
                return INT_MIN;
            }
            res += 1 << i;
        }
    }
    // bug 修复：因为不能使用乘号，所以将乘号换成三目运算符
    return sign == 1 ? res : -res;

}

void Solution::nextPermutation(vector<int>& nums){
    int size = nums.size() - 2;
    while(size>=0 && nums[size]>=nums[size+1]){
        size--;
    }
    if(size < 0){
        sort(nums.begin(),nums.end());
    }
    else{
        int pos = nums.size() - 1;
        while(nums[pos]<=nums[size])
        {
            pos--;
        }
        swap(nums[pos], nums[size]);
        reverse(nums.begin()+size+1,nums.end());
    }
}

//二分查找
int Solution::search_two(vector<int>& nums, int target){
    int lo = 0, hi = nums.size() - 1;
    while(lo < hi){
        int mid = (lo + hi) / 2;
        if((nums[0] > target) ^ (nums[0] > nums[mid]) ^ (target > nums[mid]))
        {lo = mid +1;}
        else{
            hi = mid;
        }
    }
    return lo == hi && nums[lo] == target ? lo : -1;
}

vector<int> Solution::searchRange(vector<int>& nums, int target){
    int lo = 0, hi = nums.size() - 1;
    while(lo < hi){
        if(nums[lo] != target) lo++;
        if(nums[hi] != target) hi--;
        if((nums[lo]==target) & (nums[hi]==target)){return vector<int>{lo,hi};}
    }
    return vector<int>{-1, -1};

}

    // lower_bound 返回最小的满足 nums[i] >= target 的 i
    // 如果数组为空，或者所有数都 < target，则返回 nums.size()
    // 要求 nums 是非递减的，即 nums[i] <= nums[i + 1]

    // 闭区间写法
int lower_bound(vector<int> &nums, int target) {
    int left = 0, right = (int) nums.size() - 1; // 闭区间 [left, right]
    while (left <= right) { // 区间不为空
        // 循环不变量：
        // nums[left-1] < target
        // nums[right+1] >= target
        int mid = left + (right - left) / 2;
        if (nums[mid] < target)
            left = mid + 1; // 范围缩小到 [mid+1, right]
        else
            right = mid - 1; // 范围缩小到 [left, mid-1]
        }
    return left; // 或者 right+1
}

    // 左闭右开区间写法
int lower_bound2(vector<int> &nums, int target) {
    int left = 0, right = nums.size(); // 左闭右开区间 [left, right)
    while (left < right) { // 区间不为空
            // 循环不变量：
            // nums[left-1] < target
            // nums[right] >= target
        int mid = left + (right - left) / 2;
        if (nums[mid] < target)
            left = mid + 1; // 范围缩小到 [mid+1, right)
        else
            right = mid; // 范围缩小到 [left, mid)
    }
    return left; // 或者 right
}

    // 开区间写法
int lower_bound3(vector<int> &nums, int target) {
    int left = -1, right = nums.size(); // 开区间 (left, right)
    while (left + 1 < right) { // 区间不为空
            // 循环不变量：
            // nums[left] < target
            // nums[right] >= target
        int mid = left + (right - left) / 2;
        if (nums[mid] < target)
            left = mid; // 范围缩小到 (mid, right)
        else
            right = mid; // 范围缩小到 (left, mid)
    }
    return right; // 或者 left+1
}

vector<int> Solution::searchRange_2(vector<int> &nums, int target) {
    int start = lower_bound(nums, target); // 使用其中一种写法即可
    if (start == nums.size() || nums[start] != target)
        return {-1, -1};
        // 如果 start 存在，那么 end 必定存在
    int end = lower_bound(nums, target);
    return {start, end};
}
int Solution::searchInsert(vector<int>& nums, int target) {
    int size = nums.size() - 1;
    for(int i = 0; i <= size;i++){
        if(nums[i] == target) return i;
        else if (nums[i] > target)
        {
            return i;
        }
        
    }
}

//哈希表判断数出现与否，行（列）代表数字，列（行）代表是否出现
bool Solution::isValidSudoku(vector<vector<char>>& board) {
    int row[9][10] = {0};// 哈希表存储每一行的每个数是否出现过，默认初始情况下，每一行每一个数都没有出现过
    // 整个board有9行，第二维的维数10是为了让下标有9，和数独中的数字9对应。
    int col[9][10] = {0};// 存储每一列的每个数是否出现过，默认初始情况下，每一列的每一个数都没有出现过
    int box[9][10] = {0};// 存储每一个box的每个数是否出现过，默认初始情况下，在每个box中，每个数都没有出现过。整个board有9个box。
    for(int i=0; i<9; i++){
        for(int j = 0; j<9; j++){
            // 遍历到第i行第j列的那个数,我们要判断这个数在其所在的行有没有出现过，
            // 同时判断这个数在其所在的列有没有出现过
            // 同时判断这个数在其所在的box中有没有出现过
            if(board[i][j] == '.') continue;
            int curNumber = board[i][j]-'0';
            if(row[i][curNumber]) return false; 
            if(col[j][curNumber]) return false;
            if(box[j/3 + (i/3)*3][curNumber]) return false;

            row[i][curNumber] = 1;// 之前都没出现过，现在出现了，就给它置为1，下次再遇见就能够直接返回false了。
            col[j][curNumber] = 1;
            box[j/3 + (i/3)*3][curNumber] = 1;
        }
    }
    return true;
}

string Solution::multiply(string num1, string num2) {
    vector<int> A, B;
    int n = num1.size(), m = num2.size();
    for (int i = n - 1; i >= 0; i -- ) A.push_back(num1[i] - '0'); //反向存贮
    for (int i = m - 1; i >= 0; i -- ) B.push_back(num2[i] - '0');
    vector<int> C(n + m);
    for (int i = 0; i < n; i ++ )
        for (int j = 0; j < m; j ++ )
            C[i + j] += A[i] * B[j];
    int t = 0;  //存贮进位
    for (int i = 0; i < C.size(); i ++ ) {
        t += C[i];
        C[i] = t % 10;
        t /= 10;
    }
    int k = C.size() - 1;
    while (k > 0 && !C[k]) k -- ;  //去除前导0
    string res;
    while (k >= 0) res += C[k -- ] + '0';  //反转
    return res;
}

vector<vector<int>> Solution::insert(vector<vector<int>>& intervals, vector<int>& newInterval){
    vector<vector<int>> res;
    int index = 0;//intervals的索引
    //找到合并的区间
    while(index < intervals.size() && intervals[index][1] < newInterval[0]){
        res.push_back(intervals[index++]);
    }
    //合并区间
    //intervals[index]起始位置 <= newInterval终止位置,就一直合并下去
    while(index < intervals.size() && intervals[index][0] <= newInterval[1]){
        newInterval[0] = min(intervals[index][0], newInterval[0]);
        newInterval[1] = max(intervals[index][1], newInterval[1]);
        index++;
    }
    //比较特殊的情况，直接加入，也可以是上述处理完后形成这种不需要比较的区间
    res.push_back(newInterval);
    //合并之后的区间加入
    while(index < intervals.size()){
        res.push_back(intervals[index++]);
    }
    return res;
}

int Solution::lengthOfLastWord(string s){
    if(s.empty()) return 0;
    s += " ";//确保最后能走出循环。根据空格判断一个单词的终止
    string temp = "";
    vector<string> res;
    for(char ch : s){
        if(ch == ' '){
            if(!temp.empty()){
                res.push_back(temp);
                temp.clear();
            }
        }
        else temp+=ch;
    }
    if(res.empty())
    return 0;
    return res.back().size();//.back最后一个元素的引用
}

void Solution::rotate(vector<vector<int>>& matrix){
    int n = matrix.size();
    for(int i = 0;i < n/2;i++){
        for(int j = 0;j < (n+1)/2;j++){
            int tmp = matrix[i][j];
            matrix[i][j] = matrix[n-1-j][i];
            matrix[n-1-j][i] = matrix[n-1-i][n-1-j];
            matrix[n-1-i][n-1-j] = matrix[j][n-1-i];
            matrix[j][n-1-i] = tmp;
        }
    }
}

vector<int> Solution::spiralOrder(vector<vector<int>>& matrix){
    int mat_d = matrix.size() - 1; //下边界
    int mat_r = matrix[0].size() - 1; //右边界
    int mat_u = 0; //上边界
    int mat_l = 0; //左边界
    vector<int> res;
    if(matrix.empty()) return res;
    while(true){
        for(int i = mat_l;i <= mat_r;++i) res.push_back(matrix[mat_u][i]);
        if(++mat_u > mat_d) break;
        for(int i = mat_u;i <= mat_d;++i) res.push_back(matrix[i][mat_r]);
        if(--mat_r < mat_l) break;
        for(int i = mat_r;i >= mat_l;--i) res.push_back(matrix[mat_d][i]);
        if(--mat_d < mat_u) break;
        for(int i = mat_d;i >= mat_u;--i) res.push_back(matrix[i][mat_l]);
        if(++mat_l > mat_r) break;
    }
    return res;
}

vector<vector<int>> Solution::generateMatrix(int n){
    int startx, starty = 0;
    vector<vector<int>> res(n, vector<int>(n));//新建二维矩阵
    int loop = n/2;
    int mid = n/2;
    int count = 1;
    int offset = 1;
    int i,j;
    while(loop--){
        i = startx;
        j = starty;
        for(j = startx;j < n - offset;j++){
            res[startx][j] = count++;
        }
        for(i = startx;i < n - offset;i++){
            res[i][j] = count++;
        }
        for(;j > starty;j--){
            res[i][j] = count++;
        }
        for(;i > starty;i--){
            res[i][j] = count++;
        }
        startx++;
        starty++;
        offset+=1;
    }
    if(n % 2){
        res[mid][mid]=count;
    }
    return res;
}

void Solution::setZeroes(vector<vector<int>>& matrix){
    int m = matrix.size();
    int n = matrix[0].size();
    vector<int> line(m, 0);
    vector<int> col(n, 0);
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(matrix[i][j]==0){
                line[i]=1;
                col[j]=1;
            }
        }
    }
    for(int i=0;i<m;i++){
        if(line[i]==1){
            for(int j=0;j<n;j++) matrix[i][j]=0;
        }
    }
    for(int i=0;i<n;i++){
        if(col[i]==1){
            for(int j=0;j<m;j++) matrix[j][i]=0;
        }
    }
}

bool Solution::searchMatrix(vector<vector<int>>& matrix, int target){
    int m = matrix.size();//行
    int n = matrix[0].size();//列
    for(int i = 0;i < m;i++){
        if(matrix[i][n-1] > target){
            for(int j=0;j < n-1;j++){
                if(matrix[i][j]==target) return true;
            }
        }
        if(matrix[i][n-1]==target) return true;
    }
    return false;
}

bool searchMatrix1(vector<vector<int>>& matrix, int target) {
    int row = matrix.size(), col = matrix[0].size();
        // 右上角开始查找
    for(int i = 0, j = col-1; i < row && j >= 0;) {
        if(matrix[i][j] == target) //等于target
            return true;
        else if(matrix[i][j] > target) //大于target,向左（列变小）
            j--;
        else if(matrix[i][j] < target) //小于target.向下（行变大）
            i++;
    }
    return false;
}



vector<vector<string>> Solution::groupAnagrams(vector<string>& strs){
    vector<vector<string>> res; //结果数组
    unordered_map<string, vector<string>> v_map; //哈希表
    for(auto&str : strs){  //值的引用，对其的操作会影响到原容器
        string key(str);
        sort(key.begin(), key.end());
        v_map[key].push_back(str);
    }
    for(auto&pair : v_map){
        res.push_back(pair.second);
    }
    return res;
}

double Solution::myPow(double x, int n){
    if(n == 0) return 1;
    if(n == -1) return 1/x;
    if(n == 1) return x;
    double half = myPow(x, n/2);
    double rest = myPow(x, n%2);
    return rest*half*half;    
}
//限制是每次只能向下或者向右
int Solution::uniquePaths(int m,int n){  
    vector<vector<int>> dp(m, vector<int>(n, 0));  //dp[i - 1][j] 表示从(0, 0)的位置到(i - 1, j)有几条路径
    for(int i = 0;i < m; i++) dp[i][0] = 1;  //初始化边界
    for(int j = 0;j < n; j++) dp[0][j] = 1;
    for(int i = 1;i < m; i++){
        for(int j = 1;j < n; j++){
            dp[i][j] = dp[i-1][j]+dp[i][j-1];  //想要求dp[i][j]，只能有两个方向来推导出来，即dp[i - 1][j] 和 dp[i][j - 1]
        }
    }
    return dp[m-1][n-1];
}

int Solution::uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid){
    //起始点或者终点有障碍
    if(obstacleGrid[0][0] == 1 || obstacleGrid[obstacleGrid.size() - 1][obstacleGrid[0].size() - 1] == 1) return 0;
    vector<vector<int>> dp(obstacleGrid.size(), vector<int>(obstacleGrid[0].size(), 0));
    for(int i = 0;i < obstacleGrid.size() && obstacleGrid[i][0] == 0; i++) dp[i][0] = 1;  //初始化边界
    for(int j = 0;j < obstacleGrid[0].size() && obstacleGrid[0][j] == 0; j++) dp[0][j] = 1;
    for(int i = 1;i < obstacleGrid.size(); i++){
        for(int j = 1;j < obstacleGrid[0].size(); j++){
            if(obstacleGrid[i][j]==1) continue;
            dp[i][j] = dp[i-1][j]+dp[i][j-1];
        }
    }
    return dp[obstacleGrid.size()-1][obstacleGrid[0].size()-1];
}

int Solution::minPathSum(vector<vector<int>>& grid){
    int m = grid.size();
    int n = grid[0].size();
    vector<vector<int>> dp(m, vector<int>(n, 0));
    dp[0][0] = grid[0][0];

    for(int i = 1;i < m;i++) dp[i][0] = grid[i][0] + dp[i-1][0];
    for(int j = 1;j < n;j++) dp[0][j] = grid[0][j] + dp[0][j-1];
    for(int i = 1;i < m; i++){
        for(int j = 1;j < n;j++){
            dp[i][j] = grid[i][j] + min(dp[i][j-1], dp[i-1][j]);
        }
    }
    return dp[m-1][n-1];
}
//有进位的情况
vector<int> Solution::plusOne(vector<int>& digits){
    bool CF = false;
    int ptr = digits.size() - 1;
    do{
        if(ptr >= 0){
            digits[ptr]++;
            CF=digits[ptr]>=10;//判断是否产生进位
            digits[ptr]%=10;
            ptr-=1;
        }
        else{
            digits.insert(digits.begin(), 1);//最高为加1
            CF = false;
        }
    }while(CF);
    return digits;
}

string Solution::addBinary(string a, string b){
    int al = a.size();
    int bl = b.size();
    while(al > bl){
        b = '0' + b;
    }
    while(bl > al){
        a = '0' + a;
    }
	int carry = 0;  //进位
	for (int i = al-1; i >= 0; i--)
	{
		int sum = a[i] - '0' + b[i] - '0' + carry;
		a[i] = (sum) % 2+'0';//本位数值
		carry = sum / 2;//进位更新
	}
	if (carry > 0)//有溢出
		a = '1' + a;
    return a;
}
//字符串转化为整数后进行处理
string addBinary_(string a, string b) {
    //从后面开始遍历
    int i = a.size() - 1;
    int j = b.size() - 1;
    string sum;
    int carry = 0;
    for(; i >= 0 || j >= 0 || carry > 0; --i, --j)
    {
        if(i >= 0){
            carry += a[i] - '0';
        }
        if(j >= 0){
            carry += b[j] - '0';
        }
        //将carry取余2的整数结果化成字符串然后从后往前添加到sum中
        sum.push_back((carry % 2) + '0');
        //判断是否需要进位
        carry /= 2;
    }
    //反转字符串输出
    reverse(sum.begin(), sum.end());
    return sum;
}
// 二分法查找
// 猜的数平方以后大了就往小了猜；
// 猜的数平方以后恰恰好等于输入的数就找到了；
// 猜的数平方以后小了，可能猜的数就是，也可能不是。
int Solution::mySqrt(int x){
    if(x==0) return 0;
    if(x==1) return 1;
    int left = 1;
    int right = x / 2;
    //// 在区间 [left..right] 查找目标元素
    while(left < right){
        int mid = left + (right - left + 1)/2;
        if(mid > x /mid){
            //// 下一轮搜索区间是 [left..mid - 1]
            right = mid - 1;
        }
        else{
            //// 下一轮搜索区间是 [mid..right]
            left = mid;
        }
    }
    return left;
}

string Solution::simplifyPath(string path){
    vector<string> stk;
    int n = path.size(),i = 0;
    string str = "";
    while (i < n)
    {
        if(path[i]=='/') ++i;//遇到‘/’不处理，最后输出添加‘/’
        else{
            for(;i<n && path[i] != '/';++i){
                str += path[i];
            }
            if(str == ".") ;
            else if(str ==".."){
                if(!stk.empty()) stk.pop_back();
            }
            else stk.push_back(str);
            str = "";//清空，用于下次循环
        }
    }
    if(stk.empty()) return "/";
    string ans = "";
    for(auto& s : stk){
        ans += ('/' + s);//补全‘/’，最后不加
    }
    return ans;
}

int Solution::removeDuplicates_3(vector<int>& nums){
    int count = 2;
    if(nums.size() == 1) return 1;
    for(int i = 2;i < nums.size();i++){
        if(nums[i] != nums[count - 2]){
            nums[count++] = nums[i];
        }
    }
    return count;
}

int find(vector<int>& nums, int low, int high, int target){
    while(low < high){
        int mid = (low + high) / 2;
        if(nums[mid] >= target) high = mid;//有序数组，mid右边一定比mid所在位置的值大，调整右边指针
        else
        {
            low = mid + 1;//有序数组，mid左边一定比mid所在位置的值小，调整左边指针
        }
    }
    return nums[high]==target?high:-1;
}

bool Solution::search(vector<int>& nums, int target){
    int n = nums.size();
    int l = 0, r = n - 1;
    // 恢复二段性
    while (l < r && nums[0] == nums[r]) r--;//去除两边重复值

    // 第一次二分，找旋转点
    while (l < r) {
        int mid = (l + r + 1) >> 1;
        if (nums[mid] >= nums[0]) {
            l = mid;
        } else {
            r = mid - 1;
        }
    }
        
    int idx = n;
    if (nums[r] >= nums[0] && r + 1 < n) idx = r + 1;

    // 第二次二分，找目标值
    int ans = find(nums, 0, idx - 1, target);
    if (ans != -1) return true;
    ans = find(nums, idx, n - 1, target);
    return ans != -1;

}

vector<string> Solution::str_grayCode(int n){
    if(n == 1) return{"0", "1"};
    vector<string> pregraycode = str_grayCode(n - 1);
    vector<string> Graycode;
    for(int i = 0;i < pregraycode.size();i++){
        Graycode.push_back("0" + pregraycode[i]);
    }

    for(int i = pregraycode.size() - 1;i >= 0;i--){
        Graycode.push_back("1" + pregraycode[i]);
    }
    return Graycode;
}

vector<int> Solution::grayCode(int n){
    if(n == 1) return{0, 1};
    vector<int> pregraycode = grayCode(n - 1);

    for(int i = pregraycode.size() - 1;i >= 0;i--){
        pregraycode.push_back(pregraycode[i] + pow(2, n-1));
    }
    return pregraycode;
}
