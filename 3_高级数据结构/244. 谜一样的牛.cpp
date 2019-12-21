/*

题目描述：

有n头奶牛，已知它们的身高为 1~n 且各不相同，但不知道每头奶牛的具体身高。

现在这n头奶牛站成一列，已知第i头牛前面有Ai头牛比它低，求每头奶牛的身高。

输入格式
第1行：输入整数n。

第2..n行：每行输入一个整数Ai,第i行表示第i头牛前面有Ai头牛比它低。
（注意：因为第1头牛前面没有牛，所以并没有将它列出）

输出格式
输出包含n行，每行输出一个整数表示牛的身高。

第i行输出第i头牛的身高。

数据范围
1≤n≤105
输入样例：
5
1
2
1
0
输出样例：
2
4
5
3
1

*/


/*
解法1：vector 动态维护身高
time : O(N^2)
space : O(N)
*/

#include<vector>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
const int N = 100010;
int n, a[N], ans[N];
vector<int>high;
int main()
{
    cin>>n;
    a[1] = 0;
    high.push_back(1);
    for(int i = 2; i <= n; i++)
    {
        cin>>a[i];
        high.push_back(i);
    }
    for(int i = n; i; i--)
    {
        ans[i] = high[a[i]];
        high.erase(high.begin() + a[i]);
    }

    for(int i = 1; i <= n; i++)cout<<ans[i]<<endl;

    return 0;
}


/*
解法2：二分 + 树状数组
time : O(NlogN)
space : O(N)
*/

#include<vector>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
const int N = 100010;
int n, a[N], ans[N], tr[N];
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
    cin>>n;
    a[1] = 0;
    add(1, 1);
    for(int i = 2; i <= n; i++)
    {
        cin>>a[i];
        add(i, 1);
    }
    for(int i = n; i; i--)
    {
        int l = 1, r = n;
        while(l < r)
        {
            int mid = l + r >> 1;
            if(sum(mid) >= a[i] + 1)r = mid;
            else l = mid + 1;
        }
        ans[i] = l;
        add(l, -1);
    }

    for(int i = 1; i <= n; i++)cout<<ans[i]<<endl;

    return 0;
}
/*
解法3：
time : 
space : 
*/
