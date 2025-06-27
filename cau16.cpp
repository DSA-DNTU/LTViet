#include <iostream>
using namespace std;

// Định nghĩa màu sắc node: đỏ hoặc đen
enum Color { RED, BLACK };

// Cấu trúc node trong cây đỏ-đen
struct Node {
    int data;           // Giá trị của node
    bool color;         // Màu sắc: RED hoặc BLACK
    Node *left, *right, *parent; // Con trái, phải, cha

    Node(int data) : data(data), color(RED), left(nullptr), right(nullptr), parent(nullptr) {} // Khởi tạo node mặc định là đỏ
};

class RedBlackTree {
private:
    Node* root; // Gốc của cây

    // Hàm xoay trái tại node pt
    void rotateLeft(Node*& root, Node*& pt) {
        Node* pt_right = pt->right; // Lưu node con phải

        pt->right = pt_right->left; // Đưa con trái của pt_right thành con phải của pt
        if (pt->right != nullptr)
            pt->right->parent = pt;

        pt_right->parent = pt->parent; // Cập nhật cha cho pt_right

        if (pt->parent == nullptr)
            root = pt_right; // Nếu pt là gốc, cập nhật lại gốc
        else if (pt == pt->parent->left)
            pt->parent->left = pt_right;
        else
            pt->parent->right = pt_right;

        pt_right->left = pt; // Đưa pt thành con trái của pt_right
        pt->parent = pt_right;
    }

    // Hàm xoay phải tại node pt
    void rotateRight(Node*& root, Node*& pt) {
        Node* pt_left = pt->left; // Lưu node con trái

        pt->left = pt_left->right; // Đưa con phải của pt_left thành con trái của pt
        if (pt->left != nullptr)
            pt->left->parent = pt;

        pt_left->parent = pt->parent; // Cập nhật cha cho pt_left

        if (pt->parent == nullptr)
            root = pt_left; // Nếu pt là gốc, cập nhật lại gốc
        else if (pt == pt->parent->left)
            pt->parent->left = pt_left;
        else
            pt->parent->right = pt_left;

        pt_left->right = pt; // Đưa pt thành con phải của pt_left
        pt->parent = pt_left;
    }

    // Hàm cân bằng cây sau khi chèn node vi phạm quy tắc đỏ-đen
    void fixViolation(Node*& root, Node*& pt);

    // Hàm cân bằng lại sau khi xóa node
    void fixDelete(Node*& x) {
        // Lặp cho đến khi x là gốc hoặc x là node đen
        while (x != root && (x == nullptr || x->color == BLACK)) {
            if (x == x->parent->left) {
                Node* w = x->parent->right; // w là anh/em của x
                if (w->color == RED) {
                    // Trường hợp 1: w là đỏ
                    w->color = BLACK;
                    x->parent->color = RED;
                    rotateLeft(root, x->parent);
                    w = x->parent->right;
                }
                // Trường hợp 2: w là đen và cả hai con của w đều đen
                if ((w->left == nullptr || w->left->color == BLACK) && (w->right == nullptr || w->right->color == BLACK)) {
                    w->color = RED;
                    x = x->parent;
                } else {
                    // Trường hợp 3: w là đen, w->right là đen, w->left là đỏ
                    if (w->right == nullptr || w->right->color == BLACK) {
                        if (w->left) w->left->color = BLACK;
                        w->color = RED;
                        rotateRight(root, w);
                        w = x->parent->right;
                    }
                    // Trường hợp 4: w là đen, w->right là đỏ
                    w->color = x->parent->color;
                    x->parent->color = BLACK;
                    if (w->right) w->right->color = BLACK;
                    rotateLeft(root, x->parent);
                    x = root;
                }
            } else {
                // Tương tự như trên nhưng đổi trái/phải
                Node* w = x->parent->left;
                if (w->color == RED) {
                    w->color = BLACK;
                    x->parent->color = RED;
                    rotateRight(root, x->parent);
                    w = x->parent->left;
                }
                if ((w->left == nullptr || w->left->color == BLACK) && (w->right == nullptr || w->right->color == BLACK)) {
                    w->color = RED; // Trường hợp 2: w là đen và cả hai con của w đều đen
                    x = x->parent;
                } else {
                    if (w->left == nullptr || w->left->color == BLACK) {
                        if (w->right) w->right->color = BLACK;
                        w->color = RED;
                        rotateLeft(root, w);
                        w = x->parent->left;
                    }
                    w->color = x->parent->color;
                    x->parent->color = BLACK;
                    if (w->left) w->left->color = BLACK;
                    rotateRight(root, x->parent);
                    x = root;
                }
            }
        }
        if (x) x->color = BLACK; // Đảm bảo gốc là đen
    }

    // Hàm thay thế node u bằng node v trong cây
    void transplant(Node* u, Node* v) {
        if (u->parent == nullptr)
            root = v;
        else if (u == u->parent->left)
            u->parent->left = v;
        else
            u->parent->right = v;
        if (v != nullptr)
            v->parent = u->parent;
    }

    // Tìm node có giá trị nhỏ nhất trong cây con
    Node* minValueNode(Node* node) {
        Node* current = node;
        while (current->left != nullptr)
            current = current->left;
        return current;
    }

