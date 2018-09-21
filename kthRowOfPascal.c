#include <stdio.h>
#include <stdlib.h>

int *ans;

int ncr(int n, int r) {

	if(r > n/2) {
	
		r = n-r;
	}
	
	int val = 1;
	while(r) {
	
		val *= n/r;
		n--;
		r--;
	}
	return val;
}

int * kthRow(int k) {

	//k++;

	ans = (int *)malloc(sizeof(int)*(k+1));
	
	int i;
	for(i = 0; i <= k; i++) {
	
		ans[i] = ncr(k, i);
	}
	
	return ans;
}

int main() {

	int row;
	scanf("%d", &row);
	int *ans = (int *)malloc(sizeof(int)*row);
	ans = kthRow(row);
	int i;
	for(i = 0; i < row+1; i++) {
	
		printf("%d ", ans[i]);
	}
	return 0;
}
