#ifndef LINKED_LIST_H
#define LINKED_LIST_H
#include  <iostream>
using namespace std;
enum boolean {FALSE, TRUE};

template <class Type> class Node;  
template <class Type> class List;           /*類別樣板*/
// template <class Type> class List_Interator; /*類別樣板*/

template <class Type> 
class Node{           /*類別樣板*/
    friend class List<Type>;
    // friend class List_Interator<Type>;
    public:
        Node<Type>(Type k){
            data = k;
            link = NULL;
        };
    private:
        Type data;
        Node<Type>* link;
};

template <class Type> 
class List{             /*宣告List類別*/
    // friend class List_Interator <Type>;
    public:
        void insert(int num_node, Type k);
        void creatlinkedlist(int size);
        void attach(Type k);
        void invert();
        void concatenate(List<Type> b); /*list接list*/
        void printlist();
        List();
        ~List();                        /*解建構子:前面不需要加任何回傳函數型態*/
    private:
        Node<Type>* first;              /*此List的first address*/
        Node<Type>* last;
        Node<Type>* current;
        int size;
};

// template <class Type> 
// class List_Interator{
//     public:
//     private:
// };



#endif
