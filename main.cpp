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