# 动态规划
## 数字三角形模型

- 摘花生
  
- 最低通行费用

- 方格取数

  

> 摘花生

```
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
```



> 最低通行费用

```
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
```



> 方格取数

```
#include<iostream>
#include<algorithm>
using namespace std;

const int N = 11;
int w[N][N], f[2*N][N][N];

int main()
{
    int n;
    cin>>n;
    int x, y, z;
    while(cin>>x>>y>>z, x || y || z)
    {
        w[x][y] = z;
    }
    for(int t = 2; t <= 2 * n; t ++)
    {
        for(int i1 = 1; i1 <= n; i1 ++ )
        {
            for(int i2 = 1; i2 <= n; i2++)
            {
                int j1 = t - i1, j2 = t - i2;
                if(j1 >= 1 && j1 <= n && j2 >= 1 && j2 <= n)
                {
                    f[t][i1][i2] = max(f[t - 1][i1 - 1][i2 - 1], f[t - 1][i1][i2]);
                    f[t][i1][i2] = max(f[t][i1][i2], f[t - 1][i1][i2 - 1]);
                    f[t][i1][i2] = max(f[t][i1][i2], f[t - 1][i1 - 1][i2]);
                    f[t][i1][i2] += w[i1][j1];
                    if(i1 != i2)f[t][i1][i2] += w[i2][j2];
                }
            }
        }
    }
    cout<<f[2*n][n][n]<<endl;
    return 0;
}
```



## 最长上升子序列模型

- 怪盗基德的滑翔翼

- 登山

- 合唱队形

- 友好城市

- 最大上升子序列和

- 拦截导弹

- 导弹防御系统

- 最长公共上身子序列

  

> 怪盗基德的滑翔翼

```

```



> 登山

```

```



> 合唱队形

```

```



> 友好城市

```

```



> 最大上升子序列和

```

```



> 拦截导弹

```

```



> 导弹防御系统

```

```



> 最长公共上身子序列

```

```



## 次标题

- 小标题

- 小标题

- 小标题

  

> 小标题

```

```



> 小标题

```

```



> 小标题

```

```



## 次标题

- 小标题

- 小标题

- 小标题

  

> 小标题

```

```



> 小标题

```

```



> 小标题

```

```



## 次标题

- 小标题

- 小标题

- 小标题

  

> 小标题

```

```



> 小标题

```

```



> 小标题

```

```

