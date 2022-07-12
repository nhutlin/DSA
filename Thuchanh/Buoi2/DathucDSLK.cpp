#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <math.h>
using namespace std;
struct Data {
    int heso;
    int somu;
};
struct Donthuc {
    Data x;
    Donthuc* pnext;
};
struct Dathuc {
    Donthuc* pHead;
    Donthuc* pTail;
};
Donthuc* createDonthuc(Data x) {
    Donthuc *p = new Donthuc;
    if(p == NULL) return NULL;
    p->x.heso = x.heso;
    p->x.somu = x.somu;
    p->pnext = NULL;
    return p;
}
void initDathuc(Dathuc &d) {
    d.pHead = NULL;
    d.pTail = NULL;
}
void insertTail(Dathuc &d, Data x) {
    Donthuc* p = createDonthuc(x);
    if(d.pHead == NULL) {
        d.pHead = p;
        d.pTail = p;
    } else {
        d.pTail->pnext = p;
        d.pTail = p;
    }
}
void Nhap(Dathuc &d) {
    initDathuc(d);
    Data x;
    do {
        cout << "Moi nhap he so: ";
        cin >> x.heso;
        cout << "Moi nhap so mu: ";
        cin >> x.somu;
        if(x.heso == -1 && x.somu == -1) break;
        insertTail(d, x);
    } while(1);
}

void Nhaptudong(Dathuc &d) {
    initDathuc(d);
    int sl;
    Data x;
    srand(time(NULL));
    sl = rand() % (10 - 1 + 1) + 1;
    for(int i = 0; i < sl; i++) {
        x.heso = rand() % (79 - 39 + 1) + 39;
        x.somu = rand() % (9 - 0 + 1) + 0;
        insertTail(d, x);
    }
}
void Xuat(Dathuc d) {
    cout << "y = f(x) = ";
    Donthuc* head = d.pHead;
    cout << head->x.heso << "x^" << head->x.somu << " ";
    head = head->pnext;
    while(head != NULL) {
        if(head->x.heso >= 0)  cout << "+ " << head->x.heso << "x^" << head->x.somu << " ";
        else  cout << " " << head->x.heso << "x^" << head->x.somu << " ";
        head = head->pnext;
    }
}
float Tinhgiatri(Dathuc d, int x) {
    Donthuc* head = d.pHead;
    float gt = 0;
    while(head != NULL) {
        gt = gt + (head->x.heso * pow(x, head->x.somu));
        head = head->pnext;
    }
    return gt;
}
void BacLonNhat(Dathuc d) {
    Donthuc* max;
    Donthuc* head = d.pHead;
    max->x.somu = head->x.somu;
    while(head != NULL) {
        if(head->x.somu >= max->x.somu) max = head;
        head = head->pnext;
    }
    cout << max->x.heso << "x^" << max->x.somu;
}
void BacNhoNhat(Dathuc d) {
    Donthuc* min;
    Donthuc* head = d.pHead;
    min->x.somu = head->x.somu;
    while(head != NULL) {
        if(head->x.somu <= min->x.somu) min = head;
        head = head->pnext;
    }
    cout << min->x.heso << "x^" << min->x.somu;
}
int main() {
    int n, x, luachon = 0;
    Dathuc d;
    do {
        cout << "1. Khoi tao 1 da thuc" << endl;
        cout << "2. Nhap bang tay da thuc" << endl;
        cout << "3. Nhap tu dong da thuc" << endl;
        cout << "4. Hien thi da thuc" << endl;
        cout << "5. Tinh gia tri da thuc" << endl;
        cout << "6. Tim don thuc co bac lon nhat" << endl;
        cout << "7. Tim don thuc co bac nho nhat" << endl;
        cout << "0. Thoat" << endl;
        cout << "Moi nhap lua chon: ";
        cin >> luachon;
        switch(luachon) {
            case 1:
                initDathuc(d);
                break;
            case 2:
                Nhap(d);
                break;
            case 3:
                Nhaptudong(d);
                break;
            case 4:
                Xuat(d);
                break;
            case 5:
                cout << "Nhap vao gia tri muon tinh: ";
                cin >> x;
                cout << "Gia tri cua da thuc voi x la: " << Tinhgiatri(d, x);
                break;
            case 6:
                cout << "Don thuc co bac lon nhat la: ";
                BacLonNhat(d);
                break;
            case 7:
                cout << "Don thuc co bac nho nhat la: ";
                BacNhoNhat(d);
                break;
            default:
                break;
        }
        cout << endl;
        fflush(stdin);
    } while(luachon != 0);
    return 0;
}
