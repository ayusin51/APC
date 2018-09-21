#include <stdio.h>
#include <math.h>

int binToDec(int bin) {

	int dec = 0, count = 0;
	while(bin) {
	
		dec += (bin%10)*pow(2, count++);
		bin /= 10;
	}
	return dec;
}

int main() {

	int bin;
	scanf("%d", &bin);
	int dec = binToDec(bin);
	printf("Decimal : %d\n", dec);
}
