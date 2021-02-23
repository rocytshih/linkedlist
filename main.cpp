#include <iostream>
#include "linked_list.h"
#include "linked_list.cpp"
using namespace std;


int main() {
    List<int>A;
    int size;
    cout<<"Initial linkedlist size :";
    cin>>size;
    A.creatlinkedlist(size);
    A.printlist();
    A.insert(2,66);
    A.printlist();
    system("pause");
    return 0;
}