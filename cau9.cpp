#include <iostream>
#include <vector>
#include <fstream>
using namespace std;
class queue {
private:
    vector <int> arr;
public:
void enqueue (int item) {
    arr.push_back(item); // Thêm phần tử vào cuối vector
    }
int dequeue() {
    if (!isEmpty()) {
        int front = arr.front();
        arr.erase(arr.begin()); // Xóa phần tử đầu tiên
        return front;
    } else {
        cerr << "hang doi rong!" << endl;
        return -1; // Hoặc một giá trị khác để báo lỗi
    }
}
int peek() {
    return arr.empty() ? -1 : arr.front(); // Trả về phần tử đầu tiên nếu không rỗng, ngược lại trả về -1
}
bool isEmpty() { // Kiểm tra xem hàng đợi có rỗng hay không
   return arr.empty();
}
};
int main() {
    fstream input("cau9.inp");
    if (!input) {
        cerr << "Loi mo file!" << endl;
        return 1;
    } 
    int x; queue q;
    while (input >> x) { // Đọc từng số nguyên từ file
        q.enqueue(x);
    }
    input.close();
    cout << "Phan tu dau tien trong hang doi: " << q.peek() << endl;
    cout << "Xoa phan tu dau tien: " << q.dequeue() << endl;
    cout << "Phan tu dau tien sau khi xoa: " << q.peek() << endl;
    cout << "Kiem tra hang doi co rong khong: " << (q.isEmpty() ? "Co" : "Khong") << endl;
    return 0;
}
/* input: 2 3 4 5 2 3 5 2 3 5 2 2 8 9 7 2    
output:                   
    Phan tu dau tien trong hang doi: 2
    Xoa phan tu dau tien: 2
    Phan tu dau tien sau khi xoa: 3
    Kiem tra hang doi co rong khong: Khong */
