#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;
void insert (int arr[], int& n, int x, int pos) {
    if (pos < 0 || pos > n) return; // Kiểm tra vị trí hợp lệ
    for (int i = n; i > pos; i--) {
        arr[i] = arr[i - 1]; // Dịch chuyển các phần tử
    }
    arr[pos] = x; // Chèn phần tử mới vào vị trí pos
    n++; // Tăng kích thước mảng
}
/* 1 2 3 4 5 6 7                nhap mang
2 3                             x và pos    */
int main() {
    fstream input("cau1.inp");
    string line;
    getline(input, line); // Đọc dòng đầu tiên
    stringstream ss(line); // Sử dụng stringstream để tách các số
    int arr[1000], n = 0;
    int x, pos;
    while (ss >> x) {
        arr[n++] = x;
    }
    input >> x >> pos;
    insert  (arr, n, x, pos); // Chèn phần tử x vào vị trí pos
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    return 0;
}
// output: 1 2 3 2 4 5 6 7
