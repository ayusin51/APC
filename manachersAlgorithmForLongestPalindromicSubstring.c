#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <limits.h>

int *lps;

int min(int a, int b) {

  return ((a > b) ? b : a);
}

void computeStr(char *arr, char *a) {

  int len = strlen(a);
  int i = 0, j = 0;
  for(i = 0; i < len; i++) {
    
    arr[j++] = '$';
    arr[j++] = a[i];
  }
  arr[j++] = '$';
  arr[j] = '\0';
}

void calcLPS(char *arr) {

  int len = strlen(arr);
  lps = (int *)malloc(sizeof(int) * len);
  int start = 1, end = 1, i;
  lps[0] = 1;
  lps[len - 1] = 1;
  for(i = 1; i < len - 1;) {

      while(start > 0 && end < len-1 && arr[start - 1] == arr[end + 1]) {

        start--;
        end++;
      }
      lps[i++] = end - start + 1;
      int j = i;
      while(j <= end) {

        lps[j] = min(lps[2 * (i - 1) - j], 2 * ( end - j) + 1);
        if((j + lps[j] / 2) == end) {

          i = j;
          break;
        } else  j++;
      }
      start = i;
      end = i;
    }
  
}

char* longestSubstring(char *a) {

  char *arr = (char *)malloc(sizeof(char) * (2 * strlen(a) + 2));
  computeStr(arr, a);
  calcLPS(arr);
  int len = strlen(arr);
  int i, max = 0, pos = -1;
  for(i = 0; i < len; i++) {

    printf("%d ", lps[i]);
    if(lps[i] > max) {

      max = lps[i];
      pos = i;
    }
  }
    char *ans = malloc(max + 1);
    int start = pos - max / 2;
    int end = pos + max / 2;
    int k = 0;
    while(start <= end) {

      if(arr[start] != '$')
        ans[k++] = arr[start++];
      else
        start++;
    }
    ans[k] = '\0';
    return (ans);
  
}

int main() {

  char *arr = malloc(12);
  strcpy(arr, "abaxabaxabb");
  char* ans = longestSubstring(arr);
  puts(ans);
}
