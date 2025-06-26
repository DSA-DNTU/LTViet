#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    int height;

    Node(int val) {
        data = val;
        left = right = nullptr;
        height = 1;
    }
};

// Tính chiều cao của node
int getHeight(Node* node) {
    return node ? node->height : 0;
}

// Cập nhật chiều cao sau khi thêm hoặc xoay
void updateHeight(Node* node) {
    node->height = 1 + max(getHeight(node->left), getHeight(node->right));
}

// Tính hệ số cân bằng của một node
int getBalance(Node* node) {
    return node ? getHeight(node->left) - getHeight(node->right) : 0;
}

// Xoay phải - xử lý trường hợp Left-Left
Node* rotateRight(Node* y) {
    Node* x = y->left;
    Node* T2 = x->right;

    // Thực hiện xoay
    x->right = y;
    y->left = T2;

    // Cập nhật lại chiều cao
    updateHeight(y);
    updateHeight(x);

    return x;
}

// Hàm chèn phần tử vào cây AVL có cân bằng
Node* insert(Node* root, int key) {
    if (!root) return new Node(key);

    if (key < root->data)
        root->left = insert(root->left, key);
    else if (key > root->data)
        root->right = insert(root->right, key);
    else
        return root; // Không chèn trùng

    updateHeight(root);
    int balance = getBalance(root);

    // Trường hợp Left-Left: xoay phải
    if (balance > 1 && key < root->left->data)
        return rotateRight(root);

    return root;
}

// Duyệt cây theo thứ tự trước (Node -> Left -> Right)
void preorder(Node* root) {
    if (!root) return;
    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}

int main() {
    Node* root = nullptr;

    // Chèn lần lượt 30, 20, 10 gây mất cân bằng LL
    root = insert(root, 30);
    root = insert(root, 20);
    root = insert(root, 10); // Mất cân bằng tại node 30

    cout << "Cay AVL sau khi xoay phai tai nut 30:\n";
    preorder(root);  // Ket qua: 20 10 30

    return 0;
}
// Output: Cay ACay AVL sau khi xoay phai tai nut 30: 20 10 30