#include <iostream> 
#include <vector>
using namespace std;

int main() 
{
    int n, m;
    cout<<" nhập số đỉnh: ";
    cin>>n;
    cout<<" nhập số cạnh: ";
    cin>>m;
    vector<vector<int>> a(n);
    cout<<" nhập các cạnh: \n";
    for(int i=0; i<m; i++)
    {
        int x, y;
        cin>>x>>y;
        a[x].push_back(y);
    }
    cout<<" danh sách kề: \n";
    for(int i=0; i<n; i++)
    {
        cout<<i<<": [ ";
        for (int j : a[i])
            cout<<j<<" ";
        cout<<"]\n";
    }
    return 0;
}