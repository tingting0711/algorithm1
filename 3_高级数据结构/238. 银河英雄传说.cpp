/*

题目描述：

有一个划分为N列的星际战场，各列依次编号为1,2,…,N。

有N艘战舰，也依次编号为1,2,…,N,其中第i号战舰处于第i列。

有T条指令，每条指令格式为以下两种之一：

1、M i j，表示让第i号战舰所在列的全部战舰保持原有顺序，接在第j号战舰所在列的尾部。

2、C i j，表示询问第i号战舰与第j号战舰当前是否处于同一列中，如果在同一列中，它们之间间隔了多少艘战舰。

现在需要你编写一个程序，处理一系列的指令。

输入格式
第一行包含整数T，表示共有T条指令。

接下来T行，每行一个指令，指令有两种形式：M i j或C i j。

其中M和C为大写字母表示指令类型，i和j为整数，表示指令涉及的战舰编号。

输出格式
你的程序应当依次对输入的每一条指令进行分析和处理：

如果是M i j形式，则表示舰队排列发生了变化，你的程序要注意到这一点，但是不要输出任何信息；

如果是C i j形式，你的程序要输出一行，仅包含一个整数，表示在同一列上，第i号战舰与第j号战舰之间布置的战舰数目，如果第i号战舰与第j号战舰当前不在同一列上，则输出-1。

数据范围
N≤30000,T≤500000
输入样例：
4
M 2 3
C 1 2
M 2 4
C 4 2
输出样例：
-1
1

*/


/*
解法1：并查集
time : O(N*logN)
space : O(N)
*/

#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
const int N = 30010;
int n, m, p[N], size[N], depth[N];
int find(int x)
{
    if(x != p[x])
    {
        int root = find(p[x]);
        depth[x] += depth[p[x]] ;
        p[x] = root;
    }
    return p[x];
}
int main()
{
    cin>>m;
    for(int i = 0; i < N; i++)
    {
        p[i] = i;
        size[i] = 1;
        depth[i] = 0;
    }
    
    while(m --)
    {
        char op;
        int a, b;
        cin>>op>>a>>b;
        if(op == 'M')
        {
            int pa = find(a), pb = find(b);
            if(pa != pb)
            {
                depth[pa] = size[pb];
                size[pb] += size[pa];
                p[pa] = pb;
            }
        }
        else
        {
            int pa = find(a), pb = find(b);
            if(pa != pb)cout<<-1<<endl;
            else cout<<max(0, abs(depth[a] - depth[b]) - 1)<<endl;
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
