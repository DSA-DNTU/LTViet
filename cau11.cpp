#include <iostream>
#include <array>
#include <string>
using namespace std;
struct node {
    string s; // Chuỗi giá trị
    int n; // Số nguyên ưu tiên
};
class V_priority_queue {
    private:
        array<node, 100> arr; // Mảng để lưu trữ các phần tử
        int size; // Kích thước hiện tại của hàng đợi ưu tiên
    public:
    V_priority_queue() : size(0) {} // khi khởi tạo một đối tượng, size sẽ được gán là 0
    void enqueue(string s, int n) { 
        if (size < arr.size()) {
            arr[size++]= {s,n}; // Thêm phần tử mới vào mảng và tăng kích thước
        } else {
            cout << "Hang doi day!" << endl;
        }
    }
    string dequeue() {
        if (size == 0) {
            cerr << "hang doi rong!" << endl;
            return "";
        }
        // Tìm phần tử có n lớn nhất
        int max = 0;
        for (int i = 1; i < size; ++i) {
            if (arr[i].n > arr[max].n)
                max = i;
        }
        string res = arr[max].s;
        // Xóa phần tử đó khỏi mảng
        for (int i = max; i < size - 1; ++i)
            arr[i] = arr[i + 1];
        size--;
        return res;
    }
};
int main() {
    V_priority_queue pq; // Khởi tạo hàng đợi ưu tiên
    pq.enqueue("Task A", 3); 
    pq.enqueue("Task B", 1);
    pq.enqueue("Task C", 2); 
    cout<< "thao tac 1: "<< pq.dequeue() << endl; 
    cout<< "thao tac 2: "<< pq.dequeue() << endl;
    cout<< "thao tac 3: "<< pq.dequeue() << endl;
}
/* output:
thao tac 1: Task A
thao tac 2: Task C
thao tac 3: Task B */