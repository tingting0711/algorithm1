/*

题目描述：

有 N 种物品和一个容量是 V 的背包。

第 i 种物品最多有 si 件，每件体积是 vi，价值是 wi。

求解将哪些物品装入背包，可使物品体积总和不超过背包容量，且价值总和最大。
输出最大价值。

输入格式
第一行两个整数，N，V (0<N≤1000, 0<V≤20000)，用空格隔开，分别表示物品种数和背包容积。

接下来有 N 行，每行三个整数 vi,wi,si，用空格隔开，分别表示第 i 种物品的体积、价值和数量。

输出格式
输出一个整数，表示最大价值。

数据范围
0<N≤1000
0<V≤20000
0<vi,wi,si≤20000
提示
本题考查多重背包的单调队列优化方法。

输入样例
4 5
1 2 3
2 4 1
3 4 3
4 5 2
输出样例：
10

*/


/*
解法1：
time : O(T*N)
space : 0(M)
*/

#include<iostream>
#include<algorithm>
#include<string.h>
using namespace std;
const int N = 110, M = 25010;
int n, t, a[N], f[M];
int main()
{
    cin>>t;
    while(t--)
    {
        cin>>n;
        for(int i = 0; i < n ; i++)cin>>a[i];
        sort(a, a + n);
        int res = 0;
        memset(f, 0, sizeof f);
        f[0] = 1;
        for(int i = 0; i < n; i++)
        {
            if(!f[a[i]])res ++;
            for(int j = a[i]; j <=a[n - 1]; j++)  //用a[i]去更新其他值，查看是否能配出来
            {
                f[j] += f[j - a[i]];
            }
        }
        cout<<res<<endl;
    }
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
