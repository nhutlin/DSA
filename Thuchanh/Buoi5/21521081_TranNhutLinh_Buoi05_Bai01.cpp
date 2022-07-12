// Họ và tên: Trần Nhựt Linh
// Buổi 05 - Bài 01
#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <iomanip>
using namespace std;

void createArrayY(int *&a, int n) 
{
    int random;
    srand(time(NULL));
    a = new int[n];
    a[0] = 100;
    for(int i = 1; i < n; i++) {
        random = rand() % (15 - 1 + 1) + 1;
        a[i] = a[i - 1] + random;
    }
}

void createArrayX(int *&a, int n) 
{
    int random;
    srand(time(NULL));
    a = new int[n];
    a[0] = 100;
    for(int i = 0; i < n; i++) {
        random = rand() % (999 - 100 + 1) + 100;
        a[i] = random;
    }
}

int LinearSearch(int *a, int n, int X)
{
    for(int i = 0; i < n; i++) {
        if(X == a[i])
            return a[i];
    }
    return -1;
}

int BinarySearch(int *a, int n, int X)
{
    int l, r, m;
    l = 0;
    r = n - 1;
    while(l <= r) {
        m = (l + r) / 2;
        if(a[m] == X)
            return a[m];
        else if(X < a[m])
            r = m - 1;
        else if(X > a[m])
            l = m + 1;
    }
    return -1;
}

int countLinear(int *a, int n, int X) 
{
    int dem = 0;
    for(int i = 0; i < n; i++) {
        dem++;
        if(X == a[i]) break;
    }
    return dem;
}

int countBinary(int *a, int n, int X)
{
    int l, r, m, dem = 0;
    l = 0;
    r = n - 1;
    while(l <= r) {
        dem++;
        m = (l + r) / 2;
        if(a[m] == X)
            break;
        else if(X < a[m])
            r = m - 1;
        else if(X > a[m])
            l = m + 1;
    }
    return dem;

}

void Xuat(int *a, int n) {
    for(int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
}

int main() {
    int *a, *b;
    int n, x, kq;
    char luachon1, luachon2, luachon3;
    srand(time(NULL));
    n = rand() % (50 - 30 + 1) + 30;
    x = rand() % (999 - 100 + 1) + 100;
    int option = 0;
    do {
        cout << setfill('-');
        cout << setw(45) << right<< "MENU";
        cout << setw(45) << left << '-';
        cout << setfill('-');
        cout << endl;
        cout << setfill(' ');
        cout << "1. Tao mang" << endl;
        cout << setw(25) << right << "A. Tao mang arrayX" << endl;
        cout << setw(25) << right << "B. Tao mang arrayY" << endl;
        cout << "2. Xuat mang" << endl;
        cout << setw(25) << right << "A. Xuat mang arrayX" << endl;
        cout << setw(25) << right << "B. Xuat mang arrayY" << endl;
        cout << "3. Tim kiem tuyen tinh" << endl;
        cout << setw(25) << right << "A. Ap dung mang arrayX" << endl;
        cout << setw(25) << right << "B. Ap dung mang arrayY" << endl;
        cout << "4. Tim kiem nhi phan, ap dung mang arrayY" << endl;
        cout << "5. So sanh so lan tim kiem, ap dung arrayY" << endl;
        cout << setfill('-');
        cout << setw(45) << right<< "END";
        cout << setw(45) << left << '-';
        cout << setfill('-');
        cout << endl;
        cout << setfill(' ');
        cout << setw(25) << right << "Xin moi nhap lua chon: ";
        cin >> option;
        switch(option) {
            case 1:
                cout << setw(25) << right << "A. Tao mang arrayX" << endl;
                cout << setw(25) << right << "B. Tao mang arrayY" << endl;
                cout << "Moi nhap lua chon: ";
                cin >> luachon1;
                if(luachon1 == 'a' || luachon1 == 'A') createArrayX(a, n);
                else if(luachon1 == 'b' || luachon1 == 'B') createArrayY(b, n);
                break;
            case 2:
                cout << setw(25) << right << "A. Xuat mang arrayX" << endl;
                cout << setw(25) << right << "B. Xuat mang arrayY" << endl;
                cout << "Moi nhap lua chon:";
                cin >> luachon2;
                if(luachon2 == 'a' || luachon2 == 'A') Xuat(a, n);
                else if(luachon2 == 'b' || luachon2 == 'B') Xuat(b, n);
                break;
            case 3:
                cout << setw(25) << right << "A. Ap dung mang arrayX" << endl;
                cout << setw(25) << right << "B. Ap dung mang arrayY" << endl;
                cout << "Moi nhap lua chon: ";
                cin >> luachon3;
                if(luachon3 == 'a' || luachon3 == 'A') {
                    cin.ignore();
                    cout << "Gia tri X can tim la: " << x << endl;
                    if(LinearSearch(a, n, x) == -1) {
                        cout << "Khong tim duoc X";
                    }
                    else cout << "Da tim duoc X";
                }
                else if(luachon3 == 'b' || luachon3 == 'B') {
                    cout << "Gia tri X can tim la: " << x << endl;
                    if(LinearSearch(b, n, x) == -1) {
                        cout << "Khong tim duoc X";
                    }
                    else cout << "Da tim dc X";
                }
                break;
            case 4:
                cout << "Gia tri X can tim la: " << x << endl;
                if(BinarySearch(b, n, x) == -1)
                    cout << "Khong tim duoc X";
                else cout << "Da tim duoc X";
                break;
            case 5:
                if(countBinary(b, n, x) > countLinear(b, n, x))
                    cout << "So lan tim kiem nhi phan nhieu hon tuyen tinh (" << countBinary(b, n, x) << " lan so voi " << countLinear(b, n, x) << " lan)";
                else if(countBinary(b, n, x) < countLinear(b, n, x)) 
                    cout << "So lan tim kiem tuyen tinh nhieu hon nhi phan (" << countLinear(b, n, x) << " lan so voi " << countBinary(b, n, x) << " lan)";
                else cout << "So lan tim kiem cua ca 2 bang nhau (" << countBinary(b, n, x) << " lan)";
                break;
            default:
                break;
        }
        cout << endl;
        fflush(stdin);
    }while(option > 0 && option < 6);

    return 0;
}