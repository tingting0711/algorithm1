/*

题目描述：

为了对抗附近恶意国家的威胁，R国更新了他们的导弹防御系统。

一套防御系统的导弹拦截高度要么一直上升要么一直下降。

例如，一套系统先后拦截了高度为3和高度为4的两发导弹，那么接下来该系统就只能拦截高度大于4的导弹。

给定即将袭来的一系列导弹的高度，请你求出至少需要多少套防御系统，就可以将它们全部击落。

输入格式
输入包含多组测试用例。

对于每个测试用例，第一行包含整数n，表示来袭导弹数量。

第二行包含n个不同的整数，表示每个导弹的高度。

当输入测试用例n=0时，表示输入终止，且该用例无需处理。

输出格式
对于每个测试用例，输出一个占据一行的整数，表示所需的防御系统数量。

数据范围
1≤n≤50
输入样例：
5
3 5 2 4 1
0 
输出样例：
2
样例解释
对于给出样例，最少需要两套防御系统。

一套击落高度为3,4的导弹，另一套击落高度为5,2,1的导弹。

*/


/*
解法1：
time : O(2^N)
space : O(N)
*/

#include<iostream>
#include<algorithm>
#include<string.h>
using namespace std;

const int N = 55;
int n, up[N], down[N], a[N], res;

void dfs(int u, int su, int sd)
{
    // cout<<u<<" "<<n<<" "<<su<<" "<<sd<<" "<<res<<endl;
    if(su + sd >= res)return;
    if(u == n){res = su + sd; return;}
    int k = 0;
    while(k < su && a[u] < up[k])k++;
    int temp = up[k];
    up[k] = a[u];
    if(k < su)dfs(u + 1, su, sd);
    else dfs(u + 1, su + 1, sd);
    up[k] = temp;
    
    k = 0;
    while(k < sd && a[u] > down[k])k++;
    temp = down[k];
    down[k] = a[u];
    if(k < sd)dfs(u + 1, su, sd);
    else dfs(u + 1, su, sd + 1);
    down[k] = temp;
}

int main()
{
    while(cin>>n, n)
    {
        res = n;
        for(int i = 0; i < n; i++)cin>>a[i];
        memset(up, 0, sizeof up);
        memset(down, 0, sizeof down);
        dfs(0, 0, 0);
        cout<<res<<endl;
    }
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
