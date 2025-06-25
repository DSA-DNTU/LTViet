#include <iostream>
#include <fstream>
#include <string>
#include <stack>
using namespace std;
bool valid( string line) {  
    stack <char> s;
    auto X = [] (char open, char close) { // hàm lambda kiểm tra dấu ngoặc
        return (open == '(' && close == ')') || (open == '{' && close == '}') || (open == '[' && close == ']');
    };
    for (char c : line) { 
        if (c == '{' ||  c == '[' || c == '(' ) {

            s.push(c); // Thêm dấu ngoặc mở vào stack
        } else if (c == '}' || c == ']' || c == ')') {
            if (s.empty() || !X(s.top(), c)) {
                return false; // Không có dấu ngoặc mở tương ứng
            }
            s.pop(); // Xóa dấu ngoặc mở tương ứng
        }
    }
    return s.empty(); // Nếu stack rỗng, tất cả dấu ngoặc đã được đóng đúng cách
}
// input: { [ ( ] }  output: Invalid
int main () {
    fstream input("cau6.inp");
    if (!input) {
        cerr << "file loi" << endl;
        return 1;
    }
    string line;
    getline(input, line); // Đọc toàn bộ dòng từ file
    cout << (valid(line) ? "Valid" :  "Invalid") << endl; // Kiểm tra tính hợp lệ của dấu ngoặc
    return 0;
}