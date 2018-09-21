#include <stdio.h>
#include <math.h>

int main() {
	
	int n;
	int i;
	scanf("%d", &n);
	int ans = 0;
	for(i = 31; i >= 0; i--) {
	
		if((n & 1<<i)>>i == 1) {
		
			ans += pow(5, i+1);
		}
	}
	printf("ans : %d\n", ans);
} 

	

