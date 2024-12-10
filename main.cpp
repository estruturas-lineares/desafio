#include <iostream>
using namespace std;
#define TAM 401
//testando com 200 items tam = 401

int sequence_to_1 (int number, int quant){
    if (number == 1){
        quant++;
        return quant;
    };
    if (number % 2 == 0){
        cout << number << " ";
        return sequence_to_1(number / 2, quant++);
    }else{
        cout << number << " ";
        return sequence_to_1((3*number) + 1, quant++);
    }

};


//lista
class Node{
public:
    int data;
    Node* next;
    Node(int d):data(d){}
};

class LinkedList{
public:
    Node* head;
    int tam;
};

void initializaLinkedList(LinkedList* l){
    l->head = NULL;
    l->tam = 0;
};

void insertLinkedList(LinkedList* list, int data){
    Node* newNode = new Node(data);

    newNode->next = list->head;
    list->head = newNode;
    list->tam++;

};

int searchLinkedList(LinkedList* list, int value){
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

int func_hash(int value){
    return value % TAM;
};

void insert_hash(LinkedList t[], int value){
    int id = func_hash(value);
    insertLinkedList(&t[id], value);

};

int search_hash(LinkedList t[], int value){
    int id = func_hash(value);
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

  int quant = 0;
  LinkedList table[TAM];
  initialize_hash(table);
  for (int i = 1; i < 200; i++){
      insert_hash(table, sequence_to_1(i, quant));
  };
  print_hash(table);

  return 0;
}