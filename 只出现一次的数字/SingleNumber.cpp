//
// Created by chijx on 2020/5/9.
//
#include <iostream>
#include <vector>
using namespace std;
/*
 * 给定一个非空整数数组，除了某个元素只出现一次以外，其余每个元素均出现`两次`。找出那个只出现了一次的元素。
 * 解：
 * 交换律：a ^ b ^ c <=> a ^ c ^ b
 * 任何数于0异或为任何数 0 ^ n => n
 * 相同的数异或为0: n ^ n => 0
 */
int SingleNumber(vector<int>& nums) {
  int result=0;
  for(auto num : nums) {
    result = result ^ num;
  }
  return result;
}

int main() {
  vector<int> nums{4,1,2,1,2};
  cout << SingleNumber(nums) <<endl;
  return 0;
}