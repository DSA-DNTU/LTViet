#include <iostream>
#include <fstream>
using namespace std;
struct node {
    int data;
    node* next;
};

// Hàm đọc danh sách liên kết từ file
node* readListFromFile(const char* filename) {
    ifstream fin(filename);
    if (!fin) return nullptr;
    int Head, x;
    fin >> Head; // Đọc giá trị đầu tiên để xác định head chỉ định
    if (!(fin >> x)) return nullptr; // Không có phần tử nào
    node* head = new node{x, nullptr};
    node* tail = head;
    node* point = nullptr;
    int i = 1;
    if (i == Head) point = head;
    while (fin >> x) {
        node* tmp = new node{x, nullptr};
        tail->next = tmp;
        tail = tmp;
        i++;
        if (i == Head) point = tmp;
    }
    tail->next = head; // Tạo vòng liên kết
    fin.close();
    return point;
}
/*4                vị trí head chỉ định
2 3 4 5 6 7 8 9    danh sách liên kêt*/
int main () {
    node* head = readListFromFile("cau5.inp");
    if (!head) {
        cout << "Danh sach rong hoac loi file!" << endl;
        return 0;
    }
    // In toàn bộ danh sách liên kết vòng
    node* cur = head;
    do {
        cout << cur->data << " ";
        cur = cur->next;
    } while (cur != head);
    cout << endl;
    return 0;
}
// output 5 6 7 8 9 2 3 4