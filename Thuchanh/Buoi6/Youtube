#include <iostream>
using namespace std;
#define MAX 255
#include <string>
struct Node {
    string ten;
    long subscribe;
    int videos;
    Node* pnext;
};

struct Youtube {
    Node* pHead;
    Node* pTail;
};

void initYoutube(Youtube &y)
{
    y.pHead = NULL;
    y.pTail = NULL;
}
Node* createNode(string ten, long subscribe, int videos)
{
    Node* p = new Node;
    if(p == NULL) return NULL;
    p->subscribe = subscribe;
    p->ten = ten;
    p->videos = videos;
    p->pnext = NULL;
    return p;
}

void insertHead(Youtube &y, string ten, long subscribe, int videos)
{
    Node* p = createNode(ten,subscribe,videos);
    if(y.pHead == NULL) {
        y.pHead = p;
        y.pTail = p;
    }
    else {
        p->pnext = y.pHead;
        y.pHead = p;
    }
}

Node* deleteHead(Youtube &y) {
    Node* p = y.pHead;
    Node* q;
    q = p;
    y.pHead = p->pnext;
    p->pnext = NULL;
    delete p;
    return q;
}

void Xuat(Youtube y) 
{
    Node* head = y.pHead;
    while(head != NULL) {
        cout << head->ten << " - " << "Subscribe: " << head->subscribe << " - " << head->videos << " video" << endl;
        head = head->pnext;
    }
}

int countTen(Youtube y)
{
    Node* head = y.pHead;
    int dem = 0;
    while(head != NULL) {
        dem++;
        head = head->pnext;
    }
    return dem;
}

Node* mostSub(Youtube y) 
{
    Node* head;
    Node* max;
    max->subscribe = y.pHead->subscribe;
    head = y.pHead;
    while(head != NULL) {
        if(head->subscribe > max->subscribe) {
            max->subscribe = head->subscribe;
        }
        head = head->pnext;
    }
    return max;
}

int main() {
    Youtube y;
    long sub;
    string name;
    int vid;
    initYoutube(y);
    int luachon = 0;
    Node* head = mostSub(y);

    do {
        cout << "1. Subscribe kenh moi" << endl;
        cout << "2. Hien thi thong tin cac kenh da dang ky" << endl;
        cout << "3. Hien thi thong tin kenh co so luot dang ky nhieu nhat" << endl;
        cout << "4. Hien thi tong so kenh da dang ky" << endl;
        cout << "5. Unsubscribe mot kenh" << endl;
        cout << "0. Thoat" << endl;
        cout << "Moi nhap lua chon: ";
        cin >> luachon;
        switch (luachon)
        {
        case 1:
            cout << "Moi nhap ten kenh: ";
            cin >> name;
            cout << "Moi nhap so luong subscribe: ";
            cin >> sub;
            cout << "Moi nhap so luong video: ";
            cin >> vid;
            sub = sub + 1;
            insertHead(y, name, sub, vid);
            break;
        case 2: 
            Xuat(y);
            break;
        case 3:
            cout << head->ten << " - " << "Subscribe: " << head->subscribe << " - " << head->videos << " video" << endl;
            break;
        case 4: 
            cout << "Tong kenh dang ki la: ";
            cout << countTen(y);
            break;
        case 5:
            deleteHead(y);
            cout << "Da huy mot kenh" << endl;
            break;
        default:
            break;
        }
        cout << endl;
        fflush(stdin);
    }while(luachon != 0);
    return 0;
}
