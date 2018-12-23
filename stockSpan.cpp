#include <iostream>
#include <stack>
using namespace std;

void calcSpan(int *arr, int *S, int n) {

    stack<int> s;
    s.push(0);

    S[0] = 1;

    for(int i = 1; i < n; i++) {

        while(!s.empty() && arr[s.top()] <= arr[i]) s.pop();
        
        S[i] = (s.empty() ? i + 1 : i - s.top());

        s.push(i);
    }
}

void printArr(int *arr, int n) {

    for(int i = 0; i < n; i++) {

        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {

    int tc;
    cin >> tc;
    while(tc--) {

        int n;
        cin >> n;
        int *arr = new int[n];
        int *S = new int[n];
        for(int i = 0; i < n; i++) {

            cin >> arr[i];
        }

        calcSpan(arr, S, n);
        cout << endl << "Case #" << tc + 1 << endl;
        printArr(S, n);
    }

    return 0;
}
