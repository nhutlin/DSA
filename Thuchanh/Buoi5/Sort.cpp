#include <iostream>
#include <time.h>
#include <stdlib.h>
#include <random>
#include <iomanip>
using namespace std;

void createArray(double *&a, int &n) {
    a = new double[n];
    srand (static_cast <double> (time(0)));
    for(int i = 0; i < n; i++) {
        a[i] = static_cast <double> (rand()) / (static_cast <double> (RAND_MAX / 100000.0));
    }
}

void selectionSortUp(double *a, int n) 
{
    int min;
    for (int i = 0; i < n - 1; i++) {
        min = i;
        for (int j = i + 1; j < n; j++)
            if (a[j] < a[min])
                min = j;
        swap(a[min], a[i]);
    }
}

void selectionSortDown(double *a, int n)
{
    int max;
    for(int i = 0; i < n - 1; i++) {
        max = i;
        for(int j = i + 1; j < n; j++)
            if(a[j] > a[max])
                max = j;
        swap(a[max], a[i]);
    }
}

double timeThucHienSeclectionSortDown(double *a, int n)
{
    double period;
    clock_t start, end;
    start = clock();
    selectionSortDown(a, n);
    end = clock();
    period = ((double)(end - start)) / CLOCKS_PER_SEC;
    return period;
}

double timeThucHienSeclectionSortUp(double *a, int n)
{
    double period;
    clock_t start, end;
    start = clock();
    selectionSortUp(a, n);
    end = clock();
    period = ((double)(end - start)) / CLOCKS_PER_SEC;
    return period;
}

void insertionSortUp(double *a, int n)
{
   int e, j;
   for (int i = 1; i < n; i++) {
       e = a[i];
       j = i - 1;
       while(j >= 0 && a[j] < e) {
           a[j + 1] = a[j];
           j = j - 1;
       }
       a[j + 1] = e;
   }
}

void insertionSortDown(double *a, int n)
{
    int e, j;
    for(int i = 1; i < n; i++) {
        e = a[i];
        j = i - 1;
        while(j >= 0 && a[j] > e) {
            a[j + 1] = a[j];
            j = j - 1;
        }
        a[j + 1] = e;
    }
}

double timeThucHienInsertionSortUp(double *a, int n)
{
    double period;
    clock_t start, end;
    start = clock();
    insertionSortUp(a, n);
    end = clock();
    period = ((double)(end - start)) / CLOCKS_PER_SEC;
    return period;
}

double timeThucHienInsertionSortDown(double *a, int n) 
{
    double period;
    clock_t start, end;
    start = clock();
    insertionSortDown(a, n);
    end = clock();
    period = ((double)(end - start)) / CLOCKS_PER_SEC;
    return period;
}

void printArray(double *a, int n)
{
    for(int i = 0; i < n; i++) {
        cout << fixed << setprecision(4) << a[i] << " ";
    }
}

bool isUp(double *a, int n)
{
    for(int i = 0; i < n - 1; i++) 
        if(a[i] > a[i + 1]) return 0;
    return 1;
}

bool isDown(double *a, int n) 
{
    for(int i = 0; i < n - 1; i++)
        if(a[i] < a[i + 1]) return 0;
    return 1;
}

