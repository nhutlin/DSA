#include <iostream>
#include <stdlib.h>
#include <time.h>
#define MAX 101
using namespace std;
struct NODE {
    int value;
    NODE* pnext;
};
struct list {
    NODE* pHead;
    NODE* pTail;
};
NODE* createNODE(int val) {
    NODE* p = new NODE;
    if(p == NULL) return NULL;
    p->value = val;
    p->pnext = NULL;
    return p;
}
void initList(list &l) {
    l.pHead = NULL;
    l.pTail = NULL;
}
void insertHead(list &l, int val) {
    NODE *p = createNODE(val);
    if(l.pHead == NULL) {
        l.pHead = p;
        l.pTail = p;
    } else {
        p->pnext = l.pHead;
        l.pHead = p;
    }
}
void insertTail(list &l, int val) {
    NODE *p = createNODE(val);
    if(l.pHead == NULL) {
        l.pHead = p;
        l.pTail = p;
    } else {
        l.pTail->pnext = p;
        l.pTail = p;
    }
}
void XuatDS(list l) {
    NODE* head = l.pHead;
    while(head != NULL) {
        cout << head->value << " ";
        head = head->pnext;
    }
}
void NhapthucongDS(list &l) {
    int k;
    do {
        cout << "Nhap gia tri muon them vao ds: ";
        cin >> k;
        if(k == -1) break;
        insertHead(l, k);
    }while(1);
}
void NhaptudongDS(list &l) {
    int sl, k;
    srand(time(NULL));
    cout << "Nhap so luong phan tu trong danh sach: ";
    cin >> sl;
    for(int i = 0; i < sl; i++) {
        k = rand() % (99 + 99 + 1) - 99;
        insertTail(l, k);
    }
}
void deleteHead(list &l) {
    NODE* p = l.pHead;
    l.pHead = p->pnext;
    p->pnext = NULL;
    delete p;
}
void SortTang(list &l) {
    for(NODE *p = l.pHead; p != NULL; p = p->pnext)
        for(NODE *q = l.pHead; q != NULL; q = q->pnext)
            if (p->value < q->value)
                swap(p->value, q->value);
}
void SortGiam(list &l) {
    for(NODE *p = l.pHead; p != NULL; p = p->pnext)
        for(NODE *q = l.pHead; q != NULL; q = q->pnext)
            if (p->value > q->value)
                swap(p->value, q->value);
}
void DaonguocDS(list &l) {
    NODE* p = l.pHead;
    NODE* prev = NULL;
    NODE* next = NULL;
    while (p != NULL) {
        next = p->pnext;
        p->pnext = prev;
        prev = p;
        p = next;
    }
    l.pHead = prev;    
}
int main() {
    int n, k;
    int luachon = 0;
    list l;
    int a[MAX];
    do {
        cout << "1. Khoi tao danh sach lien ket" << endl;
        cout << "2. Chen node vao dau danh sach" << endl;
        cout << "3. Chen node vao cuoi danh sach" << endl;
        cout << "4. Nhap thu cong cac gia tri danh sach" << endl;
        cout << "5. Nhap tu dong cac gia tri danh sach" << endl;
        cout << "6. In ra cac gia tri danh sach " << endl;
        cout << "7. Sap xep danh sach tang" << endl;
        cout << "8. Sap xep danh sach giam" << endl;
        cout << "9. Dao nguoc danh sach" << endl;
        cout << "0. Thoat" << endl;
        cout << "Moi nhap lua chon: ";
        cin >> luachon;
        switch(luachon) {
            case 1:
                initList(l);
                break; 
            case 2:
                cout << "Nhap gia tri can chen: ";
                cin >> k;
                insertHead(l, k);
                break; 
            case 3:
                int k;
                cout << "Nhap gia tri can chen: ";
                cin >> k;
                insertTail(l, k);
                break; 
            case 4:
                NhapthucongDS(l);
                break; 
            case 5:
                NhaptudongDS(l);
                break;
            case 6:
                XuatDS(l);
                break;
            case 7:
                SortTang(l);
                cout << "Danh sach sau khi sap xep: ";
                XuatDS(l);
                break;
            case 8:
                SortGiam(l);
                cout << "Danh sach sau khi sap xep: ";
                XuatDS(l);
                break;
            case 9:
                DaonguocDS(l);
                cout << "Danh sach sau khi dao nguoc: ";
                XuatDS(l);
                break;
            default: 
                break;
        }
        cout << endl;
        fflush(stdin);
    }while(luachon != 0);
    return 0;
}
