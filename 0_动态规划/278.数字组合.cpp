/*

题目描述：

给定N个正整数A1,A2,…,AN，从中选出若干个数，使它们的和为M，求有多少种选择方案。

输入格式
第一行包含两个整数N和M。

第二行包含N个整数，表示A1,A2,…,AN。

输出格式
包含一个整数，表示M。

数据范围
1≤N≤100,
1≤M≤10000,
1≤Ai≤1000
输入样例：
4 4
1 1 2 2
输出样例：
3

*/


/*
解法1：
time : O(N*M)
space : O(N)
*/

#include<iostream>
#include<algorithm>
#include<string.h>
using namespace std;
const int N = 10010;
int n, m;
int f[N];
int main()
{
    cin>>n>>m;
    // memset(f, -1, sizeof f);
    f[0] = 1;
    for(int i = 0; i < n; i++)
    {
        int a;
        cin>>a;
        for(int j = m; j >= a; j--)
        {
            f[j] += f[j - a];
        }
    }
    cout<<f[m]<<endl;
}

/*
解法2：
time : 
space : 
*/



/*
解法3：
time : 
space : 
*/
