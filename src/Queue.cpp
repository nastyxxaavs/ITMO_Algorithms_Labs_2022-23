#include <iostream>
struct Node{
    int data;
    Node *next;
    Node(int value)
    {
        data = value;
        next = NULL;
    }
};

struct Queue{
    Node *head = NULL, *tail = NULL;
};

void INIT(Queue *Q){
    (*Q).head = 0;
    (*Q).tail = 0;
}


void Enqueue(Queue *Q, int value){
    Node *new_node = new Node(value);
    if (((*Q).tail == NULL) && ((*Q).head == NULL)){
        (*Q).head = (*Q).tail = new_node;
        return;
    }
    (*(*Q).tail).next = new_node;
    (*Q).tail = new_node;
}


void Dequeue(Queue *Q){
    if ((*Q).head == NULL)
        return;
    Node *deleted = (*Q).head;
    std::cout << (*(*Q).head).data <<"\n";
    (*Q).head = (*(*Q).head).next;
    if ((*Q).head == NULL) {
        (*Q).tail = NULL;
    }
    delete (deleted);
}


int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    struct Queue Que;
    int n, add;
    char flag;
    std::cin >> n;
    for (int i = 0; i<n; i++){
        std::cin >> flag;
        if (flag == '+'){
           std::cin >> add;
            Enqueue(&Que, add);
        }
        else if (flag == '-'){
            Dequeue(&Que);
        }
    }
    return 0;
}

