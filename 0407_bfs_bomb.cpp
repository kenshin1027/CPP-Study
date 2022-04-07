#include <iostream>
using namespace std;

struct note
{
    int x;
    int y;
};
char a[20][20];
int getnum(int i, int j)
{
    int sum,x,y;
    sum = 0;
    x = i; y = j;
    while(a[x][y] != '#')
    {
        if(a[x][y] == 'G')
            sum++;
        x--;
    }
    x = i; y = j;
    while(a[x][y] != '#')
    {
        if(a[x][y] == 'G')
            sum++;
        x++;
    }
    x = i; y = j;
    while(a[x][y] != '#')
    {
        if(a[x][y] == 'G')
            sum++;
        y--;
    }
    x = i; y = j;
    while(a[x][y] != '#')
    {
        if(a[x][y] == 'G')
            sum++;
        y++;
    }
    return sum;
}

int main()
{
    struct note que[401];
    int head,tail;
    int book[20][20]={0};
    int i,j,k,m,n,sum,maxnum=0;
    int mx,my,startx,starty,tx,ty;
    int next[4][2]={
        {0,1},{1,0},{0,-1},{-1,0}
    };
    scanf("%d %d %d %d",&n, &m, &startx, &starty);
    for(i = 0; i <= n-1; i++)
        scanf("%s", a[i]);
    head = 1; tail = 1;
    que[tail].x = startx;
    que[tail].y = starty;
    tail++;
    book[startx][starty] = 1;
    maxnum = getnum(startx, starty);
    mx = startx;
    my = starty;

    while(head < tail)
    {
        for(k = 0; k <= 3; k++)
        {
            tx = que[head].x + next[k][0];
            ty = que[head].y + next[k][1];
            if(tx<1 || tx>n || ty<1 || ty>m)
                continue;
            if(a[tx][ty] =='.' && book[tx][ty] == 0)
            {
                book[tx][ty] = 1;
                que[tail].x = tx;
                que[tail].y = ty;
                tail++;
                sum = getnum(tx, ty);
                if(sum > maxnum)
                {
                    maxnum = sum; mx = tx; my = ty;
                }
            }
        }
        head++;
    }
    printf("put bomb at (%d,%d) can kill %d monsters!\n",mx, my, maxnum);
    return 0;
}
/*
#############
#GG.GGG#GGG.#
###.#G#G#G#G#
#.......#..G#    
#G#.###.#G#G#
#GG.GGG.#.GG#
#G#.#G#.#.#.#
##G...G.....#
#G#.#G###.#G#
#...G#GGG.GG#
#G#.#G#G#.#G#
#GG.GGG#G.GG#
#############
*/