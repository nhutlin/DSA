#include <iostream>

using namespace std;

struct HASH {
    int key;
    int data[100];

    int size;
};

void initHT(HASH h[]) {
    for(int i = 0; i < 7; i++) {
        h[i].size = 0;
        h[i].key = i;
        for(int j = 0; j < 100; j++) {
            h[i].data[j] = -1;
        }
    }
}

int hashFunction(int data) {
    return data % 7;
}

void insert_hash(HASH h[], int data) {
    int key = hashFunction(data);

    int bucket_size = h[key].size;

    h[key].data[bucket_size] = data;
    h[key].size = bucket_size + 1;
}

void showHash(HASH h[]) {
    for(int i = 0; i < 7; i++) {
        cout << "Key " << h[i].key << ": ";
        for (int j = 0; j < h[i].size; j++)
            cout << h[i].data[j] << " ";
        cout << endl;
    }

}

int searchX(HASH h[], int x)
{
    for(int i = 0; i < 7; i++) {
        for(int j = 0; j < h[i].size; j++) {
            if(h[i].data[j] == x) return x;
        }
    }
    return -1;
}

int main()
{
   HASH hashtable[7];
   initHT(hashtable);
   int N, d;
   cout << "Nhap so phan tu: ";
   cin >> N;
   for (int i = 0; i< N; i++) {
        cin >> d;
        insert_hash(hashtable, d);
   }

   showHash(hashtable);
   cout << endl;
   int x;
   cout << "Nhap x can tim: ";
   cin >> x;
   if(searchX(hashtable, x) == -1) cout << "Khong tim duoc x";
   else cout << searchX(hashtable, x);
   return 0;
}
