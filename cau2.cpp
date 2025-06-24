#include <iostream>
#include <fstream>
using namespace std;
class DynamicArray {
public:
    int* arr; // con trỏ đến mảng động
    int size; // kích thước của mảng

    DynamicArray(int n) {
        size = n + 1; // kích thước mới là m + 1
        arr = new int[size]; // cấp phát bộ nhớ cho mảng
    }

    ~DynamicArray() {
        delete[] arr; // giải phóng bộ nhớ khi đối tượng bị hủy
    }
};
int add (DynamicArray& da, int k) {
    da.arr[da.size - 1] = k; // thêm phần tử mới vào cuối mảng
    return da.size; // trả về kích thước mới của mảng
}
int get(DynamicArray& da, int index) {
    if (index < 0 || index >= da.size) {
        throw out_of_range("index không nằm trong mảng"); // kiểm tra chỉ số hợp lệ
    }
    return da.arr[index]; // trả về giá trị tại chỉ số index
}
int size(DynamicArray& da) {
    return da.size; // trả về kích thước của mảng
}
/*8 3 5                         kích thước mảng, phần tử mới, index
2 34 3 2 3 5 3 2                phần tử mảng*/
int main () {
    fstream input("cau2.inp");
    int n = 0;
    int m = 0;
    int index = 0; 
    input >> n >> m >> index; // đọc kích thước mảng và phần tử mới, index
    DynamicArray da(n); // tạo mảng động với kích thước n
    for (int i = 0; i < n; i++) {
        input >> da.arr[i]; // đọc các phần tử vào mảng
    }
    int newSize = add(da, m); // thêm phần tử mới vào mảng
    cout << "Kich thuoc moi cua mang: " << newSize << endl; // in kích thước mới
    cout << "Cac phan tu trong mang: ";
    for (int i = 0; i < newSize; i++) {
        cout << da.arr[i] << " "; // in các phần tử trong mảng
    }
    cout << endl;
    cout << "Phan tu tai chi so index: " << get(da, index) << endl; // in phần tử tại chỉ số 2
    return 0;
}
/*Kich thuoc moi cua mang: 9
Cac phan tu trong mang: 2 34 3 2 3 5 3 2 3
Phan tu tai chi so index: 5 */