/*

题目描述：

给你一个n种面值的货币系统，求组成面值为m的货币有多少种方案。

输入格式
第一行，包含两个整数n和m。

接下来n行，每行包含一个整数，表示一种货币的面值。

输出格式
共一行，包含一个整数，表示方案数。

数据范围
n≤15,m≤3000
输入样例：
3 10
1
2
5
输出样例：
10

*/


/*
解法1：完全背包问题扩展
time : O(N*M)
space : O(N)
*/

#include<iostream>
#include<algorithm>
using namespace std;
typedef long long LL;
const int N = 3010, M = 20;
int n, m;
int a[N];
LL f[N]; 
int main()
{
    cin>>n>>m;
    f[0] = 1;
    for(int i = 1; i <= n; i++)
    {
        cin>>a[i];
        for(int j = 0; j <= m; j ++)
        {
            if(j >= a[i])
            {
                f[j] += f[j - a[i]];
            }
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
