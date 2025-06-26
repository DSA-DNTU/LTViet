#include <iostream>
using namespace std;
struct node { // Định nghĩa cấu trúc nút của cây nhị phân
    char data;
    node* left;
    node* right;

    node (char val) { // Hàm khởi tạo nút
        data = val;
        left = nullptr;
        right = nullptr;
    }
};
void preOrder(node* root) {
    if (root == nullptr) return; // Kiểm tra nếu nút hiện tại là nullptr ( nút rỗng là nút lá)
    cout << root->data << " ";
    preOrder(root->left); // Gọi đệ quy cho nút con bên trái
    preOrder(root->right); // Gọi đệ quy cho nút con bên phải
}
int main () {
    // Tạo một cây nhị phân mẫu
    node* root = new node('F');
    root->left = new node('B');
    root->right = new node('G');
    root->left->left = new node('A');
    root->left->right = new node('D');
    root->right->right = new node('I');
    root->left->right->left = new node('C');
    root->left->right->right = new node('E');

    preOrder(root); // Gọi hàm duyệt trước (pre-order traversal)
    cout << endl;

    // Giải phóng bộ nhớ (nếu cần)
    // delete root->left->left;
    // delete root->left->right;
    // delete root->right->left;
    // delete root->right->right;
    // delete root->left;
    // delete root->right;
    // delete root;

    return 0;
}