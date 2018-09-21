#include <stdio.h>
#include <stdlib.h>

int **mat;

int **generate(int A, int *len1, int *len2) {

	//printf("JB");
	int size = A, tot = A, i;
	
	mat = (int **)malloc(sizeof(int *)*size);
	//printf("B4 allocation");
	for(i = 0; i < size; i++) {
	
		*(mat+i) = (int *)malloc(sizeof(int)*size);
	}
	int row = 0, col = 0, start = 0;
	i = 1;
	//printf("Allocated");
	
	
	
	//printf("B4 entering..");
	while(i <= tot*tot) {
	
		//printf("Entered..");
		while(col < size) {
		
			//printf("0 ");
			mat[row][col++] = i++;
			//printf("1 ");
		}
		col--;
		row++;
		while(row < size) {
		
			mat[row++][col] = i++;
			//printf("2 ");
		}
		row--;
		col--;
		while(col >= start) {
		
			mat[row][col--] = i++;
			//printf("3 ");
		}
		col++;
		row--;
		start++;
		while(row >= start) {
		
			mat[row--][col] = i++;
			//printf("4 ");
		}
		row++;
		col++;
		size--;
		
	}
	//printf("Alloted");
	*len1 = A;
	*len2 = A;
	//printf("Returning..");
	return mat;
}

int main() {

	
	int size;
	scanf("%d",&size);
	int a, b;
	int *len1 = &a;
	int *len2 = &b;
	
	int i, j;
	
	//printf("kewndk");
	int **mat1 = generate(size, len1, len2);
	
	for(i = 0; i < *len1; i++) {
	
		for(j = 0; j < *len2; j++) {
		
			printf("%d ", mat1[i][j]);
		}
		printf("\n");
	}
	return 0;
}
