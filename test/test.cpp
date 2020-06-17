//
// Created by chijx on 2020/5/19.
//

#include <iostream>
#include <vector>
#include <unordered_map>
#include <set>
using namespace std;

// 有效的IP地址
bool isValid(string t){  //判断是否为合法的IP地址的一段
  int temp = atoi(t.c_str());
  if(temp >= 0 && temp<=255 &&(t.size() == 1 || t[0] != '0'))
    return true;
  return false;
}
void dfs(int l, string s, string t, vector<string> &res)  //s表示已划分的字符串，t表示剩余未划分的字符串, l是划分的层级
{
  if (l==3) {
    if(isValid(t)){
      res.push_back(s+t);
    }
    return;
  }
  for(int i=1; i<4 && i<t.size(); i++) {
    string cur = t.substr(0, i);
    if(isValid(cur)){
      dfs(l+1, s+cur+'.', t.substr(i), res);
    }
  }
}

vector<string> restoreIpAddresses(string t) {
  vector<string> result;
  string s;
  dfs(0, s, t, result);
  return result;
}

int main(){
  vector<string> res = restoreIpAddresses("25525511135");
  for(auto& r : res) {
    cout << r <<endl;
  }
  return 0;
}


//int p[10]={0};
//bool vis[10]={0};
//int n;
//void dfs(int x)
//{
//  if (x==n+1) {
//    for(int i=1;i<=n;i++) cout<<p[i]<<" ";
//    cout<<endl;
//    return;
//  }
//  for (int i=1;i<=n;i++) {
//    if (vis[i]==false)  //加上这句代码，也就是剪枝，可以避免下面的递归
//    {
//      p[x] = i;
//      vis[i] = true;
//      dfs(x+1);
//      // 回溯
//      vis[i] = false;
//    }
//  }
//}
//
//int main()
//{
//  n=4;
//  dfs(1);
//  return 0;
//}


////无重复最长子串
//int lengthOfLongestSubstring(string s) {
//  int result = 0, l=0, r=0;
//  set<char> tmp;
//  while (r<s.length()) {
//    if(tmp.find(s.at(r)) == tmp.end()) {
//      tmp.insert(s.at(r));
//      r++;
//      result = max(result, r-l);
//    } else {
//      tmp.erase(s.at(l));
//      l++;
//    }
//  }
//  return result;
//}
//
//int main(){
//  cout << lengthOfLongestSubstring("dvdf") << endl;
//}

// 两数之和
//vector<int> twoSum(vector<int>& nums, int target) {
//  unordered_map<int,int> tmp;
//  vector<int> result;
//  for(int i=0; i<nums.size(); i++) {
//    // 找到
//    auto iter = tmp.find(nums[i]);
//    if( iter != tmp.end() ) {
//        result.push_back(iter->second);
//        result.push_back(i);
//       tmp.erase(iter);
//    } else {
//      tmp[target-nums[i]] = i;
//    }
//  }
//  return result;
//}
//
//int main(){
//  vector<int> nums{2, 7, 11, 15};
//  int target = 9;
//  auto result = twoSum(nums, target);
//  for_each(result.begin(), result.end(), [](int r){
//    cout << r << " " << endl;
//  });
//  return 0;
//}