

#ifndef PROJEKTI_STRUCT_H
#define PROJEKTI_STRUCT_H

#include <string.h>

struct result
{
    int arr[9];
    int len;
};

struct result getPossibilities(int arr[][9], int x, int y)
{
    int possibilities[9];
    for(int i=0;i<9;i++) possibilities[i] = i+1;

    //traversing the row
    for(int i=0;i<9;i++)
        if(arr[x][i] != -1)
            possibilities[arr[x][i]-1] = -1;
    //traversing the column
    for(int i=0;i<9;i++)
        if(arr[i][y] != -1)
            possibilities[arr[i][y]-1] = -1;
    //traversing the arr.
    int arr_start_x = (x/3)*3;
    int arr_start_y = (y/3)*3;

    for(int i=arr_start_x;i<arr_start_x+3;i++)
        for(int j=arr_start_y;j<arr_start_y+3;j++)
            if(arr[i][j] != -1)
                possibilities[arr[i][j]-1] = -1;
    int temp_poss[9];
    int index = 0;
    memset(temp_poss, -1 , 9*sizeof(int));


    for(int i=0;i<9;i++)
        if(possibilities[i]!=-1)
            temp_poss[index++] = possibilities[i];
    struct result res;
    memcpy(res.arr, temp_poss,index*sizeof(int));
    res.len = index;
    return res;
}

#endif //PROJEKTI_STRUCT_H
