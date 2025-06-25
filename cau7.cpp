#include <iostream>
#include <fstream>
#include <stack>
using namespace std;
int fl (stack <int>* s, int n) {
    int result = 1; 
    for (int i = 1; i <= n; ++i) {
        s->push(i); // Dùng con trỏ để push vào stack
        result *= i; // Tính giai thừa
    }
    return result;
}
// n = 5        output: 120 (vì 120 = 5! = 1*2*3*4*5 = 120)
int main() {
    fstream input("cau7.inp");

    if (!input) {
        cerr << "Loi mo file!" << endl;
        return 1;
    }

    stack<int> s; // Khởi tạo stack
    int n, x;
    input >> n; // Đọc số giai thừa
    input.close();
    x = fl(&s, n); // Truyền địa chỉ stack
    cout << x << " (vi " << x << " = " << n << "!) = ";
    for (int i = 0; i < n; ++i) {
        cout << s.top() << "*"; // In các phần tử trong stack
        s.pop(); // xoá phần tử khỏi stack
    }
    cout << " = " << x << endl;
    return 0;
}