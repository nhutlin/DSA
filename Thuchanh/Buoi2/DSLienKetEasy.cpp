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
    initList(l);
    float k;
    do {
        cout << "Moi nhap: ";
        cin >> k;
        if(k != int(k)) break;
        insertHead(l,k);
    }while(1);
}

void NhaptudongDS(list &l) {
    initList(l);
    int sl, k;
    srand(time(NULL));
    cout << "Nhap so luong phan tu trong danh sach: ";
    cin >> sl;
    for(int i = 0; i < sl; i++) {
        k = rand() % (99 + 99 + 1) - 99;
        insertTail(l, k);
    }
}
NODE* deleteHead(list &l) {
    NODE* p = l.pHead;
    NODE* q;
    q->value = p->value;
    l.pHead = p->pnext;
    p->pnext = NULL;
    delete p;
    return q;
}
void XuatAdress(list &l) {
    NODE* head = l.pHead;
    cout << "Dia chi cua tung phan tu trong ds: ";
    while(head != NULL) {
        cout << &(head->value) << " ";
        head = head->pnext;
    }
}
int Max(list l) {
    NODE* p;
    int max = l.pHead->value;
    p = l.pHead;
    while(p != NULL) {
        if(p->value >= max) max = p->value;
        p = p->pnext;
    }
    return max;
}
int Min(list l) {
    NODE* p;
    int min = l.pHead->value;
    p = l.pHead;
    while(p != NULL) {
        if(p->value <= min) min = p->value;
        p = p->pnext;
    }
    return min;
}
void NhapDSmang(list &l, int a[]) {
    initList(l);
    int n;
    cout << "Moi nhap so luong phan tu mang: ";
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        insertTail(l, a[i]);
    }
}
int main() {
    int k;
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
        cout << "7. In ra gia tri min va max trong danh sach" << endl;
        cout << "8. Nhap gia tri danh sach tu mang" << endl;
        cout << "9. In ra cac dia chi cua tung gia tri danh sach" << endl;
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
                cout << "Gia tri max trong danh sach la: " << Max(l) << endl;
                cout << "Gia tri min trong danh sach la: " << Min(l);
                break;
            case 8:
                NhapDSmang(l, a);
                break;
            case 9:
                XuatAdress(l);
            default: 
                break;
        }
        cout << endl;
        fflush(stdin);
    }while(luachon != 0);
    return 0;
}
