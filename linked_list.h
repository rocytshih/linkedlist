#ifndef LINKED_LIST_H
#define LINKED_LIST_H
#include  <iostream>
using namespace std;
enum boolean {FALSE, TRUE};

template <class Type> class Node;  
template <class Type> class List;           /*���O�˪O*/
// template <class Type> class List_Interator; /*���O�˪O*/

template <class Type> 
class Node{           /*���O�˪O*/
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
class List{             /*�ŧiList���O*/
    // friend class List_Interator <Type>;
    public:
        void insert(int num_node, Type k);
        void creatlinkedlist(int size);
        void attach(Type k);
        void invert();
        void concatenate(List<Type> b); /*list��list*/
        void printlist();
        List();
        ~List();                        /*�ѫغc�l:�e�����ݭn�[����^�Ǩ�ƫ��A*/
    private:
        Node<Type>* first;              /*��List��first address*/
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
