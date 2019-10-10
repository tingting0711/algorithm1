/*

题目描述：

总公司拥有高效设备M台，准备分给下属的N个分公司。

各分公司若获得这些设备，可以为国家提供一定的盈利。

问：如何分配这M台设备才能使国家得到的盈利最大？

求出最大盈利值。

分配原则：每个公司有权获得任意数目的设备，但总台数不超过设备数M。

输入格式
第一行有两个数，第一个数是分公司数N，第二个数是设备台数M；

接下来是一个N*M的矩阵，矩阵中的第 i 行第 j 列的整数表示第 i 个公司分配 j 台机器的盈利。

输出格式
第一行输出最大盈利值；

接下N行，每行有2个数，即分公司编号和该分公司获得设备台数。

答案不唯一，输入任意合法方案即可。

数据范围
1≤N≤10,
1≤M≤15
输入样例：
3 3
30 40 50
20 30 50
20 25 30
输出样例：
70
1 1
2 1
3 1

*/


/*
解法1：
time : O(N * M * M)
space : O(N * M)
*/

#include<iostream>
#include<algorithm>
using namespace std;

const int N = 11, M = 16;
int n, m, w[N][M], f[N][M], g[N];

int main()
{
    cin>>n>>m;
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= m; j++)
        {
            cin>>w[i][j];
        }
    }
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= m; j++)
        {
            for(int k = 0; k <= j; k++)
            {
                f[i][j] = max(f[i][j], f[i - 1][j - k] + w[i][k]);
            }
        }
    }
    cout<<f[n][m]<<endl;
    int j = m;
    for(int i = n; i >= 1; i--)
    {
        for(int k = 0; k <= j; k ++)
        {
            if(f[i][j] == f[i - 1][j - k] + w[i][k])
            {
                j -= k;
                g[i] = k;
                break;
            }
        }
    }
    for(int i = 1; i <= n; i++)cout<<i<<" "<<g[i]<<endl;
    return 0;
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