    // Hàm xóa node với giá trị key
    void deleteNodeHelper(Node* node, int key) {
        Node* z = root;
        Node* x, *y;
        // Tìm node có giá trị key
        while (z != nullptr) {
            if (z->data == key)
                break;
            if (z->data < key)
                z = z->right;
            else
                z = z->left;
        }

        if (z == nullptr) return; // Không tìm thấy

        y = z;
        bool y_original_color = y->color;
        if (z->left == nullptr) {
            x = z->right;
            transplant(z, z->right);
        } else if (z->right == nullptr) {
            x = z->left;
            transplant(z, z->left);
        } else {
            y = minValueNode(z->right); // Node nhỏ nhất bên phải
            y_original_color = y->color;
            x = y->right;
            if (y->parent == z) {
                if (x) x->parent = y;
            } else {
                transplant(y, y->right);
                y->right = z->right;
                y->right->parent = y;
            }
            transplant(z, y);
            y->left = z->left;
            y->left->parent = y;
            y->color = z->color;
        }
        delete z;
        if (y_original_color == BLACK)
            fixDelete(x); // Cân bằng lại nếu cần
    }

    // Duyệt giữa cây và in ra
    void inorderHelper(Node* root) {
        if (root == nullptr) return;
        inorderHelper(root->left);
        cout << root->data << (root->color == RED ? "(R) " : "(B) ");
        inorderHelper(root->right);
    }

public:
    RedBlackTree() : root(nullptr) {}

    // Hàm chèn node
    void insert(const int &data);

    // Hàm xóa node
    void remove(int data) {
        deleteNodeHelper(root, data);
    }

    // Duyệt giữa và in cây
    void inorder() {
        inorderHelper(root);
        cout << endl;
    }
};

// Hàm xử lý vi phạm sau khi chèn vào cây
void RedBlackTree::fixViolation(Node*& root, Node*& pt) {
    Node* parent_pt = nullptr;
    Node* grand_parent_pt = nullptr;

    // Lặp cho đến khi pt không phải là gốc và cha của pt là đỏ
    while ((pt != root) && (pt->color != BLACK) && (pt->parent->color == RED)) {
        parent_pt = pt->parent;
        grand_parent_pt = pt->parent->parent;

        // Nếu cha là con trái của ông
        if (parent_pt == grand_parent_pt->left) {
            Node* uncle_pt = grand_parent_pt->right;

            // Trường hợp 1: chú là đỏ
            if (uncle_pt != nullptr && uncle_pt->color == RED) {
                grand_parent_pt->color = RED;
                parent_pt->color = BLACK;
                uncle_pt->color = BLACK;
                pt = grand_parent_pt;
            } else {
                // Trường hợp 2: pt là con phải
                if (pt == parent_pt->right) {
                    rotateLeft(root, parent_pt);
                    pt = parent_pt;
                    parent_pt = pt->parent;
                }
                // Trường hợp 3: pt là con trái
                rotateRight(root, grand_parent_pt);
                swap(parent_pt->color, grand_parent_pt->color);
                pt = parent_pt;
            }
        } else {
            // Nếu cha là con phải của ông
            Node* uncle_pt = grand_parent_pt->left;

            if ((uncle_pt != nullptr) && (uncle_pt->color == RED)) {
                grand_parent_pt->color = RED;
                parent_pt->color = BLACK;
                uncle_pt->color = BLACK;
                pt = grand_parent_pt;
            } else {
                if (pt == parent_pt->left) {
                    rotateRight(root, parent_pt);
                    pt = parent_pt;
                    parent_pt = pt->parent;
                }
                rotateLeft(root, grand_parent_pt);
                swap(parent_pt->color, grand_parent_pt->color);
                pt = parent_pt;
            }
        }
    }
    root->color = BLACK; // Đảm bảo gốc là đen
}

// Hàm chèn node vào cây
void RedBlackTree::insert(const int &data) {
    Node* pt = new Node(data); // Tạo node mới

    Node* y = nullptr;
    Node* x = root;

    // Tìm vị trí thích hợp để chèn node mới
    while (x != nullptr) {
        y = x;
        if (pt->data < x->data)
            x = x->left;
        else
            x = x->right;
    }

    pt->parent = y;

    if (y == nullptr)
        root = pt; // Nếu cây rỗng, node mới là gốc
    else if (pt->data < y->data)
        y->left = pt;
    else
        y->right = pt;

    pt->left = pt->right = nullptr;
    pt->color = RED; // Node mới luôn là đỏ

    fixViolation(root, pt); // Cân bằng lại cây nếu cần
}

int main() {
    RedBlackTree tree;

    // Chèn các node vào cây
    tree.insert(10);
    tree.insert(20);
    tree.insert(30);
    tree.insert(15);
    tree.insert(25);
    tree.insert(5);
    cout << "Cay sau khi chen: ";
    tree.inorder();

    // Xóa node có giá trị 20
    tree.remove(20);
    cout << "Cay sau khi xoa 20: ";
    tree.inorder();

    return 0;
}
// output: 
// Cay sau khi chen: 5(R) 10(B) 15(R) 20(B) 25(R) 30(B)
// Cay sau khi xoa 20: 5(R) 10(B) 15(R) 25(B) 30(B)