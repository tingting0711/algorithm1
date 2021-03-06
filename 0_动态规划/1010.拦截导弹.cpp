/*

题目描述：

某国为了防御敌国的导弹袭击，发展出一种导弹拦截系统。

但是这种导弹拦截系统有一个缺陷：虽然它的第一发炮弹能够到达任意的高度，但是以后每一发炮弹都不能高于前一发的高度。

某天，雷达捕捉到敌国的导弹来袭。

由于该系统还在试用阶段，所以只有一套系统，因此有可能不能拦截所有的导弹。

输入导弹依次飞来的高度（雷达给出的高度数据是不大于30000的正整数，导弹数不超过1000），计算这套系统最多能拦截多少导弹，如果要拦截所有导弹最少要配备多少套这种导弹拦截系统。

输入格式
共一行，输入导弹依次飞来的高度。

输出格式
第一行包含一个整数，表示最多能拦截的导弹数。

第二行包含一个整数，表示要拦截所有导弹最少要配备的系统数。

输入样例：
389 207 155 300 299 170 158 65
输出样例：
6
2


*/


/*
解法1：预习版
time : O(N^2)
space : O(N)
*/

#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

const int N = 1010;
vector<int>a;
int f[N], n;

int main()
{
    int h;
    while(cin>>h)
    {
        n++;
        a.push_back(h);
    }
    n = a.size();
    
    int res1 = 0;
    for(int i = n - 1; i >= 0; i--)
    {
        f[i] = 1;
        for(int j = n - 1; j > i; j--)
        {
            if(a[i] >= a[j] && i != j)f[i] = max(f[i], f[j] + 1);
        }
        res1 = max(res1, f[i]);
    }
    cout<<res1<<endl;
    
    int res2 = 0;
    vector<int>::iterator k;
    for(vector<int>::iterator i = a.begin(); i != a.end(); )
    {
        res2 ++;
        for(vector<int>::iterator j = i + 1; j != a.end(); )
            {
                k = j;
                if(k < a.end() && *k <= *i)*i = *k, a.erase(k);
                else j++;
            }
        k = i;
        a.erase(k);
    }
    
    cout<<res2<<endl;
    return 0;
}


/*
解法2：反链定理（https://www.zybuluo.com/LinKArftc/note/79936）
一个数列的最大上升子序列长度k 等于 其可被拆分为k个非上升序列的最小值
time : O(N^2) =》 可优化为 O(NlogN)，具体参考上升子序列2
space : O(N)
*/
#include<iostream>
#include<algorithm>
using namespace std;

const int N = 1010;
int n, f[N], a[N], g[N];

int main()
{
    int k = 0;
    while(cin>>n && n)a[k++] = n;
    n = k;
    int res = 0;
    
    for(int i = 0; i < n; i ++)
    {
        f[i] = 1;
        for(int j = 0; j < i; j ++)
        {
            if(a[i] <= a[j])f[i] = max(f[i], f[j] + 1);
        }
        res = max(res, f[i]);
    }
    cout<<res<<endl;
    
    int cnt = 0;
    for(int i = 0; i < n; i++)
    {
        g[i] = 1;
        for(int j = 0; j < i; j++)
        {
            if(a[i] > a[j])g[i] = max(g[i], g[j] + 1);
        }
        cnt = max(cnt, g[i]);
    }
    cout<<cnt<<endl;
    return 0;
}


/*
解法3：利用单调的性质
time : O(N^2)
space : O(N)
*/

#include<iostream>
#include<algorithm>
using namespace std;

const int N = 1010;
int n, f[N], a[N], g[N];

int main()
{
    int k = 0;
    while(cin>>n && n)a[k++] = n;
    n = k;
    int res = 0;
    
    for(int i = 0; i < n; i ++)
    {
        f[i] = 1;
        for(int j = 0; j < i; j ++)
        {
            if(a[i] <= a[j])f[i] = max(f[i], f[j] + 1);
        }
        res = max(res, f[i]);
    }
    cout<<res<<endl;
    
    int cnt = 0;
    for(int i = 0; i < n; i++)
    {
        int j = 0;
        while(j < cnt && g[j] < a[i])j++;
        g[j] = a[i];
        if(j >= cnt)cnt ++;
    }
    cout<<cnt<<endl;
    return 0;
}
