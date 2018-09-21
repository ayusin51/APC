#include <stdio.h>
#include <stdlib.h>
/* Include other headers as needed */
int main()
{
  int row, col;
  scanf("%d %d", &row, &col);
  int **arr = (int **)malloc(sizeof(int *) * row);
  int i, j;
  for(i = 0; i < row; i++) {
    *(arr + i) = (int *)malloc(sizeof(int) * col);
  }
  for(i = 0; i < row; i++) {
    for(j = 0; j < col; j++) {
      scanf("%d", &arr[i][j]);
    }
  }
  
  int row_end = row, col_end = col;
  int row_start = -1, col_start = -1;
  i = j = 0;
  int flag = 0;
  while(row_start < row_end-1 && col_start < col_end-1) {
    //flag = 0;
    while(j < col_end) {
      printf("%d\n", arr[i][j++]);
      //flag = 1;
    }
    //if(flag) 
    j--;
    row_start++;
    i++;
    
    //flag = 0;
    if(!(row_start < row_end-1 && col_start < col_end-1)) break;
    while(i < row_end) {
      printf("%d\n", arr[i++][j]);
      //flag = 1;
    }
    //if(flag) 
    i--;
    col_end--;
    j--;
    
    if(!(row_start < row_end-1 && col_start < col_end-1)) break;
    //flag = 0;
    while(j > col_start) {
      printf("%d\n", arr[i][j--]);
      //flag = 1;
    }
    //if(flag) 
    j++;
    row_end--;
    i--;
    
    if(!(row_start < row_end-1 && col_start < col_end-1)) break;
    //flag = 0;
    while(i > row_start) {
      printf("%d\n", arr[i--][j]);
      //flag = 1;
    }
    //if(flag) 
    i++;
    col_start++;
    j++;
  }
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    return 0;
}





























