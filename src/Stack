#include <iostream>//стек на односвязном списке
struct Node{
    int data;
    Node *next;
    Node(int value)
    {
        data = value;
        next = NULL;
    }
};

struct Stack{
    Node *head = NULL;
};

void Push(Stack *Q, int value){
    Node *new_node = new Node(value);
    new_node->data = value;
    new_node->next = (*Q).head;
    (*Q).head = new_node;
}

void Pop(Stack *Q){
    Node *deleted = (*Q).head;
    if(deleted == NULL){
        exit(-1);
    }
    std::cout << deleted->data << "\n";
    ((*Q).head) = deleted->next;
    free(deleted);
}

int main() {
    std::cin.tie(nullptr);
    struct Stack my_stack;
    int n, add;
    char flag;
    std::cin >> n;
    for (int i = 0; i < n; i++) {
        std::cin >> flag;
        if (flag == '+') {
            std::cin >> add;
            Push(&my_stack, add);
        } else if (flag == '-') {
            Pop(&my_stack);
        }
    }
    return 0;
}
