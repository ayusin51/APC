#include <stdio.h>
#include <stdlib.h>

int main() {

	int size, i, j;
	scanf("%d", &size);
	int **arr = (int**)malloc(sizeof(int *)*size);
	for(i = 0 ; i < size; i++) {
	
		*(arr+i) = (int *)malloc(sizeof(int)*(i+1));
		arr[i][i] = arr[i][0] = 1;
	}
	
	for(i = 2; i < size; i++) {
	
		for(j = 1; j < i; j++) {
		
			arr[i][j] = arr[i-1][j] + arr[i-1][j-1];
		}
	}
	
	for(i = 0; i < size; i++ ) {
	
		for(j = 0; j < i+1; j++) {
		
			printf("%d ", arr[i][j]);
		}
		printf("\n");
	}
	
}
