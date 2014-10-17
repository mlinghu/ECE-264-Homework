#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"answer06.h"

int inmap(int x ,int y, int w, int h, char** maze)
{
  return(x >= 0 && y >= 0 && x < h && y < w && maze[x][y] == ' ');
}

void out(int* a, int cnt)
{
  const char Dir[] = {'E','W','S','N'};
  int tot = 1;
  int i =2;
  while (i <= cnt)
  {
    if (a[i] == a[i-1])
    {
      tot++;
    }
    else
    {
      printf("%c %d\n",Dir[a[i-1]], tot);
      tot = 1;
    }
    i++;
  }
}

void dfs(char** maze, int w, int h, int now, int* dir, int deep, int cnt, int tot, int* vis, int* over)
{
  const int dx[] = {0,0,1,-1};
  const int dy[] = {1,-1,0,0};
  if (*over)
  {
    return;
  }
  if (cnt == tot)
  {
    *over = 1;
    out(dir, deep);
    return;
  }
  int i;
  for (i = 0;i < 4; i++)
  {
    int x = now/w +dx[i];
    int y = now%w + dy[i];
    int next = x*w + y;
    if (inmap(x,y,w,h,maze))
    {
      if (!vis[next])
      {
        vis[next] = cnt + 1;
        int temp = dir[deep];
        dir[deep] = i;
        dfs(maze, w, h, next, dir, deep + 1, cnt + 1, tot, vis, over);
        dir[deep] = temp;
        vis[next] = 0;
      }
      else if (vis[next] < cnt)
      {
        int vistemp = vis[next];
        int temp = dir[deep];
        vis[next] = cnt;
        dir[deep] = i;
        dfs(maze, w, h, next, dir, deep + 1, cnt, tot, vis, over);
        dir[deep] = temp;
        vis[next] = vistemp;
      }
    }
  }
}

void print_directions(char** maze, int w, int h)
{
  int over = 0;;
  int i,j;
  int vis[10000], dir[10000];
  int tot = 0;
  memset(vis, 0, sizeof(vis));
  memset(dir, -1, sizeof(dir));
  for (i = 0; i < h; i++)
  {
    for (j = 0; j < w; j++)
    {
      if (maze[i][j] == ' ')
      {
        tot++;
      }
    }
  }
  int ini = 0;
  for (j = 0; j < w; j++)
  {
    if (maze[0][j] == ' ');
    {
      ini = j;
      break;
    }
  }
  vis[ini] = 1;
  dfs(maze, w, h, ini, dir, 1, 1, tot, vis, &over);
}
