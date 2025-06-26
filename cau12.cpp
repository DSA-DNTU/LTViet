#include <iostream>
#include <vector>
using namespace std;
class V_deque {
    private:
        vector<int> arr; // Sử dụng vector để lưu trữ các phần tử
    public:
    void add_front(int x) {
        arr.insert(arr.begin(), x); // Thêm phần tử vào đầu deque
    }
    void add_rear(int x) {
        arr.push_back(x); // Thêm phần tử vào cuối deque
    }
    int remove_front() {
        if (arr.empty()) {
            cerr << "deque rong!" << endl;
            return -1;
        } else {
            int a = arr.front();
            arr.erase(arr.begin()); // Xóa phần tử đầu tiên
        return a;
    } }
    int remove_rear() {
        if (arr.empty()) {
            cerr << "deque rong!" << endl;
            return 0;
        } else {
            int a = arr.back();
            arr.pop_back(); // Xóa phần tử cuối cùng
            return a; 
        }
    }
    int peek_front() {
        if (arr.empty()) {
            cerr << "deque rong!" << endl;
            return -1; // Trả về -1 nếu deque rỗng
        }
        return arr.front(); // Trả về phần tử đầu tiên
    }
    int peek_rear() {
        if (arr.empty()) {
            cerr << "deque rong!" << endl;
            return -1; // Trả về -1 nếu deque rỗng
        }
        return arr.back(); // Trả về phần tử cuối cùng
    }
    void in() {
        if (arr.empty()) {
            cout << "deque rong!" << endl;
            return;
        } else {
            for (int i = 0; i < arr.size(); ++i) {
                cout << arr[i] << " "; 
            }
        }
    }
};
int main() {
    V_deque dq;
    dq.add_front(10); dq.in(); cout << endl;
    dq.add_rear(20); dq.in(); cout << endl;
    dq.add_front(5); dq.in(); cout << endl;
    int item_rear = dq.remove_rear(); dq.in(); cout << endl;
    int item_front = dq.remove_front(); dq.in(); cout << endl;

}
/*output 
10
10 20
5 10 20
5 10
10  */