int main() {
    double *a;
    int n = 100000;
    int option = 0;
    char luachon1, luachon2, luachon3, luachon4;
    do {
        cout << setfill('-');
        cout << setw(45) << right<< "MENU";
        cout << setw(45) << left << '-';
        cout << setfill('-');
        cout << endl;
        cout << setfill(' ');
        cout << "1. Tao mang" << endl;
        cout << "2. Xuat mang" << endl;
        cout << "3. Sap xep Selection Sort" << endl;
        cout << setw(25) << right << "A. Sap xep tang" << endl;
        cout << setw(25) << right << "B. Sap xep giam" << endl;
        cout << "4. Tinh thoi gian thuc hien Selection Sort" << endl;
        cout << setw(25) << right << "A. Time sap xep tang" << endl;
        cout << setw(25) << right << "B. Time sap xep giam" << endl;
        cout << "5. Sap xep Insertion Sort" << endl;
        cout << setw(25) << right << "A. Sap xep tang" << endl;
        cout << setw(25) << right << "B. Sap xep giam" << endl;
        cout << "6. Tinh thoi gian thuc hien Insertion Sort" << endl;
        cout << setw(25) << right << "A. Time sap xep tang" << endl;
        cout << setw(25) << right << "B. Time sap xep giam" << endl;
        cout << setfill('-');
        cout << setw(45) << right<< "END";
        cout << setw(45) << left << '-';
        cout << setfill('-');
        cout << endl;
        cout << setfill(' ');
        cout << setw(25) << right << "Xin moi nhap lua chon: ";
        cin >> option;
        switch(option) {
            case 1:
                createArray(a, n);
                break;
            case 2:
                printArray(a, n);
                break;
            case 3:
                cout << setw(25) << right << "A. Sap xep tang" << endl;
                cout << setw(25) << right << "B. Sap xep giam" << endl;
                cout << setw(25) << right << "Moi nhap lua chon: ";
                cin >> luachon1;
                if(luachon1 == 'a' || luachon1 == 'A') {
                    selectionSortUp(a, n);
                    cout << "Mang da sap xep: " << endl;
                    printArray(a, n);
                }
                else if(luachon1 == 'b' || luachon1 == 'B') {
                    selectionSortDown(a, n);
                    cout << "Mang da sap xep: " << endl;
                    printArray(a, n);
                }
                break;
            case 4:
                if(isUp(a, n) == 1 || isDown(a, n) == 1) {
                    cout << "Mang da sap xep. Vui long tao mang moi!" << endl;
                    break;
                }
                else {
                cout << setw(25) << right << "A. Time sap xep tang" << endl;
                cout << setw(25) << right << "B. Time sap xep giam" << endl;
                cout << setw(25) << right << "Moi nhap lua chon: ";
                cin >> luachon2;
                cout << "Thoi gian thuc hien: ";
                if(luachon2 == 'a' || luachon2 == 'A')
                    cout << fixed << setprecision(4) << timeThucHienSeclectionSortUp(a, n);
                else if(luachon2 == 'b' || luachon2 == 'B') 
                    cout << fixed << setprecision(4) << timeThucHienSeclectionSortDown(a, n);
                }
                break;
            case 5:
                cout << setw(25) << right << "A. Sap xep tang" << endl;
                cout << setw(25) << right << "B. Sap xep giam" << endl;
                cout << setw(25) << right << "Moi nhap lua chon: ";
                cin >> luachon3;
                if(luachon3 == 'a' || luachon3 == 'A') {
                    insertionSortUp(a, n);
                    cout << "Mang da sap xep: " << endl;
                    printArray(a, n);
                }
                else if(luachon3 == 'b' || luachon3 == 'B') {
                    insertionSortDown(a, n);
                    cout << "Mang da sap xep: " << endl;
                    printArray(a, n);
                }
                break;
            case 6:
                if(isUp(a, n) == 1 || isDown(a, n) == 1) {
                    cout << "Mang da sap xep. Vui long tao mang moi!" << endl;
                    break;
                }
                else {
                cout << setw(25) << right << "A. Time sap xep tang" << endl;
                cout << setw(25) << right << "B. Time sap xep giam" << endl;
                cout << setw(25) << right << "Moi nhap lua chon: ";
                cin >> luachon4;
                cout << "Thoi gian thuc hien: ";
                if(luachon4 == 'a' || luachon4 == 'A')
                    cout << fixed << setprecision(4) << timeThucHienInsertionSortUp(a, n);
                else if(luachon4 == 'b' || luachon4 == 'B') 
                    cout << fixed << setprecision(4) << timeThucHienInsertionSortDown(a, n);
                }
                break;
            default:
                break;
        }
    cout << endl;
    fflush(stdin);
    }while(option != 0);
    return 0;
}
