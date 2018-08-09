//
// Created by chijinxin on 18-8-9.
//
#include <iostream>
#include <vector>
#include "Tree33.hpp"

using namespace std;

void digui(TreeNode* root, vector<vector<int>> &Paths, vector<int> path)
{
    if(root->left == NULL && root->right == NULL)
    {
        Paths.push_back(path);
        //path.clear();
        return;
    }
    if(root->left != NULL)
    {
        path.push_back(root->left->val);
        digui(root->left, Paths, path);
    }
    if(root->right != NULL)
    {
        path.push_back(root->right->val);
        digui(root->right, Paths, path);
    }
}



vector<vector<int>> BTreePaths(TreeNode* root)
{
    vector<vector<int>> Paths;
    if(root==NULL) return Paths;
    vector<int> path;
    path.push_back(root->val);
    digui(root, Paths, path);
    return Paths;

}

void ff(TreeNode *root,vector<string>&Paths,string strPaths)
{
    if(root->left==NULL&&root->right==NULL)
    {
        Paths.push_back(strPaths);
        return;
    }
    if(root->left!=NULL)
        ff(root->left,Paths,strPaths+"->"+to_string(root->left->val) );
    if(root->right!=NULL)
        ff(root->right,Paths,strPaths+"->"+to_string(root->right->val) );

}
vector<string> binaryTreePaths(TreeNode* root) {
    // Write your code here
    vector<string>Paths;
    if(root==NULL) return Paths;
    ff(root,Paths,to_string(root->val) );
    return Paths;
}



public void findPath(Node root ,int n){
    if(root!=null)
    {
        stack.push(root);
        n = n-root.value;
        if(n==0 && root.left==null && root.right==null){
            for(Node no:stack){
                System.out.print(no.value);
            }
            System.out.println();
        }

        findPath(root.left, n);
        findPath(root.right, n);
        stack.pop();
    }

    public int minNumberInRotateArray(int [] array)
    {

        if(array == null)
            return 0;
        int i = 0, j = array.length - 1, mid = 0;
        while(array[i] >= array[j])
        {
            if(j-i==1)
            {
                mid = j;
                break;
            }

            mid = (i+j)/2;
            //如果array[i]==array[j]==array[mid]
            //则不能用二分查找，因为不确定array[mid]位于哪个有序子数组
            //只能用顺序查找
            if(array[i]==array[j]&&array[j]==array[mid])
            {
                //在除了Main()方法中调用其他方法需要new实例之外，其他方法中调用同一个类中的方法直接用：方法名（实参）即可，不需要其他操作
                return findInOrder(array,i,j);
            }

            if(array[i]<=array[mid])
                i=mid;
            else if(array[mid]<=array[j])
                j=mid;
        }
        return array[mid];
    }
    //顺序查找
    public int findInOrder(int[] a, int in1, int in2)
    {
        int k = a[in1];
        for(int i = in1+1; i < in2; i++)
            if(a[i]<k)
                k=a[i];
        return k;
    }

    /*
     * 最长递增子序列
     */
    private static int lis(int[] arr, int length){
        int lis[] = new int[length];

        //init
        for(int i = 0; i < length; i++)
            lis[i] = 1;

        for(int i = 1; i < length; i++)
        {
            for(int j = 0; j < i; j++)
            {

                if(arr[i] > arr[j])
                {
                    if(lis[j] + 1 > lis[i])
                        lis[i] = lis[j] + 1;
                }
                else{
                    if(lis[j] > lis[i])
                        lis[i] = lis[j];
                }
            }
        }

        /*
         * 最短编辑距离
         */

        public class Levenshtein {

            /**
             * 获取两字符串的相似度
             * @param source 初始串
             * @param target 比较串
             * @return 相似度
             */
        public static float getSimilarityRatio(String source, String target) {
                return 1 - (float) compare(source, target) / Math.max(source.length(), target.length());
            }

        private static int compare(String source, String target) {

                int matrix[][];
                int n = source.length();
                int m = target.length();
                int i; //source索引
                int j; //target索引
                char ch1;
                char ch2;
                int temp; //记录相同字符,值为0/1

                if (n == 0)
                    return m;

                if (m == 0)
                    return n;

                matrix = new int[n + 1][m + 1];
                for (i = 0; i <= n; i++) { //初始化第一列
                    matrix[i][0] = i;
                }

                for (j = 0; j <= m; j++) { //初始化第一行
                    matrix[0][j] = j;
                }

                for (i = 1; i <= n; i++) { //遍历source
                    ch1 = source.charAt(i - 1);
                    //匹配target
                    for (j = 1; j <= m; j++) {
                        ch2 = target.charAt(j - 1);
                        if (ch1 == ch2) temp = 0;
                        else temp = 1;
                        //左+1,上+1,左上+temp 取最小
                        matrix[i][j] = min(matrix[i - 1][j] + 1, matrix[i][j - 1] + 1, matrix[i - 1][j - 1] + temp);
                    }
                }
                return matrix[n][m];
            }

        private static int min(int one, int two, int three) {
                return (one = one < two ? one : two) < three ? one : three;
            }

        public static void main(String[] args) {
                String source = "中国";
                String target = "中国人";
                System.out.println("similarityRatio=" + Levenshtein.getSimilarityRatio(source, target));
            }
        }


int main()
{
    Tree tree;
    vector<vector<int>> Paths1 = BTreePaths(tree.root);
    vector<string> Paths2 = binaryTreePaths(tree.root);
    cout<<endl;
    return 0;
}
