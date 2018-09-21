#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int min(int a, int b) {

  return (a < b) ? a : b;
}

int strStr(char* str1, char* str2) {

  int l1 = strlen(str1), l2 = strlen(str2), i;
  int l = 0, r = 0;

  char *string = (char *)malloc(l1 + l2 + 1);
  strcat(string, str2);
  strcat(string, "$");
  strcat(string, str1);

  int *Z = (int *)calloc(sizeof(int), (l1 + l2 + 1));

  int len = l1 + l2 + 1;

  for(i  = 1; i < len;) {
  
    l = i;
    r = i;
    while(r < len && string[r] == string[r - i]) r++;
    r--;
    Z[i++] = r - l + 1;
//    else Z[i++] = 0;
    
    int j = i;
    while(j <= r) {

      Z[j] = min(Z[j - i + 1], r -j + 1);
      if(j + Z[j] == r) {

         break;
      }
      j++;
    }
    i = j;
  }

  // printing z-array
  for(i = 0; i < len ; i++) {

      printf("%d  ", Z[i]);
  }
  return 0;
}

int main() {

  char *str1 = "xyzabzcdabadx";
  char *str2 = "aba";
  
  printf("--%d\n", strStr(str1, str2));
  return 0;
}
