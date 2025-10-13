#include <iostream>
#include <vector>
using namespace std;

class MinHeap {
private:
    vector<int> heap;

    // Hàm đưa phần tử ở index i lên đúng vị trí (heapify-up)
    void heapifyUp(int i) {
        while (i > 0) {
            int parent = (i - 1) / 2;
            if (heap[i] < heap[parent]) {
                swap(heap[i], heap[parent]);
                i = parent;
            } else {
                break;
            }
        }
    }

    // Hàm đưa phần tử ở index 0 xuống đúng vị trí (heapify-down)
    void heapifyDown(int i) {
        int size = heap.size();
        while (true) {
            int left = 2 * i + 1;
            int right = 2 * i + 2;
            int smallest = i;

            if (left < size && heap[left] < heap[smallest]) {
                smallest = left;
            }
            if (right < size && heap[right] < heap[smallest]) {
                smallest = right;
            }

            if (smallest != i) {
                swap(heap[i], heap[smallest]);
                i = smallest;
            } else {
                break;
            }
        }
    }

public:
    // Thêm phần tử
    void insert(int value) {
        heap.push_back(value);
        heapifyUp(heap.size() - 1);
    }

    // Lấy phần tử nhỏ nhất
    int getMin() {
        if (heap.empty()) {
            throw runtime_error("Heap rong!");
        }
        return heap[0];
    }

    // Xóa phần tử nhỏ nhất
    void extractMin() {
        if (heap.empty()) {
            throw runtime_error("Heap rong!");
        }
        heap[0] = heap.back();
        heap.pop_back();
        if (!heap.empty()) {
            heapifyDown(0);
        }
    }

    // In heap dạng mảng
    void printHeap() {
        for (int v : heap) {
            cout << v << " ";
        }
        cout << endl;
    }
};

int main() {
    MinHeap mh;
    mh.insert(7);
    mh.insert(3);
    mh.insert(10);
    mh.insert(5);
    mh.insert(1);
    mh.insert(8);

    cout << "Min-Heap hien tai: ";
    mh.printHeap();

    cout << "Phan tu nho nhat: " << mh.getMin() << endl;

    cout << "Xoa phan tu nho nhat..." << endl;
    mh.extractMin();

    cout << "Heap sau khi xoa: ";
    mh.printHeap();

    return 0;
}
