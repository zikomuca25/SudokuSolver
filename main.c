//
//  main.c
//  sudok
//
//  Created by Jord Thanasi on 29.5.23.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
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
    int arr1[9][9];
    int i,j;
    printf("Welcome to Sudoku solver \n------------------------\n");
    printf("IMPORTANT: \n----------\n");
    printf("1) Enter every row separately \n2) Range of accepted numbers are from 1 to 9 \n3) For empty places put 0 \n4) If the layout is unsolvable, the program will print:UNSOLVABLE\n");
    for( i=0;i<9;i++)
    {
        printf("Enter row %d:\n", i+1);
        for( j=0;j<9;j++)
        {
            scanf("%d", &arr[i][j]);
            arr1[i][j]=arr[i][j];
            if(arr[i][j] == 0)
                arr[i][j] = -1;
        }
    }
    printf("The entered values are:\n");
    printf("-------------------------------\n");
    for( i=0;i<9;i++)
    {
        printf("|");
        for( j=0;j<9;j++)
        {
            printf(" %d ", arr1[i][j]);
            if (((j + 1) % 3) == 0)
            {
                printf("|");
            }
        }
        printf("\n");
        if (((i + 1) % 3) == 0)
        {
            printf("-------------------------------\n");
        }
    }
    int res = solve(arr,0,0);
    printf("The given puzzle is %s\n\n", (res==1?"SOLVABLE":"UNSOLVABLE"));
    
    printf("The solution of the given values:\n");
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
        }
    }
    printf("Thank you for using our program \nHave a nice day 😀\n");
    return 0;
}
