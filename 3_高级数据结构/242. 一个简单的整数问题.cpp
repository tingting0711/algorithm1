/*

题目描述：

给定长度为N的数列A，然后输入M行操作指令。

第一类指令形如“C l r d”，表示把数列中第l~r个数都加d。

第二类指令形如“Q X”，表示询问数列中第x个数的值。

对于每个询问，输出一个整数表示答案。

输入格式
第一行包含两个整数N和M。

第二行包含N个整数A[i]。

接下来M行表示M条指令，每条指令的格式如题目描述所示。

输出格式
对于每个询问，输出一个整数表示答案。

每个答案占一行。

数据范围
1≤N,M≤105,
|d|≤10000,
|A[i]|≤1000000000
输入样例：
10 5
1 2 3 4 5 6 7 8 9 10
Q 4
Q 1
Q 2
C 1 6 3
Q 2
输出样例：
4
1
2
5

*/


/*
解法1：差分 + 树状数组
time : O(NkogN)
space : O(N)
*/

#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
const int N = 100010;
int n, m, tr[N], a[N];
int lowbit(int x)
{
    return x & -x;
}
int sum(int x)
{
    int res = 0;
    for(int i = x; i; i -= lowbit(i))
        res += tr[i];
    return res;
}
void add(int x, int c)
{
    for(int i = x; i <= n; i += lowbit(i))
        tr[i] += c;
}
int main()
{
    cin>>n>>m;
    for(int i = 1; i <= n; i++)
    {
        cin>>a[i];
        add(i, a[i] - a[i - 1]);
    }
    while(m --)
    {
        char op;
        int l, r, c;
        cin>>op>>l;
        if(op == 'Q')
        {
            cout<<sum(l)<<endl;
        }
        else
        {
            cin>>r>>c;
            add(l, c);
            add(r + 1, -c);
        }
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
