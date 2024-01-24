#include <iostream>
#include <string>
using namespace std;
double average_score(int n, int a[]){
    double sum = 0;
    for(int i = 0; i < n; i++) {
      sum += a[i];
   }
   return sum / n;
}
void sort(int n , int a[]) {
    int min_i;
    for(int i = 0; i < n - 1; i++) {
       min_i = i;
       for(int j = i + 1; j < n; j++) {
         if(a[j] < a[min_i]) {
            min_i = j;
         }
       }
       if(min_i != i) {
         int tmp = a[i];
         a[i] = a[min_i];
         a[min_i] = tmp;
       }
    }
}
int main() {
   int n;
   cin >> n;
   int a[n];
   for(int i = 0; i < n; i++) {
    cin >> a[i];
   }
    cout << average_score(n, a) << endl;
    sort(n, a);
    for(int i = 0; i < n; i++) {
    cout << a[i] << " ";
   }
}