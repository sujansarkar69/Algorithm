#include <bits/stdc++.h>
using namespace std;
bool is_palindrome(string str)
{
    if (str == "" || str.size() == 1)
        return true;
    int n = str.size();
    string smaller_str = str.substr(1, n - 2);
    return is_palindrome(smaller_str) && (str[0] == str.back());
}
int main()
{
    string str;
    cin >> str;
    if (is_palindrome(str))
        cout << "Palindrome\n";
    else
        cout << "Not Palindrome\n";

    return 0;
}