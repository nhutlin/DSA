#include <iostream>
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
void Xuat1Donthuc(Donthuc a) {
    cout << a.heso << "x^" << a.somu;

}
void NhapDathuc(Donthuc d[100], int &sl) {
    cout << "Nhap so luong don thuc: ";
    cin >> sl;
    for(int i = 0; i < sl; i++)
        Nhap1Donthuc(d[i]);
}
void XuatDathuc(Donthuc d[100], int sl) {
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
int main() {
    Donthuc a[100];
    int n;
    NhapDathuc(a, n);
    XuatDathuc(a, n);
    return 0;

}