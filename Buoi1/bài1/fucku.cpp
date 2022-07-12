#include<set>
#include<iostream>
using namespace std;
int main()
{
    set<int> MySet;
    MySet.insert(7);
    MySet.insert(1);
    MySet.insert(5);
    MySet.insert(3);
    for(auto it = MySet.begin(); it != MySet.end(); ++it)
        cout << *it << ' ';
    return 0;
}