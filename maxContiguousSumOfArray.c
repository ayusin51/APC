#include <stdio.h>
#include <stdlib.h>

int main() {

	int size, flag = 1, maxSum;
	scanf("%d", &size);
	int *arr = (int*)malloc(sizeof(int)*size);
	int i;
	for(i = 0 ; i < size; i++) {
	
		scanf("%d", (arr+i));
		if(*(arr+i)>0) flag = 0;
	}
	
	if(flag) {
	
		maxSum = *(arr);
		for(i = 1; i < size; i++) {
			
			if(*(arr+i) > maxSum) maxSum = *(arr+i);
		}
	}else {
	
		maxSum = *(arr);
		int sum = *(arr);
		for(i = 0; i < size; i++) {
	
			
			if(sum + *(arr + i) > *(arr + i)) {
		
				sum += *(arr+i);
				i++;
				
			}else {
			
				sum = *(arr+i);
				if(sum > maxSum) maxSum = sum;
				//sum = 0;
			}
			
			
		}
	}
	
	printf("Max Sum is %d", maxSum);
	
	return 0;
	
}

//

//max = a[0];
//sum = a[0];

