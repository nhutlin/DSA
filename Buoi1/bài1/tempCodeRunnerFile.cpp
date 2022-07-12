#include <iostream>
#include <cmath>
using namespace std;
bool SCP(int a) {
    return (sqrt(a) == int(sqrt(a)));
}
int main() {
    float k, a[100];
    int i = 0;
    int dem = 0;
    do {
        cin >> k;
        a[i] = k;
        i++;
        dem++;
        if(k == 9) break;
    }while(1);
    float max = a[0];
    for(int i = 0; i <= dem; i++) {
        if(SCP(a[i]) == 1 && a[i] >= max) max = a[i]; 
    }
    cout << max;
    return 0;

}