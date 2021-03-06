/*

题目描述：

一个商人穿过一个N×N的正方形的网格，去参加一个非常重要的商务活动。

他要从网格的左上角进，右下角出。

每穿越中间1个小方格，都要花费1个单位时间。

商人必须在(2N-1)个单位时间穿越出去。

而在经过中间的每个小方格时，都需要缴纳一定的费用。

这个商人期望在规定时间内用最少费用穿越出去。

请问至少需要多少费用？

注意：不能对角穿越各个小方格（即，只能向上下左右四个方向移动且不能离开网格）。

输入格式
第一行是一个整数，表示正方形的宽度N。

后面N行，每行N个不大于100的整数，为网格上每个小方格的费用。

输出格式
输出一个整数，表示至少需要的费用。

数据范围
1≤N≤100
输入样例：
5
1  4  6  8  10 
2  5  7  15 17 
6  8  9  18 20 
10 11 12 19 21 
20 23 25 29 33
输出样例：
109
样例解释
样例中，最小值为109=1+2+5+7+9+12+19+21+33。

*/


/*
解法1：
time : O(N^2)
space : O(N^2)
*/

#include<iostream>
#include<algorithm>
#include<string.h>
using namespace std;

const int N = 110;

int w[N][N], f[N][N];

int main()
{
    int n;
    cin>>n;
    memset(f, 0x3f, sizeof f); //int只能设置为 0， -1， 0x3f;

    for(int i = 1; i <= n; i ++)
    {
        for(int j = 1; j <= n; j++)
        {
            scanf("%d", &w[i][j]);
        }
    }
    
    for(int i = 1; i <= n; i ++)
    {
        for(int j = 1; j <= n; j++)
        {
            if(i == 1 && j == 1)f[i][j] = w[i][j];
            else
            {
                f[i][j] = w[i][j] + min(f[i - 1][j], f[i][j - 1]);
            }
        }
    }
    cout<<f[n][n]<<endl;
    
    return 0;
}

/*
解法2：
time : O(N^2)
space : O(N)
*/



/*
解法3：
time : 
space : 
*/
