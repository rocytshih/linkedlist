#include  "linked_list.h"

/*�N�@��node�[��list���̫�*/
template <class Type>
void List<Type>::attach(Type k){
    Node<Type> *newnode = new Node<Type>(k);
    if(first == 0){
        first = last = newnode; /*�@�}�l���S�F�誺�ɭ�*/
    }
    else{
        last->link = newnode;
        last = newnode;
    }
}

template <class Type>
void List<Type>::invert(){
    /*q���p��, r�A���q��*/
    Node<Type>* p = first, *q = 0; //q trials p
    while(p){/*��p=0��, ��ܨ�list�����ݤF*/
        Node<Type>* r = q; //r trails q
        q = p;
        p = p->link;
        q->link = r;
    }
    first = q;/*��p��link����0��, q�ҫ��V���O�o��list���̫�@��node(�]�N�Op���a�})*/
}

template <class Type>
void List<Type>::concatenate(List<Type> b){
    if(!first){ /*�쥻��list�O�Ū����p�U*/
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
    // first->link = NULL;             /*�Ĥ@��node��link���е�null*/
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
    current = first;                            /*�Ncurrent node�]�m��list���Ĥ@��node*/
    if(!first){
        Node<Type>* t = new Node<Type>(k);
        first = t;
        return;
    }
    Node<Type>* insert = new Node<Type>(k);
    for(int i = 0; i <num_node-1; i++){
        if(current->link == 0){                 /*�J��̫�@��node*/
            break;
        }
        current = current->link;                /*scan list����w��node number*/
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