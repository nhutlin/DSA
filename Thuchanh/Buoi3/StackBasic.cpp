#include <iostream>
using namespace std;
struct NODE {
    int value;
    NODE* pnext;
};
struct STACK {
    NODE* pHead;
    NODE* pTail;
};
NODE* createNode(int value) {
    NODE *p = new NODE;
    if(p == NULL) return NULL;
    p->value = value;
    p->pnext = NULL;
    return p;
}
void initStack(STACK &l) {
    l.pHead = NULL;
    l.pTail = NULL;
}
void insertHead(STACK &s, int value) {
    NODE* p = createNode(value);
    if(s.pHead == NULL) {
        s.pHead = p;
        s.pTail = p;
    } else {
        p->pnext = s.pHead;
        s.pHead = p;
    }
}
NODE* deleteHead(STACK &s) {
    NODE* p = s.pHead;
    NODE* q;
    if(s.pHead == NULL) return NULL;
    s.pHead = p->pnext;
    q = new NODE(*p);
    delete p;
    return q;
}
void insertTail(STACK &l, int value) {
    NODE* p = createNode(value);
    if(l.pHead == NULL) {
        l.pHead = p;
        l.pTail = p;
    } else {
        l.pTail->pnext = p;
        l.pTail = p;
    }
}
bool isEmpty(STACK s) {
    if(s.pHead == NULL) return 1;
    return 0;
}
void push(STACK &s, int value) {
    insertHead(s, value);
}
int pop(STACK &s) {
    NODE *p = deleteHead(s);
    if(p == NULL) return -1;
    return p->value;
}
int Top(STACK s) {
    return s.pHead->value;
}
int main () {
    STACK s;
    int luachon = 0, k;
    do {
        cout << "1. Khoi tao Stack" << endl;
        cout << "2. Kiem tra Stack rong" << endl;
        cout << "3. Day phan tu vao Stack" << endl;
        cout << "4. Lay phan tu ra khoi Stack" << endl;
        cout << "5. Xuat phan tu TOP ra khoi Stack" << endl;
        cout << "0. Thoat" << endl;
        cout << "Moi nhap lua chon: ";
        cin >> luachon;
        switch(luachon) {
            case 1:
                initStack(s);
                break;
            case 2:
                if(isEmpty(s)) cout << "Stack rong";
                else cout << "Stack khong rong";
                break;
            case 3:
                cout << "Nhap gia tri can day vao Stack: ";
                cin >> k;
                push(s, k);
                break;
            case 4:
                cout << "Phan tu vua duoc lay ra khoi Stack: " << pop(s);
                break;
            case 5:
                cout << "Phan tu TOP cua Stack: " << Top(s);
                break;
            default: 
                break;
        }
        cout << endl;
        fflush(stdin);
    }while(luachon != 0);
    return 0;
}
