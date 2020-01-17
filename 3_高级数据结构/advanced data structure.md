# 高级数据结构
## 并查集

- 合并两个集合
  
- 查询某个元素的祖宗节点

- 路径压缩   O(log N)

- 按轶合并  O(log N)

- 记录每个集合大小                    -> 绑定到根节点

- 记录每个点到根节点的距离     ->绑定到每个元素

  

> 离散化

- 保序
  - 排序，判重，二分
- 不包序
  - map
  - hash

```

```



> 小标题

```

```



> 小标题

```

```



## 树状数组/二叉搜索树binary index tree

- 基本原理
- 扩展
  - 树状数组 + 差分
  - 树状数组 + 差分 + 公式
- 例题
- 用处
- 快速求前缀和  O(logN)
  - for(int i = x; i; i -= lowbit(i))res += tr[i];
- 修改某个数      O(logN)
  - for(int i = x; i <= n; i += lowbit(i))tr[i] += c;

![树状数组2](./img/树状数组2.png)

> 初始化

```
/* O(NlogN) */
for(int i = 1; i <= n; i++)add(i, a[i]);

/* O(N) */
for(int i = 1; i <= n; i++)s[i] = s[i - 1] + a[i];
for(int i = 1; i <= n; i++)tr[i] = s[i] - s[i - lowbit(i)]
```



> 树状数组 + 差分 

a[L ~ R] += c

求a[x] = b[1] + b[2] + ... + b[x]

```

```



> 小标题

```

```



## 线段树segment tree

- 操作
  - pushup
  - build
  - modify
    - 单点
    - 区间（懒标记）
  - query
  - pushdown
  
- 原理
  
  - 满二叉树（一维数组/堆）4n
  - 编号
    - 父节点  x >> 1
    - 左二子  x << 1
    - 右儿子  x << 1 | 1
  
  

> build

```
void build(int u, int L, int R)
{
		记录左右端点L,R
		if(L == R)return;
		int mid = L + R >> 1;
		build(u<<1, L, mid), build(u<<1 | 1, mid + 1, R);
		pushup(u);
}
```

> query

```

```



> 小标题

```

```



## 平衡树 - treap(tree + heap)

- BST(binary search tree)

  - 当前节点的左子树中的任何一点的权值 < 当前节点的权值
  - 当前节点的右子树中的任何一点的权值 > 当前节点的权值
  - 所有节点权值均不同，使用cnt[]记录每个权值出现的次数替代重复权值节点
  - 中序遍历：左 -> 根 -> 右，从小到大排序
  - 操作
    - 插入
    - 删除
    - 找前驱、后继
    - 找最大值、最小值
    - 求某个值的排名
    - 求排名是k的数
    - lower_bound
    - upper_bound
  - set
    - 插入 insert
    - 删除 erase
    - 前驱、后继 ++,  --
    - 最大、最小 begin, end - 1

- 堆(heap)

  

> BST 二叉搜索树

```

```



> 小标题

```

```



> 小标题

```

```



## AC自动机

- Trie + KMP

- next[i]: 在p[i]中，以p[i]结尾的后缀，能够匹配的从1开始的**非平凡**（非原串）前缀的最大长度

- 优化：trie图

  

> KMP求next[]

```
# s, p的下标从1开始
next[0] = next[1] = 1;
for(int i = 2; i <= n; i++)
{
		int j = next[i - 1];
		while(j && p[i] != p[j + 1]) j = next[j];
		if(p[i] == p[j + 1])j++;
		next[i] = j;
}
```



> AC自动机求next[]

```
while(hh <= tt)
{
		t = q[hh ++];
		for(int i = 0; i < 26; i++)
		{
				c = tr[t, i];
				if(!c)continue;
				j = next[t];
				 (j && !tr[j][i])j = next[j];
				if(tr[j][i])j = tr[j][i];
				next[c] = j;
				q[++ tt] = c;
		}
}
```



> 小标题

```

```



## 可持久化数据结构

- 解决什么问题？

  - 保存数据结构的所有历史版本
  - 核心：只记录每个版本与前一个版本不同的节点

- Trie的可持久化

  - 

- 线段树的可持久化 

  - 主席树
  - 难以进行区间修改

  

> Trie的可持久化

```
p = root[i - 1], q = root[i] = ++ idx;
if(p) tr[q] = tr[p];
tr[q][si] = ++ idx;
p = tr[p][si], q = tr[q][si]
```



> 小标题

```

```



> 小标题

```

```

