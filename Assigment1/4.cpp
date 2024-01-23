#include <iostream>
#include <string>
using namespace std;
void revert_array (int n, int a[]){
    for(int i = 0; i < n/2; i++) {
      int tmp = a[i];
      a[i] = a[n - i - 1];
      a[n - i - 1] = tmp;
   }
}
int main() {
   int n;
   cin >> n;
   int a[n];
   for(int i = 0; i < n; i++) {
    cin >> a[i];
   }
   revert_array(n,a);
   for(int i = 0; i < n; i++) {
    cout << a[i] << " ";
   }
}