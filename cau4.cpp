#include <iostream>
#include <fstream>
using namespace std;

struct node {
    int data; // dữ liệu của nút
    node* next; // con trỏ đến nút tiếp theo
};
node* CreateNode(int data) {
    node* NewNode = new node;
    NewNode->data = data;
    NewNode->next = nullptr;
    return NewNode;
}
node* insertnode(node* head, int pos, int data) {
    node* p = head;
    int idx = 1; // Bắt đầu từ vị trí 1
    // Duyệt đến node thứ pos
    while (p != nullptr && idx < pos) {
        p = p->next;
        idx++;
    }
    if (p == nullptr) return head; // Nếu pos lớn hơn số node

    node* NewNode = CreateNode(data);
    NewNode->next = p->next;
    p->next = NewNode;
    return head;
}
node* listnode(node* head, int data) {
    node* NewNode = CreateNode(data);
    // Trường hợp danh sách rỗng
    if (head == nullptr) {
        return NewNode;
    }
    node* temp = head;
    // Duyệt đến cuối danh sách
    while (temp->next != nullptr) {
        temp = temp->next;
    }
    // Nối nút mới vào cuối danh sách
    temp->next = NewNode;
    return head;
}
void in(node* head) {
    node* temp = head;
    while (temp != nullptr) {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "null\n";
}
/* 3 2                                      vị trí và dữ liệu của nút mới 
1 2 3 4 5 6 7                               node có sẵn   */
int main() {    
    fstream input("cau4.inp"); 
    node* head = nullptr; // con trỏ đầu của danh sách liên kết
    int n,m,k; 
    input >> m >> k; // đọc vị trí và dữ liệu của nút mới
    while (input >> n) { 
        head=listnode(head, n); // thêm nút mới vào cuối danh sách
    }
    head=insertnode(head, m, k); 
    in(head); 
    return 0;
}
//output: 1 -> 2 -> 3 -> 2 -> 4 -> 5 -> 6 -> 7 -> null