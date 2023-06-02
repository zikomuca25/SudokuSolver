#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "struct.h"
void printEnteredValues(int n, int arr1[][n], int i, int j)
{
    for( i=0;i<n;i++)
    {
        printf("|");
        for( j=0;j<n;j++)
        {
            if(arr1[i][j]>=0&&arr1[i][j]<=9&&arr1[i+1][j]>=0&&arr1[i+1][j]<=9)
                printf(" %d ", arr1[i][j]);
            else if(arr1[i][j]>9 && arr1[i+1][j]>9)
                printf(" %d", arr1[i][j]);
            else if(arr1[i][j]>=0&&arr1[i][j]<=9&&arr1[i+1][j]>9)
                printf(" %d ", arr1[i][j]);
            else if(arr1[i][j]>9&&arr1[i+1][j]>=0&&arr1[i+1][j]<=9)
                printf(" %d", arr1[i][j]);
            if (((j + 1) % (int)sqrt(n)) == 0)
            {
                printf("|");
            }
        }
        printf("\n");
        if (((i + 1) % (int)sqrt(n)) == 0)
        {
            if(n==9)
                printf("-------------------------------\n");
            else if(n==16)
                printf("-----------------------------------------------------\n");
        }
    }
}
int getData(int n, int arr[][n], int arr1[][n], int i, int j)
{
    for( i=0;i<n;i++)
    {
        printf("Enter row %d:\n", i+1);
        for( j=0;j<n;j++)
        {
            scanf("%d", &arr[i][j]);
            if(arr[i][j]>n){
                printf("Number entered passes the limit");
                return 1;
            }
            arr1[i][j]=arr[i][j];
            if(arr[i][j] == 0)
                arr[i][j] = -1;
        }
    }
    return 0;
}
int getDataf(FILE** file, int n, int arr[][n], int arr1[][n], int i, int j)
{
    while (!feof (*file)){
        for( i=0;i<n;i++)
        {
            for( j=0;j<n;j++)
            {
                fscanf (*file, "%d", &arr[i][j]);
                if(arr[i][j]>n){
                    printf("Number entered passes the limit");
                    return 1;
                }
                arr1[i][j]=arr[i][j];
                
                if(arr[i][j] == 0)
                    arr[i][j] = -1;
            }
        }
    }
    return 0;
}
int solve(int n, int arr[][n], int x, int y)
{

    for(int i=x;i<n;i++)
    {
        for(int j=y;j<n;j++)
        {
            if(arr[i][j]==-1)
            {

                struct result res = getPossibilities(n, arr, i,j);
                if(res.len == 0)
                {
                    return 0;
                }
                for(int k=0;k<res.len;k++)
                {
                    arr[i][j] = res.arr[k];
                    if(solve(n,arr,x,y))
                        return 1;
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
    int i,j,n,test;
    printf("Welcome to Sudoku solver \n------------------------\n");
    printf("IMPORTANT: \n----------\n");
    printf("1) Enter every row separately \n2) Range of accepted numbers are from 1 until the number of rown/colums \n3) For empty places put 0 \n4) If the layout is unsolvable, the program will print:UNSOLVABLE \n5)For the number of rown/colums is required to enter a number which has a square root\n");
    printf("Press 1 if you want to enter the values directly. \nPress 2 if you want to read a file.\n");
    scanf("%d", &test);
    if(test==2){
        printf("Cation: \nThe file should be constructed with this guidelines in mind: \n1)The first thing writen in the file must be the nr of rows/columns present. \n2)The rown should be writen seperately. \n3)The file must be named Input.txt, and stored inside the programs file.\n");
        FILE *fptr;
        fptr = fopen("Input.txt", "r");
        if(fptr == NULL) {
            printf("Not able to open the file.");
            return 1;
        }
        fscanf (fptr, "%d", &n);
        int arr[n][n];
        int arr1[n][n];
        int ptest=getDataf(&fptr, n, arr, arr1, i, j);
        if(ptest==1){
            return 0;
        }
        int res = solve(n, arr,0,0);
        printf("The given puzzle is %s\n\n", (res==1?"SOLVABLE":"UNSOLVABLE"));
        printf("The entered values are:\n");
        if(n==9)
            printf("-------------------------------\n");
        else if(n==16)
            printf("-----------------------------------------------------\n");
        printEnteredValues(n, arr1, i, j);
        printf("\n");
        printf("The solution of the given values:\n");
        if(n==9)
            printf("-------------------------------\n");
        else if(n==16)
            printf("-----------------------------------------------------\n");
        for (i = 0; i < n; i++)
        {
            printf("|");
            for (j = 0; j < n; j++)
            {
                printf(" %d ", arr[i][j]);
                if (((j + 1) % (int)sqrt(n)) == 0)
                {
                    printf("|");
                }
            }
            printf("\n");
            if (((i + 1) % (int)sqrt(n)) == 0)
            {
                if(n==9)
                    printf("-------------------------------\n");
                else if(n==16)
                    printf("-----------------------------------------------------\n");
            }
        }
    }
    else if(test==1)
    {
        printf("Please enter the number of rows/columns: ");
        scanf("%d", &n);
        int arr[n][n];
        int arr1[n][n];
        int ptest=getData(n, arr, arr1, i, j);
        if(ptest==1){
            return 0;
        }
        int res = solve(n, arr,0,0);
        printf("The given puzzle is %s\n\n", (res==1?"SOLVABLE":"UNSOLVABLE"));
        printf("The entered values are:\n");
        if(n==9)
            printf("-------------------------------\n");
        else if(n==16)
            printf("-----------------------------------------------------\n");
        printEnteredValues(n, arr1, i, j);
        printf("\n");
        printf("The solution of the given values:\n");
        if(n==9)
            printf("-------------------------------\n");
        else if(n==16)
            printf("-----------------------------------------------------\n");
        for (i = 0; i < n; i++)
        {
            printf("|");
            for (j = 0; j < n; j++)
            {
                if(arr[i][j]>=0&&arr[i][j]<=9&&arr[i+1][j]>=0&&arr[i+1][j]<=9)
                    printf(" %d ", arr[i][j]);
                else if(arr[i][j]>9 && arr[i+1][j]>9)
                    printf(" %d", arr[i][j]);
                else if(arr[i][j]>=0&&arr[i][j]<=9&&arr[i+1][j]>9)
                    printf(" %d ", arr[i][j]);
                else if(arr[i][j]>9&&arr[i+1][j]>=0&&arr[i+1][j]<=9)
                    printf(" %d", arr[i][j]);
                if (((j + 1) % (int)sqrt(n)) == 0)
                {
                    printf("|");
                }
            }
            printf("\n");
            if (((i + 1) % (int)sqrt(n)) == 0)
            {
                if(n==9)
                    printf("-------------------------------\n");
                else if(n==16)
                    printf("-----------------------------------------------------\n");
            }
        }
    }
    else{
        printf("The entered value is wrong, please try again:");
        return 0;
    }
    printf("Thank you for using our program \nHave a nice day :)\n");
    return 0;
}
