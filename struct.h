

#ifndef PROJEKTI_STRUCT_H
#define PROJEKTI_STRUCT_H


#define MAX_SIZE 100

struct result
{
    int n;
    int len;
    int arr[MAX_SIZE];
};
struct result getPossibilities(int n, int arr[][n], int x, int y)
{
    int possibilities[n];
    for(int i=0;i<n;i++) possibilities[i] = i+1;

    //traversing the row
    for(int i=0;i<n;i++)
        if(arr[x][i] != -1)
            possibilities[arr[x][i]-1] = -1;
    //traversing the column
    for(int i=0;i<n;i++)
        if(arr[i][y] != -1)
            possibilities[arr[i][y]-1] = -1;
    //traversing the arr.
    int arr_start_x = (x/(int)sqrt(n))*(int)sqrt(n);
    int arr_start_y = (y/(int)sqrt(n))*(int)sqrt(n);

    for(int i=arr_start_x;i<arr_start_x+sqrt(n);i++)
        for(int j=arr_start_y;j<arr_start_y+sqrt(n);j++)
            if(arr[i][j] != -1)
                possibilities[arr[i][j]-1]=-1;
    int temp_poss[n];
    int index = 0;
    memset(temp_poss, -1 , n*sizeof(int));


    for(int i=0;i<n;i++)
        if(possibilities[i]!=-1)
            temp_poss[index++] = possibilities[i];
    struct result res;
    memcpy(res.arr, temp_poss,index*sizeof(int));
    res.len = index;
    return res;
}
#endif //PROJEKTI_STRUCT_H
