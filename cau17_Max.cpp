#include <iostream>
#include <vector>
using namespace std;

 class heap 
 {
    private:
        vector<int> arr;
        void heapifyUp(int i) // đưa phần tử ở index i lên đúng vị trí (heapify-up)
        {
            while(i > 0)
            {
                int parent = (i -1)/2;
                if(arr[i] > arr[parent])
                {
                    swap(arr[i], arr[parent]);
                    i = parent;
                }
                else
                {
                    break;
                }
            }
        }

        void heapifydown(int i) // đưa phần tử ở index 0 xuống đúng vị trí (heapify-down)
        {
            int size = arr.size();
            while(true)
            {
                int left = 2*i + 1;
                int right = 2*1 + 2;
                int largest = i;

                if (left < size && arr[left] > arr[largest])
                    largest = left;
                if (right < size && arr[right] > arr[largest])
                    largest = right;
                if (largest != i)
                {
                    swap(arr[i], arr[largest]);
                    i = largest;
                }
                else
                    break;
            }
        }
        public:
        void insert(int value) // thêm phần tử
        {
            arr.push_back(value);
            heapifyUp(arr.size()-1);
        }
        int getMax() // lấy phần tử lớn nhất
        {
            if (arr.empty())
                throw runtime_error("Heap rong!");
            return arr[0];
        }
        int getMin() // lấy phần tử nhỏ nhất
        { 
            if (arr.empty())
                throw runtime_error("Heap rong!");
            int minIndex = arr.size()/2; // tìm phần tử nhỏ nhất trong nửa dưới của heap
            for (int i = arr.size()/2 + 1; i < arr.size(); i++)
                if (arr[i] < arr[minIndex])
                    minIndex = i;
            return arr[minIndex];
        }
        void extractMax() // xóa phần tử lớn nhất
        {
            if (arr.empty())
                throw runtime_error("Heap rong!");
            arr[0] = arr.back();
            arr.pop_back();
            heapifydown(0);
        }   
        void printHeap() // in heap
        {
            if (arr.empty())
            {
                cout << "Heap rong!\n";
                return;
            }
            cout << "Heap: ";
            for (int val : arr)
                cout << val << " ";
            cout << endl;
        }
 };
 int main() 
 {
    heap mxh;
    mxh.insert(4);
    mxh.insert(5);
    mxh.insert(43);
    mxh.insert(23);
    mxh.insert(2);

    cout << "Min-Heap hien tai: ";
    mxh.printHeap();

    cout << "Phan tu lon  nhat: " << mxh.getMax() << endl;

    cout << "Xoa phan tu lon nhat..." << endl;
    mxh.extractMax();

    cout << "Heap sau khi xoa: ";
    mxh.printHeap();

    return 0;
 }