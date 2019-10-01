/*

题目描述：

阿福是一名经验丰富的大盗。趁着月黑风高，阿福打算今晚洗劫一条街上的店铺。

这条街上一共有 N 家店铺，每家店中都有一些现金。

阿福事先调查得知，只有当他同时洗劫了两家相邻的店铺时，街上的报警系统才会启动，然后警察就会蜂拥而至。

作为一向谨慎作案的大盗，阿福不愿意冒着被警察追捕的风险行窃。

他想知道，在不惊动警察的情况下，他今晚最多可以得到多少现金？

输入格式
输入的第一行是一个整数 T，表示一共有 T 组数据。

接下来的每组数据，第一行是一个整数 N ，表示一共有 N 家店铺。

第二行是 N 个被空格分开的正整数，表示每一家店铺中的现金数量。

每家店铺中的现金数量均不超过1000。

输出格式
对于每组数据，输出一行。

该行包含一个整数，表示阿福在不惊动警察的情况下可以得到的现金数量。

数据范围
1≤T≤50,
1≤N≤105
输入样例：
2
3
1 8 2
4
10 7 6 14
输出样例：
8
24
样例解释
对于第一组样例，阿福选择第2家店铺行窃，获得的现金数量为8。

对于第二组样例，阿福选择第1和4家店铺行窃，获得的现金数量为10+14=24。

*/


/*
解法1：类似背包、朴素做法
time : O(T*N)
space : O(N)
*/

#include<iostream>
#include<algorithm>
using namespace std;
const int T = 55, N = 100010;
int n, t;
int a[N], f[N];
int main()
{
    cin>>t;
    while(t--)
    {
        cin>>n;
        for(int i = 2; i <= n + 1; i++)
        {
            cin>>a[i];
            f[i] = max(f[i - 1], f[i - 2] + a[i]);
        }
        cout<<f[n + 1]<<endl;
    }
}


/*
解法2： 状态机做法，只需用到前f[i - 1]的状态
time : O(T*N)
space : O(N)
*/

#include<iostream>
#include<algorithm>
using namespace std;
const int T = 55, N = 100010;
int n, t;
int a[N], f[N][2];
int main()
{
    cin>>t;
    while(t--)
    {
        cin>>n;
        for(int i = 1; i <= n; i++)
        {
            cin>>a[i];
            f[i][1] = f[i - 1][0] + a[i];
            f[i][0] = max(f[i - 1][0], f[i - 1][1]);
        }
        cout<<max(f[n][0], f[n][1])<<endl;
    }
}

/*
解法3：
time : 
space : 
*/
