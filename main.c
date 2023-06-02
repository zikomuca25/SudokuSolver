#include <stdio.h>
#include "struct.h"

int solve(int arr[][9], int x, int y)
{

    for(int i=x;i<9;i++)
    {
        for(int j=y;j<9;j++)
        {
            if(arr[i][j]==-1)
            {

                struct result res = getPossibilities(arr, i,j);
                if(res.len == 0)
                {
                    return 0;
                }
                for(int k=0;k<res.len;k++)
                {
                    arr[i][j] = res.arr[k];
                    if(solve(arr,x,y)) return 1;
                }
                arr[i][j] = -1;
                return 0;
            }
        }
    }
    return 1;
}

int main()
{
    int arr[9][9];
    int i,j;
    for( i=0;i<9;i++)
    {
        for( j=0;j<9;j++)
        {
            scanf("%d", &arr[i][j]);
            if(arr[i][j] == 0)arr[i][j] = -1;
        }
    }
    int res = solve(arr,0,0);
    printf("The given puzzle is %s\n\n", (res==1?"SOLVABLE":"UNSOLVABLE"));

    printf("-------------------------------\n");
    for (i = 0; i < 9; i++)
    {
        printf("|");
        /* print each row */
        for (j = 0; j < 9; j++)
        {
            printf(" %d ", arr[i][j]);

            if (((j + 1) % 3) == 0)
            {
                printf("|");
            }
        }
        printf("\n");
        if (((i + 1) % 3) == 0)
        {
            printf("-------------------------------\n");
        }}
    return 0;
}