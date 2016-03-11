#include<iostream>
#include<cmath>
using namespace std;

typedef struct 
{
	int x;
	int y;
}dot;
dot dog, door;
char map[6][6];
int m, n, time,flag=-1;
int sur[1000];//存放结果
int runmaz(int x,int y,int t)
{   int test ;
	if (door.x == x && door.y == y && t == 0) return flag=1;
	if (( door.x != x || door.y !=y ) && t == 0) return 0;
	test = abs(door.x - x) + abs(door.y - y) - t;//奇偶剪枝
	if (test % 2 != 0) return flag=0;
	//dfs
	map[x][y] = 'X';
	if (x > 0 && map[x - 1][y] != 'X')//向上走
	{
		runmaz(x - 1, y, t - 1);
		if (flag == 1) 
			return flag=1;
	}
	if (x < m - 1 && map[x + 1][y] != 'X')//向下走
	{
		runmaz(x + 1, y, t - 1);
		if (flag == 1)
			return flag=1;
	}
	if (y > 0 && map[x][y-1] != 'X')//向左走
	{
		runmaz(x, y-1, t - 1);
		if (flag == 1)
			return flag=1;
	}
	if (y<n - 1 && map[x][y+1] != 'X')//向右走
	{
		runmaz(x, y+1, t - 1);
		if (flag == 1)
			return flag=1;
	}
	map[x][y] = '.';
   return 0;
}
int main()
{
	int cnt=0;
	while (cin >> m >> n >> time)
	{   
		
		if (m*n*time == 0) break;
	    flag = -1;
		for (int i = 0; i < m; i++)   //构造地图
			for (int j = 0; j < n; j++)
			{
				cin >> map[i][j];
				if (map[i][j] == 'D')
				{
					door.x = i;
					door.y = j;
				}
				if (map[i][j] == 'S')
				{
					dog.x = i;
					dog.y = j;
				}
			}
		sur[cnt++]=runmaz(dog.x,dog.y,time);

	}	
	for (int i = 0; i < cnt; i++)
	{
		if (sur[i] == 1)
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
	}
//	system("pause");
	return 0;
}