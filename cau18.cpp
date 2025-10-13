#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

void heapifydown(vector<int>& arr, int i, int size) // đưa phần tử ở index 0 xuống đúng vị trí
{
    while(true)
    {
        int left = 2*i + 1;
        int right = 2*i + 2;
        int largest = i;
        if(left < size && arr[left] > arr[largest])
            largest = left;
        if(right < size && arr[right] > arr[largest])
            largest = right;
        if(largest != i)
        {
            swap(arr[i], arr[largest]);
            i = largest;
        }
        else
            break;
    }
}
void buildheap(vector<int>& arr) // xây dựng heap từ mảng ban đầu
{
    int size = arr.size();
    for(int i = size/2 - 1; i >= 0; i--)
        heapifydown(arr, i, size);
}
void heapsort(vector<int>& arr) // sắp xếp mảng sử dụng heapsort
{
    buildheap(arr);
    int size = arr.size();
    for(int i = size - 1; i > 0; i--)
    {
        swap(arr[0], arr[i]);
        heapifydown(arr, 0, i);
    }
}

int main()
{
    ifstream input("input.txt");
    if(!input)
    {
        cerr << "Khong the mo file!" << endl;
        return 1;
    }
    vector<int> arr;
    int n;
    while(input >> n)
        arr.push_back(n);
    input.close();

    heapsort(arr);

    cout << "Mang sau khi sap xep: ";
    for(int num : arr)
        cout << num << " ";
    cout << endl;

    return 0;
}
