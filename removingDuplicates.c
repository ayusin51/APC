#include <stdio.h>
#include <stdlib.h>

int main() {

	int size, count = 0;
	scanf("%d", &size);
	int *arr = (int *)malloc(sizeof(int)*size);
	int i;
	for(i = 0; i < size; i++) {
		
		scanf("%d", (arr+i));
	}
	
	/*for(i = 1; i < size; i++) {
	
		if(arr[i] == arr[i-1]) {
		
			count++;
			arr[i] = -111111111;
		}
	}
	
	int new_size = size-count;
	
	int j = 0;
	i = 0;
	
	for(i = 0; i < size; i++) {
	
		if(arr[i] != -111111111) {
		
			arr[j++] = arr[i];
		}
		if(j == new_size) break;
	}*/
	
	int pos = 1;
	
	int temp = arr[0];
	
	for(i = 1; i < size; i++) {
	
		if(arr[i] != temp) {
		
			arr[pos++] = arr[i];
			temp = arr[i];
		}
	}
	
	int new_size = pos;
	
	for(i = 0; i < new_size; i++) {
		
		printf("%d ", arr[i]);
	}
	return 0;
}
