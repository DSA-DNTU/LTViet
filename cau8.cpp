#include <iostream>
#include <fstream>
#include <stack>
#include <string>
#include <cctype> // Thư viện cho isdigit
#include <sstream> // Thư viện cho stringstream
using namespace std;
int pt(string n) { //tính toán tiền tố
    stack <int> s; // Khởi tạo stack
    stringstream ss(n);
    string c;
    while (ss >> c) { // Đọc từng phần tử từ chuỗi
        if (isdigit(c[0])) { 
            s.push(stoi(c)); // Chuyển đổi ký tự số thành số nguyên
        }
        else {
            int b = s.top(); s.pop();
            int a = s.top(); s.pop();
            if (c == "+") {
                s.push(a + b);
            } else if (c == "-") {
                s.push(a - b);
            } else if (c == "*") {
                s.push(a * b);
            } else if (c == "/") {
                if (b != 0) {
                    s.push(a / b);
                } else {
                    cerr << "Loi: Chia cho 0!" << endl;
                    return 0; // Trả về 0 nếu chia cho 0
                }
            } else {
                cerr << "Loi: Toan tu khong hop le!" << endl;
                return 0; // Trả về 0 nếu toán tử không hợp lệ
            }
        }
    }
    return s.top(); // số còn lại là kết quả
}
// input : 2 3 1 * + 9 -            output: -4
int main () {
    fstream input("cau8.inp");
    if (!input) {
        cerr << "Loi mo file!" << endl;
        return 1;
    }
    stack<int> s; // Khởi tạo stack
    string n;
    getline(input, n); // Đọc số nguyên từ file
    cout<< pt(n) << endl; 
    input.close();

}