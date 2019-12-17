/*

题目描述：

在实现程序自动分析的过程中,常常需要判定一些约束条件是否能被同时满足。

考虑一个约束满足问题的简化版本：假设x1,x2,x3,…代表程序中出现的变量，给定n个形如xi=xj或xi≠xj的变量相等/不等的约束条件，请判定是否可以分别为每一个变量赋予恰当的值，使得上述所有约束条件同时被满足。

例如，一个问题中的约束条件为：x1=x2，x2=x3，x3=x4，x1≠x4，这些约束条件显然是不可能同时被满足的，因此这个问题应判定为不可被满足。

现在给出一些约束满足问题，请分别对它们进行判定。

输入格式
输入文件的第1行包含1个正整数t，表示需要判定的问题个数，注意这些问题之间是相互独立的。

对于每个问题，包含若干行：

第1行包含1个正整数n，表示该问题中需要被满足的约束条件个数。

接下来n行，每行包括3个整数i,j,e，描述1个相等/不等的约束条件，相邻整数之间用单个空格隔开。若e=1，则该约束条件为xi=xj；若e=0，则该约束条件为xi≠xj。

输出格式
输出文件包括t行。

输出文件的第k行输出一个字符串“YES”或者“NO”（不包含引号，字母全部大写），“YES”表示输入中的第k个问题判定为可以被满足，“NO”表示不可被满足。

数据范围
1≤n≤1000000
1≤i,j≤1000000000
输入样例：
2
2
1 2 1
1 2 0
2
1 2 1
2 1 1
输出样例：
NO
YES

*/


/*
解法1：离散化并查集
time : O(N*logN)
space : O(N)
*/

#include<cstring>
#include<iostream>
#include<algorithm>
#include<unordered_map>
using namespace std;

const int N = 2000010;
int n, m, t, p[N];
unordered_map<int, int> S;

struct Query
{
    int a, b, e;
}query[N];
int get(int x)
{
    if(S.count(x) == 0)S[x] = ++ n;
    return S[x];
}
int find(int x)
{
    if(p[x] != x)p[x] = find(p[x]);
    return p[x];
}
int main()
{
    cin>>t;
    while(t --)
    {
        bool is_conflict = false;
        n = 0;
        S.clear();
        // for(int i = 0; i < N; i++)p[i] = i;
        cin>>m;
        for(int i = 0; i < m; i++)
        {
            int a, b, e;
            cin>>a>>b>>e;
            query[i] = {get(a), get(b), e};
        }
        
        for(int i = 1; i <= n; i++)p[i] = i;
        
        for(int i = 0; i < m; i++)
        {
            if(query[i].e == 1)
            {
                int a = query[i].a, b = query[i].b;
                int pa = find(a), pb = find(b);
                if(pa != pb)
                {
                    p[pa] = pb;
                }
            }
        }
        
        for(int i = 0; i < m; i++)
        {
            if(query[i].e == 0)
            {
                int a = query[i].a, b = query[i].b;
                int pa = find(a), pb = find(b);
                if(pa == pb)
                {
                    is_conflict = true;
                    break;
                }
            }
        }
        if(is_conflict)cout<<"NO"<<endl;
        else cout<<"YES"<<endl;
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
