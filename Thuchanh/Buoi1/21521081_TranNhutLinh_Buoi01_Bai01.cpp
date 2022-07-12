//Họ và tên: Trần Nhựt Linh
//Buổi 01 - Bài  01
#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <math.h>
using namespace std;
struct Donthuc {
    int somu;
    int heso;
};
void Nhap1Donthuc(Donthuc &a) {
    cout << "Nhap he so: ";
    cin >> a.heso;
    cout << "Nhap so mu: ";
    cin >> a.somu;

}
void Nhap1DonthucTuDong (Donthuc &a) {
    a.heso = rand() % (79 - 39 + 1) + 39;
    a.somu = rand() % (9 - 0 + 1) + 0;
}
void Xuat1Donthuc(Donthuc a) {
    cout << a.heso << "x^" << a.somu;
}
void NhapDathuc(Donthuc d[100], int &sl) {
    cout << "Nhap so luong don thuc: ";
    cin >> sl;
    for(int i = 0; i < sl; i++)
        Nhap1Donthuc(d[i]);
}
void NhapDathucTuDong(Donthuc d[100], int &sl) {
    srand(time(NULL));
    sl = rand() % (10 - 1 + 1) + 1;
    for(int i = 0; i < sl; i++) 
        Nhap1DonthucTuDong(d[i]);
}
void XuatDathuc(Donthuc d[100], int sl) {
    cout << "y = f(x) = ";
    for(int i = 0; i < sl; i++){
        if(i == 0) Xuat1Donthuc(d[i]);
        else {
            if(d[i].heso >= 0) {
                cout << "+";
                Xuat1Donthuc(d[i]);
            }
            else Xuat1Donthuc(d[i]);
        }
    }
}
float TinhGiaTriDathuc(Donthuc d[100], int sl, int x) {
    float gt;
    for(int i = 0; i < sl; i++) {
        gt = gt + d[i].heso * pow(x, d[i].somu);
    }
    return gt;
}
   
void BacLonNhat(Donthuc d[100], int sl) {
    cout << "Don thuc co bac lon nhat la: ";
    Donthuc max;
    max.somu = d[0].somu;
    for(int i = 0; i < sl; i++) {
        if(d[i].somu >= max.somu) {
            max = d[i];
        }
    }
    cout << max.heso << "x^" << max.somu;
}
void BacNhoNhat(Donthuc d[100], int sl) {
    cout << "Don thuc co bac nho nhat la: ";
    Donthuc min;
    min.somu = d[0].somu;
    for(int i = 0; i < sl; i++) {
        if(d[i].somu <= min.somu) {
            min = d[i];
        }
    }
    cout << min.heso << "x^" << min.somu;
}
int main() {
    Donthuc a[100];
    int n, x, luachon = 0;
    do {
        cout << "1. Nhap bang tay da thuc" << endl;
        cout << "2. Nhap tu dong da thuc" << endl;
        cout << "3. Hien thi da thuc" << endl;
        cout << "4. Tinh gia tri da thuc" << endl;
        cout << "5. Tim don thuc co bac lon nhat" << endl;
        cout << "6. Tim don thuc co bac nho nhat" << endl;
        cout << "0. Thoat" << endl;
        cout << "Moi nhap lua chon: ";
        cin >> luachon;
        switch(luachon) {
            case 1:
                NhapDathuc(a, n);
                break;
            case 2:
                NhapDathucTuDong(a, n);
                break;
            case 3:
                XuatDathuc(a, n);
                break;
            case 4:
                cout << "Nhap vao gia tri muon tinh: ";
                cin >> x;
                cout << "Gia tri cua da thuc voi x la: " <<TinhGiaTriDathuc(a, n, x);
                break;
            case 5:
                BacLonNhat(a, n);
                break;
            case 6:
                BacNhoNhat(a, n);
                break;
            default:
                break;
        }
        cout << endl;
        fflush(stdin);
    } while(luachon != 0);
    return 0;
}