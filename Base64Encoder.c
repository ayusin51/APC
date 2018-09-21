#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char array[64];

void fillArray() {

	int i = 0;
	char ch = 'A';
	for(i = 0; i < 26; i++) {
	
		array[i] = ch;
		ch++;
	}
	
	ch = 'a';
	
	for(i = 26; i < 52; i++) {
	
		array[i] = ch;
		ch++;
	}
	
	ch = '0';
	
	for(i = 52; i < 62; i++) {
	
		array[i] = ch;
		ch++;
	}
	
	array[62] = '+';
	array[63] = '/';
	
}

char *strrev(char *str)
{
      char *p1, *p2;

      if (! str || ! *str)
            return str;
      for (p1 = str, p2 = str + strlen(str) - 1; p2 > p1; ++p1, --p2)
      {
            *p1 ^= *p2;
            *p2 ^= *p1;
            *p1 ^= *p2;
      }
      return str;
}

char* toBinary(char *str, int size) {

	char ch;
	char *bin = (char*)malloc(sizeof(char)*size);
	int i = 0, cnt, strPos = size-2;
	while(str[i] != '\0') {
	
		cnt = 0;
		ch = str[i];
		int num = (int)ch;
		while(cnt < 8) {
			
			if(num & 1) {
				
				bin[strPos--] = '1';
			}else {
			
				bin[strPos--] = '0';
			}
			num >>= 1;
 			
			cnt++;
		}
		i++;
	}
	while(strPos >=0) {
	
		bin[strPos--] = '0';
	}
	bin[size] = '\0';
	//puts(bin);	
	return bin;
	
}

char val(char *num) {

	int numout = 0;
	int i=0;
	while(i < 6) {
	
		numout <<= 1;
		if(num[i] == '1') {
		
			numout += 1;
		}
		i++;
	}
	return array[numout];
}

char *encode(char *bin, int size) {

	int outSize = (size-1)/6;
	char *output = (char*)malloc(sizeof(char)*(outSize+1));
	int start = 0, end = 5, pos = 0;
	while(end < size-1) {
	
		char temp[7];
		int i=0;
		while(i < 6) {
		
			temp[i] = bin[start+i];
			i++;
		}
		temp[i] = '\0';
		
		output[pos++] = val(temp);
		//printf("\nAfter func call : %c, pos :  %d\n", output[pos-1], pos-1);
		//puts(temp);
		
		start = end+1;
		end += 6;
	}
	//printf("\nTotal : %d", pos);
	output[pos] = '\0';
	//puts(output);
	
	return output;
}

int main() {

	fillArray();
	char str[100];
	printf("Enter the string to encode : ");
	gets(str);
	//puts(str);
	strrev(str);
	int len = strlen(str);
	int size = len*8 + (6-(len*8)%6) + 1;
	if((len*8)%6 == 0) size -= 6;
	char *bin = (char*)malloc(sizeof(char)*size);
	bin = toBinary(str, size);
	//puts(bin);
	
	char *output = (char*)malloc(sizeof(char)*(size-1)/6+1);
	output = encode(bin, size);
	printf("Encoded string is : %s\n", output);
	
}
