//Họ và tên: Trần Nhựt Linh
//Buổi 01 - Bai 02
#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <math.h>
using namespace std;
void Nhapdayso(int a[], int& sl) {
    cout << "Nhap so luong: ";
    cin >> sl;
    for (int i = 0; i < sl; i++)
        cin >> a[i];
}
void NhapdaysoTuDong(int a[], int& sl) {
    srand(time(NULL));
    sl = rand() % (50 - 10 + 1) + 10;
    for (int i = 0; i < sl; i++)
        a[i] = rand() % (999 + 999 + 1) + 999;
}
void Xuatdayso(int a[], int sl) {
    cout << "Day so da nhap: ";
    for (int i = 0; i < sl; i++)
        cout << a[i] << " ";
}
int SoluongPhantu(int a[], int sl) {
    cout << "So phan tu cua day so: ";
    int dem = 0;
    for (int i = 0; i < sl; i++)
        dem++;
    return dem;
}
int main()
{
    int dayso[100];
    int n{}, luachon = 0;
    do {
        cout << "1. Nhap bang tay day so" << endl;
        cout << "2. Nhap tu dong day so" << endl;
        cout << "3. Hien thi day so" << endl;
        cout << "4. Hien thi so luong cac phan tu" << endl;
        cout << "0. Thoat" << endl;
        cout << "Vui long nhap lua chon: ";
        cin >> luachon;
        switch (luachon) {
        case 1:
            Nhapdayso(dayso, n);
            break;
        case 2:
            NhapdaysoTuDong(dayso, n);
            break;
        case 3:
            Xuatdayso(dayso, n);
            break;
        case 4:
            cout << SoluongPhantu(dayso, n);
            break;
        default:
            break;
        }
        cout << endl;
        fflush(stdin);
    } while (luachon != 0);
    return 0;
}
