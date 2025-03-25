#include <iostream>
using namespace std;
long long help(int x)
{
    long long result;
    if (x > 10)
    {
        result = 2 * x * help(x - 6);
    }
    else if (x <= 10)
    {
        result = x * (x - 1);
    }
}
int main()
{
    int n;
    cin >> n;
    cout << help(n) % 998244353;
    return 0;
}