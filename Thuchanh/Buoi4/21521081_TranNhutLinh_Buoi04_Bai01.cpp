// Tên: Trần Nhựt Linh
// Buổi 04 - Bài 01
#include <iostream>
#include <time.h>
#include <stdlib.h>
using namespace std;
struct NODE {
    int value;
    NODE* pLeft;
    NODE* pRight;
};

struct Tree {
    NODE* root;
};

NODE* createNode(int value)
{
    NODE* p = new NODE;
    if(p == NULL) 
        return NULL;
    p->pLeft = NULL;
    p->pRight = NULL;
    p->value = value;
    return p;
}

void initTree(Tree &t)
{
    t.root = NULL;
}

void insertNode(NODE* &root, int data)
{
    if(root != NULL) {
        if(root->value == data)
            return;
        if(root->value > data) {
            insertNode(root->pLeft, data);
        }
        else {
            insertNode(root->pRight, data);
        }
    }
    else {
        root = createNode(data);

    }
}

void DuyetCayLNR(NODE* root) 
{
    if(root != NULL) {
        DuyetCayLNR(root->pLeft);
        cout << root->value << '\t' << &(root->value) << '\t';
        cout << "pLeft: " << &(root->pLeft->value) << '\t' << '\t';
        cout << "pRight: " << &(root->pRight->value) << endl;
        DuyetCayLNR(root->pRight);
    }
}

void DuyetCayLRN(NODE* root) 
{
    if(root != NULL) {
        DuyetCayLRN(root->pLeft);
        DuyetCayLRN(root->pRight);
        cout << root->value << '\t' << &(root->value) << '\t';
        cout << "pLeft: " << &(root->pLeft->value) << '\t' << '\t';
        cout << "pRight: " << &(root->pRight->value) << endl;
    }
}

void DuyetCayNLR(NODE* root) 
{
    if(root != NULL) {
        cout << root->value << '\t' << &(root->value) << '\t';
        cout << "pLeft: " << &(root->pLeft->value) << '\t' << '\t';
        cout << "pRight: " << &(root->pRight->value) << endl;
        DuyetCayNLR(root->pLeft);
        DuyetCayNLR(root->pRight);
    }
}

void searchX(NODE* root, int x)
{
    NODE* p = root;
    while(p != NULL) {
        if(x == p->value) {
            cout << "True";
            return;
        }
        else if(x < p->value) 
            p = p->pLeft;
        else p = p->pRight;
    }
    cout << "False" << endl;
    return;
}

int CountNode(NODE* root)
{
   if( root == NULL)
      return 0;
   else
      return 1 + CountNode(root->pLeft) + CountNode(root->pRight);
}

int sumOdd(NODE* root, int &sum)
{
    if(root != NULL) {
        if(root->value % 2 != 0) 
            sum += root->value;
        sumOdd(root->pLeft, sum);
        sumOdd(root->pRight, sum);
    }
    return sum;
}

int dem1 = 0;

int countNodeSmall(NODE* root, int x)
{
    if(root != NULL) {
        countNodeSmall(root->pLeft, x);
        if(root->value < x) 
            dem1++;
        countNodeSmall(root->pRight, x);
    }
    return dem1;
}

int dem2 = 0;

int countNodeLarge(NODE* root, int x)
{
    if(root != NULL) {
        countNodeLarge(root->pLeft, x);
        if(root->value > x) 
            dem2++;
        countNodeLarge(root->pRight, x);
    }
    return dem2;
}



int main() {
    Tree t;
    initTree(t);
    int option = 0, luachon = 0, soluong = 0, val = 0;
    int n, k, x, X;
    srand(time(NULL));
    x = rand() % (800 - 300 + 1) + 300;
    do {
        cout << "1. Chen node vao cay" << endl;
        cout << "2. Nhap gia tri vao cay (Nhap 0 de dung)" << endl;
        cout << "3. Nhap gia tri tu dong vao cay" << endl;
        cout << "4. Duyet cay" << endl;
        cout << "5. Tim kiem gia tri x trong cay" << endl;
        cout << "6. Xoa gia tri x trong cay" << endl;
        cout << "7. Dem toan bo node cua cay" << endl;
        cout << "8. Dem so node co gia tri nho hon x trong cay" << endl;
        cout << "9. Dem so node co gia tri lon hon x trong cay" << endl;
        cout << "10. Tinh tong node le trong cay" << endl;
        cout << "0. Thoat" << endl;
        cout << "Moi nhap lua chon: ";
        cin >> option;
        switch(option) {
            case 1:
                cout << "Nhap node can chen: ";
                cin >> k;
                insertNode(t.root, k);
                break;
            case 2:
                do {
                    cout << "Moi nhap gia tri can them: ";
                    cin >> n;
                    if(n == 0) break;
                    insertNode(t.root, n);
                }while(n != 0);
                break;
            case 3:
                initTree(t);
                srand(time(NULL));
                soluong = rand () % (20 - 10 + 1) + 10;
                for(int i = 0; i < soluong; i++) {
                    val = rand () % (1358 + 358 + 1) - 358; 
                    insertNode(t.root, val);
                }
                cout << soluong << endl;
                break;
            case 4:
                cout << "1. LNR" << endl;
                cout << "2. LRN" << endl;
                cout << "3. NLR" << endl;
                cout << "Moi nhap lua chon: ";
                cin >> luachon;
                if(luachon == 1) 
                    DuyetCayLNR(t.root);
                else if(luachon == 2) 
                    DuyetCayLRN(t.root);
                else if(luachon == 3) 
                    DuyetCayNLR(t.root);
                break;
            case 5:
                cout << "x = " << x << endl;
                searchX(t.root, x);
                break;
            case 6:
                cout << "Moi nhap gia tri x co trong cay: ";
                cin >> X;
                //deleteX(t, X);
                break;
            case 7:
                cout << "So node trong cay: ";
                cout << CountNode(t.root) << endl;
                break;
            case 8:
                cout << "x = " << x << endl;
                cout << "So node nho hon x: " << countNodeSmall(t.root, x) << endl;
                break;
            case 9:
                cout << "x = " << x << endl;
                cout << "So node lon hon x: " << countNodeLarge(t.root, x) << endl;
                break;
            case 10:
                cout << "Tong cac node le: " << sumOdd(t.root) << endl;
                break;
            default: 
                break;
        }
        cout << endl;
        fflush(stdin);
    }while(option != 0);
    return 0;
}