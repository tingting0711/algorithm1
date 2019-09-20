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

![1017](./img/1017.png)

```
#include<iostream>
#include<algorithm>
using namespace std;

const int N = 110;
int n;
int a[N], f[N], g[N];
int main()
{
		int T;
		cin>>T;
		while(T--)
		{
				cin>>n;
				for(int i = 1; i <= n; i ++)cin>>a[i];
				
				//正向求解
				int res = 0;
				for(int i = 1; i <= n; i++)
				{
						f[i] = 1;
						for(int j = 1; j < i; j++)
						{
								if(a[i] > a[j])f[i] = max(f[i], f[j] + 1);
						}
						res = max(res, f[i]);
				}
				//反向求解
				for(int i = n; i >= 1; i--)
				{
						f[i] = 1;
						for(int j = n; j > i; j--)
						{
								if(a[i] > a[j])f[i] = max(f[i], f[j] + 1);
						}
						res = max(res, f[i]);
				}
				cout<<res<<endl;
		}
}
```



> 登山

![1014](./img/1014.png)

```
#include<algorithm>
#include<iostream>
using namespace std;

const int N = 1010;
int n;
int a[N], f[N], g[N];

int main()
{
    cin>>n;
    for(int i = 1; i <= n; i ++)cin>>a[i];
    for(int i = 1; i <= n; i++)
    {
        f[i] = 1;
        for(int j = 1; j < i; j++ )
        {
            if(a[i] > a[j])
                f[i] = max(f[i], f[j] + 1);
        }
    }
    for(int i = n; i >= 1; i--)
    {
        g[i] = 1;
        for(int j = n; j > i; j-- )
        {
            if(a[i] > a[j])
                g[i] = max(g[i], g[j] + 1);
        }
    }
    int res = 0;
    for(int i = 1; i <= n; i++)res = max(res, f[i] + g[i] - 1);
    cout<<res<<endl;
    return 0;
}
```



> 合唱队形

```
#include<algorithm>
#include<iostream>
using namespace std;

const int N = 110;
int n;
int a[N], f[N], g[N];

int main()
{
    cin>>n;
    for(int i = 1; i <= n; i ++)cin>>a[i];
    for(int i = 1; i <= n; i++)
    {
        f[i] = 1;
        for(int j = 1; j < i; j++ )
        {
            if(a[i] > a[j])
                f[i] = max(f[i], f[j] + 1);
        }
    }
    for(int i = n; i >= 1; i--)
    {
        g[i] = 1;
        for(int j = n; j > i; j-- )
        {
            if(a[i] > a[j])
                g[i] = max(g[i], g[j] + 1);
        }
    }
    int res = 0;
    for(int i = 1; i <= n; i++)res = max(res, f[i] + g[i] - 1);
    cout<<n - res<<endl;
    return 0;
}
```



> 友好城市

```
#include<iostream>
#include<algorithm>
using namespace std;

typedef pair<int, int>PII;

const int N = 5010;

int n;
PII a[N];
int f[N];
int main()
{
    cin>>n;
    for(int i = 0; i < n; i++)cin>>a[i].first>>a[i].second;
    sort(a, a + n);
    int res = 0;
    for(int i = 0; i < n; i++)
    {
        f[i] = 1;
        for(int j = 0; j < i; j++)
        {
            if(a[i].second > a[j].second)f[i] = max(f[i], f[j] + 1);
        }
        res = max(res, f[i]);
    }
    cout<<res<<endl;
    
    return 0;
}

```



> 最大上升子序列和

![1016](./img/1016.png)

```
#include<iostream>
#include<algorithm>
using namespace std;

const int N = 1010;
int n, a[N], f[N];

int main()
{
    cin>>n;
    for(int i = 1; i <= n; i++)cin>>a[i];
    
    int res = 0;
    for(int i = 1; i <= n; i++)
    {
        f[i] = a[i];
        for(int j = 1; j < i; j++)
        {
            if(a[i] > a[j])
            {
                f[i] = max(f[i], f[j] + a[i]);
            }
        }
        res = max(res, f[i]);
    }
    cout<<res<<endl;
    return 0;
}
```



> 拦截导弹

![1010](./img/1010.png)

```
#include<iostream>
#include<algorithm>
using namespace std;

const int N = 1010;

int n, q[N], f[N], g[N];

int main()
{
    while(cin>>q[n])n++;
    
    int res = 0;
    for(int i = 0; i < n; i++)
    {
        f[i] = 1;
        for(int j = 0; j < i; j++)
        {
            if(q[i] <= q[j])f[i] = max(f[i], f[j] + 1);
            res = max(res, f[i]);
        }
    }
    cout<<res<<endl;
    
    int cnt = 0;
    for(int i = 0; i < n; i++)
    {
        int k = 0;
        while(k < cnt && g[k] < q[i])k++;
        g[k] = q[i];
        if( k>= cnt)cnt ++;
    }
    cout<<cnt<<endl;
    return 0;
}
```

思考：反链定理/Dilworth定理



> 导弹防御系统

![187](./img/187.png)

```
/*
暴力搜索
记录全局最小值
*/

```



> 最长公共上升子序列

![272](./img/272.png)

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

