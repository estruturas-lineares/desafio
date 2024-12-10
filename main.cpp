#include <iostream>
using namespace std;
#define TAM 401
//testando com 200 items tam = 401

long long int sequence_to_1 (long long int number, long quant){
    if (number == 1){
        return quant;
    };
    if (number % 2 == 0){
        return sequence_to_1(number / 2, quant+ 1);
    }else{
        return sequence_to_1((3*number) + 1, quant+ 1);
    }

};


//lista
class Node{
public:
    long long int data;
    Node* next;
    Node(long long int d):data(d){}
};

class LinkedList{
public:
    Node* head;
    long long int tam;
};

void initializaLinkedList(LinkedList* l){
    l->head = NULL;
    l->tam = 0;
};

void insertLinkedList(LinkedList* list, long long int data){
    Node* newNode = new Node(data);

    newNode->next = list->head;
    list->head = newNode;
    list->tam++;

};

int searchLinkedList(LinkedList* list, long long int value){
    Node* temp = list->head;

    while(temp && temp->data != value ){
        temp = temp->next;
        if (temp) {
            return temp->data;
        }
    }
    return 0;

};

int printLinkedList(LinkedList* list){
    Node* temp = list->head;
    while(temp){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
};

void initialize_hash(LinkedList t[]){
    for (int i = 0; i < TAM; i++){
        initializaLinkedList(&t[i]);
    }
};

int func_hash(long long int value){
    return value % TAM;
};

void insert_hash(LinkedList t[], long long int value){
    long long int id = func_hash(value);
    insertLinkedList(&t[id], value);

};

int search_hash(LinkedList t[], long long int value){
    long long int id = func_hash(value);
    return searchLinkedList(&t[id], value);
};

void print_hash(LinkedList t[]) {
    for ( int i = 0; i < TAM; i++){
        cout << i << "=";
        printLinkedList(&t[i]);
        cout << endl;
    };
};


int main() {

  long long int quant = 0;
  LinkedList table[TAM];
  initialize_hash(table);
  for (int i = 1; i < 200; i++){
      insert_hash(table, sequence_to_1(i, quant));
  };
  print_hash(table);


  return 0;
}