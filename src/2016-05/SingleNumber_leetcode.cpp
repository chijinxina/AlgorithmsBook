//
// Created by chijinxin on 2017/9/23.
//
#include <iostream>
using namespace std;

int A[9]={1,1,2,8,7,2,8,7,6};

int main(){
    int temp=0;
    for(int i=0;i<9;i++){
        temp^=A[i];
    }
    cout<<temp;
    return 0;
}
