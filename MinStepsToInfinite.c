#include <stdio.h>

int main() {

	int size;
	scanf("%d", &size);
	int *arr = (int *)malloc(sizeof(int)*size);
	int i;
	for(int i = 0; i < size; i++) {
		
		scanf("%d", (arr+i));
	}
	
	
}
