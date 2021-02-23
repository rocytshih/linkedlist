#include  "linked_list.h"

/*將一個node加到list的最後*/
template <class Type>
void List<Type>::attach(Type k){
    Node<Type> *newnode = new Node<Type>(k);
    if(first == 0){
        first = last = newnode; /*一開始都沒東西的時候*/
    }
    else{
        last->link = newnode;
        last = newnode;
    }
}

template <class Type>
void List<Type>::invert(){
    /*q跟著p走, r再跟著q走*/
    Node<Type>* p = first, *q = 0; //q trials p
    while(p){/*當p=0時, 表示到list的底端了*/
        Node<Type>* r = q; //r trails q
        q = p;
        p = p->link;
        q->link = r;
    }
    first = q;/*當p的link等於0時, q所指向的是這個list的最後一個node(也就是p的地址)*/
}

template <class Type>
void List<Type>::concatenate(List<Type> b){
    if(!first){ /*原本的list是空的情況下*/
        first = b.first;
        return;
    }
    if(b.first){
        Node<Type> *p;
        for(p = first; p->link; p = p->link);
        p->link = b.first;
    }
}

template <class Type>
List<Type>::~List(){
    Node<Type>* next;
    for(;first;first = next){
        next = first->link;
        delete first;
    }
}

template <class Type>
List<Type>::List(){
    Node<Type>* node = new Node<Type>(0);
    node->link = NULL;
}

template <class Type>
void List<Type>::creatlinkedlist(int size){
    if(size < 0){
        cout<< "size error!"<<endl;
        return;
    }
    // first = new Node<Type>(0);
    // first->link = NULL;             /*第一個node的link指標給null*/
    // cout<<"Input node 1's data: ";
    // cin >> first->data;
    Type key_in;
    first = NULL;
    for(int i = 0; i<size; i++){
        cout<<"Input node"<<i+1<<"'s data: ";
        cin >> key_in;
        insert(i+1, key_in);
    }
    cout<<endl;
    cout<<"create size"<<size<<"linkedlist completed!"<<endl;
    cout<<endl;
}

template <class Type>
void List<Type>::insert(int num_node, Type k){
    current = first;                            /*將current node設置成list的第一個node*/
    if(!first){
        Node<Type>* t = new Node<Type>(k);
        first = t;
        return;
    }
    Node<Type>* insert = new Node<Type>(k);
    for(int i = 0; i <num_node-1; i++){
        if(current->link == 0){                 /*遇到最後一個node*/
            break;
        }
        current = current->link;                /*scan list到指定的node number*/
    }
    insert->link = current->link;
    current->link = insert;
}

template <class Type>
void List<Type>::printlist(){
    int i = 1;
    if(first == NULL){
        cout<<"The list is empty!"<<endl;
    }
    current = first;
    while(current){
        cout<<"Node-"<<i<<" address:"<<current<<endl;
        cout<<"Node-"<<i<<" data: "<<current->data<<endl;
        cout<<"Node-"<<i<<" link address: "<<current->link<<endl;
        cout<<endl;
        if(current->link == NULL){
            break;
        }
        current = current->link;
        i++;
    }
}