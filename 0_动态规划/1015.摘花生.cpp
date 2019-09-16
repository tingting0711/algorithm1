/*

题目描述：

Hello Kitty想摘点花生送给她喜欢的米老鼠。

她来到一片有网格状道路的矩形花生地(如下图)，从西北角进去，东南角出来。

地里每个道路的交叉点上都有种着一株花生苗，上面有若干颗花生，经过一株花生苗就能摘走该它上面所有的花生。

Hello Kitty只能向东或向南走，不能向西或向北走。

问Hello Kitty最多能够摘到多少颗花生。

1.gif

输入格式
第一行是一个整数T，代表一共有多少组数据。

接下来是T组数据。

每组数据的第一行是两个整数，分别代表花生苗的行数R和列数 C。

每组数据的接下来R行数据，从北向南依次描述每行花生苗的情况。每行数据有C个整数，按从西向东的顺序描述了该行每株花生苗上的花生数目M。

输出格式
对每组输入数据，输出一行，内容为Hello Kitty能摘到得最多的花生颗数。

数据范围
1≤T≤100,
1≤R,C≤100,
0≤M≤1000
输入样例：
2
2 2
1 1
3 4
2 3
2 3 4
1 6 5
输出样例：
8
16

*/


/*
解法1：
time : O(N^2)
space :O(N^2)
*/

#include<iostream>
#include<algorithm>
#include<string.h>
using namespace std;

const int N = 110;
int a[N][N], f[N][N];
int t, r, c;

int main()
{
    cin>>t;
    while(t --)
    {
        memset(a, 0, sizeof a), memset(f, 0, sizeof f);
        cin>>r>>c;
        for(int i = 1; i <= r; i++)
        {
            for(int j = 1; j <= c; j ++)cin>>a[i][j];
        }
        
        for(int i = 1; i <= r; i++)
        {
            for(int j = 1; j <= c; j ++)
            {
                if(i == 1 && j == 1)
                {
                    f[i][j] = a[i][j];
                }
                else if(i == 1)
                {
                    f[i][j] = a[i][j] + f[i][j - 1];
                }
                else if(j == 1)
                {
                    f[i][j] = a[i][j] + f[i - 1][j];
                }
                else
                {
                    // i != 1 && j != 1
                    f[i][j] = a[i][j] + max(f[i - 1][j], f[i][j - 1]);
                }
            }
        }
        
        cout<<f[r][c]<<endl;
    }
    return 0;
}


/*
解法2：
time : O(N^2)
space :O(N)
*/

#include<iostream>
#include<algorithm>
#include<string.h>
using namespace std;

const int N = 110;
int a, f[2][N];
int t, r, c;

int main()
{
    cin>>t;
    while(t --)
    {
        memset(f, 0, sizeof f);
        cin>>r>>c;
        for(int i = 1; i <= r; i++)
        {
            for(int j = 1; j <= c; j ++)
            {
                cin>>a;
                if(i == 1 && j == 1)
                {
                    f[i & 1][j] = a;
                }
                else if(i == 1)
                {
                    f[i & 1][j] = a + f[i & 1][j - 1];
                }
                else if(j == 1)
                {
                    f[i & 1][j] = a + f[i - 1 & 1][j];
                }
                else
                {
                    // i != 1 && j != 1
                    f[i & 1][j] = a + max(f[i - 1 & 1][j], f[i & 1][j - 1]);
                }
            }
        }
        
        cout<<f[r & 1][c]<<endl;
    }
    return 0;
}

/*
解法3：
time : O(N^2)
space :O(N^2)
*/

#include<iostream>
#include<algorithm>
using namespace std;
const int N = 110;

int n, m;
int w[N][N], f[N][N];

int main()
{
		int T;
		cin>>T;
		while(T--)
		{
				cin>>n>>m;
				for(int i = 1; i <= n; i++)
						for(int j = 1; j <= m; j++)
						{
								cin>>w[i][j];
								f[i][j] = max(f[i - 1][j], f[i][j - 1]) + w[i][j];
						}
					
				cout<<f[n][m]<<endl;
		}
		return 0;
}

