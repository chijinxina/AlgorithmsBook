//
// Created by chijinxin on 18-8-11.
//
#include <iostream>
#include "Tree33.hpp"
using namespace std;
/*
 * 1、首先设置标志位result = false，因为一旦匹配成功result就设为true，
 * 剩下的代码不会执行，如果匹配不成功，默认返回false
 * 2、递归思想，如果根节点相同则递归调用DoesTree1HaveTree2（），
 * 如果根节点不相同，则判断tree1的左子树和tree2是否相同，
 * 再判断右子树和tree2是否相同
 * 3、注意null的条件，HasSubTree中，如果两棵树都不为空才进行判断，
 * DoesTree1HasTree2中，如果Tree2为空，则说明第二棵树遍历完了，即匹配成功，
 * tree1为空有两种情况（1）如果tree1为空&&tree2不为空说明不匹配，
 * （2）如果tree1为空，tree2为空，说明匹配。
 */

bool isSubTree(TreeNode* root1, TreeNode* root2)
{
    if(root2==NULL) return true;
    if(root1==NULL) return false;
    if(root1->val == root2->val)
    {
        return isSubTree(root1->left, root2->left) && isSubTree(root1->right, root2->right);
    }
    else return false;
}

bool HasSubTree(TreeNode* root1, TreeNode* root2)
{
    if(root1==NULL || root2==NULL) return false;
    return isSubTree(root1,root2) || HasSubTree(root1->left,root2) || HasSubTree(root1->right, root2);
}

void TRUE(bool flag)
{
    if(flag) cout<<"TRUE"<<endl;
    else cout<<"FALSE"<<endl;
}

int main()
{
    Tree t;
    //flag==1 （3（1,4））
    Tree subt(1);
    TRUE(HasSubTree(t.root, subt.root));
}
