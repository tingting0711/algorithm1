/*

题目描述：

N位同学站成一排，音乐老师要请其中的(N-K)位同学出列，使得剩下的K位同学排成合唱队形。     

合唱队形是指这样的一种队形：设K位同学从左到右依次编号为1，2…，K，他们的身高分别为T1，T2，…，TK，  则他们的身高满足T1<…<Ti>Ti+1>…>TK(1≤i≤K)。     

你的任务是，已知所有N位同学的身高，计算最少需要几位同学出列，可以使得剩下的同学排成合唱队形。

输入格式
输入的第一行是一个整数N，表示同学的总数。

第二行有n个整数，用空格分隔，第i个整数Ti是第i位同学的身高(厘米)。

输出格式
输出包括一行，这一行只包含一个整数，就是最少需要几位同学出列。

数据范围
2≤N≤100,
130≤Ti≤230
输入样例：
8
186 186 150 200 160 130 197 220
输出样例：
4

*/

/*
解法1：
time : O(N^2)
space : O(N)
*/

#include<iostream>
#include<algorithm>
using namespace std;
const int N = 1010;
int n, a[N], f[N], g[N];

int main()
{
    cin>>n;
    for(int i = 1; i <= n; i++)scanf("%d", &a[i]);
    
    for(int i = 1; i <= n; i++)
    {
        f[i] = 1;
        for(int j = 1; j < i; j++)
        {
            if(a[i] > a[j])f[i] = max(f[i], f[j] + 1);
        }
    }
    
    for(int i = n; i >= 1; i--)
    {
        g[i] = 1;
        for(int j = n; j > i; j--)
        {
            if(a[i] > a[j])g[i] = max(g[i], g[j] + 1);
        }
    }
    int res = 0;
    for(int i = 1; i <= n; i++)res = max(res, f[i] + g[i] - 1);
    cout<<n - res<<endl;
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
