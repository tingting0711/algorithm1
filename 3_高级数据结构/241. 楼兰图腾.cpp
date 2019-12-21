/*

题目描述：

在完成了分配任务之后，西部314来到了楼兰古城的西部。

相传很久以前这片土地上(比楼兰古城还早)生活着两个部落，一个部落崇拜尖刀(‘V’)，一个部落崇拜铁锹(‘∧’)，他们分别用V和∧的形状来代表各自部落的图腾。

西部314在楼兰古城的下面发现了一幅巨大的壁画，壁画上被标记出了N个点，经测量发现这N个点的水平位置和竖直位置是两两不同的。

西部314认为这幅壁画所包含的信息与这N个点的相对位置有关，因此不妨设坐标分别为(1,y1),(2,y2),…,(n,yn),其中y1~yn是1到n的一个排列。

西部314打算研究这幅壁画中包含着多少个图腾。

如果三个点(i,yi),(j,yj),(k,yk)满足1≤i<j<k≤n且yi>yj,yj<yk，则称这三个点构成V图腾;

如果三个点(i,yi),(j,yj),(k,yk)满足1≤i<j<k≤n且yi<yj,yj>yk，则称这三个点构成∧图腾;

西部314想知道，这n个点中两个部落图腾的数目。

因此，你需要编写一个程序来求出V的个数和∧的个数。

输入格式
第一行一个数n。

第二行是n个数，分别代表y1，y2,…,yn。

输出格式
两个数，中间用空格隔开，依次为V的个数和∧的个数。

数据范围
对于所有数据，n≤200000,且输出答案不会超过int64。

输入样例：
5
1 5 3 2 4
输出样例：
3 4

*/


/*
解法1：树状数组
time : O(NlogN)
space : O(N)
*/

#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
const int N = 200010;
int n, a[N], tr[N], bigger[N], smaller[N];
long long res1, res2;
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
    for(int i = 1; i <= n; i++)cin>>a[i];

    for(int i = 1; i <= n; i++)
    {
        int y = a[i];
        bigger[i] = sum(n) - sum(y - 1);
        smaller[i] = sum(y - 1);
        add(y, 1);
    }
    memset(tr, 0, sizeof tr);
    res1 = 0, res2 = 0;
    for(int i = n; i; i--)
    {
        int y = a[i];
        res1 += bigger[i] * (long long)(sum(n) - sum(y - 1));
        res2 += smaller[i] * (long long)(sum(y - 1));
        add(y, 1);
    }
    cout<<res1<<" "<<res2<<endl;
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
