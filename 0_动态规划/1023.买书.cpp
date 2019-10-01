/*

题目描述：

小明手里有n元钱全部用来买书，书的价格为10元，20元，50元，100元。

问小明有多少种买书方案？（每种书可购买多本）

输入格式
一个整数 n，代表总共钱数。

输出格式
一个整数，代表选择方案种数。

数据范围
0≤n≤1000
输入样例1：
20
输出样例1：
2

*/


/*
解法1：
time : O(N)
space : O(N)
*/

#include<iostream>
#include<algorithm>
using namespace std;
const int N = 1010;

int n, f[N], a[4] = {10, 20, 50, 100};

int main()
{
    cin>>n;
    if (!n)
    {
        cout<<0<<endl;
        return 0;
    }
    f[0] = 1;
    for(int i = 0; i < 4; i++)
    {
        for(int j = a[i]; j <= n; j++)
        {
            f[j] = f[j] + f[j - a[i]];
        }
    }
    cout<<f[n]<<endl;
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
