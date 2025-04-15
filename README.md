## Asymptotic analysis

```c++
#include <iostream>
using namespace std;

int search(vector<int> a, int x) //O(n) = c*n
{
    for(size_t i = 0; i < a.size(); ++i) {
        if(a[i] == x) {
            return i;
        }
    }

    return -1;
}

void swap(int& a, int& b) // O(1) = c
{
    int t = a;
    a = b;
    b = t;
}

void cycle_l() //O(1)
{
    const int c = 4;

    for (size_t i = 0; i < c; ++i)
    {
        cout << i;
    }
    
}

void cycle_n(int n) //O(n)
{
    for (size_t i = 0; i < n; ++i)
    {
        cout << i;
    }
    
}

void cycle_nm(int n, int m) //O(max(n,m)) = O(n + m)
{
    for (size_t i = 0; i < n; ++i)
    {
        cout << i;
    }

    for (size_t i = 0; i < m; ++i)
    {
        cout << i;
    }
    
}

void cycle_nm1(int n, int m) //O(n*m)
{
    for (size_t i = 0; i < n; ++i)
    {
        for (size_t j = 0; j < m; ++j)
        {
            cout << i + j;
        }
    }
}

void cycle_nm2(int n) //O(n^2)
{
    for (size_t i = 0; i < n; ++i)
    {
        for (size_t j = 0; j < n; ++j)
        {
            cout << i + j;
        }
    }
}

void cycle_nm3(int n) //O(n^3)
{
    for (size_t i = 0; i < n; ++i)
    {
        for (size_t j = 0; j < n; ++j)
        {
            for (size_t k = 0; i < n; ++k)
            {
                cout << i + j + k;
            }
            
        }
    }
}

// n + (n - 1) + (n - 2) + (n - 3) ... + 1 = n*(n + 1)/2
// n*(n + 1)/2 = 1/2*(n*n + n) = O(n^2)
void cycle_ij(int n) //O(n^2)
{
    for (size_t i = 0; i < n; ++i)
    {
        for (size_t j = i; j < n; ++j)
        {
            cout << i + j;
        }
    }
}

void cycle_n123(int n) //O(n^3)
{
    for (size_t i = 0; i < n; ++i) //O(n)
    {
        cout << i;
    }

    for (size_t i = 0; i < n; ++i) //O(n^2)
    {
        for (size_t j = 0; j < n; ++j)
        {
            cout << j + i;
        }
        
    }

    for (size_t i = 0; i < n; ++i) //O(n^3)
    {
        for (size_t j = 0; j < n; ++j)
        {
            for (size_t k = 0; i < n; ++k)
            {
                cout << j + i + k;
            }
            
        }
        
    }
}

void cycle_abc123(int a, int b, int c) //O(a + b^2 + c^3)
{
    for (size_t i = 0; i < a; ++i) //O(a)
    {
        cout << i;
    }

    for (size_t i = 0; i < b; ++i) //O(b^2)
    {
        for (size_t j = 0; j < b; ++j)
        {
            cout << j + i;
        }
        
    }

    for (size_t i = 0; i < c; ++i) //O(c^3)
    {
        for (size_t j = 0; j < c; ++j)
        {
            for (size_t k = 0; i < c; ++k)
            {
                cout << j + i + k;
            }
            
        }
        
    }
}

int cycle_log1(int a) //O(log(a))
{
    int sum = 0;

    while (a != 0) //log(a)
    {
        sum += a & 10;
        a /= 10;
    }
    
    return sum;
}

int cycle_log2(int n) //O(n * log(n))
{
    int sum = 0;

    for (size_t i = 0; i < n; ++i)
    {
        int a = i;

        while (a != 0) //log(a)
        {
            sum += a & 10;
            a /= 10;
        }
    }
    
    
    return sum;
}

void cycle_sqrt(int n) //O(sqrt(n))
{
    for (size_t i = 0; i * i < n; ++i)
    {
        cout << i;
    }
}

void cycle_n_plus_2(int n) //O(n)
{
    for (size_t i = 0; i < n; i += 2) // n / 2 = 1/2 * n
    {
        cout << i;
    }
    
}

//O(2^n), O(3^n), O(n!)

int main() {
    return 0;
}
```

## Stack O(1) - LIFO

```c++
#include <iostream>
#include <stack>
using namespace std;

bool isOpen(char& ch) {
    return ch == '(' || ch == '[' || ch == '{';
}

bool isPair(char& top, char& ch) 
{
    if(top == '(' && ch == ')') 
    {
        return true;
    }

    if(top == '[' && ch == ']') 
    {
        return true;
    }

    if(top == '{' && ch == '}') 
    {
        return true;
    }

    return false;
}

bool isBalanced(string& str) 
{
    if(str == "") {
        return true;
    }

    stack<char> st;
    int result = true;

    for (size_t i = 0; i < str.size(); ++i)
    {
        if(isOpen(str[i])) 
        {
            st.push(str[i]);

            continue;
        }

        if(st.empty()) {
            result = false;

            break;
        }

        if(isPair(st.top(), str[i])) {
            st.pop();

            continue;
        }

        result = false;
        break;
    }

    if(!st.empty()) {
        result = false;
    }
    
    return result;
}

int main() {
    string str1 = "()({[]}())"; //true 1
    string str2 = "{}"; //true 1
    string str3 = "}{"; //false 0
    string str4 = ""; //true 1
    string str5 = "(()"; //false 0
    string str6 = "())"; //false 0
    string str7 = "[(])"; //false 0
    string str8 = "}"; //false 0

    cout << isBalanced(str1) << endl;
    cout << isBalanced(str2) << endl;
    cout << isBalanced(str3) << endl;
    cout << isBalanced(str4) << endl;
    cout << isBalanced(str5) << endl;
    cout << isBalanced(str6) << endl;
    cout << isBalanced(str7) << endl;
    cout << isBalanced(str8) << endl;

    return 0;
}
```