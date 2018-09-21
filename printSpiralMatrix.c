#include <stdio.h>
#include <stdlib.h>

int main() {

	int size, i, count = 1, j;
	scanf("%d", &size);
	int **mat = (int **)malloc(sizeof(int *)*size);
	
	for(i = 0; i < size; i ++) {
	
		*(mat+i) = (int *)malloc(sizeof(int)*size);
	}
	
	for(i = 0; i < size; i++) {
	
		for(j = 0; j < size; j++) {
		
			mat[i][j] = count++;
		}
	}
	
	int *arr = (int *)malloc(sizeof(int)*size*size);
	int row = 0, col = 0, start = 0, tot = size;
	
	i = 0;
	while(i < tot*tot) {
	
		while(col < size) {
		
			arr[i++] = mat[row][col++];
		}
		col--;
		row++;
		while(row < size) {
		
			arr[i++] = mat[row++][col];
		}
		row--;
		col--;
		while(col >= start) {
		
			arr[i++] = mat[row][col--];
		}
		col++;
		row--;
		start++;
		while(row >= start) {
		
			arr[i++] = mat[row--][col];
		}
		row++;
		col++;
		size--;
		
	}
	
	
	for(i = 0; i < tot*tot; i++) {
	
		printf("%d ", arr[i]);
	}
	return 0;
}
