#include <iostream>
using namespace std;

// Khai báo Node
struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};

// Hàm chèn node vào BST
Node* insert(Node* root, int val) {
    if (root == nullptr) return new Node(val);

    if (val < root->data) // đẩy số bé hơn sang bên trái
        root->left = insert(root->left, val);
    else if (val > root->data) // đẩy số lớn hơn sang bên phải
        root->right = insert(root->right, val);

    return root; // Trả về con trỏ gốc của cây nếu không có thay đổi nào (không chèn trùng lặp)
}

// Hàm tìm kiếm trong BST
bool searchBST(Node* root, int key) {
    if (root == nullptr) return false;
    if (root->data == key) return true;

    if (key < root->data)
        return searchBST(root->left, key); // Nếu key nhỏ hơn giá trị của nút hiện tại, tìm kiếm bên trái
    else
        return searchBST(root->right, key); // Nếu key lớn hơn giá trị của nút hiện tại, tìm kiếm bên phải
}

int main() {
    // Dữ liệu cây: 10, 5, 15, 2, 7, 20
    Node* root = nullptr;
    int values[] = {10, 5, 15, 2, 7, 20};

    for (int val : values)
        root = insert(root, val);

    // Tìm kiếm
    int key1 = 7;
    int key2 = 12;

    cout << "Tim " << key1 << ": " << (searchBST(root, key1) ? "Found" : "Not Found") << endl;
    cout << "Tim " << key2 << ": " << (searchBST(root, key2) ? "Found" : "Not Found") << endl;

    return 0;
}
// output:  Tim 7: Found
//          Tim 12: Not Found