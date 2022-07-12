//Họ và tên: Trần Nhựt Linh
//Buổi 03 - Bài 02
#include <iostream>
using namespace std;
struct Node {
    int value;
    Node *pnext;
};
struct QUEUE {
    Node *pHead;
    Node *pTail;
};
Node* createNode(int value) {
    Node *p = new Node;
    if(p == NULL) return NULL;
    p->value = value;
    p->pnext = NULL;
    return p;
}
void initQueue(QUEUE &q) {
    q.pHead = NULL;
    q.pTail = NULL;
}
void insertTail(QUEUE &q, int value) {
    Node *p = createNode(value);
    if(q.pHead == NULL) {
        q.pHead = p;
        q.pTail = p;
    } else {
        q.pTail->pnext = p;
        q.pTail = p;
    }
}
Node* deleteHead(QUEUE &q) {
    Node *p = q.pHead;
    Node *t;
    if(q.pHead == NULL) return NULL;
    q.pHead = p->pnext;
    p->pnext = NULL;
    t = new Node(*p);
    delete p;
    return t;
}
bool isEmpty(QUEUE q) {
    return q.pHead == NULL;
}
void enQueue(QUEUE &q, int value) {
    insertTail(q, value);
}
int deQueue(QUEUE &q) {
    Node* p = deleteHead(q);
    if(p == NULL) return -1;
    return p->value;
}
int front(QUEUE q) {
    return q.pHead->value;
}
int rear(QUEUE q) {
    return q.pTail->value;
}
int main() {
    QUEUE q;
    int luachon = 0, k;
    do {
        cout << "1. Khoi tao Queue" << endl;
        cout << "2. Kiem tra Queue rong" << endl;
        cout << "3. Dua mot phan tu vao Queue" << endl;
        cout << "4. Lay mot phan tu ra khoi Queue" << endl;
        cout << "5. Xuat phan tu REAR va FRONT cua Queue" << endl;
        cout << "0. Thoat" << endl;
        cout << "Moi nhap lua chon: ";
        cin >> luachon;
        switch(luachon) {
            case 1:
                initQueue(q);
                break; 
            case 2:
                if(isEmpty(q)) cout << "Queue rong";
                else cout << "Queue khong rong";
                break; 
            case 3:
                cout << "Nhap phan tu muon dua vao Queue: ";
                cin >> k;
                enQueue(q, k);
                break; 
            case 4:
                cout << "Phan tu vua duoc lay ra khoi Queue la: " << deQueue(q);
                break;
            case 5:
                cout << "Phan tu REAR cua Queue la: " << rear(q) << endl;
                cout << "Phan tu FRONT cua Queue la: " << front(q);
                break;
            default:
                break;
        }
        cout << endl;
        fflush(stdin);
    }while(luachon !=0);
    return 0;
}