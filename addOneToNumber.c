#include <stdio.h>
#include <stdlib.h>

int countNum(int *arr, int n1) {

	int count = 0;
	int i, flag = 0;
	for(i = 0; i < n1; i++) {
		
		if(arr[i] != 0) flag = 1;
		if(flag) count++;
	}
	return count;
}

int *res;

int *plusOne(int *arr, int n1, int *len1) {

	int size = countNum(arr, n1);
	res  = (int *)malloc(sizeof(int)*size);
	int i;
	for(i = 0; i < size; i++ ){
	
		res[i] = arr[n1-i-1];
	}
	
	
	res[0]++;
	(*len1) = n1;
	
	
	if(res[0]>9) {
	
		int carry = res[0]/10;
		res[0] %= 10;
		i = 1;
		while(carry) {
		
			res[i] += carry;
			carry = res[i]/10;
			res[i] %= 10;
			i++;
			if(carry && i == size) {
			
				res = realloc(res, sizeof(int)*(size+1));
				(*len1)++;
			}
		}
	
	}

	for(i = 0; i < (*len1)/2; i++) {
	
		res[i] = res[i]^res[(*len1)-i-1];
		res[*len1-i-1] = res[i]^res[(*len1)-i-1];
		res[i] = res[i]^res[(*len1)-i-1];
	}
	
	return res;
}

int main() {

	int size;
	scanf("%d", &size);
	int i;
	int *arr = (int*)malloc(sizeof(int)*size);
	for(i = 0; i < size; i++) {
	
		scanf("%d", (arr+i));
	}
	int *len = (int*)malloc(4);
	int *res = plusOne(arr, size, len);
	//printf("\nCount : %d", *res);
	for(i = 0 ; i < (*len); i++) {
	
		printf("%d", res[i]);
	}
	
	return 0;

}
