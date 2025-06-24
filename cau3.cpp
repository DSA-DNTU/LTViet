#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

// Hàm tạo node mới
Node* createNode(int data) {
    Node* newNode = new Node;
    newNode->data = data;
    newNode->next = nullptr;
    return newNode;
}

// Hàm thêm node vào cuối danh sách
Node* them(Node* head, int data) {
    Node* newNode = createNode(data);

    // Trường hợp danh sách rỗng
    if (head == nullptr) {
        return newNode;
    }

    // Duyệt đến cuối danh sách
    Node* temp = head;
    while (temp->next != nullptr) {
        temp = temp->next;
    }

    // Gắn node mới vào cuối
    temp->next = newNode;

    return head;
}

// Hàm in danh sách
void in(Node* head) {
    Node* temp = head;
    while (temp != nullptr) {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "null\n";
}

int main() {
    Node* head = nullptr;  // Danh sách rỗng ban đầu

    head = them(head, 1);  
    head = them(head, 2);  
    head = them(head, 3);

    in(head);  

    return 0;
}
