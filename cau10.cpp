#include <iostream>
#include <array>
using namespace std;
class queue_ {
    private:
        array<int,3> arr;
        int front = 0, rear = 0, size = 0 ;
    public:
    void enqueue(int item) { // hàm thêm vào hàng đợi
        if (size == arr.size()) {
            cout<< "hang doi day" << endl;
        } else {
        arr[rear] = item;
        rear = (rear + 1)  % arr.size();
        size++;
    } }
    int dequeue() { // hàm lấy phần tử đầu tiên ra khỏi hàng đợi    
        if (isEmpty()) {
            cerr << "hang doi rong" << endl;
            return -1;
        }
        else {
            int Front = arr [front];
            Front = (Front + 1) % arr.size(); // cập nhật chỉ số front
            size--;        
            return Front;
        }
    }
    int peek() {
        return isEmpty() ? -1 : arr[front]; // Trả về phần tử đầu tiên nếu không rỗng, ngược lại trả về -1
    }
    bool isEmpty() { // Kiểm tra xem hàng đợi có rỗng hay không
        return size == 0; 
    }
    void in() { // hàm in ra các phần tử trong hàng đợi
        int i = 0, j = front;
        while ( i < size) {
            cout<< arr[j] <<" ";
            j = (j +1) % arr.size();
            i++;
        }
        cout<< "front = " << front << " rear = " << rear << " size = " << size << endl;
    }
};
int main() {
    queue_ q;
    cout<< "thao tac 1: "; q.enqueue(1); q.in(); // thao tac 1: 1 front = 0 rear = 1 size = 1
    cout<< "\nthao tac 2: "; q.enqueue(2); q.in(); // thao tac 2: 1 2 front = 0 rear = 2 size = 2
    cout<< "\nthao tac 3: "; q.enqueue(3); q.in(); // thao tac 3: 1 2 3 front = 0 rear = 0 size = 3
    cout<< "\nthao tac 4: item1 = " << q.dequeue() << " "; q.in(); // thao tac 4: item1 = 2 1 2 front = 0 rear = 0 size = 2
    cout<< "\nthao tac 5: " ;q.enqueue(4); q.in(); // thao tac 5: 4 2 3 front = 0 rear = 1 size = 3
    return 0;
}